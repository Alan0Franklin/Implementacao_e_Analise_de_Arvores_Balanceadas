#include <iostream>
#include <sstream>
#include <iomanip> // necessário para setw e setfill
#include <memory> // Necessário para shared_ptr
#include <vector>
#include <string>
#include "binary_nodo.hpp"
#include "binary_tree.hpp"

using namespace std;

// Construtor de Árvore:
binary_tree::binary_tree(int key, string data) {this->r = make_shared<binary_nodo>(key, data);}

// Principais Operações:
void binary_tree::insert(int key, string data) {this->insert(key, data, this->r);}
bool binary_tree::remove(int key) {return this->remove(key, this->r);}
string binary_tree::search(int key) {return this->search(key, this->r);}
void binary_tree::printTree() {
    int tree_height = this->getTreeHeight();
    if (tree_height == 0) {
        cout << "  \'-> Arvore esta vazia." << endl;
        return;
    }
    vector<vector<shared_ptr<binary_nodo>>> tree_structure(tree_height);
    tree_height--;
    for (int i = 0; i <= tree_height; i++) {tree_structure[i] = vector<shared_ptr<binary_nodo>>(1 << i);}
    cout << "  |-> Estrutura da Arvore:" << endl;
    this->printTree(this->r, 0, 0, tree_structure);
    int number_digits = to_string(static_cast<int>(this->maxKey())).length(); //largest_n_digits
    int smallest_n_digits = to_string(static_cast<int>(this->minKey())).length();
    if (smallest_n_digits > number_digits) {number_digits = smallest_n_digits;}
    int margin = 4 + number_digits;
    int base_width = (1 << tree_height) * (margin + 2 + number_digits);
    string empty_space = string(number_digits, ' ');
    for (int i = 0; i <= tree_height; i++){
        int tree_level_size = (1 << i);
        int space_between_elements = base_width / tree_level_size;
        int hold = (margin - 1) * ((1 << (tree_height - i)) - 1);
        cout << "  |" << setw(hold) << "";
        for (int j = 0; j < tree_level_size; j++){
            ostringstream oss;
            if (tree_structure[i][j]) {oss << '(' << setfill('0') << setw(number_digits) << static_cast<int>(tree_structure[i][j]->key) << ')';}
            else {oss << empty_space << "  ";}
            cout << oss.str();
            if (j != tree_level_size - 1){cout << setw(space_between_elements - number_digits - 2) << "";}
        }
        cout << setw(space_between_elements + 2 - hold) << "Nivel " << i << endl;
        if (i < tree_height) {
            hold /= 2;
            string nodo_line = string(hold - 1, '-');
            string no_nodo_line = string(hold + 1, ' ');
            cout << "  |" << setw(hold + ((number_digits + 1) % 2)) << "";
            for (int k = 0; k < (1 << i); k++) {
                if (tree_structure[i + 1][k * 2]) {cout << '.' << nodo_line << "\'";}
                else {cout << no_nodo_line;}
                cout << empty_space;
                if (tree_structure[i + 1][k * 2 + 1]) {cout << "\'" << nodo_line << '.';}
                else {cout << no_nodo_line;}
                cout << setw(space_between_elements - 2 - number_digits - hold * 2) << "";}
            cout << endl;
        }
    }
    cout << "  \'" << endl;
}

// Operações Secundárias:
float binary_tree::maxKey() const {
    int tree_height = this->getTreeHeight() - 1;
    if (tree_height == -1) {return 0.5f;}
    shared_ptr<binary_nodo> largest_key = this->r;
    for (int i = 0; i < tree_height; i++) {
        if (largest_key->right_child) {largest_key = largest_key->right_child;}
        else {break;}
    }
    return largest_key->key;
}
float binary_tree::minKey() const {
    int tree_height = this->getTreeHeight() - 1;
    if (tree_height == -1) {return 0.5f;}
    shared_ptr<binary_nodo> smallest_key = this->r;
    for (int i = 0; i < tree_height; i++) {
        if (smallest_key->left_child) {smallest_key = smallest_key->left_child;}
        else {break;}
    }
    return smallest_key->key;
}
int binary_tree::getTreeHeight() const {
    if (this->r) {return this->r->getHeight();}
    return 0;
}

