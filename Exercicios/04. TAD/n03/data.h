#ifndef DATA_H
#define DATA_H

struct Data {
    int dia;
    int mes;
    int ano;
};

Data criar_data(int dia, int mes, int ano);
bool data_valida(Data d);              // Verifica se a data é válida
int dias_no_mes(int mes, int ano);     // Retorna número de dias do mês
bool eh_bissexto(int ano);             // Verifica se ano é bissexto
Data somar_dias(Data d, int dias);     // Adiciona dias à data
int diferenca_dias(Data d1, Data d2);  // d2 - d1 em dias
int dia_da_semana(Data d);             // 0=dom, 1=seg, ..., 6=sáb
void imprimir(Data d);                 // Formato: dd/mm/aaaa
void imprimir_por_extenso(Data d);     // "25 de dezembro de 2024"

#endif