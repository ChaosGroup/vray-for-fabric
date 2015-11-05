#include "VRayPropertyRuntimeMeta_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayPropertyRuntimeMeta_construct (KL::Traits< KL::VRayPropertyRuntimeMeta >::IOParam this_)
{
    V4F_TRY
    VRay::PropertyRuntimeMeta *meta;

    this_->pointer = meta;
    V4F_CATCH()
} // VRayPropertyRuntimeMeta_construct


FABRIC_EXT_EXPORT void
VRayPropertyRuntimeMeta_destruct (KL::Traits< KL::VRayPropertyRuntimeMeta >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::PropertyRuntimeMeta* >(this_->pointer);
    V4F_CATCH()
} // VRayPropertyRuntimeMeta_destruct


FABRIC_EXT_EXPORT KL::UInt32
VRayPropertyRuntimeMeta_getRuntimeElementsCount (KL::Traits< KL::VRayPropertyRuntimeMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyRuntimeMeta *meta = static_cast< VRay::PropertyRuntimeMeta* >(this_->pointer);

    return convert< KL::UInt32 >(meta->getRuntimeElementsCount());

    V4F_CATCH (-1)
} // VRayPropertyRuntimeMeta_getRuntimeElementsCount


FABRIC_EXT_EXPORT KL::SInt32
VRayPropertyRuntimeMeta_getRuntimeType (KL::Traits< KL::VRayPropertyRuntimeMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyRuntimeMeta *meta = static_cast< VRay::PropertyRuntimeMeta* >(this_->pointer);

    return convert< KL::SInt32 >(meta->getRuntimeType());

    V4F_CATCH (-1)
} // VRayPropertyRuntimeMeta_getRuntimeType


FABRIC_EXT_EXPORT void
VRayPropertyRuntimeMeta_getRuntimeTypeAsString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyRuntimeMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyRuntimeMeta *meta = static_cast< VRay::PropertyRuntimeMeta* >(this_->pointer);

    _result = meta->getRuntimeTypeAsString().c_str();
    V4F_CATCH()
} // VRayPropertyRuntimeMeta_getRuntimeTypeAsString







