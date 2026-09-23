#ifndef COMPLEXO_H
#define COMPLEXO_H

struct Complexo {
    double real;
    double imag;
};

// Operações
Complexo criar_complexo(double real, double imag);
Complexo somar(Complexo a, Complexo b);
Complexo subtrair(Complexo a, Complexo b);
Complexo multiplicar(Complexo a, Complexo b);
Complexo dividir(Complexo a, Complexo b); // Tratar divisão por zero!
Complexo conjugado(Complexo z);
double modulo(Complexo z);                // sqrt(real^2 + imag^2)
double argumento(Complexo z);             // atan2(imag, real) em radianos
void imprimir(Complexo z);                // Formato: "a + bi" ou "a - bi"

#endif 