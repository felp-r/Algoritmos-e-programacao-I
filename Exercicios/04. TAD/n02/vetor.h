#ifndef VETOR_H
#define VETOR_H

struct Vetor3D {
    double x, y, z;
};

Vetor3D criar_vetor(double x, double y, double z);
Vetor3D somar(Vetor3D v1, Vetor3D v2);
Vetor3D subtrair(Vetor3D v1, Vetor3D v2);
Vetor3D multiplicar_por_escalar(Vetor3D v, double k);
double produto_escalar(Vetor3D v1, Vetor3D v2);
Vetor3D produto_vetorial(Vetor3D v1, Vetor3D v2);
double norma(Vetor3D v);                      // Comprimento do vetor
Vetor3D normalizar(Vetor3D v);                 // Vetor unitário
bool sao_ortogonais(Vetor3D v1, Vetor3D v2);   // Produto escalar == 0
bool sao_paralelos(Vetor3D v1, Vetor3D v2);    // Produto vetorial == (0,0,0)
double angulo_entre(Vetor3D v1, Vetor3D v2);   // Em graus
void imprimir(Vetor3D v);                     // Formato: (x, y, z)

#endif