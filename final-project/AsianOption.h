#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
	private :
		std::vector<double> timeSteps;

	public:
		AsianOption(std::vector<double>& timeSteps, double expiry) : Option(expiry){}

		std::vector<double> getTimeSteps() const {
			return timeSteps;
		}

		bool isAsianOption() override{
			return true;
		}

		double payoffPath(std::vector<double> timeSteps) override{
			int sum = 0;
			for (int i = 0; i < timeSteps.size(); i++) {
				sum += timeSteps[i];
			}
			double x = sum / timeSteps.size();
			return payoff(x);
		}
};
