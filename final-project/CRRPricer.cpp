#include <iostream>;
#include "CRRPricer.h"

CRRPricer::CRRPricer(Option* option, int depth, double assetPrice, double up, double down, double riskFreeRate) :
	_option{ option }, _depth{ depth }, _assetPrice{ assetPrice }, _up{ up }, _down{ down }, _interest_rate{ riskFreeRate } {
	//Checking for abitrage

	if (!(_down < _interest_rate && _interest_rate < _up)) {
		throw std::runtime_error("The model doesn't verify D < R < U.");
	}

	_tree.setDepth(depth);

	//Checking if it is an AsianOption
	if (_option->isAsianOption()) {
		throw std::runtime_error("Asian options are not supported by CRRPricer.");
	}
	if (_option->isAmericanOption()) {
		_exercise.setDepth(depth);
	}

	riskNeutralProbability = (_interest_rate - _down) / (_up - _down);
}

CRRPricer::CRRPricer(Option* option, int depth, double assetPrice, double r, double volatility)
{
	/*_up = exp(volatility * sqrt(option->getExpiry() / depth)) - 1.0;
	_down = exp(-volatility * sqrt(option->getExpiry() / depth)) - 1.0;
	_interest_rate = exp(r * option->getExpiry() / depth) - 1.0;*/
	double h = option->getExpiry() / depth;
	_up = exp((r + volatility* volatility/ 2) * h + volatility * sqrt(h)) - 1;
	_down = exp((r + volatility * volatility / 2) * h - volatility * sqrt(h)) - 1;
	_interest_rate = exp(r * h) - 1;
	_assetPrice = assetPrice;
	_option = option;
	_depth = depth;

	if (!(_down < _interest_rate && _interest_rate < _up)) {
		throw std::runtime_error("The model doesn't verify D < R < U.");
	}

	_tree.setDepth(depth);

	//Checking if it is an AsianOption
	if (_option->isAsianOption()) {
		throw std::runtime_error("Asian options are not supported by CRRPricer.");
	}
	if (_option->isAmericanOption()) {
		_exercise.setDepth(depth);
	}

	riskNeutralProbability = (_interest_rate - _down) / (_up - _down);
}

void CRRPricer::compute() {

	double q = riskNeutralProbability;

	for (int n = _depth - 1; n >= 0;n--) {
		for (int i = 0; i <= n; i++) {
			double h = (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i)) / (1 + _interest_rate);
			if (_option->isAmericanOption()) {
				double intrinsicValue = _option->payoff(_assetPrice * pow(1 + _up, i) * pow(1 + _down, n - i));
				bool exercise = intrinsicValue > h;
				_exercise.setNode(n, i, exercise);
				_tree.setNode(n, i, exercise ? intrinsicValue : h);
			}
			else {
				_tree.setNode(n, i, h);
			}
		}
	}
}

// CRRPricer function to calculate the combination of n choose k
double combination(int n, int k) {
	if (k == 0) return 1.0;
	double prod = 1.0;
	for (int i = 1;i <= k;i++) {
		prod *= 1.0*(n - (k-i)) / i;
	}
	return prod;
}

/// <summary>
/// CRRPricer method in order to calculate the option pricing (using a closed-form formula in case of flag)
/// </summary>
/// <param name="closedForm">Flag indicating whether to use the closed-form formula (default is false)</param>
/// <returns>The calculated option price</returns>
double CRRPricer::operator()(bool closedForm) {
	for (int i = 0; i <= _depth; i++) {
		_tree.setNode(_depth, i, _option->payoff(_assetPrice * pow(1 + _up, i) * pow(1 + _down, _depth - i)));
	}
	if (closedForm) { 
		//closed-form formula for pricing option :
		double resultTot=0.0, resultInter;
		for (int i = 0;i <= _depth;i++) {
			resultInter = combination(_depth, i)*1.0;
			//std::cout << resultInter << std::endl;
			resultInter *= std::pow(riskNeutralProbability, i) * std::pow(1 - riskNeutralProbability, _depth - i);
			double price = _tree.getNode(_depth, i);
			resultInter *= price;
			resultTot += resultInter;
		}
		return (1.0 / std::pow(1.0 + _interest_rate, _depth)) * resultTot;
	}
	else {
		compute();
		return _tree.getNode(0, 0);
	}
}