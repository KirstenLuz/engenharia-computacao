// Parâmetros default
#include <iostream>
using namespace std;
#include <time.h>

int teste1(int base = 1, int altura = 2){
  // caso não sejam passados parâmetros na chamada da função, serão esses valores usados
  int area;
  area = base * altura;
  return area;
}
int main() {
  int ba = 10, al = 10;

  cout << "\n" << teste1();
  cout << "\n" << teste1(10);
  cout << "\n" << teste1(ba, al);

  return 0;
}
