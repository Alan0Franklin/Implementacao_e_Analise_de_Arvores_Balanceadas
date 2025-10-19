#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory> // Necessário para std::shared_ptr
#include <string>
#include <vector>
#include "binary_nodo.hpp"

class binary_tree {
public:
    // Construtor de Árvore:
    binary_tree(int key, std::string data);

    // Destrutor de Árvore:
    virtual ~binary_tree() = default;

    // Principais Operações:
    virtual void insert(int key, std::string data);
    virtual bool remove(int key);
    virtual std::string search(int key);
    
    // Operações Secundárias:
    int maxKey();
    int minKey();
    void printTree();
    int getTreeHeight() const;

protected:
    // Nó raiz da árvore
    std::shared_ptr<binary_nodo> r;

    // Operações com Sobrecarga:
    virtual void insert(int key, std::string data, std::shared_ptr<binary_nodo> &T);
    virtual bool remove(int key, std::shared_ptr<binary_nodo> &T);
    std::shared_ptr<binary_nodo> getSuccessor(std::shared_ptr<binary_nodo> &T);
    virtual std::string search(int key, std::shared_ptr<binary_nodo> &T);
    void printTree(std::shared_ptr<binary_nodo> &T, int nodo_level, int nodo_index, std::vector<std::vector<float>> &tree_structure);

    // Rotações:
    void RR_rotation(std::shared_ptr<binary_nodo> &T); // rotação simples à esquerda
    void LL_rotation(std::shared_ptr<binary_nodo> &T); // rotação simples à direita
    void RL_rotation(std::shared_ptr<binary_nodo> &T); // rotação dupla à esquerda
    void LR_rotation(std::shared_ptr<binary_nodo> &T); // rotação dupla à direita
};

#endif