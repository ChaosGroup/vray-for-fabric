#include "VRayRenderer_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
VRayRenderer_construct (KL::Traits< KL::VRayRenderer >::IOParam this_)
{
    V4F_TRY
    this_->pointer = (void*) new VRay::VRayRenderer();

    V4F_CATCH()
} // VRayRenderer_construct


FABRIC_EXT_EXPORT void
VRayRenderer_construct_variant1 (
    KL::Traits< KL::VRayRenderer >::IOParam this_,
    KL::Traits< KL::RendererOptions >::INParam options)
{
    V4F_TRY
    VRay::RendererOptions *opts = static_cast< VRay::RendererOptions* >(options->pointer);

    this_->pointer = (void*) new VRay::VRayRenderer (*opts);
    V4F_CATCH()
} // VRayRenderer_construct_variant1


FABRIC_EXT_EXPORT void
VRayRenderer_destruct (KL::Traits< KL::VRayRenderer >::IOParam this_)
{
    V4F_TRY
    delete static_cast< VRay::VRayRenderer* >(this_->pointer);
    this_->pointer = NULL;
    V4F_CATCH()
} // VRayRenderer_destruct


FABRIC_EXT_EXPORT void
VRayRenderer_getLastError (
    KL::Traits< KL::VRayError >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::Error *error = new VRay::Error (renderer->getLastError().getCode());

    _result = KL::VRayError::Create();
    _result->pointer = error;
    V4F_CATCH()
} // VRayRenderer_getLastError


FABRIC_EXT_EXPORT void
VRayRenderer_getLastParserError (
    KL::Traits< KL::ParserError >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::ParserError error = renderer->getLastParserError();

    _result.fileName = error.fileName.c_str();
    _result.errorText = error.errorText.c_str();
    _result.fileLine = convert< KL::UInt32 >(error.fileLine);
    V4F_CATCH()
} // VRayRenderer_getLastParserError


FABRIC_EXT_EXPORT KL::UInt64
VRayRenderer_getPluginID (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::UInt64 >(renderer->getPluginID (pluginName.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_getPluginID


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginName (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::UInt64 >::INParam pluginID)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = renderer->getPluginName (convert< long long >(pluginID)).c_str();
    V4F_CATCH()
} // VRayRenderer_getPluginName


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setRenderMode (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam mode)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->setRenderMode (static_cast< VRay::RendererOptions::RenderMode >(mode)));

    V4F_CATCH (false)
} // VRayRenderer_setRenderMode


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_getRenderMode (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< int >(renderer->getRenderMode());

    V4F_CATCH (-1)
} // VRayRenderer_getRenderMode


FABRIC_EXT_EXPORT void
VRayRenderer_showFrameBuffer (
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::VRayRenderer >::INParam this_,
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam visible)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->showFrameBuffer (convert< bool >(visible));
    V4F_CATCH()
} // VRayRenderer_showFrameBuffer


FABRIC_EXT_EXPORT void
VRayRenderer_showFrameBuffer_variant1 (
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::VRayRenderer >::INParam this_,
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam visible,
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::Boolean >::INParam setFocus)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->showFrameBuffer (convert< bool >(visible), convert< bool >(setFocus));
    V4F_CATCH()
} // VRayRenderer_showFrameBuffer_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isFrameBufferShown (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isFrameBufferShown());

    V4F_CATCH (false)
} // VRayRenderer_isFrameBufferShown


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setOptions (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::RendererOptions >::INParam options)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::RendererOptions *opts = static_cast< VRay::RendererOptions* >(options->pointer);

    return convert< KL::Boolean >(renderer->setOptions (*opts));

    V4F_CATCH (false)
} // VRayRenderer_setOptions


FABRIC_EXT_EXPORT void
VRayRenderer_getOptions (
    KL::Traits< KL::RendererOptions >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::RendererOptions *options = new VRay::RendererOptions (renderer->getOptions());

    _result = KL::RendererOptions::Create();
    _result->pointer = options;
    V4F_CATCH()
} // VRayRenderer_getOptions


FABRIC_EXT_EXPORT void
VRayRenderer_enableVFBInteractivity (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->enableVFBInteractivity();
    V4F_CATCH()
} // VRayRenderer_enableVFBInteractivity


