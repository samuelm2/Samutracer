#pragma once
#include "Tracer.h"
#include "Constants.h"
#include "World.h"
class MultiObjectTracer :
	public Tracer
{
public:
	RGBColor trace_ray(const Ray & ray) const;
	MultiObjectTracer(World * w);
	MultiObjectTracer();
	~MultiObjectTracer();
};

