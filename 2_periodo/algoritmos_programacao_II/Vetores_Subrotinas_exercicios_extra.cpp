#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

/* Exercicio 1
Declare um vetor de 10 inteiros, leia um valor para cada posição. Calcule o fatorial do maior 
e do menor valor contidos no vetor usando função

#define TAM 5

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

int maior(int vet[]){
  int i, maior = vet[0];
  for(i = 1; i < TAM; i++){
    if(vet[i] > maior)
      maior = vet[i];
  }

  return(maior);
}

int menor(int vet[]){
  int i, menor = vet[0];
  for(i = 1; i < TAM; i++){
    if(vet[i] < menor)
      menor = vet[i];
  }

  return(menor);
}

int fatorial(int numero){
  int resultado = 1;
  for(int i = 1; i <= numero; i++){
    resultado *= i;
  }
  return(resultado);
}

int main() {
  int vet[TAM], valor_maior, valor_menor;

  cout << "Digite dez valores para o vetor: ";
  leitura(vet);

  valor_maior = maior(vet);
  valor_menor = menor(vet);

  cout << "Fatorial do maior valor do vetor: " << fatorial(valor_maior);
  cout << "\nFatorial do menor valor do vetor: " << fatorial(valor_menor);
  
  return 0;
}
*/


/* Exercicio 2
Construa um algoritmo que solicite 5 valores inteiros ao usuário e os armazene em um 
vetor. Na sequência, faça uma função que inverta os valores do vetor utilizando um segundo 
vetor


#define TAM 5

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void invertido(int vet[]){
  for(int i = TAM-1; i >= 0; i--){
    cout << vet[i] << " ";
  }
}

int main(){
  int vet[TAM];

  cout << "Digite 5 valores para o vetor: ";
  leitura(vet);

  cout << "Vetor invertido: ";
  invertido(vet);

  return 0;  
}
*/

/* Exercicio 3
Leia 30 valores em um vetor e em uma função jogue os pares em um vetor e os ímpares em 
outro. Após a distribuição faça uma função para calcular o somatório dos dois vetores. Exiba o 
vetor de maior valor no main


#define TAM 30
#define MET (TAM/2)

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void distribuicao(int vet[], int vetor_par[], int vetor_impar[]){
  for(int i = 0, p = 0, im = 0; i < TAM; i++){
    if(vet[i] % 2 == 0){
      vetor_par[p] = vet[i];
      p++;
    } else {
      vetor_impar[im] = vet[i];
      im++;
    }
  }
}

void imprimir(int vet[]){
for(int i = 0; i < MET; i++){
  cout << vet[i] << " ";
  }
}

int soma(int somatorio[]){
  int soma_vetor = 0;
  for(int i = 0; i < MET; i++){
    soma_vetor += somatorio[i];
  }

  return(soma_vetor);
}

int main(){
  int vet[TAM], vetor_par[MET], vetor_impar[MET], soma_par, soma_impar;

  cout << "Digite 30 valores para o vetor: ";
  leitura(vet);

  distribuicao(vet, vetor_par, vetor_impar);

  cout << "Vetor par: ";
  imprimir(vetor_par);
  cout << "\nVetor ímpar: ";
  imprimir(vetor_impar);

  soma_par = soma(vetor_par);
  soma_impar = soma(vetor_impar);
  

  if(soma_par > soma_impar){
    cout << "\nO somátorio do vetor par é maior";
  } else if (soma_impar > soma_par){
    cout << "\nO somatório do vetor ímpar é maior";
  }
  
  return 0;
}
*/

/* Exercicio 4
Faça um programa que leia dois vetores A e B, de tamanho 8. Em uma função realize a troca 
dos elementos destes vetores; ou seja, após a execução da função o vetor B deverá conter os 
valores fornecidos para o vetor A, e vice-versa.


#define TAM 4

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

void troca(int vet_A[], int vet_B[]){
  int auxiliar;
  for(int i = 0; i < TAM; i++){
    auxiliar = vet_A[i]; // a auxiliar recebe o valor de A
    vet_A[i] = vet_B[i]; // depois de guardar o valor dessa posição de A, eu passo o novo valor que é de B
    vet_B[i] = auxiliar; // após trocar o valor de A para B, já posso colocar o valor de A (auxiliar) para B
  }
}

// Aqui a variável serve para trocar o valor de A e B

int main(){
  int vet_A[TAM], vet_B[TAM];

  cout << "Digite o vetor A: ";
  leitura(vet_A);

  cout << "Digite o vetor B: ";
  leitura(vet_B);

  cout << "Vetor A: ";
  imprimir(vet_A);
  
  cout << "\nVetor B: ";
  imprimir(vet_B);

  troca(vet_A, vet_B);

  cout << "\nNovo vetor A: ";
  imprimir(vet_A);
  
  cout << "\nNovo vetor B: ";
  imprimir(vet_B);

  return 0;
}
*/

/* Exercicio 5
Construa um algoritmo que solicite 5 valores ao usuário, armazene estes em um vetor de 5 
posições inteiras. Na sequência, crie uma função que verifique se o número 7 se encontra no 
vetor. Em caso positivo, retorne a posição em que ele foi encontrado. Se ele for encontrado 
mais de uma vez também, obtenha também quantas vezes ele foi encontrado

#define TAM 5

void leitura(int vetor[]){
  for(int i = 0; i < TAM; i++){
    cin >> vetor[i];
  }
}

void sete(int vetor[]){
  int i, j = 0;
  cout << "O número 7 está nas posições: ";
  for(i = 0; i < TAM; i++){
    if(vetor[i] == 7){
      cout << i+1 << " ";
      j++;
    }
  }
  if(j > 0){
      cout << "\nEle apareceu " << j << " vez(es) no vetor.";
    }
}

int main(){
  int vetor[TAM];

  cout << "Digite os valores do vetor: ";
  leitura(vetor);

  sete(vetor);

  return 0;
}
*/

/* Exercicio 6
Faça uma função que preencha um vetor de 10 posições com valores gerados (utilize o rand), e garanta que não haja números repetidos. Mostre o vetor gerado no main.
#include <time.h>
srand(time(NULL)) -- inicio do main
rand() % 9+1 -- quando for usar
*/

#define TAM 10

void leitura(int vet[TAM]){
  for(int i = 0; i < TAM; i++){
    vet[i] = rand() % 9 + 1;
    for(int j = 0; j < i; j++){
       if(vet[j] == vet[i]){
         vet[i] = rand() % TAM + 1;
    }
  }
}

void imprimir(int vet[TAM]){
  for(int i = 0; i < TAM; i++){
    cout << vet[i] << "  ";
  }
}

int main(){
  srand(time(NULL));
  int vet[TAM];

  leitura(vet);

  imprimir(vet);
  
  return 0;
}
