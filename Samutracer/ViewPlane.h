#pragma once
class ViewPlane
{
public:
	int hres;
	int vres;
	double pixel_size;

	ViewPlane();
	ViewPlane(int hres, int vres, double pixel_size);
	~ViewPlane();
};

