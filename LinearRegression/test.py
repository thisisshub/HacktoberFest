import numpy as np
from Fundamental import *

A = np.loadtxt('DATA.txt',delimiter = ',')

X = A[:,:1]
Y = A[:,1:]
_X, _Y = X.copy(),Y.copy()
print (X,Y, sep ='\n')
print(X.shape, Y.shape)
#X.reshape((X.shape(axis=0)[0],1))
#Y.reshape((Y.shape(axis=0)[0],1))
needPredict = np.array([1,17])
# X = np.append([[1]]*np.size(X,0),X,1) #check
# m = np.size(X,0) #check
# n = np.size(X,1)
#
# alpha = 0.003
# # theta = GradientDescent(X,Y,alpha = 0.03, iter = 500)
# # print(theta)
# [theta,J_hist] = GradientDescent(X,Y,alpha)
#theta = np.array([[0]]*n)

[theta, Jhist] = GradientDescent(X,Y,alpha =0.001)

#print(X,Y,sep='\n')
print(theta)
t = predict(needPredict,theta)
#print(t)
## Visualizing data
import matplotlib.pyplot as plt

for x,y in zip(_X,_Y):
    plt.plot(x,y,'o')
testx = []
testy = []
for i in range(1,50000):
    testx.append(i/100)
    testy.append(theta[0] + theta[1]*i/100)
plt.plot(testx,testy)
plt.show()





