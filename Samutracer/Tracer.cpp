#include "pch.h"
#include "Tracer.h"


RGBColor Tracer::trace_ray(const Ray & ray) const
{
	return RGBColor();
}

Tracer::Tracer()
{
	world = nullptr;
}

Tracer::Tracer(World * w) 
{
	this->world = w;
}


Tracer::~Tracer()
{
}
