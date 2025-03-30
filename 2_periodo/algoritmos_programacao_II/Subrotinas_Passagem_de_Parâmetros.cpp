#include <iostream>
using namespace std;
#include <time.h>

/* FUNÇÃO SEM RETORNO
void mensagem(){
  cout << "Primeira função sem retorno.";
}
Função void é uma função que não retorno, e nesse caso não há também parâmetros necessários, serve apenas para executar uma tarefa

void segunda(){
  cout << endl << 2 * 2;
}

int main() {  
  setlocale(LC_ALL,"Portuguese");

  mensagem(); 
  Chamada da função

  segunda();

  return 0;
}
*/

/* FUNÇÃO COM RETORNO */

int soma (int a, int b){
  return (a+b);
}
- nessa função há um retorno e parâmetros
- ao declarar a função, deve-se colocar o tipo do valor
devolvido por ela (int, float, char)
- deve-se colocar também os tipos de parâmetros necessários para essa função (int, float, char)

int main() {  
  setlocale(LC_ALL,"Portuguese");

  int c = 5, d = 6;

  cout << c << " + " << d << " = " << soma(c, d) << endl;

  return 0;
}
/*
- ao passar as os valores para a função, devem ser variáveis criadas no local (main), e não precisam ser necessariamente do mesmo nome que os parâmetros, pois ao chamar a função com essas variáveis o programa irá copiar os valores armazenadas nessas variáveis e passar para os parâmetros
*/

/* ESTRUTURA DE FUNÇÃO */
void leitura (int &x, string letra){
  do{
    cout << "Valor de " << letra << ": ";
    cin >> x;
    // ao vir pra cá, aqui ele faz referência da letra e ao x, que ao passado nos parâmetros será o "A" e a variável a do main, e como o & foi usado, o valor da variável do main será modificado

    if(x <= 0){
      cout << "Valor inválido! Digite novamente!" << endl;
    }
  } while (x <= 0);
}

int MDC (int a, int b){
  while(a != b){
    (a > b) ? a = a - b : b = b - a;
    // o ? é um condicional
    // expressão ? expressão : expressão
    // operando1 ? operando2 : operando3
    // se o operando1 é verdade, então o operando2 é executado, e se ele for falso, então o operando3 será executado
  }
  return (a);
  // retorna o valor de A apenas
}

int main (){
  int a, b;
  // duas variáveis para esse bloco

  leitura(a, "A");
  leitura(b, "B");
  // aqui chama a função void

  cout << endl << "O MDC de " << a <<" e " << b << " é " << MDC(a, b);

  return 0;
}
