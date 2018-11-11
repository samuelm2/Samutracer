#pragma once
#include <glm/glm.hpp>
#include "Constants.h"

class HitInfo
{
public:
	bool did_hit;
	Point3D hit_point;
	Direction normal;
	RGBColor color;

	bool is_reflective;
	bool is_transparent;

	HitInfo();
	HitInfo(const RGBColor & color);
	~HitInfo();
};

