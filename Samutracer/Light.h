#pragma once
#include "Constants.h"
#include "HitInfo.h"

class Light
{
public:
	virtual Direction get_direction(const HitInfo & hit_info) const = 0;
	virtual Direction get_direction_deterministic(const HitInfo & hit_info) const = 0;
	virtual RGBColor L(HitInfo & hit_info) const = 0;
	Light();
	~Light();
};

