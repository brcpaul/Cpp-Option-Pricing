#include "AsianPutOption.h"


/// <summary>
/// AsianPutOption function in order to calculate the payoff for an asian put option
/// </summary>
/// <returns> the payoff of the asian put option </returns>
double AsianPutOption::payoff(double price) const {
	if (price <= _strike) {
		return _strike - price;
	}
	else return 0.0;
}