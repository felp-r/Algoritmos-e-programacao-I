/*
 * Problema: Operações Avançadas em Árvore Genérica de Diretórios
 * 
 * Usando a estrutura NoArvore, implemente as seguintes operações avançadas:
 * a) int caminho(NoArvore *no, char *nome, char *resultado): encontra o caminho da raiz até um nó específico (ex: "raiz/documentos/tese.pdf")
 * b) void imprimir_por_nivel(NoArvore *no): imprime os nós agrupados por nível (usando BFS)
 * c) NoArvore* remover(NoArvore *no, char *nome): remove um nó e toda a sua subárvore (libera memória)
 * 
 * Entrada:
 * - Primeira linha: N (número de nós)
 * - Próximas N linhas: nome_pai nome_filho
 * - Última linha: nome_alvo
 * 
 * Saída:
 * - Primeira linha: "Caminho: <caminho>"
 * - Segunda linha: "Por nivel: <nós agrupados por nível>"
 * - Terceira linha: "Apos remover <nome>:"
 * - Próximas linhas: a árvore exibida hierarquicamente após a remoção
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

int caminho(noArvore *no, string *nome, string *resultado){
    if(no == nullptr) return 0;
    if(!buscar(no, nome)) return 0;

    *resultado += no->nome + (*nome != no->nome ? "/" : "");
    
    noArvore* filho = no->primeiro_filho;
    while(filho != nullptr){
        caminho(filho, nome, resultado);
        filho = filho->proximo_irmao;
    }

    return 1;
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

void imprimir_por_nivel(noArvore *no) {
    if (no == nullptr) return;

    int h = altura(no);

    for (int i = 0; i < h; i++) {
        imprimir_nivel(no, 0, i);
        
        if (i < h - 1) {
            cout << "| ";
        }
    }
}

void destruir_sub_arvore(noArvore *no) {
    if (no == nullptr) return;
    destruir_sub_arvore(no->primeiro_filho);
    destruir_sub_arvore(no->proximo_irmao);
    delete no;
}

noArvore* remover(noArvore *no, string *nome) {
    if (no == nullptr) return nullptr;

    // Se o nó atual for o que queremos remover
    // (Assumindo que no->nome seja string e *nome seja o valor apontado)
    if (no->nome == *nome) { 
        noArvore* proximo = no->proximo_irmao;
        
        // Libera o nó atual e toda a sua descendência (filhos)
        destruir_sub_arvore(no->primeiro_filho);
        delete no;
        
        // Retorna o próximo irmão para que o pai ou irmão anterior assuma o lugar
        return proximo;
    }

    // Caso contrário, continua a busca recursivamente nos filhos e nos irmãos
    no->primeiro_filho = remover(no->primeiro_filho, nome);
    no->proximo_irmao = remover(no->proximo_irmao, nome);

    return no;
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
    string nome_alvo;
    cin >> nome_alvo;

    string resultado = "";
    caminho(raiz, &nome_alvo, &resultado);
    cout << "Caminho: " << resultado << endl;
    
    cout << "Por nivel: ";
    imprimir_por_nivel(raiz);

    remover(raiz, &nome_alvo);
    cout << "\nApos remover " << nome_alvo << ": " << endl;
    exibir(raiz, 0);

    return 0;
}