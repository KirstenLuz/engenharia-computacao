from multiprocessing import Pipe, Process
from cliente import cliente_loop
from servidor import servidor_loop

def main():
    #cria uma conexão de comunicação entre os dois processos
    conexao_cliente, conexao_servidor = Pipe()

    #cria um processo separado para o servidor
    #target=servidor_loop: Diz ao processo qual função executar quando ele iniciar.
    #args=(conexao_servidor,): Passa os argumentos que essa função precisa, aqui fornecendo uma ponta do pipe para comunicação.
    #o processo do servidor vai ter como parametro o servidor loop que vai fazer todas as
    # opções do cliente e conexão servidor vai conectar as informações do cliente ao servidor
    processo_servidor = Process(target=servidor_loop, args=(conexao_servidor,))
    processo_servidor.start()

    #Executa o loop principal do cliente, passando a conexão do lado do cliente
    cliente_loop(conexao_cliente)
    # Aguarda o término do processo do servidor, por causa do join()
    # o programa ficará esperando aqui até que: O servidor seja encerrado ou de erro
    processo_servidor.join()

if __name__ == "__main__":
    main()
