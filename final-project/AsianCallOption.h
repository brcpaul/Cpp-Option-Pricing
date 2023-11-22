#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption {
	private:
		AsianOption* aOption;
	public:
		
		double strike;
		AsianCallOption(AsianOption* aOption, std::vector<double>& timeSteps, double strike, double expiry) : aOption (aOption), AsianOption(timeSteps, expiry) {}

		double payoff();
};