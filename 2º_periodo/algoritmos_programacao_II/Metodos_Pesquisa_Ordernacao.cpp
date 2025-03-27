// Métodos de pesquisa e ordenação
#include <iostream>
using namespace std;
#include <locale.h>

/* Pesquisa sequencial (faz a pesquisa em sequência pelo vetor)
#define TAM 10

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimir(int vet[]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << " ";
  }
}

// Aqui ele faz a pesquisa por todo o vetor e compara com o if caso seja igual a chave dada
nos parâmetros fica (tamanho do vetor, o vetor em si, a chave)

int pesquisaSequencial(int tam, int vet[], int p){
  for(int i = 0; i < tam; i++){
    if(vet[i] == p){
      return(i+1);
    }
  }
  return -1;
}

int main() {
  int vet[TAM], numero;

  cout << "Digite os valores do vetor: ";
  leitura(vet);
  imprimir(vet);

  cout << "\nDigite o número que você quer achar no vetor: ";
  cin >> numero;

  cout << "O número " << numero << " está na posição: " << pesquisaSequencial(TAM, vet, numero);

  return 0;
}
*/

/* Pesquisa binária (usada quando o vetor está em ordem crescente e não há inserção ou remoção de elementos)
#define TAM 6

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimir(int vet[]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << " ";
  }
}

// aqui a função vai dividindo o vetor pela metade, e como considera o vetor em ordem crescente, torna mais fácil encontrar a chave
int pesquisaBinaria(int tam, int vet[], int p){
  int inf = 0;
  int sup = tam - 1;
  int meio;
  while(inf <= sup){
    meio = (inf + sup) / 2;
    if(p == vet[meio])
      return meio+1;
    else
      if(p < vet[meio])
        sup = meio - 1;
      else
        inf = meio + 1;
  }
  return -1;
}

int main(){
  int vet[TAM], numero;

  cout << "Digite os valores do vetor: ";
  leitura(vet);
  imprimir(vet);

  cout << "\nDigite o número que você quer achar no vetor: ";
  cin >> numero;

  cout << "O número " << numero << " está na posição: " << pesquisaBinaria(TAM, vet, numero);

  return 0;
*/

// Métodos de ordenação 

/* bolha (BubbleSort) 
#define TAM 8

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimir(int vet[]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << "  ";
  }
}

void bubblesort(int vet[], int n){
  int i, j, cond, temp;
  cond = 1;
  for(i = n-1; (i >= 1) && (cond == 1); i--){
    cond = 0;
    for(j = 0;j < i; j++){
     if(vet[j+1] < vet[j]){
       temp = vet[j];
       vet[j] = vet[j+1];
       vet[j+1] = temp;
       cond = 1;
      } 
    }
  }
}

int main(){
  int vet[TAM];

  cout << "Digite os valores do vetor: ";
  leitura(vet);

  cout << endl;
  imprimir(vet);
  cout << endl;
  bubblesort(vet, TAM);
  cout << endl;
  imprimir(vet);
  
  return 0;
}
*/
  
/* seleção (Selection Sort) 
#define TAM 8

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimir(int vet[]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << "  ";
  }
}

void selection_sort(int num[], int tam){
  int i, j, min;
  for(i = 0; i < (tam-1); i++){
    min = i;
    for(j = (i + 1); j < tam; j++){
      if(num[j] < num[min]){
        min = j;
      }
    }
    if(i != min){
      int swap = num[i];
      num[i] = num[min];
      num[min] = swap;
    }
  }
}

int main(){
  int vet[TAM];

  cout << "Digite os valores do vetor: ";
  leitura(vet);

  cout << endl;
  imprimir(vet);
  cout << endl;
  selection_sort(vet, TAM);
  cout << endl;
  imprimir(vet);
  
  return 0;
}
*/

/* inserção (Insertion Sort) */

#define TAM 8

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimir(int vet[]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << "  ";
  }
}

void insertion(int vetor[], int n){
  int j, i, key;
  for(j = 1; j < n; j++){
    key = vetor[j];
    i = j - 1;
    while(i >= 0 && vetor[i] > key){
      vetor[i + 1] = vetor[i];
      i = i - 1;
    }
    vetor[i + 1] = key;
  }
}

int main(){
  int vet[TAM];

  cout << "Digite os valores do vetor: ";
  leitura(vet);

  cout << endl;
  imprimir(vet);
  cout << endl;
  insertion(vet, TAM);
  cout << endl;
  imprimir(vet);
  
  return 0;
}
