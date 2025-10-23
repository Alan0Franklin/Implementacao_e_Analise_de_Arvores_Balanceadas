/*
 * red_black_tree.hpp
 *
 *  Created on: 22 Oct 2025
 *      Author: soggart
 */

#ifndef RED_BLACK_TREE_HPP_
#define RED_BLACK_TREE_HPP_

#include <string>
#include "binary_tree.hpp"

class red_black_tree : public binary_tree {
public:
    // Construtor de Árvore:
    red_black_tree(int key, std::string data);

protected:
    // Operações com Sobrecarga:
    void insert(int key, std::string data, std::shared_ptr<binary_nodo> &T) override;
    bool remove(int key, std::shared_ptr<binary_nodo> &T) override;
    void printTree();
};


#endif /* RED_BLACK_TREE_HPP_ */
