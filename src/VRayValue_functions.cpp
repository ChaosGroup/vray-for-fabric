#include "VRayValue_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"


using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayValue_construct (KL::Traits< KL::VRayValue >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value();

    V4F_CATCH()
} // VRayValue_construct


FABRIC_EXT_EXPORT void
VRayValue_construct_int (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::SInt32 >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< int >(value));

    V4F_CATCH()
} // VRayValue_construct_int


FABRIC_EXT_EXPORT void
VRayValue_construct_float (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::Float32 >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< float >(value));

    V4F_CATCH()
} // VRayValue_construct_float


FABRIC_EXT_EXPORT void
VRayValue_construct_bool (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::Boolean >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< bool >(value));

    V4F_CATCH()
} // VRayValue_construct_bool


FABRIC_EXT_EXPORT void
VRayValue_construct_color (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayColor >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< VRay::Color >(value));

    V4F_CATCH()
} // VRayValue_construct_color


FABRIC_EXT_EXPORT void
VRayValue_construct_acolor (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayAColor >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< VRay::AColor >(value));

    V4F_CATCH()
} // VRayValue_construct_acolor


FABRIC_EXT_EXPORT void
VRayValue_construct_vector (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayVector >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< VRay::Vector >(value));

    V4F_CATCH()
} // VRayValue_construct_vector


FABRIC_EXT_EXPORT void
VRayValue_construct_matrix (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayMatrix >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< VRay::Matrix >(value));

    V4F_CATCH()
} // VRayValue_construct_matrix


FABRIC_EXT_EXPORT void
VRayValue_construct_transform (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayTransform >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (convert< VRay::Transform >(value));

    V4F_CATCH()
} // VRayValue_construct_transform


FABRIC_EXT_EXPORT void
VRayValue_construct_intlist (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VariableArray< KL::SInt32 > >::INParam list)
{
    V4F_TRY
    VRay::IntList ints;

    for (int i = 0; i < list.size(); i++) {
        ints.push_back (convert< int >(list[i]));
    }

    this_->pointer = (void*) new VRay::Value (ints);
    V4F_CATCH()
} // VRayValue_construct_intlist


FABRIC_EXT_EXPORT void
VRayValue_construct_floatlist (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VariableArray< KL::Float32 > >::INParam list)
{
    V4F_TRY
    VRay::FloatList floats;

    for (int i = 0; i < list.size(); i++) {
        floats.push_back (convert< float >(list[i]));
    }

    this_->pointer = (void*) new VRay::Value (floats);
    V4F_CATCH()
} // VRayValue_construct_floatlist


FABRIC_EXT_EXPORT void
VRayValue_construct_vectorlist (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VariableArray< KL::VRayVector > >::INParam list)
{
    V4F_TRY
    VRay::VectorList vectors;

    for (int i = 0; i < list.size(); i++) {
        vectors.push_back (convert< VRay::Vector >(list[i]));
    }

    this_->pointer = (void*) new VRay::Value (vectors);
    V4F_CATCH()
} // VRayValue_construct_vectorlist


FABRIC_EXT_EXPORT void
VRayValue_construct_colorlist (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VariableArray< KL::VRayColor > >::INParam list)
{
    V4F_TRY
    VRay::ColorList colors;

    for (int i = 0; i < list.size(); i++) {
        colors.push_back (convert< VRay::Color >(list[i]));
    }

    this_->pointer = (void*) new VRay::Value (colors);
    V4F_CATCH()
} // VRayValue_construct_colorlist


FABRIC_EXT_EXPORT void
VRayValue_construct_valuelist (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VariableArray< KL::VRayValue > >::INParam list)
{
    V4F_TRY
    VRay::ValueList values;

    for (int i = 0; i < list.size(); i++) {
        VRay::Value *value = static_cast< VRay::Value* >(list[i]->pointer);
        values.push_back (*value);
    }

    this_->pointer = (void*) new VRay::Value (values);
    V4F_CATCH()
} // VRayValue_construct_valuelist


FABRIC_EXT_EXPORT void
VRayValue_construct_string (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::String >::INParam value)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::Value (std::string (value.c_str()));

    V4F_CATCH()
} // VRayValue_construct_string


FABRIC_EXT_EXPORT void
VRayValue_construct_plugin (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayPlugin >::INParam plugin)
{
    V4F_TRY
    VRay::Plugin *p = static_cast< VRay::Plugin* >(plugin->pointer);

    this_->pointer = (void*) new VRay::Value (*p);
    V4F_CATCH()
} // VRayValue_construct_plugin


FABRIC_EXT_EXPORT void
VRayValue_construct_renderer_id (
    KL::Traits< KL::VRayValue >::IOParam this_,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::UInt64 >::INParam id)
{
    V4F_TRY
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(renderer->pointer);

    this_->pointer = (void*) new VRay::Value (rndr, convert< VRay::InstanceId >(id));
    V4F_CATCH()
} // VRayValue_construct_renderer_id


FABRIC_EXT_EXPORT void
VRayValue_destruct (KL::Traits< KL::VRayValue >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::Value* >(this_->pointer);
    this_->pointer = NULL;
    V4F_CATCH()
} // VRayValue_destruct


FABRIC_EXT_EXPORT KL::SInt32
VRayValue_getType (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::SInt32 >(value->getType());

    V4F_CATCH (-1)
} // VRayValue_getType


FABRIC_EXT_EXPORT KL::UInt32
VRayValue_getCount (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::UInt32 >(value->getCount());

    V4F_CATCH (-1)
} // VRayValue_getCount


