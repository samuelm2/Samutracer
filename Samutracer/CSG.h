#pragma once
#include <vector>
#include "GeometricObject.h"
#include "Sphere.h"

#define UNION 0
#define INTERSECTION 1
#define SUBTRACTION 2

class CSG :
	public GeometricObject
{
public:
	Sphere* o1;
	Sphere* o2;
	unsigned char op; // 0 is union 1 is intersection 2 is subtraction

	bool hit(const Ray &r, double & hit_t, HitInfo & hit_info) const;
	bool shadow_hit(const Ray &r, double & min_t) const;
	BoundingBox getBBox() const;

	CSG();
	~CSG();
};

