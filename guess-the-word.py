word = ''
no_of_guesses = 3
guess = input('enter a word')

while guess != word:
    no_of_guesses = no_of_guesses -1
    print('try again')
    guess = input('enter a word')
    if no_of_guesses == 0:
        print('game over!')
        break

if guess == word:
    print('well done')
