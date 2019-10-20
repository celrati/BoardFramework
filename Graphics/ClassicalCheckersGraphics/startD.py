import pygame

pygame.init()
BLACK   = (   0,   0,   0)
GREEN    = (   0, 255,   0)

size = (700, 700)
screen = pygame.display.set_mode(size)


ok = True
clock = pygame.time.Clock()


while ok:
    screen.fill((0,0,0))
    file = open("../dataBoardC.oc",'r')
    filenoti = open("../dataNotif.oc",'r')

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            ok = False

    wallpaper = pygame.image.load("boardDame.png").convert()
    font=pygame.font.Font(None,30)
    screen.blit(wallpaper,(13,52))#10,50 pour 10x10
    scoretext=font.render("         Checkers v0.2 by Achraf && Oussama      ", 1,(255,0,0))
    screen.blit(scoretext, (10, 0))
    #screen.fill(GREEN)

    # we 're' gonna blit the pieces lol --
    i = 1
    for line in file:
        if i >= 2 and i < 22:
            row = line[2:].split('|')[1:][:8];
            if(len(row) != 0):
                for j in range(0,8):
                    if(row[j] != "###" and row[j] != "   "):
                        if(row[j] == " O "):
                            piece = pygame.image.load("Pieces/white.png").convert_alpha()
                            piece = pygame.transform.scale(piece, (55, 55))
                            screen.blit(piece,(42+(j)*56.5, 80 + ((i - 3) * 28.5) ))
                        elif(row[j] == " @ "):
                            piece = pygame.image.load("Pieces/black.png").convert_alpha()
                            piece = pygame.transform.scale(piece, (55, 55))
                            screen.blit(piece,(42+(j)*56.5, 80 + ((i - 3) * 28.5) ))
                        elif(row[j] == " K "):
                            piece = pygame.image.load("Pieces/blackK.png").convert_alpha()
                            piece = pygame.transform.scale(piece, (55, 55))
                            screen.blit(piece,(42+(j)*56.5, 80 + ((i - 3) * 28.5) ))
                        elif(row[j] == " Q "):
                            piece = pygame.image.load("Pieces/whiteK.png").convert_alpha()
                            piece = pygame.transform.scale(piece, (55, 55))
                            screen.blit(piece,(42+(j)*56.5, 80 + ((i - 3) * 28.5) ))
                            #screen.blit(piece,(55+(j)*63, 97 + ((i - 3) * 63) ) )
            # here we get the row  each time --
            # now we have just to print the pieces on the board
            #print row
        i = i + 1
        
    for line in filenoti:
        scoretext=font.render("notification : "+line, 1,(0,255,0))
        screen.blit(scoretext, (0, 650))
        pygame.display.flip()

    pygame.display.flip()

    clock.tick(60)









