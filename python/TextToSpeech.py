import pyttsx3  #pip install pyttsx3

#initializing the speak engine
speaker = pyttsx3.init('sapi5')
voices = speaker.getProperty('voices')
speaker.setProperty('voice', voices[1].id)  # 0 for male voice and 1 for female voice

#defining the speak function
def speak(text):
  speaker.say(audio)
  speaker.runAndWait()
  
speak("Hello this code uses pyttsx3 module to convert text to speech")
