#pragma once
#include "GeometricObject.h"
class Plane :
	public GeometricObject
{
public:
	bool hit(const Ray &r, double & min_t, HitInfo & hit_info) const;
	Point3D point;
	Direction normal;

	Plane();
	Plane(const Point3D & a, const Direction & normal);
	~Plane();
};

