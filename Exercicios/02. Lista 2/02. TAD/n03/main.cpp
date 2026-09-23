/*
 * Exercício 5 — TAD Data e Calendário
 * 
 * Projete e implemente um TAD para manipulação de datas.
 * 
 * Especificação:
 * 
 * struct Data {
 *     int dia;
 *     int mes;
 *     int ano;
 * };
 * 
 * Data criar_data(int dia, int mes, int ano);
 * bool data_valida(Data d);              // Verifica se a data é válida
 * int dias_no_mes(int mes, int ano);     // Retorna número de dias do mês
 * bool eh_bissexto(int ano);             // Verifica se ano é bissexto
 * Data somar_dias(Data d, int dias);     // Adiciona dias à data
 * int diferenca_dias(Data d1, Data d2);  // d2 - d1 em dias
 * int dia_da_semana(Data d);             // 0=dom, 1=seg, ..., 6=sáb
 * void imprimir(Data d);                 // Formato: dd/mm/aaaa
 * void imprimir_por_extenso(Data d);     // "25 de dezembro de 2024"
 * 
 * Algoritmo para dia da semana (Zeller):
 * h = (q + floor(13*(m+1)/5) + K + floor(K/4) + floor(J/4) - 2*J) mod 7
 * 
 * Onde:
 * • q = dia do mês
 * • m = mês (3=março, 4=abril, ..., 14=fevereiro; janeiro e fevereiro contam como meses 13 e 14 do ano anterior)
 * • K = ano do século (ano mod 100)
 * • J = século (floor(ano/100))
 * • h = 0=sábado, 1=domingo, 2=segunda, ..., 6=sexta (ajustar para seu formato)
 * 
 * Testes obrigatórios:
 * • Diferença entre 01/01/2024 e 31/12/2024 (deve ser 365 dias, 2024 é bissexto)
 * • Somar 30 dias a 01/01/2024 (deve resultar em 31/01/2024)
 * • Somar 365 dias a 01/01/2024 (deve resultar em 31/12/2024)
 * • Dia da semana de 25/12/2024 (Natal)
 * 
 * Dica:
 * Trate anos bissextos: divisível por 4, mas não por 100, exceto se divisível por 400.
 */

#include <iostream>
#include "data.h"
using namespace std;

int main(){
    Data d1 = criar_data(1, 1, 2024);
    Data d2 = criar_data(31, 12, 2024);
    Data natal = criar_data(25, 12, 2024);

    // 1. Diferença entre 01/01/2024 e 31/12/2024 (deve ser 365)
    int diff = diferenca_dias(d1, d2);
    cout << "1. Diferenca entre 01/01/2024 e 31/12/2024: " << diff << " dias ";
    cout << endl;

    // 2. Somar 30 dias a 01/01/2024 (deve resultar em 31/01/2024)
    Data res_30 = somar_dias(d1, 30);
    cout << "2. 01/01/2024 + 30 dias: ";
    imprimir(res_30);

    // 3. Somar 365 dias a 01/01/2024 (deve resultar em 31/12/2024)
    Data res_365 = somar_dias(d1, 365);
    cout << "3. 01/01/2024 + 365 dias: ";
    imprimir(res_365);

    // 4. Dia da semana de 25/12/2024 (Natal) - 25/12/2024 foi uma Quarta-feira (3)
    int ds = dia_da_semana(natal);
    const string nomes_dias[] = {"Sábado", "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira"};
    cout << "4. Dia da semana do Natal (25/12/2024): " << ds << " (" << (ds >= 0 && ds <= 6 ? nomes_dias[ds] : "Invalido") << ")" << endl << endl;

    // 5. Testes de funcoes auxiliares
    cout << "--- Testes de Funcoes Auxiliares ---" << endl;

    // Teste de Ano Bissexto
    cout << "2024 e bissexto? " << (eh_bissexto(2024) ? "Sim" : "Nao") << endl;
    cout << "2023 e bissexto? " << (eh_bissexto(2023) ? "Sim" : "Nao") << endl;

    // Teste de Dias no Mês
    cout << "Dias em Fev/2024: " << dias_no_mes(2, 2024) << endl;
    cout << "Dias em Fev/2023: " << dias_no_mes(2, 2023) << endl;

    // Teste de Validação de Datas
    Data invalida = criar_data(29, 2, 2023);
    cout << "29/02/2023 e valida? " << (data_valida(invalida) ? "Sim" : "Nao") << endl;

    // Teste de Impressão por Extenso
    cout << "Impressao por extenso do Natal: ";
    imprimir_por_extenso(natal);
    cout << endl;

    return 0;
}