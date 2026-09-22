/*
 * Problema: Simulação de Fila de Atendimento Bancário
 * 
 * Um banco possui uma única fila de atendimento. Cada cliente possui um número de senha e um tipo:
 * - N: cliente normal
 * - P: cliente prioritário
 * 
 * Política de atendimento:
 * - A cada 2 clientes prioritários atendidos, 1 cliente normal é atendido.
 * - Se não houver prioritários, atende-se normais.
 * - Se não houver normais, atende-se prioritários.
 * 
 * Dada a sequência de chegada dos clientes, determine a ordem de atendimento.
 * 
 * Entrada:
 * - Primeira linha: N (número de clientes, 1 <= N <= 1000)
 * - Próximas N linhas: tipo e senha (ex: "P 101", "N 102")
 * 
 * Saída:
 * - N linhas com as senhas na ordem de atendimento
 */

#include <iostream>

using namespace std;
#define MAX 1000

struct Pessoa{
    char tipo;
    int senha;
    Pessoa* prox;
};

struct Fila{
    Pessoa* frente;
    Pessoa* tras;
    int tam;
};

// Inicializar fila
void inicializar(Fila* f){
    f->frente = f->tras = nullptr;
    f->tam = 0;
}

bool adicionar(Fila* f, char tipo, int senha){
    Pessoa* novo = new Pessoa;

    if(novo == nullptr)
        return false;

    novo->tipo = tipo;
    novo->senha = senha;
    novo->prox = nullptr;

    if(f->tras == nullptr){
        f->frente = novo;
        f->tras = novo;
    } else{
        f->tras->prox = novo;
        f->tras = novo;
    }

    f->tam++;
    
    return true;
}

bool remover(Fila* f){
    if(f->tras == nullptr){
        return false;
    }

    Pessoa* temp = f->frente;
    f->frente = temp->prox;

    if(f->frente == nullptr)
        f->tras = nullptr;

    cout << temp->senha << endl;
    f->tam--;
    delete temp;
    return true;
}

void exibir(Fila* f){
    if(f->tras == nullptr){
        return;
    }

    for(Pessoa* p = f->frente; p != nullptr; p = p->prox){
        cout << "Tipo: "<< p->tipo << " - Senha: "<< p->senha << endl;
    }
}

int main(){
    int pCont = 0;
    Fila* P = new Fila[MAX];
    Fila* N = new Fila[MAX];

    inicializar(P);
    inicializar(N);

    int num;
    cin >> num;

    char t;
    int s;

    // Adicionar elementos
    for(int i = 0; i < num; i++){
        cin >> t;
        cin >> s;
        
        if(t == 'P'){
            adicionar(P, t, s);
        }
        if(t == 'N'){
            adicionar(N, t, s);
        }
    }

    // Remover elementos
    for(int i = 0; i < num; i++){
        if(pCont != 2){
            remover(P);
            pCont++;
        } else{
            remover(N);
            pCont = 0;
        }

        // Caso alguma lista esteja vazia, é retornado false
        if(!remover(P)){
            remover(N);
        }
        if(!remover(N)){
            remover(P);
        }
    }

    delete[] P;
    delete[] N;
    return 0;
}