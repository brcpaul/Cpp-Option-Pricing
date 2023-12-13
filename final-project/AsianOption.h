#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
	private :
	#pragma region attributes
		std::vector<double> timeSteps;
	#pragma endregion

	public:
		// AsianOption Constructor
		//AsianOption(std::vector<double>& timeSteps, double expiry) : Option(expiry) {} pouquoi le & ?
		AsianOption(std::vector<double> timeSteps, double expiry) : Option(expiry){}

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
