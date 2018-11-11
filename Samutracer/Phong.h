#pragma once
#include "World.h"
class Phong :
	public Material
{
public:
	RGBColor color;
	RGBColor shade(HitInfo & h, const Ray & ray, World * world) const;
	bool is_in_shadow(HitInfo & h, const Light & l, World * world) const;
	Phong();
	Phong(const RGBColor & c);
	~Phong();
protected:

};

