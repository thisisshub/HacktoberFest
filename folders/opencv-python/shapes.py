import numpy as np
import cv2

img = np.zeros([512,512,3], np.uint8)


img = cv2.line(img, (0,0), (255,255), (255,0,0), 5)  #arguments are image,start coordinate as a tuple,end ,color in BGR and thicknes
img = cv2.arrowedLine(img, (0,255), (255,255), (0,0,255), 5)
img = cv2.rectangle(img, (384,0), (450,125), (0,255,0), 5)
img = cv2.circle(img, (300,63), 63, (0,255,255), -1) #-1 to fill the shape


cv2.imshow('lena',img)
cv2.waitKey(0)
cv2.destroyAllWindows()