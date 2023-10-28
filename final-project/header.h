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
		BinaryTree(int d) : _depth{ d } { setDepth(d); }
		void setDepth(int d) {
			_depth = d; //affectation de la profondeur
			_tree.resize(d + 1); //changement de la taille du vecteur (va de 0 à d inclus)
			for (int i = 0;i <= d;i++) {
				_tree[i].resize(i + 1); //changement de la taille de chaque sous-vecteur du vecteur
			}
		}
		void setNode(int, int, T);
		T getNode(int, int);
		void display(); 

		//liens antoine (à ne pas effacer svp): 
		//https://www.geeksforgeeks.org/vector-in-cpp-stl/
		//https://cplusplus.com/reference/vector/vector/ (best)
		//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
		//https://stackoverflow.com/questions/40054600/searching-binary-tree-of-objects-for-a-single-class-member
};