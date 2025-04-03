// Lista de exercícios extras - recursividade extra

/* Exercício 1 */
#include <iostream>
using namespace std;

int SomaSerie(int i, int j, int k){
  if(i==j){

    return j+k;
  }
  return SomaSerie(i+1,j,k);
}

int main() {
int i=0,j=0,k=1;

  cout<<"Digite um numero para i:";
  cin>>i;
    cout<<"Digite um numero para j:";
    cin>>j;
  cout<< SomaSerie(i,j,k);

}

/* Exercício 2 */
#include <iostream>
using namespace std;

float conta(int N, int c, int d){
  if(N==1){
    return 1;
  }
  c++;
  return d/conta(N-1, c, d+1);
}

int main() {
  int N, cont=0, d=1;

  cout<<"Digite um valor:";
  cin>>N;
  cout<<conta(N, cont, d);
}

/* Exercício 3 */
#include <iostream>
using namespace std;

int MOD(int x, int y){
  if (x < 0 || y <= 0) {
      return -1; 
  }
    if (x < y) {
      return x;
    }
    return MOD(x - y, y);
  }

int main() {
int x, y; 

  cout<<"Digite um numero para x:";
  cin>>x;

  cout<<"Digite um numero para y:";
  cin>>y;
  int resultado = MOD(x, y);

  if (resultado != -1) {
    cout << "O resto da divisao de " << x << " por " << y << " eh: " << resultado << endl;
  } else {
    cout << "Nao e possivel calcular o MOD." << endl;
  }

}
/* Exercício 4 */

#include <iostream>
using namespace std;

float soma(int num, int aux) {
  if (num == aux) {
    return aux;
  }
  cout<<"a:"<<aux<<endl;
  cout<<"n:"<<num<<endl;
return soma(num, aux + 1.0) + (1.0 + aux * aux) / (aux + 1.0);
  //
//return soma(num, aux+1.0) + (1.0 + num*num) / num ;
}

int main() {

  float n;
  cout << "Digite um numero:";
  cin >> n;
  cout << soma(n, 1.0);
}

Faça uma função recursiva, em linguagem C++, que calcule o valor da série S= 2+ 5/2 + 10/3 + 17/4 +... + 1+n²/n 
descrita a seguir para um valor n>0 a ser fornecido como parâmetro para a
mesma*/

/* Exercício 5 */

#include <iostream>
using namespace std;

int MOD(int x, int y){
  if (x < 0 || y <= 0) {
      return -1; 
  }
    if (x < y) {
      return x;
    }
    return MOD(x - y, y);
  }

int main() {
int x, y; 

  cout<<"Digite um numero para x:";
  cin>>x;

  cout<<"Digite um numero para y:";
  cin>>y;
  int resultado = MOD(x, y);

  if (resultado != -1) {
    cout << "O resto da divisao de " << x << " por " << y << " eh: " << resultado << endl;
  } else {
    cout << "Nao e possivel calcular o MOD." << endl;
  }

}
/* Exercício 6 */

#include <iostream>
using namespace std;

int MOD(int x, int y){
  if (x < 0 || y <= 0) {
      return -1; 
  }
    if (x < y) {
      return x;
    }
    return MOD(x - y, y);
  }

int main() {
int x, y; 

  cout<<"Digite um numero para x:";
  cin>>x;

  cout<<"Digite um numero para y:";
  cin>>y;
  int resultado = MOD(x, y);

  if (resultado != -1) {
    cout << "O resto da divisao de " << x << " por " << y << " eh: " << resultado << endl;
  } else {
    cout << "Nao e possivel calcular o MOD." << endl;
  }

}
