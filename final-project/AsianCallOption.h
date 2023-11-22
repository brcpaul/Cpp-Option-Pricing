#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption {
	private:
		AsianOption* asOption;
	public:
		
		double strike;
		AsianCallOption(AsianOption* aOption, std::vector<double>& timeSteps, double strike, double expiry) : asOption (asOption), AsianOption(timeSteps, expiry) {}

		double payoff();
};