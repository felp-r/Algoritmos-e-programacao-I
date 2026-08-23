/*
 * Exercício 6 — Soma e Produto Recursivos
 * 
 * Implemente funções recursivas que, dado um array de inteiros e seu tamanho, calculam:
 * 
 * a) A soma de todos os elementos do array.
 *    int soma_array(int arr[], int n);
 *    // Exemplo: soma_array([1, 2, 3, 4, 5], 5) = 15
 * 
 * b) O produto de todos os elementos do array.
 *    long long produto_array(int arr[], int n);
 *    // Exemplo: produto_array([1, 2, 3, 4, 5], 5) = 120
 * 
 * Desafio Extra:
 * Implemente uma versão alternativa que funciona com long long para evitar overflow em arrays
 * grandes, e que retorna 0 se algum elemento for zero (otimização).
 * 
 * Dica:
 * Use a técnica de considerar arr[0] como elemento atual e arr+1 como o restante do array
 * (passando n-1).
 */

#include <iostream>
using namespace std;

int soma_array(int arr[], int n){
    if(n <= 0) return 0;

    return arr[n -1] + soma_array(arr, n -1);
}

long long produto_array(int arr[], int n){
    long long produto = 1;

    if(n <= 0) return 1;

    if(arr[n -1] == 0) return 0;

    return arr[n -1] * produto_array(arr, n -1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 2};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    int soma = soma_array(arr, arr_length);
    cout << "A soma é: " << soma << endl;

    int produto = produto_array(arr, arr_length);
    cout << "O produto é: " << produto << endl;

    return 0;
}