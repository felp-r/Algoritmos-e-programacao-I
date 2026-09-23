#include <iostream>
#include "lista_encadeada.h"

using namespace std;

void inicializar_encadeada(ListaEncadeada *lista){
    lista->cabeca = nullptr;
    lista->cauda = nullptr;
    lista->tamanho = 0;
}

No* criar_no(int valor){
    No* novo = new (std::nothrow) No();
    if(novo == nullptr){
        return nullptr;
    }

    novo->dado = valor;
    novo->proximo = nullptr;
    return novo;
}

void inserir_inicio_encadeada(ListaEncadeada *lista, int valor){
    No* novo = criar_no(valor);
    if(novo == nullptr) return;

    novo->proximo = lista->cabeca;
    lista->cabeca = novo;

    if(lista->cauda == nullptr)
        lista->cauda = novo;

    lista->tamanho++;
}

void inserir_fim_encadeada(ListaEncadeada *lista, int valor){
    No* novo = criar_no(valor);
    if(novo == nullptr) return;

    if(lista->cabeca == nullptr){
        lista->cabeca = novo;
        lista->cauda = novo;
    } else {
        lista->cauda->proximo = novo;
        lista->cauda = novo;
    }

    lista->tamanho++;
}

// Acesso a posicao especifica (Experimento 3)
int acessar_posicao_encadeada(ListaEncadeada *lista, int posicao){
    No* atual = lista->cabeca;
    for(int i = 0; i < posicao && atual != nullptr; i++){
        atual = atual->proximo;
    }
    return (atual != nullptr) ? atual->dado : -1;
}

void destruir_encadeada(ListaEncadeada *lista){
    No* atual = lista->cabeca;

    while(atual != nullptr){
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    lista->cabeca = nullptr;
    lista->cauda = nullptr;
    lista->tamanho = 0;
}