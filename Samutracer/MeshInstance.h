#pragma once
#include "GeometricObject.h"
#include "Mesh.h"
#include "World.h"
class MeshInstance :
	public GeometricObject
{
public:
	Mesh* mesh;
	glm::mat4 inv_transform;
	glm::mat4 transform;

	void set_transform();

	BoundingBox getBBox() const;
	bool hit(const Ray &r, double & min_t, HitInfo & hit_info) const;
	bool shadow_hit(const Ray &r, double & min_t) const;

	void translate(float x, float y, float z);
	void scale(float x, float y, float z); 

	void add_geometry(World* world);

	MeshInstance(Mesh* mesh);
	~MeshInstance();
};

