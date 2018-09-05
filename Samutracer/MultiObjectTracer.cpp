#include "pch.h"
#include "MultiObjectTracer.h"

RGBColor MultiObjectTracer::trace_ray(const Ray & ray) const
{
	double minimum_t = MAX_DOUBLE;
	HitInfo h = HitInfo();
	RGBColor color = world->background_color;

	double curr_t = MAX_DOUBLE;
	for (auto it = world->objects.begin(); it != world->objects.end(); ++it) {
		if ((*it)->hit(ray, curr_t, h) && curr_t < minimum_t) {
			color = h.color;
			minimum_t = curr_t;
		}
	}
	return color;
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
