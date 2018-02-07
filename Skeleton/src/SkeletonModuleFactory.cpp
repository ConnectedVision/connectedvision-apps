/**
* Connected Vision - https://github.com/ConnectedVision
* MIT License
*/

#include "SkeletonModuleFactory.h"
#include "SkeletonModule.h"

namespace ConnectedVision {
namespace Module {
namespace Skeleton {

ConnectedVision::shared_ptr<IModule> SkeletonModuleFactory::createModule()
{
	ConnectedVision::shared_ptr<IModule> moduleInstance = ConnectedVision::make_shared<SkeletonModule>();
	if ( !moduleInstance ) 
		throw std::runtime_error("SkeletonModuleFactory: error creating instance for module");

	return moduleInstance;
}

} // namespace Skeleton
} // namespace Module
} // namespace ConnectedVision