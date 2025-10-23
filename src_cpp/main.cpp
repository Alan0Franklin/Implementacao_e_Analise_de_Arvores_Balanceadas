#include <iostream>
#include <memory> // Necessário para std::shared_ptr
#include <limits>
#include "binary_nodo.hpp"
#include "cor_nodo.hpp"
#include "binary_tree.hpp"
#include "AVL_tree.hpp"
#include "red_black_tree.hpp"
#include "funcoes_uteis.hpp"

using namespace std;

int main(){
    int tipo_arvore, chave_no, operacao = 0;
    string conteudo_no = "\n";
    cout << "> Selecione o tipo de arvore deseja criar:" << endl;
    cout << "  | 1 - Arvore Binaria Simples" << endl;
    cout << "  | 2 - Arvore AVL" << endl;
    cout << "  | 3 - Arvore Rubro-Negra" << endl;
	cout << "  !:> ";
    tipo_arvore = ler_inteiro("> Digite o número correspondente ao tipo de arvore que deseja criar, entre 1 e 3: ", 1, 3);
    shared_ptr<binary_tree> arvore;
    cout << "> Determine a chave do seu no raiz, deve ser um inteiro: ";
    chave_no = ler_inteiro("> Digite um numero inteiro correspondente a chave do no raiz: ", 0, 0);
    /*
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "> Determine o conteudo que o no raiz deve conter em uma linha: ";
    getline(cin, conteudo_no);
    */

    switch (tipo_arvore) {
        case 1:
            arvore = make_shared<binary_tree>(chave_no, conteudo_no);
            break;
        case 2:
            arvore = make_shared<AVL_tree>(chave_no, conteudo_no);
            break;
        case 3:
            arvore = make_shared<red_black_tree>(chave_no, conteudo_no);
            break;
    }

    while (operacao != 5) {
        cout << " ---\n" << endl;
        cout << "> Selecione uma operacao para ser realizada na arvore: " << endl;
        cout << "  | 1 - Inserir Elemento" << endl;
        cout << "  | 2 - Remover Elemento" << endl;
        cout << "  | 3 - Buscar Elemento" << endl;
        cout << "  | 4 - Imprimir Arvore" << endl;
        cout << "  | 5 - Sair" << endl;
	    cout << "  !:> ";
        operacao = ler_inteiro("> Digite o número correspondente a operacao que deseja realizar, entre 1 e 5: ", 1, 5);
        switch (operacao) {
            case 1:
                cout << "  !:> Determine a chave do elemento que deseja inserir, deve ser um inteiro: ";
                chave_no = ler_inteiro("  !:> Digite um numero inteiro correspondente a chave do elemento que deseja inserir: ", 0, 0);
                /*
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "> Determine o conteudo que o elemento que deseja inserir deve conter em uma linha: ";
                getline(cin, conteudo_no);
                */
                arvore->insert(chave_no, conteudo_no);
                cout << "  \'-> Operacao de Insercao Concluida!" << endl;
                break;
            case 2:
                cout << "  !:> Informe a chave do elemento que deseja remover, deve ser um inteiro: ";
                chave_no = ler_inteiro("  !:> Digite um numero inteiro correspondente a chave do elemento que deseja remover: ", 0, 0);
                if (!arvore->remove(chave_no)){cout << "> [Error]: Chave " << chave_no << " nao encontrada!" << endl;}
                cout << "  \'-> Operacao de Remocao Concluida!" << endl;
                break;
            case 3: {
                cout << "  !:> Informe a chave do elemento que deseja buscar, deve ser um inteiro: ";
                chave_no = ler_inteiro("  !:> Digite um numero inteiro correspondente a chave do elemento que deseja buscar: ", 0, 0);
                string result_busca = arvore->search(chave_no);
                if (result_busca == ""){cout << "> [Error]: Chave " << chave_no << " nao encontrada!" << endl;}
                else {cout << "  |-> Conteudo do elemento: " << arvore->search(chave_no);}
                cout << "  \'-> Operacao de Busca Concluida!" << endl;
                break;
            }
            case 4:
                arvore->printTree();
                break;
            case 5:
                cout << "  \'-> Fim da Execucao do Programa.\n" << endl;
                break;
        }
    }
    return 0;
}