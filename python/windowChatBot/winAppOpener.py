import os
import pyttsx3
pyttsx3.speak("Hello Buddy! I am your personal assistant.")
while True: 
       pyttsx3.speak("How can I help you?")   
       print("How can I help you:",end='')
       p=input()
       p=p.lower()
       if (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p))and (("chrome" in p) or ("browser" in p)):
          pyttsx3.speak("Opening chrome browser.") 
          os.system("chrome")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("notepad" in p) or ("editor" in p)):
          pyttsx3.speak("Opening Notepad editor.")
          os.system("notepad")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("player" in p) or ("video player" in p) or ("media player" in p) or ("music player" in p)):
          pyttsx3.speak("Opening window media player.")
          os.system("wmplayer")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("mycomputer" in p) or ("my computer" in p) or ("file manager" in p) or ("explorer" in p) or ("file explorer" in p)):
          pyttsx3.speak("This program is compatible to open C drive to F drive.")
          print("NOTE:This program can open C to F drive.")
          pyttsx3.speak("which drive do yo want me to open?.")
          print("which drive do yo want me to open: ",end='')
          pyttsx3.speak("Opening.")
          q=input()
          if q=='c' or q=='C':
            path = "C:/"
            path = os.path.realpath(path)
            os.startfile(path)
          elif q=='d' or q=='D':
            path = "D:/"
            path = os.path.realpath(path)
            os.startfile(path)
          elif q=='e' or q=='E':
            path = "E:/"
            path = os.path.realpath(path)
            os.startfile(path)
          elif q=='f' or q=='F':
            path = "F:/"
            path = os.path.realpath(path)
            os.startfile(path)
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("media player" in p) or ("video player" in p) or ("music player" in p)):
          pyttsx3.speak("Opening window media player.")
          os.system("wmplayer")
       elif (("exit" in p) or ("stop" in p) or ("terminate" in p) or ("end" in p) or ("break" in p)):
          pyttsx3.speak("thank you! Visit again.")
          print("Visit again!")
          break
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("pdf reader" in p) or ("reader" in p) or ("Adobe Reader" in p)):
          pyttsx3.speak("Opening Adobe reader.")
          os.system("acroRd32")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("excel" in p) or ("Excel" in p)):
          pyttsx3.speak("Opening Excel.")
          os.system("Excel")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("power point" in p) or ("powerpoint" in p)):
          pyttsx3.speak("Opening PowerPoint.")
          os.system("POWERPNT")
       elif (("run" in p) or ("execute" in p) or ("launch" in p) or ("open" in p)) and (("word" in p) or ("ms word" in p)):
          pyttsx3.speak("Opening M S Word.")
          os.system("WINWORD")
       else:
          pyttsx3.speak("sorry! program not found.Try another way or install the program.")
          print("sorry! program not found.\nTry another way or install the program")
