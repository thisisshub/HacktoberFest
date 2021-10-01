"""
EXERCISE : Guess the number
"""

n=69
ng=9                                             # No. of guesses
print("Write your Guess", end="- ")
while(True):
    g=int(input())
    if ng!=1:
        if g>n:
           ng=ng-1
           print(ng, "Guesses left")
           print("Try a smaller number", end="- ")
        elif g==n:
            print("\nCongo!!",n,"is the right guess")
            break
        else:
            ng = ng - 1
            print(ng, "Guesses left")
            print("Try a greater number", end="- ")
    elif g == n:
        print("\nCongo!!", n, "is the right guess")
        break
    else:
        print("No Guesses Left :(")

