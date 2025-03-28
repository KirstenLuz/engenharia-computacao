#include <iostream>
using namespace std;

// Exemplo 1
/*
int main (){
  int *pont1, v = 5;

  // aqui eu atribuo o valor armazenado no ponteiro o endereço da variável v, é necessário o uso do &
  pont1 = &v;

  // aqui ao imprimir o ponteiro com o asterisco, eu digo para imprimir o valor armazenado no endereço armazenado do ponteiro
  cout << endl << *pont1;
  // e aqui ao imprimir apenas a "variável" ponteiro, eu estou imprimindo o endereço da variável que ele está apontando
  cout << endl << pont1;

  return 0;
}
*/

// Exemplo 2
/* 
int main(){
  int *pont1, *pont2, v = 5, k = 6;

  pont1 = &v;
  pont2 = &k;

  cout << endl << pont1;
  cout << endl << *pont1;

  cout << endl << pont2;
  cout << endl << *pont2;

  // Neste código, quando você faz a atribuição pont1 = pont2;, o pont1 deixa de apontar para o endereço de memória que armazena o valor v e passa a apontar para o mesmo endereço de memória que pont2, ou seja, para onde k está armazenado. Isso significa que ambos pont1 e pont2 agora apontam para a mesma variável, k.
  
  // Isso não faz uma cópia do valor de pont2 em pont1. Em vez disso, pont1 e pont2 agora referenciam o mesmo endereço de memória. Portanto, qualquer alteração feita através de pont1 também afetará o valor de k, porque ambos estão apontando para a mesma localização de memória.
  
  // Se você modificar o valor por meio de *pont1, como *pont1 = 10;, isso também afetará o valor de k, tornando k igual a 10, já que ambos os ponteiros estão apontando para a mesma variável na memória.
  pont1 = pont2;
  
  cout << endl << pont1;

  return 0;
}
*/

// Exemplo 3
/*
int main(){
  int *pont1, *pont2, v = 5, k = 6;

  pont1 = &v;
  pont2 = &k;

  cout << endl << pont1;
  cout << endl << *pont1;

  cout << endl << pont2;
  cout << endl << *pont2;
  
  // Se você fizer *pont1 = *pont2; em vez de pont1 = pont2;, você estará copiando o valor apontado por pont2 para o endereço apontado por pont1. Nesse caso, não haverá mudança na localização da memória para a qual pont1 aponta, mas sim na alteração do valor armazenado nessa localização de memória.
  *pont1 = *pont2;

  cout << endl << *pont1;

  return 0;
}
*/

// Exemplo 4
/*
int main(){
  int *p1, *p2, v = 5, x = 3;

  // Se eu for tentar atribuir ao valor do ponteiro algo que não seja um endereço de memória, o programa gera um erro.
  p1 = &v;
  p2 = &x;

  cout << endl << p1;
  cout << endl << *p1;
  cout << endl << p2;
  cout << endl << *p2;

  // Aqui o valor contido dentro do endereço de memória apontando por p1 será copiado do valor contido dentro do endereço de memória apontando por p2.
  *p1 = *p2;

  cout << endl << *p1;
  // *p1 = 3
  cout << endl << *p2;
  // *p2 = 3
  
  *p1 = 9;
  cout << endl << *p1;
  // *p1 = 9
  cout << endl << *p2;
  // *p2 = 3

  // Já aqui o que mudou foi para onde o p2 está apontando, no caso p2 passa a apontar para o endereço da variável v
  p2 = p1;
  cout << endl << endl << *p1;
  // *p1 = 9
  cout << endl << *p2;
  // *p2 = 9

  // E como a p2 passou a apontar para o mesmo lugar que o p1, se eu mudar o valor contido dentro do endereço de memória apontado por p2, p1 também mudará
  *p2 = 10; // está mudando o valor de v
  cout << endl << endl << *p1;
  // *p1 = 10
  cout << endl << *p2;
  // *p2 = 10
  
  return 0;
}
*/

// Exemplo 5
/*
int main (){
  int *p1, *p2, x = 3, y = 4;

  p1 = &x;
  p2 = &y;

  cout << endl << *p1;
  cout << endl << *p2 << endl;

  *p1 += 2;
  cout << endl << *p1 << endl;

  *p2 *= 4;
  cout << endl << *p2 << endl;

  *p1 += *p2;
  cout << endl << *p1 << endl;

  p2 = p1;
  cout << endl << p1;
  cout << endl << *p1;
  cout << endl << p2;
  cout << endl << *p2;
}
*/

// Exemplo 6
// Alocação dinâmica de memória = criar variáveis que não possuem identificadores, mas são referenciadas por meio de ponteiros. Usa-se "new" para criar essas variáveis e delete para destruí - las.
/*
int main(){
  int *p1;

  p1 = new int;

  cin >> *p1;
  *p1 = *p1 + 3;
  cout << *p1;

  delete p1;

  return 0;
}
*/

// Exemplo 7

int main(){
  int *p1, *p2;

  // criei uma variável sem identidade, e disse que p1 está apontando pra ela
  p1 = new int;

  // aqui eu falei que o valor contido dentro dessa variável sem identidade passou a ser 42
  *p1 = 42;

  // aqui eu disse que p2 está apontando também para essa variável sem identidade
  p2 = p1;

  cout << endl << endl << *p1;
  // 42
  cout << endl << *p2;
  // 42

  // aqui eu disse que o valor dessa variável sem id passou a ser 53
  *p2 = 53;

  cout << endl << endl << *p1;
  // 53
  cout << endl << *p2;
  // 53

  // aqui eu falei que o p1 está apontando agora para outra variável sem identidade
  p1 = new int;
  // e que o valor contido nessa variável é 88
  *p1 = 88;

  cout << endl << endl << *p1;
  // 88
  cout << endl << *p2;
  // 53, pois mesmo que p1 tenha mudado, p2 continua apontando para a variável sem id inicial

  delete p1;
  p1 = nullptr;
  delete p2;
  p2 = nullptr; 

  // Nesse código, após a desalocação de memória de p1 e p2, atribuímos nullptr a ambos os ponteiros para indicar que eles não estão mais apontando para qualquer local de memória. Isso ajuda a evitar o problema de "ponteiros pendurados" e torna seguro verificar se um ponteiro é nulo antes de tentar acessar ou modificar o valor a que ele aponta.
  
  return 0;
}
