prog: main.o  Init_Ennemi.o Afficher_Ennemi.o Collision.o
	gcc Init_Ennemi.o  main.o  Afficher_Ennemi.o  Collision.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Afficher_Ennemi.o:Afficher_Ennemi.c
	gcc -c Afficher_Ennemi.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Init_Ennemi.o:Init_Ennemi.c
	gcc -c Init_Ennemi.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Collision.o:Collision.c
	gcc -c Collision.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
