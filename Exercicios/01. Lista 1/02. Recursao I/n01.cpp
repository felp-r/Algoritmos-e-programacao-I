/*
 * Exercício 5 — Recursão Simples: Contagem
 * 
 * Implemente de forma recursiva (sem usar laços for, while ou goto):
 * 
 * a) Uma função que imprime todos os números de 1 até n em ordem crescente.
 *    void imprimir_crescente(int n);
 *    // Exemplo: imprimir_crescente(5) imprime: 1 2 3 4 5
 * 
 * b) Uma função que imprime todos os números de n até 1 em ordem decrescente.
 *    void imprimir_decrescente(int n);
 *    // Exemplo: imprimir_decrescente(5) imprime: 5 4 3 2 1
 * 
 * Dica:
 * Pergunta para reflexão: O que acontece se você inverter a ordem da impressão e da chamada
 * recursiva em cada função? Desenhe a pilha de chamadas para n = 3 em ambos os casos e explique
 * por que a ordem de impressão muda.
 * A posição do cout em relação à chamada recursiva determina se a impressão ocorre na "ida"
 * ou na "volta" da recursão.
 */

#include <iostream>
using namespace std;

void imprimir_crescente(int n){
    if(n == 0) return;

    imprimir_crescente(n-1);
    cout << n << " ";
}

void imprimir_decrescente(int n){
    if(n == 0) return;

    cout << n << " ";
    imprimir_decrescente(n-1);
}

int main(){
    int num;
    cout << "Digite um número: ";
    cin >> num;
    cout << endl;

    cout << "Ordem crescente:   ";
    imprimir_crescente(num);

    cout << endl;
    
    cout << "Ordem decrescente: ";
    imprimir_decrescente(num);

    cout << endl;

    return 0;
}