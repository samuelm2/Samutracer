#pragma once
#include "Tracer.h"
class PhongTracer :
	public Tracer
{
public:
	RGBColor trace_ray(const Ray & ray, int bounces, double refractive_ratio);
	bool is_in_shadow(const HitInfo & h, const Light & l) const;
	float get_shadow_scalar(const HitInfo & h, const Light & l);
	PhongTracer(World * w);
	PhongTracer();
	~PhongTracer();
};

