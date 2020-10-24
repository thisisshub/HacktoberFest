import random
name = input('Enter your name: ')
print("welcome",name,"let's play hangman!!!\n")
level = int(input('\nEnter dififculty level ( 1  |  2  |  3) : '))
print(' ')

if level==1:
    lives = 9
elif level ==2:
    lives = 7
elif level == 3:
    lives = 5
    
def run():
    L=['cushion','refrigerator','tennis','badminton','speaker','country','curtain','animal','movie','penguin','hamster','omnivore','alien','bullet','field','travel','huge','destroy','pastry']
    word = L[random.randint(0,len(L)-1)]

    list_word_1 = list(word)
    list_word_2 = list(word)


    for i in range(len(list_word_1)):
        list_word_1[i] = ' '

    print(lives,'lives remaining ')
    print(list_word_1)

    def play():
     
        count = 0
        guess = input('Enter a letter: ')        

        for i in range(len(list(word))):
            if list_word_2[i]==guess:
                list_word_1[i]=guess
                count+=1

        if count==0:
            global lives
            lives = lives-1

        print(lives,'lives remaining')

        if list_word_1==list_word_2:
            print('\ncongratulations you won !')
            print(list_word_2)
            ask = input('Do you want to play again ?')
            if ask == 'no':
                quit()
            elif ask=='yes':

                level = int(input('\nEnter dififculty level ( 1  |  2  |  3) : \n'))

                print(' ')
                if level==1:
                    lives = 9
                elif level ==2:
                    lives = 7
                elif level == 3:
                    lives = 5
                
                run()
                
        
        elif lives==0:
            print('\nyou lost better luck next time !')
            print('the correct word is',word)
            ask = input('Do you want to play again ?')
            if ask == 'no':
                quit()
            elif ask=='yes':

                level = int(input('\nEnter dififculty level ( 1  |  2  |  3) : \n'))
                print(' ')

                if level==1:
                    lives = 9
                elif level ==2:
                    lives = 7
                elif level == 3:
                    lives = 5
                
                run()
                
                

        print(list_word_1)

        play()

    play()

run()
