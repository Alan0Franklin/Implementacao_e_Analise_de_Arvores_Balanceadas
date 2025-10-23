#ifndef BINARY_NODO_HPP
#define BINARY_NODO_HPP

#include <memory> // Necessário para std::shared_ptr
#include <string>

class binary_nodo {
protected:
    int height;

public:
	bool cor = true;//false é preto, true é vermelho
    int key;
    std::string data;
    std::shared_ptr<binary_nodo> left_child;
    std::shared_ptr<binary_nodo> right_child;

    // Construtor de Nó:
    binary_nodo(int key, std::string data);

    // Destrutor de Nó:
    virtual ~binary_nodo() = default;
    
    // Operações Secundárias:
    int getHeight() const;
    void updateHeight();
};

/*
    int getKey() const;
    std::string getData() const;
    std::shared_ptr<const binary_nodo> getLeft_Child() const;
    std::shared_ptr<const binary_nodo> getRight_Child() const;
*/

#endif