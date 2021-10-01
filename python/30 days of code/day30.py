#This opens your camera and shows your video

import cv2
cap = cv2.VideoCapture(0)

while True:
    ret, vid = cap.read()
    vid = cv2.rotate(vid , cv2.ROTATE_180)
    cv2.imshow("vid" , vid)
    if cv2.waitKey(1) == ord("q"):
        break
cv2.destroyAllWindows()
