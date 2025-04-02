// Lista de exercícios
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

/* Exercício 1
Faça um programa que permita o cadastro do código, nome e três
notas de vários alunos. Imprima o código, o nome e a média de cada aluno.

#define TAM 2

struct cadastro{
  string nome;
  long codigo;
  double notas[3];
};

void ler(cadastro leitura[TAM]){
  for(int i = 0; i < TAM; i++){
    cout << i+1 << "º aluno" << endl;
    cout << "Digite o nome do aluno: ";
    cin >> leitura[i].nome;
    cout << "Digite o código do aluno: ";
    cin >> leitura[i].codigo;
    cout << "Digite três notas do aluno: ";
    cin >> leitura[i].notas[0] >> leitura[i].notas[1] >> leitura[i].notas[2]; 
    cout << endl;
  }
}

double media(cadastro media[TAM], long aluno){
  double resultado = 0, final;
  for(int i = 0; i < TAM; i++){
    if(aluno == media[i].codigo){
      for(int j = 0; j < 3; j++){
        resultado += media[i].notas[j];
      }
        final = resultado / 3;
      return (final);
    }
  }
}

int main() {
  cadastro alunos[TAM];
  long codigo_aluno;

  ler(alunos);

  cout << "Digite o código do aluno: ";
  cin >> codigo_aluno;

  cout << "A média do aluno foi " << media(alunos, codigo_aluno);
  
  return 0;
}

*/

/* Exercício 2 
Faça um programa que receba o nome, a altura, o peso e o cpf de 
três pessoas, em seguida permita a localização de uma pessoa através do seu CPF e imprima o seu IMC.

#define TAM 1

struct cadastro{
  string nome;
  float altura, peso;
  int cpf;
};

void ler(cadastro leitura[TAM]){
  for(int i = 0; i < TAM; i++){
    cout << i+1 << "º cadastro" << endl;
    cout << "Digite o nome: ";
    cin >> leitura[i].nome;
    cout << "Digite o cpf: ";
    cin >> leitura[i].cpf;
    cout << "Digite a altura e o peso: ";
    cin >> leitura[i].altura >> leitura[i].peso;
  }
}

void IMC(cadastro calculo[TAM], int n){
  float resultado;

  resultado = calculo[n].peso / (calculo[n].altura * calculo[n].altura);

  if(resultado < 18.5){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado abaixo do peso.";
  } else if (resultado > 18.6 && resultado < 24.9){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado no peso ideal.";
  } else if (resultado > 25.0 && resultado < 29.9){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado como levemente acima do peso.";
  } else if (resultado > 30.0 && resultado < 34.9){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado como obesidade grau I.";
  } else if (resultado > 35.0 && resultado < 39.9){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado como obesidade grau II (severa).";
  } else if (resultado > 40){
    cout << "\nO índice de massa corporal do(a) " << calculo[n].nome << " é " << resultado << ", sendo considerado como obesidade III (mórbida).";
  }
}

int main(){
  cadastro pessoas[TAM];
  int localiza;

  ler(pessoas);

  cout << "\nDigite um cpf para o cálculo: ";
  cin >> localiza;

  for(int i = 0; i < TAM; i++){
    if(localiza == pessoas[i].cpf){
      IMC(pessoas, i);
    }
  }

}

*/

/* Exercício 4
Faça um programa que permita o cadastro de cinco produtos e 
imprima uma lista com o código e nome da cada um. Ao final, o
programa deve permitir a consulta de um produto através do seu 
código

#define TAM 5

struct cadastro{
  string nome;
  long codigo;
};

void leitura(cadastro produtos[TAM]){
  for(int i = 0; i < TAM; i++){
    cout << i+1 << "º produto" << endl;
    cout << "Digite o nome e o código do produto: ";
    cin >> produtos[i].nome >> produtos[i].codigo;
  }
}

void consulta(cadastro produtos[TAM]){
  long loc;
  cout << "Digite o código do produto: ";
  cin >> loc;
  for(int i = 0; i < TAM; i++){
    if(loc == produtos[i].codigo)
      cout << produtos[i].codigo << " = " << produtos[i].nome;
  }
}

int main(){
  cadastro produtos[TAM];

  leitura(produtos);

  consulta(produtos);

  return 0;
}
*/

/* Exercício 5 
Escreva um programa que simule contas bancárias
Ao iniciar o programa vamos criar contas bancárias para três 
clientes.
- Cada conta deve ter o nome e o CPF do cliente associado a ela.
- No ato da criação da conta o cliente precisará fazer um 
depósito inicial.
- Após as contas serem criadas, o sistema deverá possibilitar 
realizações de saques ou depósitos nas contas.
- Sempre que uma operação de saque ou depósito seja 
realizada, o sistema deverá imprimir o nome do titular e o 
saldo final da conta
*/

#define TAM 2

struct cadastro{
  string nome;
  long cpf;
  double deposito;
};

void informacoes(cadastro pessoa[TAM]){
  for(int i = 0; i < TAM; i++){
    cout << i+1 << "º cadastro" << endl;
    cout << "Digite o nome e o CPF do cliente: ";
    cin >> pessoa[i].nome >> pessoa[i].cpf;
    cout << "Depósito inicial: ";
    cin >> pessoa[i].deposito;
    cout << endl;
  }
}

void acoes(cadastro pessoa[TAM], int n, long usuario){
  double saque, deposito, saldo;
  for(int i = 0; i < TAM; i++){
    if(usuario == pessoa[i].cpf){
      if(n == 1){
        cout << "Digite o valor do saque: ";
        cin >> saque;
        saldo = pessoa[i].deposito - saque;
        pessoa[i].deposito = saldo;
        cout << endl << pessoa[i].nome << " - " << pessoa[i].cpf << endl << "Saldo atual: " << pessoa[i].deposito;
      } else if(n == 2){
        cout << "Digite o valor do depósito: ";
        cin >> deposito;
        saldo = pessoa[i].deposito + deposito;
        pessoa[i].deposito = saldo;
        cout << endl << pessoa[i].nome << " - " << pessoa[i].cpf << endl << "Saldo atual: " << pessoa[i].deposito;
      }
    }
  }
}

int main(){
  cadastro pessoa[TAM];
  int menu;
  long localizar;

  informacoes(pessoa);

  cout << "Digite seu CPF: ";
  cin >> localizar;
  cout << endl << "1. Saque\n2. Depósito\n3. Sair\nSelecione uma opção acima: ";
  cin >> menu;

  switch(menu){
    case 1:
      acoes(pessoa, menu, localizar);
      break;
    case 2:
      acoes(pessoa, menu, localizar);
      break;
    case 3:
      cout << "Finalizando...";
      break;
  }
  
  return 0;
}
