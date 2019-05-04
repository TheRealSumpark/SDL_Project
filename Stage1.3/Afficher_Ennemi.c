#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "Afficher_Ennemi.h"
/**
* @file afficher_Ennemi.c	
*/


void Afficher_Ennemi(Ennemi Mob,SDL_Surface *ecran)
{

SDL_BlitSurface (Mob.Anim_Ennemi,NULL,ecran,&Mob.Pos_Ennemi);
}
