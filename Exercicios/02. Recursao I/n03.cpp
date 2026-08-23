/*
 * Exercício 7 — Potência Recursiva Otimizada
 * 
 * a) Implemente a versão ingênua (complexidade O(n)):
 *    int potencia_ingenua(int base, int expoente);
 *    // Exemplo: potencia_ingenua(2, 5) = 2 * 2 * 2 * 2 * 2 = 32
 * 
 * b) Implemente a versão otimizada (exponenciação rápida) usando a propriedade matemática:
 *    
 *           / 1                  se n = 0
 *    x^n = <  (x^2)^(n/2)        se n é par
 *           \ x * (x^2)^((n-1)/2) se n é ímpar
 * 
 *    long long potencia_rapida(long long base, int expoente);
 *    // Exemplo: potencia_rapida(2, 10) = 1024
 *    // Complexidade: O(log n)
 * 
 * c) Teste ambas as funções para expoentes grandes (ex: 2^30, 2^50) e compare o número de chamadas
 *    recursivas. Use um contador global para medir.
 * 
 * Desafio Extra:
 * Implemente uma versão que funciona com expoentes negativos, retornando double.
 */

#include <iostream>
using namespace std;

// contador global para medir o número de chamadas das funções
long long cont_p_ing = 0;
long long cont_p_rap = 0;

int potencia_ingenua(int base, int expoente){
    cont_p_ing += 1;

    if(base == 0) return 0;
    if(expoente == 0) return 1;

    return base * potencia_ingenua(base, expoente-1);
}

long long potencia_rapida(long long base, int expoente) {
    cont_p_rap += 1;

    if(base == 0) return 0;
    if (expoente == 0) return 1;

    long long metade = potencia_rapida(base, expoente / 2);

    if (expoente % 2 == 0) return metade * metade;
    else return base * metade * metade;
}

double potencia_negativa(int base, int expoente){
    if(base == 0){
        cerr << "Erro: Divisão por zero!" << endl;
        return 0;
    }
    if(expoente == 0) return 1.0;

    if (expoente < 0) {
        return 1.0 / potencia_negativa(base, -expoente);
    }

    return base * potencia_negativa(base, expoente - 1);
}

int main(){
    int b, e;

    // valores de entrada
    cout << "Entre com o valor da base: ";
    cin >> b;
    cout << "Entre com o valor do expoente: ";
    cin >> e;

    // resultado das funções
    if(e >= 0){
        cout << "Potência ingênua: " << potencia_ingenua(b, e) << endl;
        cout << "Potência rápida: " << potencia_rapida(b, e) << endl;
    } else {
        cout << "Potência negativa: " << potencia_negativa(b, e) << endl;
    }

    // quantidade de interações
    cout << "Número de chamados da função potencia_ingenua: " << cont_p_ing << endl;
    cout << "Número de chamados da função potencia_rapida: " << cont_p_rap << endl;

    return 0;
}