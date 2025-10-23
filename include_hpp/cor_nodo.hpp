/*
 * cor_nodo.hpp
 *
 *  Created on: 22 Oct 2025
 *      Author: soggart
 */

#ifndef INCLUDE_HPP_COR_NODO_HPP_
#define INCLUDE_HPP_COR_NODO_HPP_

class cor_nodo: public binary_nodo {
public:
    bool cor; //false é preto, true é vermelho

    // Construtor de Nó:
    cor_nodo(int key, std::string data);

    // Destrutor de Nó:
    virtual ~cor_nodo() = default;
    
    // Operações Secundárias:
    bool getCor();
    void updateCor();
};



#endif /* INCLUDE_HPP_COR_NODO_HPP_ */
