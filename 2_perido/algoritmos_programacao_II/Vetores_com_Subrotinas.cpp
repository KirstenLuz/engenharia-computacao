// Lista de exercícios - vetores com subrotinas
#include <iostream>
using namespace std;
#include <locale.h>

/* Exercicio 1
#define TAM 10

void leitura(int vet[]){
  int i;
  for (i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

float media(int vet[]){
  float media = 0;
  for (int i = 0; i < TAM; i++){
    media += vet[i];
  }
  media /= TAM;
  return (media);
}

int maior(int vet[]){
  int valor_maior = vet[0];
  for(int i = 1; i < TAM; i++){
    if(vet[i] > valor_maior){
      valor_maior = vet[i];
    } 
  }
  return (valor_maior);
}

int menor (int vet[]){
  int valor_menor = vet[0];
  for(int i = 1; i < TAM; i++){
    if(vet[i] < valor_menor){
      valor_menor = vet[i];
    } 
  }
  return (valor_menor);
}

int main (){
  int vet[TAM];

  cout << "Digite os valores para o vetor: ";

  leitura(vet);

  cout << "A média dos valores no vetor é: " << media(vet);
  cout << "\nO maior valor do vetor é: " << maior(vet);
  cout << "\nO menor valor do vetor é: " << menor(vet);
  
  return 0;
}

Declare um vetor de 10 inteiros no main, crie uma função para fazer a leitura do vetor. Na 
sequência faça outras três funções para calcular a média, o menor e o maior valor contidos no 
vetor. Exiba os valores da média, menor e maior no main
*/

/* Exercício 2
#define TAM 10

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

float media(int vet[]){
  float media_alunos = 0;
  for (int i = 0; i < TAM; i++){
    media_alunos += vet[i];
  }
  media_alunos /= TAM;

  return(media_alunos);
}

int superior(int vet[], float valor){
  int notas_superiores = 0;
  for (int i = 0; i < TAM; i++){
    if(vet[i] >= valor){
      notas_superiores++;
    }
  }
  return (notas_superiores);
}

int main(){
  int notas[TAM];
  float media_dos_alunos = 0;

  cout << "Digite a nota dos alunos: ";
  leitura(notas);

  media_dos_alunos = media(notas);
  
  cout << "A média dos alunos é: " << media_dos_alunos;
  cout << "\nA quantidade de alunos acima da média é: " << superior(notas, media_dos_alunos);
    
  return 0; 
}


Crie uma função para fazer a leitura das notas de 10 alunos e adicioná-las no vetor. Crie 
uma função para calcular a média das notas de 10 alunos de uma disciplina e em outra função 
verifique o número de alunos que tiveram nota superior à média calculada. Exiba a quantidade 
de alunos com nota superior à média no main
*/

/* Exercicio 3
#define TAM 5

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

int maior(int vet[], int valor){
  int valores_maiores = 0;
  for(int i = 1; i < 5; i++){
    if(vet[i] > valor){
      valores_maiores++;
    }
  }
  return(valores_maiores);
}

int menor(int vet[], int valor){
  int valores_menores = 0;
  for(int i = 1; i < 5; i++){
    if(vet[i] < valor){
      valores_menores++;
    }
  }
  return(valores_menores);
}

int igual(int vet[], int valor){
  int valores_iguais = 0;
  for(int i = 1; i < 5; i++){
    if(vet[i] == valor){
      valores_iguais++;
    }
  }
  return(valores_iguais);
}

int main(){
  int vet[TAM], primeiro_valor;

  cout << "Digites cinco valores inteiros: ";
  leitura(vet);

  primeiro_valor = vet[0];

  cout << maior(vet, primeiro_valor) << " valor(es) maior(es) que " << primeiro_valor << " no vetor\n";

  cout << menor(vet, primeiro_valor) << " valor(es) menor(es) que " << primeiro_valor << " no vetor\n";

  cout << igual(vet, primeiro_valor) << " valor(es) igual(is) que " << primeiro_valor << " no vetor\n";

  return 0;
}

Declare um vetor de 5 inteiros, leia um valor para cada posição. Crie uma função que
verifique quantos elementos possuem valor maior, menor e igual ao primeiro elemento do 
vetor. Mostre a quantidade de valores maiores, menores e iguais no main
*/

/* Exercicio 4
#define TAM 10

void leitura(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void inversa(int vet[]){
  for(int i = TAM - 1; i >= 0; i--){
    cout << vet[i] << " ";
  }
}

int main(){
  int vet[TAM], vet_inverso[TAM];

  cout << "Digite dez valores inteiros: ";
  leitura(vet);

  inversa(vet);

  return 0;
}


Declare um vetor de 10 inteiros, leia um valor para cada posição. Crie uma função que
mostre os elementos deste vetor em posição inversa ao que foram atribuídos
*/

// Exercicio 5
#define TAM 20

void leituraA(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void leituraB(int vet[]){
  for(int i = 0; i < TAM; i++){
    cin >> vet[i];
  }
}

void imprimirC(int vetA[], int vetB[]){
  int vetC[TAM];
  cout << "Vetor C: ";
  for(int i = 0; i < TAM; i++){
    vetC[i] = vetA[i] - vetB[i];
    cout << vetC[i] << " ";
  }
}

int main(){
  int vetA[TAM], vetB[TAM];

  cout << "Digite 20 valores para A: ";
  leituraA(vetA);

  cout << "Digite 20 valores para B: ";
  leituraA(vetB);

  imprimirC(vetA, vetB);

  return 0;
}
/* 
Leia dois vetores A e B com vinte elementos e declare um terceiro vetor C. Faça uma função
que calcule cada elemento de C com a subtração do elemento correspondente de A com B.
Exiba o vetor C no main
*/
