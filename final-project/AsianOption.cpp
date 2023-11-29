#include "AsianOption.h"


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

