#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

struct No {
    int dado;
    No *proximo;
};

struct ListaEncadeada {
    No *cabeca;
    No *cauda;
    int tamanho;
};

void inicializar_encadeada(ListaEncadeada *lista);
void destruir_encadeada(ListaEncadeada *lista);

void inserir_inicio_encadeada(ListaEncadeada *lista, int valor);
void inserir_fim_encadeada(ListaEncadeada *lista, int valor);
int acessar_posicao_encadeada(ListaEncadeada *lista, int posicao);

#endif