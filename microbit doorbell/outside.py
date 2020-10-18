import radio
from microbit import *
import time
im = Image("99900:90000:99900:00900:99900")
radio.on()
radio.config(channel=42, power=7)
for i in range(3):
    radio.send("B")
    display.show(im)
    time.sleep(0.5)
    display.clear()
    time.sleep(0.5)
response = None
display.show(Image("00000:00000:00000:00000:00005"))
while not response:
    response = radio.receive()
    time.sleep(0.5)
radio.off()

if response == "Y": im = Image("00000:00009:00090:90900:09000")
elif response == "N": im = Image("90009:09090:00900:09090:90009")
else: im = Image("99990:90000:99990:90000:99990")
for i in range(10):
        display.show(im)
        time.sleep(0.4)
        display.clear()
        time.sleep(0.2)
time.sleep(5)
while True:
    display.scroll("Turn me off!")