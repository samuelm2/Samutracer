#pragma once
#include "GeometricObject.h"
#include "World.h"
#include <string>


class Mesh :
	public GeometricObject
{
public:
	void add_geometry(World* world);
	Mesh(std::string file_path);
	~Mesh();
	std::vector<tinyobj::shape_t>* shapes;
	std::vector<tinyobj::material_t>* materials;
	tinyobj::attrib_t* attrib;
};

