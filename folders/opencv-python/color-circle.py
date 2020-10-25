import numpy as np
import cv2

img = np.zeros([512,512,3], np.uint8)
stop = 0
while stop == 0 :
    for r in range(4):
        for g in range(4):
            for b in range(4):
                img = cv2.circle(img, (256,256), 256, (r*64,g*64,b*64), -1) #-1 to fill the shape
                cv2.imshow('lena',img)
                k = cv2.waitKey(1)
                if k%256 == 27:
                    # ESC pressed
                    print("Escape hit, closing...")
                    stop = 1

cv2.destroyAllWindows()