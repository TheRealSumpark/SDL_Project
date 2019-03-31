#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
typedef enum {RIGHT ,LEFT,}Direction;
float mvt_aleatoire (SDL_Rect posinitialMonstre , SDL_Rect max , SDL_Rect min  ) ;
SDL_Surface animatin_monstre ( SDL_Rect posactuelMonstre , SDL_Rect posinitialMonstre ,SDL_Surface  *monstrebleu  ,  SDL_Surface *monstrejaune );
#endif /* FONCTIONS_H_ */ 
