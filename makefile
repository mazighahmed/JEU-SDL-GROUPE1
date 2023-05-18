prog:main.o image.o bouton.o menu.o texte.o player.o background.o robots.o enigme.o collision.o score.o door.o mini-map.o sousmenu.o IA2.o enigme2.o
	gcc main.o image.o bouton.o menu.o texte.o player.o background.o robots.o enigme.o collision.o score.o door.o mini-map.o sousmenu.o enigme2.o IA2.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g
texte.o:texte.c 
	gcc -c texte.c -g
bouton.o:bouton.c
	gcc -c bouton.c -g
image.o:image.c 
	gcc -c image.c -g
menu.o:menu.c 
	gcc -c menu.c -g
player.o:player.c 
	gcc -c player.c -g
background.o:background.c 
	gcc -c background.c -g
robots.o:robots.c 
	gcc -c robots.c -g
enigme.o:enigme.c 
	gcc -c enigme.c -g
collision.o:collision.c 
	gcc -c collision.c -g
score.o:score.c 
	gcc -c score.c -g
door.o:door.c
	gcc -c door.c -g
mini-map.o:mini-map.c
	gcc -c mini-map.c -g
sousmenu.o:sousmenu.c
	gcc -c sousmenu.c -g
IA2.o:IA2.c
	gcc -c IA2.c -g
enigme2.o:enigme2.c
	gcc -c enigme2.c -g
