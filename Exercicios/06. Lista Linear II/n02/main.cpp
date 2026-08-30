/*
 * Exercício 9 — Lista Encadeada: Operações Avançadas
 * 
 * Estenda a implementação da lista encadeada do Exercício 8 com as seguintes operações:
 * 
 * a) Inverter lista: Inverter a ordem dos nós da lista encadeada.
 *    void inverter(ListaEncadeada *lista);
 *    // Exemplo: 1 -> 2 -> 3 -> NULL torna-se 3 -> 2 -> 1 -> NULL
 * 
 *    Implemente duas versões:
 *    • Iterativa: Percorre a lista ajustando ponteiros
 *    • Recursiva: Chamadas recursivas que retornam a nova cabeça
 * 
 * b) Inserir ordenado: Inserir elemento mantendo a lista ordenada crescentemente.
 *    void inserir_ordenado(ListaEncadeada *lista, int valor);
 *    // Exemplo: Lista = 1 -> 3 -> 5 -> NULL
 *    // inserir_ordenado(lista, 4) => Lista = 1 -> 3 -> 4 -> 5 -> NULL
 *    // inserir_ordenado(lista, 0) => Lista = 0 -> 1 -> 3 -> 4 -> 5 -> NULL
 * 
 * c) Encontrar elemento do meio: Retornar o valor do nó central sem saber o tamanho antecipadamente.
 *    int encontrar_meio(ListaEncadeada *lista);
 *    // Lista = 1 -> 2 -> 3 -> 4 -> 5 => retorna 3
 *    // Lista = 1 -> 2 -> 3 -> 4      => retorna 2 (primeiro do meio)
 * 
 * d) Detectar ciclo: Verificar se a lista contém um ciclo (último nó aponta para algum nó anterior).
 *    bool tem_ciclo(ListaEncadeada *lista);
 * 
 * Dica:
 * Para encontrar meio, use a técnica dos dois ponteiros: um avança 1 passo e outro avança 2
 * passos. Quando o rápido chegar ao fim, o lento estará no meio.
 * Para tem_ciclo, use o algoritmo de Floyd (tartaruga e lebre): se os ponteiros se encontrarem,
 * há ciclo.
 * 
 * Desafio Extra:
 * Implemente inserir_ordenado de forma recursiva e compare a legibilidade com a versão iterativa.
 */


#include <iostream>
#include "lista_encadeada.h"

using namespace std;

void exibir_menu() {
    cout << "\n--- MENU LISTA ENCADEADA ---\n";
    cout << "1. Inserir no inicio\n";
    cout << "2. Inserir no fim\n";
    cout << "3. Inserir apos um valor\n";
    cout << "4. Inserir ordenado\n";
    cout << "5. Remover do inicio\n";
    cout << "6. Remover do fim\n";
    cout << "7. Remover por valor (todas as ocorrencias)\n";
    cout << "8. Buscar valor\n";
    cout << "9. Encontrar elemento do meio\n";
    cout << "10. Inverter lista (Iterativo)\n";
    cout << "11. Verificar se tem ciclo\n";
    cout << "12. Exibir lista\n";
    cout << "13. Destruir lista\n";
    cout << "14. Criar ciclo de teste (para testar a opcao 11)\n";
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
                cout << "Digite o valor: ";
                cin >> valor;
                inserir_ordenado(&lista, valor);
                cout << "Inserido de forma ordenada!\n";
                break;

            case 5:
                if (remover_inicio(&lista, &rem)) {
                    cout << "Removido do inicio: " << rem << endl;
                }
                break;

            case 6:
                if (remover_fim(&lista, &rem)) {
                    cout << "Removido do fim: " << rem << endl;
                }
                break;

            case 7:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                if (remover_valor(&lista, valor)) {
                    cout << "Ocorrencias do valor " << valor << " removidas!\n";
                }
                break;

            case 8: {
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                int pos = buscar(&lista, valor);
                if (pos != -1) {
                    cout << "Valor encontrado no indice: " << pos << endl;
                }
                break;
            }

            case 9: {
                int meio = encontrar_meio(&lista);
                if (meio != -1) {
                    cout << "Elemento do meio: " << meio << endl;
                }
                break;
            }

            case 10:
                inverter(&lista); // Chama a versão iterativa
                cout << "Lista invertida com sucesso!\n";
                break;

            case 11:
                if (tem_ciclo(&lista)) {
                    cout << "ATENCAO: A lista possui um ciclo!\n";
                } else {
                    cout << "A lista NAO possui ciclo.\n";
                }
                break;

            case 12:
                exibir(&lista);
                break;

            case 13:
                destruir(&lista);
                cout << "Lista destruida com sucesso!\n";
                break;

            case 14:
                // Força a cauda a apontar para a cabeça criando um ciclo
                if (lista.cauda != nullptr && lista.cabeca != nullptr) {
                    lista.cauda->proximo = lista.cabeca;
                    cout << "Ciclo criado! (Cauda agora aponta para a Cabeça)\n";
                    cout << "AVISO: Nao use as opcoes 8, 9, 10 ou 12 enquanto houver ciclo!\n";
                } else {
                    cout << "Insira elementos na lista primeiro.\n";
                }
                break;

            case 0:
                // Se houver ciclo, desfaz antes de destruir para nao travar o loop
                if (lista.cauda != nullptr) {
                    lista.cauda->proximo = nullptr;
                }
                destruir(&lista);
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }
    }

    return 0;
}