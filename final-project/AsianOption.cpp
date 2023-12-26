#include "AsianOption.h"
#include "Option.h"

std::vector<double> AsianOption::getTimeSteps() const {
	return _timeSteps;
}


/// <summary>
/// Boolean function to initialize the type of the chosen Option to an asian option
/// </summary>
/// <returns> a boolean </returns>
bool AsianOption::isAsianOption() {
	return true;
}



double AsianOption::payoffPath(std::vector<double> h) {
	double sum = 0;
	for (int i = 0; i < h.size(); i++)
	{
		sum += h[i];
	}
	return payoff(sum / h.size());
}



