#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption 
{
	private:
	#pragma region attributes
		AsianOption* asOption;
	#pragma endregion


	public:
		double _strike;
	
		// AsianPutOption Constructor
		AsianPutOption(AsianOption* aOption, std::vector<double>& timeSteps, double _strike, double _expiry) : asOption(asOption), AsianOption(timeSteps, _expiry) {}


		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		double payoff();
	

};