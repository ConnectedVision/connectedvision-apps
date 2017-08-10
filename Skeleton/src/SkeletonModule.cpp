/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

#include <Module/OutputPins/OutputPin_JSON.h>

#include "SkeletonModule.h"
#include "SkeletonWorker.h"

#include "Skeleton_ModuleDescription.h"

#include <Module/InputPins/InputPin_PNG.h>
#include "InputPin_Skeleton_input_Detections.h"
#include "OutputPin_Skeleton_output_Average.h"
#include "Class_Skeleton_output_Average.h"
#include "Store_Manager_SQLite_Skeleton_output_Average.h"
#include "Store_Manager_Ringbuffer_Skeleton_output_Average.h"

namespace ConnectedVision {
namespace Module {
namespace Skeleton {

#define STORE_USE_RINGBUFFER 1

using namespace ConnectedVision;

SkeletonModule::SkeletonModule() : ConnectedVisionModule(_moduleDescription, _inputPinDescription, _outputPinDescription)
{

}

void SkeletonModule::initModule( IModuleEnvironment *env ) 
{
	LOG_SCOPE;

	// clean up module before init
	releaseModule();

	// call parent init
	ConnectedVisionModule::initModule(env);
}

void SkeletonModule::releaseModule() 
{
	LOG_SCOPE;

	// call parent release
	ConnectedVisionModule::releaseModule();

	// reset store managers
	this->storeManagerAverage.reset();	

// TODO --> do additional clean-up HERE! <--

}

void SkeletonModule::prepareStores() 
{
	LOG_SCOPE;

	// module specific stores

	// Average output pin
#if STORE_USE_RINGBUFFER
	this->storeManagerAverage = ConnectedVision::make_shared<DataHandling::Store_Manager_Ringbuffer_Skeleton_output_Average>(
		10,			// number of stores in manager
		1000,		// number of element slots in ringbuffer
		10010		// total number of available objects (for all ring buffers)
	);
#else
	this->storeManagerAverage = ConnectedVision::make_shared<DataHandling::Store_Manager_SQLite_Skeleton_output_Average>( this->getDB() );
#endif

}

boost::shared_ptr<IConnectedVisionInputPin> SkeletonModule::generateInputPin(const pinID_t& pinID)
{
	LOG_SCOPE;

	if ( InputPin_PNG::hasPinID(pinID)  )	
	{
		/*
			PNG input pin (see input pin description)
			This is an commonly used PNG binary input pin.
		*/
		return boost::shared_ptr<IConnectedVisionInputPin>( new InputPin_PNG( this->env, pinID ) );
	}
	else if ( InputPin_Skeleton_input_Detections::hasPinID(pinID) )
	{
		/* 
			bounding box input pin (see input pin description)
			Use the auto generated meta-data input pin.
		*/
		return boost::shared_ptr<IConnectedVisionInputPin>( new InputPin_Skeleton_input_Detections( this->env, pinID ) );
	}

	throw runtime_error("invalid pinID: " + pinID);
}

boost::shared_ptr<IConnectedVisionOutputPin > SkeletonModule::generateOutputPin(const pinID_t& pinID)
{
	LOG_SCOPE;

	if ( OutputPin_Skeleton_output_Average::hasPinID(pinID) )
	{
		// Average output pin
		return boost::make_shared<OutputPins::OutputPin_JSON<Class_Skeleton_output_Average>>(this->storeManagerAverage);
	}

	throw runtime_error("invalid pinID: " + pinID);
}

boost::shared_ptr<IConnectedVisionAlgorithmWorker> SkeletonModule::createWorker(IModuleEnvironment *env, boost::shared_ptr<const Class_generic_config> config)
{
	LOG_SCOPE;

	// create worker instance
	return boost::make_shared<SkeletonWorker>(env, this, config);
}

void SkeletonModule::deleteResults(const boost::shared_ptr<const Class_generic_config> config)
{
	LOG_SCOPE_CONFIG( config->getconst_id() );

	// delete all results for configID
	this->storeManagerAverage->getReadWriteStore( config->getconst_id() )->deleteAll();
}

}}} // namespace
