from tkinter import *
from tkinter import ttk, messagebox
import cv2
from datetime import datetime
from PIL import ImageTk, Image

class Alert():
    def __init__(self,master):
        def start():
            status=""
            cap = cv2.VideoCapture(0) #capture video from laptop web-camera
            fourcc = cv2.VideoWriter_fourcc(*'XVID') #video codec
            out = cv2.VideoWriter('Video.mp4',fourcc,20.0,(640,480)) #name of video and frame size of video

            ret, frame1 = cap.read() #capture frame 1
            ret, frame2 = cap.read() #capture next frame

            while cap.isOpened():
                diff = cv2.absdiff(frame1, frame2) #calculate the difference between first frame and next frames
                gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY) #convert image from color space to another
                blur = cv2.GaussianBlur(gray, (5, 5), 0) #remove noise using kernal
                _, thresh = cv2.threshold(blur, 20, 255, cv2.THRESH_BINARY)
                dilated = cv2.dilate(thresh, None, iterations=10)
                contours, _ = cv2.findContours(dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

                # cv2.drawContours(frame1, contours, -1, (0,255,0), 2)

                for contour in contours:
                    (x, y, w, h) = cv2.boundingRect(contour)
                    if cv2.contourArea(contour) < 3000:
                        continue

                    cv2.rectangle(frame1, (x, y), (x + w, y + h), (0, 0, 255), 1)
                    status = "Movement"

                    
                    out.write(frame1)
                cv2.putText(frame1, "Status : {}".format(status), (10, 450), cv2.FONT_HERSHEY_SIMPLEX, 0.7,
                            (255, 255, 255), 2)
                status = ""
                cv2.putText(frame1, "Time : {}".format(datetime.now()), (10, 470), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                            (255, 255, 255), 2)

                cv2.imshow("WiNdoW", frame1)
                frame1 = frame2
                ret, frame2 = cap.read()

                key = cv2.waitKey(40)
                if key == ord('q'):
                    break
            cap.release()
            out.release()
            cv2.destroyAllWindows()

        self.img = ImageTk.PhotoImage(Image.open("Motion-Detection.jpg"))
        self.l = Label(image=self.img)
        self.l.pack()

        self.frame_header = ttk.Frame(master)
        self.frame_header.pack()

        ttk.Label(self.frame_header,text = 'Thanks For Using Our Software').grid(row=0,column = 2)
        ttk.Label(self.frame_header,text = 'Click the Start Button Below to start the surviliance').grid (row=1,column = 2)
        # self.logo = PhotoImage(file='Motion-Detection.jpg')
        # ttk.Label(self.frame_header , image = self.logo).grid(row =0,column =0,rowspan=2)

        self.frame_content = ttk.Frame(master)
        self.frame_content.pack()
        self.frame_content.config(padding =10)
        ttk.Button(self.frame_content,text = 'Start',command = start).grid(row=3,column=0)


def help():
    messagebox.showinfo(title='Help !', message='Working on it. . .')

def about():
    messagebox.showinfo(title='About !', message='Version = 1.0\nLast Update = 22.02.2020\nThank you for using our software.')

def main():
    root =Tk()
    root.title("Motion Dtector")
    root.geometry('800x430+50+10')
    root.resizable(False,False)
    root.option_add('*tearOff',False)
    menubar = Menu(root)
    root.config(menu = menubar)
    File = Menu(menubar)
    # Edit = Menu(menubar)
    Help = Menu(menubar)
    menubar.add_cascade(menu = File,label='File')
    # menubar.add_cascade(menu = Edit,label='Edit')
    menubar.add_cascade(menu = Help,label='Help')
    File.add_command(label= 'New')
    File.add_separator()
    File.add_command(label= 'Open')
    File.add_command(label= 'Save')
    File.add_command(label= 'Save As')
    File.add_separator()
    File.add_command(label= 'Exit',command=root.quit)
    # Edit.add_command(label='Undo')
    # Edit.add_command(label='Redo')
    # Edit.add_command(label='Delete')
    Help.add_command(label='Help?',command = help)
    Help.add_separator()
    Help.add_command(label='About',command= about)
    label = ttk.Label(root, text="Motion Detector").pack()
    alert = Alert(root)
    root.mainloop()

if __name__ == "__main__" : main()
