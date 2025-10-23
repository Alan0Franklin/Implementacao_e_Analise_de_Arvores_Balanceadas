#ifndef COLOR_NODO_HPP
#define COLOR_NODO_HPP

class color_nodo: public binary_nodo {
public:
    bool color; //false é preto, true é vermelho

    // Construtor de Nó:
    color_nodo(int key, std::string data);
    
    // Operações Secundárias:
    bool getColor();
    void updateColor();
};

#endif