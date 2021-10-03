from scipy.interpolate import make_interp_spline
from sympy import lambdify, Symbol, parse_expr, simplify
import numpy as np
import matplotlib.pyplot as plt
import re
import copy

outputFile = open("result.txt", "w")
outputFile.close()

def main():
    inputFile = open("input.txt", "r")

    for lineIndex, line in enumerate(inputFile):
        line = re.sub('[\n]*','',line)
        line = line.split(";")
        
        points = []
        lValues = []

        for pointString in line:
            points.append(np.array(pointString.replace('[', '').replace(']','').replace('\n', '').split(',')).astype(np.float))

        pointsLength = len(points)
        finalExpression = ""

        for i in range(pointsLength):
            lValue = 1
            for j in range(pointsLength):
                if j != i:
                    lValue = "({} * ((x - {})/({} - {})))".format(lValue, points[j][0], points[i][0], points[j][0])
            
            lValues.append(lValue.replace('1',str(points[i][1]), 1))
            
            if i > 0:
                finalExpression = finalExpression + " + {}".format(lValues[i])
            else:
                finalExpression = finalExpression + "{}".format(lValues[i])

        approximateEquation = simplify(finalExpression)
        finalExpression = lambdify(Symbol('x'), parse_expr(finalExpression))
        
        xValues = []
        yValues = []
        predictedValues = []
        
        for i in range(len(points)):
            xValues.append(points[i][0])
            yValues.append(points[i][1])
            predictedValues.append(finalExpression(points[i][0]))

        outputFile = open("result.txt", "a")
        outputFile.write("---------------Problem Nº {}-------------------\n".format(lineIndex+1))
        outputFile.write("Approximate equation found: Y = {}".format(approximateEquation))
        outputFile.write("\n\n")
        outputFile.close()

        if len(predictedValues) > 3:
            newXValues = np.linspace(min(xValues), max(xValues), 200)
            spline = make_interp_spline(xValues, predictedValues, k=3)
            smoothYValues = spline(newXValues)


            plt.scatter(xValues, yValues)
            plt.plot(newXValues, smoothYValues, color='blue')
            plt.show()
        else:
            plt.scatter(xValues, yValues)
            plt.plot(xValues, predictedValues, color='blue')
            plt.show()




main()