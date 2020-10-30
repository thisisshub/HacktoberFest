#-*-coding:utf8;-*-
import random
import os
import time
from sys import exit

class Game():
    
    def __rand_num(self,qta):
        num = []
        da = int(input("Inserisci il numero più piccolo: "))
        a = int(input("Inserisci il numero più grande: "))
        for x in range(qta):
            num.append(random.randint(da,a))
        return num

    def __somma(self,num):
        result = 0
        for i, y in enumerate(num):
            print(str(y), end = '')
            if i != len(num) - 1:
                print(" + ", end = '')
            result += y
        return result
    
    def __sottrazione(self, num):
        # result = 0
        # for i, y in enumerate(num):
        #     print(str(y), end = '')
        #     if i != len(num) - 1:
        #         print(" - ", end = '')
        #     result -=y
        # return result
        result = 0
        for i, y in enumerate(num):
            print(str(y), end = '')
            if i != len(num) - 1:
                print(" - ", end = '')
            if i == 0:
                result = y
            else:
                result -= y
        return result
            
        time.sleep(10)

    def __test(self,resutl, user_result):
        if(resutl == user_result):
            print("Bravo hai risposto correttamente!")
        else:
            print("Mi dispiace ma il risultato corretto era " + str(resutl))
    
    def __menu(self):
        os.system('clear')
        # Chiedi che operazioni vuoi fare
        print('''Operazioni:
            1. Addizione
            2. Sottrazione
            3. Mggiore o minore
            4. Moltiplicazione
            5. Divisione
            6. ESCI
        ''')
        op = int(input("Che operazione scegli? "))
        return op

    def gioca(self):
        op = self.__menu()
        qta = 0
        if(op == 1):
            # Se si sceglie la somma
            while(qta < 2):
                qta = int(input("Con quanti numeri vuoi giocare, minimo 2: "))
            num = self.__rand_num(qta)
            result = self.__somma(num)
        elif(op == 2):
            while(qta < 2):
                qta = int(input("Con quanti numeri vuoi giocare, minimo 2: "))
            num = self.__rand_num(qta)
            result = self.__sottrazione(num)
        elif(op > 1 and op < 6):
            print("Mi dispiace ma l'operazione selezionata non è ancora stata implementata")
            return 1
        elif(op == 6):
            return 0
        else:
            print("L'operazione scelta non è corretta")
            return 1
        
        user_result = int(input("\nDimmi il risultato di "))
        self.__test(result, user_result)
        return 1


game = Game()
while game.gioca():
    time.sleep(3)
