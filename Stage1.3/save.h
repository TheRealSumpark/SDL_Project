#ifndef SAVE_H_
#define SAVE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include "perso.h"
#include "Init_Ennemi.h"
#include "Ennemi.h"
#include "collision_bounding_box.h"

typedef struct 
{
 
SDL_Surface *image;
SDL_Rect positionecran;
Mix_Music *music;
SDL_Rect camera;
	
}background;
typedef struct Player
{	
	SDL_Surface *perso;
    	SDL_Rect Pos_perso;
	SDL_Surface *perso_mv_right[5];
	SDL_Surface *perso_idle[2];
	SDL_Surface *perso_attack_right[5];
	SDL_Surface *perso_mv_left[5];
	SDL_Surface *perso_attack_left[5];
	SDL_Rect positionHealth;
	SDL_Surface *Player_Health[3];
	int nmb_mv;
	int nmb_attack;
	int P_health;
}Player;

typedef struct EO
{
	SDL_Surface *objett;
	SDL_Surface *surf1;
    	SDL_Rect positionsurf1;
	SDL_Rect positionobjett;
}EO;

void saveGame(char nomfichier[],player *hero1 ,player *hero2, Ennemi *Mob , EO *obj , background *b , int lineNumber , int verif_input , int nbsave) ;
int numberSave(char nomfichier[],int nbsave);


#endif // SAVE_H_

