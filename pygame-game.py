import pygame, sys
from pygame.locals import *

largura = 900
altura = 400


class Bala(pygame.sprite.Sprite):
    def __init__(self, posx, posy):
        pygame.sprite.Sprite.__init__(self)
        self.ImagemBala = pygame.image.load('imagens/baladourada.png')

        self.rect = self.ImagemBala.get_rect()
        self.velocidadeBala = 5
        self.rect.top = posy
        self.rect.left = posx

    def trajetoria(self):
        self.rect.top = self.rect.top - self.velocidadeBala

    def colocar(self, superficie):
        superficie.blit(self.ImagemBala, self.rect)
        
        
    

class naveEspacial(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.ImagemNave = pygame.image.load('imagens/nave.png')

        self.rect = self.ImagemNave.get_rect()
        self.rect.centerx = largura / 2
        self.rect.centery = altura - 60

        self.listaDisparo = []
        self.vida = True
        self.velocidade = 20

    def movimento(self):
        if self.vida:
            if self.rect.left <= 0:
                self.rect.left = 0

            elif self.rect.right > 900:
                self.rect.right = 900
              
    def disparar(self):
        print('disparou')

    def colocar(self, superficie):
        superficie.blit(self.ImagemNave, self.rect)   



def invasaoEspaco():
    pygame.init()
    tela = pygame.display.set_mode((largura, altura))
    pygame.display.set_caption("Invação do Espaço")

    jogador = naveEspacial()
    ImagemFundo = pygame.image.load('imagens/fundo.png')
    jogando = True

    balaProjetil = Bala(largura/2, altura - 60)

    while True:
        jogador.movimento()
        balaProjetil.trajetoria()
        for evento in pygame.event.get():
            if evento.type == QUIT:
                pygame.quit()
                sys.exit()

            if evento.type == pygame.KEYDOWN:
                if evento.key == K_LEFT:
                    jogador.rect.left -= jogador.velocidade

                elif evento.key == K_RIGHT:
                    jogador.rect.right += jogador.velocidade

                elif evento.key == K_SPACE:
                    jogador.disparar()

        tela.blit(ImagemFundo, (0,0))
        balaProjetil.colocar(tela)
        jogador.colocar(tela)
        pygame.display.update()


invasaoEspaco()
