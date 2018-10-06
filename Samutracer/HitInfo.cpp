#include "pch.h"
#include "HitInfo.h"

HitInfo::HitInfo()
{
	this->color = RGBColor(0, 0, 0);
	this->did_hit = false;
}

HitInfo::HitInfo(const RGBColor & color) {
	this->color = RGBColor(color);
	this->hit_point = glm::vec3(0.0, 0.0, 0.0);
	this->did_hit = false;
}

HitInfo::~HitInfo()
{
}
