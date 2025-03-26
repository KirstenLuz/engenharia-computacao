// Sobrecarga de função
#include <iostream>
using namespace std;
#include <time.h>

/* Exemplo 1
float media(float n1, float n2){
  return ((n1 + n2) / 2.0);
}

float media(float n1, float n2, float n3){
  return ((n1 + n2 + n3) / 3.0);
}

int main() {
  float nota1, nota2, nota3;
  cout << "Nota 1 ..: ";
  cin >> nota1;

  cout << "Nota 2 ..: ";
  cin >> nota2;

  cout << "Nota 3 ..: ";
  cin >> nota3;

  cout << "\nMedia com 2 valores... " << media(nota1, nota2) << "\n";
  
  cout << "\nMedia com 3 valores... " << media(nota1, nota2, nota3) << "\n";

  return 0;
}
*/

/* Exemplo 2 */

int soma(int a, int b){
  return (a+b);
}

int soma(int a, int b, int c){
  return (a+b+c);
}

double soma(double a, double b){
  return (a+b);
}

int main(){
  cout << soma(1,2) << endl;
  cout << soma(3,4,5) << endl;
  cout << soma(6.7,8.9) << endl;

  return 0;
}
