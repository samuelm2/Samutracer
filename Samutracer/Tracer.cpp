#include "pch.h"
#include "Tracer.h"


RGBColor Tracer::trace_ray(const Ray & ray, int bounces, double refractive_ratio)
{
	return RGBColor();
}

int Tracer::get_num_traced() const
{
	return num_traced;
}

Tracer::Tracer()
{
	num_traced = 0;
	world = nullptr;
}

Tracer::Tracer(World * w) 
{
	num_traced = 0;
	this->world = w;
}


Tracer::~Tracer()
{
}
