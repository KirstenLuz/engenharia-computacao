# cliente.py
def cliente_loop(conn):
    print("Cliente conectado ao servidor.")
    
    while True:
        print("\nMENU DE OPERAÇÕES")
        print("=========================")
        print("1. Inserir novo registro")
        print("2. Deletar registro existente")
        print("3. Listar todos os registros")
        print("4. Buscar registro por ID (SELECT)")
        print("5. Atualizar nome de registro (UPDATE)")
        print("6. Encerrar conexão")
        print("=========================")

        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            try:
                id = int(input("Digite o ID: "))
                nome = input("Digite o nome: ")
                conn.send(f"INSERT {id} {nome}")
                print(conn.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")
        elif opcao == "2":
            try:
                id = int(input("Digite o ID para deletar: "))
                conn.send(f"DELETE {id}")
                print(conn.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")
        elif opcao == "3":
            conn.send("LISTAR")
            dados = conn.recv()
            print("\nRegistros armazenados:")
            for registro in dados:
                print(f"ID: {registro['id']}, Nome: {registro['nome']}")
        elif opcao == "4":
            try:
                id = int(input("Digite o ID para buscar: "))
                conn.send(f"SELECT {id}")
                print(conn.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")
        elif opcao == "5":
            try:
                id = int(input("Digite o ID para atualizar: "))
                novo_nome = input("Digite o novo nome: ")
                conn.send(f"UPDATE {id} {novo_nome}")
                print(conn.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")
        elif opcao == "6":
            conn.send("EXIT")
            print("Encerrando cliente...")
            break
        else:
            print("Opção inválida. Tente novamente.")
