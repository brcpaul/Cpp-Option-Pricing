#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption {
	private:

	public:
		double strike;
		AsianCallOption(std::vector<double>& timeSteps, double strike) : AsianOption(timeSteps) {}

		double payoff() const{
			double price = payoffPath(AsianOption::getTimeSteps());
			if (price >= strike) {
				return price - strike;
			}
			else return 0.0;
		}

};