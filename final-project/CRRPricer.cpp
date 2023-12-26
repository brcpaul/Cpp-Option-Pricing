#include <iostream>;
#include "CRRPricer.h"

void CRRPricer::computeTree() {
	_tree.setNode(0, 0, _assetPrice);
	for (int n = 1; n <= _depth;n++) {
		for (int i = 0; i <= n; i++) {
			double newValue;
			if (i > 0) {
				newValue = _tree.getNode(n - 1, i - 1) * (1 + _up);
			}
			else {
				newValue = _tree.getNode(n - 1, i) * (1 + _down);
			}
			_tree.setNode(n, i, newValue);
		}
	}
}
void CRRPricer::compute() {
	
	computeTree();
	//_tree.display();

	double q = riskNeutralProbability();

	for (int i = 0; i <= _depth; i++) {
		_tree.setNode(_depth, i, _option->payoff(_tree.getNode(_depth, i)));
	}

	for (int n = _depth - 1; n >= 0;n--) {
		for (int i = 0; i <= n; i++) {
			double h = (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i)) / (1 + _interest_rate);
			if (_option->isAmericanOption()) {
				bool exercise = _option->payoff(_tree.getNode(n, i)) > h;
				_exercise.setNode(n, i, exercise);
				_tree.setNode(n, i, exercise ? _option->payoff(_tree.getNode(n, i)) : h);
			}
			else {
				_tree.setNode(n, i, h);
			}
		}
	}

	//_tree.display();
}

/// <summary>
/// CRRPricer function to calculate the risk-neutral probability 
/// </summary>
/// <returns>The calculated risk-neutral probability</returns>
double CRRPricer::riskNeutralProbability() {
	return (_interest_rate - _down) / (_up - _down);
}

/// <summary>
/// CRRPricer function to calculate the combination of n choose k
/// </summary>
/// <param name="n">Total number of elements</param>
/// <param name="k">Number of elements to choose</param>
/// <returns>Integer representing the combination of n choose k</returns>
int combination(int n, int k) {
	if (k == 0) return 1;
	double prod = 1;
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
double CRRPricer::operator()(bool closedForm=false) {
	if (closedForm) { //closed-form formula for pricing option :
		computeTree();
		double resultTot=0.0, resultInter;
		for (int i = 0;i <= _depth;i++) {
			resultInter = combination(_depth, i);
			resultInter *= std::pow(riskNeutralProbability(), i) * std::pow(1 - riskNeutralProbability(), _depth - i);
			double price = _option->payoff(_tree.getNode(_depth, i));
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