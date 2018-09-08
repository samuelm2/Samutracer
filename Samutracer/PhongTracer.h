#pragma once
#include "Tracer.h"
class PhongTracer :
	public Tracer
{
public:
	RGBColor trace_ray(const Ray & ray) const;
	PhongTracer(World * w);
	PhongTracer();
	~PhongTracer();
};

