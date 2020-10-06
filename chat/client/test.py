from client import Client
import time
from threading import Thread

b1 = input("enter your name ")
c1 = Client(b1)


def update():
    msgs = []
    run = True
    while run:
        time.sleep(0.2)
        new_messages = c1.get()
        msgs.extend(new_messages)
        for msg in new_messages:
            print(msg)
            if msg == "{quit}":
                run = False
                break


Thread(target=update).start()

while True:
    ma = input()
    c1.send(ma)
