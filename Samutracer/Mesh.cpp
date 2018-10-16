#include "pch.h"
#include "Mesh.h"
#include <iostream>
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"


//taken from tinyobjloader github https://github.com/syoyo/tinyobjloader
Mesh::Mesh(std::string file_path)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string err;
	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, file_path.c_str());

	if (!err.empty()) { // `err` may contain warning message.
		std::cerr << err << std::endl;
	}

	if (!ret) {
		exit(1);
	}

	for (int i = 0; i < shapes[0].mesh.indices.size(); i++) {
		this->indices.push_back(shapes[0].mesh.indices[i].vertex_index);
	}
	for (int i = 0; i < attrib.vertices.size(); i+=3) {
		this->vertices.push_back(Point3D(attrib.vertices[i], attrib.vertices[i + 1], attrib.vertices[i + 2]));
	}
	std::cout << "Object parsing complete" << " "<< this->indices.size()/3 << std::endl;
}


Mesh::~Mesh()
{
}