FABRIC_EXT_EXPORT void
VRayRenderer_enableVFBInteractivity_variant1 (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Boolean >::INParam enable)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->enableVFBInteractivity (convert< bool >(enable));
    V4F_CATCH()
} // VRayRenderer_enableVFBInteractivity_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isVFBInteractivityEnabled (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isVFBInteractivityEnabled());

    V4F_CATCH (false)
} // VRayRenderer_isVFBInteractivityEnabled


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_getCurrentFrame (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->getCurrentFrame());

    V4F_CATCH (-1)
} // VRayRenderer_getCurrentFrame


FABRIC_EXT_EXPORT void
VRayRenderer_setCurrentFrame (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam frame)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->setCurrentFrame (convert< int >(frame));
    V4F_CATCH()
} // VRayRenderer_setCurrentFrame


FABRIC_EXT_EXPORT KL::Float64
VRayRenderer_getCurrentTime (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Float64 >(renderer->getCurrentTime());

    V4F_CATCH (-1)
} // VRayRenderer_getCurrentTime


FABRIC_EXT_EXPORT void
VRayRenderer_setCurrentTime (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->setCurrentTime (convert< double >(time));
    V4F_CATCH()
} // VRayRenderer_setCurrentTime


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_clearAllPropertyValuesUpToTime (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Float64 >::INParam time)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->clearAllPropertyValuesUpToTime (convert< double >(time)));

    V4F_CATCH (false)
} // VRayRenderer_clearAllPropertyValuesUpToTime


FABRIC_EXT_EXPORT void
VRayRenderer_useAnimatedValues (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Boolean >::INParam use)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->useAnimatedValues (convert< bool >(use));
    V4F_CATCH()
} // VRayRenderer_useAnimatedValues


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_getUseAnimatedValuesState (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->getUseAnimatedValuesState());

    V4F_CATCH (false)
} // VRayRenderer_getUseAnimatedValuesState


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_getSequenceFrame (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->getSequenceFrame());

    V4F_CATCH (-1)
} // VRayRenderer_getSequenceFrame


FABRIC_EXT_EXPORT void
VRayRenderer_getBoundingBox (
    KL::Traits< KL::VRayBox >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::Box bbox = renderer->getBoundingBox();

    _result.pmin.x = bbox.pmin.x;
    _result.pmin.y = bbox.pmin.y;
    _result.pmin.z = bbox.pmin.z;

    _result.pmax.x = bbox.pmax.x;
    _result.pmax.y = bbox.pmax.y;
    _result.pmax.z = bbox.pmax.z;
    V4F_CATCH()
} // VRayRenderer_getBoundingBox


FABRIC_EXT_EXPORT void
VRayRenderer_getBoundingBox_variant1 (
    KL::Traits< KL::VRayBox >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Boolean >::IOParam success)
{
    V4F_TRY
    bool result = false;
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::Box bbox = renderer->getBoundingBox (result);

    success = convert< KL::Boolean >(result);

    _result.pmin.x = bbox.pmin.x;
    _result.pmin.y = bbox.pmin.y;
    _result.pmin.z = bbox.pmin.z;

    _result.pmax.x = bbox.pmax.x;
    _result.pmax.y = bbox.pmax.y;
    _result.pmax.z = bbox.pmax.z;
    V4F_CATCH()
} // VRayRenderer_getBoundingBox_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setCamera (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::VRayPlugin >::INParam plugin)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::Plugin *p = static_cast< VRay::Plugin* >(plugin->pointer);

    return convert< KL::Boolean >(renderer->setCamera (*p));

    V4F_CATCH (false)
} // VRayRenderer_setCamera


