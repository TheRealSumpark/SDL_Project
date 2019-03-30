#ifndef struct_H_INCLUDED
#define struct_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct objet
{
	SDL_Surface *objett;
    	SDL_Rect positionobjett;
}objet;

typedef struct enemy
{
	SDL_Surface *enemyy;
    	SDL_Rect positionenemyy;
}enemy;

typedef struct Animation
{

SDL_Surface *Attack[5];
SDL_Surface *Jump[5];
SDL_Surface* Mouvement[4];

}Animation;

typedef struct Player
{	
	SDL_Surface *surf;
    	SDL_Rect positiontext;
	Animation Player_Animation;
	SDL_Surface *Player_Health[3];
	int NUM;
        int anim;
	int P_health;
}Player;

#endif
