/*
 * Exercício 3 — Operadores Bitwise: Sistema de Permissões
 * 
 * Considere um sistema onde cada usuário possui permissões representadas por um unsigned char (8 bits).
 * Os bits representam:
 * 
 * +-----+--------------+------------------+
 * | Bit | Permissão    | Máscara          |
 * +-----+--------------+------------------+
 * |  0  | Ler          | 1 << 0 = 0x01    |
 * |  1  | Escrever     | 1 << 1 = 0x02    |
 * |  2  | Executar     | 1 << 2 = 0x04    |
 * |  3  | Deletar      | 1 << 3 = 0x08    |
 * |  4  | Administrar  | 1 << 4 = 0x10    |
 * +-----+--------------+------------------+
 * 
 * a) Defina as máscaras como constantes:
 *    const unsigned char LER         = (1 << 0);
 *    const unsigned char ESCREVER    = (1 << 1);
 *    const unsigned char EXECUTAR   = (1 << 2);
 *    const unsigned char DELETAR    = (1 << 3);
 *    const unsigned char ADMINISTRAR = (1 << 4);
 * 
 *    Implemente macros ou funções inline:
 *    void ligar_permissao(unsigned char &permissoes, unsigned char mascara);
 *    void desligar_permissao(unsigned char &permissoes, unsigned char mascara);
 *    bool verificar_permissao(unsigned char permissoes, unsigned char mascara);
 * 
 * b) Implemente uma função que recebe as permissões de dois usuários e retorna as permissões
 *    comuns a ambos (intersecção):
 *    unsigned char intersecao_permissoes(unsigned char user1, unsigned char user2);
 * 
 * c) Implemente uma função que verifica se um usuário tem permissão de administrador e execução
 *    simultaneamente:
 *    bool pode_administrar_e_executar(unsigned char permissoes);
 * 
 * Dica:
 * Para verificar múltiplas permissões ao mesmo tempo, combine as máscaras com OR e depois use AND.
 */

#include <iostream>

using namespace std;

const unsigned char LER         = (1 << 0);
const unsigned char ESCREVER    = (1 << 1);
const unsigned char EXECUTAR    = (1 << 2);
const unsigned char DELETAR     = (1 << 3);
const unsigned char ADMINISTRAR = (1 << 4);

void ligar_permissao(unsigned char &permissoes, unsigned char mascara){
    permissoes = permissoes | mascara;
}

void desligar_permissao(unsigned char &permissoes, unsigned char mascara){
    permissoes = permissoes & ~mascara;
}

bool verificar_permissao(unsigned char permissoes, unsigned char mascara){
    return (permissoes & mascara) == mascara;
}

unsigned char intersecao_permissoes(unsigned char user1, unsigned char user2){
    return user1 & user2;
}

bool pode_administrar_e_executar(unsigned char permissoes){
    unsigned char mascara_combinada = ADMINISTRAR | EXECUTAR;
    return (permissoes & mascara_combinada) == mascara_combinada;
}

void imprimir_permissoes(const string &nome_usuario, unsigned char permissoes) {
    cout << nome_usuario << " (Valor: " << (int)permissoes << "): [ ";
    if (verificar_permissao(permissoes, LER)) cout << "LER ";
    if (verificar_permissao(permissoes, ESCREVER)) cout << "ESCREVER ";
    if (verificar_permissao(permissoes, EXECUTAR)) cout << "EXECUTAR ";
    if (verificar_permissao(permissoes, DELETAR)) cout << "DELETAR ";
    if (verificar_permissao(permissoes, ADMINISTRAR)) cout << "ADMINISTRAR ";
    cout << "]\n";
}

int main() {
    cout << "=== TESTANDO SISTEMA DE PERMISSÕES ===\n\n";

    unsigned char user1 = 0;
    unsigned char user2 = 0;

    cout << "--- Teste Item A: Manipulação Básica ---\n";
    
    ligar_permissao(user1, LER);
    ligar_permissao(user1, ESCREVER);
    ligar_permissao(user1, EXECUTAR);
    imprimir_permissoes("User 1", user1);

    cout << "Removendo permissao de ESCREVER do User 1...\n";
    desligar_permissao(user1, ESCREVER);
    imprimir_permissoes("User 1", user1);

    cout << "User 1 pode LER? " << (verificar_permissao(user1, LER) ? "Sim" : "Nao") << "\n";
    cout << "User 1 pode ESCREVER? " << (verificar_permissao(user1, ESCREVER) ? "Sim" : "Nao") << "\n\n";

    cout << "--- Teste Item B: Intersecção ---\n";
    
    ligar_permissao(user2, LER);
    ligar_permissao(user2, EXECUTAR);
    ligar_permissao(user2, ADMINISTRAR);

    imprimir_permissoes("User 1", user1);
    imprimir_permissoes("User 2", user2);

    unsigned char comum = intersecao_permissoes(user1, user2);
    imprimir_permissoes("Permissoes em Comum", comum);
    cout << "\n";

    cout << "--- Teste Item C: Pode Administrar e Executar? ---\n";
    
    cout << "User 1 pode administrar E executar? " 
              << (pode_administrar_e_executar(user1) ? "Sim" : "Nao") << "\n";

    cout << "User 2 pode administrar E executar? " 
              << (pode_administrar_e_executar(user2) ? "Sim" : "Nao") << "\n";

    unsigned char user3 = 0;
    ligar_permissao(user3, ADMINISTRAR);
    ligar_permissao(user3, LER);
    imprimir_permissoes("User 3", user3);

    cout << "User 3 pode administrar E executar? " 
              << (pode_administrar_e_executar(user3) ? "Sim" : "Nao") << "\n";

    return 0;
}