#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
	private :
	#pragma region attributes
		std::vector<double> _timeSteps;
		double _strike;
	#pragma endregion

	public:
		friend class AsianCallOption;	
		friend class AsianPutOption;
		AsianOption(std::vector<double> timeSteps, double strike) : _timeSteps(timeSteps), _strike(strike), Option(timeSteps.back()) {} // Vérifier logique timeSteps.back() = expiry ??  

		std::vector<double> getTimeSteps() const;
		
		bool isAsianOption() override;
		double payoffPath(std::vector<double>) override;
		
};
