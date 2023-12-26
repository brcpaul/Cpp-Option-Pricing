#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption
{

private:
#pragma region attributes
	//AsianOption* asOption;
#pragma endregion
public:
	AsianCallOption(std::vector<double> timeSteps, double _strike) : AsianOption(timeSteps, _strike) {}
	double payoff(double) override;
};