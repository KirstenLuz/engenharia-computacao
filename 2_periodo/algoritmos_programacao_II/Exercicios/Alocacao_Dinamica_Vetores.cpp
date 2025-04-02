// Lista de exercícios - Alocação dinâmica de vetores
#include <iostream>
using namespace std;

/* Exercício 1
Utilizando alocação dinâmica, declare um vetor de N inteiros (onde N é um valor fornecido pelo usuário), leia um valor para cada posição e no final mostre a média, o menor e o maior valor contidos no vetor

float media(int tam, int v[]){
  float media_vetor = 0;
  for(int i = 0; i < tam; i++){
    media_vetor += v[i];
  }

  media_vetor /= tam;
  
  return media_vetor;
}

int maior(int tam, int v[]){
  int maior = v[0];

  for(int i = 1; i < tam; i++){
    if(v[i] > maior){
      maior = v[i];
    }
  } 

  return maior;
}

int menor(int tam, int v[]){
  int menor = v[0];

  for(int i = 1; i < tam; i++){
    if(v[i] < menor){
      menor = v[i];
    }
  } 

  return menor;
}

int main() {
  int n;

  cout << "Digite tamanho do vetor: ";
  cin >> n;

  int *v1 = new int[n];

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < n; i++){
    cin >> v1[i];
  }

  cout << "A média do vetor é: " << media(n, v1) << endl;
  cout << "O maior valor do vetor é " << maior(n, v1);
  cout << " e o menor valor do vetor é " << menor(n, v1);

  return 0;
}
*/

/* Exercício 2 
Refaça o exercício anterior utilizando aritmética de ponteiros para manipular o vetor

float media(int tam, int v[]){
  float media_vetor = 0;
  for(int i = 0; i < tam; i++){
    media_vetor += *(v+i); ;
  }

  media_vetor /= tam;

  return media_vetor;
}

int maior(int tam, int v[]){
  int maior = v[0];

  for(int i = 1; i < tam; i++){
    if(v[i] > maior){
      maior = *(v+i); 
    }
  } 

  return maior;
}

int menor(int tam, int v[]){
  int menor = v[0];

  for(int i = 1; i < tam; i++){
    if(v[i] < menor){
      menor = *(v+i); 
    }
  } 

  return menor;
}

int main() {
  int n;

  cout << "Digite tamanho do vetor: ";
  cin >> n;

  int *v1 = new int[n];

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < n; i++){
    cin >> *(v1+i); 
  }

  cout << "A média do vetor é: " << media(n, v1) << endl;
  cout << "O maior valor do vetor é " << maior(n, v1);
  cout << " e o menor valor do vetor é " << menor(n, v1);

  delete []v1;
  
  return 0;
}

*/

/* Exercício 3 
Utilizando alocação dinâmica e aritmética de ponteiros, calcule a média das notas de N alunos (onde N é um valor fornecido pelo usuário) de uma disciplina e determine o número de alunos que tiveram nota superior a média calculada

float media (int n, float v[]){
  float media_alunos = 0;

  for(int i = 0; i < n; i++){
    media_alunos += *(v+i);
  }

  media_alunos /= n;

  return media_alunos;
}

int alunos_acima_media(int n, float v[], float media){
  int acima_media = 0;

  for(int i = 0; i < n; i++){
    if(*(v+i) >= media){
      acima_media++;
    }
  }

  return acima_media;
}

int main(){
  int n;

  cout << "Insira o valor de alunos: ";
  cin >> n;

  float *v = new float [n];

  cout << "Digite as notas dos alunos: ";
  for(int i = 0; i < n; i++){
    cin >> *(v+i);
  }

  cout << "Média dos alunos: " << media(n, v) << endl;
  cout << "Quantidade de alunos acima da média: " << alunos_acima_media(n, v, media(n, v));

  return 0;
}
*/

/* Exercício 4 
Utilizando alocação dinâmica e aritmética de ponteiros, declare um vetor de N inteiros (onde N é um valor fornecido pelo usuário). Crie uma função para ler um valor para cada 
posição e no final mostre quantos elementos possuem valor maior, menor e igual ao primeiro elemento do vetor

int *leitura (int n){
  int *v = new int[n];

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < n; i++){
    cin >> *(v+i);
  }

  return v;
}

void maior_menor_igual(int n, int v[]){
  int maior = 0, menor = 0, igual = 0;

  for(int i = 1; i < n; i++){
    if(v[i] > v[0]){
      maior++;
    } else if (v[i] < v[0]){
      menor++;
    } else {
      igual++;
    }
  }

  cout << "O vetor possui " << maior << " valor(es) maior que " << v[0] << ", " << menor << " valor(es) menores e " << igual << " valor(es) iguais." << endl;
}

int main(){
  int n, *vetor;

  cout << "Digite o tamanho do vetor: ";
  cin >> n;

  vetor = leitura(n);

  maior_menor_igual(n,vetor);

  return 0;
}
*/

