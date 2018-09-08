#include "pch.h"
#include "PhongTracer.h"


RGBColor PhongTracer::trace_ray(const Ray & ray) const
{
	HitInfo h = this->world->hit_objects(ray);
	RGBColor current = RGBColor(0.,0.,0.);
	if (h.did_hit) {
		for (auto it = world->lights.begin(); it != world->lights.end(); it++) {
			current += (float)(glm::dot(h.normal, -(*it)->get_direction(h))) * (*it)->L(h) * h.color;
		}
		return glm::clamp(current, 0.F, 1.F);
	}
	return world->background_color;
}

PhongTracer::PhongTracer(World * w)
{
	this->world = w;
}

PhongTracer::PhongTracer()
{
}


PhongTracer::~PhongTracer()
{
}
