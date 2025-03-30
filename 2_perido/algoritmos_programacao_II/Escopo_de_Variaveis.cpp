// Escopo de variáveis
#include <iostream>
using namespace std;
#include <time.h>


int y = 1;
int x = 4;

void primeiro (){
  static int x = 23;
  cout << "\n\n" << x;
  x++;
  cout << "\n\n" << x;
}

void segundo (){
  cout << "\n\n" << x;
  cout << "\n\n" << y;
}

void terceiro (int x, int &y){
  x *= 2;
  y *= 3;
}

int main() {
  int y = 2;
  int x = 3;

  cout << "\n\n" << y;

  {
    int x = 10;
    cout << "\n\n" << x;
    cout << "\n\n" << y;
  }

  primeiro();
  segundo();
  terceiro(x, y);
  primeiro();

  cout << "\n\n" << x;
  cout << "\n\n" << y;

  return 0;
}
