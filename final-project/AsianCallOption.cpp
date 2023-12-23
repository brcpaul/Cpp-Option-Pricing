#include "AsianCallOption.h"

double AsianCallOption::payoffPath(std::vector<double> h) const {
	double sumPrices = 0.0;
	for (int i = 0;i < h.size();i++) {
		sumPrices += h[i];
	}
	return payoff(sumPrices / h.size());
}

/// <summary>
/// AsianCallOption function in order to calculate the payoff for an asian call option
/// </summary>
/// <returns> the payoff of the asian call option </returns>
double AsianCallOption::payoff(double price) const{
	if (price >= _strike) {
		return price - _strike;
	}
	else return 0.0;
}

