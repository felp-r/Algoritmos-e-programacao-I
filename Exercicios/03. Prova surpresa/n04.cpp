/*
 * Você receberá uma sequência de N números inteiros, um por vez. Após cada número, 
 * determine a mediana dos números lidos até o momento.
 * 
 * A mediana é:
 * - Se a quantidade de elementos é ímpar: o elemento central
 * - Se a quantidade é par: a média dos dois elementos centrais
 * 
 * Entrada:
 * - Primeira linha: N (1 <= N <= 100000)
 * - Próximas N linhas: um inteiro por linha
 * 
 * Saída:
 * - N linhas, cada uma com a mediana atual
 * - Se a mediana for inteira, imprima sem casas decimais
 * - Se for fracionária, imprima com exatamente 1 casa decimal
 * 
 * Dica: Use dois heaps (max-heap e min-heap) para O(log n) por inserção.
 */

#include <iostream>

using namespace std;

const int MAXN = 100005;
int max_heap[MAXN], sz_max = 0;
int min_heap[MAXN], sz_min = 0;

void push_max(int val) {
    int i = sz_max++;
    max_heap[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (max_heap[p] < max_heap[i]) {
            int temp = max_heap[p];
            max_heap[p] = max_heap[i];
            max_heap[i] = temp;
            i = p;
        } else {
            break;
        }
    }
}

void pop_max() {
    max_heap[0] = max_heap[--sz_max];
    int i = 0;
    while (2 * i + 1 < sz_max) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (max_heap[left] > max_heap[largest]) largest = left;
        if (right < sz_max && max_heap[right] > max_heap[largest]) largest = right;
        if (largest != i) {
            int temp = max_heap[i];
            max_heap[i] = max_heap[largest];
            max_heap[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void push_min(int val) {
    int i = sz_min++;
    min_heap[i] = val;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (min_heap[p] > min_heap[i]) {
            int temp = min_heap[p];
            min_heap[p] = min_heap[i];
            min_heap[i] = temp;
            i = p;
        } else {
            break;
        }
    }
}

void pop_min() {
    min_heap[0] = min_heap[--sz_min];
    int i = 0;
    while (2 * i + 1 < sz_min) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (min_heap[left] < min_heap[smallest]) smallest = left;
        if (right < sz_min && min_heap[right] < min_heap[smallest]) smallest = right;
        if (smallest != i) {
            int temp = min_heap[i];
            min_heap[i] = min_heap[smallest];
            min_heap[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (sz_max == 0 || x <= max_heap[0]) {
            push_max(x);
        } else {
            push_min(x);
        }

        if (sz_max > sz_min + 1) {
            push_min(max_heap[0]);
            pop_max();
        } else if (sz_min > sz_max) {
            push_max(min_heap[0]);
            pop_min();
        }

        if (sz_max > sz_min) {
            cout << max_heap[0] << "\n";
        } else {
            long long soma = (long long)max_heap[0] + min_heap[0];
            if (soma % 2 == 0) {
                cout << soma / 2 << "\n";
            } else {
                cout << soma / 2 << ".5\n";
            }
        }
    }

    return 0;
}