FABRIC_EXT_EXPORT void
VRayRenderer_getCamera (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::Plugin *plugin = new VRay::Plugin (renderer->getCamera());

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_getCamera


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_pause (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->pause());

    V4F_CATCH (false)
} // VRayRenderer_pause


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_resume (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->resume());

    V4F_CATCH (false)
} // VRayRenderer_resume


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isPaused (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isPaused());

    V4F_CATCH (false)
} // VRayRenderer_isPaused


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_getWidth (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->getWidth());

    V4F_CATCH (-1)
} // VRayRenderer_getWidth


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_getHeight (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->getHeight());

    V4F_CATCH (-1)
} // VRayRenderer_getHeight


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_getImageSize (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::IOParam width,
    KL::Traits< KL::SInt32 >::IOParam height)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    int w, h;

    renderer->getImageSize (w, h);

    width = convert< KL::SInt32 >(w);
    height = convert< KL::SInt32 >(h);
    V4F_CATCH (false)
} // VRayRenderer_getImageSize


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setWidth (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam width)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->setWidth (convert< int >(width)));

    V4F_CATCH (false)
} // VRayRenderer_setWidth


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setHeight (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->setHeight (convert< int >(height)));

    V4F_CATCH (false)
} // VRayRenderer_setHeight


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setImageSize (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam width,
    KL::Traits< KL::SInt32 >::INParam height)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->setImageSize (convert< int >(width), convert< int >(height)));

    V4F_CATCH (false)
} // VRayRenderer_setImageSize


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_setRenderRegion (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam srcX,
    KL::Traits< KL::SInt32 >::INParam srcY,
    KL::Traits< KL::SInt32 >::INParam srcWidth,
    KL::Traits< KL::SInt32 >::INParam srcHeight,
    KL::Traits< KL::SInt32 >::INParam destX,
    KL::Traits< KL::SInt32 >::INParam destY,
    KL::Traits< KL::SInt32 >::INParam destWidth,
    KL::Traits< KL::SInt32 >::INParam destHeight)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->setRenderRegion (
                                      convert< int >(srcX),
                                      convert< int >(srcY),
                                      convert< int >(srcWidth),
                                      convert< int >(srcHeight),
                                      convert< int >(destX),
                                      convert< int >(destY),
                                      convert< int >(destWidth),
                                      convert< int >(destHeight)));

    V4F_CATCH (false)
} // VRayRenderer_setRenderRegion


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_load (
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::VRayRenderer >::INParam this_,
    Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::INParam fileName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->load (fileName.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_load


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_loadAsText (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam text)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->loadAsText (text.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_loadAsText


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_append (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam fileName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->append (fileName.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_append


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_appendAsText (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam text)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->appendAsText (text.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_appendAsText


FABRIC_EXT_EXPORT void
VRayRenderer_start (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->start();
    V4F_CATCH()
} // VRayRenderer_start


FABRIC_EXT_EXPORT void
VRayRenderer_startSync (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->startSync();
    V4F_CATCH()
} // VRayRenderer_startSync


FABRIC_EXT_EXPORT void
VRayRenderer_run (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->run();
    V4F_CATCH()
} // VRayRenderer_run


FABRIC_EXT_EXPORT void
VRayRenderer_renderSequence (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->renderSequence();
    V4F_CATCH()
} // VRayRenderer_renderSequence


FABRIC_EXT_EXPORT void

// TODO not passing array yet
VRayRenderer_renderSequence_variant1 (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::VariableArray< KL::SubSequenceDesc >::INParam descriptions,
    KL::Traits< KL::SInt64 >::INParam count)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->renderSequence();
    V4F_CATCH()
} // VRayRenderer_renderSequence_variant1


FABRIC_EXT_EXPORT void
VRayRenderer_continueSequence (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->continueSequence();
    V4F_CATCH()
} // VRayRenderer_continueSequence


FABRIC_EXT_EXPORT void
VRayRenderer_stop (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->stop();
    V4F_CATCH()
} // VRayRenderer_stop


// TODO support ExportSettings pointer
FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_exportScene (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam fileName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->exportScene (fileName.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_exportScene


FABRIC_EXT_EXPORT void
VRayRenderer_bucketRenderNearest (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam x,
    KL::Traits< KL::SInt32 >::INParam y)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->bucketRenderNearest (convert< int >(x), convert< int >(y));
    V4F_CATCH()
} // VRayRenderer_bucketRenderNearest


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_addHosts (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam hosts)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->addHosts (hosts.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_addHosts


FABRIC_EXT_EXPORT KL::SInt32
VRayRenderer_removeHosts (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam hosts)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::SInt32 >(renderer->removeHosts (hosts.c_str()));

    V4F_CATCH (-1)
} // VRayRenderer_removeHosts


FABRIC_EXT_EXPORT void
VRayRenderer_getAllHosts (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = renderer->getAllHosts().c_str();
    V4F_CATCH()
} // VRayRenderer_getAllHosts


FABRIC_EXT_EXPORT void
VRayRenderer_getActiveHosts (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = renderer->getActiveHosts().c_str();
    V4F_CATCH()
} // VRayRenderer_getActiveHosts


FABRIC_EXT_EXPORT void
VRayRenderer_getInactiveHosts (
    KL::Traits< KL::String >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = renderer->getInactiveHosts().c_str();
    V4F_CATCH()
} // VRayRenderer_getInactiveHosts


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_commit (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->commit());

    V4F_CATCH (false)
} // VRayRenderer_commit


FABRIC_EXT_EXPORT void
VRayRenderer_getImage (
    KL::Traits< KL::VRayImage >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = KL::VRayImage::Create();
    _result->pointer = renderer->getImage();
    V4F_CATCH()
} // VRayRenderer_getImage


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_saveImage (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam fileName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->saveImage (fileName.c_str()));

    V4F_CATCH (false)
} // VRayRenderer_saveImage


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_saveImage_variant1 (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam fileName,
    KL::Traits< KL::ImageWriterOptions >::INParam options)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    VRay::ImageWriterOptions opts;

    opts.flags.multipleFiles = convert< bool >(options.flags.multipleFiles);
    opts.flags.skipAlpha = convert< bool >(options.flags.skipAlpha);
    opts.flags.frameNumber = convert< bool >(options.flags.frameNumber);
    opts.flags.noAlpha = convert< bool >(options.flags.noAlpha);
    opts.flags.singleChannel = convert< bool >(options.flags.singleChannel);
    opts.flags.skipRGB = convert< bool >(options.flags.skipRGB);
    opts.flags.writeIntegerIDs = convert< bool >(options.flags.writeIntegerIDs);
    opts.flags.velocityZeroBased = convert< bool >(options.flags.velocityZeroBased);
    opts.flags.multiChannel = convert< bool >(options.flags.multiChannel);
    opts.flags.applyColorCorrections = convert< bool >(options.flags.applyColorCorrections);

    opts.compressionType = static_cast< VRay::ImageWriterOptions::CompressionType >(options.compressionType);
    opts.bitsPerChannel = convert< int >(options.bitsPerChannel);

    return convert< KL::Boolean >(renderer->saveImage (fileName.c_str(), opts));

    V4F_CATCH (false)
} // VRayRenderer_saveImage_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isImageReady (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isImageReady());

    V4F_CATCH (false)
} // VRayRenderer_isImageReady


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isRendering (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isRendering());

    V4F_CATCH (false)
} // VRayRenderer_isRendering


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isAborted (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isAborted());

    V4F_CATCH (false)
} // VRayRenderer_isAborted


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_isSequenceDone (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->isSequenceDone());

    V4F_CATCH (false)
} // VRayRenderer_isSequenceDone


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_waitForImageReady (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->waitForImageReady());

    V4F_CATCH (false)
} // VRayRenderer_waitForImageReady


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_waitForImageReady_variant1 (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam timeout)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->waitForImageReady (convert< int >(timeout)));

    V4F_CATCH (false)
} // VRayRenderer_waitForImageReady_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_waitForSequenceDone (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->waitForSequenceDone());

    V4F_CATCH (false)
} // VRayRenderer_waitForSequenceDone


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_waitForSequenceDone_variant1 (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam timeout)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    return convert< KL::Boolean >(renderer->waitForSequenceDone (convert< int >(timeout)));

    V4F_CATCH (false)
} // VRayRenderer_waitForSequenceDone_variant1


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginNames (
    KL::Traits< KL::VariableArray< KL::String > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    std::vector< std::string > names = renderer->getPluginNames();

    for (std::vector< std::string >::const_iterator it = names.begin(); it != names.end(); ++it) {
        _result.push_back (it->c_str());
    }

    V4F_CATCH()
} // VRayRenderer_getPluginNames


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginIds (
    KL::Traits< KL::VariableArray< KL::UInt64 > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    std::vector< VRay::InstanceId > ids = renderer->getPluginIds();

    for (std::vector< VRay::InstanceId >::const_iterator it = ids.begin(); it != ids.end(); ++it) {
        _result.push_back (*it);
    }

    V4F_CATCH()
} // VRayRenderer_getPluginIds


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginIds_variant1 (
    KL::Traits< KL::VariableArray< KL::UInt64 > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginClassName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    std::vector< VRay::InstanceId > ids = renderer->getPluginIds (pluginClassName.c_str());

    for (std::vector< VRay::InstanceId >::const_iterator it = ids.begin(); it != ids.end(); ++it) {
        _result.push_back (*it);
    }

    V4F_CATCH()
} // VRayRenderer_getPluginIds_variant1


