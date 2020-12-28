
import cv2
import os
import numpy as np #NumPy is a general-purpose array-processing package.
from PIL import Image

recognizer = cv2.face.LBPHFaceRecognizer_create();
path='dataset'
#detector= cv2.CascadeClassifier("haarcascade_frontalface_default.xml");

def getImagesAndLabels(path):
    #get the path of all the files in the folder
    imagePaths=[os.path.join(path,f) for f in os.listdir(path)] 
    #create empth face list
    faceSamples=[]
    #create empty ID list
    Ids=[]
    #now looping through all the image paths and loading the Ids and the images
    for imagePath in imagePaths:
        #loading the image and converting it to gray scale
        pilImage=Image.open(imagePath).convert('L');
        #Now we are converting the PIL image into numpy array
        imageNp=np.array(pilImage,'uint8')
        #getting the Id from the image
        Id=int(os.path.split(imagePath)[-1].split(".")[1])
        # extract the face from the training image sample
        # faces = detector.detectMultiScale(imageNp)
        # If a face is there then append that in the list as well as Id of it

        faceSamples.append(imageNp)
        Ids.append(Id)
        cv2.imshow("training",imageNp)
        cv2.waitKey(10)
        #If a face is there then append that in the list as well as Id of it

    return Ids,faceSamples


Ids,faceSamples = getImagesAndLabels('dataset')
recognizer.train(faceSamples, np.array(Ids))
recognizer.save('recognizer/trainningData.yml')
cv2.destroyAllWindows()
