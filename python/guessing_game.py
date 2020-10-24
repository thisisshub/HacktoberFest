
secret_word = "giraffe"

guess = ""

while guess!=secret_word:
    guess = input("Enter a word: ")
    if guess != secret_word:
        print("Try again! The name starts with g")
print("You guessed it right!!!")