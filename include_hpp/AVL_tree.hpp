#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <string>
#include "binary_tree.hpp"

class AVL_tree : public binary_tree {
public:
    // Construtor de Árvore:
    AVL_tree(int key, std::string data);

protected:
    // Operações com Sobrecarga:
    void insert(int key, std::string data, std::shared_ptr<binary_nodo> &T) override;
    bool remove(int key, std::shared_ptr<binary_nodo> &T) override;
};

#endif