#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "jouer.h"
/**
* @file afficher_background.c	
*/
void afficher (SDL_Surface *ecran , background *b ) 
{
SDL_BlitSurface(b->image,NULL,ecran,&b->positionecran);
} 
