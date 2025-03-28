// Recursividade
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

/* Função não recursiva - fatorial *
void leitura (int &num){
  do {
    cout << "Digite um número: ";
    cin >> num;
    if(num <= 0){
      cout << "Valor inválido! Digite novamente. " << endl;
    }
  } while(num <= 0);
}

int fatorial (int num){
  int i, fat = 1;

  for(i = 1; i <= num; i++){
    fat = fat * i;
  }

  return (fat);
}

int main() {
  int numero;

  leitura(numero);

  cout << "Fatorial de " << numero << ": " << fatorial(numero);

  return 0;
}
*/

/* Função recursiva - fatorial
void leitura (int &num){
  do {
    cout << "Digite um número: ";
    cin >> num;
    if(num <= 0){
      cout << "Valor inválido! Digite novamente. " << endl;
    }
  } while(num <= 0);
}

int fatorial (int num){
  if(num <= 1){
    return 1;
  }
  return (num * fatorial(num - 1));
}

int main(){
  int numero;

  leitura(numero);

  cout << "Fatorial de " << numero << ": " << fatorial(numero);

  return 0;
}
*/

/* Função não recursiva - fibonacci
void leitura(int &posicao){
  do {
    cout << "Posição: ";
    cin >> posicao;
    if(posicao <= 0){
      cout << "Posição inválida! Digite novamente." << endl;
    }
  } while (posicao <= 0);
}

int fibonacci(int posicao){
  int i, ante = 1, penu = 1, prox;
  for(i = 1; i < posicao; i++){
    prox = ante + penu;
    ante = penu;
    penu = prox;
  }
  return ante;
}

int main(){
  int posicao;

  leitura(posicao);
  cout << endl << "Elemento de posição " << posicao << ": " <<
fibonacci(posicao);

  return 0;
}
*/

// Função recursiva - fibonacci
void leitura(int &posicao) {
  do {
    cout << "Posição: ";
    cin >> posicao;
    if (posicao <= 0) {
      cout << "Posição inválida! Digite novamente." << endl;
    }
  } while (posicao <= 0);
}

int fibonacci(int posicao) {
  if (posicao <= 2) {
    return 1;
  }
  return (fibonacci(posicao - 1) + fibonacci(posicao - 2));
}

int main() {
  int posicao;

  leitura(posicao);
  cout << endl
       << "Elemento de posição " << posicao << ": " << fibonacci(posicao);

  return 0;
}
