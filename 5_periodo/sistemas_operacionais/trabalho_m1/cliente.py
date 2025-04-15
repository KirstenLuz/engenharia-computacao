def cliente_loop(conexao_cliente):
    #informa que está tudo certo
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
                id_registro = int(input("Digite o ID: "))
                nome_registro = input("Digite o nome: ")
                #conexao_cliente é uma das pontas do pipe e .send é um método do pipe que envia os dados
                # para a outra ponta do pipe que seria a conexão servidor (linha 94 servidor.py)
                conexao_cliente.send(f"INSERT {id_registro} {nome_registro}")
                #vai imprimir a resposta do servidor após processar o comando INSERT.
                print(conexao_cliente.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")

        elif opcao == "2":
            try:
                id_registro = int(input("Digite o ID para deletar: "))
                conexao_cliente.send(f"DELETE {id_registro}")
                print(conexao_cliente.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")

        elif opcao == "3":
            conexao_cliente.send("LISTAR")
            registros = conexao_cliente.recv()
            print("\nRegistros armazenados:")
            #para cada elemento (que chamamos de 'registro') dentro da lista 'registros', 
            # ele executa a linha abaixo
            for registro in registros:
                print(f"ID: {registro['id']}, Nome: {registro['nome']}")

        elif opcao == "4":
            try:
                id_registro = int(input("Digite o ID para buscar: "))
                conexao_cliente.send(f"SELECT {id_registro}")
                print(conexao_cliente.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")

        elif opcao == "5":
            try:
                id_registro = int(input("Digite o ID para atualizar: "))
                novo_nome = input("Digite o novo nome: ")
                conexao_cliente.send(f"UPDATE {id_registro} {novo_nome}")
                print(conexao_cliente.recv())
            except ValueError:
                print("ID inválido. Digite um número inteiro.")

        elif opcao == "6":
            conexao_cliente.send("EXIT")
            print("Encerrando cliente...")
            break
        else:
            print("Opção inválida. Tente novamente.")
