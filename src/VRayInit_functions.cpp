#include "VRayInit_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayInit_construct (KL::Traits< KL::VRayInit >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::VRayInit();

    V4F_CATCH()
} // VRayInit_construct


FABRIC_EXT_EXPORT void
VRayInit_construct_variant1 (
    KL::Traits< KL::VRayInit >::IOParam this_,
    KL::Traits< KL::Boolean >::INParam enableFrameBuffer)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::VRayInit (convert< bool >(enableFrameBuffer));

    V4F_CATCH()
} // VRayInit_construct_variant1


FABRIC_EXT_EXPORT void
VRayInit_destruct (KL::Traits< KL::VRayInit >::IOParam this_)
{
    V4F_TRY
    this_->pointer = NULL;

    V4F_CATCH()
} // VRayInit_destruct







