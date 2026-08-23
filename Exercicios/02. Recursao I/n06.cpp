/*
 * Exercício 10 — Desafio: Número de Passos para Reduzir a Zero
 * 
 * Dado um número inteiro não-negativo num, retorne o número de passos para reduzi-lo a zero seguindo
 * as regras:
 * • Se o número for par, divida por 2
 * • Se o número for ímpar, subtraia 1
 * 
 * Implemente de forma recursiva:
 * int passos_para_zero(int num);
 * 
 * Exemplo passo a passo para num = 14:
 * 14 é par   -> 7 (1 passo)
 * 7 é ímpar  -> 6 (2 passos)
 * 6 é par    -> 3 (3 passos)
 * 3 é ímpar  -> 2 (4 passos)
 * 2 é par    -> 1 (5 passos)
 * 1 é ímpar  -> 0 (6 passos)
 * Total: 6 passos
 * 
 * Exemplos adicionais:
 * • passos_para_zero(8) = 4
 * • passos_para_zero(123) = 12
 * 
 * Desafio Extra:
 * Você consegue pensar em uma solução usando operadores bitwise que resolve em O(1)
 * (tempo constante)?
 * 
 * Dica:
 * O número de passos está relacionado com a posição do bit 1 mais significativo e a
 * quantidade total de bits 1.
 */

#include <iostream>
using namespace std;

int passos_para_zero(int num){
    if(num == 0) return 0;

    if(num % 2 == 0) num /= 2;
    else num -= 1;

    return 1 + passos_para_zero(num);
}

int pas_p_zero_bitwise(int num){
    if(num == 0) return 0;

    if((num & 1) == 0){
        return 1 + pas_p_zero_bitwise(num >> 1);
    } else{
        return 1 + pas_p_zero_bitwise(num -1);
    }

}

int main(){
    int n;
    cout << "Digite um número: ";
    cin >> n;

    cout << "O total de passos para o número " << n << " chegar a zero é " << passos_para_zero(n) << endl;
    cout << "O total de passos para o número " << n << " chegar a zero é " << pas_p_zero_bitwise(n) << endl;

    return 0;
}