import cv2
import numpy as np

img = cv2.imread('sudoku.png')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
edge = cv2.Canny(gray,50,150,apertureSize=3)
cv2.imshow('edge',edge)
lines = cv2.HoughLines(edge, 1, np.pi/180,200)

for line in lines:
    rho,theta = line[0]
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a * rho
    y0 = b * rho
    #x1 stores the rounded off values of (r*cos(theta)-100*sin(theta))
    x1 = int(x0 + 1000 * (-b))
    # y1 stores the rounded off values of (r*sin(theta)+100*cos(theta))
    y1 = int(y0 + 1000 * (a))
    # x2 stores the rounded off values of (r*cos(theta)+100*sin(theta))
    x2 = int(x0 - 1000 * (-b))
    # x1 stores the rounded off values of (r*sin(theta)-100*cos(theta))
    y2 = int(y0 - 1000 * (a))
    cv2.line(img,(x1,y1),(x2,y2),(0,0,255),2)

cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
