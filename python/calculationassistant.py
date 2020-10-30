import pyttsx3 
engine = pyttsx3.init()
engine.say("Hello, what is your name.")
engine.runAndWait()
name = input("Enter your name: ")
engine.say("Hello "+name+". What do you want me to do?")
engine.runAndWait()
# speak = input("what do you want me to speak: ")
# engine.say(speak)
dotask = input("what do you want me to do: ")
if dotask== "calculation" or "calc":
    engine.say("enter no 1: ")
    engine.runAndWait()
    no1= int(input("enter no 1: "))
    engine.say("enter no 2: ")
    engine.runAndWait()
    no2= int(input("enter no 2: "))
    engine.say("enter any operator")
    engine.runAndWait()
    oper= (input("enter any operator + - / * % : "))
    engine.say("You entered"+ oper+ " operator")
    engine.runAndWait()
else:
    engine.say("error bro")
    engine.runAndWait()

if oper == "+":
    print(str(no1)+" + "+str(no2)+" = "+str(no1+no2))
    engine.say(str(no1) +" + "+ str(no2) +" is "+ str(no1+no2))
elif oper == "-":
    print(str(no1)+" - "+str(no2)+" = "+str(no1-no2))
    engine.say(str(no1) +" - "+ str(no2) +" is "+ str(no1-no2))
elif oper == "*":
    print(str(no1)+" * "+str(no2)+" = "+str(no1*no2))
    engine.say(str(no1) +" * "+ str(no2) +" is "+ str(no1*no2))
elif oper == "/":
    print(str(no1)+" / "+str(no2)+" = "+str(no1/no2))
    engine.say(str(no1) +" / "+ str(no2) +" is "+ str(no1/no2))
elif oper == "%":
    print(str(no1)+" % "+str(no2)+" = "+str(no1%no2))
    engine.say(str(no1) +" % "+ str(no2) +" is "+ str(no1%no2))
else:
    print("Error broooooooooooooooooooooooooo")
    engine.say("error")

engine.runAndWait()