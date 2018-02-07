/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

#ifndef SkeletonModule_def
#define SkeletonModule_def

#include <IConnectedVisionModule.h>
#include <IStore.h>

#include <Module/Module_BaseClass.h>

#include "Class_Skeleton_output_Average.h"

namespace ConnectedVision {
namespace Module {
namespace Skeleton {

/**
*	module class: Skeleton Module
*	
*/
class SkeletonModule: public Module_BaseClass
{
friend class SkeletonWorker;
public:
	/**
	* module constructor
	*/
	SkeletonModule();

	/**
	* worker factory
	*
	* @return Skeleton Module worker
	*/
	virtual std::unique_ptr<IWorker> createWorker(
		IWorkerControllerCallbacks &controller,							///< reference to worker controller
		ConnectedVision::shared_ptr<const Class_generic_config> config	///< config for the worker to be created
	);

	/**
	* delete data / results of a given config
	*/
	virtual void deleteAllData(
		const id_t configID		///< [in] config ID of data to be deleted
	);

protected:
	/**
	* connect to stores
	*/
	virtual void prepareStores();
	
	/**
	* output pin factory
	*
	* @return output pin for pinID
	*/
	virtual boost::shared_ptr<IConnectedVisionOutputPin> generateOutputPin(
		const pinID_t& pinID	///< [in] pinID of output pin to be generated
	);

	/**
	* input pin factory
	*
	* @return output pin for pinID
	*/
	virtual boost::shared_ptr<IConnectedVisionInputPin> generateInputPin(
		const pinID_t& pinID	///< [in] pinID of input pin to be generated
	);

	// data store
	ConnectedVision::shared_ptr< ConnectedVision::DataHandling::IStore_Manager<Class_Skeleton_output_Average> > storeManagerAverage;
};

}}} // namespace

#endif // SkeletonModule_def