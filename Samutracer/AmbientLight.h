#pragma once
#include "Constants.h"
class AmbientLight 
{
public:
	RGBColor color;
	AmbientLight(const RGBColor & color);
	AmbientLight();
	~AmbientLight();
};

