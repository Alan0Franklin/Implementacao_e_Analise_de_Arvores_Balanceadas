#include <memory> // Necessário para std::shared_ptr
#include "binary_nodo.hpp"
#include "AVL_tree.hpp"

using namespace std;

// Construtor de Árvore:
AVL_tree::AVL_tree(int key, string data) : binary_tree(key, data) {}

// Operações com Sobrecarga:
void AVL_tree::insert(int key, string data, shared_ptr<binary_nodo> &T) {
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
    else {T = make_shared<binary_nodo>(key, data);}
    T->updateHeight();
}
bool AVL_tree::remove(int key, shared_ptr<binary_nodo> &T) {
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
    if (result) {T->updateHeight();}
    return result;
}