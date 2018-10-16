#pragma once
#include "GeometricObject.h"
#include "Mesh.h"
class MeshTriangle :
	public GeometricObject
{
public:
	Mesh* mesh;
	int index1, index2, index3;
	Direction normal;

	BoundingBox getBBox() const;
	bool hit(const Ray &r, double & min_t, HitInfo & hit_info) const;
	bool shadow_hit(const Ray &r, double & min_t) const;
	MeshTriangle(Mesh* mesh);
	~MeshTriangle();
};

