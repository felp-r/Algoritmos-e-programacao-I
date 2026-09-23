/*
 * Problema: Soma e Contagem em Lista Encadeada com Funções Recursivas
 * 
 * Dada uma lista encadeada de números inteiros, implemente uma função recursiva que calcule 
 * a soma de todos os elementos. Em seguida, implemente outra função recursiva que conte quantos 
 * elementos são maiores que um valor X.
 * 
 * Entrada:
 * - Primeira linha: N (número de elementos, 1 <= N <= 1000)
 * - Segunda linha: N inteiros (elementos da lista)
 * - Terceira linha: X (valor de referência)
 * 
 * Saída:
 * - Primeira linha: soma de todos os elementos
 * - Segunda linha: quantidade de elementos maiores que X
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 1000

struct No{
  int dado;
  No* prox;
};

struct Lista{
    No* cab;
    int tam;
};

void inicializar(Lista* l){
    l->cab = nullptr;
    l->tam = 0;
}

No* criar_no(int valor){
    No* novo = new No;
    
    if(novo == nullptr){
        cout << "Erro! Memoria insuficiente";
        exit(1);
    }
    
    novo->dado = valor;
    novo->prox = nullptr;
    return novo;
}

void adicionar(Lista* l, int valor){
    No* novo = criar_no(valor);
    
    if(l->cab == nullptr) {
        l->cab = novo;
    } else{
        No* atual = l->cab;
        
        while(atual->prox != nullptr)
            atual = atual->prox;
            
        atual->prox = novo;
    }
    l->tam++;
}

int somar(No* atual){
    if(atual == nullptr)
        return 0;
     
    return atual->dado + somar(atual->prox);
}

int cont_maior_x(No* atual, int x){
    if(atual == nullptr) 
        return 0;

    if(atual->dado > x) 
        return 1 + cont_maior_x(atual->prox, x);

    return cont_maior_x(atual->prox, x);
}

void exibir(Lista* l){
    if(l->cab == nullptr) return;

    No* atual = l->cab;
    while(atual != nullptr){
        cout << atual->dado << endl;
        atual = atual->prox;
    }
}

int main(){
    Lista* l = new Lista[MAX];
    inicializar(l);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int valor;
        cin >> valor;
        adicionar(l, valor);
    }

    cout << somar(l->cab) << endl;

    int x;
    cin >> x;

    cout << cont_maior_x(l->cab, x);
    
    delete[] l;
    return 0;
}