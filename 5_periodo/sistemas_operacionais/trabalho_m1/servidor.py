from threading import Thread, Lock
import json
import os

banco_de_dados = [] #cria a lista que vai armazenar todos os registros
acesso_ao_banco = Lock() #controle de acesso, caso multiplas threads tentem acessar o banco

def salvar_banco():
    with open("banco.json", "w") as arquivo_json:
        json.dump(banco_de_dados, arquivo_json)

def carregar_banco():
    global banco_de_dados
    if os.path.exists("banco.json"):
        with open("banco.json", "r") as arquivo_json:
            banco_de_dados = json.load(arquivo_json)
#opção 3 do MENU  LISTAR
def processar_comando(comando_recebido, conexao_cliente):
    
    with acesso_ao_banco: #Tranca o acesso por causa do Lock, só vai abrir o acesso quando terminar de executar
        if comando_recebido == "LISTAR":
            conexao_cliente.send(banco_de_dados.copy())

#opção 1 do menu INSERIR
        elif comando_recebido.startswith("INSERT"):
            try:
                _, id_str, nome = comando_recebido.split(maxsplit=2) #divide a variavel em 3 partes (INSERT, ID, NOME)
                id_registro = int(id_str)
                #Se existir um registro com o mesmo ID ele diz que ja existe
                if any(registro["id"] == id_registro for registro in banco_de_dados):
                    conexao_cliente.send(f"ID {id_registro} já existe.")
                else:
                    banco_de_dados.append({"id": id_registro, "nome": nome})
                    salvar_banco()
                    conexao_cliente.send(f"Inserido: ID {id_registro}, Nome {nome}")
            except Exception as erro:
                conexao_cliente.send(f"Erro no INSERT: {erro}")

#opção 2 do menu DELETAR registro existente
        elif comando_recebido.startswith("DELETE"):
            try:
                _, id_str = comando_recebido.split() #divide  a string ["DELETE", "10"]
                id_registro = int(id_str)
                quantidade_antes = len(banco_de_dados) #retorna o numero de registros na lista
                banco_de_dados[:] = [   #substitui todos os elementos da lista original
                    #percorre cada registro em banco_de_dados, mantem apenas os registros cujo o ID seja 
                    # diferente de id_registro, que no caso é o que eu apaguei
                    registro for registro in banco_de_dados if registro["id"] != id_registro
                ]
                salvar_banco()
                #compara para confirmar que foi deletado
                if len(banco_de_dados) < quantidade_antes:
                    conexao_cliente.send(f"Deletado ID {id_registro}")
                else:
                    conexao_cliente.send(f"ID {id_registro} não encontrado.")
            except Exception as erro:
                conexao_cliente.send(f"Erro no DELETE: {erro}")

#opção 4 do menu SELECT
        elif comando_recebido.startswith("SELECT"): #verifica o tipo de comando recebido, se for o SELECT esta ok
            try:
                _, id_str = comando_recebido.split()#divide  a string ["SELECT", "10"]
                id_registro = int(id_str)
                #ele quer encontrar o ID digitado, entao ele verifica cada registro em ordem (next) ate encontrar o que satisfaz 
                resultado = next((registro for registro in banco_de_dados if registro["id"] == id_registro),
                    None) # se ele nao encontrar o resgistro que eu procuro entao retorna none
                if resultado:
                    conexao_cliente.send(
                        f"Encontrado: ID {id_registro}, Nome: {resultado['nome']}")
                else:
                    conexao_cliente.send("Registro não encontrado.")
            except Exception as erro:
                conexao_cliente.send(f"Erro no SELECT: {erro}")

#opção 5 do menu UPDATE
        elif comando_recebido.startswith("UPDATE"):
            try:
                _, id_str, novo_nome = comando_recebido.split(maxsplit=2)
                id_registro = int(id_str)
                atualizado = False
                 # Percorre todos os registros do banco de dados
                for registro in banco_de_dados:
                    # Verifica se encontrou o registro com o ID especificado
                    if registro["id"] == id_registro:
                        registro["nome"] = novo_nome
                        atualizado = True
                        break
                if atualizado:
                     # Salva as alterações no arquivo JSON
                    salvar_banco()
                    conexao_cliente.send(
                        f"Atualizado: ID {id_registro}, Novo nome: {novo_nome}")
                else:
                    conexao_cliente.send("ID não encontrado.")
            except Exception as erro:
                conexao_cliente.send(f"Erro no UPDATE: {erro}")
        else:
            conexao_cliente.send("Comando não reconhecido.")


def servidor_loop(conexao_servidor):
    carregar_banco() #carrega os dados no arquivo JSON e inicializa o banco de dados quando o servidor inicia

    while True:
        #aqui ele recebe as informações enviadas do conexao_cliente.send (linha:24 cliente.py)
        comando_recebido = conexao_servidor.recv() #Recebe a mensagem do cliente
        print("\nComando recebido:", comando_recebido)

#opção 6 do menu ENCERRAR
        if comando_recebido == "EXIT":
            print("Encerrando servidor...")
            break # Sai do loop while, encerrando a função/servidor

        # Para cada comando recebido, cria uma NOVA THREAD para processá-lo
        # Isso permite que o servidor continue recebendo outros comandos
        # enquanto processa os anteriores (concorrência)
        Thread(target=processar_comando, #função que a thread vai executar
               args=(comando_recebido, conexao_servidor)
               ).start()
