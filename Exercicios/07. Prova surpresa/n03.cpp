/*
 * Problema: K-ésimo Maior Elemento
 * 
 * Dado um array de N inteiros e um número K, determine o K-ésimo maior elemento do array (não necessariamente distinto).
 * 
 * Entrada:
 * - Primeira linha: N e K (1 <= K <= N <= 100000)
 * - Segunda linha: N inteiros (-10^9 <= ai <= 10^9)
 * 
 * Saída:
 * - O K-ésimo maior elemento
 */

#include <iostream>

using namespace std;

// Decrescente
void bubble_sort(int* arr, int tam){
    if(tam <= 1) return;

    int aux;
    bool trocou;

    for(int i = 0; i < tam - 1; i++){
        trocou = false;
        
        for(int j = 0; j < tam - i - 1; j++){
            if(*(arr + j) < *(arr + j + 1)){
                // Troca os vizinhos de lugar
                aux = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = aux;
                
                trocou = true;
            }
        }
        
        if(!trocou) break;
    }
}

int main(){
    int n, K;
    cin >> n;
    cin >> K;

    int* arr = new int[n];

    // povoando array
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;

        *(arr+i) = x;
    }

    bubble_sort(arr, n);

    // K-ésimo maior número
    cout << *(arr +K -1);

    delete[] arr;
    return 0;
}