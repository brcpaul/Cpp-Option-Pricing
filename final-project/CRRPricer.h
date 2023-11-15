#pragma once
#include "BinaryTree.h"
#include "Option.h"

class CRRPricer {
private:
	//Option* _option = nullptr;
	int _depth;
	double _assetPrice;
	double _up;
	double _down;
	double _riskFreeRate;
	Option* _option;
	BinaryTree<double> _tree;
public:
	CRRPricer(Option *option, int depth, double assetPrice, double up, double down, double riskFreeRate) :
		_option{option}, _depth{ depth }, _assetPrice{ assetPrice }, _up{ up }, _down{ down }, _riskFreeRate{ riskFreeRate } {
		//Checking for abitrage
		if (!(_down < _riskFreeRate && _riskFreeRate < _up)) {
			std::cerr<< "The model doesn't verify D < R < U.";
		}

		 _tree.setDepth(depth);
	}
	void compute();
	double get(int n, int i) { return _tree.getNode(n, i); }
	double operator()(bool closedForm = false) {
		if (closedForm) {

		}
		else {
			compute();
			return _tree.getNode(0, 0);
		}
	}
};