// // Exercício 1
// #include <iostream>
// using namespace std;

// int main() {
//   int x, y;

//   cout << "Entre com o valor de X: ";
//   cin >> x;

//   cout << "Entre com o valor de Y: ";
//   cin >> y;

//   cout << "A subtração de X e Y é igual a: " << x - y;

//   return 0;
// }

// // Exercício 2
// #include <iostream>
// using namespace std;

// int main(){
//   int i;

//   for(i = 0; i < 7; i++){
//     cout << i << "\t";
//   }

//   return 0;
// }

// Exercício 3
#include <iostream>
using namespace std;

int main(){
  int A[4];

  cout << "Leitura dos elementos do vetor: \n\n";
  for(int i = 0; i < 4; i++){
    cout << "Entre com A[" << i << "]: ";
    cin >> A[i];
  }

  cout << "\nApresentação do leitor lido: \n";
  for(int i = 0; i < 4; i++){
    cout << A[i] << "\t";
  }

  return 0;
}
