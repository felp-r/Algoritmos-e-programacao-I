#include <iostream>
#include "lista_sequencial.h"

using namespace std;

void inicializar(ListaSequencial *lista){
    lista->tamanho = 0;
}

bool inserir(ListaSequencial *lista, int posicao, int valor){
    if(esta_cheia(lista)){
        cout << "Lista cheia. Impossível inserir novos elementos." << endl;
        return false;
    }

    if(posicao < 0 || posicao > lista->tamanho){
        cout << "Você está tentando inserir em uma posição inválida!" << endl;
        return false;
    }

    // Desloca os elementos para a direita
    for(int i = lista->tamanho; i > posicao; i--){
        lista->dados[i] = lista->dados[i-1];
    }

    lista->dados[posicao] = valor;
    lista->tamanho++;
    return true;
}

bool remover(ListaSequencial *lista, int posicao, int *valor_removido){
    if(lista->tamanho <= 0){
        cout << "Nada para remover. A lista está vazia." << endl;
        return false;
    }

    if(posicao < 0 || posicao > lista->tamanho){
        cout << "Você está tentando remover de uma posição inválida!" << endl;
        return false;
    }
        

    *valor_removido = lista->dados[posicao];
    
    for(int i = posicao; i < lista->tamanho; i++){
        lista->dados[i] = lista->dados[i+1];
    }

    lista->tamanho--;
    return true;
}

int buscar(ListaSequencial *lista, int valor){
    if(esta_vazia(lista)){
        cout << "Lista vazia." << endl;
        return -1;
    }

    for(int i = 0; i < lista->tamanho; i++){
        if(lista->dados[i] == valor)
            return i;  // Retorna a posição
    }

    return -1;
}

int tamanho(ListaSequencial *lista){
    return lista->tamanho;
}

bool esta_vazia(ListaSequencial *lista){
    if(lista->tamanho <= 0)
        return true;
    return false;
}

bool esta_cheia(ListaSequencial *lista){
    if(lista->tamanho >= MAX)
        return true;
    return false;
}

void exibir(ListaSequencial *lista){
    if(esta_vazia(lista)){
        cout << "Lista vazia. Nada para exibir." << endl << endl;
    } 
    else{
        cout << "Lista Sequencial: [";
        for(int i = 0; i < lista->tamanho; i++){
            if(i != lista->tamanho -1)
                cout << lista->dados[i] << ", ";
            else
                cout << lista->dados[i] << "]" << endl << endl; 
        }
    }
}

void inverter(ListaSequencial *lista){
    int inicio = 0;
    int fim = lista->tamanho -1;
    int aux;

    if(esta_vazia(lista)){
        cout << "Lista vazia. Nada para inverter." << endl << endl; 
    }
    else{
        while(inicio < fim){
            aux = lista->dados[inicio];
            lista->dados[inicio] = lista->dados[fim];
            lista->dados[fim] = aux;

            inicio++;
            fim--;
        }
        cout << "Lista invertida!" << endl << endl;
    }
}