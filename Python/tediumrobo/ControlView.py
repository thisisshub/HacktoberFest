"""
import Control
from tkinter import *


class Application(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createlabel(master)
        self.control = Control.Control(10)
        self.mylabel = Label()
        self.mylabel.pack()
        self.contents = StringVar()
        self.contents.set(self.control.refresh())
        self.mylabel["textvariable"] = self.contents


    def createlabel(self, master):
        self.robot = Button(self, text="Create a robot", command=self.createrobot).grid(row = 1, column = 0)
        #self.hi_there = Button(self, text="Refresh", command=self.refresh).grid(row = 1, column = 1)
        self.attack_button = Button(self, text=" attack a robot", command=self.attack).grid(row = 1, column = 1)
        self.quit = Button(self, text="Esci", fg="red", command=master.destroy).grid(row = 1, column = 2)

    def refresh(self):
        self.contents.set(self.control.refresh())

    def createrobot(self):
        self.top = Toplevel(self)
        self.labelname = Label(self.top, text="Name").grid(row=0)
        self.labelweap = Label(self.top, text="Weap").grid(row=1)
        self.name = Entry(self.top)
        self.weap = Entry(self.top)
        self.name.grid(row=0, column=1)
        self.weap.grid(row=1, column=1)
        self.check = Button(self.top, text="Crea", command=self.create).grid(row=2, column=1)


    def create(self):
        self.control.createrobot(self.name.get(), self.weap.get())
        self.refresh()
        self.top.destroy()

    def attack(self):
        self.control.attack(self.name.get(), self.weap.get())
        self.refresh()
        self.top.destroy()

    def start(self):
        test = Tk()
        app = Application(test)
        app.mainloop()



"""
import Control
from tkinter import *


class Application(Frame):
    def __init__(self, dimension, master=None):
        Frame.__init__(self, master)
        self.master.title('Tediumrobo')
        self.pack()
        self.create_label(master)
        self.control = Control.Control(dimension)
        self.my_label = Label()
        self.my_label.pack()
        self.contents = StringVar()
        self.contents.set(self.control.refresh())
        self.my_label["textvariable"] = self.contents

    def create_label(self, master):
        self.create_robot = Button(self, text="Crea un robot", command=lambda: self.entry(0)).grid(row=1, column=0)
        # self.hi_there = Button(self, text="Refresh", command=self.refresh).grid(row=1, column=1)
        self.attack_button = Button(self, text=" attacca un robot", command=lambda: self.entry(1)).grid(row=1, column=1)
        self.quit = Button(self, text="Esci", fg="red", command=master.destroy).grid(row=1, column=3)

    def refresh(self):
        self.contents.set(self.control.refresh())

    def entry(self, case):
        self.top = Toplevel(self)
        if case is 0:
            self.label_one = Label(self.top, text="Nome").grid(row=0)
            self.label_two = Label(self.top, text="Arma").grid(row=1)
        else:
            self.label_one = Label(self.top, text="Attacker").grid(row=0)
            self.label_two = Label(self.top, text="Defender").grid(row=1)

        self.one = Entry(self.top)
        self.two = Entry(self.top)
        self.one.grid(row=0, column=1)
        self.two.grid(row=1, column=1)
        self.check = Button(self.top, text="Ok", command=lambda: self.action(case)).grid(row=2, column=1)

    def action(self, action):
        if action is 0:
            self.control.create_robot(self.one.get(), self.two.get())
        else:
            self.control.attack(self.one.get(), self.two.get())
        self.refresh()
        self.top.destroy()

    @staticmethod
    def start(self, dimension):
        game = Tk()
        app = Application(dimension, game)
        app.mainloop()
