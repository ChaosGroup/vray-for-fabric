#include "RenderElement_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
RenderElement_construct (KL::Traits< KL::RenderElement >::IOParam this_)
{
    //this_->pointer = NULL;
} // RenderElement_construct


FABRIC_EXT_EXPORT void
RenderElement_destruct (KL::Traits< KL::RenderElement >::IOParam this_)
{
    this_->pointer = NULL;
} // RenderElement_destruct


FABRIC_EXT_EXPORT KL::UInt32
RenderElement_getIndex (KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    return convert< KL::UInt32 >(elem->getIndex());

    V4F_CATCH (-1)
} // RenderElement_getIndex


FABRIC_EXT_EXPORT void
RenderElement_getName (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    _result = elem->getName().c_str();
    V4F_CATCH()
} // RenderElement_getName


FABRIC_EXT_EXPORT KL::SInt32
RenderElement_getType (KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    return convert< KL::SInt32 >(elem->getType());

    V4F_CATCH (-1)
} // RenderElement_getType


FABRIC_EXT_EXPORT KL::SInt32
RenderElement_getBinaryFormat (KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    return convert< KL::SInt32 >(elem->getBinaryFormat());

    V4F_CATCH (-1)
} // RenderElement_getBinaryFormat


FABRIC_EXT_EXPORT KL::SInt32
RenderElement_getDefaultPixelFormat (KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    return convert< KL::SInt32 >(elem->getDefaultPixelFormat());

    V4F_CATCH (-1)
} // RenderElement_getDefaultPixelFormat


FABRIC_EXT_EXPORT void
RenderElement_getImage (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::RenderElement >::INParam this_)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = elem->getImage();
    V4F_CATCH()
} // RenderElement_getImage


FABRIC_EXT_EXPORT void
RenderElement_getImage_variant1 (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::RenderElement >::INParam this_,
    KL::Traits< KL::ImageRegion >::INParam region)
{
    V4F_TRY
    VRay::RenderElement *elem = static_cast< VRay::RenderElement* >(this_->pointer);
    VRay::ImageRegion *reg = static_cast< VRay::ImageRegion* >(region->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = elem->getImage (reg);
    V4F_CATCH()
} // RenderElement_getImage_variant1







