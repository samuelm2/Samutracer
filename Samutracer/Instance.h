#pragma once
#include "GeometricObject.h"
#include "glm/gtc/matrix_transform.hpp"

class Instance :
	public GeometricObject
{
public:
	GeometricObject* reference;
	glm::mat4* inverse_transform;
	glm::mat4* transform;
	bool owns_transform;

	BoundingBox getBBox() const; 
	bool hit(const Ray & r, double & min_t, HitInfo & hit_info) const;
	bool shadow_hit(const Ray & r, double & min_t) const;
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void set_transform();

	Instance(GeometricObject* ref);
	Instance(GeometricObject * ref, glm::mat4 * inverse_transform, glm::mat4 * transform);
	~Instance();
};

