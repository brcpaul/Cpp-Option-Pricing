#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption 
{
	private:
	#pragma region attributes
		//AsianOption* asOption;
	#pragma endregion


	public:	
		//asOption(asOption),
		// AsianPutOption Constructor
		AsianPutOption(std::vector<double> timeSteps, double strike) : AsianOption(timeSteps, strike) {}


		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		double payoff(double) override;

};