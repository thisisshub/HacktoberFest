from turtle import Turtle
import random


class Food(Turtle):  # we have inherited Turtle directly so that the Food class contains all the methods and attributes
    # of the Turtle and we don't need to create another function to do that.

    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.penup()
        self.shapesize(stretch_len=0.5, stretch_wid=0.5)  # shapesize stretches the length and width of the shape times
        # the specified number
        self.color("blue")
        self.speed("fastest")
        self.refresh()

    def refresh(self):
        self.goto(x=random.randint(-320, 320), y=random.randint(-320, 320))

