#include "pch.h"
#include "MeshTriangle.h"
#include <iostream>

BoundingBox MeshTriangle::getBBox() const
{
	Triangle temp = Triangle(mesh->vertices[index1], mesh->vertices[index2], mesh->vertices[index3]);
	return temp.getBBox();
}

bool MeshTriangle::hit(const Ray & r, double & min_t, HitInfo & hit_info) const
{
	Triangle temp = Triangle(mesh->vertices[index1], mesh->vertices[index2], mesh->vertices[index3]);
	temp.color = RGBColor(0., 0., 1.);
	bool hit = temp.hit(r, min_t, hit_info);
	return hit;

}

bool MeshTriangle::shadow_hit(const Ray & r, double & min_t) const
{
	Triangle temp = Triangle(mesh->vertices[index1], mesh->vertices[index2], mesh->vertices[index3]);
	return temp.shadow_hit(r, min_t);
}

MeshTriangle::MeshTriangle(Mesh* mesh) : mesh(mesh)
{
}


MeshTriangle::~MeshTriangle()
{
}
