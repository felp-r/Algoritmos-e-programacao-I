/*
 * Problema: Árvore Genérica de Diretórios (Filho mais velho / Irmão mais novo)
 * 
 * Usando a estrutura NoArvore que define uma árvore genérica para representar a estrutura 
 * de diretórios de um sistema de arquivos (representação filho mais velho / irmão mais novo), 
 * implemente funções recursivas para:
 * a) int altura(NoArvore *no): calcula a altura da árvore (número de níveis)
 * b) int profundidade(NoArvore *no, char *nome, int nivel_atual): calcula a profundidade de um nó específico (raiz = 0)
 * c) int grau_maximo(NoArvore *no): retorna o grau máximo entre todos os nós (maior número de filhos diretos)
 * 
 * Entrada:
 * - Primeira linha: N (número de nós)
 * - Próximas N linhas: nome_pai nome_filho
 * - Última linha: nome_profundidade
 * 
 * Saída:
 * - Primeira linha: "Altura: <n>"
 * - Segunda linha: "Profundidade de <nome>: <n>"
 * - Terceira linha: "Grau maximo: <n>"
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
    cout << "|--" << no->nome << endl;

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

int profundidade(noArvore *no, string *nome, int nivel_atual){
    if(no == nullptr) return -1;

    else if(no->nome == *nome) return nivel_atual;

    noArvore* filho = no->primeiro_filho;
    int prof = 0;
    while(filho != nullptr){
        int prof_filho = profundidade(filho, nome, nivel_atual+1);
        if(prof_filho > prof){
            prof = prof_filho;
        }
        filho = filho->proximo_irmao;
    }

    return prof;
}

int grau_maximo(noArvore *no) {
    if (no == nullptr) return 0;

    int grau_atual = 0;
    int maior_grau_filhos = 0;
    noArvore* filho = no->primeiro_filho;

    while (filho != nullptr) {
        grau_atual++;
        
        int grau_filho = grau_maximo(filho);
        if (grau_filho > maior_grau_filhos) {
            maior_grau_filhos = grau_filho;
        }
        
        filho = filho->proximo_irmao;
    }

    // O grau máximo é o maior entre o grau do nó atual e o grau máximo das sub-árvores
    return (grau_atual > maior_grau_filhos) ? grau_atual : maior_grau_filhos;
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

    cout << "Altura: " << altura(raiz) << endl;
    
    string nome_profundidade;
    cin >> nome_profundidade;
    cout << "Profundidade de " << nome_profundidade
    << ": " << profundidade(raiz, &nome_profundidade, 0) << endl;
    
    cout << "Grau maximo: " << grau_maximo(raiz);

    return 0;
}