import sys
from tkinter import *


# My frame for form
class simpleform_ap(Tk):

    def __init__(self, parent):
        Tk.__init__(self, parent)
        self.parent = parent
        self.initialize()
        self.grid()

    def initialize(self):
        # Dropdown Menu
        optionList = ["Yes", "No"]
        self.dropVar = StringVar()
        self.dropVar.set("Select Group")  # default choice
        self.dropMenu1 = OptionMenu(self, self.dropVar, *optionList,
                                    command=self.func)
        self.dropMenu1.grid(column=1, row=4)

    def func(self, value):
        print(self.dropVar.get())


def create_form(argv):
    form = simpleform_ap(None)
    form.title('My form')
    form.mainloop()


if __name__ == "__main__":
    create_form(sys.argv)