FABRIC_EXT_EXPORT void
VRayRenderer_getAvailablePlugins (
    KL::Traits< KL::VariableArray< KL::String > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);
    std::vector< std::string > names = renderer->getAvailablePlugins();

    for (std::vector< std::string >::const_iterator it = names.begin(); it != names.end(); ++it) {
        _result.push_back (it->c_str());
    }

    V4F_CATCH()
} // VRayRenderer_getAvailablePlugins


FABRIC_EXT_EXPORT void
VRayRenderer_getInstanceOf (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginType)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->getInstanceOf (pluginType.c_str()));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_getInstanceOf


FABRIC_EXT_EXPORT void
VRayRenderer_getInstanceOrCreate (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginType)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->getInstanceOrCreate (pluginType.c_str()));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_getInstanceOrCreate


FABRIC_EXT_EXPORT void
VRayRenderer_getPlugin_byname (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->getPlugin (pluginName.c_str()));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_getPlugin_byname


FABRIC_EXT_EXPORT void
VRayRenderer_getPlugin_byid (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::UInt64 >::INParam pluginID)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->getPlugin (convert< VRay::InstanceId >(pluginID)));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_getPlugin_byid


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginMeta (
    KL::Traits< KL::VRayPluginMeta >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginClassName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::PluginMeta *meta = new VRay::PluginMeta (renderer->getPluginMeta (pluginClassName.c_str()));

    _result = KL::VRayPluginMeta::Create();
    _result->pointer = meta;
    V4F_CATCH()
} // VRayRenderer_getPluginMeta


