#include <iostream>
using namespace std;

// Exemplo 1
/*
int main() {
  int vet[10];
  // criei um vetor com o nome vet e disse que ele possui 10 elementos
  int *ponteiro, i;
  // criei um ponteiro
  
  ponteiro = vet;
  // aqui eu disse que o ponteiro aponta para o vet, pois o nome dado ao vetor é como se fosse um ponteiro que aponta para endereço do primeiro elemento da alocação de memória que é o vetor

  for(i = 0; i < 10; i++){
    ponteiro[i] = i * 2;
  }
  // quando um ponteiro aponta para um vetor, nós podemos utilizar o operador de acesso de vetor com o ponteiro, e o ponteiro também pode ser utilizado como índice para o vetor, ele passa a ter a mesma função que o nome do vetor criado

  for(i = 0; i < 10; i++){
    cout << vet[i] << " ";
  }

  return 0;
}
*/

// Exemplo 2
/*
int main() {
  int tam, i;

  cout << "Tamanho: ";
  cin >> tam;
  // defini o tamanho que eu queria que meu vetor tivesse

  float *vet;
  // criei um ponteiro
  vet = new float[tam];
  // defini que o ponteiro aponta para um vetor sem identidade com o tamanho lido, o ponteiro criado e o vetor devem ser do mesmo tipo

  for(i = 0; i < tam; i++){
    cin >> vet[i];
  }
  // atribuí valores aos elementos do vetor sem identidade

  for(i = 0; i < tam; i++){
    cout << vet[i] << " ";
  }
  // imprimi esses valores usando o ponteiro

  delete []vet;
  

  return 0;
}
*/

// Exemplo 3
/* funciona ler o tamanho após criar o vetor sem identidade
int main(){
  int *p, tam;

  p = new int[tam];

  cout << "Digite um tamanho: ";
  cin >> tam;

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < tam; i++){
    cin >> p[i];
  }

  for(int i = 0; i < tam; i++){
    cout << p[i] << " ";
  }

  return 0;
}
*/

// Exemplo 4
/*
int* dobro (int a[], int tam){
  // criei uma função que possui o retorno de um endereço
  int *temp = new int[tam];
  // criei um ponteiro ao mesmo tempo que digo que ele aponta para um vetor sem identidade
  int i;

  for(i = 0; i < tam; i++){
    temp[i] = 2 * a[i];
  }
  // atribuí o dobro de cada elemento do vetor ao vetor criado com o ponteiro

  return temp;
  // retornei o endereço apontado pelo ponteiro temp, que é o primeiro elemento do vetor sem identidade
}

// Perguntas:
// 1. Por que ao criar a função usou-se o * na variável de retorno?
// O uso do * na declaração da função int* dobro(...) indica que a função retorna um ponteiro para um inteiro. Nesse caso, a função aloca dinamicamente um array de inteiros e retorna o endereço do primeiro elemento desse array. Isso é útil quando você deseja criar um novo array de inteiros na função e retorná-lo para uso posterior.

// 2. Por que ao passar o vetor de parâmetro não foi necessário passar o tamanho do vetor?
// O tamanho do vetor não precisa ser passado explicitamente como um argumento porque, em C/C++, um vetor não armazena seu tamanho junto com seus elementos. Em vez disso, a função usa o parâmetro tam para determinar o tamanho do vetor. O tamanho é passado como um argumento quando você chama a função.

// 3. Qual a diferença em declar *temp = new int[tam] e temp = new int[tam]?
// A declaração int *temp = new int[tam] declara uma variável temp que é um ponteiro para um inteiro e, em seguida, aloca dinamicamente um array de inteiros e faz com que temp aponte para o primeiro elemento desse array.
// A declaração temp = new int[tam] assume que temp já é um ponteiro para um inteiro e, em seguida, aloca dinamicamente um array de inteiros, fazendo com que o ponteiro temp aponte para o primeiro elemento desse array. Essa forma é útil quando você já possui um ponteiro e deseja realocá-lo para apontar para uma nova área de memória alocada dinamicamente.

// 4. O retorno dessa função será o endereço que temp está apontando ou o valor dentro desse endereço?
// A função dobro retorna o endereço da primeira posição do array de inteiros que foi alocado dinamicamente na função. Portanto, o valor retornado pela função é um ponteiro para inteiros que aponta para o primeiro elemento desse array. Você pode acessar os valores do array usando esse ponteiro.


int main(){
  int a[] = {1,2,3,4,5};
  int *b, i, tam = 5;

  // aqui eu disse que o ponteiro está apontando para o endereço que retornará da função dobro
  b = dobro(a, tam);

  cout << "Vetor A" << endl;
  for(i = 0; i < tam; i++){
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "Vetor B" << endl;
  for(i = 0; i < tam; i++){
    cout << b[i] << " ";
  }

  delete [b];

  return 0;
}
*/

int main(){
  int vetor[] = {10, 20, 30, 40};
  int *pvetor =  vetor;

  for(int i = 0; i < 4; i++){
    cout << *(pvetor+i) << endl;
  }
  
  for(int i = 0; i < 4; i++){
    cout << *pvetor++ << endl;
  }
  return 0;
}
