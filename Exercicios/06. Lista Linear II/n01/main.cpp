/*
 * Exercício 8 — Lista Encadeada: Implementação Fundamental
 * 
 * Implemente um TAD de lista simplesmente encadeada com as seguintes operações:
 * 
 * struct No {
 *     int dado;
 *     No *proximo;
 * };
 * 
 * struct ListaEncadeada {
 *     No *cabeca;
 *     int tamanho;
 * };
 * 
 * // Operações a implementar:
 * void inicializar(ListaEncadeada *lista);
 * void inserir_inicio(ListaEncadeada *lista, int valor);
 * void inserir_fim(ListaEncadeada *lista, int valor);
 * bool remover_inicio(ListaEncadeada *lista, int *valor_removido);
 * bool remover_fim(ListaEncadeada *lista, int *valor_removido);
 * bool remover_valor(ListaEncadeada *lista, int valor);
 * int buscar(ListaEncadeada *lista, int valor);
 * void exibir(ListaEncadeada *lista);
 * void destruir(ListaEncadeada *lista);
 * 
 * Requisitos:
 * • Antes de codar, desenhe no papel os diagramas de nós e ponteiros para cada operação
 * • A função remover_valor deve remover todas as ocorrências do valor na lista
 * • A função destruir deve liberar toda a memória alocada
 * • Teste com casos extremos: lista vazia, remoção de lista com um elemento, remoção do único elemento
 * 
 * Exemplo de uso:
 * 
 * ListaEncadeada lista;
 * inicializar(&lista);
 * 
 * inserir_inicio(&lista, 10); // Lista: 10 -> NULL
 * inserir_inicio(&lista, 20); // Lista: 20 -> 10 -> NULL
 * inserir_fim(&lista, 30);    // Lista: 20 -> 10 -> 30 -> NULL
 * 
 * int valor;
 * remover_inicio(&lista, &valor); // valor = 20
 * exibir(&lista);                // Lista: 10 -> 30 -> NULL
 * 
 * Dica:
 * Para inserir no fim com complexidade O(1), considere adicionar um ponteiro cauda à estrutura.
 * Sem ele, a operação é O(n).
 * 
 * Desafio Extra:
 * Implemente uma versão recursiva da função exibir e da função destruir.
 */

#include <iostream>
#include "lista_encadeada.h"

using namespace std;

void exibir_menu() {
    cout << "\n--- MENU LISTA ENCADEADA ---\n";
    cout << "1. Inserir no inicio\n";
    cout << "2. Inserir no fim\n";
    cout << "3. Inserir apos um valor\n";
    cout << "4. Remover do inicio\n";
    cout << "5. Remover do fim\n";
    cout << "6. Remover por valor\n";
    cout << "7. Buscar valor\n";
    cout << "8. Exibir lista\n";
    cout << "9. Destruir lista\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    ListaEncadeada lista;
    inicializar(&lista);

    int opcao = -1;
    int valor, rem;

    while (opcao != 0) {
        exibir_menu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                inserir_inicio(&lista, valor);
                cout << "Inserido no inicio!\n";
                break;

            case 2:
                cout << "Digite o valor: ";
                cin >> valor;
                inserir_fim(&lista, valor);
                cout << "Inserido no fim!\n";
                break;

            case 3: {
                int ref;
                cout << "Digite o valor de referencia: ";
                cin >> ref;
                
                // Busca o nó de referência para passar para a função
                int idx = buscar(&lista, ref);
                if (idx != -1) {
                    No* atual = lista.cabeca;
                    for (int i = 0; i < idx; i++) {
                        atual = atual->proximo;
                    }
                    cout << "Digite o novo valor: ";
                    cin >> valor;
                    inserir_meio(&lista, atual, valor);
                    cout << "Inserido apos o valor " << ref << "!\n";
                }
                break;
            }

            case 4:
                if (remover_inicio(&lista, &rem)) {
                    cout << "Removido do inicio: " << rem << endl;
                }
                break;

            case 5:
                if (remover_fim(&lista, &rem)) {
                    cout << "Removido do fim: " << rem << endl;
                }
                break;

            case 6:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                if (remover_valor(&lista, valor)) {
                    cout << "Valor " << valor << " removido com sucesso!\n";
                }
                break;

            case 7: {
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                int pos = buscar(&lista, valor);
                if (pos != -1) {
                    cout << "Valor encontrado na posicao/indice: " << pos << endl;
                }
                break;
            }

            case 8:
                exibir(&lista);
                break;

            case 9:
                destruir(&lista);
                cout << "Lista destruida com sucesso!\n";
                break;

            case 0:
                destruir(&lista); // Limpa a memoria antes de sair
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }
    }

    return 0;
}