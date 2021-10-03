import turtle
PIXEL_POSITION = [(0, 0), (-20, 0), (-40, 0)]  # positions for the 3 square pixels
MOVE_DISTANCE = 20
UP = 90
DOWN = 270
LEFT = 180
RIGHT = 0


class Snake:
    def __init__(self):
        self.snake_segment = []
        self.create_snake()
        self.head = self.snake_segment[0]

    def create_snake(self):  # creates the initial 3 pixel snake
        # this loop creates the starting snake that is 3 square pixels positioned side by side
        for index in PIXEL_POSITION:
            self.add_segment(index)

    def add_segment(self, index):
        snake_pixel = turtle.Turtle(shape="square")
        snake_pixel.color("white")
        snake_pixel.penup()
        snake_pixel.goto(index)
        self.snake_segment.append(snake_pixel)

    def extend(self):
        self.add_segment(self.snake_segment[-1].position())

    def move_snake(self):
        for segment in range(len(self.snake_segment) - 1, 0, -1):  # start = len -1 because list starts from 0.
            # the next line is used to give the x and y coordinates of the further element to the element before
            # that is the coordinates of 2nd pixel is given to 3rd pixel, 1st to 2nd and so on.
            self.snake_segment[segment].goto(self.snake_segment[segment - 1].xcor(), self.snake_segment[segment - 1].ycor())
        self.head.forward(MOVE_DISTANCE)

    def up(self):
        if self.head.heading() != DOWN:
            self.head.setheading(90)

    def down(self):
        if self.head.heading() != UP:
            self.head.setheading(270)

    def left(self):
        if self.head.heading() != RIGHT:
            self.head.setheading(180)

    def right(self):
        if self.head.heading() != LEFT:
            self.head.setheading(0)
