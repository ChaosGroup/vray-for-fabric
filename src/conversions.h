#ifndef V4F_CONVERSIONS_H_
#define V4F_CONVERSIONS_H_

#include <FabricEDK.h>
#include "vraysdk.hpp"

#include "global.h"
#include "VRayColor.h"
#include "VRayAColor.h"
#include "VRayVector.h"
#include "VRayMatrix.h"
#include "VRayTransform.h"


using namespace Fabric::EDK;


template< typename To, typename From >
To
convert (const From &f)
{
    return To (f);
} // convert


template< >
inline
VRay::Vector
convert (const KL::VRayVector &vec3)
{
    return VRay::Vector (convert< float >(vec3.x), convert< float >(vec3.y), convert< float >(vec3.z));
} // convert


template< >
inline
KL::VRayVector
convert (const VRay::Vector &vec3)
{
    KL::VRayVector v;

    v.x = convert< KL::Float32 >(vec3.x);
    v.y = convert< KL::Float32 >(vec3.y);
    v.z = convert< KL::Float32 >(vec3.z);

    return v;
} // convert


template< >
inline
VRay::Matrix
convert (const KL::VRayMatrix &mat33)
{
    return VRay::Matrix (convert< VRay::Vector >(mat33.col1), convert< VRay::Vector >(mat33.col2), convert< VRay::Vector >(mat33.col3));
} // convert


template< >
inline
KL::VRayMatrix
convert (const VRay::Matrix &mat33)
{
    KL::VRayMatrix m;

    m.col1 = convert< KL::VRayVector >(mat33.v0);
    m.col2 = convert< KL::VRayVector >(mat33.v1);
    m.col3 = convert< KL::VRayVector >(mat33.v2);

    return m;
} // convert


template< >
inline
VRay::Transform
convert (const KL::VRayTransform &trans)
{
    VRay::Transform x;

    x.matrix = convert< VRay::Matrix >(trans.matrix);
    x.offset = convert< VRay::Vector >(trans.offset);

    return x;
} // convert


template< >
inline
KL::VRayTransform
convert (const VRay::Transform &trans)
{
    KL::VRayTransform x;

    x.matrix = convert< KL::VRayMatrix >(trans.matrix);
    x.offset = convert< KL::VRayVector >(trans.offset);

    return x;
} // convert


template< >
inline
VRay::Color
convert (const KL::VRayColor &color)
{
    return VRay::Color (convert< float >(color.r), convert< float >(color.g), convert< float >(color.b));
} // convert


template< >
inline
KL::VRayColor
convert (const VRay::Color &color)
{
    KL::VRayColor c;

    c.r = convert< KL::Float32 >(color.r);
    c.g = convert< KL::Float32 >(color.g);
    c.b = convert< KL::Float32 >(color.b);

    return c;
} // convert


template< >
inline
VRay::AColor
convert (const KL::VRayAColor &acolor)
{
    return VRay::AColor (convert< VRay::Color >(acolor.color), convert< float >(acolor.alpha));
} // convert


template< >
inline
KL::VRayAColor
convert (const VRay::AColor &acolor)
{
    KL::VRayAColor c;

    c.color = convert< KL::VRayColor >(acolor.color);
    c.alpha = convert< KL::Float32 >(acolor.alpha);

    return c;
} // convert
#endif // ifndef CONVERSIONS_H_







