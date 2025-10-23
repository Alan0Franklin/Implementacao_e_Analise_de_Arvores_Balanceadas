#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <string>
#include "binary_tree.hpp"

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
};


#endif