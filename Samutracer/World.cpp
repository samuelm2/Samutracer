#include "pch.h"
#include "World.h"
#include "MultiObjectTracer.h"


void World::build()
{
	//this->background_color = RGBColor(0.1, 0.1, 0.1);
	Sphere* s = new Sphere(Point3D(0., 0., -100.), 50.);
	s->color = RGBColor(1., 0., 0.);
	this->add_object(s);

	Sphere* s2 = new Sphere(Point3D(20., 0., -5.), 40.);
	s2->color = RGBColor(0., 0., 1.);
	this->add_object(s2);

	Triangle* t = new Triangle(Point3D(-70., -40., -1.), Point3D(70., -40., -1.), Point3D(0., 60., 50.));
	t->color = RGBColor(1., 1., 0.);
	this->add_object(t);

	Plane* p = new Plane(Point3D(0., -15., 0.), glm::normalize(Direction(0., 1., .2)));
	p->color = RGBColor(0., 1., 0.);
	this->add_object(p);
}

void World::render_scene(RawImage & raw_image) const
{
	double x;
	double y;
	Direction d = Direction(0., 0., -1.);
	Ray r = Ray();
	r.direction = d;
	r.origin.z = 100.;
	RGBColor curr;
	
	for (int i = 0; i < view_plane.vres; i++) {
		for (int j = 0; j < view_plane.hres; j++) {
			x = view_plane.pixel_size * (j - 0.5 * (view_plane.hres - 1.));
			y = view_plane.pixel_size * (i - 0.5 * (view_plane.vres - 1.));
			r.origin.x = x;
			r.origin.y = y;
			curr = tracer->trace_ray(r);
			raw_image.set_pixel(j, i, curr);
		}
	}
}

void World::add_object(GeometricObject * obj)
{
	objects.push_back(obj);
}

void World::set_resolution(int hres, int vres, double pixel_size)
{
	this->view_plane.hres = hres;
	this->view_plane.vres = vres;
	this->view_plane.pixel_size = pixel_size;
}

World::World(const RGBColor & color)
{
	this->tracer = new MultiObjectTracer(this);
	this->background_color = RGBColor(color);
	this->view_plane =  ViewPlane();
}

World::World() : background_color(0., 0., 0.)
{
	this->tracer = new MultiObjectTracer(this);
	this->view_plane =  ViewPlane();
}


World::~World()
{
	for (int i = 0; i < objects.size(); i++) {
		delete this->objects[i];
	}
	delete this->tracer;
}
