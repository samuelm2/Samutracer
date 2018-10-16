#include "pch.h"
#include "Instance.h"


BoundingBox Instance::getBBox() const
{
	glm::vec4 new_points_min = *transform * glm::vec4(reference->getBBox().min, 1.);
	glm::vec4 new_points_max = *transform * glm::vec4(reference->getBBox().max, 1.);

	return BoundingBox(Point3D(new_points_min), Point3D(new_points_max));
}

bool Instance::hit(const Ray & r, double & min_t, HitInfo & hit_info) const
{
	glm::vec4 transformed_ray_direction = *inverse_transform * glm::vec4(r.direction, 0.);
	glm::vec4 transformed_ray_origin = *inverse_transform * glm::vec4(r.origin, 1.);

	Ray transformed_ray = Ray(Point3D(transformed_ray_origin), Direction(transformed_ray_direction));
	bool ret = reference->hit(transformed_ray, min_t, hit_info);
	if (hit_info.did_hit) {
		hit_info.hit_point = Point3D(glm::inverse(*inverse_transform) * glm::fvec4(hit_info.hit_point, 1.));
	}
	return ret;
}

bool Instance::shadow_hit(const Ray & r, double & min_t) const
{
	glm::vec4 transformed_ray_direction = *inverse_transform * glm::vec4(r.direction, 0.);
	glm::vec4 transformed_ray_origin = *inverse_transform * glm::vec4(r.origin, 1.);
	Ray transformed_ray = Ray(Point3D(transformed_ray_origin), Direction(transformed_ray_direction));

	bool ret = reference->shadow_hit(transformed_ray, min_t);
	return ret;
}

void Instance::translate(float x, float y, float z)
{
	glm::mat4 translate = glm::translate(glm::mat4(1.0), glm::vec3(-x, -y, -z));
	*inverse_transform = *inverse_transform * translate;
}

void Instance::scale(float x, float y, float z)
{
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1. / x, 1. / y, 1. / z));
	*inverse_transform = *inverse_transform * scale;
}

void Instance::set_transform()
{
		*transform = glm::inverse(*inverse_transform);
}

Instance::Instance(GeometricObject* ref): reference(ref)
{
	inverse_transform = new glm::mat4(1.0);
	transform = new glm::mat4(1.0);
	owns_transform = true;
}

Instance::Instance(GeometricObject * ref, glm::mat4 * inverse_transform, glm::mat4 * transform) : reference(ref), inverse_transform(inverse_transform), transform(transform)
{
	owns_transform = false;
}

Instance::~Instance()
{
	if (owns_transform) {
		delete inverse_transform;
	}
}
