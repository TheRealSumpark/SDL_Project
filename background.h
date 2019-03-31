#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
typedef struct 
{
 
SDL_Surface *image;
SDL_Rect positionecran;
Mix_Music *music;
	
}background;

 background initialiser ();
 void afficher (background b , SDL_Surface *screen) ;

#endif /* FONCTIONS_H_ */ 
