prog:afficher_perso.o main.o initial_perso.o collision_bounding_box.o Animer_Personnage.o
	gcc afficher_perso.o main.o initial_perso.o collision_bounding_box.o Animer_Personnage.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
initial_perso.o:initial_perso.c
	gcc -c initial_perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Animer_Personnage.o:Animer_Personnage.c
	gcc -c Animer_Personnage.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
collision_bounding_box.o:collision_bounding_box.c
	gcc -c collision_bounding_box.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
afficher_perso.o:afficher_perso.c
	gcc -c afficher_perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
