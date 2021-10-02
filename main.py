import turtle
import time
from snake import Snake
from food import Food
from scoreboard import Scoreboard
screen = turtle.Screen()
screen.setup(width=700, height=700)  # set the dimensions of the screen
screen.bgcolor("black")  # set the background color of the screen
screen.title("Snake Game")  # set the title of the screen
screen.tracer(0)  # this method turns on or off the animations,can be used to accelerate the drawing of complex graphics

snake = Snake()
food = Food()
scoreboard = Scoreboard()
screen.listen()
screen.onkey(snake.up, "Up")
screen.onkey(snake.down, "Down")
screen.onkey(snake.left, "Left")
screen.onkey(snake.right, "Right")

game_is_on = True

while game_is_on:
    screen.update()
    time.sleep(0.1)  # this will add delay to the refreshing cycle of the screen
    snake.move_snake()

    # Check if the snake head has collided with any of the 4 boundaries of the screen, if yes then exit the game
    if snake.head.xcor() > 345 or snake.head.ycor() > 345 or snake.head.xcor() < -345 or snake.head.ycor() < -345:
        game_is_on = False
        scoreboard.game_over()

    # detect collision with food
    if snake.head.distance(food) < 15:
        food.refresh()
        scoreboard.score_increase()
        snake.extend()
    # detect collision with tail
    for segment in snake.snake_segment[1::]:
        if snake.head.distance(segment) < 10:
            game_is_on = False
            scoreboard.game_over()

screen.exitonclick()
