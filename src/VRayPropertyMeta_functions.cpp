#include "VRayPropertyMeta_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayPropertyMeta_construct (KL::Traits< KL::VRayPropertyMeta >::IOParam this_)
{
    V4F_TRY
    this_->pointer = NULL;

    V4F_CATCH()
} // VRayPropertyMeta_construct


FABRIC_EXT_EXPORT void
VRayPropertyMeta_destruct (KL::Traits< KL::VRayPropertyMeta >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::PropertyMeta* >(this_->pointer);

    this_->pointer = NULL;
    V4F_CATCH()
} // VRayPropertyMeta_destruct


FABRIC_EXT_EXPORT KL::UInt32
VRayPropertyMeta_getElementsCount (KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    return convert< KL::UInt32 >(meta->getElementsCount());

    V4F_CATCH (-1)
} // VRayPropertyMeta_getElementsCount


FABRIC_EXT_EXPORT void
VRayPropertyMeta_getName (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    _result = meta->getName().c_str();
    V4F_CATCH()
} // VRayPropertyMeta_getName


FABRIC_EXT_EXPORT KL::SInt32
VRayPropertyMeta_getType (KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    return convert< KL::SInt32 >(meta->getType());

    V4F_CATCH (-1)
} // VRayPropertyMeta_getType


FABRIC_EXT_EXPORT void
VRayPropertyMeta_getDefaultValue (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    _result = meta->getDefaultValue().c_str();
    V4F_CATCH()
} // VRayPropertyMeta_getDefaultValue


FABRIC_EXT_EXPORT void
VRayPropertyMeta_getDescription (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    _result = meta->getDescription().c_str();
    V4F_CATCH()
} // VRayPropertyMeta_getDescription


FABRIC_EXT_EXPORT void
VRayPropertyMeta_typeToString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam type)
{
    V4F_TRY
        _result = VRay::PropertyMeta::typeToString (static_cast< VRay::Type >(type)).c_str();

    V4F_CATCH()
} // VRayPropertyMeta_typeToString


FABRIC_EXT_EXPORT void
VRayPropertyMeta_typeToString_variant1 (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam type,
    KL::Traits< KL::UInt32 >::INParam count)
{
    V4F_TRY
        _result = VRay::PropertyMeta::typeToString (static_cast< VRay::Type >(type), convert< int >(count)).c_str();

    V4F_CATCH()
} // VRayPropertyMeta_typeToString_variant1


FABRIC_EXT_EXPORT void
VRayPropertyMeta_getTypeAsString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPropertyMeta >::INParam this_)
{
    V4F_TRY
    VRay::PropertyMeta *meta = static_cast< VRay::PropertyMeta* >(this_->pointer);

    _result = meta->getTypeAsString().c_str();
    V4F_CATCH()
} // VRayPropertyMeta_getTypeAsString







