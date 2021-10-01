import time
import threading
from pynput.mouse import Button, Controller
from pynput.keyboard import Listener, KeyCode

delay= 0.001
button= Button.left
actionK = KeyCode(char='s')
cancel = KeyCode(char='d')
class ClickMouse(threading.Thread):
     
     def __init__(self, delay, button):
           super(ClickMouse, self).__init__()
           self.delay = delay
           self.button = button
           self.running = False
           self.program_running = True

     def startC(self):
          self.running = True
          

     def stopC(self):
          self.running = False

     def cancelC(self):
          self.stopC()
          self.program_running = False

     def run(self):
          while self.program_running:
               while self.running:
                    mouse.click(self.button)
                    time.sleep(self.delay)


mouse = Controller()
click_thread = ClickMouse(delay, button)
click_thread.start()


def on_press(key):
     if key == actionK:
          if click_thread.running:
               click_thread.stopC()
          else:
               click_thread.startC()
     elif key == cancel:
          click_thread.cancelC()
          listener.stop()


with Listener(on_press=on_press) as listener:
     listener.join()
           
           
