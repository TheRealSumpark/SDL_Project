#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "Ennemi.h"
#include  "jouer.h"

int Collision_Ennemi(SDL_Rect Pos_perso,Ennemi Mob);


#endif
