score = input("Enter Score: ")
score=float(score)
try:
    if score>=0.9 and score<=1.0:
        print("A")
    elif score>=0.8:
        print("B")
    elif score>=0.7:
        print("C")
    elif score>=0.6:
        print("D")
    elif score<0.6 and score>=0:
        print("F")
except:
    print("Enter a score between 0 to 1")
