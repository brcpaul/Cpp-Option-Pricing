#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
	private :
		std::vector<double> timeSteps;

	public:
		AsianOption(std::vector<double>& timeSteps, double expiry) : Option(expiry){}

		std::vector<double> getTimeSteps() const;
		
		bool isAsianOption() override;
		
};
