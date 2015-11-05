#include "RenderElements_functions.h"
#include "conversions.h"
#include "exceptions.h"

#include "vraysdk.hpp"

using namespace Fabric::EDK;


FABRIC_EXT_EXPORT void
RenderElements_construct (KL::Traits< KL::RenderElements >::IOParam this_)
{
    V4F_TRY
    this_->pointer = NULL;

    V4F_CATCH()
} // RenderElements_construct


FABRIC_EXT_EXPORT void
RenderElements_destruct (KL::Traits< KL::RenderElements >::IOParam this_)
{
    V4F_TRY
    this_->pointer = NULL;

    V4F_CATCH()
} // RenderElements_destruct


FABRIC_EXT_EXPORT KL::UInt32
RenderElements_getCount (KL::Traits< KL::RenderElements >::INParam this_)
{
    V4F_TRY
    VRay::RenderElements *elems = static_cast< VRay::RenderElements* >(this_->pointer);

    return convert< KL::UInt32 >(elems->getCount());

    V4F_CATCH (-1)
} // RenderElements_getCount


FABRIC_EXT_EXPORT void
RenderElements_get (
    KL::Traits< KL::RenderElement >::Result _result,
    KL::Traits< KL::RenderElements >::INParam this_,
    KL::Traits< KL::UInt32 >::INParam index)
{
    V4F_TRY
    VRay::RenderElements *elems = static_cast< VRay::RenderElements* >(this_->pointer);
    VRay::RenderElement elem = elems->get (convert< int >(index));

    _result = KL::RenderElement::Create();
    _result->pointer = &elem;
    V4F_CATCH()
} // RenderElements_get


FABRIC_EXT_EXPORT void
RenderElements_getByType (
    KL::Traits< KL::RenderElement >::Result _result,
    KL::Traits< KL::RenderElements >::INParam this_,
    KL::Traits< KL::SInt32 >::INParam type)
{
    V4F_TRY
    VRay::RenderElements *elems = static_cast< VRay::RenderElements* >(this_->pointer);
    VRay::RenderElement elem = elems->getByType (VRay::RenderElement::Type (convert< int >(type)));

    _result = KL::RenderElement::Create();
    _result->pointer = &elem;
    V4F_CATCH()
} // RenderElements_getByType







