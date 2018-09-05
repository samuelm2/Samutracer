#include "pch.h"
#include "Plane.h"

Plane::Plane() : Plane(Point3D(0.0, 0.0, 0.0), Direction(0.0, 0.0, 0.0))
{

}

Plane::Plane(const Point3D & a, const Direction & normal)
{
	this->point = Point3D(a);
	this->normal = Direction(normal);
}


Plane::~Plane()
{
}

bool Plane::hit(const Ray &r, double & min_t, HitInfo & hit_info) const{
	double t = glm::dot((this->point - r.origin), this->normal) / (glm::dot(r.direction, this->normal));
	if (t > TINY_DOUBLE && t != INFINITY && t != -INFINITY) {
		min_t = t;
		hit_info.color = this->color;
		hit_info.normal = this->normal;
		hit_info.hit_point = r.origin + r.direction * t;
		return true;
	}
	return false;
}
