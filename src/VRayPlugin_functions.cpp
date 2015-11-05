#include "VRayPlugin_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

#include <iostream>

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayPlugin_construct (KL::Traits< KL::VRayPlugin >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Plugin();

    V4F_CATCH()
} // VRayPlugin_construct


FABRIC_EXT_EXPORT void
VRayPlugin_construct_variant1 (
    KL::Traits< KL::VRayPlugin >::IOParam this_,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::String >::INParam name)
{
    V4F_TRY
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(this_->pointer);

    this_->pointer = (void*) new VRay::Plugin (rndr, std::string (name.c_str()));
    V4F_CATCH()
} // VRayPlugin_construct_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_construct_variant2 (
    KL::Traits< KL::VRayPlugin >::IOParam this_,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::UInt64 >::INParam id)
{
    V4F_TRY
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(this_->pointer);

    this_->pointer = (void*) new VRay::Plugin (rndr, static_cast< VRay::InstanceId >(id));
    V4F_CATCH()
} // VRayPlugin_construct_variant2


FABRIC_EXT_EXPORT void
VRayPlugin_destruct (KL::Traits< KL::VRayPlugin >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::Plugin* >(this_->pointer);
    this_->pointer = NULL;
    V4F_CATCH()
} // VRayPlugin_destruct


FABRIC_EXT_EXPORT void
VRayPlugin_getRenderer (
    KL::Traits< KL::VRayRenderer >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = KL::VRayRenderer::Create();
    _result->pointer = plugin->getRenderer();
    V4F_CATCH()
} // VRayPlugin_getRenderer


FABRIC_EXT_EXPORT void
VRayPlugin_getName (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = plugin->getName().c_str();
    V4F_CATCH()
} // VRayPlugin_getName


FABRIC_EXT_EXPORT void
VRayPlugin_getType (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = plugin->getType().c_str();
    V4F_CATCH()
} // VRayPlugin_getType


FABRIC_EXT_EXPORT KL::UInt64
VRayPlugin_getId (KL::Traits< KL::VRayPlugin >::INParam this_)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::UInt64 >(plugin->getId());

    V4F_CATCH (-1)
} // VRayPlugin_getId


FABRIC_EXT_EXPORT void
VRayPlugin_getMeta (
    KL::Traits< KL::VRayPluginMeta >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    VRay::PluginMeta *meta = new VRay::PluginMeta (plugin->getMeta());

    _result = KL::VRayPluginMeta::Create();
    _result->pointer = meta;
    V4F_CATCH()
} // VRayPlugin_getMeta


FABRIC_EXT_EXPORT void
VRayPlugin_getPropertyRuntimeMeta (
    KL::Traits< KL::VRayPropertyRuntimeMeta >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    VRay::PropertyRuntimeMeta *meta = new VRay::PropertyRuntimeMeta (plugin->getPropertyRuntimeMeta (propertyName.c_str()));

    _result = KL::VRayPropertyRuntimeMeta::Create();
    _result->pointer = meta;
    V4F_CATCH()
} // VRayPlugin_getPropertyRuntimeMeta


FABRIC_EXT_EXPORT void
VRayPlugin_getValueAsString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = plugin->getValueAsString (propertyName.c_str());
    V4F_CATCH()
} // VRayPlugin_getValueAsString


