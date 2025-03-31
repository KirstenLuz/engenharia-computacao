/* Milene Emmel Rovedder, Kirsten Luz Concepcion, Isabella Zermiani Bastos */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#include "lib.h"
#define TAM 300

/* Define as cores para o código */
#define background_purple_color "\033[48;5;"
#define pink_color "\033[38;5;206m"
#define purple_color "\033[38;5;141m"
#define reset_color "\033[0m"
#define blue_color "\033[0;34m"
#define green_color "\033[38;5;150m"

void limpar() {
  if (system("clear") == -1) {
    // Handle the error, if necessary
  }
}

void pressione_enter() {
  cout << "Pressione enter para continuar...";
  cin.get();
  cin.ignore();
  if (system("clear") == -1) {
    // Handle the error, if necessary
  }
}

/* Menu de opções */
void opcoes_menu(int &Menu) {
  // int opcoes;

  cout << purple_color << "╔════════════════════════════════╗" << endl;
  cout << "║            " << reset_color << " Menu" << purple_color
       << "               ║" << endl;
  cout << "╠════════════════════════════════╣" << endl;
  cout << "║ " << reset_color << "1. Inserir novo produto" << purple_color
       << "        ║" << endl;
  cout << "║ " << reset_color << "2. Eliminar produto" << purple_color
       << "            ║" << endl;
  cout << "║ " << reset_color << "3. Consulta de produto" << purple_color
       << "         ║" << endl;
  cout << "║ " << reset_color << "4. Sair" << purple_color
       << "                        ║" << endl;
  cout << "╚════════════════════════════════╝" << endl;
  cout << reset_color << endl
       << pink_color << "Digite a opção que deseja: " << reset_color;
  cin >> Menu;
}

/* Insere novo produto */
bool insere_produto(ListaE &lista, Produto *&novoProduto) {
  Produto *busca = lista.inicio;
  novoProduto = new Produto;
  // Inicializa a posição como 0 (primeira posição na lista)
  int pos = 0;
  // Cria um novo produto na memória dinâmica

  cout << pink_color << "============" << endl << reset_color;
  cout << "Novo produto" << endl;
  cout << pink_color << "============" << endl << reset_color;
  cout << endl << "Insira o código do produto: ";
  cin >> novoProduto->Codigo;
  if (busca_produto(novoProduto->Codigo, busca, pos) != -1) {
    return false;
  } else {
    cout << "Insira nome do produto: ";
    cin.ignore(); // Ignora o caractere de nova linha pendente no buffer
    // Lê o nome do produto, permitindo espaços em branco
    getline(cin, novoProduto->Nome);
    cout << "Insira preço do produto: ";
    cin >> novoProduto->Preco;
    cout << endl;
  }

  return true;
}

int main() {
  int CodigoParaConsulta;
  int Menu;
  ListaE lista;
  int CodigoParaRemover;
  Produto *novoProduto;

  inicializa_lista(lista);
 
  if(!carregar_itens_do_arquivo(lista)){
    cout << "Erro ao carregar os itens do arquivo." << endl;
  }
  
  // Abre um arquivo para escrever a lista de produtos
  ofstream escreve;
  escreve.open("lista_produtos.txt");

  do {
    exibir_lista(lista);
    opcoes_menu(Menu);

    if (Menu <= 0 || Menu > 4) {
      cout << "\nNúmero inválido, selecione uma opção válida.\n\n";
      // Evitar erros na hora de escolher a opção do menu
    }

    switch (Menu) {
    case 1: // Inserir novo produto
      limpar();
      if (insere_produto(lista, novoProduto)) {
        inserir(lista, novoProduto);
        escreve << lista.inicio->Codigo << lista.inicio->Nome
                << lista.inicio->Preco;
      } else {
        cout << pink_color << endl
             << "Código já cadastrado!" << endl
             << reset_color;
      }
      pressione_enter();
      break;
    case 2: // Eliminar produto
      limpar();
      cout << "Insira o código do produto a ser removido: ";
      cin >> CodigoParaRemover;
      // Remove o produto da lista e salva no arquivo
      if (remover(lista, CodigoParaRemover)) {
        cout << endl
             << blue_color << "Produto removido com sucesso!" << reset_color
             << endl;
     
      } else {
        cout << endl << purple_color << "Produto não encontrado." << reset_color << endl;
      }
      pressione_enter();
      break;
    case 3: // Consulta de produto
      limpar(); // Limpa a tela do console para uma apresentação mais organizada
      Produto *busca = lista.inicio;
      cout << "Insira o código do produto para consulta: ";
      cin >> CodigoParaConsulta; 
      // Realiza a consulta do produto e exibe suas informações
      if (consulta_produto(lista, CodigoParaConsulta, busca)) {
        cout << green_color << "============" << endl << reset_color;
        cout << "Nome: " << busca->Nome << endl;
        cout << "Preço: " << busca->Preco << endl;
        cout << green_color << "============" << endl << reset_color;
      } else {
        cout << endl << purple_color << "Produto não encontrado." << reset_color << endl;
      }
      pressione_enter();
      break;
    }

  } while (Menu != 4);

  // Fecha o arquivo de escrita
  escreve.close();
  if (!salvar_no_arquivo(lista)) {
    cout << "Erro ao salvar itens no arquivo." << endl;
    return 1;
  }

   limpar();

  return 0;
}
