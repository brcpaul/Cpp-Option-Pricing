#pragma once
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption
{

public:
	// AmericanPutOption constructor
	AmericanPutOption(double expiry, double strike) : AmericanOption(expiry, strike) {

	};

	double payoff(double price);
};