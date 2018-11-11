#include "pch.h"
#include "Phong.h"

RGBColor Phong::shade(HitInfo & h, const Ray& ray, World* world) const
{

	RGBColor current = RGBColor(0., 0., 0.);
	for (auto it = world->lights.begin(); it != world->lights.end(); it++) {
		if (!is_in_shadow(h, (**it), world)) {
			current += (float)(glm::dot(h.normal, -glm::normalize((*it)->get_direction(h)))) * (*it)->L(h) * color;
			Direction r = glm::normalize(glm::reflect(glm::normalize(-(*it)->get_direction(h)), h.normal));
			Direction v = glm::normalize(ray.direction);
			float rv = glm::pow(glm::clamp(glm::dot(r, v), 0., 1.), 50);
			current += rv * one;
		}
	}
	current += world->ambient->color * color;
	return glm::clamp(current, 0.F, 1.F);
}

bool Phong::is_in_shadow(HitInfo & h, const Light & l, World* world) const {
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

Phong::Phong()
{
}

Phong::Phong(const RGBColor & c) : color(c)
{
}


Phong::~Phong()
{
}
