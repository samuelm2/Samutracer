#include "pch.h"
#include "DirectionalLight.h"


Direction DirectionalLight::get_direction_deterministic(const HitInfo & hit_info) const
{
	return this->direction;
}

Direction DirectionalLight::get_direction(const HitInfo & hit_info) const
{
	return this->direction;
}

RGBColor DirectionalLight::L(HitInfo & hit_info) const
{
	return this->scalar * this->color;
}

DirectionalLight::DirectionalLight(const RGBColor & color, float scalar, const Direction & direction) : color(color), scalar(scalar)
{
	this->direction = glm::normalize(direction);
}

DirectionalLight::DirectionalLight()
{
}


DirectionalLight::~DirectionalLight()
{
}
