#include <iostream>
#include "lista_encadeada.h"

using namespace std;

void inicializar(ListaEncadeada *lista){
    lista->cabeca = nullptr;
    lista->cauda = nullptr;
    lista->tamanho = 0;
}

No* criar_no(int valor){
    No* novo = new No();

    if(novo == nullptr){
        cout << "Erro: memória insuficiente" << endl;
        return nullptr;
    }

    novo->dado = valor;
    novo->proximo = nullptr;
    return novo;
}

void inserir_inicio(ListaEncadeada *lista, int valor){
    No* novo = criar_no(valor);

    novo->proximo = lista->cabeca;
    lista->cabeca = novo;

    if(lista->cauda == nullptr)
        lista->cauda = novo;

    lista->tamanho++;
}

void inserir_fim(ListaEncadeada *lista, int valor){
    No* novo = criar_no(valor);

    if(lista->cabeca == nullptr){
        lista->cabeca = novo;
        lista->cauda = novo;
    } else{
        lista->cauda->proximo = novo;
        lista->cauda = novo;
    }

    lista->tamanho++;
}

void inserir_meio(ListaEncadeada *lista, No *elemento, int valor){
    if(elemento == nullptr)
        return;

    No* novo = criar_no(valor);

    if(novo == nullptr)
        return;

    if(elemento == lista->cauda)
        lista->cauda = novo;

    novo->proximo = elemento->proximo;
    elemento->proximo = novo;

    lista->tamanho++;
}

void inserir_ordenado(ListaEncadeada *lista, int valor){
    No* novo = criar_no(valor);

    if (lista->cabeca == nullptr || valor <= lista->cabeca->dado) {
        novo->proximo = lista->cabeca;
        lista->cabeca = novo;
        
        // Se a lista estava vazia, atualiza a cauda tambem
        if (lista->cauda == nullptr) {
            lista->cauda = novo;
        }
    } 
    else {
        No* atual = lista->cabeca;

        while (atual->proximo != nullptr && atual->proximo->dado < valor) {
            atual = atual->proximo;
        }

        // Insere o novo no apos o 'atual'
        novo->proximo = atual->proximo;
        atual->proximo = novo;

        // Se inseriu apos o ultimo elemento antigo, atualiza a cauda
        if (novo->proximo == nullptr) {
            lista->cauda = novo;
        }
    }

    lista->tamanho++;
}

bool remover_inicio(ListaEncadeada *lista, int *valor_removido){
    if(lista->cabeca == nullptr){
        cout << "Erro: lista vazia!" << endl;
        return false;
    }

    No *temp = lista->cabeca;
    *valor_removido = temp->dado;

    
    lista->cabeca = temp->proximo;

    if(lista->cabeca == nullptr)
        lista->cauda == nullptr;

    delete temp;
    lista->tamanho--;
    
    return true;
}

bool remover_fim(ListaEncadeada *lista, int *valor_removido){
    if(lista->cabeca == nullptr){
        cout << "Erro: lista vazia!" << endl;
        return false;
    }

    if(lista->cabeca->proximo == nullptr){  // apenas um elemento
        *valor_removido = lista->cabeca->dado;
        delete lista->cabeca;
        lista->cabeca = nullptr;
        lista->cabeca = nullptr;
    } else{
        No *atual = lista->cabeca;
        // percorre até o último elemento
        while(atual->proximo->proximo != nullptr){
            atual = atual->proximo;
        }
        *valor_removido = atual->proximo->dado;
        delete atual->proximo;
        atual->proximo = nullptr;
        lista->cauda = atual;
    }

    lista->tamanho--;
    
    return true;
}

bool remover_valor(ListaEncadeada *lista, int valor){
    if(lista->cabeca == nullptr){
        cout << "Erro: lista vazia!" << endl;
        return false;
    }

    bool removeu_algum = false;

    while(lista->cabeca != nullptr && lista->cabeca->dado == valor){
        No *remover = lista->cabeca;
        lista->cabeca = lista->cabeca->proximo;
        delete remover;
        lista->tamanho--;
        removeu_algum = true;
    }

    // Se a lista ficou vazia apos remover as cabecas
    if(lista->cabeca == nullptr){
        lista->cauda = nullptr;
        return removeu_algum;
    }

    No *atual = lista->cabeca;
    while(atual->proximo != nullptr){
        if(atual->proximo->dado == valor){
            No *remover = atual->proximo;

            // Se o nó removido for a cauda, atualiza para o 'atual'
            if(remover == lista->cauda){
                lista->cauda = atual;
            }

            atual->proximo = remover->proximo;
            delete remover;
            lista->tamanho--;
            removeu_algum = true;
        } else {
            atual = atual->proximo;
        }
    }

    if(!removeu_algum){
        cout << "Valor nao encontrado!" << endl;
    }

    return removeu_algum;
}

int buscar(ListaEncadeada *lista, int valor){
    if(lista->cabeca == nullptr){
        cout << "Erro: Lista vazia!" << endl;
        return -1;
    }

    int idx = 0;
    No* atual = lista->cabeca;

    while (atual != nullptr) {
        if (atual->dado == valor) {
            return idx; // Encontrou
        }
        atual = atual->proximo;
        idx++;
    }

    cout << "Valor não encontrado!" << endl;
    return -1;
}

int encontrar_meio(ListaEncadeada *lista) {
    if (lista->cabeca == nullptr) {
        cout << "Erro: Lista vazia!" << endl;
        return -1;
    }

    No* lento = lista->cabeca;
    No* rapido = lista->cabeca;

    // O ponteiro rápido anda o dobro da velocidade do lento.
    // A condição garante a preferência pelo primeiro elemento do meio em listas pares.
    while (rapido->proximo != nullptr && rapido->proximo->proximo != nullptr) {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
    }

    return lento->dado;
}

void inverter(ListaEncadeada *lista) {
    // Se a lista estiver vazia ou tiver apenas 1 elemento
    if (lista == nullptr || lista->cabeca == nullptr || lista->cabeca->proximo == nullptr) {
        return;
    }

    No* anterior = nullptr;
    No* atual = lista->cabeca;
    No* proximo = nullptr;

    // A antiga cabeça se tornará a nova cauda
    lista->cauda = lista->cabeca;

    while (atual != nullptr) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->cabeca = anterior;
}

bool tem_ciclo(ListaEncadeada *lista) {
    if (lista == nullptr || lista->cabeca == nullptr) {
        return false;
    }

    No *lento = lista->cabeca;
    No *rapido = lista->cabeca;

    while (rapido != nullptr && rapido->proximo != nullptr) {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;

        if (lento == rapido) {
            return true;
        }
    }

    return false;
}

void exibir(ListaEncadeada *lista){
    if(lista->cabeca == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

    No* atual = lista->cabeca;

    cout << "Lista encadeada: [";
    while(atual != nullptr){
        cout << atual->dado << " ";
        atual = atual->proximo;
    }
    cout << "]" << endl;
}

void destruir(ListaEncadeada *lista){
    if(lista->cabeca == nullptr){
        cout << "Lista vazia!" << endl;
        return;
    }

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
