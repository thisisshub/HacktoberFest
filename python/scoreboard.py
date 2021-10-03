from turtle import Turtle
ALIGNMENT = "center"
FONT = ("Courier", 15, "bold")


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.penup()
        self.goto(x=0, y=300)

        self.color("white")
        self.hideturtle()
        self.update_scoreboard()

    def update_scoreboard(self):
        self.goto(x=0, y=320)
        self.write(f"SCORE: {self.score}", True, align=ALIGNMENT, font=FONT)

    def game_over(self):
        self.goto(x=0, y=0)
        self.write("GAME OVER", True, align=ALIGNMENT, font=("Courier", 25, "bold"))

    def score_increase(self):
        self.score += 1
        self.clear()
        self.update_scoreboard()