// Operações com Sobrecarga:
void binary_tree::insert(int key, string data, shared_ptr<binary_nodo> &T) {
    if (T) {
        if (key == T->key) {T->data = data;}
        else if (key < T->key) {this->insert(key, data, T->left_child);}
        else {this->insert(key, data, T->right_child);}
    }
    else {T = make_shared<binary_nodo>(key, data);}
    T->updateHeight();
}
bool binary_tree::remove(int key, shared_ptr<binary_nodo> &T) {
    bool result = false;
    if (T) {
        if (key == T->key) {
            if (T->right_child && T->left_child) {
                if (T->right_child->left_child){
                    shared_ptr<binary_nodo> T_sucessor = getSuccessor(T->right_child);
                    T_sucessor->left_child->left_child = T->left_child;
                    shared_ptr<binary_nodo> T_hold = T_sucessor->left_child->right_child;
                    T_sucessor->left_child->right_child = T->right_child;
                    T = T_sucessor->left_child;
                    T_sucessor->left_child = T_hold;
                }
                else {
                    T->right_child->left_child = T->left_child;
                    T = T->right_child;
                }
            }
            else if (T->left_child) {T = T->left_child;}
            else if (T->right_child) {T = T->right_child;}
            else {
                T = nullptr; 
                return true;
            }
            result = true;
        }
        else if (key < T->key) {result = this->remove(key, T->left_child);}
        else {result = this->remove(key, T->right_child);}
    }
    else {return false;}
    if (result) {T->updateHeight();}
    return result;
}
shared_ptr<binary_nodo> binary_tree::getSuccessor(shared_ptr<binary_nodo> &T) {
    if (T->left_child->left_child){return getSuccessor(T->left_child);}
    else {return T;}
}
string binary_tree::search(int key, shared_ptr<binary_nodo> &T) {
    if (T) {
        if (key == T->key) {return T->data;}
        else if (key < T->key) {return this->search(key, T->left_child);}
        else {return this->search(key, T->right_child);}
    }
    else {return "";}
}
void binary_tree::printTree(shared_ptr<binary_nodo> &T, int nodo_level, int nodo_index, vector<vector<shared_ptr<binary_nodo>>> &tree_structure) {
    if (T->left_child) {this->printTree(T->left_child, nodo_level + 1, nodo_index * 2, tree_structure);}
    if (T->right_child) {this->printTree(T->right_child, nodo_level + 1, nodo_index * 2 + 1, tree_structure);}
    tree_structure[nodo_level][nodo_index] = T;
}

// Rotações:
void binary_tree::RR_rotation(shared_ptr<binary_nodo> &T) { // rotação simples à esquerda
    shared_ptr<binary_nodo> antigo_r = T;
    T = T->right_child;
    antigo_r->right_child = T->left_child;
    T->left_child = antigo_r;
    T->left_child->updateHeight();
    T->updateHeight();
}
void binary_tree::LL_rotation(shared_ptr<binary_nodo> &T) { // rotação simples à direita
    shared_ptr<binary_nodo> antigo_r = T;
    T = T->left_child;
    antigo_r->left_child = T->right_child;
    T->right_child = antigo_r;
    T->right_child->updateHeight();
    T->updateHeight();
}
void binary_tree::RL_rotation(shared_ptr<binary_nodo> &T) { // rotação dupla à direita-esquerda
    LL_rotation(T->right_child);
    RR_rotation(T);
}
void binary_tree::LR_rotation(shared_ptr<binary_nodo> &T) { // rotação dupla à esquerda-direita
    RR_rotation(T->left_child);
    LL_rotation(T);
}