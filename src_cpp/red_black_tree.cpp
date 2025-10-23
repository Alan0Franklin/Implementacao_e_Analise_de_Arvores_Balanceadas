#include <iostream>
/*#include <sstream>
#include <iomanip> // necessário para setw e setfill
#include <vector>*/ // Necessário para shared_ptr
#include <memory>
#include <string>
#include "binary_nodo.hpp"
#include "cor_nodo.hpp"
#include "red_black_tree.hpp"

using namespace std;
// Construtor de Árvore:
red_black_tree::red_black_tree(int key, string data) : binary_tree(key, data) {}

// Operações com Sobrecarga:
void red_black_tree::insert(int key, string data, shared_ptr<binary_nodo> &T) {
    if (T) {
        if (key == T->key) {T->data = data;}
        else if (key < T->key) {
			cout<<"menor"<<endl;
            this->insert(key, data, T->left_child);
            int right_height = 0;
            if (T->right_child) {right_height = T->right_child->getHeight();}
            if (T->left_child->getHeight() - right_height > 1) {
                if (key < (T->left_child->key)) {LL_rotation(T);}
                else {LR_rotation(T);}
            }
        }
        else {
			cout<<"maior"<<endl;
            this->insert(key, data, T->right_child);
            int left_height = 0;
            if (T->left_child) {left_height = T->left_child->getHeight();}
            if (T->right_child->getHeight() - left_height > 1) {
                if ((T->right_child->key) < key) {RR_rotation(T);}
                else {RL_rotation(T);}
            }
        }
    }
    else {T = make_shared<cor_nodo>(key, data);cout<<"T n existe"<<endl;}
    T->updateHeight();cout<<"atualizando altura"<<endl;
    std::shared_ptr<cor_nodo> sog = dynamic_pointer_cast<cor_nodo>(T);
    sog->updateCor();cout<<"atualizando cor"<<endl;
}
bool red_black_tree::remove(int key, shared_ptr<binary_nodo> &T) {
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
        int right_height = 0;
        int left_height = 0;
        if (T->right_child) {right_height = T->right_child->getHeight();}
        if (T->left_child) {left_height = T->left_child->getHeight();}
        if (right_height - left_height > 1) {
            if ((T->right_child->key) < key) {RR_rotation(T);}
            else {RL_rotation(T);}
        }
        if (left_height - right_height > 1) {
            if (key < (T->left_child->key)) {LL_rotation(T);}
            else {LR_rotation(T);}
        }
    }
    else {return false;}
    if (result) {T->updateHeight();dynamic_pointer_cast<cor_nodo>(T)->updateCor();}
    return result;
}

void red_black_tree::printTree() {
    int tree_height = this->getTreeHeight();
    vector<vector<float>> tree_structure(tree_height);
    tree_height--;
    for (int i = 0; i <= tree_height; i++) {tree_structure[i] = vector<float>((1 << i), 0.5f);}
    cout << "  |-> Estrutura da Arvore:" << endl;
    this->printTree(this->r, 0, 0, tree_structure);
    int number_digits = to_string(this->maxKey()).length(); //largest_n_digits
    int smallest_n_digits = to_string(this->minKey()).length();
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
            float element = tree_structure[i][j];
            if (element == 0.5f) {oss << empty_space << "  ";}
            else if (AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA(cor)){oss << '(' << setfill('0') << setw(number_digits) << static_cast<int>(element) << "R" << ')';}
            else {oss << '(' << setfill('0') << setw(number_digits) << static_cast<int>(element) << "B" << ')';)
            cout << oss.str();
            if (j != tree_level_size - 1){cout << setw(space_between_elements - number_digits - 3) << "";}
        }
        cout << setw(space_between_elements + 2 - hold) << "Nivel " << i << endl;
        if (i < tree_height) {
            hold /= 2;
            string nodo_line = string(hold - 1, '-');
            string no_nodo_line = string(hold + 1, ' ');
            cout << "  |" << setw(hold + ((number_digits + 1) % 2)) << "";
            for (int k = 0; k < (1 << i); k++) {
                if (tree_structure[i + 1][k * 2] == 0.5f) {cout << no_nodo_line;}
                else {cout << '.' << nodo_line << "\'";}
                cout << empty_space;
                if (tree_structure[i + 1][k * 2 + 1] == 0.5f) {cout << no_nodo_line;}
                else {cout << "\'" << nodo_line << '.';}
                cout << setw(space_between_elements - 2 - number_digits - hold * 2) << "";}
        }
        cout << "  \'" << endl;
    }
}


