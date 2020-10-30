import pyttsx3

engine = pyttsx3.init()
engine.setProperty("rate", 120)
n = input(")
engine.say(f" {n} !")
engine.runAndWait()
