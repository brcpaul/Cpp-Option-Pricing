#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
	private :
	#pragma region attributes
		std::vector<double> timeSteps;
		double _strike;
	#pragma endregion

	public:
		friend class AsianCallOption;
		friend class AsianPutOption;
		// AsianOption Constructor
		//AsianOption(std::vector<double>& timeSteps, double expiry) : Option(expiry) {} pouquoi le & ?
		AsianOption(std::vector<double> _timeSteps, double _strike) : timeSteps(_timeSteps), Option(_timeSteps.back()) {} // Vérifier logique _timeSteps.back() = expiry ??  

		/// <summary>
		/// 
		/// </summary>
		/// <returns> vector <double> </returns>
		std::vector<double> getTimeSteps() const;
		

		/// <summary>
		/// Boolean function to initialize the type of the option at an asiaon option
		/// </summary>
		/// <returns> a boolean </returns>
		bool isAsianOption() override;

		double payoffPath(std::vector<double>) const;
		
};
