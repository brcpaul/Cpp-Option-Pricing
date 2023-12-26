#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption 
{	
	public:	
		AsianPutOption(std::vector<double> timeSteps, double strike) : AsianOption(timeSteps, strike) {}
		double payoff(double) override;
};