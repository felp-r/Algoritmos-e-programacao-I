#include <iostream>
#include <cmath>
#include <stdexcept>
#include "complexo.h"
using namespace std;

// Operações
Complexo criar_complexo(double real, double imag){
    Complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

Complexo somar(Complexo a, Complexo b){
    Complexo c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complexo subtrair(Complexo a, Complexo b){
    Complexo c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

Complexo multiplicar(Complexo a, Complexo b){
    Complexo c;
    c.real = a.real * b.real + (a.imag * b.imag) * -1;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

// Tratar divisão por zero!
Complexo dividir(Complexo a, Complexo b){
    if(b.real == 0 && b.imag == 0)
        throw runtime_error("Erro: divisao por zero");

    Complexo numerador = multiplicar(a, conjugado(b));
    double denominador = b.real * b.real + b.imag * b.imag;

    Complexo c;
    c.real = numerador.real / denominador;
    c.imag = numerador.imag / denominador;

    return c;
} 

Complexo conjugado(Complexo z){
    Complexo c;
    c.real = z.real;
    c.imag = z.imag * -1;
    return c;
}

// sqrt(real^2 + imag^2)
double modulo(Complexo z){
    return sqrt(pow(z.real, 2) + pow(z.imag, 2));
}

// atan2(imag, real) em radianos
double argumento(Complexo z){
    return atan2(z.imag, z.real);
}   

// Formato: "a + bi" ou "a - bi"
void imprimir(Complexo z){
    if(z.imag == 0)
        cout << z.real;
    else
        cout << z.real << (z.imag > 0 ? " + " : " - ") << (z.imag > 0 ? z.imag : z.imag * -1) << "i";
}