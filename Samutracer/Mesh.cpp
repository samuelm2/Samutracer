#include "pch.h"
//#include "Mesh.h"
//#define TINYOBJLOADER_IMPLEMENTATION
//#include "tiny_obj_loader.h"
//
//
//
//Mesh::Mesh(std::string file_path)
//{
//	tinyobj::attrib_t attrib;
//	shapes = new std::vector<tinyobj::shape_t>();
//	std::vector<tinyobj::material_t> materials;
//
//	std::string err;
//	bool ret = tinyobj::LoadObj(&(this->attrib), &shapes, &materials, &err, file_path.c_str());
//}
//
//void Mesh::add_geometry(World* world) {
//	for (size_t s = 0; s < shapes.size(); s++) {
//		 Loop over faces(polygon)
//		size_t index_offset = 0;
//		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
//			int fv = shapes[s].mesh.num_face_vertices[f];
//			if (fv != 3) {
//				perror("non-triangle face found. exiting.");
//				exit(-1);
//			}
//			 Loop over vertices in the face.
//			for (size_t v = 0; v < fv; v++) {
//				 access to vertex
//				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
//				tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
//				tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
//				tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
//
//				if (minx > vx) {
//					minx = vx;
//				}
//				if (miny > vy) {
//					miny = vy;
//				}
//				if (minz > vz) {
//					minz = vz;
//				}
//				if (maxx < vx) {
//					maxx = vx;
//				}
//				if (maxy < vy) {
//					maxy = vy;
//				}
//				if (maxz < vz) {
//					maxz = vz;
//				}
//			}
//			index_offset += fv;
//
//
//			TODO: ADD TRIANGLES TO TRIANGLE ARRAY
//			shapes[s].mesh.material_ids[f];
//		}
//	}
//}
//
//Mesh::~Mesh()
//{
//}
