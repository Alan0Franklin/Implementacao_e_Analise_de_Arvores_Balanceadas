#include "binary_nodo.hpp"
#include "color_nodo.hpp"

using namespace std;

// Construtor de Nó:
color_nodo::color_nodo(int key, string data) : binary_nodo(key, data) {this->parent = nullptr;}

// Operações Secundárias:
bool color_nodo::getColor(){return this->color;}
void color_nodo::updateColor() {
		int hb = 0;
	    shared_ptr<color_nodo> cl, cr;
        if (this->left_child) {cl = dynamic_pointer_cast<color_nodo>(this->left_child);}
        if (this->right_child) {cr = dynamic_pointer_cast<color_nodo>(this->right_child);}
        if(cl){
			if (cl->color == false) {hb++;}
        	if (dynamic_pointer_cast<color_nodo>(cl->right_child) && !(dynamic_pointer_cast<color_nodo>(cl->left_child))){cl->color = false;dynamic_pointer_cast<color_nodo>(cl->right_child)->color = true;}
        	if (dynamic_pointer_cast<color_nodo>(cl->left_child) && !(dynamic_pointer_cast<color_nodo>(cl->right_child))){cl->color = false;dynamic_pointer_cast<color_nodo>(cl->left_child)->color = true;}
        	if ((cl->left_child && dynamic_pointer_cast<color_nodo>(cl->left_child)->color == false) || (cl->right_child && dynamic_pointer_cast<color_nodo>(cl->right_child)->color == false)) {hb++;}
        }
        if(cr){
			if (cr->color == false) {hb--;}
        	if (dynamic_pointer_cast<color_nodo>(cr->right_child) && !(dynamic_pointer_cast<color_nodo>(cr->left_child))){cr->color = false;dynamic_pointer_cast<color_nodo>(cr->right_child)->color = true;}
        	if (dynamic_pointer_cast<color_nodo>(cr->left_child) && !(dynamic_pointer_cast<color_nodo>(cr->right_child))){cr->color = false;dynamic_pointer_cast<color_nodo>(cr->left_child)->color = true;}
        	if ((cr->left_child && dynamic_pointer_cast<color_nodo>(cr->left_child)->color == false) || (cr->right_child && dynamic_pointer_cast<color_nodo>(cr->right_child)->color == false)) {hb--;}
        }
        if ((cl && cl->color==true) || (cr && cr->color==true)){this->color = false;}
        else if (!cl && cr){cr->color = true;}
        else if (cl && !cr){cl->color = true;}
        if (hb < 0 && cr) {cr->color = true;}
		if (hb > 0 && cl) {cl->color = true;}
		if (this->color==true && cl && cr) { //condição 4
            cl->color = false;
            cr->color = false;
        }
}