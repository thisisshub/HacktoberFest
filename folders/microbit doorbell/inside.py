import radio
from microbit import *
import time
radio.on()
while True:
    radio.config(channel=42, power=0)
    button_a.was_pressed()
    button_b.was_pressed()
    for i in range(10): radio.receive() # clear queue
    while not radio.receive(): # wait for msg
        time.sleep(5)
    
    send = ""
    while not send: # get attention
        display.show(Image("99999:"*5))
        time.sleep(0.2)
        display.clear()
        time.sleep(0.2)
        if button_a.was_pressed():
            send = "N"
        if button_b.was_pressed():
            send = "Y"
    
    radio.config(channel=42, power=7)
    im = Image("99900:90000:99900:00900:99900")
    for i in range(3):
        radio.send(send)
        display.show(im)
        time.sleep(0.5)
        display.clear()
        time.sleep(0.5)