#include "pch.h"
#include "NRooksSampler.h"


void NRooksSampler::generate_samples(int num_samples, int num_sets)
{
	for (int i = 0; i < num_sets; i++) {
		for (int j = 0; j < num_samples; j++) {
			Point2D p = Point2D();
			p.x = (j + glm::linearRand(0., 1.))/num_samples;
			p.y = (j + glm::linearRand(0., 1.))/num_samples;
			samples.push_back(p);
		}
	}
}

NRooksSampler::NRooksSampler()
{
}


NRooksSampler::~NRooksSampler()
{
}

void NRooksSampler::shuffle_x()
{
}
