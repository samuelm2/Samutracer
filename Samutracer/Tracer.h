#pragma once
class World;
#include "World.h"
class Tracer
{
public:

	virtual RGBColor trace_ray(const Ray & ray, int bounces, double refractive_ratio);
	int get_num_traced() const;
	Tracer();
	Tracer(World* w);
	~Tracer();

protected:
	World* world;
	int num_traced;
};

