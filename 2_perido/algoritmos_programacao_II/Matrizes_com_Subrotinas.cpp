// Lista de exercícios
#include <iostream>
using namespace std;
#include <locale.h>
#include <time.h>

/* Exercício 1 
Faça uma função que preencha uma matriz de 5X5 com o elemento 
um em todas as posições. Crie também uma função para exibir a 
matriz.

// precisa ter no mínimo o valor da coluna ao declarar a matriz como parâmetro na subrotina 

#define TAM 5

// i = linha, j = coluna

void matriz(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){                                   
      mat[i][j] = 1;
    }
  }
}

void imprimir(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int main() {
  srand(time(NULL));
  int mat[TAM][TAM];

  matriz(mat);

  imprimir(mat);

  return 0;
}
*/

/* Exercício 2
Faça um programa que preencha uma matriz de 5X5 com o 
elemento um em todas as posições em que o índice de linha tem valor 
igual ao da coluna. Crie uma função para exibir a matriz.

#define TAM 5

void matriz(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      if(i == j)
        mat[i][j] = 1;
      else
        mat[i][j] = 0;
    }
  }
}

void imprimir(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(){
  srand(time(NULL));
  int mat[TAM][TAM];
  
  matriz(mat);

  imprimir(mat);

  return 0;
}
*/

/* Exercício 3 
Faça uma função que solicita ao usuário 25 valores reais e armazene 
em uma matriz 5x5. A seguir em outra função troque todos os 
elementos da matriz que sejam maiores do que 100 pelo valor zero.
Crie também uma função para exibir a matriz. No main exiba a matriz 
original e alterada.

#define TAM 5

void matriz(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cin >> mat[i][j];
      // mat[i][j] = rand() % (10*15) + 1;
    }
  }
}

void leitura(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

void troca(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      if(mat[i][j] > 100){
        mat[i][j] = 0;
      }
    }
  }
}

int main (){
  srand(time(NULL));
  int mat[TAM][TAM];

  cout << "Digite os valores da matriz: \n";
  matriz(mat);
  cout << endl;
  
  cout << "Matriz original: \n";
  leitura(mat);
  cout << endl;

  troca(mat);

  cout << "Matriz alterada: \n";
  leitura(mat);
  cout << endl;

  return 0;
}

*/

/* Exercício 4 
Faça uma função que preencha uma matriz de 5X5 com o elemento 
um em todas as posições em que o índice de linha tem valor maior que 
o da coluna. Crie também uma função para exibir a matriz.

#define TAM 5

void matriz(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      if(i > j)
        mat[i][j] = 1;
      else
        mat[i][j] = rand() % (TAM*TAM) + 1;
    }
  }
}

void leitura(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(){
  srand(time(NULL));
  int mat[TAM][TAM];

  matriz(mat);

  leitura(mat);

  return 0;
}
*/

/* Exercicio 5 
Faça uma função que preencha uma matriz quadrada de qualquer 
tamanho. A seguir em outra função realize a soma dos valores que não 
estão nem na diagonal principal nem na diagonal secundaria. Crie 
também uma função para exibir a matriz
*/

#define TAM 4

void matriz(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      if(i > j)
        mat[i][j] = 1;
      else
        mat[i][j] = rand() % (TAM*TAM) + 1;
    }
  }
}

void leitura(int mat[TAM][TAM]){
  int i, j;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
}

int soma(int mat[TAM][TAM]){
  int i, j, auxiliar = 0;
  for(i = 0; i < TAM; i++){
    for(j = 0; j < TAM; j++){
      // condição da diagonal principal e secundária
      if((i != j) && (j != TAM - 1 - i)) {
        auxiliar += mat[i][j];
      }
    }
  }
  return(auxiliar);
}

int main(){
  srand(time(NULL));
  int mat[TAM][TAM];

  matriz(mat);
  cout << endl;
  leitura(mat);
  cout << endl;
  cout << "A soma dos valores da matriz é: " << soma(mat);
  return 0;
}
