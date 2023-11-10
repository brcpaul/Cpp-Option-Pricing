#pragma once
class CRRPricer {
private:
	//Option* _option = nullptr;
	int _depth;
	double _assetPrice;
	double _up;
	double _down;
	double _interestRate;
	BinaryTree<double> _tree;
public:
	CRRPricer(option, int depth, double assetPrice, double up, double down, double interestRate) :
		_option{option}, _depth{ depth }, _assetPrice{ assetPrice }, _up{ up }, _down{ down }, _interestRate{ interestRate } {
		BinaryTree<double> _tree(depth);
	}
	void compute();
	double get(int n, int i) { return _tree.getNode(n, i); }
	double operator()(bool closedForm = false) {
		if (closedForm) {

		}
		else {
			compute();
		}
	}
};