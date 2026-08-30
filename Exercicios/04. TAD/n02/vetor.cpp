#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "vetor.h"

using namespace std;

const double PI = 3.14159265358979323846;

Vetor3D criar_vetor(double x, double y, double z){
    Vetor3D v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vetor3D somar(Vetor3D v1, Vetor3D v2){
    Vetor3D v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    return v;
}

Vetor3D subtrair(Vetor3D v1, Vetor3D v2){
    Vetor3D v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;
    return v;
}

Vetor3D multiplicar_por_escalar(Vetor3D v, double k){
    v.x *= k;
    v.y *= k;
    v.z *= k;
    return v;
}

double produto_escalar(Vetor3D v1, Vetor3D v2){
    double soma = 0.0;
    soma += (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
    return soma;
}

Vetor3D produto_vetorial(Vetor3D v1, Vetor3D v2){
    Vetor3D v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return v;
}

// Comprimento do vetor
double norma(Vetor3D v){
    double comp = v.x * v.x + v.y * v.y + v.z * v.z;
    return sqrt(comp);
}

// Vetor unitário
Vetor3D normalizar(Vetor3D v){
    double comp = norma(v);

    if(comp == 0)
        throw runtime_error("Erro: divisao por zero");
        
    v.x /= comp;
    v.y /= comp;
    v.z /= comp;
    return v;
}

// Produto escalar == 0
bool sao_ortogonais(Vetor3D v1, Vetor3D v2){
    if(produto_escalar(v1, v2) == 0) 
        return true;
    return false;
}

// Produto vetorial == (0,0,0)
bool sao_paralelos(Vetor3D v1, Vetor3D v2){
    Vetor3D v = produto_vetorial(v1, v2);
    if(v.x == 0 && v.y == 0 && v.z == 0)
        return true;
    return false;
}

// Em graus
double angulo_entre(Vetor3D v1, Vetor3D v2){
    double norma_v = norma(v1) *norma(v2);

    if(norma_v == 0)
        throw runtime_error("Erro: divisao por zero");

    double prod_esc = produto_escalar(v1, v2);

    return acos(prod_esc / norma_v) * (180.0 * PI);
}

// Formato: (x, y, z)
void imprimir(Vetor3D v){
    cout << "(" << v.x;
    cout << ", " << v.y;
    cout << ", " << v.z << ")";
}                     