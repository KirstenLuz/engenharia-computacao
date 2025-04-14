# **Trabalho M1 – Sistemas Operacionais**

## **Objetivo**

Este projeto simula o funcionamento de um sistema de gerenciamento de banco de dados utilizando conceitos de:

- Comunicação entre Processos (IPC)
- Threads
- Concorrência com Mutex
- Processamento Paralelo

## **Estrutura do Projeto**

A estrutura do projeto está organizada da seguinte maneira:

trabalho_m1/

├── main.py # arquivo principal que inicializa a comunicação e os processos

├── cliente.py # arquivo que contém a lógica do cliente que se comunica com o servidor

├── servidor.py # arquivo que contém a lógica do servidor que processa as requisições

├── banco.json # banco de dados simulado em formato JSON

├── pycache/ # pasta gerada automaticamente pelo Python

└── .gitignore # arquivo para ignorar arquivos temporários como pycache

## **Arquitetura do Sistema**

O sistema é composto por dois componentes principais:

### **1. Cliente**

O cliente interage com o usuário e envia comandos para o servidor, como **INSERT**, **DELETE**, **SELECT**, **UPDATE**, e **LISTAR**.

### **2. Servidor**

O servidor gerencia o banco de dados, processando os comandos do cliente de forma concorrente com a utilização de threads e mutex para garantir a integridade dos dados.

## **Tecnologias Utilizadas**

- **Python 3.x**: Linguagem de programação utilizada.
- **Multiprocessing**: Comunicação entre processos e execução paralela.
- **Threading**: Para gerenciar múltiplas requisições simultâneas no servidor.
- **JSON**: Para persistência de dados.
- **Mutex**: Controle de concorrência e integridade dos dados.

## **Como Rodar o Projeto**

### **Pré-requisitos**

- Python 3.x instalado.

### **Passos para executar:**

Como executar o projeto no GitHub Codespaces

1. Abra o ambiente de Codespace
   
   Na página do repositório _engenharia-computacao_, siga os passos:
   - Clique no botão **Code**
   - Selecione a aba **Codespaces**
   - Clique em **+ Create codespace on main**

2. Acesse a pasta do projeto no terminal
   
Assim que o ambiente for carregado, no terminal integrado, digite o seguinte comando para navegar até a pasta do trabalho:
   
   **_cd 5_periodo/disciplinas/sistemas_operacionais/trabalho_m1_**

3. Execute o programa
   
No terminal, rode o programa com o comando:
   
   **_python3 main.py_**

4. Interaja com o sistema
   
O menu do cliente será exibido e você poderá testar as funcionalidades do sistema, como inserir, listar, buscar, atualizar e deletar registros.

## Exemplo de Execução


- O cliente apresentará um menu de opções para interagir com o banco de dados.
- O servidor processa os comandos e responde ao cliente.
