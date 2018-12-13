#pragma once
#include "Light.h"
class DirectionalLight :
	public Light
{
public:
	RGBColor color;
	float scalar;
	Direction direction;

	Direction get_direction_deterministic(const HitInfo & hit_info) const;
	Direction get_direction(const HitInfo & hit_info) const;
	RGBColor L(HitInfo & hit_info) const;

	DirectionalLight(const RGBColor & color, float scalar, const Direction & direction);

	DirectionalLight();
	~DirectionalLight();
};

