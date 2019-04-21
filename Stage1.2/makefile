prog:collision_bounding_box.o main.o perso.o Animer_Personnage.o initialiser_ojbets.o Afficher_objets.o initialiser_background.o afficher_background.o scrolling.o collision.o Init_Ennemi.o Afficher_Ennemi.o quiz.o Collision_trigo.o Perfect_Collision.o mvtaleatoire.o
	gcc collision_bounding_box.o main.o perso.o Animer_Personnage.o initialiser_ojbets.o Afficher_objets.o initialiser_background.o afficher_background.o scrolling.o collision.o Init_Ennemi.o Afficher_Ennemi.o quiz.o Collision_trigo.o Perfect_Collision.o mvtaleatoire.o -o prog -g $(sdl-config --libs --cflags) -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm
collision_bounding_box.o:collision_bounding_box.c
	gcc -c collision_bounding_box.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Animer_Personnage.o:Animer_Personnage.c
	gcc -c Animer_Personnage.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
initialiser_ojbets.o:initialiser_ojbets.c
	gcc -c initialiser_ojbets.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Afficher_objets.o:Afficher_objets.c
	gcc -c Afficher_objets.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
initialiser_background.o:initialiser_background.c
	gcc -c initialiser_background.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
afficher_background.o:afficher_background.c
	gcc -c afficher_background.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
scrolling.o:scrolling.c
	gcc -c scrolling.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
perso.o:perso.c
	gcc -c perso.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
collision.o:collision.c
	gcc -c collision.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Init_Ennemi.o:Init_Ennemi.c
	gcc -c Init_Ennemi.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Afficher_Ennemi.o:Afficher_Ennemi.c
	gcc -c Afficher_Ennemi.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
mvtaleatoire.o:mvtaleatoire.c
	gcc -c mvtaleatoire.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
quiz.o:quiz.c
	gcc -c quiz.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf
Perfect_Collision.o:Perfect_Collision.c
	gcc -c Perfect_Collision.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
Collision_trigo.o:Collision_trigo.c
	gcc -c Collision_trigo.c -g $(sdl-config --libs --cflags) -lSDL_mixer -lSDL_image -lSDL_ttf -lm
