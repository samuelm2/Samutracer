#include "pch.h"
#include "MultiObjectTracer.h"

RGBColor MultiObjectTracer::trace_ray(const Ray & ray) const
{
	HitInfo h = this->world->hit_objects(ray);
	if (h.did_hit) {
		return h.color;
	}
	return world->background_color;
}

MultiObjectTracer::MultiObjectTracer(World* w) {
	this->world = w;
}

MultiObjectTracer::MultiObjectTracer()
{
}


MultiObjectTracer::~MultiObjectTracer()
{
}
