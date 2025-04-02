// Lista de exercícios - Alocação dinâmica de matrizes
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

/* Exercício 1 
Utilizando alocação dinâmica, faça um programa que preencha uma matriz de MXN (onde M e N são valores fornecidos pelo usuário) com o elemento um em todas as posições

int main(){
  int m, n; // m = linha e n = coluna

  cout << "Digite os valores de linhas e colunas da matriz: ";
  cin >> m >> n;

  int **p = new int*[m];

  for(int i = 0; i < m; i++){
    p[i] = new int[n];
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      p[i][j] = 1;
    }
  }

  cout << "Matriz: " << endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << p[i][j] << "\t";
    }
    cout << endl;
  }

  for(int i = 0; i < m; i++){
    delete p[i];
  }

  delete []p;

  return 0;
}
*/

/* Exercício 2 
Utilizando alocação dinâmica, faça um programa que preencha uma matriz de MXN (onde M e N são valores fornecidos pelo usuário) com o elemento um em todas as posições em que o índice de linha tem valor igual ao da coluna.


int main(){
  int m, n;

  cout << "Digite o valor de linhas e colunas: ";
  cin >> m >> n;

  int **p = new int*[m];

  for(int i = 0; i < m; i++){
    p[i] = new int[n];
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(j == i)
        p[i][j] = 1;
      else
        p[i][j] = 0;
    }
  }

  cout << "Matriz: " << endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << p[i][j] << "\t";
    }
  cout << endl;
  }

  for(int i = 0; i < m; i++){
    delete p[i];
  }

  delete[] p;
    
  return 0;
}
*/

/* Exercício 3 
Utilizando alocação dinâmica e aritmética de ponteiros, faça um programa que solicita ao usuário M*N valores reais e armazene em uma matriz MXN (onde N e M são valores fornecidos pelo usuário). A seguir troque todos os elementos da matriz que sejam maiores do que 100 pelo valor zero. Exiba a matriz original e alterada

int main(){
  srand(time(NULL));
  int m, n;

  cout << "Digite o valor de m e n: ";
  cin >> m >> n;

  int **p = new int*[m];

  for(int i = 0; i < m; i++){
    p[i] = new int[n];
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      p[i][j] = rand() % 200 + 1;
    }
  }
  
  cout << endl << "Matriz original: " << endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << p[i][j] << "\t";
    }
    cout << endl;
  }

  cout << endl << "Matriz alterada: " << endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(p[i][j] > 100){
        p[i][j] = 0;
        cout << p[i][j] << "\t";
      } else {
        cout << p[i][j] << "\t";
      }
    }
    cout << endl;
  }

  for(int i = 0; i < m; i++){
    delete p[i];
  }

  delete[] p;

  return 0;
}
*/

/* Exercício 4 
Utilizando alocação dinâmica e aritmética de ponteiros, faça um programa que preencha uma matriz de NXN (onde N é um valor fornecido pelo usuário) com o elemento um em todas as posições em que o índice de linha tem valor maior que o da coluna.


int main(){
  srand(time(NULL));
  int n;

  cout << "Digite o valor de linhas e colunas: ";
  cin >> n;

  int **p = new int*[n];

  for(int i = 0; i < n; i++){
    p[i] = new int[n];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i > j){
        p[i][j] = 1;
      } else {
        p[i][j] = rand() % 10 + 1;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << p[i][j] << "\t";
    }
  cout << endl;
  }

  for(int i = 0; i < n; i++){
    delete p[i];
  }

  delete[] p;

  return 0;
}
*/

/* Exercício 5 
Utilizando alocação dinâmica e aritmética de ponteiros, faça um programa que manipula uma matriz quadrada NxN (onde N é um valor fornecido pelo usuário), somando os valores que não estão nem na diagonal principal nem na diagonal secundaria.
*/

int main(){
  int n;

  cout << "Digite o valor de n: ";
  cin >> n;

  int **p = new int*[n];

  for(int i = 0; i < n; i++){
    p[i] = new int[n];
  }

  
}
