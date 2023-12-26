#pragma once
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption 
{

	public:
		// AmericanCallOption constructor
		AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike) {

		};

		double payoff(double price);
};