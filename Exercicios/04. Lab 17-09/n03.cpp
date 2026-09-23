/*
 * Problema: Simulação de Fila de Impressão com Prioridades
 * 
 * Uma impressora recebe trabalhos de impressão. Cada trabalho possui:
 * - ID (número inteiro)
 * - Número de páginas
 * - Prioridade (0 = baixa, 1 = média, 2 = alta)
 * 
 * A impressora processa os trabalhos na seguinte ordem:
 * - Todos os trabalhos de prioridade alta (na ordem de chegada)
 * - Todos os trabalhos de prioridade média (na ordem de chegada)
 * - Todos os trabalhos de prioridade baixa (na ordem de chegada)
 * 
 * Simule a impressão e calcule o tempo total de impressão, sabendo que cada página leva 1 segundo.
 * Restrição: Não pode usar tipos de C++.
 * 
 * Entrada:
 * - Primeira linha: N (número de trabalhos, 1 <= N <= 1000)
 * - Próximas N linhas: ID, páginas, prioridade
 * 
 * Saída:
 * - Primeira linha: ordem de impressão (IDs separados por espaço)
 * - Segunda linha: tempo total de impressão em segundos
 */

#include <iostream>

using namespace std;

#define MAX 1000

struct No{
    int id;
    int nPag;
    int prioridade;
    No* prox;
};

struct Lista{
    No* cab;
    int tam;
};

void inicializar(Lista* l){
    l->cab = nullptr;
    l->tam = 0;
}

No* criar_no(int id, int pag, int prioridade){
    No* novo = new No;
    
    if(novo == nullptr){
        cout << "Erro! Memoria insuficiente" << endl;
        exit(1);
    }
    
    novo->id = id;
    novo->nPag = pag;
    novo->prioridade = prioridade;
    novo->prox = nullptr;
    return novo;
}

void adicionar(Lista* l, int id, int pag, int prioridade){
    No* novo = criar_no(id, pag, prioridade);
    
    if(l->cab == nullptr) {
        l->cab = novo;
    } else{
        No* atual = l->cab;
        
        while(atual->prox != nullptr)
            atual = atual->prox;
            
        atual->prox = novo;
    }
    l->tam++;
}

void deletar(Lista* l, int* id){
    if(l->cab == nullptr) return;

    No* temp = l->cab;
    *id = temp->id;
    l->cab = temp->prox;
    l->tam--;
    delete temp;
}


int main(){
    Lista* alta = new Lista[MAX];
    Lista* media = new Lista[MAX];
    Lista* baixa = new Lista[MAX];

    inicializar(alta);
    inicializar(media);
    inicializar(baixa);

    int tempoTotal = 0;
    int idImpressao;
    int n;
    cin >> n;

    // povoar
    for(int i = 0; i < n; i++){
        int id;
        int pag;
        int prioridade;

        cin >> id >> pag >> prioridade;

        tempoTotal += pag;

        if(prioridade == 0){
            adicionar(baixa, id, pag, prioridade);
        } else if (prioridade == 1){
            adicionar(media, id, pag, prioridade);
        } else if(prioridade == 2){
            adicionar(alta, id, pag, prioridade);
        }
    }

    // imprimir alta
    while(alta->tam != 0){
        deletar(alta, &idImpressao);
        cout << idImpressao << " ";
    }

    // imprimir media
    while(media->tam != 0){
        deletar(media, &idImpressao);
        cout << idImpressao << " ";
    }

    // imprimir baixa
    while(baixa->tam != 0){
        deletar(baixa, &idImpressao);
        cout << idImpressao << " ";
    }

    cout << endl << tempoTotal << endl;
    
    delete[] alta;
    delete[] media;
    delete[] baixa;
    return 0;
}