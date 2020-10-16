# A tic-tac-toe game where one player is human and the other is a computer which uses a min-max algorithm
import random
class Tic_tac_toe():
    def __init__(self):
        self.board =['','','','','','','','','','']
        self.available_move = [str(num) for num in range(0,10)]
        
    def display_board(self,a,b):
        print(f'Available   TIC-TAC-TOE\n  moves\n\n  {a[7]}|{a[8]}|{a[9]}        {b[7]}|{b[8]}|{b[9]}\n  -----        -----\n  {a[4]}|{a[5]}|{a[6]}        {b[4]}|{b[5]}|{b[6]}\n  -----        -----\n  {a[1]}|{a[2]}|{a[3]}        {b[1]}|{b[2]}|{b[3]}\n')
    
    def players(self):
        player = ''
        while player not in ['X','O']:
            player  = input('player choice')
        if player == 'X' or player == 'x':
            return ['X','O']
        else :return ['O','X']
    
    def space_check(self,board,position):
        return board[position] == ' '
    
    def full_board_check(self,board):
        return ' ' not in board[1:]
    
    def first_to_move(self):
        return int(random.randint(0,1))
    
    
    def replay(self):
        return input('Do you want to play again? Enter Yes or No: ').lower().startswith('y')
    
    def get_player_move(self,board):
        position = 0
        while position not in [1,2,3,4,5,6,7,8,9] or not self.space_check(board, position):
            try:
                position = int(input('Player, choose your next position: (1-9) '))
            except:
                print("I'm sorry, please try again.")
        return position
    
    def win_check(self,board,mark):
        return ((board[7] ==  board[8] ==  board[9] == mark) or # across the top
        (board[4] ==  board[5] ==  board[6] == mark) or # across the middle
        (board[1] ==  board[2] ==  board[3] == mark) or # across the bottom
        (board[7] ==  board[4] ==  board[1] == mark) or # down the middle
        (board[8] ==  board[5] ==  board[2] == mark) or # down the middle
        (board[9] ==  board[6] ==  board[3] == mark) or # down the right side
        (board[7] ==  board[5] ==  board[3] == mark) or # diagonal
        (board[9] ==  board[5] ==  board[1] == mark)) # diagonal
    
    def make_move(self,avail,board,marker,position):
        board[position] = marker
        avail[position] = ' '
    
    def getBoardCopy(self,board):
        # Make a duplicate of the board list and return it the duplicate.
        dupeBoard = []
        for i in board:
            dupeBoard.append(i)
        return dupeBoard
    
    def getavail(self,board):
        # Make a duplicate of the board list and return it the duplicate.
        dupeavail =[]
        for i in board:
            dupeavail.append(i)
        return dupeavail
    
    def chooseRandomMoveFromList(self,board, movesList):
        # Returns a valid move from the passed list on the passed board.
        # Returns None if there is no valid move.
        possibleMoves = []
        for i in movesList:
            if self.space_check(board, i):
                possibleMoves.append(i)

        if len(possibleMoves) != 0:
            return random.choice(possibleMoves)
        else:
            return None

    def getComputerMove(self,board, computerLetter):
        # Given a board and the computer's letter, determine where to move and return that move.
        if computerLetter == 'X':
            playerLetter = 'O'
        else:
            playerLetter = 'X'
        # Here is our algorithm for our Tic Tac Toe AI:
        # First, check if we can win in the next move
        for i in range(1, 10):
            copy = self.getBoardCopy(board)
            copy_2 = self.getavail(self.available_move)
            if self.space_check(copy, i):
                self.make_move(copy_2,copy, computerLetter, i)
                if self.win_check(copy, computerLetter):
                    return i

        # Check if the player could win on their next move, and block them.
        for i in range(1, 10):
            copy = self.getBoardCopy(board)
            copy_2 = self.getavail(self.available_move)
            if self.space_check(copy, i):
                self.make_move(copy_2,copy, playerLetter, i)
                if self.win_check(copy, playerLetter):
                    return i
        # Try to take one of the corners, if they are free.
        move = self.chooseRandomMoveFromList(board, [1, 3, 7, 9])
        if move != None:
            return move
        # Try to take the center, if it is free.
        if self.space_check(board, 5):
            return 5
        # Move on one of the sides.
        return self.chooseRandomMoveFromList(board, [2, 4, 6, 8])
    
    def game_on(self):
        self.board = [' '] * 10
        self.available_move = [str(num) for num in range(0,10)]
        playerLetter, computerLetter = self.players()
        turn = self.first_to_move()
        print('The ' + str(turn) + ' will go first.')
        gameIsPlaying = True
        
        while gameIsPlaying == True:
            if turn == 0:
                self.display_board(self.board,self.available_move)
                move = self.get_player_move(self.board)
                self.make_move(self.available_move,self.board,playerLetter,move)
                
                if self.win_check(self.board, playerLetter):
                    self.display_board(self.board,self.available_move)
                    print('Player is the winner!!!!!!!!!!!!')
                    gameIsPlaying = False
                else:
                    if self.full_board_check(self.board):
                        self.display_board(self.board,self.available_move)
                        print('The game is a tie!')
                        break
                    else:
                        turn = 1
            else:
                move = self.getComputerMove(self.board, computerLetter)
                self.make_move(self.available_move, self.board, computerLetter, move)
                
                if self.win_check(self.board,computerLetter):
                    self.display_board(self.board,self.available_move)
                    print('The computer has beaten you! You lose.')
                    gameIsPlaying = False
                else:
                    if self.full_board_check(self.board):
                        self.display_board(self.board,self.available_move)
                        print('The game is a tie!')
                        break
                    else:
                        turn = 0
    def start(self):
        repl = True
        while repl == True:
            self.game_on()
            if self.replay() == False:
                repl = False
            else : repl = True
			
tk = Tic_tac_toe()
tk.start()
