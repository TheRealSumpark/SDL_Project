#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collision_bounding_box.h"
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


Player Initial_personnage();
int Animer_Personnage(int *frametime ,int nmb_frame,int frame);
void Afficher_perso(Player hero,int vie,SDL_Surface *ecran);
void main(SDL_Surface *ecran);
#endif
