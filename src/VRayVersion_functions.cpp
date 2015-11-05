#include "VRayVersion.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"


using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
getVRayVersion (KL::Traits< KL::VRayVersion >::Result _result)
{
    V4F_TRY
    VRay::VRayVersion version = VRay::getVRayVersion();

    _result.revision = convert< KL::UInt8 >(version.revision);
    _result.minor = convert< KL::UInt8 >(version.minor);
    _result.major = convert< KL::UInt16 >(version.major);
    _result.allFields = convert< KL::UInt32 >(version.allFields);
    V4F_CATCH()
} // getVRayVersion


FABRIC_EXT_EXPORT void
getVRayVersionAsString (KL::Traits< KL::String >::Result _result)
{
    V4F_TRY
    VRay::VRayVersion version = VRay::getVRayVersion();

    _result = version.toString().c_str();
    V4F_CATCH()
} // getVRayVersionAsString







