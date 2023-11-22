#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption {
private:
	AsianOption* asOption;
public:
	double strike;
	
	AsianPutOption(AsianOption* aOption, std::vector<double>& timeSteps, double strike, double expiry) : asOption(asOption), AsianOption(timeSteps, expiry) {}

	double payoff();
	

};