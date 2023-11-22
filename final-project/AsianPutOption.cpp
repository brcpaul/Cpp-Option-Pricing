#include "AsianPutOption.h"

double AsianPutOption::payoff() {
	double price_smoothed = payoffPath(aOption->getTimeSteps());
	if (price_smoothed <= strike) {
		return strike - price_smoothed;
	}
	else return 0.0;
}