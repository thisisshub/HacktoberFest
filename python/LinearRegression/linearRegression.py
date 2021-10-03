import numpy as np
import matplotlib.pyplot as plt

outputFile = open("result.txt", "w")
outputFile.close()

def main():
    inputFile = open("input.txt", "r")

    for lineIndex, line in enumerate(inputFile):
        line = line.split(";")
        x = np.array(line[0].replace('[', '').replace(']','').replace('\n', '').split(',')).astype(np.float)
        y = np.array(line[1].replace('[', '').replace(']','').replace('\n', '').split(',')).astype(np.float)
        
        meanX = np.mean(x)
        meanY = np.mean(y)

        lengthX = len(x)
        numerator = 0
        denominator = 0
        for i in range(lengthX):
            numerator += (x[i] - meanX)*(y[i] - meanY)
            denominator += (x[i] - meanX)**2

        alpha = numerator / denominator
        beta = meanY - alpha*meanX

        outputFile = open("result.txt", "a")
        outputFile.write("---------------Problem Nº {}-------------------\n".format(lineIndex+1))
        mainOperator = " + " if beta >= 0 else " - "
        outputFile.write("Approximate linear equation found: Y = {}x{}{}".format(alpha, mainOperator,abs(beta)))

        outputFile.write("\n\n")
        outputFile.close()

        predictedYValues = alpha*x + beta
        plt.scatter(x, y)
        plt.plot([min(x), max(x)], [min(predictedYValues), max(predictedYValues)], color='blue')
        plt.show()

        

main()