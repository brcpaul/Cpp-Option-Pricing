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

	double q = (_riskFreeRate-_down)/(_up-_down);

	for (int i = 0; i <= _depth; i++) {
		_tree.setNode(_depth, i, _option->payoff(_tree.getNode(_depth, i)));
	}

	for (int n = _depth-1; n >= 0;n--) {
		for (int i = 0; i <= n; i++) {
			double h = (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i))/(1+_riskFreeRate);
			_tree.setNode(n, i, h);
		}
	}
}