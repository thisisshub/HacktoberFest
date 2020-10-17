import pyttsx3

engine = pyttsx3.init()
engine.setProperty("rate", 120)
print("Enter your name")
n = input()
engine.say(f"Hello {n} !")
engine.runAndWait()
