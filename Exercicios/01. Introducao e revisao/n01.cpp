/*
 * Exercício 1 — Manipulação de Arrays Dinâmicos
 * 
 * Implemente uma função que recebe um array dinâmico de inteiros, seu tamanho atual, e um valor a
 * ser inserido no início do array. A função deve:
 * • Criar um novo array com tamanho tam + 1
 * • Inserir o novo valor na primeira posição
 * • Copiar os elementos existentes deslocando-os uma posição à direita
 * • Liberar a memória do array antigo
 * • Retornar o ponteiro para o novo array
 * 
 * int* inserir_inicio(int* arr, int tam, int valor);
 * 
 * Exemplo de uso:
 * int tam = 0;
 * int* arr = nullptr;
 * arr = inserir_inicio(arr, tam++, 10); // arr = [10]
 * arr = inserir_inicio(arr, tam++, 20); // arr = [20, 10]
 * arr = inserir_inicio(arr, tam++, 30); // arr = [30, 20, 10]
 * // Não esqueça de liberar a memória ao final!
 * delete[] arr;
 * 
 * Dica:
 * Não esqueça de tratar o caso do array vazio (nullptr) e de usar delete[] apenas no array
 * antigo, não no novo.
 */


#include <iostream>

using namespace std;

void imprimir(int* new_arr, int tam){
    cout << " arr = [";
    for(int i = 0; i < tam; i++){
        if(i == tam-1) cout << new_arr[i];
        else cout << new_arr[i] << ", ";
    }
    cout << "]" << endl;
}

int* inserir_inicio(int* arr, int tam, int valor){
    int* new_arr = new int[tam+1]();

    new_arr[0] = valor;

    for(int i = 0; i < tam; i++){
        new_arr[i+1] = arr[i];
    }

    delete[] arr;

    return new_arr;
}

int main(){
    int tam = 0;
    int* arr = nullptr;
    arr = inserir_inicio(arr, tam++, 10); 
    imprimir(arr, tam);  // arr = [10]
    arr = inserir_inicio(arr, tam++, 20); 
    imprimir(arr, tam);  // arr = [20, 10]
    arr = inserir_inicio(arr, tam++, 30); 
    imprimir(arr, tam);  // arr = [30, 20, 10]

    cout << endl;

    delete[] arr;
    return 0;
}