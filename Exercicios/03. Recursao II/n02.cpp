/*
 * Exercício 2 — Labirinto com Backtracking
 * 
 * Implemente um solucionador de labirinto usando backtracking. O labirinto é representado por uma
 * matriz onde:
 * • 0 = caminho livre
 * • 1 = parede
 * • 2 = posição visitada (marcação durante a busca)
 * 
 * a) Função base:
 *    bool resolver_labirinto(int labirinto[][MAX], int n, int m,
 *                             int x, int y, int destino_x, int destino_y);
 *    // Retorna true se encontrou caminho da posição (x,y) até o destino
 * 
 * Movimentos permitidos: cima, baixo, esquerda, direita (4 direções).
 * 
 * Exemplo de labirinto 5x5:
 * int labirinto[5][5] = {
 *     {0, 1, 0, 0, 0},
 *     {0, 1, 0, 1, 0},
 *     {0, 0, 0, 1, 0},
 *     {0, 1, 1, 1, 0},
 *     {0, 0, 0, 0, 0}
 * };
 * // Início: (0,0), Destino: (4,4)
 * // Caminho possível: (0,0)->(1,0)->(2,0)->(2,1)->(2,2)->(1,2)->(0,2)->(0,3)->(0,4)->(1,4)->(2,4)->(3,4)->(4,4)
 * 
 * b) Modifique o algoritmo para imprimir o labirinto a cada passo da exploração, mostrando as posições
 *    visitadas com um caractere especial.
 * 
 * c) Conte quantos movimentos (passos recursivos) foram necessários para encontrar a solução.
 * 
 * Desafio Extra:
 * Implemente uma versão que encontra o menor caminho (não apenas o primeiro encontrado).
 * Compare a quantidade de passos explorados.
 */

#include <iostream>
#include <ctime>
using namespace std;

#define MAX 5
int CONT = 0;

void imprimir_caminho(int x, int y, int des_x, int des_y){
    cout << "(" << x << ", " << y << ")";
    if(x == des_x && y == des_y) 
        cout << endl;
    else 
        cout << "->";
}

bool resolver_labirinto(int labirinto[][MAX], int n, int m, int x, int y, int destino_x, int destino_y){
    CONT++;

    // x ou y assumiram posições que não se encontram na matriz
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    // encontrou uma parede ou um caminho ja percorrido
    if(labirinto[x][y] == 1 || labirinto[x][y] == 2) return false;

    // troca o 0 por 2
    labirinto[x][y] = 2;

    // imprimi o caminho
    imprimir_caminho(x, y, destino_x, destino_y);

    // chegou ao destino
    if(x == destino_x && y == destino_y) return true;

    // andar para baixo
    if(resolver_labirinto(labirinto, n, m, x +1, y, destino_x, destino_y)){
        return true;
    }
    // andar para a direita
    if(resolver_labirinto(labirinto, n, m, x, y +1, destino_x, destino_y)){
        return true;
    }
    // andar para cima
    if(resolver_labirinto(labirinto, n, m, x -1, y, destino_x, destino_y)){
        return true;
    }
    // andar para esquerda
    if(resolver_labirinto(labirinto, n, m, x, y -1, destino_x, destino_y)){
        return true;
    }
    
    // Se nenhuma das 4 direções funcionou, desmarca a posição
    labirinto[x][y] = 0;
    return false;
}

int main(){
    int labirinto[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0}
    };

    resolver_labirinto(labirinto, 5, 5, 0, 0, 4, 4);
    cout << "Foram necessários " << CONT << " passos para encontrar a solução" << endl;

    return 0;
}