#include "pch.h"
#include "MeshInstance.h"
#include "MeshTriangle.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Instance.h"



void MeshInstance::set_transform()
{
	transform = glm::inverse(inv_transform);
}

BoundingBox MeshInstance::getBBox() const
{
	return BoundingBox();
}

bool MeshInstance::hit(const Ray & r, double & min_t, HitInfo & hit_info) const
{
	glm::vec4 transformed_ray_direction = inv_transform * glm::vec4(r.direction, 0.);
	glm::vec4 transformed_ray_origin = inv_transform * glm::vec4(r.origin, 1.);

	Ray transformed_ray = Ray(Point3D(transformed_ray_origin), Direction(transformed_ray_direction));
	MeshTriangle curr_mesh(mesh);

	bool did_hit = false;
	double minimum_t = MAX_DOUBLE;
	HitInfo h = HitInfo();
	RGBColor curr = RGBColor();
	Direction curr_normal = Direction();
	Point3D hit_point = Point3D();

	HitInfo cpy = HitInfo(hit_info);

	double curr_t = MAX_DOUBLE;
	
	for (int i = 0; i < mesh->indices.size(); i += 3) {
		curr_mesh.index1 = mesh->indices[i];
		curr_mesh.index2 = mesh->indices[i + 1];
		curr_mesh.index3 = mesh->indices[i + 2];
		if (curr_mesh.hit(transformed_ray, curr_t, cpy) && curr_t < minimum_t) {
			did_hit = true;
			minimum_t = curr_t;
			curr = cpy.color;
			curr_normal = cpy.normal;
			hit_point = cpy.hit_point;
		}
	}
	if (did_hit) {
		hit_info.color = curr;
		hit_info.did_hit = true;
		hit_info.normal = curr_normal;
		hit_info.hit_point = Point3D(glm::inverse(inv_transform) * glm::fvec4(hit_point, 1.));
		min_t = minimum_t;
	}

	
	return did_hit;
}

bool MeshInstance::shadow_hit(const Ray & r, double & min_t) const
{
	return true;
}

void MeshInstance::translate(float x, float y, float z)
{
	glm::mat4 translate = glm::translate(glm::mat4(1.0), glm::vec3(-x, -y, -z));
	inv_transform = inv_transform * translate;
}

void MeshInstance::scale(float x, float y, float z)
{
	glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(1./x, 1./y, 1./z));
	inv_transform = inv_transform * scale;
}

void MeshInstance::add_geometry(World * world)
{
	for (int i = 0; i < mesh->indices.size(); i += 3) {
		MeshTriangle* curr_mesh = new MeshTriangle(mesh);
		curr_mesh->index1 = mesh->indices[i];
		curr_mesh->index2 = mesh->indices[i + 1];
		curr_mesh->index3 = mesh->indices[i + 2];
		world->add_object(new Instance(curr_mesh, &inv_transform, &transform));
	}
}



MeshInstance::MeshInstance(Mesh* mesh) : mesh(mesh), inv_transform(1.0)
{
}


MeshInstance::~MeshInstance()
{
}
