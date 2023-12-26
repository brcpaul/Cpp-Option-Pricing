#pragma once
#include "BinaryTree.h"
#include "Option.h"
#include <math.h>

class CRRPricer {
private:
#pragma region attributes
	int _depth;
	double _assetPrice;
	double _up;
	double _down;
	double _interest_rate;
	Option* _option;
	BinaryTree<double> _tree;
	BinaryTree<bool> _exercise;
	void computeTree();
	double riskNeutralProbability;
#pragma endregion

public:
	CRRPricer(Option* option, int depth, double assetPrice, double up, double down, double riskFreeRate);

	CRRPricer(Option* option, int depth, double assetPrice, double r, double volatility);

	void compute();
	double get(int n, int i) { return _tree.getNode(n, i); }
	bool getExercise(int n, int i) { return _exercise.getNode(n, i); }
	double operator()(bool closedForm=false);
};




