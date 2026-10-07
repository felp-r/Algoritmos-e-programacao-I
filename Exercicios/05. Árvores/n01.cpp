/*
 * Problema: Árvore de Diretórios
 * 
 * Implemente o exemplo da aula e adicione:
 * - Função para buscar um nó por nome (recursiva)
 * - Função para contar o número total de nós
 * - Função para calcular a altura da árvore
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

struct No{
    string nome;
    No* primeiro_filho;
    No* proximo_irmao;
};

No* criar_no(const string nome){
    No* novo = (No*) malloc(sizeof(No));
    novo->nome = nome;
    novo->primeiro_filho = NULL;
    novo->proximo_irmao = NULL;
    return novo;
}

void adicionar_filho(No* pai, No* filho){
    filho->proximo_irmao = pai->primeiro_filho;
    pai->primeiro_filho = filho;
}

void exibir(No* no, int nivel){
    if(no == NULL) return;

    for(int i = 0; i < nivel; i++){
        cout << "    ";
    }
    cout << "|--" << no->nome << endl;

    No* filho = no->primeiro_filho;
    while(filho != NULL){
        exibir(filho, nivel +1);
        filho = filho->proximo_irmao;
    }
}

// Buscar um nó por nome (recursiva)
No* buscar_nome(No* no, string nome){
    if(no == NULL) return NULL;
    if(no->nome == nome) return no;

    No* retorno = NULL;
    No* filho = no->primeiro_filho;
    while(filho != NULL && retorno == NULL){
        retorno = buscar_nome(filho, nome);
        filho = filho->proximo_irmao;
    }

    return retorno;
}


int main(){
    // Construindo a arvore de diretorios
    No* raiz = criar_no("raiz");
    
    No* documentos = criar_no("documentos");
    No* imagens = criar_no("imagens");
    No* musicas = criar_no("musicas");

    adicionar_filho(raiz, documentos);
    adicionar_filho(raiz, imagens);
    adicionar_filho(raiz, musicas);

    adicionar_filho(documentos, criar_no("trabalho.txt"));
    adicionar_filho(documentos, criar_no("tese.pdf"));
    adicionar_filho(imagens, criar_no("foto.jpg"));

    // Exibindo a arvore
    exibir(raiz, 0);

    // Buscar por nome
    string nome = "trabalho.txt";
    No* no_buscado = buscar_nome(raiz, nome);

    if (no_buscado != NULL)
        cout << "Buscando " << nome << ": "
        << no_buscado << " -> "
        << no_buscado->primeiro_filho ? no_buscado->primeiro_filho->nome : "Não tem";
    else
        cout << "Nao encontrado " << nome;

    return 0;
}