"""
Solver functions for Sudoku

"""

def print_sudoku(sudoku):
    for i in range(len(sudoku)):
        line = ""
        if i == 3 or i == 6:
            print("---------------------")
        for j in range(len(sudoku[i])):
            if j == 3 or j == 6:
                line += "| "
            line += str(sudoku[i][j])+" "
        print(line)

def get_next_empty_cell(sudoku):
    for x in range(9):
        for y in range(9):
            if sudoku[x][y] == 0:
                return x, y
    return -1, -1

def is_possible(sudoku, i, j, e):
    check_row = all([e != sudoku[i][x] for x in range(9)])
    if check_row:
        check_col = all([e != sudoku[x][j] for x in range(9)])
        if check_col:
            sq_x, sq_y = 3*(i//3), 3*(j//3)
            for x in range(sq_x, sq_x+3):
                for y in range(sq_y, sq_y+3):
                    if sudoku[x][y] == e:
                        return False
            return True
    return False

def solve(sudoku, i=0, j=0):
    i, j = get_next_empty_cell(sudoku)
    if i == -1:
        return True
    for n in range(1, 10):
        if is_possible(sudoku, i, j, n):
            sudoku[i][j] = n
            if solve(sudoku, i, j):
                return True
            sudoku[i][j] = 0
    return False

