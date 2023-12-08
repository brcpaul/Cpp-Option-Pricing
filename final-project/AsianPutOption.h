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
		double _strike;
	
		//asOption(asOption),
		// AsianPutOption Constructor
		AsianPutOption(std::vector<double>& timeSteps, double _strike) : AsianOption(timeSteps, _strike) {}


		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		double payoff(double) const override;
	

};