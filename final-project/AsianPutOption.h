#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption {
private:
	AsianOption* aOption;
public:
	double strike;
	
	AsianPutOption(AsianOption* aOption, std::vector<double>& timeSteps, double strike, double expiry) : aOption(aOption), AsianOption(timeSteps, expiry) {}

	double payoff();
	

};