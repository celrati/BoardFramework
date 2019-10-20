import pygame

pygame.init()
BLACK   = (   0,   0,   0)
GREEN    = (   0, 255,   0)

size = (700, 700)
screen = pygame.display.set_mode(size)

# declare the pieces
pawnBlack = pygame.image.load("Pieces/B1.png").convert_alpha()

ok = True
clock = pygame.time.Clock()


while ok:
	screen.fill((0,0,0))
	file = open("../dataBoard.oc",'r')
	filenoti = open("../dataNotif.oc",'r')

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			ok = False
	

	wallpaper = pygame.image.load("board.jpg").convert()
	font=pygame.font.Font(None,30)
	screen.blit(wallpaper,(10,50))
	scoretext=font.render("         Chess v0.4 by Achraf && Oussama         ", 1,(150,45,78))
	screen.blit(scoretext, (10, 0))
	#screen.fill(GREEN)

	# we 're' gonna blit the pieces lol --
	i = 1
	for line in file:
		if i >= 3 and i < 11:
			row = line[2:].split('||')[1:][:8]
			for j in range(0,8):
				if(row[j] != "00" and row[j] != "11"):					
					piece = pygame.image.load("Pieces/"+row[j]+".png").convert_alpha()
					screen.blit(piece,(55+(j)*63, 97 + ((i - 3) * 63) ) )
				
			# here we get the row  each time --
			# now we have just to print the pieces on the board
			#print row
		i = i + 1
		
	for line in filenoti:
		scoretext=font.render("notification : "+line, 1,(70,25,250))
		screen.blit(scoretext, (0, 650))
		pygame.display.flip()

	pygame.display.flip()

	clock.tick(60)






	


