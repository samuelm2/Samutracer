#include "pch.h"
#include "AmbientLight.h"


AmbientLight::AmbientLight(const RGBColor & color) : color(color)
{
}

AmbientLight::AmbientLight() : color(.1F, .1F, .1F)
{
}


AmbientLight::~AmbientLight()
{
}
