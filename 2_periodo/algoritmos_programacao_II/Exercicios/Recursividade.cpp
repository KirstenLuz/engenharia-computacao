// Lista de exercícios - Recursividade
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

/* Exercício 1
Faça uma função recursiva para elevar um valor base a potência do valor
expoente.

int potencia (int b, int e){
  if(e == 1){
    return b; // aqui deveria ser e < 1 e retornar 1, para multiplicar na última recursão
  }

  return (b * potencia(b, e - 1));
}

int main(){
  int base, expoente;

  cout << "Digite a base e o expoente: ";
  cin >> base >> expoente;

  cout << "A potência é " << potencia(base, expoente);
  
  return 0;
}
*/

/* Exercício 2
Faça uma função recursiva que calcule o M.D.C. (máximo divisor comum) entre dois
valores fornecidos pelo usuário

int mdc (int n1, int n2){
  if(n1 == n2){
    return n1;
  }

  if(n1 < n2){
    return (mdc(n1, n2 - n1));
  }
  
  return (mdc(n1 - n2, n2)); // o return pode só existir dentro de um if else 
}

int main(){
  int num1, num2;

  cout << "Digite dois valores para o cálculo: ";
  cin >> num1 >> num2;

  cout << "MDC: " << mdc(num1, num2);

  return 0;
}
*/

/* Exercício 3
Faça uma função recursiva que calcule o M.D.C. pelo algoritmo de Euclides. Por
exemplo, divide-se a por b e obtêm-se o quociente q e o resto r. Se r for zero,
b é o m.d.c; se não for, divide-se b por r e assim sucessivamente até encontrar
um resto zero. O último divisor é o M.D.C.

int mdc (int a, int b){
  if(a % b == 0){
    return b;
  }
  return (mdc(b, a % b));
}

int main(){
  int a, b;

  cout << "Digite dois números para o cálculo: ";
  cin >> a >> b;

  cout << "Resultado: " << mdc(a, b);

  return 0;
}
*/

/* Exercícios 4
Faça um programa que receba um valor n, e imprima a contagem regressiva a partir
deste valor. Por exemplo, se o usuário digitar 5, o programa irá imprimir 5, 4,
3, 2, 1, 0

int cont (int a){ // podia ter usado um void
  cout << a << "\t";
  
  if(a < 1){
    return 0;
  }
  
  return (cont(a - 1));
}

int main(){
  int a;

  cout << "Digite um valor: ";
  cin >> a;

  cont(a);

  return 0;
}
*/

/* Exercício 5 
Faça uma função recursiva que recebe um vetor preenchido e a quantidade de posições deste 
vetor, e retorna a soma de todos os elementos do vetor

int soma (int v[], int tam){
  if(tam < 0){
    return 0;
  }

  return v[tam] + soma(v, tam - 1); // não precisa criar uma variável 
}

int main(){
  srand(time(NULL));
  int tam = 5;
  int v[tam];
  
  for(int i = 0; i < tam; i++){
    v[i] = rand() % 9 + 1;
  }

  for(int i = 0; i < tam; i++){
    cout << v[i] << "\t";
  }
  
  cout << "\nResultado: " << soma(v, tam - 1); // passar como parâmetro tamanho - 1, para já somar a prox posição 

  return 0;
}
*/

/* Exercício 6 
Faça uma função recursiva que realize a multiplicação entre dois valores int, sem utilizar o operador *.
int mult (int a, int b){
  if(b < 1){
    return 0;
  }

  return a + mult(a, b - 1);
}

int main(){
  int a, b;

  cout << "Digite os valores a serem multiplicados: ";
  cin >> a >> b;

  cout << "Resultado: " << mult(a, b);

  return 0;
}
*/

/* Exercício 7
Faça uma função recursiva que receba os valores de X e N e realize o cálculo da seguinte 
progressão geométrica
*/

int potencia (int b, int e){
  if(e < 1){
    return 1;
  }

  return (b * potencia(b, e - 1));
}

float calculo (int x, int n){
  if(n < 1){
    return 1;
  }

  return potencia(x, n) + calculo(x, n - 1);
}

int main (){
  int x, n;

  cout << "Digite os valores de x e n: ";
  cin >> x >> n;

  cout << "Resultado: " << calculo(x, n);
  
  return 0;
}
