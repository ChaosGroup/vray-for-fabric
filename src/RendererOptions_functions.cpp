#include "RendererOptions_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
RendererOptions_construct (KL::Traits< KL::RendererOptions >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::RendererOptions();

    V4F_CATCH()
} // RendererOptions_construct


FABRIC_EXT_EXPORT void
RendererOptions_destruct (KL::Traits< KL::RendererOptions >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::RendererOptions* >(this_->pointer);

    this_->pointer = NULL;
    V4F_CATCH()
} // RendererOptions_destruct


FABRIC_EXT_EXPORT KL::UInt32
RendererOptions_imageWidth (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);
    KL::UInt32 _imagewidth = convert< KL::UInt32 >(options->imageWidth);

    return _imagewidth;

    V4F_CATCH (-1)
} // RendererOptions_imageWidth


FABRIC_EXT_EXPORT void
RendererOptions_setImageWidth (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam imagewidth)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->imageWidth = convert< int >(imagewidth);
    V4F_CATCH()
} // RendererOptions_setImageWidth


FABRIC_EXT_EXPORT KL::UInt32
RendererOptions_imageHeight (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::UInt32 >(options->imageHeight);

    V4F_CATCH (-1)
} // RendererOptions_imageHeight


FABRIC_EXT_EXPORT void
RendererOptions_setImageHeight (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam imageheight)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->imageHeight = convert< int >(imageheight);
    V4F_CATCH()
} // RendererOptions_setImageHeight


FABRIC_EXT_EXPORT KL::SInt32
RendererOptions_renderMode (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::SInt32 >(options->renderMode);

    V4F_CATCH (-1)
} // RendererOptions_renderMode


FABRIC_EXT_EXPORT void
RendererOptions_setRenderMode (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam rendermode)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->renderMode = convert< VRay::RendererOptions::RenderMode >(rendermode);
    V4F_CATCH()
} // RendererOptions_setRenderMode


FABRIC_EXT_EXPORT KL::UInt32
RendererOptions_rtSampleLevel (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::UInt32 >(options->rtSampleLevel);

    V4F_CATCH (-1)
} // RendererOptions_rtSampleLevel


FABRIC_EXT_EXPORT void
RendererOptions_setRTSampleLevel (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam rtsamplelevel)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->rtSampleLevel = convert< int >(rtsamplelevel);
    V4F_CATCH()
} // RendererOptions_setRTSampleLevel


FABRIC_EXT_EXPORT KL::Float32
RendererOptions_rtNoiseThreshold (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::Float32 >(options->rtNoiseThreshold);

    V4F_CATCH (-1)
} // RendererOptions_rtNoiseThreshold


FABRIC_EXT_EXPORT void
RendererOptions_setRTNoiseThreshold (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::Float32 >::INParam rtnoisethreshold)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->rtNoiseThreshold = convert< float >(rtnoisethreshold);
    V4F_CATCH()
} // RendererOptions_setRTNoiseThreshold


FABRIC_EXT_EXPORT KL::UInt64
RendererOptions_rtTimeout (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::UInt64 >(options->rtTimeout);

    V4F_CATCH (-1)
} // RendererOptions_rtTimeout


FABRIC_EXT_EXPORT void
RendererOptions_setRTTimeout (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::UInt64 >::INParam rttimeout)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->rtTimeout = convert< long >(rttimeout);
    V4F_CATCH()
} // RendererOptions_setRTTimeout


FABRIC_EXT_EXPORT KL::UInt32
RendererOptions_numThreads (KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    return convert< KL::UInt32 >(options->numThreads);

    V4F_CATCH (-1)
} // RendererOptions_numThreads


FABRIC_EXT_EXPORT void
RendererOptions_setNumThreads (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam numthreads)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->numThreads = convert< int >(numthreads);
    V4F_CATCH()
} // RendererOptions_setNumThreads


FABRIC_EXT_EXPORT void
RendererOptions_flags (
    KL::Traits< KL::RendererFlags >::Result _result,
    KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    _result.enableFrameBuffer = convert< KL::Boolean >(options->enableFrameBuffer);
    _result.showFrameBuffer = convert< KL::Boolean >(options->showFrameBuffer);
    _result.inProcess = convert< KL::Boolean >(options->inProcess);
    _result.keepRTRunning = convert< KL::Boolean >(options->keepRTRunning);
    _result.transferAssets = convert< KL::Boolean >(options->transferAssets);
    _result.useCachedAssets = convert< KL::Boolean >(options->useCachedAssets);
    _result.bakeGamma = convert< KL::Boolean >(options->bakeGamma);
    _result.noRenderLicensePreCheck = convert< KL::Boolean >(options->noRenderLicensePreCheck);
    _result.noDR = convert< KL::Boolean >(options->noDR);
    V4F_CATCH()
} // RendererOptions_flags


FABRIC_EXT_EXPORT void
RendererOptions_setFlags (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::RendererFlags >::INParam flags)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->enableFrameBuffer = convert< bool >(flags.enableFrameBuffer);
    options->showFrameBuffer = convert< bool >(flags.showFrameBuffer);
    options->inProcess = convert< bool >(flags.inProcess);
    options->keepRTRunning = convert< bool >(flags.keepRTRunning);
    options->transferAssets = convert< bool >(flags.transferAssets);
    options->useCachedAssets = convert< bool >(flags.useCachedAssets);
    options->bakeGamma = convert< bool >(flags.bakeGamma);
    options->noRenderLicensePreCheck = convert< bool >(flags.noRenderLicensePreCheck);
    options->noDR = convert< bool >(flags.noDR);
    V4F_CATCH()
} // RendererOptions_setFlags


FABRIC_EXT_EXPORT void
RendererOptions_pluginLibraryPath (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::RendererOptions >::INParam this_)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    _result = options->pluginLibraryPath.c_str();
    V4F_CATCH()
} // RendererOptions_pluginLibraryPath


FABRIC_EXT_EXPORT void
RendererOptions_setPluginLibraryPath (
    KL::Traits< KL::RendererOptions >::INParam this_,
    KL::Traits< KL::String >::INParam pluginLibraryPath)
{
    V4F_TRY
    VRay::RendererOptions *options = static_cast< VRay::RendererOptions* >(this_->pointer);

    options->pluginLibraryPath = std::string (pluginLibraryPath.c_str());
    V4F_CATCH()
} // RendererOptions_setPluginLibraryPath







