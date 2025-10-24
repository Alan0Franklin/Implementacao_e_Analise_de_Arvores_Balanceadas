#include <iostream>
#include <sstream>
#include <iomanip> // necessário para setw e setfill
#include <vector> // Necessário para shared_ptr
#include <memory>
#include <string>
#include "binary_nodo.hpp"
#include "color_nodo.hpp"
#include "red_black_tree.hpp"

using namespace std;

// Construtor de Árvore:
red_black_tree::red_black_tree(int key, string data) {this->r = make_shared<color_nodo>(key, data);}

// Operações com Sobrecarga:
void red_black_tree::insert(int key, string data, shared_ptr<binary_nodo> &T) {
    if (T) {
        if (key == T->key) {T->data = data;}
        else if (key < T->key) {
			this->insert(key, data, T->left_child);
			int right_height = 0;
            if (T->right_child) {right_height = T->right_child->getHeight();}
            if (T->left_child->getHeight() - right_height > 1) {
                if (key < (T->left_child->key)) {LL_rotation(T);}
                else {LR_rotation(T);}
            }
		}
        else {
			this->insert(key, data, T->right_child);
			int left_height = 0;
            if (T->left_child) {left_height = T->left_child->getHeight();}
            if (T->right_child->getHeight() - left_height > 1) {
                if ((T->right_child->key) < key) {RR_rotation(T);}
                else {RL_rotation(T);}
            }
		}
    }
    else {T = make_shared<color_nodo>(key, data);}
    shared_ptr<color_nodo> hold = dynamic_pointer_cast<color_nodo>(T);
    hold->updateHeight();
    //if(hold->getHeight() <= 1){hold->color=true;}
    hold->updateColor();
    this->fixinsert(hold);
    if(hold->getHeight() == this->getTreeHeight()){hold->color=false;}
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
        }}
    else {return false;}
    if (result) {
        shared_ptr<color_nodo> hold = dynamic_pointer_cast<color_nodo>(T);
        cout << hold->key << endl;
        this->fixDelete(hold);
        hold->updateHeight();
        cout << hold->getHeight() << endl;
        hold->updateColor();
        cout << hold->getColor() << endl;
    }
    return result;
}
void red_black_tree::printTree() {
    int tree_height = this->getTreeHeight();
    if (tree_height == 0) {
        cout << "  \'-> Arvore esta vazia." << endl;
        return;
    }
    vector<vector<shared_ptr<binary_nodo>>> tree_structure(tree_height);
    tree_height--;
    for (int i = 0; i <= tree_height; i++) {tree_structure[i] = vector<shared_ptr<binary_nodo>>(1 << i);}
    cout << "  |-> Estrutura da Arvore:" << endl;
    binary_tree::printTree(this->r, 0, 0, tree_structure);
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
    	    shared_ptr<color_nodo> element = dynamic_pointer_cast<color_nodo>(tree_structure[i][j]);
            if (element) {
				string cor;
				element->updateColor();
                if (element->color==false) {cor = "B";}
                else if(element->color==true){cor = "R";}
                oss << '(' << setfill('0') << setw(number_digits) << static_cast<int>(element->key) << ')' << cor;
            }
            else {oss << empty_space << "   ";}
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
                if (tree_structure[i + 1][k * 2]) {cout << '.' << nodo_line << "\'";}
                else {cout << no_nodo_line;}
                cout << empty_space;
                if (tree_structure[i + 1][k * 2 + 1]) {cout << "\'" << nodo_line << '.';}
                else {cout << no_nodo_line;}
                cout << setw(space_between_elements - 2 - number_digits - hold * 2) << "";}
        }
        cout << endl;
    }
    cout << "  \'" << endl;
}

void red_black_tree::fixinsert(std::shared_ptr<color_nodo> &T) {
	if(T->parent && (T->parent->parent->right_child || T->parent->parent->left_child)){
	while (T->getHeight() <= 1 && T->parent->color == true) {
            if (T->parent == T->parent->parent->left_child) {
                shared_ptr<color_nodo> y = dynamic_pointer_cast<color_nodo>(T->parent->parent->right_child);
                if (y != nullptr && y->color == true) {
                    T->parent->color = false;
                    y->color = false;
                    T->parent->parent->color = true;
                    T = T->parent->parent;
                } else {
                    if (T == T->parent->right_child) {
                        T = T->parent;
                        L_rotation(T);
                    }
                    T->parent->color = false;
                    T->parent->parent->color = true;
                    R_rotation(T->parent->parent);
                }
            } else {
                shared_ptr<color_nodo> y = dynamic_pointer_cast<color_nodo>(T->parent->parent->left_child);
                if (y != nullptr && y->color == true) {
                    T->parent->color = false;
                    y->color = false;
                    T->parent->parent->color = true;
                    T = T->parent->parent;
                } else {
                    if (T == T->parent->left_child) {
                        T = T->parent;
                        R_rotation(T);
                    }
                    T->parent->color = false;
                    T->parent->parent->color = true;
                    L_rotation(T->parent->parent);
                }
            }
        }
        if(T->getHeight() == this->getTreeHeight()){T->color=false;}
        T->updateColor();
}}

