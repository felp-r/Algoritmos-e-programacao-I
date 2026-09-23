/*
 * Exercício 2 — Structs e Ponteiros
 * 
 * Defina uma struct Produto com os campos:
 * 
 * struct Produto {
 *     int codigo;
 *     std::string nome;
 *     float preco;
 *     int quantidade;
 * };
 * 
 * Implemente as seguintes funções:
 * 
 * a) Uma função que recebe um array dinâmico de Produto e retorna o índice do produto mais caro. Se
 *    houver empate, retorne o primeiro encontrado.
 *    int indice_mais_caro(Produto* produtos, int tam);
 * 
 * b) Uma função que recebe o array e um código, e retorna um ponteiro para o produto encontrado (ou nullptr se não existir).
 *    Produto* buscar_por_codigo(Produto* produtos, int tam, int codigo);
 * 
 * c) Use assert ou mensagens de erro apropriadas para tratar o caso de array vazio (tamanho zero ou
 *    ponteiro nulo).
 * 
 * Dica:
 * Use assert(produtos != nullptr && tam > 0) no início de cada função.
 */

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Produto {
   int codigo;
   string nome;
   float preco;
   int quantidade;
};

int indice_mais_caro(Produto* produtos, int tam){
   assert(produtos != nullptr && tam > 0);

   int idx = 0;
   for(int i = 0; i < tam; i++){
      if(produtos[idx].preco < produtos[i].preco){
         idx = i;
      }
   }

   return idx;
}

Produto* buscar_por_codigo(Produto* produtos, int tam, int codigo){
   assert(produtos != nullptr && tam > 0);

   for(int i = 0; i < tam; i++){
      if(codigo == produtos[i].codigo){
         return &produtos[i];
      }
   }

   return nullptr;
}

void adicionar_produto(Produto* produtos, int tam){
   for(int i = 0; i < tam; i++){
      cout << "Digite o código: ";
      cin >> produtos[i].codigo;
      cin.ignore();

      cout << "Digite o nome: ";
      getline(cin, produtos[i].nome);

      cout << "Digite o preço: ";
      cin >> produtos[i].preco;

      cout << "Digite a quantidade: ";
      cin >> produtos[i].quantidade;

      cout << endl;
   }
}

void imprimir_produto(Produto *produto){
   cout << endl;

   if(produto != nullptr){
      cout << "Produto encontrado!" << endl;
      cout << "Código: " << produto->codigo << endl;
      cout << "Nome: " << produto->nome << endl;
      cout << "Preço: " << produto->preco << endl;
      cout << "Quantidade: " << produto->quantidade << endl;

   } else{
      cout << "Produto não encontrado!" << endl;
   }

   cout << endl;
}

void menu(){
   cout << "Escolha uma opção:" << endl;
   cout << "1- Adicionar produtos" << endl;
   cout << "2- Mostrar indice do produto mais caro" << endl;
   cout << "3- Buscar produto por código" << endl;
   cout << "4- Sair" << endl;
}

int main(){
   int tam, qtd = 0;
   cout << "Digite a quantidade de produtos a serem armazenados: ";
   cin >> tam;

   Produto* produtos = new Produto[tam];

   int op;
   bool c = true;
   while(c){
      menu();

      cin >> op;

      switch (op)
      {
      case 1:
         if(tam != qtd) {
            adicionar_produto(produtos, tam);
            qtd = tam;
         } 
         else cout << "Número máximo de elementos atingido!" << endl;
         
         continue;

      case 2:
         cout << "O índice do produto mais caro é: " << indice_mais_caro(produtos, tam) << endl << endl;
         continue;

      case 3:{
         int cod;
         cout << "Digite o código: ";
         cin >> cod;

         Produto* produto = buscar_por_codigo(produtos, tam, cod);

         imprimir_produto(produto);

         continue;
      }
      case 4:
         cout << "Programa encerrado!";
         c = false;
         break;
         
      default:
         cout << "Digite uma entrada válida." << endl;
         continue;
      }
   }

   delete[] produtos;
   return 0;
}