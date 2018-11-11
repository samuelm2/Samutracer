#pragma once
#include "Ray.h"
#include "HitInfo.h"
class BoundingBox;
#include "BoundingBox.h"
class GeometricObject
{
public:
	RGBColor color;
	bool is_reflective;
	bool is_transparent;
	virtual BoundingBox getBBox() const = 0;
	virtual bool hit(const Ray &r, double & min_t, HitInfo & hit_info) const = 0;
	virtual bool shadow_hit(const Ray &r, double & min_t) const = 0;
	GeometricObject();
	GeometricObject(const RGBColor & color);
	~GeometricObject();

};

