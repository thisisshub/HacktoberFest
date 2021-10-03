import numpy as np
import matplotlib.pyplot as plt
import copy

inputFile = open("input.txt", "r")
outputFile = open("result.txt", "w")
outputFile.close()

def jacobi(matrix, extension):
    matrixLength = len(matrix)
    originalMatrix = copy.deepcopy(matrix)
    originalExtension = copy.deepcopy(extension)

    x0 = [0] * matrixLength
    x = copy.deepcopy(x0) 
    counter = 0

    while counter < 10000:
        for i in range(matrixLength):
            cellsSum = 0
            for j in range(matrixLength):
                if j != i:
                    cellsSum = cellsSum + matrix[i][j] * x0[j] / matrix[i][i]
                x[i] = (extension[i]/matrix[i][i]) - cellsSum
        if abs(safe_norm(x) - safe_norm(x0)) < 0.01:
            break
        else:
            x0 = copy.deepcopy(x)
        counter = counter + 1

        
    
    printResult(originalMatrix, originalExtension, x0)

def safe_norm(x):
    return np.linalg.norm(np.matrix(x))  

def printResult(matrix, extension, results):
    outputFile = open("result.txt", "a")
    outputFile.write("-----------------------------------------------\n")
    outputFile.write("Found variables: ")
    for result in results:
        outputFile.write("   {}   ".format(result))

    outputFile.write("\n\n")
    outputFile.close()
    
    nx = ny = len(matrix)
    nx = nx + 1

    cellColours = [[None] * nx] * ny

    data = np.column_stack([matrix, extension])

    for i in range(nx):
        for j in range(ny):
            if i != nx-1:
                cellColours[j][i] = "#4bb543"
            else:
                cellColours[j][i] = "#4bb"

    plt.figure()
    tb = plt.table(cellText=data, loc=(0,0), cellLoc='center', cellColours=cellColours)
    

    tc = tb.properties()['children']
    for cell in tc: 
        cell.set_height(1/ny)
        cell.set_width(1/nx)

    ax = plt.gca()
    ax.set_xticks([])
    ax.set_yticks([])

    plt.title(label="Found variables: "+(len(results)*'   {:.2f}   ').format(*results),
          loc="left",
          fontstyle='italic',
          wrap=True)

    plt.show()


def calculateSpacing(array, index):
    bigger = len(str(array[0][0]))

    for item in array:
        itemLength = len(str(item[index]))
        if itemLength > bigger:
            bigger = itemLength

    return bigger


def main():
    for line in inputFile:
        line = line.split(",")
        numberOfLines = int(line[0])
        matrix = []
        matrixExtension = []

        if len(line) != numberOfLines+2:
            print("Wrong input format. Please, check it again!\n")
            return
        
        for i in range(numberOfLines):
            matrix.append(list(map(int, line[i+1].split(" "))))

        matrixExtension = list(map(int, line[-1].split(" ")))
        
        jacobi(matrix, matrixExtension)

    inputFile.close()

main()
print("Done. See the results on result.txt\n")