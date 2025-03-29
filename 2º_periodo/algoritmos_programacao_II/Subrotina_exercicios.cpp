/* Exercício 1
#include <iostream>
using namespace std;
#include <time.h>

void numeros(int a, int b, int c){
  if(a < b && a < c){
    cout << a;
  } else if (b < a && b < c){
    cout << b;
  } else if (c < a && c < b){
    cout << c;
  }
}

int main() {
  int x, y, z;

  cout << "Digite o valor de X: ";
  cin >> x;
  
  cout << "Digite o valor de Y: ";
  cin >> y;
  
  cout << "Digite o valor de Z: ";
  cin >> z;

  numeros(x, y, z);

  return 0;
}
*/

/* Exercicio 2
#include <iostream>
using namespace std;
#include <time.h>

bool numero(int a){
  int soma = a, resultado = 0; //resultado = soma dos múltiplos
  for(int i = 1; i < a; i++){
    if(soma % i == 0){
      resultado += i;
    }
  }
  if(resultado == a){
    return true;
  } else {
    return false;
  }
}

int main (){
  int a, b;

  cout << "Digite um número inteiro e positivo: ";
  cin >> a;

  b = numero(a);

  if(b){
    cout << a << " é um número perfeito.";
  } else {
    cout << a << " não é um número perfeito.";
  }

  return 0;

}

*/

/* Exercicio 3
#include <iostream>
using namespace std;
#include <time.h>

void castigo(int a){
  for(int i = 1; i <= a; i++){
    cout << "Não vou colar na prova\n";
  }
}

int main (){
  int a;

  cout << "Digite um número inteiro: ";
  cin >> a;

  castigo(a);
  
  return 0;
}
*/

/* Exercicio 4
#include <iostream>
using namespace std;
#include <time.h>

float formula(int x){
  float calc = 0;
  for (float i = 1; i <= x; i++){
    calc += x / i;
  }
  return(calc);
}

int main(){
  float x, y;
  float soma = 0;

  cout << "Digite um intervalo para a soma do cálculo de E: ";
  cin >> x >> y;

  for(float i = x; i <= y; i++){
    soma += formula(i);
  }

  cout << "O resultado da equação E é " << soma;
  
  return 0;
}
*/

/* Exercicio 5
#include <iostream>
using namespace std;
#include <time.h>

float peso(string a, float b){
  float peso = 0;
  if(a == "homem"){
    peso = (72.7 * b) - 58;
  } else if(a == "mulher"){
    peso = (62.1 * b) - 44.7;
  }
  return(peso);
}

int main(){
  float altura, peso_ideal;
  string sexo;

  cout << "Digite o sexo (homem/mulher) e a altura: ";
  cin >> sexo >> altura;

  peso_ideal = peso(sexo, altura);

  cout << "O peso ideal é " << peso_ideal;

  return 0;
}
*/

/* Exercicio 6
#include <iostream>
using namespace std;
#include <time.h>

bool primos(int a){
  int num = 0;
  for(int i = 2; i < a; i++){
    if(a % i == 0){
      num = 1;
    } 
  }
    
  if(num == 0){
    return true;
  } else {
    return false;
  }
}
  // Primeiro criar a função que verifica se ele é primo

int main(){
  int sequencia, a = 100;
  
  for(int i = 1; i <= 10; a++){
    if(primos(a) == true){
      cout << a << endl;
      i++;
    }
  }

  return 0;
}
*/

/* Exercicio 7
#include <iostream>
using namespace std;
#include <time.h>

float fatorial(float x){
  float numero = 1;
  for(int i = 1; i <= x; i++){
    numero *= i;
  }
  return(numero);
}

float calculo(int x, int n){
  float soma = (x + 2), divisor;
  
  for(int i = 2; i <= n; i++){
    if((i + 1) % 2 == 0){
      divisor = fatorial(i);
      soma -= (x + i + 1) / divisor;
    } else {
      divisor = fatorial(i);
      soma += (x + i + 1) / divisor;
    }
  }
  return(soma);
}


int main(){
  float x, n, resultado;

  do {
    cout << "Digite o valor de X: ";
    cin >> x;
    
    cout << "Digite o valor de N: ";
    cin >> n; 
   
  } while (n <= 0);

  resultado = calculo(x, n);

  cout << "O resultado é: " << resultado;

  return 0;
}
// função para o fatorial
// while para o numero N
*/

/* Exercicio 8
#include <iostream>
using namespace std;
#include <time.h>

void triangulo(float a, float b, float c){
  if(a == b && b == c){
    cout << "O triângulo é equilátero";
  } else if (a == b && a != c && c != b || a == c && a != b && b != c || b == c && b != a && c != a) {
    cout << "O triângulo é isósceles";
  } else if (a != b != c) {
    cout << "O triângulo é escaleno";
  }
}

int main(){
  float a, b, c;

  cout << "Digite os três lados do triângulo: ";
  cin >> a >> b >> c;

  triangulo(a, b, c);

  return 0;
}
*/

/* Exercicio 9
#include <iostream>
using namespace std;
#include <time.h>

void letra(char a){
  if(a == 'a' && 'e' && 'i' && 'o' && 'u'){
    cout << a << " é uma vogal";
  } else {
    cout << a << " é uma consoante";
  }
}

int main (){
  char a;

  cout << "Digite uma letra: ";
  cin >> a;

  letra(a);

  return 0;
}
*/

// Exercicio 10
#include <iostream>
using namespace std;
#include <time.h>

float soma(float x, float y){
  return (x + y);
}

float subtracao(float x, float y){
  return (x - y);
}

float multiplicacao(float x, float y){
  return (x * y);
}

float divisao(float x, float y){
  return (x / y);
}


int main (){
  int operacao;
  float x, y;

  cout << "1 - soma\n2 - subtração\n3 - multiplicação\n4 - divisão" << endl;
  cout << "Digite a operação desejada: ";
  cin >> operacao;

  cout << "Digite o valor de x e y: ";
  cin >> x >> y;

  switch(operacao){
    case 1:
      cout << "A soma é " << soma(x, y);
      break;
    case 2:
      cout << "A subtração é " << subtracao(x, y);
      break;
    case 3:
      cout << "A multiplicação é " << multiplicacao(x, y);
      break;
    case 4:
      cout << "A divisão é " << divisao(x, y);
    break;
    default:
      cout << "Opção inválida!";
  }

  return 0;
}
