#include "VRayError_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayError_construct (
    KL::Traits< KL::VRayError >::IOParam this_,
    KL::Traits< KL::SInt32 >::INParam errorCode)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Error (convert< int >(errorCode));

    V4F_CATCH()
} // VRayError_construct


FABRIC_EXT_EXPORT void
VRayError_destruct (KL::Traits< KL::VRayError >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::Error* >(this_->pointer);
    this_->pointer = NULL;
    V4F_CATCH()
} // VRayError_destruct


FABRIC_EXT_EXPORT KL::SInt32
VRayError_getCode (KL::Traits< KL::VRayError >::INParam this_)
{
    V4F_TRY
    VRay::Error *error = static_cast< VRay::Error* >(this_->pointer);

    return static_cast< int >(error->getCode());

    V4F_CATCH (-1)
} // VRayError_getCode


FABRIC_EXT_EXPORT void
VRayError_toString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayError >::INParam this_)
{
    V4F_TRY
    VRay::Error *error = static_cast< VRay::Error* >(this_->pointer);

    _result = error->toString().c_str();
    V4F_CATCH()
} // VRayError_toString







