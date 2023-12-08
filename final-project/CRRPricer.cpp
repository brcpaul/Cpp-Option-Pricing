#include <iostream>;
#include "CRRPricer.h"
void CRRPricer::compute() {

	// Fill in the tree 
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


	//_tree.display();

	double q = riskNeutralProbability();

	for (int i = 0; i <= _depth; i++) {
		_tree.setNode(_depth, i, _option->payoff(_tree.getNode(_depth, i)));
	}

	for (int n = _depth - 1; n >= 0;n--) {
		for (int i = 0; i <= n; i++) {
			double h = (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i)) / (1 + _interest_rate);
			bool exercise = _option->payoff(_tree.getNode(n, i)) >= h;
			if (_option->isAmericanOption()) {
				_exercise.setNode(n, i, exercise);
				_tree.setNode(n, i, exercise ? _option->payoff(_tree.getNode(n, i)) : h);
			}
			else {
				_tree.setNode(n, i, h);
			}
		}
	}
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
	int prod = 1;
	for (int i = 1;i <= k;i++) {
		prod *= (n + 1 - i) / i;
	}
	return prod;
}

/// <summary>
/// CRRPricer method in order to calculate the option pricing (using a closed-form formula in case of flag)
/// </summary>
/// <param name="closedForm">Flag indicating whether to use the closed-form formula (default is false)</param>
/// <returns>The calculated option price</returns>
double CRRPricer::operator()(bool closedForm) {
	if (closedForm) { //closed-form formula for pricing option :
		double resultTot=0.0, resultInter;
		std::cout << "Closed" << std::endl;
		for (int i = 0;i <= _depth;i++) {
			resultInter = combination(_depth, i);
			//(factoriel(_depth) / (factoriel(i) * factoriel(_depth - i)));
			resultInter *= std::pow(riskNeutralProbability(), i) * std::pow(1 - riskNeutralProbability(), _depth - i);
			resultInter *= get(_depth, i); //H(N,i) = h(S(N,i)) at expiry date N = _depth
			resultTot += resultInter;
		}
		return (1 / std::pow(1 + _interest_rate, _depth)) * resultTot;
	}
	else {
		std::cout << "Open" << std::endl;
		compute();
		return _tree.getNode(0, 0);
	}
}