/*
 * Problema: Percursos em Árvore Genérica de Diretórios
 * 
 * Usando a mesma estrutura, implemente os seguintes percursos:
 * a) void pre_ordem(NoArvore *no): exibe o nó antes de seus filhos
 * b) void pos_ordem(NoArvore *no): exibe o nó depois de seus filhos
 * c) void em_largura(NoArvore *no): percurso em nível (BFS) — use uma fila auxiliar
 * 
 * Entrada:
 * - Primeira linha: N (número de nós)
 * - Próximas N linhas: nome_pai nome_filho
 * 
 * Saída:
 * - Primeira linha: "Pre-ordem: <nós separados por espaço>"
 * - Segunda linha: "Pos-ordem: <nós separados por espaço>"
 * - Terceira linha: "Em largura: <nós separados por espaço>"
 */

#include <iostream>

using namespace std;

struct noArvore{
    string nome;
    noArvore* primeiro_filho;
    noArvore* proximo_irmao;
};

noArvore* criar_no(string nome){
    noArvore* novo = new noArvore;
    novo->nome = nome;
    novo->primeiro_filho = nullptr;
    novo->proximo_irmao = nullptr;
    return novo;
}

void adicionar_filho(noArvore* pai, noArvore* filho){
    filho->proximo_irmao = pai->primeiro_filho;
    pai->primeiro_filho = filho;
}

void exibir(noArvore* no, int nivel){
    if(no == nullptr) return;

    for(int i = 0; i < nivel; i++){
        cout << "    ";
    }
    cout << "|-- " << no->nome << endl;

    noArvore* filho = no->primeiro_filho;
    while(filho != nullptr){
        exibir(filho, nivel +1);
        filho = filho->proximo_irmao;
    }
}

noArvore* buscar(noArvore* no, string* nome){
    if(no == nullptr) return nullptr;
    if(no->nome == *nome) return no;

    noArvore* retorno = nullptr;
    noArvore* filho = no->primeiro_filho;

    while(filho != nullptr && retorno == nullptr){
        retorno = buscar(filho, nome);
        filho = filho->proximo_irmao;
    }

    return retorno;
}

int altura(noArvore *no){
    if(no == nullptr) return 0;

    int altura_max = 0;
    noArvore* filho = no->primeiro_filho;
    while(filho != nullptr){
        int altura_filho = altura(filho);
        if(altura_filho > altura_max){
            altura_max = altura_filho;
        }
        filho = filho->proximo_irmao;
    }

    return altura_max + 1;
}

void pre_ordem(noArvore *no){
    if(no == nullptr) return;

    cout << no->nome << " ";

    noArvore* filho = no->primeiro_filho;
    while(filho != nullptr){
        pre_ordem(filho);
        filho = filho->proximo_irmao;
    }
}

void pos_ordem(noArvore *no){
    if(no == nullptr) return;

    noArvore* filho = no->primeiro_filho;
    while(filho != nullptr){
        pos_ordem(filho);
        filho = filho->proximo_irmao;
    }

    cout << no->nome << " ";
}

void imprimir_nivel(noArvore *no, int atual, int alvo) {
    if (no == nullptr) return;

    if (atual == alvo) {
        cout << no->nome << " ";
    } else {
        imprimir_nivel(no->primeiro_filho, atual + 1, alvo);
    }

    imprimir_nivel(no->proximo_irmao, atual, alvo);
}

void em_largura(noArvore *no){
    if(no == nullptr) return;

    int h = altura(no);

    for (int i = 0; i < h; i++) {
        imprimir_nivel(no, 0, i);
    }
}

int main(){
    int n;
    cin >> n;

    string pai, filho;

    noArvore* raiz = nullptr;
    for(int i = 0; i < n; i++){
        cin >> pai >> filho;

        auto no_pai = buscar(raiz, &pai);
        if(no_pai == nullptr){
            raiz = criar_no(pai);
            no_pai = raiz;
        }

        noArvore* no_filho = criar_no(filho);
        adicionar_filho(no_pai, no_filho);
    }

    
    cout << "Pre-ordem: ";
    pre_ordem(raiz);

    cout << endl;

    cout << "Pos-ordem: ";
    pos_ordem(raiz);

    cout << endl;
    
    cout << "Em largura: ";
    em_largura(raiz);

    return 0;
}