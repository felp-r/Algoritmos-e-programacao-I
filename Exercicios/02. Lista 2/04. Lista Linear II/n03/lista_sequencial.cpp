#include <iostream>
#include "lista_sequencial.h"

using namespace std;

void inicializar(ListaSequencial *lista) {
    lista->tamanho = 0;
}

bool inserir(ListaSequencial *lista, int posicao, int valor) {
    if (lista->tamanho >= MAX) {
        return false;
    }

    if (posicao < 0 || posicao > lista->tamanho) {
        return false;
    }

    // Desloca elementos para a direita
    for (int i = lista->tamanho; i > posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return true;
}

int acessar_posicao(ListaSequencial *lista, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        return lista->dados[posicao];
    }
    return -1;
}

void destruir_sequencial(ListaSequencial *lista) {
    lista->tamanho = 0;
}