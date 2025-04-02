// Lista de exercícios
#include <iostream>
using namespace std;

// Exercício 1 - c

// Exercício 2 - d

// Exercício 3
/*
int main() {
  int *px, x = 10;

  px = &x;

  cout << endl << *px;

  *px = *px / 5;

  cout << endl << x;

  return 0;
}
*/

// Exercício 4 - e

// Exercício 5 
/*
int main (){
  int *p1, *p2, *p3, v, x;

  cout << "V...: ";
  cin >> v;
  cout << "X...: ";
  cin >> x;

  // p3 = new - erro aqui pois faltou declarar o valorn numérico da nova variável
  p3 = new int;
  p1 = &v;
  p2 = &x;
  *p3 = v + *p2;

  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << *p3 << endl;
  
  delete p3;
  
  // *p3 = p1; - não é possível, pois o ponteiro agora está pendurado e não aponta para nenhum endereço em que possa ser armazenado um valor numérico, por isso devia ser p3 = p1
  *p2 = *p1;
  p3 = p2;
  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << *p3 << endl;
  // o fato de o valor 2097 ser impresso é simplesmente um resultado do comportamento indefinido, pois como o p3 foi desalocado, o valor impresso no console não tem um significado específico no contexto do programa

  // aqui se torna possível pois o ponteiro p3 está recebendo um novo endereço, o endereço de p2
  p3 = p2;
  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << *p3 << endl; 
  

  *p3 = 8;
  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << *p3 << endl;

  return 0;
}
*/

// Exercício 6
/*
int main(){
  int *p1, *p2, v = 3;

  p1 = new int;
  p2 = &v;

  cout << endl << p1;
  // endereço da variável sem id
  cout << endl << p2;
  // endereço de v
  cout << endl << *p2 << endl;
  // valor de v

  *p1 = 42;
  cout << endl << *p1 << endl;
  // valor da variável sem id

  int *p3;

  p3 = p2;
  // p3 passa a apontar pra v

  cout << endl << *p3;
  // 3
  cout << endl << *p2 << endl;
  // 3

  *p3 = 88;
  // v passa a ser 88

  cout << endl << *p3;
  // 88
  cout << endl << *p2 << endl;
  // 88

  p1 = p3;
  // p1 passa a apontar para v também

  cout << endl << *p1;
  cout << endl << *p2;
  cout << endl << *p3;
  cout << endl << v;
  
  return 0;
}
*/

// Exercício 7

int main(){
  int i = 5, *p, **l;;
  // **l é um ponteiro para ponteiros, ele aponta para um ponteiro que por sua vez aponta para uma variável;

  p = &i;
  l = &p;

  // cout << endl << p;
  // // endereço de i
  // cout << endl << *p;
  // // valor de i - 5
  // cout << endl << l;
  // // endereço de p
  // cout << endl << *l;
  // // valor de p (endereço de i) 
  // cout << endl << **l;
  // // valor contido do endereço que está dentro de p (valor de i)

  cout << "i...: " << i << endl;
  // 5
  cout << "p = &i: \n" << p << endl;
  // endereço de i
  cout << "&i...: " << &i << endl;
  // endereço de i
  cout << "p...: " << p << endl;
  // endereço de i
  cout << "*p + 2: " << *p + 2 << endl;
  // 7
  cout << "&p ......: " << &p << endl; 
  // endereço de p (= l)
  cout << "*&p .....: " << *&p << endl; 
  // endereço de i (valor que está dentro de p, *l)
  cout << "**&p ....: " << **&p << endl; 
  // 5 (valor que está dentro do endereço dentro de p, valor de i, **l)
  cout << "3**p ....: " << 3**p << endl; 
  // 15
  cout << "**&p+4 ..: " << **&p+4 << endl; 
  // 9
  cout << "l .......: " << l << endl; 
  // endereço de p (= l)
  cout << "*l ......: " << *l << endl; 
  // endereço de i (valor que está dentro de p, *l)
  return 0;
}
