/*
 * Exercício 9 — Recursão sobre Strings
 * 
 * Implemente funções recursivas que (sem usar laços):
 * 
 * a) Verificam se uma string é palíndromo (lê-se igual de frente para trás, ignorando diferenças entre
 *    maiúsculas e minúsculas).
 *    bool eh_palindromo(std::string s, int inicio, int fim);
 *    // Exemplos: "radar", "osso", "arara", "Reviver", "Ame a ema"
 * 
 * b) Invertem uma string.
 *    std::string inverter(std::string s, int inicio, int fim);
 *    // Exemplo: inverter("recursao", 0, 7) = "oasrucer"
 * 
 * c) Contam quantas vogais (a, e, i, o, u — maiúsculas ou minúsculas) existem em uma string.
 *    int contar_vogais(std::string s, int pos);
 *    // Exemplo: contar_vogais("Algoritmos", 0) = 4
 * 
 * Desafio Extra:
 * Modifique a função de palíndromo para ignorar espaços e acentos.
 * Exemplo: "A mala nada na lama" deve ser considerado palíndromo.
 */

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool eh_palindromo(std::string s, int inicio, int fim){
    if(s[inicio] != s[fim]) return false;

    if(eh_palindromo(s, inicio +1, fim -1)) return true;

    return true;
}

string inverter(std::string s, int inicio, int fim){
    string inverso = "";
    inverso += s[fim];

    if(inicio == fim) return inverso;

    return inverso += inverter(s, inicio, fim -1);
}

int contar_vogais(std::string s, int pos){
    string vogais = "aeiou";

    if(pos == s.size()) return 0;

    bool eh_vogal = (vogais.find(s[pos]) != string::npos);

    if (eh_vogal) return 1 + contar_vogais(s, pos +1);

    return contar_vogais(s, pos +1);
}

int main(){
    string str;
    cout << "Digite a palavra desejada: ";
    getline(cin, str);

    // converter tudo para minúsculo primeiro
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    if(eh_palindromo(str, 0, str.size() -1)){
        cout << "A string '" << str << "' é um palíndromo." << endl;
    } else{
        cout << "A string '" << str << "' não é um palíndromo." << endl;
    }

    cout << "A string '" << str << "' invertida é: " << inverter(str, 0, str.size() -1) << endl;

    cout << "A string '" << str << "' possui " << contar_vogais(str, 0) << " vogais" << endl;

    return 0;
}