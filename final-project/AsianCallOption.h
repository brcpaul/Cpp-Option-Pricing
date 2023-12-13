#pragma once
#include "AsianOption.h"
#include <vector>

class AsianCallOption : public AsianOption 
{

	private:
	#pragma region attributes
		//AsianOption* asOption;
	#pragma endregion
	public:
		
		double _strike;

		//asOption(asOption),
		//AsianCallOption Constructor
		//AsianCallOption(AsianOption* aOption, std::vector<double>& timeSteps, double _strike, double _expiry) : asOption(asOption), AsianOption(timeSteps, _expiry) {}
		//deux arguments pour la classe AsianCallOption, et le pointeur à droite
		AsianCallOption(std::vector<double>& timeSteps, double strike) : AsianOption(timeSteps), _strike(strike) {}

		/// <summary>
		/// 
		/// </summary>
		/// <returns> </returns>
		double payoff(double) const override;
};