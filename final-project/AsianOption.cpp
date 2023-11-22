#include "AsianOption.h"

std::vector<double> AsianOption::getTimeSteps() const {
	return timeSteps;
}

bool AsianOption::isAsianOption() {
	return true;
}