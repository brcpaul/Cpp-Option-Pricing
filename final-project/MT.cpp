#include "MT.h"

double MT::rand_unif()
{
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	return dist(getInstance().rng);
}

double MT::rand_norm()
{
	std::normal_distribution<double> dist(0.0, 1.0);
	return dist(getInstance().rng);
}


