#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

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
		int verifIndex(int, int) const;
		int maxDigit() const;

		//liens antoine (à ne pas effacer svp): 
		//https://www.geeksforgeeks.org/vector-in-cpp-stl/
		//https://cplusplus.com/reference/vector/vector/ (best)
		//https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
		//https://stackoverflow.com/questions/40054600/searching-binary-tree-of-objects-for-a-single-class-member

		//https://www.youtube.com/watch?v=B6eIfpcAXKk
};

/// <summary> 
/// The setter method of BinaryTree (setDepth(int) a setter for _depth) that resizes _tree and allocate / deallocate properly the vectors in tree
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree (int, double, float, etc.)</typeparam>
/// <param name="d">depth</param>
template <typename T>
void BinaryTree<T>::setDepth(int d) {
	_depth = d; //affectation de la profondeur
	_tree.resize(d + 1); //changement de la taille du vecteur (va de 0 ‡ d inclus)
	for (int i = 0;i <= d;i++) {
		_tree[i].resize(i + 1); //changement de la taille de chaque sous-vecteur du vecteur
	}
}
/// <summary>
/// Verification method of BinaryTree (used in order to reduce iteration in methods and valid indices)
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <param name="iVect">Vector indices</param>
/// <param name="iSubVect">sousVector indices</param>
/// <returns>0 or 1 (for true or false valid indices)</returns>
template <typename T>
int BinaryTree<T>::verifIndex(int iVect, int iSubVect) const {
	if (iVect >= 0 && iVect <= _depth && iSubVect >= 0 && iSubVect <= iVect)
		//Conditions de vérifications taille vecteur (entre 0 et depth) et  taille sous vecteur (entre 0 et indice vecteur)
	{
		return 1;
	}
	else
		//Si condition non valide => raise une erreur (si en dehors taille vecteur et sous-vecteur)
	{
		//std::cerr << "Invalid indices !" << std::endl;
		std::cerr << "Invalid indices at : --- (" << iVect << ";" << iSubVect << ") --- !" << std::endl;
		return 0;
	}
}
/// <summary>
/// Setter Method of BinaryTree to set node of the Binary Tree at specific indices (set one of the values of the vector of vector)
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <param name="iVect">Vector indices</param>
/// <param name="iSubVect">sousVector indices</param>
/// <param name="val">Value of type T</param>
template <typename T>
void BinaryTree<T>::setNode(int iVect, int iSubVect, T val) {
	if (verifIndex(iVect, iSubVect))
	{
		_tree[iVect][iSubVect] = val; //afectation 
	}
}
/// <summary>
/// Getter Method of BinaryTree to get node of the Binary Tree at specific indices
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <param name="iVect">Vector indices</param>
/// <param name="iSubVect">sousVector indices</param>
/// <returns>Value of the Node or default value for invalid indices</returns>
template <typename T>
T BinaryTree<T>::getNode(int iVect, int iSubVect) const {
	if (verifIndex(iVect, iSubVect)) {
		return _tree[iVect][iSubVect];
	}
	return T();
}
/// <summary>
/// Method of BinaryTree which converts a value of type T to a string with a specified number of decimals places
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <param name="value">the value to be converted to a string</param>
/// <param name="nDecimals">Number of decimal places</param>
/// <returns>A string with  a specified number of decimals places</returns>
template <typename T>
std::string toStringWithDecimals(T value, int nDecimals = 6)
{
	std::ostringstream outStream;
	outStream.precision(nDecimals);
	outStream << std::fixed << value;
	return std::move(outStream).str();
}
/// <summary>
/// Method of BinaryTree which calculates the maximum total number of digits (both before and after the decimal point) in the vector of vector
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <returns>The maximum total number of digits in the binary tree</returns>
template <typename T>
int BinaryTree<T>::maxDigit() const {
	int maxDigit = 0;
	//std::cout << std::to_string(_tree[0][0]) << std::endl; 
	for (const auto& vect : _tree) {
		for (const auto& sousVect : vect) {
			std::string str = std::to_string(sousVect);
			//std::string::npos = const static de std::string en lien avec .find("motif") pour voir si aucune correspondance "motif" n'a été trouvée
			int strDigit = str.find('.') != std::string::npos ? str.find('.') : str.size();
			//gestion des 0 inutiles :
			int strDigitDeci = 0;
			if (str.find('.') != std::string::npos) {
				for (int i = str.size() - 1; i > str.find('.'); i--) { //(size_t i) à la place de (int i) peut-etre
					if (str[i] != '0') {
						strDigitDeci = i - str.find('.');
						break;
					}
				}
			}
			//int strDigitDeci = str.find('.') != std::string::npos ? str.size() - str.find('.') - 1 : 0;
			//std::cout << str.size() << " " << str.find('.') << "(strDigit ; strDigitDeci) : (" << strDigit << ";" << strDigitDeci << ")." << std::endl;
			maxDigit = std::max(maxDigit, strDigit + strDigitDeci);
		}
	}
	if (maxDigit % 2 == 0) maxDigit++;
	return maxDigit;
}
/// <summary>
/// Method of BinaryTree which displays the binary tree in two formated manners
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
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
	int stringWidth = maxDigit();
	std::cout << stringWidth << std::endl;
	//std::cout << "maxDigit = " << stringWidth << std::endl;
	for (int i = 0;i <= _depth;i++) {


		if (i > 0) {
			std::cout << std::string(stringWidth * (_depth - i), ' ');
			for (int k = 0;k <= i;k++) {
				if (k == 0) {
					std::cout << std::string((stringWidth + 1) / 2, ' ') << "/" << std::string((stringWidth - 3) / 2, ' ') << std::string(stringWidth, ' ');
				}
				else if (k == i) {
					std::cout << std::string((stringWidth - 3) / 2, ' ') << "\\" << std::string((stringWidth + 1) / 2, ' ') << std::string(stringWidth, ' ');
				}
				else {
					std::cout << std::string((stringWidth - 3) / 2, ' ') << "\\ /" << std::string((stringWidth - 3) / 2, ' ') << std::string(stringWidth, ' ');
				}
			}
			std::cout << std::endl;
		}


		std::cout << std::string(stringWidth * (_depth - i), ' ');

		for (int k = 0;k <= i;k++) {
			std::string s = toStringWithDecimals(_tree[i][k], 1); //A modif Impérativement ATTENTION si on réduit par choix à 1 décimal on aura pas tout
			int spaceBefore = (stringWidth - s.size()) / 2;
			int spaceAfter = stringWidth - s.size() - spaceBefore;
			std::cout << std::string(spaceBefore, ' ') << s << std::string(spaceAfter, ' ') << std::string(stringWidth, ' ');
		}
		std::cout << std::endl;
	}
}


#pragma region TESTS BINARY TREE : 
void test_bt_1(int depth) {
	BinaryTree<double> tree(depth);
	for (int i = 0; i <= depth;i++) {
		for (int j = 0; j <= i; j++) {
			tree.setNode(i, j, i * j * 0.23);
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


#pragma region TESTS BINARY TREE : 
void test_bt_1(int);
void test_bt_2();
#pragma endregion 
