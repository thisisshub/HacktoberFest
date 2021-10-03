import pygame
import random
from pygame import mixer
pygame.font.init()
pygame.mixer.init()
pygame.init()

# Creating main Screen
screen_width = 600
screen_height = 600
gamewindow = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Space Invaders")
# pygame.display.update()
display_font = pygame.font.SysFont("comicsans", 30)
lost_font = pygame.font.SysFont("comicsans", 50)
instruct =pygame.font.SysFont("comicsans", 20)
# require variables
lives = 5
score = 0
pause = False
# # Colors
white = (255, 255, 255)
red = (200, 0, 0)
black = (0, 0, 0)
yellow = (225, 235, 87)
light_green = (153, 232, 74)
green = (37, 224, 4)
purple = (231, 235, 16)
voilet = (245, 245, 162)
light_red = (255, 0, 0)
blue = (6, 79, 189)
clock = pygame.time.Clock()
fps = 60
# Loading all images require in game
overimg = pygame.image.load("icon/background1.jpg")
overimg = pygame.transform.scale(overimg, (screen_width, screen_height)).convert_alpha()
welcome_screen = pygame.image.load("icon/welcome.png")
welcome_screen = pygame.transform.scale(welcome_screen, (screen_width, screen_height)).convert_alpha()
background = pygame.image.load("icon/background.jpg")
background = pygame.transform.scale(background, (screen_width, screen_height)).convert_alpha()
spaceship = pygame.image.load("icon/spaceship.png")
enemy2 = pygame.image.load("icon/enemy2.png").convert_alpha()
enemy3 = pygame.image.load("icon/enemy3.png").convert_alpha()
enemy1 = pygame.image.load("icon/enemy1.png").convert_alpha()
bullet = pygame.image.load("icon/bullet.png").convert_alpha()
enemybullet = pygame.image.load("icon/enemybullet.png").convert_alpha()
game_over = False
exit_game = False
ship_x = 270
ship_y = 500
bulletx = 0
bullety = 420
bulletx_change = 0
bullety_change = 10
state = "ready"

pygame.mixer.music.load("icon/b1.wav")
pygame.mixer.music.play(-1)
def quit_game():
    pygame.quit()
    quit()


class Laser:
    def __init__(self, x, y, img):
        self.x = x
        self.y = y
        self.img = img
        self.mask = pygame.mask.from_surface(self.img)

    def draw(self, window):
        window.blit(self.img, (self.x, self.y))

    def move(self, vel):
        self.y += vel

    def off_screen(self, height):
        return not(self.y <= height and self.y >= 0)

    def collision(self, obj):
        return collide(self, obj)


