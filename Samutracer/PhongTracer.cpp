#include "pch.h"
#include "PhongTracer.h"


RGBColor PhongTracer::trace_ray(const Ray & ray) const
{
	HitInfo h = this->world->hit_objects(ray);
	RGBColor current = RGBColor(0.,0.,0.);

	if (h.did_hit) {
		//return h;
		for (auto it = world->lights.begin(); it != world->lights.end(); it++) {
			if (!is_in_shadow(h, (**it))) {
				current += (float)(glm::dot(h.normal, -glm::normalize((*it)->get_direction(h)))) * (*it)->L(h) * h.color;
				Direction r = glm::normalize(glm::reflect(glm::normalize(-(*it)->get_direction(h)), h.normal));
				Direction v = glm::normalize(ray.direction);
				float rv = glm::pow(glm::clamp(glm::dot(r, v), 0., 1.), 50);
				current += rv * one;
			}
		}
		current += world->ambient->color * h.color;
		return glm::clamp(current, 0.F, 1.F);
	}
	return world->background_color;
}

bool PhongTracer::is_in_shadow(const HitInfo & h, const Light & l) const {
	Point3D origin = h.hit_point;
	Direction direction = -(l.get_direction(h));
	double min_t = glm::length(direction);
	double smin = MAX_DOUBLE;
	Ray r = Ray(origin, glm::normalize(direction));

	HitInfo h2 = HitInfo();
	if (world->bvh.hit(r, smin, h2)) {
		if (smin < min_t) {
			return true;
		}
	}
	return false;
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
