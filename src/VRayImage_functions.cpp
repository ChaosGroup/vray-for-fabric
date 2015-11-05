#include "VRayImage_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayImage_construct (
    KL::Traits< KL::VRayImage >::IOParam this_,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = VRay::VRayImage::create (width, height);

    this_->pointer = image;
    V4F_CATCH()
} // VRayImage_construct


FABRIC_EXT_EXPORT void
VRayImage_destruct (KL::Traits< KL::VRayImage >::IOParam this_)
{
    V4F_TRY
    delete ((VRay::VRayImage*) this_->pointer);
    this_->pointer = NULL;
    V4F_CATCH()
} // VRayImage_destruct


FABRIC_EXT_EXPORT KL::UInt32
VRayImage_getWidth_ (KL::Traits< KL::VRayImage >::INParam this_)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    return convert< KL::UInt32 >(image->getWidth());

    V4F_CATCH (-1)
} // VRayImage_getWidth


FABRIC_EXT_EXPORT KL::UInt32
VRayImage_getHeight_ (KL::Traits< KL::VRayImage >::INParam this_)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    return convert< KL::UInt32 >(image->getHeight());

    V4F_CATCH (-1)
} // VRayImage_getHeight


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_getSize_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::IOParam width,
    KL::Traits< KL::UInt32 >::IOParam height)
{
    V4F_TRY
    bool result = false;
    int _width = 0;
    int _height = 0;

    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->getSize (_width, _height)) {
        width = convert< KL::UInt32 >(_width);
        height = convert< KL::UInt32 >(_height);
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_getSize_


// Defined at src//VRayImage.kl:15:1
FABRIC_EXT_EXPORT void
VRayImage_duplicate_ (
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::VRayImage >::Result _result,
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::VRayImage >::INParam this_)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->clone();
    V4F_CATCH()
} // VRayImage_duplicate_


FABRIC_EXT_EXPORT void
VRayImage_crop_ (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam x,
    KL::Traits< KL::UInt32 >::INParam y,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->crop (convert< int >(x), convert< int >(y), convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // VRayImage_crop_


FABRIC_EXT_EXPORT void
VRayImage_downscale_ (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->downscale (convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // VRayImage_downscale_


FABRIC_EXT_EXPORT void
VRayImage_downscale_variant1 (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam srcx,
    KL::Traits< KL::UInt32 >::INParam srcy,
    KL::Traits< KL::UInt32 >::INParam srcwidth,
    KL::Traits< KL::UInt32 >::INParam srcheight,
    KL::Traits< KL::UInt32 >::INParam dstwidth,
    KL::Traits< KL::UInt32 >::INParam dstheight)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->downscale (convert< int >(srcx), convert< int >(srcy), convert< int >(srcwidth), convert< int >(srcheight), convert< int >(dstwidth), convert< int >(dstheight));
    V4F_CATCH()
} // VRayImage_downscale_variant1


FABRIC_EXT_EXPORT void
VRayImage_fitIn_ (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->fitIn (convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // VRayImage_fitIn_


FABRIC_EXT_EXPORT void
VRayImage_fitOut_ (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->fitOut (convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // VRayImage_fitOut_


FABRIC_EXT_EXPORT void
VRayImage_cutIn_ (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam width,
    KL::Traits< KL::UInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = image->cutIn (convert< int >(width), convert< int >(height));
    V4F_CATCH()
} // VRayImage_cutIn_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_draw_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::VRayImage >::INParam image,
    KL::Traits< KL::UInt32 >::INParam x,
    KL::Traits< KL::UInt32 >::INParam y)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *this_image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::VRayImage *that_image = static_cast< VRay::VRayImage* >(image->pointer);

    if (this_image->draw (that_image, convert< int >(x), convert< int >(y))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_draw_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_addColor_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::VRayColor >::INParam color)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::Color rgb (convert< float >(color.r), convert< float >(color.g), convert< float >(color.b));

    if (image->addColor (rgb)) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_addColor_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_addAColor_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::VRayAColor >::INParam color)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::AColor rgba (convert< float >(color.color.r), convert< float >(color.color.g), convert< float >(color.color.b), convert< float >(color.alpha));

    if (image->addColor (rgba)) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_addAColor_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_changeExposure_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::Float32 >::INParam ev)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->changeExposure (convert< float >(ev))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_changeExposure_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_changeGamma_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::Float32 >::INParam gamma)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->changeGamma (convert< float >(gamma))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_changeGamma_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_changeContrast_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::Float32 >::INParam contrast)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->changeContrast (convert< float >(contrast))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_changeContrast_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_makeNegative_ (KL::Traits< KL::VRayImage >::INParam this_)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->makeNegative()) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_makeNegative_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToBmpFile_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::Boolean >::INParam preserveAlpha)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->saveToBmpFile (std::string (fileName.c_str()), convert< bool >(preserveAlpha))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToBmpFile_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToBmpFile_variant1 (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::Boolean >::INParam preserveAlpha)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(renderer->pointer);

    if (image->saveToBmpFile (std::string (fileName.c_str()), *rndr, convert< bool >(preserveAlpha))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToBmpFile_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToPngFile_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::Boolean >::INParam preserveAlpha)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->saveToPngFile (std::string (fileName.c_str()), convert< bool >(preserveAlpha))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToPngFile_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToPngFile_variant1 (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::Boolean >::INParam preserveAlpha)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(renderer->pointer);

    if (image->saveToPngFile (std::string (fileName.c_str()), *rndr, convert< bool >(preserveAlpha))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToPngFile_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToJpegFile_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::UInt32 >::INParam quality)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->saveToJpegFile (std::string (fileName.c_str()), convert< int >(quality))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToJpegFile_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToJpegFile_variant1 (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::UInt32 >::INParam quality)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(renderer->pointer);

    if (image->saveToJpegFile (std::string (fileName.c_str()), *rndr, convert< int >(quality))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToJpegFile_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToWebpFile_ (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::UInt32 >::INParam quality)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);

    if (image->saveToWebpFile (std::string (fileName.c_str()), convert< int >(quality))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToWebpFile_


FABRIC_EXT_EXPORT KL::Boolean
VRayImage_saveToWebpFile_variant1 (
    KL::Traits< KL::VRayImage >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::VRayRenderer >::INParam renderer,
    KL::Traits< KL::UInt32 >::INParam quality)
{
    V4F_TRY
    bool result = false;
    VRay::VRayImage *image = static_cast< VRay::VRayImage* >(this_->pointer);
    VRay::VRayRenderer *rndr = static_cast< VRay::VRayRenderer* >(renderer->pointer);

    if (image->saveToWebpFile (std::string (fileName.c_str()), *rndr, convert< int >(quality))) {
        result = true;
    }

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayImage_saveToWebpFile_variant1







