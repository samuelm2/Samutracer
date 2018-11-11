#include "pch.h"
#include "PhongTracer.h"

inline Direction get_refraction(HitInfo & h, Direction wo, float ior) {
	Direction n = h.normal;
	float cos_thetai = glm::dot(n, wo);
	double eta = ior;
	if (cos_thetai < 0) {
		cos_thetai = -cos_thetai;
		n = -n;
		eta = 1. / eta;
	}
	float temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
	float cos_theta2 = glm::sqrt(temp);
	Direction wt = (-1. * wo) / eta - (cos_theta2 - cos_thetai / eta) * n;
	return wt;
}

RGBColor PhongTracer::trace_ray(const Ray & ray, int bounces, double refractive_ratio)
{
	this->num_traced = num_traced + 1;
	if (bounces == 0) {
		return RGBColor(0., 0., 0.);
	}
	HitInfo h = this->world->hit_objects(ray);
	RGBColor current = RGBColor(0.,0.,0.);

	if (h.did_hit) {
		if (h.is_reflective) {
			Ray reflection = Ray();
			reflection.direction = glm::reflect(glm::normalize(ray.direction), glm::normalize(h.normal));
			reflection.origin = h.hit_point;
			return glm::clamp(h.color + trace_ray(reflection, bounces - 1, refractive_ratio), 0.F, 1.F);
		}
		if (h.is_transparent) {
			Ray reflection = Ray(ray);
			reflection.origin = h.hit_point;
			//reflection.direction = ray.direction;
			Direction temp = glm::refract(glm::normalize(ray.direction), glm::normalize(h.normal), refractive_ratio);
			if (glm::dot(temp, ray.direction) < 0) {
				h.normal *= -1;
			}
			reflection.direction = glm::refract(glm::normalize(ray.direction), glm::normalize(h.normal), refractive_ratio);
			//reflection.origin = h.hit_point;
			RGBColor additional = trace_ray(reflection, bounces - 1, refractive_ratio);
			return glm::clamp(h.color + additional, 0.F, 1.F);
		}

		for (auto it = world->lights.begin(); it != world->lights.end(); it++) {
			if (bounces != 3) {
				int i = 1;
			}
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
