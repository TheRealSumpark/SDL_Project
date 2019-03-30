#ifndef collision_H_INCLUDED
#define collision_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct_perso_enemy_objet.h"

int collision(Player hero,enemy e);
int collisionbox(Player hero,objet ob);
#endif 
