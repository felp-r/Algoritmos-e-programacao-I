#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

struct No {
    int dado;
    No *proximo;
};

struct ListaEncadeada {
    No *cabeca;
    No *cauda;
    int tamanho;
};

// Operações a implementar:
void inicializar(ListaEncadeada *lista);
void inserir_inicio(ListaEncadeada *lista, int valor);
void inserir_fim(ListaEncadeada *lista, int valor);
void inserir_meio(ListaEncadeada *lista, No *elemento, int valor);
void inserir_ordenado(ListaEncadeada *lista, int valor);
bool remover_inicio(ListaEncadeada *lista, int *valor_removido);
bool remover_fim(ListaEncadeada *lista, int *valor_removido);
bool remover_valor(ListaEncadeada *lista, int valor);
int buscar(ListaEncadeada *lista, int valor);
void inverter(ListaEncadeada *lista);
int encontrar_meio(ListaEncadeada *lista);
bool tem_ciclo(ListaEncadeada *lista);
void exibir(ListaEncadeada *lista);
void destruir(ListaEncadeada *lista);

#endif