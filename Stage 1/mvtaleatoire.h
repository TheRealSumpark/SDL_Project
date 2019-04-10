#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include  "main.h"
#include "Ennemi.h"
#include  "Afficher_Ennemi.h"
typedef enum {RIGHT ,LEFT,}Direction;

Direction mvt_aleatoire (Ennemi Mob , SDL_Rect max , SDL_Rect min  );
SDL_Surface  *Animer_enemy(int *frametime1 ,int nmb_frame,int frame , Direction1 sens  ) ;
#endif /* FONCTIONS_H_ */ 
