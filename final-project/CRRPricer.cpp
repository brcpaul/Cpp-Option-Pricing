#include <iostream>;
#include "CRRPricer.h"
void CRRPricer::compute() {

	// Fill in the tree 
	_tree.setNode(0, 0, _assetPrice);
	for (int n = 1; n <= _depth;n++) {
		for (int i = 0; i <= n; i++) {
			double newValue;
			if (i > 0) {
				newValue = _tree.getNode(n - 1, i - 1) * (1+_up);
			}
			else {
				newValue = _tree.getNode(n - 1, i) * (1+_down);
			}
			_tree.setNode(n, i, newValue);
		}
	}


	//_tree.display();

	double q = riskNeutralProbability();

	for (int i = 0; i <= _depth; i++) {
		_tree.setNode(_depth, i, _option->payoff(_tree.getNode(_depth, i)));
	}

	for (int n = _depth-1; n >= 0;n--) {
		for (int i = 0; i <= n; i++) {
			double h = (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i))/(1+_interest_rate);
			_tree.setNode(n, i, h);
		}
	}
}
/// <summary>
/// CRRPRicer factorial function in order to calculate the factorial of an integer
/// </summary>
/// <param name="n">an integer</param>
/// <returns>The calculated factorial of the interger n</returns>
int CRRPricer::factoriel(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * factoriel(n - 1);
}
/// <summary>
/// CRRPricer function to calculate the risk-neutral probability 
/// </summary>
/// <returns>The calculated risk-neutral probability</returns>
double CRRPricer::riskNeutralProbability() {
	return (_interest_rate - _down) / (_up - _down);
}
/// <summary>
/// CRRPricer method in order to calculate the option pricing (using a closed-form formula in case of flag)
/// </summary>
/// <param name="closedForm">Flag indicating whether to use the closed-form formula (default is false)</param>
/// <returns>The calculated option price</returns>
double CRRPricer::operator()(bool closedForm) {
	if (closedForm) { //closed-form formula for pricing option :
		double resultTot, resultInter;
		for (int i = 0;i <= _depth;i++) {
			resultInter = (factoriel(_depth) / (factoriel(i) * factoriel(_depth - i)));
			resultInter *= std::pow(riskNeutralProbability(), i) * std::pow(1 - riskNeutralProbability(), _depth - i);
			resultInter *= get(_depth, i); //H(N,i) = h(S(N,i)) at expiry date N = _depth
			resultTot += resultInter;
		}
		return (1 / std::pow(1 + _interest_rate, _depth)) * resultTot;
	}
	else {
		compute();
		return _tree.getNode(0, 0);
	}
}