#include <iostream>
#include <cmath>
#include "data.h"

using namespace std;

Data criar_data(int dia, int mes, int ano){
    Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}

// Verifica se a data é válida
bool data_valida(Data d){
    if(d.mes >= 1 && d.mes <= 12){
        if(d.dia >= 1 && d.dia <= dias_no_mes(d.mes, d.ano))
            return true;
        else
            return false;
    }
    else{
        return false;
    }
}

// Retorna número de dias do mês
int dias_no_mes(int mes, int ano){
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2){
        if(eh_bissexto(ano))
            return dias[mes -1] +1;
        return dias[mes -1];
    }

    return dias[mes -1];
}

// Verifica se ano é bissexto
bool eh_bissexto(int ano){
    if(ano % 4 == 0){
        if(ano % 100 != 0)
            return true;
        else if(ano % 400 == 0)
            return true;
        else
            return false;
    } else {
        return false;
    }
}

// Adiciona dias à data
Data somar_dias(Data d, int dias){
   while (dias > 0) {
        d.dia++;

        // Se o dia ultrapassou o limite do mês atual
        if (d.dia > dias_no_mes(d.mes, d.ano)) {
            d.dia = 1;
            d.mes++;

            // Se o mês ultrapassou dezembro
            if (d.mes > 12) {
                d.mes = 1;
                d.ano++;
            }
        }

        dias--;
    }
    return d;
}

// d2 - d1 em dias
int diferenca_dias(Data d1, Data d2){
    int dias = 0;

    // Avança d1 até ficar exatamente igual a d2
    while (d1.dia != d2.dia || d1.mes != d2.mes || d1.ano != d2.ano) {
        dias++;
        d1.dia++;

        if (d1.dia > dias_no_mes(d1.mes, d1.ano)) {
            d1.dia = 1;
            d1.mes++;
            if (d1.mes > 12) {
                d1.mes = 1;
                d1.ano++;
            }
        }
    }

    return dias;
}

// 0=dom, 1=seg, ..., 6=sáb
int dia_da_semana(Data d){
    int q = d.dia;
    int m = d.mes;
    if(m == 1 || m == 2) 
        m += 12;
    int K = d.ano % 100;
    int J = d.ano / 100;

    int h = (q + floor(13*(m+1)/5) + K + floor(K/4) + floor(J/4) - 2*J);
    
    return h % 7;
}

// Formato: dd/mm/aaaa
void imprimir(Data d){
    if(data_valida(d)){
        cout << (d.dia < 10 ? "0" : "") << d.dia << "/";
        cout << (d.mes < 10 ? "0" : "") << d.mes << "/";
        cout << d.ano << endl;
    } else {
        cout << "Data inválida!" << endl;
    }
}

// "25 de dezembro de 2024"
void imprimir_por_extenso(Data d){
    string meses[] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };

    if(data_valida(d)){
        cout << (d.dia < 10 ? "0" : "") << d.dia << " de ";
        cout << meses[d.mes-1] << " de ";
        cout << d.ano << endl;
    } else {
        cout << "Data inválida!" << endl;
    }
}     