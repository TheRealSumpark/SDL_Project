prog:afficher_perso.o main.o initial_perso.o
	gcc afficher_perso.o main.o initial_perso.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
initial_perso.o:initial_perso.c
	gcc -c initial_perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
afficher_perso.o:afficher_perso.c
	gcc -c afficher_perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
