#include "pch.h"
#include "ViewPlane.h"


ViewPlane::ViewPlane()
{
	this->hres = 8;
	this->vres = 6;
	this->pixel_size = 1.;
}

ViewPlane::ViewPlane(int hres, int vres, double pixel_size) : hres(hres), vres(vres), pixel_size(pixel_size)
{
}

ViewPlane::~ViewPlane()
{
}
