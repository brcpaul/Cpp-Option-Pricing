#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption {
private:
	AsianOption* aOption;
public:
	double strike;
	
	AsianPutOption(AsianOption* aOption, std::vector<double>& timeSteps, double strike, double expiry) : aOption(aOption), AsianOption(timeSteps, expiry) {}

	double payoff() {
		double price_smoothed = payoffPath(aOption->getTimeSteps());
		if (price_smoothed <= strike) {
			return strike - price_smoothed;
		}
		else return 0.0;
	}

};