#include "ImageRegion_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
ImageRegion_construct (KL::Traits< KL::ImageRegion >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::ImageRegion();

    V4F_CATCH()
} // ImageRegion_construct


FABRIC_EXT_EXPORT void
ImageRegion_destruct (KL::Traits< KL::ImageRegion >::IOParam this_)
{
    V4F_TRY
    this_->pointer = NULL;

    V4F_CATCH()
} // ImageRegion_destruct


FABRIC_EXT_EXPORT void
ImageRegion_set (
    KL::Traits< KL::ImageRegion >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam x,
    KL::Traits< KL::UInt32 >::INParam y,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    region->set (convert< int >(x), convert< int >(y), convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // ImageRegion_set


FABRIC_EXT_EXPORT void
ImageRegion_setX (
    KL::Traits< KL::ImageRegion >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam x)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    region->setX (convert< int >(x));
    V4F_CATCH()
} // ImageRegion_setX


FABRIC_EXT_EXPORT void
ImageRegion_setY (
    KL::Traits< KL::ImageRegion >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam y)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    region->setY (convert< int >(y));
    V4F_CATCH()
} // ImageRegion_setY


FABRIC_EXT_EXPORT void
ImageRegion_setWidth (
    KL::Traits< KL::ImageRegion >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam width)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    region->setWidth (convert< int >(width));
    V4F_CATCH()
} // ImageRegion_setWidth


FABRIC_EXT_EXPORT void
ImageRegion_setHeight (
    KL::Traits< KL::ImageRegion >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    region->setHeight (convert< int >(height));
    V4F_CATCH()
} // ImageRegion_setHeight


FABRIC_EXT_EXPORT KL::UInt32
ImageRegion_getX (KL::Traits< KL::ImageRegion >::INParam this_)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    return convert< KL::UInt32 >(region->getX());

    V4F_CATCH (0)
} // ImageRegion_getX


FABRIC_EXT_EXPORT KL::UInt32
ImageRegion_getY (KL::Traits< KL::ImageRegion >::INParam this_)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    return convert< KL::UInt32 >(region->getY());

    V4F_CATCH (0)
} // ImageRegion_getY


FABRIC_EXT_EXPORT KL::UInt32
ImageRegion_getWidth (KL::Traits< KL::ImageRegion >::INParam this_)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    return convert< KL::UInt32 >(region->getWidth());

    V4F_CATCH (0)
} // ImageRegion_getWidth


FABRIC_EXT_EXPORT KL::UInt32
ImageRegion_getHeight (KL::Traits< KL::ImageRegion >::INParam this_)
{
    V4F_TRY
    VRay::ImageRegion *region = static_cast< VRay::ImageRegion* >(this_->pointer);

    return convert< KL::UInt32 >(region->getHeight());

    V4F_CATCH (0)
} // ImageRegion_getHeight







