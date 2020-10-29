import random

start = input("Welcome to the game of Scissors, Paper, Rock. Press [Enter} to start.")

outcomes = {
    1: "scissors",
    2: "paper",
    3: "rock"
    }
while bool(start) is False:
    print("\nYou will play against the computer. Press [Enter] again at anytime to exit the game. Your score will be displayed.")
    answer = input("Enter scissors, paper or rock.\n")
    i = 0 
    x = 0 
    p = 0 
    a = 0 
    b = 0 
    while bool(answer) is True:
        while i > 0 and p == 0:
            answer = input("")
            break
        if bool(answer) is False:
            break
        p = 0
        i += 1 
        answer = answer.lower() 
        computer = random.randint(1, 3) 
        computers_answer = outcomes[computer]

        if answer == "scissors":
            if computers_answer == "scissors":
                print(computers_answer)
                print("Draw!")
                a += 1
            elif computers_answer == "paper":
                print(computers_answer)
                print("You Win!")
                x += 1
            elif computers_answer == "rock":
                print(computers_answer)
                print("You Lose!")
                b += 1
                
        elif answer == "paper":
            if computers_answer == "scissors":
                print(computers_answer)
                print("You Lose!")
                b += 1
            elif computers_answer == "paper":
                print(computers_answer)
                print("Draw!")
                a += 1
            elif computers_answer == "rock":
                print(computers_answer)
                print("You Win!")
                x += 1

        elif answer == "rock":
            if computers_answer == "scissors":
                print(computers_answer)
                print("You Win!")
                x += 1
            elif computers_answer == "paper":
                print(computers_answer)
                print("You Lose!")
                b += 1
            elif computers_answer == "rock":
                print(computers_answer)
                print("Draw!")
                a += 1
                
        elif bool(answer) is False:
            break

        while answer != "scissors" and answer != "paper" and answer != "rock" and bool(answer) is True:
            answer = input("Please enter a valid statement:\n")
            p += 1
            if bool(answer) is False:
                i -= 1
            else:
                continue

    if bool(answer) is False:
        break

while True:
    try:
        z = int(x/i * 100) 
        a = int(a/i * 100)
        b = int(b/i * 100)
        
        print("You have played " + str(i) + " rounds, " + str(x) + " of which you have won! This means you won or drew " + str(z + a) + "%, and lost " + str(b) + "% of the time.")
        break

    except:
        print("You have played " + str(i) + " rounds.") 
        break    