FABRIC_EXT_EXPORT void
VRayRenderer_newPlugin (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginName,
    KL::Traits< KL::String >::INParam pluginType)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->newPlugin (pluginName.c_str(), pluginType.c_str()));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_newPlugin


FABRIC_EXT_EXPORT void
VRayRenderer_newPlugin_noname (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginType)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->newPlugin (pluginType.c_str()));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_newPlugin_noname


FABRIC_EXT_EXPORT void
VRayRenderer_pickPlugin (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam x,
    KL::Traits< KL::SInt32 >::INParam y)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->pickPlugin (convert< int >(x), convert< int >(y)));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_pickPlugin


FABRIC_EXT_EXPORT void
VRayRenderer_pickPlugin_timeout (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam x,
    KL::Traits< KL::SInt32 >::INParam y,
    KL::Traits< KL::SInt32 >::INParam timeout)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *plugin = new VRay::Plugin (renderer->pickPlugin (convert< int >(x), convert< int >(y), convert< int >(timeout)));

    _result = KL::VRayPlugin::Create();
    _result->pointer = plugin;
    V4F_CATCH()
} // VRayRenderer_pickPlugin_timeout


FABRIC_EXT_EXPORT void
VRayRenderer_pickPlugins (
    KL::Traits< KL::VariableArray< KL::PluginDistancePair > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Float64 >::INParam x,
    KL::Traits< KL::Float64 >::INParam y)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    std::vector< VRay::PluginDistancePair > pairs = renderer->pickPlugins (convert< double >(x), convert< double >(y));

    for (std::vector< VRay::PluginDistancePair >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        KL::PluginDistancePair p;
        p.plugin = KL::VRayPlugin::Create();
        p.plugin->pointer = new VRay::Plugin (it->plugin);
        p.distance = convert< KL::Float64 >(it->distance);

        _result.push_back (p);
    }

    V4F_CATCH()
} // VRayRenderer_pickPlugins


