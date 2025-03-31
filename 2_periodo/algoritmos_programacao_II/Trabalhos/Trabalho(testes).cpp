#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

#define BG_COLOR_CODE  "\033[48;5;"
#define RESET_COLOR    "\033[0m"

void setBackgroundColor(int colorCode) {
    std::cout << BG_COLOR_CODE << colorCode << "m";
}

void imprimir(int mat[5][5]){
   for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      std::cout << mat[i][j] << "\t";
    }
     std::cout << std::endl;
  }
}

void imprimir_colorido(int numero){
  setBackgroundColor(128);
  std::cout << numero;
  std::cout << RESET_COLOR;
}

void numeros_sorteados(int vet[], int n){
  int i, j, troca, cond;
  cond = 1;
  for(i = n-1; (i >= 1) && (cond == 1); i--){
    cond = 0;
    for(j = 0;j < i; j++){
     if(vet[j+1] < vet[j]){
       troca = vet[j];
       vet[j] = vet[j+1];
       vet[j+1] = troca;
       cond = 1;
      } 
    }
  }
  std::cout << "Números já sorteados: ";
  for(i = 0; i < n; i++){
    std::cout << vet[i] << " ";
  }
  std::cout << std::endl;
}


// verdadeiro ou falso
// bool verificando(int numero, int vet[]){
//   for(int k = 0; k < 10; k++){
//     if(numero == vet[k])
//       return true;
//   }
//   return false;
// }

// função que compara o número sorteado com as cartelas
// void comparacao_cartelas(int tam, int mat[5][5], int vet[]){
//     for(int i = 0; i < tam; i++){
//       for(int j = 0; j < tam; j++){
//         if(verificando(mat[i][j], vet) == true){
//           setBackgroundColor(128);
//           std::cout << mat[i][j] << "\t";
//           std::cout << RESET_COLOR;
//         } else {
//           cout << mat[i][j] << "\t";
//         }
//     }
//       std::cout << std::endl;
//   }
// }

bool pesquisaBinaria(int tam, int vet[], int p){
  int inf = 0;
  int sup = tam-1;
  int meio;
    while(inf <= sup){
      meio = (inf + sup)/2;
        if (p == vet[meio])
          return true;
        else
        if (p < vet[meio])
          sup = meio-1;
        else
      inf = meio + 1;
    }
  return false;
}

void comparacao(int tam, int mat[5][5], int vet[]){
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
      if(pesquisaBinaria(tam, vet, mat[i][j]) == true){
        setBackgroundColor(128);
          std::cout << mat[i][j] << "\t";
          std::cout << RESET_COLOR;
        } else {
          cout << mat[i][j] << "\t";
        }
      }
    std::cout << std::endl;
  }
}

void sorteio(int vet[], int mat[5][5]){
  int i, j, cond;
  for(i = 0; i < 10; i++){
    vet[i] = rand() % 10 + 1;
    do {
      cond = 1;
      for(j = 0; j < i; j++){
        if(vet[j] == vet[i]){
          vet[i] = rand() % 10 + 1;
          cond = 0;
        }
      }
    } while(cond != 1);
    std::cout << "Número sorteado: " << vet[i] << std::endl;
    // comparacao_cartelas(5, mat, vet);
    comparacao(i, mat, vet);
    numeros_sorteados(vet, i);    
    std:: cout << std::endl;
  }
}


int main (){
  srand(time(NULL));
  
  int vet[10], mat[5][5];
  
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      mat[i][j] = rand() % 10 + 1;
    }
  } 
  
  sorteio(vet, mat);
  return 0;
}

// rosa = 95
// roxo = 128
// setBackgroundColor(128);
// setBackgroundColor(128);
// std::cout << mat[i][j] << "\t";
// std::cout << RESET_COLOR;