FABRIC_EXT_EXPORT void
VRayPlugin_getValueAsString_variant1 (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = plugin->getValueAsString (propertyName.c_str(), success);
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getValueAsString_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAsString (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::String >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAsString (propertyName.c_str(), value.c_str()));

    V4F_CATCH (false)
} // VRayPlugin_setValueAsString


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAsStringAtTime (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::String >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAsStringAtTime (propertyName.c_str(), value.c_str(), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAsStringAtTime


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_getBool (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->getBool (propertyName.c_str()));

    V4F_CATCH (false)
} // VRayPlugin_getBool


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_getBool_variant1 (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;
    bool result = plugin->getBool (propertyName.c_str(), success);

    ok = convert< KL::Boolean >(success);

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayPlugin_getBool_variant1


FABRIC_EXT_EXPORT KL::SInt32
VRayPlugin_getInt (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::SInt32 >(plugin->getInt (propertyName.c_str()));

    V4F_CATCH (-1)
} // VRayPlugin_getInt


FABRIC_EXT_EXPORT KL::SInt32
VRayPlugin_getInt_variant1 (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;
    int result = plugin->getInt (propertyName.c_str(), success);

    ok = convert< KL::Boolean >(success);

    return convert< KL::SInt32 >(result);

    V4F_CATCH (-1)
} // VRayPlugin_getInt_variant1


FABRIC_EXT_EXPORT KL::Float32
VRayPlugin_getFloat (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Float32 >(plugin->getFloat (propertyName.c_str()));

    V4F_CATCH (-1)
} // VRayPlugin_getFloat


FABRIC_EXT_EXPORT KL::Float32
VRayPlugin_getFloat_variant1 (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;
    float result = plugin->getFloat (propertyName.c_str(), success);

    ok = convert< KL::Boolean >(success);

    return convert< KL::SInt32 >(result);

    V4F_CATCH (-1)
} // VRayPlugin_getFloat_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_getColor (
    KL::Traits< KL::VRayColor >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = convert< KL::VRayColor >(plugin->getColor (propertyName.c_str()));
    V4F_CATCH()
} // VRayPlugin_getColor


FABRIC_EXT_EXPORT void
VRayPlugin_getColor_variant1 (
    KL::Traits< KL::VRayColor >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = convert< KL::VRayColor >(plugin->getColor (propertyName.c_str(), success));
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getColor_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_getAColor (
    KL::Traits< KL::VRayAColor >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = convert< KL::VRayAColor >(plugin->getAColor (propertyName.c_str()));
    V4F_CATCH()
} // VRayPlugin_getAColor


FABRIC_EXT_EXPORT void
VRayPlugin_getAColor_variant1 (
    KL::Traits< KL::VRayAColor >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = convert< KL::VRayAColor >(plugin->getAColor (propertyName.c_str(), success));
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getAColor_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_getVector (
    KL::Traits< KL::VRayVector >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = convert< KL::VRayVector >(plugin->getVector (propertyName.c_str()));
    V4F_CATCH()
} // VRayPlugin_getVector


FABRIC_EXT_EXPORT void
VRayPlugin_getVector_variant1 (
    KL::Traits< KL::VRayVector >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = convert< KL::VRayVector >(plugin->getVector (propertyName.c_str(), success));
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getVector_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_getMatrix (
    KL::Traits< KL::VRayMatrix >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = convert< KL::VRayMatrix >(plugin->getMatrix (propertyName.c_str()));
    V4F_CATCH()
} // VRayPlugin_getMatrix


FABRIC_EXT_EXPORT void
VRayPlugin_getMatrix_variant1 (
    KL::Traits< KL::VRayMatrix >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = convert< KL::VRayMatrix >(plugin->getMatrix (propertyName.c_str(), success));
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getMatrix_variant1


FABRIC_EXT_EXPORT void
VRayPlugin_getTransform (
    KL::Traits< KL::VRayTransform >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    _result = convert< KL::VRayTransform >(plugin->getTransform (propertyName.c_str()));
    V4F_CATCH()
} // VRayPlugin_getTransform


FABRIC_EXT_EXPORT void
VRayPlugin_getTransform_variant1 (
    KL::Traits< KL::VRayTransform >::Result _result,
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::IOParam ok)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    bool success;

    _result = convert< KL::VRayTransform >(plugin->getTransform (propertyName.c_str(), success));
    ok = convert< KL::Boolean >(success);
    V4F_CATCH()
} // VRayPlugin_getTransform_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_isAnimated (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->isAnimated (propertyName.c_str()));

    V4F_CATCH (false)
} // VRayPlugin_isAnimated


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueBool (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< bool >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueBool


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeBool (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Boolean >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< bool >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeBool


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueInt (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::SInt32 >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< int >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueInt


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeInt (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::SInt32 >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< int >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeInt


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueFloat (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Float32 >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< float >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueFloat


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeFloat (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::Float32 >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< float >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeFloat


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueColor (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayColor >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< VRay::Color >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueColor


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeColor (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayColor >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< VRay::Color >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeColor


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAColor (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayAColor >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< VRay::AColor >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAColor


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeAColor (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayAColor >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< VRay::AColor >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeAColor


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueVector (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayVector >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< VRay::Vector >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueVector


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeVector (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayVector >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< VRay::Vector >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeVector


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueMatrix (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayMatrix >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< VRay::Matrix >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueMatrix


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeMatrix (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayMatrix >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< VRay::Matrix >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeMatrix


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueTransform (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayTransform >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), convert< VRay::Transform >(value)));

    V4F_CATCH (false)
} // VRayPlugin_setValueTransform


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeTransform (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayTransform >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), convert< VRay::Transform >(value), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeTransform


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValuePlugin (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayPlugin >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);
    VRay::Plugin *outPlugin = static_cast< VRay::Plugin* >(value->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), *outPlugin));

    V4F_CATCH (false)
} // VRayPlugin_setValuePlugin


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimePlugin (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayPlugin >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);
    VRay::Plugin *outPlugin = static_cast< VRay::Plugin* >(value->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), *outPlugin, convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimePlugin


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueString (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::String >::INParam value)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), value.c_str()));

    V4F_CATCH (false)
} // VRayPlugin_setValueString


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValueAtTimeString (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::String >::INParam value,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);

    return convert< KL::Boolean >(plugin->setValueAtTime (propertyName.c_str(), value.c_str(), convert< double >(time)));

    V4F_CATCH (false)
} // VRayPlugin_setValueAtTimeString


FABRIC_EXT_EXPORT KL::Boolean
VRayPlugin_setValuePluginOut (
    KL::Traits< KL::VRayPlugin >::INParam this_,
    KL::Traits< KL::String >::INParam propertyName,
    KL::Traits< KL::VRayPlugin >::INParam outPlugin,
    KL::Traits< KL::String >::INParam outPropertyName)
{
    V4F_TRY
    VRay::Plugin *plugin = static_cast< VRay::Plugin* >(this_->pointer);
    VRay::Plugin *out = static_cast< VRay::Plugin* >(outPlugin->pointer);

    return convert< KL::Boolean >(plugin->setValue (propertyName.c_str(), *out, outPropertyName.c_str()));

    V4F_CATCH (false)
} // VRayPlugin_setValuePluginOut







