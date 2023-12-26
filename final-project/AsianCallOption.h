#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption
{
public:
	AsianCallOption(std::vector<double> timeSteps, double _strike) : AsianOption(timeSteps, _strike) {}
	double payoff(double) override;
};