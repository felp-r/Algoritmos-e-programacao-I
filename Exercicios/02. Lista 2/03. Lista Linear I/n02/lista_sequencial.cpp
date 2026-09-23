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

ListaSequencial concatenar(ListaSequencial *l1, ListaSequencial *l2){
    ListaSequencial *l3 = new ListaSequencial();
    inicializar(l3);

    if(!esta_vazia(l1)){
        for (int i = 0; i < l1->tamanho; i++) {
            inserir(l3, l3->tamanho, l1->dados[i]);
        }
    }

    if(!esta_vazia(l2)) {
        for (int i = 0; i < l2->tamanho; i++) {
            inserir(l3, l3->tamanho, l2->dados[i]);
        }
    }

    return *l3;
}

ListaSequencial intercalar_ordenado(ListaSequencial *l1, ListaSequencial *l2){
    ListaSequencial *l3 = new ListaSequencial();
    inicializar(l3);

    int i = 0;
    int j = 0;

    while (i < l1->tamanho && j < l2->tamanho) {
        if (l3->tamanho >= MAX) break;

        if (l1->dados[i] <= l2->dados[j]) {
            l3->dados[l3->tamanho++] = l1->dados[i++];
        } else {
            l3->dados[l3->tamanho++] = l2->dados[j++];
        }
    }

    // Se ainda restarem elementos em l1, copia o restante
    while (i < l1->tamanho && l3->tamanho < MAX) {
        l3->dados[l3->tamanho++] = l1->dados[i++];
    }

    // Se ainda restarem elementos em l2, copia o restante
    while (j < l2->tamanho && l3->tamanho < MAX) {
        l3->dados[l3->tamanho++] = l2->dados[j++];
    }

    return *l3;
}

void remover_duplicatas(ListaSequencial *lista){
    if(esta_vazia(lista)){
        cout << "Lista vazia. Nada para remover." << endl;
    } else{
        for(int i = 0; i < lista->tamanho; i++){
            // Percorre a lista em busca de uma duplicada
            for(int j = i +1; j < lista->tamanho;){
                if(lista->dados[i] == lista->dados[j]){
                    remover(lista, j, &lista->dados[j]);
                } else{
                    j++;
                }
            }
        }
    }
}

void rotacionar_direita(ListaSequencial *lista){
    if(esta_vazia(lista)){
        cout << "Lista vazia." << endl;
    } else{
        int aux = lista->dados[lista->tamanho -1];
        // Desloca os elementos para a direita
        for(int i = lista->tamanho; i > 0; i--){
            lista->dados[i] = lista->dados[i-1];
        }
        lista->dados[0] = aux;
    }

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