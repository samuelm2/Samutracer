#include "pch.h"
#include "PointLight.h"


Direction PointLight::get_direction(const HitInfo & hit_info) const
{
	return hit_info.hit_point - position;
}

RGBColor PointLight::L(HitInfo & hit_info) const
{
	return scalar * color;
}

PointLight::PointLight() : position(), color()
{
}

PointLight::PointLight(const Point3D & position, const RGBColor & color,  float scalar) : position(position), color(color), scalar(scalar)
{
}

PointLight::~PointLight()
{
}
