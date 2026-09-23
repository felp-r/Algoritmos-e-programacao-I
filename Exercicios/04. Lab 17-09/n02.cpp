/*
 * Problema: Simulação de Histórico de Navegador Web
 * 
 * Um navegador web mantém um histórico de páginas visitadas. O usuário pode executar três comandos:
 * - VISITAR url: acessa uma nova página (adiciona ao histórico)
 * - VOLTAR: retorna à página anterior no histórico
 * - AVANCAR: avança para a próxima página (após ter voltado)
 * 
 * Implemente um sistema que simula esse comportamento usando duas pilhas (uma para voltar, outra para avançar).
 * 
 * Entrada:
 * - Múltiplas linhas com comandos
 * - A entrada termina com a linha "FIM"
 * - Cada comando é: "VISITAR url", "VOLTAR" ou "AVANCAR"
 * - Se não for possível voltar ou avançar, ignore o comando
 * 
 * Saída:
 * - Para cada comando VISITAR, imprima a URL visitada
 * - Para cada comando VOLTAR ou AVANCAR bem-sucedido, imprima a URL atual
 * - Se o comando falhar, imprima "NAO FOI POSSIVEL"
 */

#include <iostream>

using namespace std;

#define MAX 1000

struct Pilha{
    string dados[MAX];
    int top;
};

void inicializar(Pilha* p){
    p->top = -1;
}

bool vazia(Pilha* p){
    return p->top == -1;
}

bool cheia(Pilha* p){
    return p->top == MAX - 1;
}

bool adicionar(Pilha* p, string str){
    if(cheia(p)) 
        return false;

    p->top++;
    p->dados[p->top] = str;
    return true;
}

bool remover(Pilha* p, string* str){
    if(vazia(p))
        return false;

    *str = p->dados[p->top];
    p->top--;
    return true;
}

int main(){
    Pilha* voltar = new Pilha;
    Pilha* avancar = new Pilha;

    inicializar(voltar);
    inicializar(avancar);

    string s, site;
    while(cin >> s){
        if(s == "FIM"){
            delete voltar;
            delete avancar;
            return 0;
        }

        if(s == "VISITAR"){
            cin >> site;

            if(adicionar(voltar, site)){
                cout << voltar->dados[voltar->top] << endl;
                inicializar(avancar);
            } else{
                cout << "NAO FOI POSSIVEL" << endl;
            }

        } else if(s == "VOLTAR"){
            if(voltar->top <= 0){
                cout << "NAO FOI POSSIVEL" << endl;
            } else{
                remover(voltar, &site);
                cout << voltar->dados[voltar->top] << endl;
                adicionar(avancar, site);
            }

        } else if(s == "AVANCAR"){
            if(remover(avancar, &site)){
                adicionar(voltar, site);
                cout << voltar->dados[voltar->top] << endl;
            } else{
                cout << "NAO FOI POSSIVEL" << endl;
            }
            
        }
    }
    
    delete voltar;
    delete avancar;
    return 0;
}