FABRIC_EXT_EXPORT KL::Boolean
VRayValue_isList (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::Boolean >(value->isList());

    V4F_CATCH (false)
} // VRayValue_isList


FABRIC_EXT_EXPORT KL::SInt32
VRayValue_getInt (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::SInt32 >(value->getInt());

    V4F_CATCH (-1)
} // VRayValue_getInt


FABRIC_EXT_EXPORT KL::Float32
VRayValue_getFloat (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::Float32 >(value->getFloat());

    V4F_CATCH (-1)
} // VRayValue_getFloat


FABRIC_EXT_EXPORT KL::Boolean
VRayValue_getBool (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::Boolean >(value->getBool());

    V4F_CATCH (false)
} // VRayValue_getBool


FABRIC_EXT_EXPORT void
VRayValue_getColor (
    KL::Traits< KL::VRayColor >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = convert< KL::VRayColor >(value->getColor());
    V4F_CATCH()
} // VRayValue_getColor


FABRIC_EXT_EXPORT void
VRayValue_getAColor (
    KL::Traits< KL::VRayAColor >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = convert< KL::VRayAColor >(value->getAColor());
    V4F_CATCH()
} // VRayValue_getAColor


FABRIC_EXT_EXPORT void
VRayValue_getVector (
    KL::Traits< KL::VRayVector >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = convert< KL::VRayVector >(value->getVector());
    V4F_CATCH()
} // VRayValue_getVector


FABRIC_EXT_EXPORT void
VRayValue_getMatrix (
    KL::Traits< KL::VRayMatrix >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = convert< KL::VRayMatrix >(value->getMatrix());
    V4F_CATCH()
} // VRayValue_getMatrix


FABRIC_EXT_EXPORT void
VRayValue_getTransform (
    KL::Traits< KL::VRayTransform >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = convert< KL::VRayTransform >(value->getTransform());
    V4F_CATCH()
} // VRayValue_getTransform


FABRIC_EXT_EXPORT void
VRayValue_getIntList (
    KL::Traits< KL::VariableArray< KL::SInt32 > >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::IntList ints = value->getIntList();

    for (VRay::IntList::const_iterator it = ints.begin(); it != ints.end(); ++it) {
        _result.push_back (convert< KL::SInt32 >(*it));
    }

    V4F_CATCH()
} // VRayValue_getIntList


FABRIC_EXT_EXPORT void
VRayValue_getFloatList (
    KL::Traits< KL::VariableArray< KL::Float32 > >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::FloatList floats = value->getFloatList();

    for (VRay::FloatList::const_iterator it = floats.begin(); it != floats.end(); ++it) {
        _result.push_back (convert< KL::Float32 >(*it));
    }

    V4F_CATCH()
} // VRayValue_getFloatList


FABRIC_EXT_EXPORT void
VRayValue_getColorList (
    KL::Traits< KL::VariableArray< KL::VRayColor > >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::ColorList colors = value->getColorList();

    for (VRay::ColorList::const_iterator it = colors.begin(); it != colors.end(); ++it) {
        _result.push_back (convert< KL::VRayColor >(*it));
    }

    V4F_CATCH()
} // VRayValue_getColorList


FABRIC_EXT_EXPORT void
VRayValue_getVectorList (
    KL::Traits< KL::VariableArray< KL::VRayVector > >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::VectorList vectors = value->getVectorList();

    for (VRay::VectorList::const_iterator it = vectors.begin(); it != vectors.end(); ++it) {
        _result.push_back (convert< KL::VRayVector >(*it));
    }

    V4F_CATCH()
} // VRayValue_getVectorList


FABRIC_EXT_EXPORT void
VRayValue_getValueList (
    KL::Traits< KL::VariableArray< KL::VRayValue > >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::ValueList values = value->getValueList();

    for (VRay::ValueList::const_iterator it = values.begin(); it != values.end(); ++it) {
        KL::VRayValue value = KL::VRayValue::Create();
        VRay::Value *v = new VRay::Value (*it);
        value->pointer = v;
        _result.push_back (value);
    }

    V4F_CATCH()
} // VRayValue_getValueList


FABRIC_EXT_EXPORT void
VRayValue_getString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = value->getString().c_str();
    V4F_CATCH()
} // VRayValue_getString


FABRIC_EXT_EXPORT KL::UInt64
VRayValue_getInstanceId (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::UInt64 >(value->getInstanceId());

    V4F_CATCH (-1)
} // VRayValue_getInstanceId


FABRIC_EXT_EXPORT void
VRayValue_getPlugin (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (value->getPlugin());

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayValue_getPlugin


FABRIC_EXT_EXPORT KL::Boolean
VRayValue_isOK (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::Boolean >(value->isOK());

    V4F_CATCH (false)
} // VRayValue_isOK


FABRIC_EXT_EXPORT KL::Boolean
VRayValue_isBad (KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    return convert< KL::Boolean >(value->isBad());

    V4F_CATCH (false)
} // VRayValue_isBad


FABRIC_EXT_EXPORT void
VRayValue_getStringType (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = value->getStringType();
    V4F_CATCH()
} // VRayValue_getStringType


FABRIC_EXT_EXPORT void
VRayValue_toString (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayValue >::INParam this_)
{
    V4F_TRY
    VRay::Value *value = static_cast< VRay::Value* >(this_->pointer);

    _result = value->toString().c_str();
    V4F_CATCH()
} // VRayValue_toString







