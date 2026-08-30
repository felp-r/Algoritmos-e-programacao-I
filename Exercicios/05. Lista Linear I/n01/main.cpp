/*
 * Exercício 6 — Lista Sequencial: CRUD Completo
 * 
 * Implemente um TAD de lista sequencial com array estático (capacidade máxima 50) contendo as
 * seguintes operações:
 * 
 * #define MAX 50
 * 
 * struct ListaSequencial {
 *     int dados[MAX];
 *     int tamanho;
 * };
 * 
 * // Operações a implementar:
 * void inicializar(ListaSequencial *lista);
 * bool inserir(ListaSequencial *lista, int posicao, int valor);
 * bool remover(ListaSequencial *lista, int posicao, int *valor_removido);
 * int buscar(ListaSequencial *lista, int valor);
 * int tamanho(ListaSequencial *lista);
 * bool esta_vazia(ListaSequencial *lista);
 * bool esta_cheia(ListaSequencial *lista);
 * void exibir(ListaSequencial *lista);
 * void inverter(ListaSequencial *lista);
 * 
 * Requisitos:
 * • Todas as funções devem tratar erros (lista cheia, lista vazia, posição inválida) com mensagens apropriadas.
 * • A função inverter deve inverter a ordem dos elementos sem usar array auxiliar.
 * • Crie um menu interativo que permita testar todas as operações.
 * 
 * Exemplo de saída esperada:
 * 
 * Menu:
 * 1. Inserir
 * 2. Remover
 * 3. Buscar
 * 4. Inverter
 * 5. Exibir
 * 0. Sair
 * Escolha: 1
 * Posição: 0
 * Valor: 10
 * Elemento 10 inserido na posição 0.
 * 
 * Dica:
 * Para inverter sem array auxiliar, use dois índices (início e fim) e troque os elementos
 * simetricamente: inicio++ e fim-- até se cruzarem.
 * 
 * Desafio Extra:
 * Implemente uma versão dinâmica da lista sequencial que redimensiona automaticamente
 * (dobra a capacidade ao encher, reduz pela metade ao ficar 25% ocupada).
 */

#include <iostream>
#include "lista_sequencial.h"
using namespace std;

void menu(ListaSequencial *lista){
    int flag = 0;  // Utilizado para encerrar o loop
    while(flag == 0){
        cout << "------MENU-----" << endl;
        cout << "| 1. Inserir  |" << endl;
        cout << "| 2. Remover  |" << endl;
        cout << "| 3. Buscar   |" << endl;
        cout << "| 4. Inverter |" << endl;
        cout << "| 5. Exibir   |" << endl;
        cout << "| 0. Sair     |" << endl;
        cout << "---------------" << endl;

        int op, pos, valor, idx;
            
        cout << "Escolha: ";
        cin >> op;

        switch (op)
        {
        // 1. Inserir 
        case 1:
            cout << "Posição: ";
            cin >> pos;

            cout << "Valor: ";
            cin >> valor;

            inserir(lista, pos, valor) ?
            cout << "Inserido com sucesso!" << endl << endl: 
            cout << "Não foi possível inserir!" << endl << endl;
            continue;

        case 2:
            cout << "Posição: ";
            cin >> pos;

            remover(lista, pos, &valor) ?
            cout << "O valor " << valor << " foi removido com sucesso!" << endl << endl:
            cout << "Não foi possível remover!" << endl << endl;
            continue;

        case 3:
            cout << "Digite o valor que deseja encontrar: ";
            cin >> valor;

            idx = buscar(lista, valor);

            idx >= 0 ?
            cout << "O valor buscado está na posição " << idx << endl << endl :
            cout << "O valor buscado não se está na lista." << endl << endl;

            continue;

        case 4:
            inverter(lista);
            continue;

        case 5:
            exibir(lista);
            continue;

        case 0:
            cout << "Programa encerrado!" << endl;
            flag = 1;
            break;
        
        default:
            cout << "Escolha uma opção válida!" << endl;
            continue;
        }
    }
}

int main(){
    ListaSequencial* lista = new ListaSequencial();

    inicializar(lista);

    menu(lista);

    delete[] lista;
    return 0;
}