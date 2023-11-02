#include "header.h"
#include <string>
#include <sstream>
#include <math.h>

/// <summary> 
/// The setter method (setDepth(int) a setter for _depth) that resizes _tree and allocate / deallocate properly the vectors in tree
/// </summary>
/// <typeparam name="T">Type of value in BinaryTree</typeparam>
/// <param name="d">depth</param>
template <typename T>
void BinaryTree<T>::setDepth(int d){
    _depth = d; //affectation de la profondeur
    _tree.resize(d+1); //changement de la taille du vecteur (va de 0 ‡ d inclus)
    for (int i = 0;i <= d;i++) {
        _tree[i].resize(i + 1); //changement de la taille de chaque sous-vecteur du vecteur
    }
}
/// <summary>
/// Verification method (used in order to reduce iteration in methods and valid indices)
/// </summary>
/// <typeparam name="T">Type of value in BinaryTree</typeparam>
/// <param name="i_vect">Vector indices</param>
/// <param name="i_sous_vect">Sous_vector indices</param>
/// <returns>0 or 1 (for true or false valid indices)</returns>
template <typename T>
int BinaryTree<T>::verif_i(int i_vect, int i_sous_vect) const {
	if (i_vect >= 0 && i_vect <= _depth && i_sous_vect >= 0 && i_sous_vect <= i_vect) 
	//Conditions de vérifications taille vecteur (entre 0 et depth) et  taille sous vecteur (entre 0 et indice vecteur)
	{
		return 1;
	}
	else 
	//Si condition non valide => raise une erreur (si en dehors taille vecteur et sous-vecteur)
	{
		//std::cerr << "Invalid indices !" << std::endl;
		std::cerr << "Invalid indices at : --- ("<<i_vect << ";"<<i_sous_vect<<") --- !" << std::endl;
		return 0;
	}
}
/// <summary>
/// Setter Method to set node of the Binary Tree at specific indices (set one of the values of the vector of vector)
/// </summary>
/// <typeparam name="T">Type of value in BinaryTree</typeparam>
/// <param name="i_vect">Vector indices</param>
/// <param name="i_sous_vect">Sous_vector indices</param>
/// <param name="val">Value of type T</param>
template <typename T>
void BinaryTree<T>::setNode(int i_vect, int i_sous_vect, T val) {
	if (verif_i(i_vect, i_sous_vect)) 
	{
		_tree[i_vect][i_sous_vect] = val; //afectation 
	}
}
/// <summary>
/// Getter Method  to get node of the Binary Tree at specific indices
/// </summary>
/// <typeparam name="T">Type of value in BinaryTree</typeparam>
/// <param name="i_vect">Vector indices</param>
/// <param name="i_sous_vect">Sous_vector indices</param>
/// <returns>Value of the Node or default value for invalid indices</returns>
template <typename T>
T BinaryTree<T>::getNode(int i_vect, int i_sous_vect) const {
	if (verif_i(i_vect, i_sous_vect)) {
		return _tree[i_vect][i_sous_vect];
	}
	return T();
}

template <typename T>
std::string to_string_with_decimals(T value, int n_decimals = 6)
{
	std::ostringstream out_stream;
	out_stream.precision(n_decimals);
	out_stream << std::fixed << value;
	return std::move(out_stream).str();
}

template <typename T>
void BinaryTree<T>::display() const {
	//First display : 
	for (int i = 0; i <= _depth;i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << _tree[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//Second display : 
	/* Archi faux :
	int a = 0;
	for (int i = 0;i <= _depth;i++) {
		a = (int)((_tree.size()-i) / 2) - 1;
		for (b = 0;b <= a;b++) {
			std::cout << "    ";
		}
		for (int j = 0; j <= i; j++) {
			std::cout _tree[i][j] << "    ";
		}
		if (i < _depth) {
			for () {
				std::cout << " /\\ ";
			}
		}
	}
	*/

	int string_width = 3;
	for (int i = 0;i <= _depth;i++) {


		if (i > 0) {
			std::cout << std::string(string_width * (_depth - i), ' ');
			for (int k = 0;k <= i;k++) {
				if (k == 0) {
					std::cout << std::string((string_width+1)/2, ' ') << "/" << std::string((string_width - 3) / 2, ' ') << std::string(string_width, ' ');
				}
				else if (k == i) {
					std::cout << std::string((string_width - 3) / 2, ' ') << "\\" << std::string((string_width + 1) / 2, ' ') << std::string(string_width, ' ');
				}
				else {
					std::cout << std::string((string_width - 3) / 2, ' ') << "\\ /" << std::string((string_width - 3) / 2, ' ') << std::string(string_width, ' ');
				}
			}
			std::cout << std::endl;
		}


		std::cout << std::string(string_width * (_depth - i), ' ');

		for (int k = 0;k <= i;k++) {
			std::string s = to_string_with_decimals(_tree[i][k], 1);
			std::cout << std::string((string_width - s.size()) / 2, ' ') << s << std::string((string_width - s.size()) / 2, ' ') << std::string(string_width, ' ');
		}
		std::cout << std::endl;
	}
}

#pragma region TESTS BINARY TREE : 
void test_bt_1(int depth) {
	BinaryTree<double> tree(depth);
	for (int i = 0; i <= depth;i++) {
		for (int j = 0; j <= i; j++) {
			tree.setNode(i, j, i*j*0.23);
		}
	}
	tree.display();
}
void test_bt_2() { //indices en dehors vecteur 
	BinaryTree<double> tree(4);
	for (int i = 0; i <= 5;i++) {//chgt ici !
		for (int j = 0; j <= i; j++) {
			tree.setNode(i, j, i * j * 0.23);
		}
	}
	tree.display();
}
#pragma endregion 
