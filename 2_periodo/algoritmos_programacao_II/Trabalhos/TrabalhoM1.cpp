#include <iostream>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;
#define TAM 5
// Tamanho das cartelas
#define TAM2 75
// Quantidade de números a serem sorteados
#define TAM3 5
// Quantidade de jogadores

// Define as cores para o código
#define background_purple_color "\033[48;5;"
#define pink_color "\033[38;5;206m"
#define purple_color "\033[38;5;141m"
#define reset_color "\033[0m"

// Função para colorir o bingo
void setBackgroundColor(int colorCode) {
  std::cout << background_purple_color << colorCode << "m";
}

// Menu do jogo
void opcoes_menu(int &Menu) {
  cout << pink_color
       << "**************************************************************\n";
  cout << "            BBBBBB   IIIII  N     N  GGGGGG  OOOOO            \n";
  cout << "            B     B    I    NN    N G       O     O           \n";
  cout << "            BBBBBB     I    N N   N G  GGGG O     O           \n";
  cout << "            B     B    I    N  N  N G     G O     O           \n";
  cout << "            BBBBBB   IIIII  N    NN  GGGGGG  OOOOO            \n";
  cout << "**************************************************************"
       << reset_color << endl;
  cout << purple_color << "1 - Jogar\n";
  cout << "2 - Sobre\n";
  cout << "3 - Sair" << reset_color << endl;
  cout << purple_color
       << "**************************************************************\n";
  cout << reset_color;
  cout << "Digite a opção desejada: ";
  cin >> Menu;
  system("clear");
}

// Função de informações do trabalho
void informacoes() {
  cout << purple_color;
  cout << "Univali - Engenharia da Computação - 2º semestre - Agosto de 2023 "
       << "\n";
  cout << reset_color << endl;
  cout << "Acadêmicos: Isabella Zermiani Bastos, Milene Emmel, Kirsten Luz e "
          "Sthephany Araceli Melho Dos Santos."
       << "\n"
       << endl;
  cout << "Disciplina: Algoritmos e programação II"
       << "\n"
       << endl;
  cout << "Professor: Rafael Ballottin Martins"
       << "\n"
       << "\n";
}

// Função que pede nome dos jogadores, esta função pede o nome dos jogadores e armazena os nomes em um array jogadores.
void pedir_jogadores(string jogadores[TAM3]) {
  cout << "Digite o nome dos cinco jogadores: " << endl;
  for (int i = 0; i < TAM3; i++) {
    cout << "Jogador " << i + 1 << ": ";
    cin >> jogadores[i];
  }
}

// Função que limpa o console.

void pressione_enter() {
  cout << "Pressione enter para continuar...";
  cin.get();
  cin.ignore();
  system("clear");
}

// Função que limpa antes de sortear
void pressione_enter_sortear() {
  cout << "Pressione enter para sortear um novo número...";
  cin.ignore();
  cin.get();
  system("clear");
}

// Função para ordenação das linhas na matriz, esta função implementa o algoritmo de ordenação de bolhas para ordenar as linhas de uma matriz (uma cartela de Bingo).
void bubblesort_matriz(int cartela[TAM][TAM], int k) {
  int i = 0, j = 0, cond, temp;
  cond = 1;
  for (i = TAM - 1; (i >= 1) && (cond == 1); i--) {
    cond = 0;
    for (j = 0; j < i; j++) {
      if (cartela[k][j + 1] < cartela[k][j]) {
        temp = cartela[k][j];
        cartela[k][j] = cartela[k][j + 1];
        cartela[k][j + 1] = temp;
        cond = 1;
      }
    }
  }
}

// Função que ordena todos os valores do vetor,esta função implementa o algoritmo de ordenação de bolhas para ordenar um vetor de números.
void bubblesort_vetor(int vet[TAM2], int n) {
  int i, j, troca, cond;
  cond = 1;
  for (i = n - 1; (i >= 1) && (cond == 1); i--) {
    cond = 0;
    for (j = 0; j < i; j++) {
      if (vet[j + 1] < vet[j]) {
        troca = vet[j];
        vet[j] = vet[j + 1];
        vet[j + 1] = troca;
        cond = 1;
      }
    }
  }
}

