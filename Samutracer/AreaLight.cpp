#include "pch.h"
#include "AreaLight.h"
#include "glm/gtc/random.hpp"

Direction AreaLight::get_direction(const HitInfo & hit_info) const
{
	glm::dvec3 rand = glm::sphericalRand(radius);
	return hit_info.hit_point - (center + rand);
}

Direction AreaLight::get_direction_deterministic(const HitInfo & hit_info) const
{
	return hit_info.hit_point - center;
}

RGBColor AreaLight::L(HitInfo & hit_info) const
{
	return color;
}

AreaLight::AreaLight(Point3D o,  float r, RGBColor c) 
{
	center = o;
	radius = r;
	color = c;
}


AreaLight::~AreaLight()
{
}
