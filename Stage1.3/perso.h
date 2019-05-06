#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include <SDL/SDL_ttf.h>
#include  "main.h"
Player Initial_personnage();
void event_handler(SDL_Event event,Direction *Sens ,Etat *State,int *keysHeld);
void Saute(Player *hero,float impulsion);
void ControleSol(Player *hero);
void Gravite(Player *hero,float factgravite,float factsautmaintenu,Uint8* keys);
void Afficher_perso(Player hero,int vie,SDL_Surface *ecran);

#endif