// Função que impede números repetidos na matriz, garante que não haja números repetidos em uma linha específica de uma cartela de Bingo.
void numeros_repetidos_matriz(int cartela[TAM][TAM], int l) {
  int cond;
  do {
    cond = 0;
    for (int i = 0; i < TAM; i++) {
      for (int j = 0; j < TAM; j++) {
        if (i != j && cartela[l][i] == cartela[l][j]) {
          cartela[l][i] = rand() % 15 + (l * 15 + 1);
          cond = 1;
        }
      }
    }
  } while (cond == 1);
}

// Função que gera a cartela
void gerar(int cartela[TAM][TAM]) {
  int cond;
  for (int l = 0; l < TAM; l++) {
    for (int c = 0; c < TAM; c++) {
      cartela[l][c] = rand() % 15 + (l * 15 + 1);
    }
    // Garante que não haja números parecidos
    numeros_repetidos_matriz(cartela, l);
  }

  // Bubblesort para a ordenação da linha
  for (int k = 0; k < TAM; k++) {
    bubblesort_matriz(cartela, k);
  }
}

// Função que impede que as cartelas sejam iguais
int cartela_igual(int cartela1[TAM][TAM], int cartela2[TAM][TAM],
                  int cartela3[TAM][TAM], int cartela4[TAM][TAM],
                  int cartela5[TAM][TAM]) {
  int cond;
  cond = 0;
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      if (cartela1[i][j] != cartela2[i][j] &&
          cartela1[i][j] != cartela3[i][j] &&
          cartela1[i][j] != cartela4[i][j] &&
          cartela1[i][j] != cartela5[i][j] &&
          cartela2[i][j] != cartela3[i][j] &&
          cartela2[i][j] != cartela4[i][j] &&
          cartela2[i][j] != cartela5[i][j] &&
          cartela3[i][j] != cartela4[i][j] &&
          cartela3[i][j] != cartela5[i][j] &&
          cartela4[i][j] != cartela5[i][j]) {
        cond = 1;
        return cond;
      }
    }
  }
  return cond;
  // Se cond for igual a zero as cartelas são iguais e precisam ser sorteadas
  // novamente
}

