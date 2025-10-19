#include <iostream>
#include <limits>
#include "funcoes_uteis.hpp"

using namespace std;

// Função para ler um número inteiro do terminal.
int ler_inteiro(string mensagem_erro, int lim_inf, int lim_sup){
    float hold;
    while (true){
        cin >> hold;
        /* 1) Se houve erro de conversão (ex.: letra, vazio, etc.);
        Isso pode acontecer quando o usuário digita letras, caracteres especiais, espaços em branco ou quando pressiona Enter sem digitar nada.
        */
        if (cin.fail()){
            cout << "> [Error]: Entrada invalida!" << endl << mensagem_erro;
            cin.clear(); // reseta o estado de erro do stream de entrada.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta todos os caracteres restantes até encontrar uma quebra de linha. esse numeric_limits é para dizer que limpe o máximo possível (tudo).
            continue; // retorna ao início do loop para solicitar uma nova entrada válida.
        }

        /* 2) Se o número está fora da faixa exigida;
        Verifica se a quantidade informada está dentro do intervalo permitido.
        Se estiver fora desse intervalo, exibe uma mensagem de erro e solicita uma nova entrada através do continue, que retorna ao início do loop.
        */
        if (hold != (int) hold || ((hold < lim_inf || hold > lim_sup) && lim_inf != lim_sup)){
            cout << "> [Error]: Numero invalido!" << endl << mensagem_erro;
            continue; // volta para o início do loop para solicitar uma nova entrada válida.
        }
        break;
    }
    return hold;
}