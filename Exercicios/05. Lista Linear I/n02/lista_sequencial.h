#ifndef LISTA_SEQUENCIAL
#define LISTA_SEQUENCIAL

#define MAX 50

struct ListaSequencial {
    int dados[MAX];
    int tamanho;
};

// Operações a implementar:
void inicializar(ListaSequencial *lista);
bool inserir(ListaSequencial *lista, int posicao, int valor);
bool remover(ListaSequencial *lista, int posicao, int *valor_removido);
int buscar(ListaSequencial *lista, int valor);
int tamanho(ListaSequencial *lista);
bool esta_vazia(ListaSequencial *lista);
bool esta_cheia(ListaSequencial *lista);
ListaSequencial concatenar(ListaSequencial *l1, ListaSequencial *l2);
ListaSequencial intercalar_ordenado(ListaSequencial *l1, ListaSequencial *l2);
void remover_duplicatas(ListaSequencial *lista);
void rotacionar_direita(ListaSequencial *lista);
void exibir(ListaSequencial *lista);
void inverter(ListaSequencial *lista);

#endif