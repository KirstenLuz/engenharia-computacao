// Exercício - Arquivos
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  char url[] = "notas.txt";
  float nota, media = 0.0;
  int n;

  ofstream arq;
  // Abre/Cria o arquivo texto para adicionar linhas ao final
  arq.open(url, ofstream::app);
  // Verifica se houve erro na abertura do arquivo
  if(!arq.is_open()){
    cout << "Erro, nao foi possivel abrir o arquivo\n";
    return 1;
  }

  cout << "Quantas médias parciais houve para a disciplina? ";
  cin >> n;

  for (int i = 1; i <= n; i++){
  // Lê a nota
  cout << "Digite a nota " << i << ": ";
  cin >> nota;
  // Grava a nota no arquivo
  arq << "M" << i << ": " <<  "nota: " << nota << endl;
  // Acumula a nota para calcular a média
  media += nota;
  }

  // Calcula a média final
  media /= n;
  // Grava a média no arquivo

  arq << "Media final: " << media << endl << endl;

  // Fecha o arquivo
  arq.close();

  return 0;
}
