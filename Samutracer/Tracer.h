#pragma once
class World;
#include "World.h"
class Tracer
{
public:

	virtual RGBColor trace_ray(const Ray & ray) const;

	Tracer();
	Tracer(World* w);
	~Tracer();

protected:
	World* world;
};

