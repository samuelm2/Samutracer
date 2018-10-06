#pragma once
#include "Tracer.h"
class PhongTracer :
	public Tracer
{
public:
	RGBColor trace_ray(const Ray & ray) const;
	bool is_in_shadow(const HitInfo & h, const Light & l) const;
	PhongTracer(World * w);
	PhongTracer();
	~PhongTracer();
};

