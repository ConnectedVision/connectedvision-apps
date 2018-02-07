/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

#ifndef SkeletonWorker_def
#define SkeletonWorker_def

#include <Module/Worker_BaseClass.h>

#include "SkeletonModule.h"
#include "Class_Skeleton_input_Detections.h"

namespace ConnectedVision {
namespace Module {
namespace Skeleton {

/**
* worker for Skeleton Module
*
*/
class SkeletonWorker : public Worker_BaseClass
{
public:
	/**
	* worker constructor
	*/
	SkeletonWorker(
		SkeletonModule &module,											///< [in] reference to "parent" module; This is the explicit SkeletonWorker (no interface) so it is ok to use the explicit SkeletonModule class.
		IWorkerControllerCallbacks &controller,							///< [in] worker controller (for callbacks)
		ConnectedVision::shared_ptr<const Class_generic_config> config	///< [in] config for this worker instance
	) : Worker_BaseClass(module, controller, config), module(module) {}

	virtual ~SkeletonWorker() {}

	virtual void run();

protected:
	/**
	* The real algorithm ... or, in this case just a dummy example computing the average color of a bounding box.
	*/
	ConnectedVision::shared_ptr<const Class_Skeleton_output_Average> computeAverage(
		boost::shared_ptr<Class_Skeleton_input_Detections> detection, 
		boost::shared_ptr<std::string> pngImg,
		boost::shared_ptr< ConnectedVision::DataHandling::IDataAllocator<Class_Skeleton_output_Average> > allocator
	);

	SkeletonModule &module;
};

}}} // namespace

#endif // SkeletonWorker_def