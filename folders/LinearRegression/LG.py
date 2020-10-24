import numpy as np
from matplotlib import pyplot as plt
def predictValue(X,theta):
    return np.sum(predict(X,theta))

def predict(X,theta):
    return X@theta

def hypothesis(X,Y,theta):
    X = np.append([[1]]*np.size(X,0),X,1)
    return (np.transpose(theta)@X - Y)

def costFunction(X,Y,theta):
    cost = X@theta - Y
    J = np.sum(np.transpose(cost)@cost)
    return J*(1/2*np.size(X,0))


    # def valueCostFunction(X,Y,theta):
    #     X = np.append([[1]]*np.size(X,0),X,1)
    #     m = np.size((Y,0))
    #     n = len(X[0,:])
    #     J = 0
    #     for i in range(1,m):
    #         J += np.sum(hypothesis(X,Y,theta)**2)
    #     J /= 2*m
    #     return J
    # def deritativeCostFunction(X,Y,theta):
    #     pass


def GradientDescent(X,Y, alpha = 0.003,iter = 5000):
    X = np.append([[1]]*np.size(X,0),X,1) #check
    m = np.size(X,0) #check
    n = np.size(X,1)
    J_hist = np.zeros((iter,2))
    theta = np.array([[0]]*n)
    preCost = costFunction(X,Y,theta)

    for i in range(500):
        theta = theta - (alpha / m) * (np.transpose(X)@(X@theta - Y))
        cost = costFunction(X,Y,theta)
        if np.round(cost,15) == np.round(preCost,15):
            print('Found optimal value of costFunction at {} is {}'.format(i,cost))
            #thêm tất cả các index còn lại sau khi break
            J_hist[i:,0] = range(i,iter)
            #giá trị J sau khi break sẽ như cũ trong những điểm còn lại
            J_hist[i:,1] = cost
            break
        else:
            J_hist[i,1] = cost
            J_hist[i,0] = i
            preCost = cost
    yield theta
    yield J_hist
