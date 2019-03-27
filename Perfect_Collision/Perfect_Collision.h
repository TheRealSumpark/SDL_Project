#ifndef PERFECT_COLLISION_H_DEFINED
#define PERFECT_COLLISION_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{

int X;
int Y;

}Coordinate;


int Collision_Parfaite();
SDL_Color GetPixel(SDL_Surface *background ,Coordinate C);



#endif
