#include "pch.h"
#include "ViewPlane.h"
#include "MultiJitteredSampler.h"

ViewPlane::ViewPlane()
{
	this->hres = 8;
	this->vres = 6;
	this->pixel_size = 1.;
}

void ViewPlane::set_samples(int s) {
	num_samples = s;
	this->sampler = new MultiJitteredSampler();
	this->sampler->generate_samples(s, 87);
}

ViewPlane::ViewPlane(int hres, int vres, double pixel_size) : hres(hres), vres(vres), pixel_size(pixel_size)
{
}

ViewPlane::~ViewPlane()
{
}
