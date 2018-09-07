#pragma once
#include <vector>
#include "GeometricObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "ViewPlane.h"
#include "RawImage.h"
#include "Camera.h"
class Tracer;
#include "Tracer.h"
class World
{
public:
	std::vector<GeometricObject*> objects;
	RGBColor background_color;
	Camera c;
	Tracer* tracer;

	void build();
	void render_scene(RawImage & r) const;
	void render_scene_perspective(RawImage & r) const;
	void add_object(GeometricObject* obj);

	void set_resolution(int hres, int vres, double pixel_size);

	World(const RGBColor & color);
	World();
	~World();
	ViewPlane view_plane;
};

