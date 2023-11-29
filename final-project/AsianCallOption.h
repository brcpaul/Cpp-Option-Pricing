#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption 
{

	private:
	#pragma region attributes
		AsianOption* asOption;
	#pragma endregion
	public:
		
		double _strike;

		//AsianCallOption Constructor
		AsianCallOption(AsianOption* aOption, std::vector<double>& timeSteps, double _strike, double _expiry) : asOption (asOption), AsianOption(timeSteps, _expiry) {}

		/// <summary>
		/// 
		/// </summary>
		/// <returns> </returns>
		double payoff();
};