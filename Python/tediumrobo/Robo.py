class Robo:
    def __init__(self, name, weap, id, damage, life):
        self.__weap = weap
        self.__id = id
        self.__name = name
        self.damage = damage
        self.healt = life

    @property
    def damage(self):
        return self.__damage

    @damage.setter
    def damage(self, bonus):
        self.__damage = bonus

    @property
    def healt(self):
        return self.__healt

    @healt.setter
    def healt(self, hurt):
        self.__healt = hurt

    def __str__(self):
        return "Name: %s Weap: %s Damge: %s Healt: %s" % (self.__name, self.__weap, self.damage, self.healt)

