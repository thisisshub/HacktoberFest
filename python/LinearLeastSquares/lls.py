from sympy import lambdify, Symbol, parse_expr
import numpy as np
import matplotlib.pyplot as plt
import re
import copy

outputFile = open("result.txt", "w")
outputFile.close()

def decomposeLU(matrix, extension):
    matrixLength = len(matrix)

    identityMatrix = np.eye(matrixLength, matrixLength).tolist()

    for j in range(matrixLength-1):
        for i in range(j+1, matrixLength):
            identityMatrix[i][j] = matrix[i][j] / matrix[j][j]
            for k in range(j+1,matrixLength):
                matrix[i][k] = matrix[i][k] - identityMatrix[i][j]*matrix[j][k]
            matrix[i][j] = 0

    yResults = [None] * matrixLength
    yResults[0] = extension[0]/identityMatrix[0][0]
    for i in range(1, matrixLength):
        resultSum = 0
        for j in range(i-1,-1,-1):
            resultSum = resultSum +  identityMatrix[i][j] * yResults[j]
        yResults[i] = ( extension[i] - resultSum ) / identityMatrix[i][i]

    results = [None] * matrixLength
    results[matrixLength-1] = yResults[matrixLength-1]/matrix[matrixLength-1][matrixLength-1]
    for i in range(matrixLength-2,-1, -1):
        resultSum = 0
        for j in range(i+1, matrixLength):
            resultSum = resultSum +  matrix[i][j] * results[j]
        results[i] = ( yResults[i] - resultSum ) / matrix[i][i]

    return results

def safe_norm(x):
    return np.linalg.norm(np.matrix(x)) 

def gauss(matrix, extension):
    matrixLength = len(matrix)

    for i in range(matrixLength-1):
        for j in range(i+1, matrixLength):
        
                m = matrix[j][i] / matrix[i][i]
                matrix[j][i] = 0

                for k in range(i+1, matrixLength):
                    matrix[j][k] = matrix[j][k] - m * matrix[i][k]
                extension[j] = extension[j] - m * extension[i]
    
    results = [None] * matrixLength
    results[matrixLength-1] = extension[matrixLength-1]/matrix[matrixLength-1][matrixLength-1]
    for i in range(matrixLength-2,-1, -1):
        resultSum = 0
        for j in range(i+1, matrixLength):
            resultSum = resultSum +  matrix[i][j] * results[j]
        results[i] = ( extension[i] - resultSum ) / matrix[i][i]

    return results

def arraysProduct(array1, array2):
    arraysLength = len(array1)
    
    result = 0
    for i in range(arraysLength):     
        result = result + (array1[i] * array2[i])

    return result

def main():
    inputFile = open("input.txt", "r")

    for lineIndex, line in enumerate(inputFile):
        line = re.sub('[\n]*','',line)
        line = line.split(";")
        xValues = np.array(line[0].replace('[', '').replace(']','').replace('\n', '').split(',')).astype(np.float)
        yValues = np.array(line[1].replace('[', '').replace(']','').replace('\n', '').split(',')).astype(np.float)
        equations = re.sub('[\+\-\/]','&',re.sub('[a-wA-Wy-zY-Z]*','',line[2])).split('&')
        originalEquations = copy.deepcopy(equations)

        equationResults = []
        newLinearEquations = []
        newLinearEquationsResults = []

        for equationsIndex, item in enumerate(equations):
            if item == '':
                equations[equationsIndex] = "1"
            equations[equationsIndex] = lambdify(Symbol('x'), parse_expr(equations[equationsIndex]))
            equationResults.append([])
            newLinearEquations.append([])

        for equationIndex, equation in enumerate(equations):
            for x in xValues:
                equationResults[equationIndex].append(equation(x))

        equationResultsLength = len(equationResults)
        for i in range(equationResultsLength):
            for j in range(equationResultsLength):
                newLinearEquations[i].append(arraysProduct(equationResults[i],equationResults[j]))
            newLinearEquationsResults.append(arraysProduct(equationResults[i], yValues))

        systemResults = decomposeLU(newLinearEquations, newLinearEquationsResults)
        systemResultsLength = len(systemResults)
        approximateEquation = ""
        mainOperator = ""
        predictedValues = []
        
        for i in range(systemResultsLength):
            if i < systemResultsLength - 2:
                approximateEquation = approximateEquation + "{}{}*x**{} ".format(mainOperator, abs(systemResults[i]),systemResultsLength - 1 - i)
                mainOperator = " + " if systemResults[i+1] >= 0 else " - "
            elif i < systemResultsLength - 1:
                approximateEquation = approximateEquation + "{}{}*x".format(mainOperator, abs(systemResults[i]))
                mainOperator = " + " if systemResults[i+1] >= 0 else " - "
            elif i == systemResultsLength - 1:
                approximateEquation = approximateEquation + "{}{}".format(mainOperator, abs(systemResults[i]))

        outputFile = open("result.txt", "a")
        outputFile.write("---------------Problem Nº {}-------------------\n".format(lineIndex+1))
        outputFile.write("Approximate equation found: Y = {}".format(approximateEquation))
        outputFile.write("\n\n")
        outputFile.close()

        approximateFunction = lambdify(Symbol('x'), parse_expr(approximateEquation))

        for i in range(len(xValues)):
            predictedValues.append(approximateFunction(xValues[i]))

        plt.scatter(xValues, yValues)
        plt.plot(xValues, predictedValues, color='blue')
        plt.show()


main()