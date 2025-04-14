# main.py
from multiprocessing import Pipe, Process
from cliente import cliente_loop
from servidor import servidor_loop


def main():
    cliente_conn, servidor_conn = Pipe()

    servidor = Process(target=servidor_loop, args=(servidor_conn,))
    servidor.start()

    cliente_loop(cliente_conn)

    servidor.join()  # Espera o servidor terminar antes de sair


if __name__ == "__main__":
    main()
