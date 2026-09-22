/*
 * N pessoas estão dispostas em um círculo, numeradas de 1 a N. Começando pela pessoa 1, 
 * conta-se até K e a K-ésima pessoa é eliminada. O processo continua com a próxima pessoa, 
 * até que reste apenas uma.
 * 
 * Determine o número da pessoa sobrevivente.
 * 
 * Entrada:
 * - Primeira linha: T (número de casos de teste, 1 <= T <= 100)
 * - Próximas T linhas: N e K (1 <= N <= 100000, 1 <= K <= 100000)
 * 
 * Saída:
 * - Para cada caso, o número do sobrevivente
 */

#include <iostream>

using namespace std;

int sobrevivente(int n, int k) {
    int sobr = 0;
    for (int i = 2; i <= n; i++) {
        sobr = (sobr + k) % i;
    }
    return sobr + 1;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            int N, K;
            cin >> N >> K;
            cout << sobrevivente(N, K) << "\n";
        }
    }

    return 0;
}