void red_black_tree::fixDelete(std::shared_ptr<color_nodo> &T) {
        while (T->getHeight() != this->getTreeHeight() && T != nullptr && T->color == false) {
			cout<<"a"<<endl;
            if (T == T->parent->left_child) {
				cout<<"if (T == T->parent->left_child)"<<endl;
                if(T->parent->right_child){shared_ptr<color_nodo> w = dynamic_pointer_cast<color_nodo>(T->parent->right_child);
                if (w->color == true) {
                    w->color = false;
                    T->parent->color = true;
                    L_rotation(T->parent);
                    w = dynamic_pointer_cast<color_nodo>(T->parent->right_child);
                }
                if ((w->left_child == nullptr || dynamic_pointer_cast<color_nodo>(w->left_child)->color == false) &&
                    (w->right_child == nullptr || dynamic_pointer_cast<color_nodo>(w->right_child)->color == false)) {
                    w->color = true;
                    T = T->parent;
                } else {
                    if (w->right_child == nullptr || dynamic_pointer_cast<color_nodo>(w->right_child)->color == false) {
                        if (w->left_child != nullptr)
                            dynamic_pointer_cast<color_nodo>(w->left_child)->color = false;
                        w->color = true;
                        R_rotation(w);
                        w = dynamic_pointer_cast<color_nodo>(T->parent->right_child);
                    }
                    w->color = T->parent->color;
                    T->parent->color = false;
                    if (w->right_child != nullptr)
                        dynamic_pointer_cast<color_nodo>(w->right_child)->color = false;
                    L_rotation(T->parent);
                    //T = root;
                }
            } else {
                shared_ptr<color_nodo> w = dynamic_pointer_cast<color_nodo>(T->parent->left_child);
                if (w->color == true) {
                    w->color = false;
                    T->parent->color = true;
                    R_rotation(T->parent);
                    w = dynamic_pointer_cast<color_nodo>(T->parent->left_child);
                }
                if ((w->right_child == nullptr || dynamic_pointer_cast<color_nodo>(w->right_child)->color == false) &&
                    (w->left_child == nullptr || dynamic_pointer_cast<color_nodo>(w->left_child)->color == false)) {
                    w->color = true;
                    T = T->parent;
                } else {
                    if (w->left_child == nullptr || dynamic_pointer_cast<color_nodo>(w->left_child)->color == false) {
                        if (w->right_child != nullptr)
                            dynamic_pointer_cast<color_nodo>(w->right_child)->color = false;
                        w->color = true;
                        L_rotation(w);
                        w = dynamic_pointer_cast<color_nodo>(T->parent->left_child);
                    }
                    w->color = T->parent->color;
                    T->parent->color = false;
                    if (w->left_child != nullptr)
                        dynamic_pointer_cast<color_nodo>(w->left_child)->color = false;
                    R_rotation(T->parent);
                    //T = root;
                }
            }
        }}
        if (T != nullptr)
            T->color = false;
    }

	// Rotações:
void red_black_tree::R_rotation(shared_ptr<color_nodo> &T) { // rotação simples à esquerda
	T->updateColor();
    if((T->left_child)&&(T->right_child)){shared_ptr<color_nodo> antigo_r = T;
    T = dynamic_pointer_cast<color_nodo>(T->right_child);
    antigo_r->right_child = T->left_child;
    T->left_child = antigo_r;
    T->left_child->updateHeight();
    dynamic_pointer_cast<color_nodo>(T->left_child)->updateColor();
    T->updateHeight();
    T->updateColor();}
}
void red_black_tree::L_rotation(shared_ptr<color_nodo> &T) { // rotação simples à direita
	T->updateColor();
    if((T->left_child)&&(T->right_child)){shared_ptr<color_nodo> antigo_r = T;
    T = dynamic_pointer_cast<color_nodo>(T->left_child);
    antigo_r->left_child = T->right_child;
    T->right_child = antigo_r;
    T->right_child->updateHeight();
    dynamic_pointer_cast<color_nodo>(T->right_child)->updateColor();
    T->updateHeight();
    T->updateColor();}
}
    
	/*
    int tree_height = this->getTreeHeight();
    int hb = 0;
    if (tree_height == 0) {
        cout << "  \'-> Arvore esta vazia." << endl;
        return;
    }
    vector<vector<shared_ptr<binary_nodo>>> tree_structure(tree_height);
    tree_height--;
    for (int ii = 0; ii <= tree_height; ii++) {tree_structure[ii] = vector<shared_ptr<binary_nodo>>(1 << ii);}
    for (int ii = 0; ii <= tree_height; ii++){//primeiro loop
        int tree_level_size = (1 << ii);
        for (int jj = 0; jj < tree_level_size; jj++){//segundo loop
    	    shared_ptr<color_nodo> element = dynamic_pointer_cast<color_nodo>(tree_structure[ii][jj]);
    	    if(element){
				if(element->getHeight() <= 1){element->color == false;}
    	    	shared_ptr<color_nodo> parent = dynamic_pointer_cast<color_nodo>(tree_structure[ii-1][jj]);
    	    	if(parent){
					parent->updateColor();
					if(parent->color == true){
						element->color = false;
					}
				}
				if (element->color == false) {
					hb++;
					cout<<hb<<endl;
				}
			}
        }
    }
}*/
