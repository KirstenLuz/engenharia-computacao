// Templates
#include <iostream>
using namespace std;
#include <locale.h>

/* Exemplo 1
template <typename Tipo> // aqui eu digito o nome do meu template criado
Tipo soma(Tipo a, Tipo b){
  return (a + b);
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  cout << endl << "Soma de dois int: " << soma(2, 4);
  cout << endl << "Soma de dois float: " << soma(2.3, 7.6);
  cout << endl << "Soma de dois caracteres: " << soma('1', 'x');

  cout << endl << "Soma de dois int: " << soma(27, 43);
  cout << endl << "Soma de dois float: " << soma(10.6, 4.4);
  cout << endl << "Soma de dois caracteres: " << soma('C', '#');
  return 0;
}
*/

/* Exemplo 2 
template <typename Tipo>
Tipo maior(Tipo a, Tipo b){
  return (a > b ? a : b);
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  
  cout << endl << "Maior entre dois int: " << maior(2, 4);
  cout << endl << "Maior entre dois float " << maior(2.3, 7.6);
  cout << endl << "Maior entre dois carcateres: " << maior('x', 'c');
  
}
*/

/* Exemplo 3 */
#define TAM 5

template <typename x>
void leituraVetor (x vetor[TAM]){
  int i;
  for (i = 0; i < TAM; i++){
    cout << "Vetor na posição " << i << ": ";
    cin >> vetor[i];
  }
}

template <typename x> // é obrigatório criar o template antes de usá-lo na função e nos parâmetros, mesmo que ele já exista anteriormente
void escritaVetor (x vetor[TAM]){
  int i;
  for(i = 0; i < TAM; i++){
    cout << vetor[i] << "\t";
  }
}

int main (){
  setlocale(LC_ALL, "Portuguese");

  int vetInt[TAM];
  leituraVetor(vetInt);
  escritaVetor(vetInt);

  cout << endl << endl;
  string vetChar[TAM];
  leituraVetor(vetChar);
  escritaVetor(vetChar);

  return 0;
}
