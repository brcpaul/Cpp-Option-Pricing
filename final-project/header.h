#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include "Header1.h"

template <typename T>
class BinaryTree {
	private :
		int _depth; //represents N
		std::vector<std::vector<T>> _tree; //hold data of type T
	public :
		BinaryTree(int depth = 0) : _depth{ depth } { setDepth(depth); }
		T getNode(int, int) const;
		void setDepth(int);
		void setNode(int, int, T);
		void display() const; 
		int verif_i(int, int) const;
		int max_digit() const;

		//liens antoine (à ne pas effacer svp): 
		//https://www.geeksforgeeks.org/vector-in-cpp-stl/
		//https://cplusplus.com/reference/vector/vector/ (best)
		//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
		//https://stackoverflow.com/questions/40054600/searching-binary-tree-of-objects-for-a-single-class-member

		//https://www.youtube.com/watch?v=B6eIfpcAXKk
};

#pragma region TESTS BINARY TREE : 
void test_bt_1(int);
void test_bt_2();
#pragma endregion 

class CRRPricer {
	private :
		//Option* option = nullprt;
		int _depth;
		double _asset_price;
		double _up;
		double _down;
		double _interest_rate;
		BinaryTree<double> tree;
	public:
		CRRPricer(/*Option* option,*/ int depth, double asset_price, double up, double down, double interest_rate) :
			/*option{option},*/ _depth{ depth }, _asset_price{ asset_price }, _up{ up }, _down{ down }, _interest_rate{ interest_rate }{
			BinaryTree<double> tree(depth);
		}
		void compute();
		double get(int, int); //verif si c bien double
		double operator()(bool closed_form = false);
};
