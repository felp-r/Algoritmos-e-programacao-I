/*
 * Exercício 10 — Comparação de Desempenho: Sequencial vs. Encadeada
 * 
 * Implemente um programa de benchmark que compare o desempenho real entre lista sequencial (array)
 * e lista encadeada. Realize os seguintes Experimentos:
 * 
 * Experimento 1: Inserção no início
 * • Insira N = 1.000, 5.000, 10.000, 50.000 elementos aleatórios no início de ambas as estruturas
 * • Meça o tempo de cada operação usando clock() da biblioteca <ctime>
 * 
 * Experimento 2: Inserção no fim
 * • Repita o procedimento anterior, mas inserindo no fim
 * • Para a lista encadeada, use a versão com ponteiro cauda (O(1))
 * 
 * Experimento 3: Acesso aleatório
 * • Gere 10.000 índices aleatórios entre 0 e N - 1
 * • Acesse cada índice em ambas as estruturas e meça o tempo total
 * 
 * Estrutura do programa:
 * #include <iostream>
 * #include <ctime>
 * #include <cstdlib>
 * 
 * double medir_tempo_insercao_inicio(int n, int tipo_estrutura);
 * double medir_tempo_insercao_fim(int n, int tipo_estrutura);
 * double medir_tempo_acesso_aleatorio(int n, int num_acessos, int tipo_estrutura);
 * // tipo_estrutura: 0 = sequencial, 1 = encadeada
 * 
 * void gerar_tabela_resultados();
 * 
 * Resultados esperados (preencha a tabela abaixo):
 * 
 * +--------+-----------------------+-----------------------+-----------------------+
 * | N      | Inserção no Início    | Inserção no Fim       | Acesso Aleatório      |
 * |        | Sequencial | Encadeada| Sequencial | Encadeada| Sequencial | Encadeada|
 * +--------+------------+-----------+------------+-----------+------------+-----------+
 * | 1.000  |  0.00034s  |  0.00018s |  0.00002s  |  0.00003s |   0.00012s |  0.00702s |
 * | 5.000  |  0.00874s  |  0.00015s |  0.00006s  |  0.00011s |   0.00017s |  0.04807s |
 * | 10.000 |  0.03281s  |  0.00025s |  0.00013s  |  0.00023s |   0.00012s |  0.09358s |
 * | 50.000 |  0.88501s  |  0.00215s |  0.00129s  |  0.00239s |   0.00024s |  0.58363s |
 * +--------+------------+-----------+------------+-----------+------------+-----------+
 * 
 * Análise crítica (relatório):
 * 1. Por que a inserção no início é tão mais lenta na lista sequencial?
 *    R: Porque na lista sequencial é preciso mover todos os demais elementos para a direita para 
 *       poder inserir no início, o que gera um alto custo.
 * 
 * 2. Em que cenário a lista encadeada é claramente superior? E a sequencial?
 *    R: A lista encadeada é superior somente em inserir no início. Nos demais, inserção no final e
 *       acesso aleatório, a lista sequencial levou vantagem. 
 * 
 * 3. O que aconteceria com os resultados se N = 1.000.000?
 *    R: Não irei testar, é um número muito grande.
 * 
 * Dica:
 * Use clock() para medir tempo de CPU:
 * clock_t inicio = clock();
 * // ... operacoes ...
 * clock_t fim = clock();
 * double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
 * Para medições mais precisas, execute cada experimento 3 vezes e use a média.
 * 
 * Desafio Extra:
 * Compare também com std::vector e std::list do C++ (compile com g++). Os resultados
 * são similares? Por quê?
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "lista_sequencial.h"
#include "lista_encadeada.h"

using namespace std;

// --- Medições de Desempenho ---

double medir_insercao_inicio(int n, int tipo) {
    clock_t inicio = clock();

    if (tipo == 0) { // Sequencial
        ListaSequencial lista;
        inicializar(&lista);
        for (int i = 0; i < n; i++) inserir(&lista, 0, rand());
        destruir_sequencial(&lista);
    } else { // Encadeada
        ListaEncadeada lista;
        inicializar_encadeada(&lista);
        for (int i = 0; i < n; i++) inserir_inicio_encadeada(&lista, rand());
        destruir_encadeada(&lista);
    }

    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

double medir_insercao_fim(int n, int tipo) {
    clock_t inicio = clock();

    if (tipo == 0) { // Sequencial
        ListaSequencial lista;
        inicializar(&lista);
        for (int i = 0; i < n; i++) inserir(&lista, lista.tamanho, rand());
        destruir_sequencial(&lista);
    } else { // Encadeada
        ListaEncadeada lista;
        inicializar_encadeada(&lista);
        for (int i = 0; i < n; i++) inserir_fim_encadeada(&lista, rand());
        destruir_encadeada(&lista);
    }

    return (double)(clock() - inicio) / CLOCKS_PER_SEC;
}

double medir_acesso_aleatorio(int n, int num_acessos, int tipo) {
    volatile int dummy; // Evita que o compilador otimize e remova a busca

    if (tipo == 0) { // Sequencial
        ListaSequencial lista;
        inicializar(&lista);
        for (int i = 0; i < n; i++) inserir(&lista, lista.tamanho, i);

        clock_t inicio = clock();
        for (int i = 0; i < num_acessos; i++) {
            dummy = acessar_posicao(&lista, rand() % n);
        }
        clock_t fim = clock();

        destruir_sequencial(&lista);
        return (double)(fim - inicio) / CLOCKS_PER_SEC;
    } else { // Encadeada
        ListaEncadeada lista;
        inicializar_encadeada(&lista);
        for (int i = 0; i < n; i++) inserir_fim_encadeada(&lista, i);

        clock_t inicio = clock();
        for (int i = 0; i < num_acessos; i++) {
            dummy = acessar_posicao_encadeada(&lista, rand() % n);
        }
        clock_t fim = clock();

        destruir_encadeada(&lista);
        return (double)(fim - inicio) / CLOCKS_PER_SEC;
    }
}

// Executa cada experimento 3 vezes e retorna a média
double media_teste(int n, int operacao, int tipo, int acessos = 10000) {
    double soma = 0;
    for (int i = 0; i < 3; i++) {
        if (operacao == 0)      soma += medir_insercao_inicio(n, tipo);
        else if (operacao == 1) soma += medir_insercao_fim(n, tipo);
        else                    soma += medir_acesso_aleatorio(n, acessos, tipo);
    }
    return soma / 3.0;
}

int main() {
    srand(12345);

    int tamanhos[] = {1000, 5000, 10000, 50000};
    int total_tamanhos = 4;
    int num_acessos = 10000;

    cout << fixed << setprecision(5);
    cout << "\n+--------+-----------------------+-----------------------+-----------------------+\n";
    cout << "| N      | Insercao no Inicio    | Insercao no Fim       | Acesso Aleatorio      |\n";
    cout << "|        | Sequencial | Encadeada| Sequencial | Encadeada| Sequencial | Encadeada|\n";
    cout << "+--------+------------+-----------+------------+-----------+------------+-----------+\n";

    for (int i = 0; i < total_tamanhos; i++) {
        int n = tamanhos[i];

        double in_seq  = media_teste(n, 0, 0);
        double in_enc  = media_teste(n, 0, 1);
        double fim_seq = media_teste(n, 1, 0);
        double fim_enc = media_teste(n, 1, 1);
        double ac_seq  = media_teste(n, 2, 0, num_acessos);
        double ac_enc  = media_teste(n, 2, 1, num_acessos);

        cout << "| " << setw(6) << n << " | "
             << setw(10) << in_seq  << "s | " << setw(9) << in_enc  << "s | "
             << setw(10) << fim_seq << "s | " << setw(9) << fim_enc << "s | "
             << setw(10) << ac_seq  << "s | " << setw(9) << ac_enc  << "s |\n";
    }

    cout << "+--------+------------+-----------+------------+-----------+------------+-----------+\n\n";

    return 0;
}