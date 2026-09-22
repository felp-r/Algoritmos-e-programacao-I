/*
 * Problema: Verificação de Expressões Balanceadas (Parênteses, Colchetes e Chaves)
 * 
 * Dada uma string contendo apenas os caracteres (, ), [, ], {, }, verifique se a sequência está balanceada.
 * Uma sequência é balanceada se:
 * - Cada abertura tem um fechamento correspondente
 * - A ordem de fechamento respeita a ordem de abertura (aninhamento correto)
 * - Não há fechamentos sem abertura correspondente
 * 
 * Entrada:
 * - Múltiplas linhas, cada uma com uma string de até 1000 caracteres
 * - A entrada termina com EOF
 * 
 * Saída:
 * - Para cada linha: OK se balanceada, ERRO caso contrário
 */

#include <iostream>

using namespace std;

#define MAX_STR 1005
#define MAX_PILHA 100

struct Pilha {
    char* dados;
    int top, cap;
};

void inicializar(Pilha* p) {
    p->dados = new char[MAX_PILHA];
    p->cap = MAX_PILHA;
    p->top = -1;
}

int vazia(Pilha* p) {
    return p->top == -1;
}

void adicionar(Pilha* p, char valor) {
    if (p->top + 1 == p->cap) {
        char* novo = new char[p->cap * 2];

        for (int i = 0; i < p->cap; i++) {
            novo[i] = p->dados[i];
        }

        delete[] p->dados;
        p->dados = novo;
        p->cap = p->cap * 2;
    }

    p->top++;
    p->dados[p->top] = valor;
}

char deletar(Pilha* p) {
    if (vazia(p)) {
        return '\0';
    }

    char temp = p->dados[p->top];
    p->top--;
    return temp;
}

int balanceamento(char* str) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            adicionar(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char r = deletar(&p);

            if (r == '\0') {
                delete[] p.dados; // Libera memória antes de sair
                return 0;
            }

            if ((r != '(' && c == ')') ||
                (r != '[' && c == ']') ||
                (r != '{' && c == '}')) {
                
                delete[] p.dados; // Libera memória antes de sair
                return 0;
            }   
        }
    }

    int resultado = vazia(&p);
    delete[] p.dados; // Libera memória da pilha criada
    return resultado;
}

int main() {
    char str[MAX_STR];

    // Lê múltiplas linhas até o final do arquivo (EOF)
    while (cin >> str) {
        cout << (balanceamento(str) ? "OK" : "ERRO") << endl;
    }

    return 0;
}