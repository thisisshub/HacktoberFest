SCREEN = (236, 61)
DEAD = "."
ALIVE = "@"

grid = []
for i in range(SCREEN[1]):
    grid.append([])
    for j in range(SCREEN[0]):
        grid[i].append(DEAD)

def disp(raw):
    out = ""
    for row in raw:
        for item in row:
            out += item
        out += "\n"
    print(out[:-1])

def iterate(working):
    changes = []
    for row in range(SCREEN[1]):
        for col in range(SCREEN[0]):


            if working[row][col] == ALIVE:
                count = 0

                if row == 0:
                    if col == 0:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1

                elif row == SCREEN[1] - 1:
                    if col == 0:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1

                else:
                    if col == 0:
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                        if working[row][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1


                if not (count == 2 or count == 3):
                    changes.append(((row, col), DEAD))


            else:
                count = 0

                if row == 0:
                    if col == 0:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1

                elif row == SCREEN[1] - 1:
                    if col == 0:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1

                else:
                    if col == 0:
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1
                        if working[row][col + 1] == ALIVE:
                            count += 1
                    elif col == SCREEN[0] - 1:
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                    else:
                        if working[row - 1][col - 1] == ALIVE:
                            count += 1
                        if working[row - 1][col] == ALIVE:
                            count += 1
                        if working[row - 1][col + 1] == ALIVE:
                            count += 1
                        if working[row][col - 1] == ALIVE:
                            count += 1
                        if working[row][col + 1] == ALIVE:
                            count += 1
                        if working[row + 1][col - 1] == ALIVE:
                            count += 1
                        if working[row + 1][col] == ALIVE:
                            count += 1
                        if working[row + 1][col + 1] == ALIVE:
                            count += 1

                if count == 3:
                    changes.append(((row, col), ALIVE))


    for item in changes:
        working[item[0][0]][item[0][1]] = item[1]
    return working


grid[21][51] = ALIVE
grid[20][52] = ALIVE
grid[21][52] = ALIVE
grid[22][52] = ALIVE
grid[20][53] = ALIVE
disp(grid)

while True:
    grid = iterate(grid)
    disp(grid)
