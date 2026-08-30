#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 50000

struct ListaSequencial {
    int dados[MAX];
    int tamanho;
};

void inicializar(ListaSequencial *lista);
bool inserir(ListaSequencial *lista, int posicao, int valor);
int acessar_posicao(ListaSequencial *lista, int posicao);
void destruir_sequencial(ListaSequencial *lista);

#endif