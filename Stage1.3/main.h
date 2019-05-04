#ifndef MENU_PRINCIPALE_H_INCLUDED
#define MENU_PRINCIPALE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "options.h"
#include "jouer.h"
//#include "Init_Ennemi1.h"

typedef struct 
{	SDL_Surface * Anim_Ennemi[48];

}Ennemii;


typedef struct 
{SDL_Surface * Anim[22];	
}anim;

Ennemii Init_Ennemi1();
void Nettoyer(SDL_Surface *background);
void main(SDL_Surface *screen);
anim Init_Anim();
void jouer(SDL_Surface *ecran);
#endif // MENU_H_INCLUDED
