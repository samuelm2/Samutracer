#pragma once
#include <vector>
#include "GeometricObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "ViewPlane.h"
#include "RawImage.h"
#include "Camera.h"
#include "Light.h"
#include "DirectionalLight.h"
class Tracer;
#include "Tracer.h"
class World
{
public:
	std::vector<GeometricObject*> objects;
	std::vector<Light*> lights;
	Light* ambient;
	RGBColor background_color;
	Camera camera;
	Tracer* tracer;

	void build();
	void render_scene(RawImage & r) const;
	void render_scene_perspective(RawImage & r) const;
	void add_object(GeometricObject* obj);
	void add_light(Light* light);
	void set_resolution(int hres, int vres, double pixel_size);

	HitInfo hit_objects(const Ray &) const;

	World(const RGBColor & color);
	World();
	~World();
	ViewPlane view_plane;
};

