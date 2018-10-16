#pragma once
#include "GeometricObject.h"
#include "World.h"
#include <string>


class Mesh
{
public:
	Mesh(std::string file_path);
	std::vector<int> indices;
	std::vector<Point3D> vertices;

	~Mesh();
};

