#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <string>
#include "binary_tree.hpp"
#include "color_nodo.hpp"

class red_black_tree : public binary_tree {
public:
    // Construtor de Árvore:
    red_black_tree(int key, std::string data);

    // Principais Operações:
    void printTree() override;
    
protected:
    // Operações com Sobrecarga:
    void insert(int key, std::string data, std::shared_ptr<binary_nodo> &T) override;
    bool remove(int key, std::shared_ptr<binary_nodo> &T) override;
    void fixinsert(std::shared_ptr<color_nodo> &T);
    void fixDelete(std::shared_ptr<color_nodo> &T);
    void R_rotation(std::shared_ptr<color_nodo> &T); // rotação simples à esquerda
    void L_rotation(std::shared_ptr<color_nodo> &T); // rotação simples à direita
};


#endif