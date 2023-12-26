#pragma once
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption
{

public:
	AmericanPutOption(double expiry, double strike) : AmericanOption(expiry, strike) {};
	double payoff(double price);
};