#ifndef collision_H_INCLUDED
#define collision_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

int collision(SDL_Surface *p,SDL_Surface *e,SDL_Rect perso,SDL_Rect enemy);
int collisionbox(SDL_Surface *p,SDL_Surface *o,SDL_Rect perso,SDL_Rect objet);
#endif 
