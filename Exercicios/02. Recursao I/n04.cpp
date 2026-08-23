/*
 * Exercício 8 — Fibonacci com Análise Empírica de Complexidade
 * 
 * a) Implemente a versão recursiva ingênua de Fibonacci:
 *    int fibonacci(int n);
 *    // F(0) = 0, F(1) = 1
 *    // F(n) = F(n-1) + F(n-2) para n > 1
 * 
 * b) Modifique a função para contar quantas vezes ela é chamada durante a execução. Use uma
 *    variável global ou um parâmetro por referência:
 *    
 *    long long contador_chamadas = 0;
 *    
 *    int fibonacci_contador(int n) {
 *        contador_chamadas++;
 *        // ... resto do código
 *    }
 * 
 * c) Execute para n = 5, 10, 15, 20, 25, 30 e preencha a tabela abaixo:
 * 
 *    +----+--------------+----------------+-----------+
 *    | n  | Fibonacci(n) | Nº de Chamadas | Tempo(ms) |
 *    +----+--------------+----------------+-----------+
 *    |  5 |     5        |      15        |     0     |
 *    | 10 |     55       |      177       |     0     |
 *    | 15 |     610      |      1.973     |     0     |
 *    | 20 |     6.765    |      21.891    |     0     |
 *    | 25 |     75.025   |      242.785   |     1     |
 *    | 30 |     832.040  |      2.692.537 |     5     |
 *    +----+--------------+----------------+-----------+
 * 
 *    Use a biblioteca <chrono> para medir o tempo de execução:
 *    
 *    #include <chrono>
 *    using namespace std::chrono;
 *    
 *    auto inicio = high_resolution_clock::now();
 *    int resultado = fibonacci_contador(n);
 *    auto fim = high_resolution_clock::now();
 *    auto duracao = duration_cast<milliseconds>(fim - inicio);
 * 
 * d) Pergunta para relatório: Por que o número de chamadas cresce tão rapidamente? Qual a relação
 *    com a complexidade O(2^n)? Em que momento a versão recursiva ingênua se torna inviável na prática?
 * 
 * Resposta: O número de chamadas cresce tão rapidamente porquê a cada chamada da função, outras 2 chamadas são feitas,
 * e isso faz com que o número de interações cresça de forma exponencial. No n = 30, já temos quase 2.7 mlhões de interações,
 * então para n maiores, esse número cresceria muito, tornando o processo bem lento. Provavelmente a partir n = 40 o processo já
 * se tornaria inviável. 
 * 
 * Dica:
 * O número de chamadas para calcular F(n) é aproximadamente 2 * F(n+1) - 1.
 */

#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

long long cont_chamadas = 0;

int fibonacci(int n){
    cont_chamadas += 1;

    if(n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cout << "Entre com um valor: ";
    cin >> n;

    auto inicio = high_resolution_clock::now();
    int resultado = fibonacci(n);
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<milliseconds>(fim - inicio);

    cout << "O resultado de F(" << n << ") " << "é: " << resultado << endl;
    cout << "Quantidade de vezes que a função de Fibonacci foi chamada: " << cont_chamadas << endl;
    cout << "Tempo: " << duracao.count() << " ms" << endl;

    return 0;
}