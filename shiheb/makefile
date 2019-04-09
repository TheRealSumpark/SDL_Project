prog:perso.o collision_bounding_box.o
	gcc main.o collision_bounding_box.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf
collision_bounding_box.o:collision_bounding_box.c
	gcc -c collision_bounding_box.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
perso.o:perso.c
	gcc -c perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
