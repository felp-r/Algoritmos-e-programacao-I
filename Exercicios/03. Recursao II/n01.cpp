/*
 * Exercício 1 — Busca Binária Recursiva com Rastreamento
 * 
 * a) Implemente a busca binária recursiva conforme visto em aula:
 *    int busca_binaria(int arr[], int esq, int dir, int x);
 *    // Retorna o índice do elemento x, ou -1 se não encontrado
 *    // Pré-condição: array ordenado de forma crescente
 * 
 * b) Modifique a função para que ela imprima o subarray sendo analisado a cada chamada recursiva,
 *    permitindo visualizar a redução do espaço de busca. Exemplo de saída:
 *    
 *    Buscando 7 no intervalo [0, 9]: [1 3 5 7 9 11 13 15 17 19]
 *    Buscando 7 no intervalo [0, 4]: [1 3 5 7 9]
 *    Buscando 7 no intervalo [3, 4]: [7 9]
 *    Encontrado na posicao 3!
 * 
 * c) Crie uma versão que conta o número de comparações realizadas e compare com o valor teórico
 *    floor(log2(n)) + 1.
 * 
 * Dica:
 * Use std::setw ou manipulação de string para indentar corretamente as chamadas recursivas.
 */


#include <iostream>
#include <cmath>
using namespace std;

void imprimir_subintervalo(int arr[], int esq, int dir, int x){
    if(esq != dir){
        cout << "Buscando " << x << " no intervalo [" << esq << ", " << dir << "]: [";

        for(int i = esq; i < dir; i++) cout << arr[i] << ", ";

        cout << arr[dir] << "]" << endl;
    }
}

int busca_binaria(int arr[], int esq, int dir, int x){
    if(esq > dir) return -1;

    imprimir_subintervalo(arr, esq, dir, x);

    int meio = esq + (dir - esq) / 2;

    if (arr[meio] == x) return meio;

    if(arr[meio] < x){
        return busca_binaria(arr, meio + 1, dir, x);
    }
    else{
        return busca_binaria(arr, esq, meio - 1, x);
    }
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int n;
    cin >> n;

    int idx = busca_binaria(arr, 0, 9, n);

    if(idx != -1) {
        cout << "Encontrado na posição " << idx << endl;
    } else {
        cout << "Não encontrado" << endl;
    }

    return 0;
}