from socket import AF_INET, SOCK_STREAM, socket
from threading import Thread
import time
from person import Person

HOST = ''
PORT = 1234
ADDR = (HOST, PORT)
MAX_CONNECTIONS = 10
BUFSIZ = 512
persons = []
SERVER = socket(AF_INET, SOCK_STREAM)
SERVER.bind(ADDR)


def broadcast(msg, name):
    for person in persons:
        client = person.client
        try:
            client.send(bytes(name, "utf8") + msg)
        except Exception as e:
            print("[EXCEPTION]", e)


def handle_client(person):
    client = person.client
    name = client.recv(BUFSIZ).decode("utf8")
    person.set_name(name)
    msg = bytes(f"{name} has joined the chat!","utf8")
    broadcast(msg, "")
    while True:  # wait for any messages from person
        msg = client.recv(BUFSIZ)

        if msg == bytes("{quit}", "utf8"):  # if message is qut disconnect client
            client.close()
            persons.remove(person)
            broadcast(bytes(f"{name} has left the chat...", "utf8"), "")
            print(f"[DISCONNECTED] {name} disconnected")
            break
        else:  # otherwise send message to all other clients
            broadcast(msg, name+": ")
            print(f"{name}: ", msg.decode("utf8"))


def accept_incoming_connections():
    while True:
        try:
            client, addr = SERVER.accept()
            person = Person(addr, client)
            persons.append(person)
            print(f"[CONNECTION]{ADDR} connected to the server at time{time.time()}")
            Thread(target=handle_client, args=(person,)).start()
        except Exception as e:
            print("[EXCEPTION]", e)
            break

    print("SERVER CRASHED")


if __name__ == "__main__":
    SERVER.listen(MAX_CONNECTIONS)
    print("waiting for connection......")
    ACCEPT_THREAD = Thread(target=accept_incoming_connections,)
    ACCEPT_THREAD.start()
    ACCEPT_THREAD.join()
    SERVER.close()
