/*
 * Exercício 4 — TAD Vetor 3D
 * 
 * Projete e implemente um TAD para vetores tridimensionais com operações da álgebra vetorial.
 * 
 * Especificação:
 * 
 * struct Vetor3D {
 *     double x, y, z;
 * };
 * 
 * Vetor3D criar_vetor(double x, double y, double z);
 * Vetor3D somar(Vetor3D v1, Vetor3D v2);
 * Vetor3D subtrair(Vetor3D v1, Vetor3D v2);
 * Vetor3D multiplicar_por_escalar(Vetor3D v, double k);
 * double produto_escalar(Vetor3D v1, Vetor3D v2);
 * Vetor3D produto_vetorial(Vetor3D v1, Vetor3D v2);
 * double norma(Vetor3D v);                      // Comprimento do vetor
 * Vetor3D normalizar(Vetor3D v);                 // Vetor unitário
 * bool sao_ortogonais(Vetor3D v1, Vetor3D v2);   // Produto escalar == 0
 * bool sao_paralelos(Vetor3D v1, Vetor3D v2);    // Produto vetorial == (0,0,0)
 * double angulo_entre(Vetor3D v1, Vetor3D v2);   // Em graus
 * void imprimir(Vetor3D v);                     // Formato: (x, y, z)
 * 
 * Programa de teste:
 * Crie vetores a = (1,0,0), b = (0,1,0), c = (1,2,3) e verifique:
 * • a e b são ortogonais?
 *   R: Sim
 * 
 * • a x b = (0,0,1)?
 *   R: Sim, o produto vetorial de a x b é (0, 0, 1)
 * 
 * • Ângulo entre a e c = 735.272 graus
 * 
 * • Norma de c e sua versão normalizada
 *   R: Norma de c = 3.74166; versão normalizada de c = (0.267261, 0.534522, 0.801784)
 * 
 * Dica:
 * Produto vetorial: (ax, ay, az) x (bx, by, bz) = (ay*bz - az*by, az*bx - ax*bz, ax*by - ay*bx)
 * Use const double PI = 3.14159265358979323846; para conversão radianos <-> graus.
 */

#include <iostream>
#include "vetor.h"
using namespace std;

int main() {
    // 1. Criação e Impressão
    Vetor3D a = criar_vetor(1, 0, 0);
    Vetor3D b = criar_vetor(0, 1, 0);
    Vetor3D c = criar_vetor(1, 2, 3);
    Vetor3D d = criar_vetor(2, 4, 6); // Paralelo a c
    Vetor3D v_nulo = criar_vetor(0, 0, 0);

    cout << "--- Vetores ---" << endl;
    cout << "a = "; imprimir(a); cout << endl;
    cout << "b = "; imprimir(b); cout << endl;
    cout << "c = "; imprimir(c); cout << endl;
    cout << "d = "; imprimir(d); cout << endl;
    cout << "v_nulo = "; imprimir(v_nulo); cout << endl << endl;

    // 2. Operações Básicas
    cout << "--- Operações Básicas ---" << endl;
    cout << "a + b = "; imprimir(somar(a, b)); cout << endl;
    cout << "a - b = "; imprimir(subtrair(a, b)); cout << endl;
    cout << "c * 2 = "; imprimir(multiplicar_por_escalar(c, 2)); cout << endl << endl;

    // 3. Produtos Vetoriais e Escalares
    cout << "--- Produtos ---" << endl;
    cout << "a . b (Produto Escalar) = " << produto_escalar(a, b) << endl;
    cout << "c . d (Produto Escalar) = " << produto_escalar(c, d) << endl;
    cout << "a x b (Produto Vetorial) = "; imprimir(produto_vetorial(a, b)); cout << endl;
    cout << "c x d (Produto Vetorial) = "; imprimir(produto_vetorial(c, d)); cout << endl << endl;

    // 4. Norma, Normalização e Ângulo
    cout << "--- Norma, Normalização e Ângulo ---" << endl;
    cout << "||c|| (Norma) = " << norma(c) << endl;
    cout << "Normalizar(c) = "; imprimir(normalizar(c)); cout << endl;
    cout << "Ângulo entre a e b = " << angulo_entre(a, b) << " graus" << endl;
    cout << "Ângulo entre a e c = " << angulo_entre(a, c) << " graus" << endl << endl;

    // 5. Testes de Relação Espacial (Ortogonalidade e Paralelismo)
    cout << "--- Relações Espaciais ---" << endl;
    cout << "a e b são ortogonais? " << (sao_ortogonais(a, b) ? "Sim" : "Não") << endl;
    cout << "c e d são ortogonais? " << (sao_ortogonais(c, d) ? "Sim" : "Não") << endl;
    cout << "c e d são paralelos? " << (sao_paralelos(c, d) ? "Sim" : "Não") << endl;
    cout << "a e b são paralelos? " << (sao_paralelos(a, b) ? "Sim" : "Não") << endl;

    return 0;
}