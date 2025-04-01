#include <iostream>
using namespace std;
#include <time.h>

/* Exercicio 1
// vai pedir ao usuário o valor
void leitura(int &x){
  cout << "Digite um valor inteiro: ";
  cin >> x;
}

// vai verificar se é positivo ou negativo
bool verifica(int y){
  if(y > 0)
    return true;
    else 
    return false;
}
// para que retorne true ou false, a função deve ser do tipo bool
// não é necessário chaves no if quando há apenas uma linha de operação acontecendo

int main() {
  int a;

  leitura(a);

  cout << "Se o número for positivo o resultado será 1, e se for negativo será 0!" << endl; 
  
  cout << verifica(a);

  return 0;
}
*/

/* Exercicio 2
bool verifica(int x){
  if(x % 2 == 0){
    return true;
  } else {
    return false;
  }
}

int main (){
  int numero;

  cout << "Digite um número: ";
  cin >> numero;

  if(verifica(numero)){
    cout << "O número é positivo";
  } else {
    cout << "O número é negativo";
  }
  
  return 0;
}
*/

/* Exercicio 3
void idade(int a, int b){
  cout << "Você tem " << b - a << " anos";
}

int main (){
  int dia, mes, ano, ano_atual;  

  cout << "Digite o seu aniversário: ";
  cin >> dia >> mes >> ano;

  cout << "Digite o ano atual: ";
  cin >> ano_atual;

  cout << "Seu aniversário é dia " << dia << "/" << mes << "/" << ano << endl;
  idade(ano, ano_atual);
  
  return 0;
}
*/

/* Exercicio 4
void verifica(int x);

int main (){
  int a;

  cout << "Digite um número: ";
  cin >> a;

  verifica(a);

  return 0;
}

void verifica(int x){
  if(x > 0){
    cout << "Ele é positivo";
  } else if(x < 0){
    cout << "Ele é negativo";
  } else {
    cout << "O número é zero";
  }
} 
*/

/* Exercicio 5
void tabuada(int x);

int main(){
  int a;

  cout << "Digite um número para a tabuada: ";
  cin >> a;

  tabuada(a);
  
  return 0;
}

void tabuada(int x){
  cout << "Tabuada do " << x << endl;
  for(int i = 0; i <= 10; i++){
    cout << i << " x " << x << " = " << i * x << endl;
  }
}
*/

/* Exercicio 6
void leitura (int &a, int &b){
  do {
  cout << "Digite dois valores inteiros e positivos para base e expoente: ";
  cin >> a >> b;
  } while (a <= 0 || b <= 0);
}

void conta(int a, int b){
  int conta = 1;
  for(int i = 0; i < b; i++){
    conta *= a;
  }
  cout << conta;
}

int main (){
  int a, b;

  leitura(a, b);
  
  conta(a, b);

  return 0;
}
*/

/* Exercicio 7
void fibonacci(){
  int t1 = 0, t2 = 1, soma = 1;
  
  for(int i = 1; i <= 20; i++){
    cout << soma << " ";
    soma = t1 + t2;
    t1 = t2;
    t2 = soma;
  }
}

int main (){

  fibonacci();
  
  return 0;
}
*/

/* Exercicio 8
int idade(){
  int x, maior = 0;
  cout << "Digite a idade de cada pessoa: ";
  for(int i = 1; i <= 10; i++){
    cin >> x;
    if(x >= 18)
      maior++;
  }
  return(maior);
}

int main(){

  cout << idade() << " maiores de 18 anos.";

  return 0;
}
*/

/* Exercicio 9
int fatorial(int x){
  int numero = 1;
  for(int i = 1; i <= x; i++){
    numero *= i;
  }
  return(numero);
}

int main (){
  int a;

  cout << "Digite um número: ";
  cin >> a;

  cout << "O fatorial de " << a << " é " << fatorial(a);
  
  return 0;
}
*/

/* Exercicio 10
void pessoas(){
  int maior, menor, peso;
  cout << "Digite o peso da 1° pessoa: ";
  cin >> maior;
  menor = maior;
  for(int i = 2; i < 25; i++){
    cout << "Digite o peso da " << i << "° pessoa: ";
    cin >> peso;
    if(peso > maior){
      maior = peso;
    } else if (peso < menor){
      menor = peso;
    }
  }
  cout << "O maior peso é " << maior << " e o menor " << menor;
}

int main (){

  pessoas();
  
  return 0;
}
*/
