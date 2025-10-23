#include "binary_nodo.hpp"
#include "cor_nodo.hpp"

using namespace std;

// Construtor de Nó:
cor_nodo::cor_nodo(int key, string data) : binary_nodo(key, data) {
	this->cor=true;
	
}
// Operações Secundárias:
//void cor_nodo::setCor(bool a){
//	this->cor = a;
//}

bool cor_nodo::getCor(){
    return this->cor;
}
void cor_nodo::updateCor() {
	//left_child = std::shared_ptr<binary_nodo> left_child;
	//right_child = std::shared_ptr<binary_nodo> right_child;
	if(this!=nullptr){
		shared_ptr<cor_nodo> cl = dynamic_pointer_cast<cor_nodo>(this->left_child);
		shared_ptr<cor_nodo> cr = dynamic_pointer_cast<cor_nodo>(this->right_child);

    	if (this->height == 1){this->cor = false;}//raiz

    	if ((this->cor == true)&&(this->left_child)&&(this->right_child)) { //condição 4
            cl->cor = false;
            cr->cor = false;
    	}

    	if ((cl->cor == true)||(cr->cor == true)){
        	this->cor = false;
    	} else if ((this->left_child == nullptr)&&(this->right_child)){
        	cr->cor = true;
    	} else if ((this->left_child)&&(this->right_child == nullptr)){
        	cl->cor = true;
    	}
	}
}


