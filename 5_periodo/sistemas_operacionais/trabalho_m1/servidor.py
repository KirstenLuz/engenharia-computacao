# servidor.py
from threading import Thread, Lock
import json
import os

banco_de_dados = []
lock = Lock()


def salvar_banco():
    with open("banco.json", "w") as f:
        json.dump(banco_de_dados, f)


def carregar_banco():
    global banco_de_dados
    if os.path.exists("banco.json"):
        with open("banco.json", "r") as f:
            banco_de_dados = json.load(f)


def processar_comando(comando, conn):
    with lock:
        if comando == "LISTAR":
            conn.send(banco_de_dados.copy())

        elif comando.startswith("INSERT"):
            try:
                _, id, nome = comando.split(maxsplit=2)
                id = int(id)
                if any(r["id"] == id for r in banco_de_dados):
                    conn.send(f"ID {id} já existe.")
                else:
                    banco_de_dados.append({"id": id, "nome": nome})
                    salvar_banco()
                    conn.send(f"Inserido: ID {id}, Nome {nome}")
            except Exception as e:
                conn.send(f"Erro no INSERT: {e}")

        elif comando.startswith("DELETE"):
            try:
                _, id = comando.split()
                id = int(id)
                antes = len(banco_de_dados)
                banco_de_dados[:] = [
                    r for r in banco_de_dados if r["id"] != id]
                salvar_banco()
                if len(banco_de_dados) < antes:
                    conn.send(f"Deletado ID {id}")
                else:
                    conn.send(f"ID {id} não encontrado.")
            except Exception as e:
                conn.send(f"Erro no DELETE: {e}")

        elif comando.startswith("SELECT"):
            try:
                _, id = comando.split()
                id = int(id)
                resultado = next(
                    (r for r in banco_de_dados if r["id"] == id), None)
                if resultado:
                    conn.send(
                        f"Encontrado: ID {id}, Nome: {resultado['nome']}")
                else:
                    conn.send("Registro não encontrado.")
            except Exception as e:
                conn.send(f"Erro no SELECT: {e}")

        elif comando.startswith("UPDATE"):
            try:
                _, id, novo_nome = comando.split(maxsplit=2)
                id = int(id)
                atualizado = False
                for r in banco_de_dados:
                    if r["id"] == id:
                        r["nome"] = novo_nome
                        atualizado = True
                        break
                if atualizado:
                    salvar_banco()
                    conn.send(
                        f"Atualizado: ID {id}, Novo nome: {novo_nome}")
                else:
                    conn.send("ID não encontrado.")
            except Exception as e:
                conn.send(f"Erro no UPDATE: {e}")

        else:
            conn.send("Comando não reconhecido.")


def servidor_loop(conn):
    carregar_banco()

    while True:
        comando = conn.recv()
        print("\nComando recebido:", comando)

        if comando == "EXIT":
            print("Encerrando servidor...")
            break

        Thread(target=processar_comando, args=(comando, conn)).start()