FABRIC_EXT_EXPORT void
VRayRenderer_pickPlugins_variant1 (
    KL::Traits< KL::VariableArray< KL::PluginDistancePair > >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Float64 >::INParam x,
    KL::Traits< KL::Float64 >::INParam y,
    KL::Traits< KL::SInt32 >::INParam maxcount,
    KL::Traits< KL::SInt32 >::INParam timeout)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    std::vector< VRay::PluginDistancePair > pairs = renderer->pickPlugins (convert< double >(x), convert< double >(y), convert< int >(maxcount), convert< int >(timeout));

    for (std::vector< VRay::PluginDistancePair >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        KL::PluginDistancePair p;
        p.plugin = KL::VRayPlugin::Create();
        p.plugin->pointer = new VRay::Plugin (it->plugin);
        p.distance = convert< KL::Float64 >(it->distance);

        _result.push_back (p);
    }

    V4F_CATCH()
} // VRayRenderer_pickPlugins_variant1


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_removePlugin (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::VRayPlugin >::INParam plugin)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    VRay::Plugin *p = static_cast< VRay::Plugin* >(plugin->pointer);

    bool result = renderer->removePlugin (*p);

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayRenderer_removePlugin


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginPtr_byname (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = KL::VRayPlugin::Create();
    _result->pointer = renderer->getPluginPtr (pluginName.c_str());
    V4F_CATCH()
} // VRayRenderer_getPluginPtr_byname


FABRIC_EXT_EXPORT void
VRayRenderer_getPluginPtr_byid (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::UInt64 >::INParam pluginID)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = KL::VRayPlugin::Create();
    _result->pointer = renderer->getPluginPtr (convert< VRay::InstanceId >(pluginID));
    V4F_CATCH()
} // VRayRenderer_getPluginPtr_byid


FABRIC_EXT_EXPORT void
VRayRenderer_pickPluginPtr (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam x,
    KL::Traits< KL::SInt32 >::INParam y)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = KL::VRayPlugin::Create();
    _result->pointer = renderer->pickPluginPtr (convert< int >(x), convert< int >(y));
    V4F_CATCH()
} // VRayRenderer_pickPluginPtr


FABRIC_EXT_EXPORT void
VRayRenderer_pickPluginPtr_timeout (
    KL::Traits< KL::VRayPlugin >::Result _result,
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam x,
    KL::Traits< KL::SInt32 >::INParam y,
    KL::Traits< KL::SInt32 >::INParam timeout)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    _result = KL::VRayPlugin::Create();
    _result->pointer = renderer->pickPluginPtr (convert< int >(x), convert< int >(y), convert< int >(timeout));
    V4F_CATCH()
} // VRayRenderer_pickPluginPtr_timeout


FABRIC_EXT_EXPORT void
VRayRenderer_freePluginPtr (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::VRayPlugin >::INParam ptr)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->freePluginPtr (static_cast< VRay::Plugin* >(ptr->pointer));
    V4F_CATCH()
} // VRayRenderer_freePluginPtr


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_pluginExists_byname (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::String >::INParam pluginName)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    bool result = renderer->pluginExists (pluginName.c_str());

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayRenderer_pluginExists_byname


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_pluginExists_byid (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::UInt64 >::INParam pluginID)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    bool result = renderer->pluginExists (convert< VRay::InstanceId >(pluginID));

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayRenderer_pluginExists_byid


FABRIC_EXT_EXPORT KL::Boolean
VRayRenderer_getAutoCommit (KL::Traits< KL::VRayRenderer >::INParam this_)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    bool result = renderer->getAutoCommit();

    return convert< KL::Boolean >(result);

    V4F_CATCH (false)
} // VRayRenderer_getAutoCommit


FABRIC_EXT_EXPORT void
VRayRenderer_setAutoCommit (
    KL::Traits< KL::VRayRenderer >::INParam this_,
    KL::Traits< KL::Boolean >::INParam autoCommit)
{
    V4F_TRY
    VRay::VRayRenderer *renderer = static_cast< VRay::VRayRenderer* >(this_->pointer);

    renderer->setAutoCommit (convert< bool >(autoCommit));
    V4F_CATCH()
} // VRayRenderer_setAutoCommit







