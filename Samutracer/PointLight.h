#pragma once
#include "Light.h"
class PointLight :
	public Light
{
public:
	Point3D position;
	RGBColor color;
	float scalar;

	Direction get_direction(const HitInfo & hit_info) const;
	Direction get_direction_deterministic(const HitInfo & hit_info) const;
	RGBColor L(HitInfo & hit_info) const;

	PointLight();
	PointLight(const Point3D & position, const RGBColor & color, float scalar);
	~PointLight();
};

