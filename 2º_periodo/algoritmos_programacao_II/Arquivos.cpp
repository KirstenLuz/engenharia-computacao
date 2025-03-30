// Arquivos
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

/* Exemplo 1 - Escrevendo em um arquivo
int main() {
  string frase;

  cout << "Escreva uma frase para ser escrita no arquivo string.txt: ";
  cin >> frase;
  cout << "Obrigado. Escrevendo dados no arquivo string.txt... \n";

  ofstream escreve;
  escreve.open("Strings.txt");
  escreve << "Utilizamos os objetos ofstream para escrever em arquivos\n";
  escreve << "Nota que podemos utilizar os caracteres \\n pra quebrar linha, como no cout\n";

  int numero = 100;
  escreve << "Podemos escrever o valor de variáveis numéricas: " << numero << "\n";

  escreve << "\n";
  escreve << "Finalmente, podemos receber dados via cin e escrever esses dados nos arquivos!\n";
  escreve << "A frase que você digitou durante a execução do programa: " << frase << "\n";

  escreve.close();
  cout << "Dados escritos no arquivo. Fim do programa!";
  
  return 0;
}
*/

// Exemplo 2 - Lendo um arquivo

int main(){
  int dia, mes;
  char letra[1000];
  cout << "PROGRAMA AGENDA VERSÃO 0.00042\n";

  ofstream agenda;
  agenda.open("agenda.txt", ofstream::app);
  cout << "Digite o compromisso no espaço abaixo (): \n"
}
