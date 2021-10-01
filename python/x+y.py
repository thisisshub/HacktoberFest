# the mathematics problem in x+y movie

def mainFunc(cards):
    for c in range(0, len(cards)-1):
        
        if cards[c] == 1:
            cards[c] = 0
            if cards[c+1] == 0:
                cards[c+1] = 1
            else:
                cards[c+1] = 0
        return cards                        

if __name__ == "__main__":
    cards = list("100111100101010111000101110101110110101")
    
    while cards != mainFunc(cards.copy()):
        cards = mainFunc(cards)
        print(cards)