/* Exercício 5 
Utilizando alocação dinâmica e aritmética de ponteiros, declare um vetor de N inteiros (onde N é um valor fornecido pelo usuário), leia um valor para cada posição e no final mostre 
os elementos deste vetor em posição inversa ao que foram atribuídos.

int *leitura (int n){
  int *v = new int[n];

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < n; i++){
    cin >> *(v+i);
  }

  return v;
}

void inverso(int n, int v[]){  
  for(int i = n-1; i >= 0; i--){
    cout << *(v+i) << " ";
  }
}

int main(){
  int n, *vetor;

  cout << "Digite o tamanho do vetor: ";
  cin >> n;

  vetor = leitura(n);

  inverso(n, vetor);
  
  return 0;
}
*/

/* Exercício 6 
Utilizando alocação dinâmica e aritmética de ponteiros, declare um vetor de N inteiros (onde N é um valor fornecido pelo usuário), leia um valor para cada posição e no final mostre o 
calculo do fatorial do maior e do menor

int *leitura (int n){
  int *v = new int[n];

  cout << "Digite os valores do vetor: ";
  for(int i = 0; i < n; i++){
    cin >> *(v+i);
  }

  return v;
}

void fatorial(int n, int v[]){
  int maior = v[0], menor = v[0];

  for(int i = 1; i < n; i++){
    if(maior < v[i])
      maior = *(v+i);

    if(menor > v[i])
      menor = *(v+i);
  }

  int fat_maior = 1, fat_menor = 1;
  for(int i = 1; i <= maior; i++){
    fat_maior *= i;
  }

  for(int j = 1; j <= menor; j++){
    fat_menor *= j;
  }

  cout << "O fatorial de " << maior << " é " << fat_maior << " e de " << menor << " é " << fat_menor;
}

int main(){
  int n, *vetor;

  cout << "Digite o tamanho do vetor: ";
  cin >> n;

  vetor = leitura(n);

  fatorial(n, vetor);

  return 0;
}
*/

/* Exercício 7 
Utilizando alocação dinâmica e aritmética de ponteiros, leia dois vetores A e B com N elementos (onde N é um valor fornecido pelo usuário). Construa um terceiro vetor C, onde cada elemento é a subtração do elemento correspondente de a A com B

int* leitura (int n, int *v){
  v = new int[n];
  
  for(int i = 0; i < n; i++){
    cin >> *(v+i);
  }

  return v;
}

int* resposta(int n, int *a, int *b){
  int *res = new int[n];

  for(int i = 0; i < n; i++){
    *(res+i) = *(a+i) - *(b+i);
  }

  return res;
}

int main (){
  int n, *a, *b, *c;

  cout << "Digite o tamanho dos vetores: ";
  cin >> n;

  cout << "Digite os valores do vetor A: ";
  a = leitura(n, a);
  cout << endl << "Digite os valores do vetor B: ";
  b = leitura(n, b);
  
  c = resposta(n, a, b);

  cout << "Diferença dos elementos entre a e b: ";
  for(int i = 0; i < n; i++)
  cout << *(c+i) << " ";

  return 0;
}
*/

/* Exercício 8 
Utilizando alocação dinâmica e aritmética de ponteiros, leia dois vetores A e B com N e M elementos respectivamente (onde N e M são valores fornecido pelo usuário). Construa um terceiro vetor C, com todos os elemento de A, seguidos de todos os elementos de B
*/

#include <iostream>
using namespace std;

// não passar ponteiros como argumento pois não estará passando o endereço do ponteiro, mas sim uma cópia do ponteiro, o que não permite que a função aloque memória dinamicamente e leia os valores corretamente.
int* leitura(int tam) {
  int* v = new int[tam];

  for (int i = 0; i < tam; i++) {
    cin >> v[i];
  }

  return v;
}

int* conjunto(int n, int m, int* a, int* b) {
  int* r = new int[n + m];

  for (int i = 0; i < n; i++) {
    r[i] = a[i];
  }

  for (int i = 0; i < m; i++) {
    r[n + i] = b[i];
  }

  return r;
}

int main() {
  int *a, *b, *c, n, m, total;

  cout << "Digite os valores de n e m: ";
  cin >> n >> m;

  cout << "Digite os valores de a: ";
  a = leitura(n);

  cout << "Digite os valores de b: ";
  b = leitura(m);

  total = m + n;

  c = conjunto(n, m, a, b);

  cout << "Vetor c: ";
  for (int i = 0; i < total; i++) {
    cout << c[i] << " ";
  }

  delete[] a;
  delete[] b;
  delete[] c;

  return 0;
}
