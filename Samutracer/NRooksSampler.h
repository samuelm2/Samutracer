#pragma once
#include "Sampler.h"
#include "glm/gtc/random.hpp"
class NRooksSampler :
	public Sampler
{
public:
	void generate_samples(int num_samples, int num_sets);
	NRooksSampler();
	~NRooksSampler();
private:
	void shuffle_x();
	void shuffle_y();
};

