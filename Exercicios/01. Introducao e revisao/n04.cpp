/*
 * Exercício 4 — Redimensionamento com Critérios
 * 
 * Implemente uma função que "limpa" um array de inteiros removendo todos os elementos negativos.
 * A função deve:
 * • Contar quantos elementos não-negativos existem
 * • Alocar um novo array com o tamanho exato (apenas não-negativos)
 * • Copiar apenas os elementos não-negativos, mantendo a ordem original
 * • Liberar a memória do array original
 * • Retornar o novo array e atualizar o tamanho via ponteiro
 * 
 * int* remover_negativos(int* arr, int* tam);
 * 
 * Exemplo:
 * int tam = 6;
 * int* arr = new int[tam]{5, -3, 8, -1, 0, 7};
 * arr = remover_negativos(arr, &tam);
 * // arr agora = [5, 8, 0, 7], tam = 4
 * delete[] arr;
 * 
 * Dica:
 * O número zero não é negativo, portanto deve ser mantido no array.
 */

#include <iostream>

using namespace std;

int* remover_negativos(int* arr, int* tam){
    int new_tam = 0;
    int idx = 0;

    for(int i = 0; i < *tam; i++){
        if(*(arr +i) >= 0)
            new_tam++;
    }

    int* new_arr = new int[new_tam]();

    for(int i = 0; i < *tam; i++){
        if(*(arr +i) >= 0){
            *(new_arr +idx) = *(arr +i);
            idx++;
        }
    }

    *tam = new_tam;

    return new_arr;
}

int main(){
    int tam = 6;
    int* arr = new int[tam]{5, -3, 8, -1, 0, 7};
    arr = remover_negativos(arr, &tam);
    // arr agora = [5, 8, 0, 7], tam = 4

    cout << "arr agora = [";
    for(int i = 0; i < tam; i++){
        if(i == 0) 
            cout << *(arr +i) << ", ";
        else if(i == tam -1) 
            cout << *(arr +i);
        else 
            cout << *(arr +i) << ", ";
    }
    cout << "], ";

    cout << "tam = " << tam << endl;

    delete[] arr;

    return 0;
}