// Função que imprime uma cartela
void imprimir(int cartela[TAM][TAM]) {
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      cout << cartela[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

// Função que imprime todas as cartelas
void imprimir_cartelas(int cartela1[TAM][TAM], int cartela2[TAM][TAM],
                       int cartela3[TAM][TAM], int cartela4[TAM][TAM],
                       int cartela5[TAM][TAM], string jogadores[TAM]) {
  cout << endl << "Jogador " << jogadores[0] << " - cartela 1" << endl;
  imprimir(cartela1);
  cout << "Jogador " << jogadores[1] << " - cartela 2" << endl;
  imprimir(cartela2);
  cout << "Jogador " << jogadores[2] << " - cartela 3" << endl;
  imprimir(cartela3);
  cout << "Jogador " << jogadores[3] << " - cartela 4" << endl;
  imprimir(cartela4);
  cout << "Jogador " << jogadores[4] << " - cartela 5" << endl;
  imprimir(cartela5);
}

// Função que gera as cartelas, impede que sejam iguais e imprime elas
void geracao_de_cartelas(int cartela_1[TAM][TAM], int cartela_2[TAM][TAM], int cartela_3[TAM][TAM], int cartela_4[TAM][TAM],int cartela_5[TAM][TAM], string jogadores[TAM]) {

  // Esse laço do while impede que as cartelas parem de ser geradas até que
  // todas sejam diferentes
  do {
    gerar(cartela_1);
    gerar(cartela_2);
    gerar(cartela_3);
    gerar(cartela_4);
    gerar(cartela_5);
  } while (cartela_igual(cartela_1, cartela_2, cartela_3, cartela_4, cartela_5) == 0);

  imprimir_cartelas(cartela_1, cartela_2, cartela_3, cartela_4, cartela_5, jogadores);
}

// Função que impede a repetição de números no sorteio
void numeros_repetidos_vetor(int numeros_bingo[TAM2], int i) {
  int cond;
  do {
    cond = 1;
    for (int j = 0; j < i; j++) {
      if (numeros_bingo[j] == numeros_bingo[i]) {
        numeros_bingo[i] = rand() % TAM2 + 1;
        cond = 0;
      }
    }
  } while (cond != 1);
}

// Função que mostra o número sorteado
void numero_sorteado(int numeros_bingo[TAM2], int i) {
  cout << endl;
  cout << "Número sorteado: " << numeros_bingo[i];
  cout << endl << endl;
}

// Função lista de todos os números já sorteados e ordenação deles no vetor
void numeros_ja_sorteados(int vet[], int n) {
  bubblesort_vetor(vet, n);
  // Ordena de forma crescente os números sorteados
  cout << "Números já sorteados:";
  for (int i = 0; i < n; i++) {
    cout << "|" << vet[i] << "|";
  }
  cout << endl;
}

// Verdadeiro ou falso para pintar o número da cartela
bool verificando(int numero, int vet[], int n) {
  for (int k = 0; k <= n; k++) {
    if (numero == vet[k])
      // Verifica se o número da cartela é igual a algum dos números já
      // sorteados
      return true;
  }
  return false;
}

// Função que compara as cartelas com o vetor e imprime coloridas
void comparacao_cartelas(int cartela[TAM][TAM], int numeros_do_sorteio[], int n,
                         int &contador) {
  contador = 0;
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      if (verificando(cartela[i][j], numeros_do_sorteio, n) == true) {
        setBackgroundColor(128);
        cout << cartela[i][j] << "\t";
        // Imprime os números da cartela que correspondem com os números que ja
        // foram sorteados
        cout << reset_color;
        // Reseta a cor original
        contador++;
        // Verifica se a cartela irá dar bingo
      } else {
        cout << cartela[i][j] << "\t";
        // Imprime os números que estão na cartela e não foram sorteados ainda
        // na cor original
      }
    }
    cout << endl;
  }
}

// Função que imprime todas as cartelas do bingo junto com o nome dos jogadores
void imprimir_todas_cartelas_bingo(
    string jogadores[TAM], int cartela1[TAM][TAM], int cartela2[TAM][TAM],
    int cartela3[TAM][TAM], int cartela4[TAM][TAM], int cartela5[TAM][TAM],
    int numeros_bingo[TAM2], int i, int &contador1, int &contador2,
    int &contador3, int &contador4, int &contador5) {

  cout << "Jogador " << jogadores[0] << " - Cartela 1\n";
  comparacao_cartelas(cartela1, numeros_bingo, i, contador1);
  cout << endl;

  cout << "Jogador " << jogadores[1] << " - Cartela 2\n";
  comparacao_cartelas(cartela2, numeros_bingo, i, contador2);
  cout << endl;

  cout << "Jogador " << jogadores[2] << " - Cartela 3\n";
  comparacao_cartelas(cartela3, numeros_bingo, i, contador3);
  cout << endl;

  cout << "Jogador " << jogadores[3] << " - Cartela 4\n";
  comparacao_cartelas(cartela4, numeros_bingo, i, contador4);
  cout << endl;

  cout << "Jogador " << jogadores[4] << " - Cartela 5\n";
  comparacao_cartelas(cartela5, numeros_bingo, i, contador5);
  cout << endl;
}

