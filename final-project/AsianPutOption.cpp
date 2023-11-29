#include "AsianPutOption.h"


/// <summary>
/// AsianPutOption function in order to calculate the payoff for an asian put option
/// </summary>
/// <returns> the payoff of the asian put option </returns>
double AsianPutOption::payoff() {
	double price_smoothed = payoffPath(asOption->getTimeSteps());
	if (price_smoothed <= _strike) {
		return _strike - price_smoothed;
	}
	else return 0.0;
}