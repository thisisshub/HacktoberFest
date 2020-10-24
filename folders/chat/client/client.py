from socket import AF_INET, SOCK_STREAM, socket
from threading import Thread, Lock
import time


class Client:
    HOST = 'localhost'
    PORT = 1234
    ADDR = (HOST, PORT)
    BUFSIZ = 512

    def __init__(self, name):
        self.client_socket = socket(AF_INET, SOCK_STREAM)
        self.client_socket.connect(self.ADDR)
        self.messages = []
        self.receive_thread = Thread(target=self.receive)
        self.receive_thread.start()
        self.send(name)
        self.lock = Lock()

    def receive(self):
        while True:
            try:
                msg = self.client_socket.recv(self.BUFSIZ).decode()
                self.lock.acquire()
                self.messages.append(msg)
                self.lock.release()
            except Exception as e:
                print("[EXCEPTION]", e)
                break

    def send(self, msg):
        try:
            self.client_socket.send(bytes(msg, "utf8"))
            if msg == "{quit}":
                self.client_socket.close()
        except Exception as e:
            self.client_socket = socket(AF_INET, SOCK_STREAM)
            self.client_socket.connect(self.ADDR)
            print(e)



    def get(self):
        msgs = self.messages[:]
        self.lock.acquire()
        self.messages = []
        self.lock.release()
        return msgs

    def disconnect(self):
        self.send("{quit}")