// Função do bingo
void bingo(int numeros_bingo[], int cartela1[TAM][TAM], int cartela2[TAM][TAM], int cartela3[TAM][TAM], int cartela4[TAM][TAM], int cartela5[TAM][TAM], string jogadores[], int &contador1, int &contador2, int &contador3, int &contador4, int &contador5) {

  for (int i = 0; i < TAM2; i++) {
    numeros_bingo[i] = rand() % TAM2 + 1;
    // Sorteia os números do bingo de 1 a 75

    numeros_repetidos_vetor(numeros_bingo, i);
    // Garante que não haverão números iguais no sorteio

    numero_sorteado(numeros_bingo, i);
    // Mostra o número que foi sorteado

    imprimir_todas_cartelas_bingo(jogadores, cartela1, cartela2, cartela3, cartela4, cartela5, numeros_bingo, i, contador1, contador2, contador3, contador4, contador5);
    // Imprime as cartelas

    numeros_ja_sorteados(numeros_bingo, i);
    // Mostra lista de números sorteados e organiza eles no vetor

    if (contador1 == TAM*TAM) {
      cout << pink_color;
      cout << "Parabéns " << jogadores[0]
           << " - cartela 1, você ganhou o bingo!";
      cout << reset_color;
      system("clear");
      break;
    } else if (contador2 == TAM*TAM) {
      cout << pink_color;
      cout << "Parabéns " << jogadores[1]
           << " - cartela 2, você ganhou o bingo!";
      cout << reset_color;
      system("clear");
      break;
    } else if (contador3 == TAM*TAM) {
      cout << pink_color;
      cout << "Parabéns " << jogadores[2]
           << " - cartela 3, você ganhou o bingo!";
      cout << reset_color;
      system("clear");
      break;
    } else if (contador4 == TAM*TAM) {
      cout << pink_color;
      cout << "Parabéns " << jogadores[3]
           << " - cartela 4, você ganhou o bingo!";
      cout << reset_color;
      system("clear");
      break;
    } else if (contador5 == TAM*TAM) {
      cout << pink_color;
      cout << "Parabéns " << jogadores[4]
           << " - cartela 5, você ganhou o bingo!";
      cout << reset_color;
      system("clear");
      break;
    } else {
      pressione_enter_sortear();
    }
    // If que quebra o laço quando alguma das cartelas dá bingo
  }
}

int main() {
  srand(time(NULL));
  int Menu, cartela_1[TAM][TAM], cartela_2[TAM][TAM], cartela_3[TAM][TAM],
      cartela_4[TAM][TAM], cartela_5[TAM][TAM], sorteio[TAM2], contador1,
      contador2, contador3, contador4, contador5;
  string jogadores[TAM3];
  // Laço do while para que o menu continue se repetindo até o usuário
  // determinar a saída
  do {
    // Função para opções do menu
    opcoes_menu(Menu);
    // If que impede que o usuário escolha outra opção além das apresentadas no
    // menu
    if (Menu <= 0 || Menu > 3)
      // Evitar erros na hora de escolher a opção do menu
      cout << "Número inválido, selecione uma opção válida.\n" << endl;
    // Switch para opções do jogo
    switch (Menu) {
    case 1:
      // Pede os nomes dos jogadores
      pedir_jogadores(jogadores);
      // Gera as cartelas do bingo
      geracao_de_cartelas(cartela_1, cartela_2, cartela_3, cartela_4, cartela_5,
                          jogadores);
      cout << "Início do bingo" << endl;
      // Limpa o console
      pressione_enter();
      // Começa o jogo do bingo
      bingo(sorteio, cartela_1, cartela_2, cartela_3, cartela_4, cartela_5,
            jogadores, contador1, contador2, contador3, contador4, contador5);
      // Limpa o console após o jogo acabar
      system("clear");
      // Pede que pressione enter novamente para voltar ao menu e reiniciar o
      // jogo
      cout << endl;
      pressione_enter();
      break;

    case 2:
      system("clear");
      // Exibe as informações do jogo
      informacoes();
      pressione_enter();
      break;

    } // Fim do switch "Menu"
  } while (Menu != 3);
  // Repete enquanto o usuário não sai do jogo
  system("clear");
  return 0;
}
