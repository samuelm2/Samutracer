#include "pch.h"
#include "World.h"
#include "MultiObjectTracer.h"
#include "PhongTracer.h"
#include "PerspectivePinhole.h"
#include "DirectionalLight.h"
#include "Mesh.h"
#include "MeshInstance.h"
#include "glm/gtc/matrix_transform.hpp"


void World::build()
{

	view_plane.set_samples(4);
	this->camera = new PerspectivePinhole(Point3D(0., 0., 200.), Point3D(0., 0., -150.), Point3D(0., 1., 0.), 200) ;
	//this->background_color = RGBColor(0.1, 0.1, 0.1);
	this->tracer = new PhongTracer(this);

	//DirectionalLight* l = new DirectionalLight( RGBColor(1.0, 1.0, 1.0), 1., Direction(0., -1., -0.4));
	PointLight* l = new PointLight(Point3D(0., 1000., 1000.), RGBColor(1., 1., 1.), 1.);
	this->add_light(l);

	ambient = new AmbientLight();
	Mesh* m = new Mesh("teapot.obj");
	MeshInstance* mesh = new MeshInstance(m);
	mesh->scale(30., 30., 30.);
	mesh->translate(0, -30, 0);
	mesh->set_transform();
	
	mesh->add_geometry(this);

	//MeshInstance* m2 = new MeshInstance(m);
	//m2->translate(0, 5, 150);
	//m2->set_transform();
	//m2->add_geometry(this);
	
	
	//for (int i = 0; i < 22; i++) {
	//	for (int j = 0; j < 22; j++) {
	//		for (int k = 0; k < 22; k++) {
	//			double x = 5 * i - 50;
	//			double y = 5 * j - 75 + 2*k;
	//			double z = -5 * k;
	//			Sphere* s = new Sphere(Point3D(x, y, z), 3.);
	//			s->color = RGBColor(1., 0., 0.);
	//			this->add_object(s);
	//		}
	//	}
	//}

	//Sphere* s = new Sphere(Point3D(0., 0., -150.), 80.);
	//s->color = RGBColor(1., 0., 0.);
	//this->add_object(s);

	/*Sphere* s2 = new Sphere(Point3D(20., -70, -40.), 40.);
	s2->color = RGBColor(0., 0., 1.);
	this->add_object(s2);

	*//*Triangle* t1 = new Triangle(Point3D(20., -70, -40.), Point3D(0., 60., -150.), Point3D(-100., 0., 0.));
	t1->color = RGBColor(1., 0., 1.);
	this->add_object(t1);*/

	//Triangle* t = new Triangle(Point3D(-70., -40., -40.), Point3D(70., -40., -40.), Point3D(60., 60., -40.));
	//t->color = RGBColor(0., 0., 1.);
	//this->add_object(t);

	bvh = BVHAccelerator(objects, 1);

	plane = new Plane(Point3D(0., -120., 0.), glm::normalize(Direction(0., 1., 0.)));
	plane->color = RGBColor(0., 1., 0.);
}

//deprecated
void World::render_scene(RawImage & raw_image) const
{
	double x;
	double y;
	Direction d = Direction(0., 0., -1.);
	Point2D sample_point = Point2D();
	Ray r = Ray();
	r.direction = d;
	r.origin.z = 100.;
	RGBColor curr;
	
	for (int i = 0; i < view_plane.vres; i++) {
		for (int j = 0; j < view_plane.hres; j++) {
			for (int n = 0; n < view_plane.num_samples; n++) {
				sample_point = this->view_plane.sampler->get_sample();
				x = view_plane.pixel_size * (j - 0.5 * view_plane.hres + sample_point.x);
				y = view_plane.pixel_size * (i - 0.5 * view_plane.vres + sample_point.y);
				r.origin.x = x;
				r.origin.y = y;
				curr += tracer->trace_ray(r);
			}

			raw_image.set_pixel(j, i, curr / (float)view_plane.num_samples);
			curr.r = 0.;
			curr.g = 0.;
			curr.b = 0.;
		}
	}
}

void World::render_scene_perspective(RawImage & raw_image) const
{
	//Point3D pixel_location = Point3D();
	//Point2D sample_point = Point2D();
	//Ray r = Ray();
	//r.origin = camera->origin;
	//r.direction.z = -camera->origin.z;
	//RGBColor curr;

	//for (int i = 0; i < view_plane.vres; i++) {
	//	for (int j = 0; j < view_plane.hres; j++) {
	//		for (int n = 0; n < view_plane.num_samples; n++) {
	//			sample_point = this->view_plane.sampler->get_sample();
	//			pixel_location.x = view_plane.pixel_size * (j - 0.5 * view_plane.hres + sample_point.x);
	//			pixel_location.y = view_plane.pixel_size * (i - 0.5 * view_plane.vres + sample_point.y);
	//			r.direction.x = pixel_location.x - camera->origin.x;
	//			r.direction.y = pixel_location.y - camera->origin.y;
	//			curr += tracer->trace_ray(r);
	//		}
	//		
	//		raw_image.set_pixel(j, i,  curr / (float)view_plane.num_samples);
	//		curr.r = 0.;
	//		curr.g = 0.;
	//		curr.b = 0.;
	//	}
	//}

	camera->render_scene(this, raw_image);
}

void World::add_object(GeometricObject * obj)
{
	objects.push_back(obj);
}

void World::add_light(Light * light)
{
	lights.push_back(light);
}

void World::set_resolution(int hres, int vres, double pixel_size)
{
	this->view_plane.hres = hres;
	this->view_plane.vres = vres;
	this->view_plane.pixel_size = pixel_size;
}

HitInfo World::hit_objects(const Ray & ray) const
{
	/*double minimum_t = MAX_DOUBLE;
	HitInfo h = HitInfo();
	RGBColor curr = RGBColor();
	Direction curr_normal = Direction();
	

	double curr_t = MAX_DOUBLE;
	for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
		if ((*it)->hit(ray, curr_t, h) && curr_t < minimum_t) {
			minimum_t = curr_t;
			curr = h.color;
			curr_normal = h.normal;
		}
	}
	if (h.did_hit) {
		h.hit_point = ray.origin + minimum_t * ray.direction;
		h.color = curr;
		h.normal = curr_normal;
	}

	return h;*/
	HitInfo h = HitInfo();
	double min_t = MAX_DOUBLE;
	Direction new_dir = glm::normalize(ray.direction);
	Ray new_ray = Ray(ray);
	new_ray.direction = new_dir;
	bvh.hit(new_ray, min_t, h);

	HitInfo plane_h = HitInfo();
	double plane_min_t = MAX_DOUBLE;
	if (plane) {
		plane->hit(new_ray, plane_min_t, plane_h);
	}


	if (plane_h.did_hit) {
		return (min_t < plane_min_t) ? h : plane_h;
	}
	else return h;
}

World::World(const RGBColor & color)
{
	this->objects = std::vector<GeometricObject*>();
	this->lights = std::vector<Light*>();
	this->background_color = RGBColor(color);
	this->view_plane =  ViewPlane();
}

World::World() : background_color(0., 0., 0.)
{
	this->objects = std::vector<GeometricObject*>();
	this->lights = std::vector<Light*>();
	this->view_plane =  ViewPlane();
}


World::~World()
{
	for (int i = 0; i < objects.size(); i++) {
		delete this->objects[i];
	}
	for (int i = 0; i < lights.size(); i++) {
		delete this->lights[i];
	}
	delete this->tracer;
}
