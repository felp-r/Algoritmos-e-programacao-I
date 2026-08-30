/*
 * Exercício 7 — Lista Sequencial: Operações Avançadas
 * 
 * Usando a implementação do Exercício 6, implemente as seguintes operações adicionais:
 * 
 * a) Concatenar: Dadas duas listas L1 e L2, retornar uma nova lista L3 contendo todos os elementos
 *    de L1 seguidos de todos os elementos de L2.
 *    ListaSequencial concatenar(ListaSequencial *l1, ListaSequencial *l2);
 * 
 * b) Intercalar: Dadas duas listas ordenadas L1 e L2, retornar uma nova lista L3 ordenada contendo
 *    todos os elementos intercalados.
 *    ListaSequencial intercalar_ordenado(ListaSequencial *l1, ListaSequencial *l2);
 *    // Exemplo: L1 = {1, 3, 5}, L2 = {2, 4, 6}
 *    // Resultado: L3 = {1, 2, 3, 4, 5, 6}
 * 
 * c) Remover duplicatas: Remover elementos repetidos mantendo a primeira ocorrência.
 *    void remover_duplicatas(ListaSequencial *lista);
 *    // Exemplo: {1, 2, 2, 3, 3, 3, 4} -> {1, 2, 3, 4}
 * 
 * d) Rotação à direita: Deslocar todos os elementos uma posição para a direita (o último vira o primeiro).
 *    void rotacionar_direita(ListaSequencial *lista);
 *    // Exemplo: {1, 2, 3, 4, 5} -> {5, 1, 2, 3, 4}
 * 
 * Dica:
 * Para intercalar ordenado, use a técnica de dois ponteiros. Para remover duplicatas,
 * considere usar marcação com array auxiliar ou comparação dupla (mais ineficiente).
 */

#include <iostream>
#include "lista_sequencial.h"
using namespace std;

// Função auxiliar para selecionar qual lista o usuário quer manipular
ListaSequencial* selecionar_lista(ListaSequencial *l1, ListaSequencial *l2) {
    int opcao_lista;
    do {
        cout << "Selecione a lista (1 ou 2): ";
        cin >> opcao_lista;
        if (opcao_lista == 1) return l1;
        if (opcao_lista == 2) return l2;
        cout << "Lista inválida! Digite 1 ou 2." << endl;
    } while (true);
}

void menu(ListaSequencial *l1, ListaSequencial *l2) {
    int flag = 0;
    while (flag == 0) {
        cout << "\n----------- MENU -----------" << endl;
        cout << "| 1. Inserir               |" << endl;
        cout << "| 2. Remover               |" << endl;
        cout << "| 3. Buscar                |" << endl;
        cout << "| 4. Inverter              |" << endl;
        cout << "| 5. Exibir                |" << endl;
        cout << "| 6. Concatenar (L1 + L2)  |" << endl;
        cout << "| 7. Intercalar Ordenado   |" << endl;
        cout << "| 8. Remover duplicatas    |" << endl;
        cout << "| 9. Rotação à direita     |" << endl;
        cout << "| 10. Status da lista      |" << endl;
        cout << "| 0. Sair                  |" << endl;
        cout << "----------------------------" << endl;

        int op, pos, valor, idx;
        cout << "Escolha: ";
        cin >> op;

        switch (op) {
            // 1. Inserir
            case 1: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                cout << "Posição: ";
                cin >> pos;
                cout << "Valor: ";
                cin >> valor;

                if (inserir(alvo, pos, valor)) {
                    cout << "Inserido com sucesso!" << endl;
                } else {
                    cout << "Não foi possível inserir (posição inválida ou lista cheia)!" << endl;
                }
                break;
            }

            // 2. Remover
            case 2: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                cout << "Posição: ";
                cin >> pos;

                if (remover(alvo, pos, &valor)) {
                    cout << "O valor " << valor << " foi removido com sucesso!" << endl;
                } else {
                    cout << "Não foi possível remover (posição inválida ou lista vazia)!" << endl;
                }
                break;
            }

            // 3. Buscar
            case 3: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                cout << "Digite o valor que deseja encontrar: ";
                cin >> valor;

                idx = buscar(alvo, valor);
                if (idx >= 0) {
                    cout << "O valor " << valor << " está na posição " << idx << "." << endl;
                } else {
                    cout << "O valor buscado não está na lista." << endl;
                }
                break;
            }

            // 4. Inverter
            case 4: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                inverter(alvo);
                cout << "Lista invertida com sucesso!" << endl;
                break;
            }

            // 5. Exibir
            case 5: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                exibir(alvo);
                break;
            }

            // 6. Concatenar
            case 6: {
                ListaSequencial resultado = concatenar(l1, l2);
                cout << "Resultado da concatenação (L1 + L2): ";
                exibir(&resultado);
                break;
            }

            // 7. Intercalar Ordenado
            case 7: {
                ListaSequencial resultado = intercalar_ordenado(l1, l2);
                cout << "Resultado do intercalamento ordenado: ";
                exibir(&resultado);
                break;
            }

            // 8. Remover Duplicatas
            case 8: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                remover_duplicatas(alvo);
                cout << "Duplicatas removidas!" << endl;
                break;
            }

            // 9. Rotação à Direita
            case 9: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                rotacionar_direita(alvo);
                cout << "Lista rotacionada à direita!" << endl;
                break;
            }

            // 10. Status da Lista (Tamanho, Vazia, Cheia)
            case 10: {
                ListaSequencial *alvo = selecionar_lista(l1, l2);
                cout << "Tamanho atual: " << tamanho(alvo) << endl;
                cout << "Está vazia? " << (esta_vazia(alvo) ? "Sim" : "Não") << endl;
                cout << "Está cheia? " << (esta_cheia(alvo) ? "Sim" : "Não") << endl;
                break;
            }

            // 0. Sair
            case 0:
                cout << "Programa encerrado!" << endl;
                flag = 1;
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }
}

int main() {
    // Alocação das duas listas
    ListaSequencial *l1 = new ListaSequencial();
    ListaSequencial *l2 = new ListaSequencial();

    // Inicialização
    inicializar(l1);
    inicializar(l2);

    // Execução do menu
    menu(l1, l2);

    delete l1;
    delete l2;

    return 0;
}