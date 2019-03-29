#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct Animation
{

SDL_Surface *Attack[5];
SDL_Surface *Jump[5];
SDL_Surface* Mouvement[5];

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

Player Initial_personnage();
#endif 
