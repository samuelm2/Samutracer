#include "GeometricObject.h"
#include "pch.h"
#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
	color = RGBColor();
}

GeometricObject::GeometricObject(const RGBColor & color) {
	this->color = RGBColor(color.r, color.g, color.b);
}

GeometricObject::~GeometricObject()
{
}
