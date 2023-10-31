#include "BinaryTree.h"
#include <iostream>

void setDepth(int d){
    _depth = d; //affectation de la profondeur
    _tree.resize(d+1); //changement de la taille du vecteur (va de 0 ‡ d inclus)
    for (int i = 0;i <= d;i++) {
        _tree[i].resize(i + 1); //changement de la taille de chaque sous-vecteur du vecteur
    }
}

