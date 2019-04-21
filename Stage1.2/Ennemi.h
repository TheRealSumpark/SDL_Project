#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct 
{	SDL_Surface * Anim_Ennemi;
	SDL_Rect Pos_Ennemi;
int direction ;
}Ennemi;

#endif
