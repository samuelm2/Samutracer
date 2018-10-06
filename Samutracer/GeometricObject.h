#pragma once
#include "Ray.h"
#include "HitInfo.h"
class GeometricObject
{
public:
	RGBColor color;

	virtual bool hit(const Ray &r, double & min_t, HitInfo & hit_info) const = 0;
	virtual bool shadow_hit(const Ray &r, double & min_t) const = 0;
	GeometricObject();
	GeometricObject(const RGBColor & color);
	~GeometricObject();
};

