#include "AsianOption.h"
#include "Option.h"


AsianOption::AsianOption(std::vector<double> timeSteps):timeSteps(timeSteps), Option(timeSteps[timeSteps.back()])
{
	timeSteps = { 0.0 };
} 




/// <summary>
/// 
/// </summary>
/// <returns> vector<double> </returns>
std::vector<double> AsianOption::getTimeSteps() const {
	return timeSteps;
}


/// <summary>
/// Boolean function to initialize the type of the chosen Option to an asian option
/// </summary>
/// <returns> a boolean </returns>
bool AsianOption::isAsianOption() {
	return true;
}



double AsianOption::payoffPath(std::vector<double> h) const{
	double sum = 0;
	for (int i = 0; i < h.size(); i++)
	{
		sum += h[i];
	}
	return payoff(sum / h.size());
}



