#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption {
private:

public:
	double strike;
	AsianPutOption(std::vector<double>& timeSteps, double strike) : AsianOption(timeSteps) {}

	double payoff() const {
		double price = payoffPath(AsianOption::getTimeSteps());
		if (price <= strike) {
			return strike - price;
		}
		else return 0.0;
	}

};