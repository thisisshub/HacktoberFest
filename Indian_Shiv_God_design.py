import turtle

turtle.speed(0)
turtle.setup(800, 600)
turtle.speed(9)
turtle.up()


def my_goto(x, y):
    turtle.pencolor("orange")
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()


def round_rectangale(center_x, center_y, width, height, cornersize):
    turtle.up()
    turtle.goto(center_x-width/2+cornersize, center_y-height/2)
    turtle.down()
    for _ in range(2):
        turtle.fillcolor("black")
        turtle.begin_fill()
        turtle.fd(width-2*cornersize)
        turtle.circle(cornersize, 90)
        turtle.fd(height-2*cornersize)
        turtle.circle(cornersize, 90)
        turtle.end_fill()


def round_rectangale(center_x, center_y, width, height, cornersize):
    turtle.up()
    turtle.goto(center_x-width/2+cornersize, center_y-height/2)
    turtle.down()
    for _ in range(2):
        turtle.fillcolor("black")
        turtle.begin_fill()
        turtle.fd(width-2*cornersize)
        turtle.circle(cornersize, 90)
        turtle.fd(height-2*cornersize)
        turtle.circle(cornersize, 90)
        turtle.end_fill()


round_rectangale(0, 0, 200, 300, 80)
turtle.fillcolor('black')
turtle.begin_fill()

turtle.goto(-35, 40)
turtle.fillcolor('white')
turtle.begin_fill()
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)

turtle.goto(-35, 80)
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)

turtle.goto(-35, 60)
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)
turtle.forward(80)
turtle.left(90)
turtle.forward(10)
turtle.left(90)
turtle.pendown()

turtle.end_fill()
turtle.fillcolor('red')
turtle.begin_fill()
turtle.goto(5, 50)
turtle.penup()
turtle.circle(15)
turtle.pendown()
turtle.end_fill()

turtle.goto(-150, -175)
turtle.begin_fill()
turtle.pencolor("black")
turtle.fillcolor("black")
round_rectangale(90, -125, 600, 100, 50)
turtle.begin_fill()
turtle.goto(-70, -175)
turtle.setheading(110)
turtle.circle(80, -100)
turtle.goto(140, -280)
turtle.setheading(350)
turtle.circle(80, -100)
turtle.end_fill()
turtle.done()
