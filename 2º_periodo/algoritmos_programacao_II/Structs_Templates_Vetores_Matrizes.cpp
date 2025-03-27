#include <iostream>
using namespace std;

// // Exemplo 1
// /* Aqui então cria-se o template que é necessário um parâmetro inteiro que
// vai servir como tamanho do vetor, e o vetor que vai ser o tipo do template */
// template <int n, typename tipo>
// struct vetor {
//   tipo v[n];
// };

// /* Ao passar como parâmetro de uma função uma struct tipo template, é
// necessário usar o & para que mude o valor real da struct. Também ao passar a
// struct como parâmetro em que dentro dela há um template usa-se a estrutura
// "struct<tipo criado> &variavel" */ template <int n, typename tipo> void
// leitura (vetor<n,tipo> &x){
//   for (int i=0; i<n; i++){
//     cin >> x.v[i];
//     cout << endl;
//   }
// }

// /* Aqui é a escrita dos valores do vetor do tipo do template de dentro da
// struct */ template <int n, typename tipo> void escrita (vetor<n,tipo> x){
//   for (int i=0; i<n; i++){
//     cout << x.v[i] << " ";
//     cout << endl;
//   }
// }

// /* Aqui está fazendo a soma de todos os elementos de dentro do vetor, com
// isso criou-se uma função com o tipo do template para que possa ser usada para
// a soma de todos os tipos de variáveis*/ template <int n, typename tipo> tipo
// soma (vetor<n,tipo> x){
//   tipo d = 0;
//   for(int i = 0; i < n; i++){
//     d += x.v[i];
//   }
//   return d;
// }

// int main(){
//   vetor<5, int> a;
//   leitura(a);
//   escrita(a);
//   cout << "A soma dos elementos do vetor é: " << soma(a) << endl << endl;

//   vetor<7, float> b;
//   leitura(b);
//   cout << "A soma dos elementos do vetor é: " << soma(b) << endl << endl;

//   return 0;
// }

// Exemplo 2
/* Criei um template que necessita da linha e da coluna para ser criado*/
template <int n, int m, typename tipo> struct estrutura { tipo mat[n][m]; };

/* Funciona igual ao vetor, função para a leitura */
template <int n, int m, typename tipo> void leitura(estrutura<n, m, tipo> &a) {
  int i, j;
  cout << endl << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a.mat[i][j];
    }
  }
}

/* Função para a escrita */
template <int n, int m, typename tipo> void escrita(estrutura<n, m, tipo> a) {
  int i, j;
  cout << endl << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a.mat[i][j] << "\t";
    }
    cout << endl;
  }
}

template <int n, int m, typename tipo>
estrutura<n, m, tipo> soma(estrutura<n, m, tipo> a, estrutura<n, m, tipo> b) {
  int i, j;
  estrutura<n, m, tipo> resultado;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      resultado.mat[i][j] = a.mat[i][j] + b.mat[i][j];
    }
  }
  return resultado;
}

int main() {
  estrutura<3, 3, float> m1, m2;
  leitura(m1);
  leitura(m2);
  escrita(soma(m1, m2));

  estrutura<2, 2, int> n1, n2, res;
  leitura(n1);
  leitura(n2);
  res = soma(n1, n2);
  escrita(res);
}
