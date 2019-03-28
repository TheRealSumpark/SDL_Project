prog: main.o Perfect_Collision.o Animer_Personnage.o
	gcc   main.o  Perfect_Collision.c Animer_Personnage.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Perfect_Collision.o:Perfect_Collision.c
	gcc -c Perfect_Collision.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Animer_Personnage.o:Animer_Personnage.c	
	gcc -c Animer_Personnage.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
