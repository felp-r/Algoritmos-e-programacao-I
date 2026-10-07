/*
 * Problema: Implementação de Heap Sort com Impressão de Build Heap
 * 
 * Implemente o algoritmo Heap Sort e, para cada array de entrada, imprima:
 * - O array após a construção do heap (build heap)
 * - O array ordenado final
 * 
 * Entrada:
 * - Primeira linha: T (número de casos de teste, 1 <= T <= 100)
 * - Para cada caso:
 *   - Primeira linha: N (tamanho do array, 1 <= N <= 1000)
 *   - Segunda linha: N inteiros
 * 
 * Saída:
 * - Para cada caso:
 *   - Linha 1: array após build heap (separado por espaço)
 *   - Linha 2: array ordenado (separado por espaço)
 *   - Linha 3: em branco
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 1000

struct Heap {
    int dados[MAX];
    int tam;
};

void inicializar(Heap* heap) {
    heap->tam = 0;
}

int pai(int i) {
    return (i - 1) / 2;
}

int filho_esq(int i) {
    return 2 * i + 1;
}

int filho_dir(int i) {
    return 2 * i + 2;
}

bool vazia(Heap* heap) {
    return heap->tam == 0;
}

// Ajusta para baixo mantendo a propriedade de Max-Heap
void heapify_down(Heap* heap, int idx) {
    int maior = idx;
    int esq = filho_esq(idx);
    int dir = filho_dir(idx);

    if (esq < heap->tam && heap->dados[esq] > heap->dados[maior]) {
        maior = esq;
    }

    if (dir < heap->tam && heap->dados[dir] > heap->dados[maior]) {
        maior = dir;
    }

    if (maior != idx) {
        int temp = heap->dados[idx];
        heap->dados[idx] = heap->dados[maior];
        heap->dados[maior] = temp;
        heapify_down(heap, maior);
    }
}

// Constrói o Max-Heap a partir do array desordenado
void construir_heap(Heap* heap) {
    for (int i = (heap->tam / 2) - 1; i >= 0; i--) {
        heapify_down(heap, i);
    }
}

void inserir(Heap* heap, int valor) {
    if (heap->tam >= MAX) 
        return;

    heap->dados[heap->tam] = valor;
    heap->tam++;
}

void exibir(Heap* heap, int tamanho_real) {
    for (int i = 0; i < tamanho_real; i++) {
        cout << heap->dados[i];
        if (i < tamanho_real - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int T, N;
    if (!(cin >> T)) return 0;

    for (int i = 0; i < T; i++) {
        cin >> N;

        Heap* heap = new Heap;
        inicializar(heap);

        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            inserir(heap, x);
        }

        // Linha 1: array após construir o Max-Heap
        construir_heap(heap);
        exibir(heap, heap->tam);

        // Linha 2: array ordenado (HeapSort ascendente)
        int tamanho_original = heap->tam;
        for (int j = N - 1; j > 0; j--) {
            int temp = heap->dados[0];
            heap->dados[0] = heap->dados[j];
            heap->dados[j] = temp;
            
            heap->tam--;
            heapify_down(heap, 0);
        }
        
        heap->tam = tamanho_original;
        exibir(heap, heap->tam);

        cout << endl;

        delete heap;
    }

    return 0;
}