#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

#define blue_color "\033[0;34m"
#define reset_color "\033[0m"

// Estrutura do produto
struct Produto {
  int Codigo;
  string Nome;
  float Preco;
  Produto *proximo;
};

// Estrutura da lista
struct ListaE {
  Produto *inicio;
};

// Inicializa lista
bool inicializa_lista(ListaE &lista) {
  lista.inicio = NULL;
  return true;
}
bool salvar_no_arquivo(ListaE &lista) {
  // Cria um objeto ofstream para escrever no arquivo "lista_produtos.txt"
  ofstream arquivo("lista_produtos.txt", ios::out);

  // Verifica se o arquivo foi aberto corretamente
  if (arquivo.is_open()) {
    // Inicializa um ponteiro para percorrer a lista, começando pelo início
    Produto *atual = lista.inicio;

    // Percorre a lista e escreve os dados de cada produto no arquivo
    while (atual != NULL) {
      arquivo << atual->Codigo << " " << atual->Nome << " " << atual->Preco << endl;
      atual = atual->proximo; // Move para o próximo produto na lista
    }

    arquivo.close(); // Fecha o arquivo após escrever todos os produtos
    return true; // Indica que a operação foi bem-sucedida
  } else {
    return false; // Indica que houve um erro ao abrir o arquivo
  }
}

//insere um novo produto na lista
void inserir(ListaE &lista, Produto *novoProduto) {
  novoProduto->proximo = lista.inicio;
  lista.inicio = novoProduto;
 
}



// int busca_produto(const ListaE &lista, int codigo) {
//    // Inicializa um ponteiro para percorrer a lista, começando pelo início
//   Produto *atual = lista.inicio;
//   // Inicializa a posição como 0 (primeira posição na lista)
//   int pos = 0;
//   // Percorre a lista enquanto houver produtos na lista (ponteiro não é nulo)
//   while (atual != NULL) {
//     // Verifica se o código do produto atual é igual ao código procurado
//     if (atual->Codigo == codigo) {
//       // Se sim, retorna a posição onde o produto foi encontrado
//       return pos;
//     }
//     // Incrementa a posição e move o ponteiro para o próximo produto na lista
//     pos++;
//     atual = atual->proximo;
//   }
//   // Se o código não foi encontrado em nenhum produto da lista, retorna -1
//   return -1;
// }

int busca_produto(const ListaE &lista, int codigo, Produto *atual, int pos) {
  // Verifica se o ponteiro atual é nulo, indicando o final da lista
  if (atual == NULL) {
    return -1; // Retorna -1 para indicar que o produto não foi encontrado na lista
  }
  // Verifica se o código do produto atual é igual ao código procurado
  if (atual->Codigo == codigo) {
    return pos; // Retorna a posição do produto se encontrado
  }
  // Chama recursivamente a função para o próximo produto na lista
  return busca_produto(lista, codigo, atual->proximo, pos + 1);
}

bool remover(ListaE &lista, int codigo) {
  Produto *busca = lista.inicio;
  // Inicializa a posição como 0 (primeira posição na lista)
  int pos = 0;
  // Inicializa ponteiros para percorrer a lista
  Produto *atual = lista.inicio;
  Produto *anterior = NULL;
  
  // Verifica se o produto com o código desejado está na lista
  if (busca_produto(lista, codigo, busca, pos) != -1) {
    // Percorre a lista até encontrar o produto com o código desejado
    for (int i = 0; i < busca_produto(lista, codigo, busca, pos); i++) {
      anterior = atual;
      atual = atual->proximo;
    }
    // Verifica se o produto foi encontrado
    if (atual != NULL) {
      // Verifica se o produto foi encontrado
      if (anterior != NULL) {
        anterior->proximo = atual->proximo;
      } else {
        // Se for o primeiro da lista, atualiza o início da lista
        lista.inicio = atual->proximo;
      }
      // Libera a memória ocupada pelo produto removido
      delete atual;
     // salvar_no_arquivo(lista);
      return true;
    }
  } else {
    return false;
  }
  return true;
}

bool consulta_produto(const ListaE &lista, int codigo, Produto *&busca) {
  Produto *atual = lista.inicio;
   // Inicializa a posição como 0 (primeira posição na lista)
    int pos = 0;
  // Verifica se o produto com o código desejado está na lista
  if (busca_produto(lista, codigo, atual, pos) != -1) {
    // Percorre a lista até encontrar o produto com o código desejado
    for (int i = 0; i < busca_produto(lista, codigo, atual, pos); i++) { 
      busca = busca->proximo;
    }
    return true; //Se foi encontrado
  }  else {
    return false; //Se nao foi encontrado
   }
  
}

void exibir_lista(const ListaE &lista) {
  // Inicializa um ponteiro para percorrer a lista, começando pelo início
  Produto *atual = lista.inicio;
  cout << blue_color << "=================" << endl
       << reset_color;
  cout << "Lista de produtos" << endl;
  cout << blue_color
       << "=================" << endl
       << reset_color;
  // Percorre a lista enquanto houver produtos (ponteiro não é nulo)
  while (atual != NULL) {
    cout << endl
         << "Código " << atual->Codigo << endl
         << "- Nome: " << atual->Nome << endl
         << "- Preço: " << atual->Preco << endl;
    // Move o ponteiro para o próximo produto na lista
    atual = atual->proximo;
  }
  cout << endl;
}

bool carregar_itens_do_arquivo(ListaE &lista) {
  // Cria um objeto ifstream para ler do arquivo "lista_produtos.txt"
  ifstream arquivo("lista_produtos.txt");

  // Verifica se o arquivo foi aberto corretamente
  if (arquivo.is_open()) {
    // Limpa a lista atual
    // while (lista.inicio != nullptr) {
    //   Produto *temp = lista.inicio;
    //   lista.inicio = lista.inicio->proximo;
    //   delete temp;
    // }

    // Lê os dados do arquivo e cria a lista
    int codigo;
    string nome;
    string preco_str; // leitura do preço como string

    // Use getline para garantir a leitura correta do nome (considerando espaços)
    while (arquivo >> codigo) {
      arquivo.ignore(); // Ignora o espaço após o código
      getline(arquivo, nome);
      getline(arquivo, preco_str);

      // Converte a string para um valor de ponto flutuante
      float preco = stof(preco_str);

      Produto *novoProduto = new Produto{codigo, nome, preco, nullptr};
      inserir(lista, novoProduto);
    }

    arquivo.close(); // Fecha o arquivo após ler todos os produtos
    return true; // Indica que a operação foi bem-sucedida
  } else {
    return false; // Indica que houve um erro ao abrir o arquivo
  }
}


/******* void carregar_do_arquivo(ListaE &lista) {
  ifstream arquivo("lista_produtos.txt");

  if (arquivo.is_open()) {
    int codigo;
    string nome;
    float preco;

    while (arquivo >> codigo >> nome >> preco) {
      Produto *novoProduto = new Produto{codigo, nome, preco, nullptr};
      inserir(lista, novoProduto);
    }

    arquivo.close();
  }
}
*******/


#endif // LIB_H_INCLUDED
