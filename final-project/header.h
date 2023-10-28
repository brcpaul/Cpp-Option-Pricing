#pragma once
#include <iostream>
#include <math.h>
#include <vector>

template <typename T>
class BinaryTree {
	private :
		int _depth; //represents N
		std::vector<std::vector<T>> _tree; //hold data of type T
	public :
		BinaryTree(int d) : _depth{d} {/*à finir*/ }
		void setDepth(int d);
		void setNode(int, int, T);
		T getNode(int, int);
		void display();
};