#pragma once
#include "Light.h"
#include "Sphere.h"
class AreaLight :
	public Light, public Sphere
{
public:
	Direction get_direction(const HitInfo & hit_info) const;
	Direction get_direction_deterministic(const HitInfo & hit_info) const;

	RGBColor L(HitInfo & hit_info) const;
	AreaLight(Point3D center, float r, RGBColor c);
	~AreaLight();
};

