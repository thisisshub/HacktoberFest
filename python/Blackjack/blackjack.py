import random
from blackjack_art import *

cards = [2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11]
dealer_cards = [random.choice(cards), random.choice(cards)]
user_cards = [random.choice(cards), random.choice(cards)]
sum_of_user_cards = sum(user_cards)
sum_of_dealer_cards = sum(dealer_cards) 

print(logo)
print(f"You have {user_cards} cards")
print(f"The dealer has {dealer_cards[0]}, ? cards")
print(f"Your total score is, {sum_of_user_cards}")

while (sum_of_user_cards <= 21):
    if sum_of_user_cards == 21:
            sum_of_user_cards = sum(user_cards)
            sum_of_dealer_cards = sum(dealer_cards)
            print(f"You have {user_cards} cards now")
            print(f"Your total score is, {sum_of_user_cards}")
            print("BLACKJACK!!")
            print(f"The dealer's cards are, {dealer_cards}")
            print(f"The dealer's total score is {sum_of_dealer_cards}")
            if sum_of_dealer_cards < sum_of_user_cards:
                print("You have won!!")
                break
    user_input = input("Do you want a card? ")
    if user_input.lower() == "yes":
        random_card = random.choice(cards)
        user_cards.append(random_card)
        sum_of_user_cards = sum(user_cards)
        print(f"You have {user_cards} cards now")
        print(f"Your total score is, {sum_of_user_cards}")
        if (sum_of_user_cards > 21): 
            if 11 in user_cards:
                print("The Ace was converted into 1")
                user_cards.insert(0, 1)
                user_cards.remove(11)
                sum_of_user_cards = sum(user_cards)
                print(f"You have {user_cards} now")
                print(f"Your total score is, {sum_of_user_cards}")
            else:
                print("You have lost :(")
        if sum_of_user_cards == 21:
            sum_of_user_cards = sum(user_cards)
            sum_of_dealer_cards = sum(dealer_cards)
            print(f"You have {user_cards} cards now")
            print(f"Your total score is, {sum_of_user_cards}")
            print("BLACKJACK!!")
            print(f"The dealer's cards are, {dealer_cards}")
            print(f"The dealer's total score is {sum_of_dealer_cards}")
            if sum_of_dealer_cards < sum_of_user_cards:
                print("You have won!!")
                break
    elif user_input.lower() == "no":
        break
if user_input.lower() == ("no"):
    sum_of_dealer_cards = sum(dealer_cards)
    while sum_of_dealer_cards <= 17:
        print("The dealer took a card")
        random_card = random.choice(cards)
        dealer_cards.append(random_card)
        sum_of_dealer_cards = sum(dealer_cards)
    if sum_of_dealer_cards > 17:
        print(f"The dealer's cards are, {dealer_cards}")
        print(f"The dealer's total score is {sum_of_dealer_cards}")
        if sum_of_dealer_cards < sum_of_user_cards:
            print("You have won!!")
        if sum_of_dealer_cards > sum_of_user_cards:
            if sum_of_dealer_cards > 21:
                sum_of_dealer_cards = sum(dealer_cards)
                if 11 in sum_of_dealer_cards:
                    print("The dealer's Ace was converted into a 1")
                    dealer_cards.insert(0, 1)
                    dealer_cards.remove(11)
                    sum_of_dealer_cards = sum(dealer_cards)
                    print(f"You have {dealer_cards} now")
                    print(f"Your total score is, {sum_of_dealer_cards}")
                else:
                    print("You Have Won :)")
            else:
                print("You have lost :(")
        if sum_of_user_cards == sum_of_dealer_cards:
            print("It was a tie.")
