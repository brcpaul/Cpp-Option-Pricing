#include "header.h"
#include <string>
#include <sstream>
#include <math.h>

/// <summary> 
/// The setter method of BinaryTree (setDepth(int) a setter for _depth) that resizes _tree and allocate / deallocate properly the vectors in tree
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree (int, double, float, etc.)</typeparam>
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
/// Verification method of BinaryTree (used in order to reduce iteration in methods and valid indices)
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
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
/// Setter Method of BinaryTree to set node of the Binary Tree at specific indices (set one of the values of the vector of vector)
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
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
/// Getter Method of BinaryTree to get node of the Binary Tree at specific indices
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
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
/// <summary>
/// Method of BinaryTree which converts a value of type T to a string with a specified number of decimals places
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <param name="value">the value to be converted to a string</param>
/// <param name="n_decimals">Number of decimal places</param>
/// <returns>A string with  a specified number of decimals places</returns>
template <typename T>
std::string to_string_with_decimals(T value, int n_decimals = 6)
{
	std::ostringstream out_stream;
	out_stream.precision(n_decimals);
	out_stream << std::fixed << value;
	return std::move(out_stream).str();
}
/// <summary>
/// Method of BinaryTree which calculates the maximum total number of digits (both before and after the decimal point) in the vector of vector
/// </summary>
/// <typeparam name="T">Type of data stored in the binary tree</typeparam>
/// <returns>The maximum total number of digits in the binary tree</returns>
template <typename T>
int BinaryTree<T>::max_digit() const {
	int max_digit = 0;
	//std::cout << std::to_string(_tree[0][0]) << std::endl; 
	for (const auto& vect : _tree) {
		for (const auto& sous_vect : vect) {
			std::string str = std::to_string(sous_vect);
			//std::string::npos = const static de std::string en lien avec .find("motif") pour voir si aucune correspondance "motif" n'a été trouvée
			int str_digit = str.find('.') != std::string::npos ? str.find('.') : str.size();
			//gestion des 0 inutiles :
			int str_digit_deci = 0;
			if (str.find('.') != std::string::npos) {
				for (int i = str.size() - 1 ; i > str.find('.'); i--) { //(size_t i) à la place de (int i) peut-etre
					if (str[i] != '0') {
						str_digit_deci = i - str.find('.');
						break;
					}
				}
			}
			//int str_digit_deci = str.find('.') != std::string::npos ? str.size() - str.find('.') - 1 : 0;
			//std::cout << str.size() << " " << str.find('.') << "(str_digit ; str_digit_deci) : (" << str_digit << ";" << str_digit_deci << ")." << std::endl;
			max_digit = std::max(max_digit, str_digit + str_digit_deci);
		}
	}
	return max_digit;
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
	int string_width = max_digit();
	//std::cout << "max_digit = " << string_width << std::endl;
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
			std::string s = to_string_with_decimals(_tree[i][k], 1); //A modif Impérativement ATTENTION si on réduit par choix à 1 décimal on aura pas tout
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
