#include "binary_nodo.hpp"

using namespace std;

// Construtor de Nó:
binary_nodo::binary_nodo(int key, string data) {
    this->height = 1;
    this->left_child = nullptr;
    this->right_child = nullptr;
    this->key = key;
    this->data = data;
}

// Operações Secundárias:
int binary_nodo::getHeight() const {return this->height;}
void binary_nodo::updateHeight() {
    int height_left_child = 0, height_right_child = 0;
    if (this->left_child) {height_left_child = this->left_child->getHeight();}
    if (this->right_child) {height_right_child = this->right_child->getHeight();}
    if (height_left_child < height_right_child) {this->height = height_right_child;}
    else{this->height = height_left_child;}
    this->height++;
}