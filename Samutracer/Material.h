#pragma once
class HitInfo;
#include "HitInfo.h"
#include "Ray.h"
//#include "BVHAccelerator.h"
#include <vector>
#include "Light.h"
class Material
{
public:
	virtual RGBColor shade(HitInfo & h, const Ray & ray, const std::vector<Light> & lights) const = 0;
	Material();
	~Material();
};

