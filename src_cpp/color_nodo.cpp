#include "binary_nodo.hpp"
#include "color_nodo.hpp"

using namespace std;

// Construtor de Nó:
color_nodo::color_nodo(int key, string data) : binary_nodo(key, data) {this->color = true;}

// Operações Secundárias:
bool color_nodo::getColor(){return this->color;}
void color_nodo::updateColor() {
	if (this->height == 1){this->color = false;}
    else {
	    shared_ptr<color_nodo> cl, cr;
        if (this->left_child) {cl = dynamic_pointer_cast<color_nodo>(this->left_child);}
        if (this->right_child) {cr = dynamic_pointer_cast<color_nodo>(this->right_child);}
        if (this->color && cl && cr) { //condição 4
            cl->color = false;
            cr->color = false;
        }
        if ((cl && cl->color) || (cr && cr->color)){this->color = false;}
        else if (!cl && cr){cr->color = true;}
        else if (cl && !cr){cl->color = true;}
    }
}