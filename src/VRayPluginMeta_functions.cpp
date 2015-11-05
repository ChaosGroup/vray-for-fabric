#include "VRayPluginMeta_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayPluginMeta_construct (KL::Traits< KL::VRayPluginMeta >::IOParam this_)
{
    V4F_TRY
    VRay::PluginMeta *meta;

    this_->pointer = meta;
    V4F_CATCH()
} // VRayPluginMeta_construct


FABRIC_EXT_EXPORT void
VRayPluginMeta_destruct (KL::Traits< KL::VRayPluginMeta >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::PluginMeta* >(this_->pointer);
    V4F_CATCH()
} // VRayPluginMeta_destruct


FABRIC_EXT_EXPORT void
VRayPluginMeta_getType (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPluginMeta >::INParam this_)
{
    V4F_TRY
    VRay::PluginMeta *meta = static_cast< VRay::PluginMeta* >(this_->pointer);

    _result = meta->getType().c_str();
    V4F_CATCH()
} // VRayPluginMeta_getType


FABRIC_EXT_EXPORT void
VRayPluginMeta_getPropertyNames (
    KL::Traits< KL::VariableArray< KL::String > >::Result _result,
    KL::Traits< KL::VRayPluginMeta >::INParam this_)
{
    V4F_TRY
    VRay::PluginMeta *meta = static_cast< VRay::PluginMeta* >(this_->pointer);

    std::vector< std::string > names = meta->getPropertyNames();

    for (std::vector< std::string >::const_iterator it = names.begin(); it != names.end(); ++it) {
        _result.push (it->c_str());
    }

    V4F_CATCH()
} // VRayPluginMeta_getPropertyNames


FABRIC_EXT_EXPORT void
VRayPluginMeta_getProperty (
    KL::Traits< KL::VRayPropertyMeta >::Result _result,
    KL::Traits< KL::VRayPluginMeta >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::PluginMeta *meta = static_cast< VRay::PluginMeta* >(this_->pointer);
    VRay::PropertyMeta *propmeta = new VRay::PropertyMeta (meta->getProperty (std::string (propertyName.c_str())));

    _result = KL::VRayPropertyMeta::Create();
    _result->pointer = propmeta;
    V4F_CATCH()
} // VRayPluginMeta_getProperty







