import Grid
import Robo
import random


class Control:

    def __init__(self, dimension):
        self.__dimension = dimension
        self.__id = -1
        self.__robots = {}
        self.__grid = Grid.Matrix(self.__dimension)
        self.__weapons = {'gun': 10, 'knife': 5}
        self.__healt = {'gun': 20, 'knife': 40}
        self.__filler = {"", " ", "\"\""}

    def create_robot(self, name, weap):
        if name not in self.__robots and weap in self.__weapons and name not in self.__filler:
            self.__id += 1
            robot = Robo.Robo(name, weap, self.__id, self.__weapons[weap], self.__healt[weap])
            self.__robots.__setitem__(name, robot)
            self.__grid.move(random.randrange(self.__dimension), random.randrange(self.__dimension), name)
        else:
            print("Nome già scelto o arma non valida")

    # TODO add a range
    def attack(self, atk, defen):
        if atk != defen:
            if atk in self.__robots:
                if defen in self.__robots:
                    att = self.__robots[atk]
                    dff = self.__robots[defen]
                    dff.healt -= att.damage
                    if dff.healt <= 0:
                        del self.__robots[defen]
                        self.__grid.delete(defen)
                        print("Robot  %s  distrutto" % defen)
                else:
                    print("Robot difensore non trovato.(%s non esiste )" % defen)
            else:
                print("Robot attaccante non trovato.(%s non esiste )" % atk)

    # TODO add move in view
    def move(self, x, y, name):
        if x <= self.__dimension and y <= self.__dimension and self.__grid.matrix[x][y] == "empty":
            if name in self.__robots:
                self.__grid.move(x, y, name)

    def refresh(self):
        return self.__grid.view

    # TODO buff/malus
