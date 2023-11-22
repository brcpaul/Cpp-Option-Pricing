#include "AsianCallOption.h"

double AsianCallOption::payoff() {
	double price_smoothed = payoffPath(asOption->getTimeSteps());
	if (price_smoothed >= strike) {
		return price_smoothed - strike;
	}
	else return 0.0;
}
