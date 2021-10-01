# Age Predictor in Python --> Predicts Your Current Age in 10 Tries
# Assumption(Range of Age - 0 to 100) 

n1 = 0
n2 = 100
c = 0
while (c < 10):
    print("Guesses : ",c)
    print("Are you ", int((n1 + n2) / 2), "years old ?")
    N = input("Less / More / Correct : ")
    if (N == "Correct"):
        print("AGE GUESSED SUCCESSFULLY!!")
        break
    elif (N == "More"):
        c += 1
        n1 = int((n1 + n2) / 2)
    else:
        c += 1
        n2 = int((n1 + n2) / 2)
