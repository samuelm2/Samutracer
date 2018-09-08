#include "pch.h"
#include "DirectionalLight.h"


Direction DirectionalLight::get_direction(HitInfo & hit_info) const
{
	return this->direction;
}

RGBColor DirectionalLight::L(HitInfo & hit_info) const
{
	return this->scalar * this->color;
}

DirectionalLight::DirectionalLight(const RGBColor & color, float scalar, const Direction & direction) : color(color), scalar(scalar), direction(direction)
{
}

DirectionalLight::DirectionalLight()
{
}


DirectionalLight::~DirectionalLight()
{
}