class Ship:
    COOLDOWN = 30

    def __init__(self, x, y, health=300):
        self.x = x
        self.y = y
        self.health = health
        self.ship_img = None
        self.laser_img = None
        self.lasers = []
        self.cool_down_counter = 0

    def draw(self, window):
        window.blit(self.ship_img, (self.x, self.y))
        for laser in self.lasers:
            laser.draw(window)

    def move_lasers(self, vel, obj):
        self.cooldown()
        for laser in self.lasers:
            laser.move(vel)
            if laser.off_screen(screen_height):
                self.lasers.remove(laser)
            elif laser.collision(obj):
                obj.health -= 10
                self.lasers.remove(laser)

    def cooldown(self):
        if self.cool_down_counter >= self.COOLDOWN:
            self.cool_down_counter = 0
        elif self.cool_down_counter > 0:
            self.cool_down_counter += 1

    def shoot(self):
        if self.cool_down_counter == 0:
            laser = Laser(self.x+22, self.y-20, self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter = 1

    def shoot1(self):
        if self.cool_down_counter == 1:
            laser = Laser(self.x-15, self.y+10, self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter = 1
    def shoot2(self):
        if self.cool_down_counter == 0:
            laser = Laser(self.x + 60, self.y+10, self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter = 1
    def shoot3(self):
        if self.cool_down_counter == 1:
            laser = Laser(self.x + 60, self.y + 10, self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter = 1



    def get_width(self):
        return self.ship_img.get_width()

    def get_height(self):
        return self.ship_img.get_height()


class Player(Ship):
    def __init__(self, x, y, health=300):
        super().__init__(x, y, health)
        self.ship_img = spaceship
        self.laser_img = bullet
        self.mask = pygame.mask.from_surface(self.ship_img)
        self.max_health = health

    def move_lasers(self, vel, objs):
        self.cooldown()
        global score
        for laser in self.lasers:
            laser.move(vel)
            if laser.off_screen(screen_height):
                self.lasers.remove(laser)
            else:
                for obj in objs:
                    if laser.collision(obj):
                        objs.remove(obj)
                        if laser in self.lasers:
                            self.lasers.remove(laser)
                        score += 1

    def draw(self, window):
        super().draw(window)
        self.healthbar(window)

    def healthbar(self, gamewindow):
        pygame.draw.rect(gamewindow, (255,0,0), (self.x, self.y + self.ship_img.get_height() + 10, self.ship_img.get_width(), 10))
        pygame.draw.rect(gamewindow, (0,255,0), (self.x, self.y + self.ship_img.get_height() + 10, self.ship_img.get_width() * (self.health/self.max_health), 10))


class Enemy(Ship):
    COLOR_MAP = {
                "red": (enemy1, enemybullet),
                "green": (enemy2, enemybullet),
                "blue": (enemy3, enemybullet)
                }

    def __init__(self, x, y, color, health=200):
        super().__init__(x, y, health)
        self.ship_img, self.laser_img = self.COLOR_MAP[color]
        self.mask = pygame.mask.from_surface(self.ship_img)

    def move(self, vel):
        self.y += vel

    def shoot(self):
        if self.cool_down_counter == 0:
            laser = Laser(self.x+15, self.y+60, self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter = 1


def message_display_pause(text, color):
    largeText = pygame.font.SysFont('Comicsansms', 80)
    TextSurf, TextRect = text_objects(text, largeText, color)
    TextRect.center = ((screen_width / 2), (screen_height / 2))
    gamewindow.blit(TextSurf, TextRect)


def message_display(text, color):
    largeText = pygame.font.SysFont('Comicsansms', 115)
    TextSurf, TextRect = text_objects(text, largeText, color)
    TextRect.center = ((screen_width / 2), (screen_height / 2))
    gamewindow.blit(TextSurf, TextRect, )


def text_objects(text, font, color):
    textSurface = font.render(text, True, color)
    return textSurface, textSurface.get_rect()


def text_screen(text, color, x, y):
    largeText = pygame.font.SysFont('Comicsansms', 15)
    screen_text = lost_font.render(text, True, color)
    gamewindow.blit(screen_text, largeText, [int(x), int(y)])


def over():
    pygame.mixer.music.load("icon/explosion.mp3")
    pygame.mixer.music.play()

    gamewindow.blit(overimg, (0, 0))
    score_label = display_font.render(f"Your Score: {score} ", 1, white)
    gamewindow.blit(score_label, (int((screen_width / 2) - score_label.get_width() / 2), int(10)))
    while True:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
                quit_game()
            if event.type == pygame.KEYDOWN:

                if event.key == pygame.K_ESCAPE:
                    quit_game()
                if event.key == pygame.K_RETURN:
                    mainloop()
        button("Replay", screen_width * 0.1, screen_height - 140, 120, 35, green, light_green, mainloop)
        button("Quit", screen_width * 0.7, screen_height - 140, 100, 35, purple, voilet, quit_game)

        pygame.display.update()
        clock.tick(60)



def button(msg, x, y, w, h, ic, ac, action=None):
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    if x + w > mouse[0] > x and y + h > mouse[1] > y:
        pygame.draw.rect(gamewindow, ac, (x, y, w, h))
        if click[0] == 1 and action != None:
            action()
    else:
        pygame.draw.rect(gamewindow, ic, (x, y, w, h))

    smallText = pygame.font.SysFont("Comicsansms", 20)
    textSurf, textRect = text_objects(msg, smallText, color=blue)
    textRect.center = ((x + (w / 2)), (y + (h / 2)))
    gamewindow.blit(textSurf, textRect)


def paused():

    while pause:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c or pygame.K_SPACE:
                    # pygame.mixer.music.load("back.mp3")
                    # pygame.mixer.music.play()
                    unpause()
                if event.key == pygame.K_ESCAPE:
                    quit_game()
                if event.key == pygame.K_q:
                    quit_game()

        # gamewindow.blit(pause1, (0, 0))
        message_display("PAUSED", yellow)

        button("Continue", screen_width * 0.1, screen_height - 140, 120, 35, green, light_green, unpause)
        button("Quit", screen_width * 0.7, screen_height - 140, 100, 35, purple, voilet, quit_game)

        pygame.display.update()
        clock.tick(30)


def unpause():
    global pause
    pause = False

def collide(obj1, obj2):
    offset_x = obj2.x - obj1.x
    offset_y = obj2.y - obj1.y
    return int(obj1.mask.overlap(obj2.mask, (offset_x, offset_y)) != None)

def instruction():

    exit_game = False
    while not exit_game:

        gamewindow.blit(background, (0, 0))
        ins0 = lost_font.render(" Controls ", 1, white)
        gamewindow.blit(ins0, (225, 60))
        ins1 = display_font.render("Arrow keys = Move spaceship in all directions  ", 1, white)
        gamewindow.blit(ins1,(50,130))
        ins2 = display_font.render("Space button = Fire!!  ", 1, white)
        gamewindow.blit(ins2, (50, 170))
        ins3 = display_font.render(" P button = pause game ", 1, white)
        gamewindow.blit(ins3, (50, 210))
        ins4 = display_font.render("Escape button = Quit the game", 1, white)
        gamewindow.blit(ins4, (50, 250))
        ins5 = display_font.render("Enter button = Start the war", 1, white)
        gamewindow.blit(ins5, (50, 290))
        ins6 = display_font.render("If  enemy goes off the screen, you will loose your life", 1, white)
        gamewindow.blit(ins6, (50, 330))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    quit()
                if event.key == pygame.K_RETURN:
                    mainloop()
        button("START", screen_width * 0.4, screen_height - 140, 120, 35, green, light_green, mainloop)
        pygame.display.update()
        clock.tick(60)



def welcome():

    exit_game =False
    while not exit_game:

        gamewindow.blit(welcome_screen, (0,0))
        # text_screen("WELCOME TO SNAKES BY ADITYA",red,120,20)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    quit()
                if event.key == pygame.K_RETURN:

                    mainloop()
                if event.key == pygame.K_c:
                    instruction()
        button("Controls", screen_width * 0.1, screen_height - 140, 120, 35, red, light_red,instruction)
        button("START", screen_width * 0.4, screen_height - 140, 120, 35, green, light_green, mainloop)
        button("Quit",screen_width * 0.7, screen_height - 140, 100, 35, purple, voilet,quit_game)

        pygame.display.update()
        clock.tick(60)



def mainloop():
    global pause
    global clock
    global fps
    global state
    global cool_down_counter
    global bulletx
    global bullety
    global bullety_change
    laser_vel = 10
    enemies = []
    wave_length = 2
    enemy_vel = 2
    init_velocity = 4
    global game_over
    global exit_game
    bgh = 0
    global score
    lives = 5
    level = 0
    score = 0
    player = Player(270, 500)
    pygame.mixer.music.load("icon/b1.wav")
    pygame.mixer.music.play(-1)
    def drawwindow():
        # draw text

        lives_label = display_font.render(f"Lives: {lives} ", 1, white)
        level_label = display_font.render(f"Level: {level} ", 1, white)
        score_label = display_font.render(f"score: {score} ", 1, white)
        gamewindow.blit(lives_label, (10, 10))
        gamewindow.blit(level_label, (screen_width - level_label.get_width() - 10, 10))
        gamewindow.blit(score_label, (int((screen_width / 2) - score_label.get_width() / 2), int(10)))

        # enemies function
        for enemy in enemies:
            enemy.draw(gamewindow)

        player.draw(gamewindow)


    while not exit_game:


        clock.tick(fps)
        player.move_lasers(-laser_vel, enemies)
        player.move_lasers(-laser_vel, enemies)

        if len(enemies) == 0:
            level += 1
            wave_length += 5
            for i in range(wave_length):
                enemy = Enemy(random.randrange(50, screen_width - 50), random.randrange(-1500, -100),
                              random.choice(["red", "green", "blue"]))
                enemies.append(enemy)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
                quit_game()
        key = pygame.key.get_pressed()
        if key[pygame.K_ESCAPE]:
            quit_game()
        if key[pygame.K_RIGHT] or key[pygame.K_d]:
            player.x += init_velocity

        if key[pygame.K_LEFT] or key[pygame.K_a]:
            player.x -= init_velocity

        if key[pygame.K_UP] or key[pygame.K_w]:
            player.y -= init_velocity

        if key[pygame.K_DOWN] or key[pygame.K_s]:
            player.y += init_velocity
        if key[pygame.K_p]:
            pause = True
            paused()
        if key[pygame.K_SPACE]:
            sound = mixer.Sound("icon/shoot.wav")
            sound.play()
            if level <= 3:
                player.shoot()
            elif level <=7:
                enemy_vel = int(2.3)
                cool_down_counter = 0
                player.shoot2()
                cool_down_counter = 1
                player.shoot1()
            else :
                enemy_vel = 3
                player.shoot()
                cool_down_counter = 1
                player.shoot1()#left
                cool_down_counter = 1
                player.shoot3()#right


         # PLayer Adjustment
        if player.x < 0:
            player.x = 0
        if player.x > 520:
            player.x = 520
        if player.y < 0:
            player.y = 0
        if player.y > 490:
            player.y = 490


        rel_bgh = bgh % background.get_rect().height
        gamewindow.blit(background, (int(0), rel_bgh - background.get_rect().height))
        bgh += 1
        if rel_bgh < screen_height:
            gamewindow.blit(background, (int(0), int(rel_bgh)))

        for enemy in enemies[:]:
            enemy.move(enemy_vel)
            enemy.move_lasers(laser_vel, player)

            if random.randrange(0, 2 * 60) == 1:
                enemy.shoot()

            if collide(enemy, player):
                player.health -= 10
                enemies.remove(enemy)
                # score += 1
            elif enemy.y + enemy.get_height() > screen_height:
                lives -= 1
                enemies.remove(enemy)

        if lives <= 0 or player.health <= 0:
            over()

        drawwindow()
        pygame.display.update()


welcome()