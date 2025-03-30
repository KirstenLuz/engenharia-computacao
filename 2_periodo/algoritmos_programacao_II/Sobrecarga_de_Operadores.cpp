/* Meu código teste
Erros:
- Sobrecarga dos operadores de entrada e saída:
Os operadores >> e << estão sendo sobrecarregados para a classe float, o que não é possível de fazer diretamente. Isso ocorre porque float é um tipo de dado primitivo em C++ e não pode ser extendido com novas operações de entrada e saída da maneira que uma classe pode ser. Você só pode sobrecarregar esses operadores para classes que você mesmo cria.
- Sobrecarga do operador de adição:
A sobrecarga do operador + está com uma sintaxe incorreta. Você não deve incluir a palavra "soma" antes do operador. A sobrecarga do operador deve ser declarada simplesmente como float operator+ (float a, float b), sem a palavra "soma" no início.


#include <iostream>
using namespace std;

istream & operator >> (istream & is, float &a){
  is >> a;
  return is;
}

ostream & operator << (ostream & os, float &a){
  os << a;
  return os;
}

float soma operator+ (float a, float b){
  return a+b;
}

int main() {
  float x, y;
  cout << "Digite x e y: ";
  cin >> x >> y;
  cout << x+y << endl;
  return 0;
}
*/

#include <iostream>
using namespace std;

template <int n, int m, typename tipo>
struct matriz {
  tipo c[n][m];
};

template <int n, int m, typename tipo>
istream & operator >> (istream & is, matriz<n, m, tipo> &a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      is >> a.c[i][j];
    }
  }
  return is;
}

template <int n, int m, typename tipo>
ostream & operator << (ostream & os, const matriz<n, m, tipo> &a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      os << a.c[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

template <int n, int m, typename tipo>
matriz<n, m, tipo> operator+ (matriz<n, m, tipo> &mat1, matriz<n, m, tipo> &mat2) {
  matriz<n, m, tipo> res;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      res.c[i][j] = mat1.c[i][j] + mat2.c[i][j];
  return res;
}

/* aqui é necessário a mudança do retorno da função para uma matriz transposta, ao inves de matriz<n,m,tipo> para matriz<m,n,tipo>*/
template <int n, int m, typename tipo>
matriz<m, n, tipo> operator~ (matriz<n, m, tipo> &a) {
  matriz<m, n, tipo> Res;  // Correção para a matriz transposta
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      Res.c[j][i] = a.c[i][j];  // Transposição
  return Res;
}

int main() {
  matriz<3, 2, int> a, b, soma;

  cout << endl << ".. leitura de a... " << endl;
  cin >> a;

  cout << endl << ".. leitura de b... " << endl;
  cin >> b;

  cout << endl << ".. escrita de a... " << endl;
  cout << a;

  cout << endl << "... escrita de b... " << endl;
  cout << b;

  cout << endl << "... soma de a + b..." << endl;
  soma = a + b;
  cout << soma;

  cout << endl << "... matriz transposta de a..." << endl;
  cout << ~a;

  return 0;
}
