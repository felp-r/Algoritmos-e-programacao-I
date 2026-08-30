/*
 * Exercício 3 — TAD Número Complexo
 * 
 * Projete e implemente um TAD para números complexos. O TAD deve ser dividido em interface e
 * implementação.
 * 
 * Especificação:
 * 
 * struct Complexo {
 *     double real;
 *     double imag;
 * };
 * 
 * // Operações
 * Complexo criar_complexo(double real, double imag);
 * Complexo somar(Complexo a, Complexo b);
 * Complexo subtrair(Complexo a, Complexo b);
 * Complexo multiplicar(Complexo a, Complexo b);
 * Complexo dividir(Complexo a, Complexo b); // Tratar divisão por zero!
 * Complexo conjugado(Complexo z);
 * double modulo(Complexo z);                // sqrt(real^2 + imag^2)
 * double argumento(Complexo z);             // atan2(imag, real) em radianos
 * void imprimir(Complexo z);                // Formato: "a + bi" ou "a - bi"
 * 
 * Requisitos:
 * • O programa de teste (main.cpp) não deve acessar os campos real e imag diretamente
 * • A função imprimir deve tratar corretamente os sinais (ex: 3 - 2i, não 3 + -2i)
 * • A função dividir deve tratar divisão por zero com mensagem de erro apropriada
 * 
 * Programa de teste sugerido:
 * 
 * int main() {
 *     Complexo z1 = criar_complexo(3, 4);
 *     Complexo z2 = criar_complexo(1, -2);
 *     
 *     cout << "z1 = "; imprimir(z1); cout << endl;
 *     cout << "z2 = "; imprimir(z2); cout << endl;
 *     cout << "|z1| = " << modulo(z1) << endl;
 *     cout << "z1 + z2 = "; imprimir(somar(z1, z2)); cout << endl;
 *     cout << "z1 * z2 = "; imprimir(multiplicar(z1, z2)); cout << endl;
 *     
 *     return 0;
 * }
 * 
 * Dica:
 * Use <cmath> para sqrt, atan2, abs. Lembre-se: i^2 = -1
 */

#include <iostream>
#include "complexo.h"
using namespace std;

int main() {
    // 1. Criação e Impressão
    Complexo z1 = criar_complexo(3, 4);
    Complexo z2 = criar_complexo(1, -2);
    Complexo z_zero = criar_complexo(0, 0);

    cout << "--- Números Complexos ---" << endl;
    cout << "z1 = "; imprimir(z1); cout << endl;
    cout << "z2 = "; imprimir(z2); cout << endl;
    cout << "z_zero = "; imprimir(z_zero); cout << endl << endl;

    // 2. Operações Aritméticas Básicas
    cout << "--- Operações Básicas ---" << endl;
    cout << "z1 + z2 = "; imprimir(somar(z1, z2)); cout << endl;
    cout << "z1 - z2 = "; imprimir(subtrair(z1, z2)); cout << endl;
    cout << "z1 * z2 = "; imprimir(multiplicar(z1, z2)); cout << endl;
    cout << "z1 / z2 = "; imprimir(dividir(z1, z2)); cout << endl << endl;

    // 3. Propriedades (Conjugado, Módulo e Argumento)
    cout << "--- Propriedades ---" << endl;
    cout << "Conjugado de z1 = "; imprimir(conjugado(z1)); cout << endl;
    cout << "Conjugado de z2 = "; imprimir(conjugado(z2)); cout << endl;
    cout << "|z1| (Módulo) = " << modulo(z1) << endl;
    cout << "Arg(z1) (Argumento em radianos) = " << argumento(z1) << " rad" << endl;

    // 4. Teste de Divisão por Zero
    cout << "--- Teste de Divisão por Zero ---" << endl;
    cout << "z1 / z_zero = "; imprimir(dividir(z1, z_zero)); cout << endl << endl;

    return 0;
}