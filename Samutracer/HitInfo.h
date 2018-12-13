#pragma once
#include <glm/glm.hpp>
#include "Constants.h"

class HitInfo
{
public:
	bool did_hit;
	Point3D hit_point;
	Direction normal;
	Direction normal2;
	RGBColor color;

	bool is_reflective;
	bool is_transparent;
	bool is_light;
	bool is_procedural;
	bool is_noise;

	HitInfo();
	HitInfo(const RGBColor & color);
	~HitInfo();
};

