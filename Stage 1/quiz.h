#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include  "main.h"
int enigme();
void reponse(SDL_Surface *ecran,int d);
void solution(SDL_Surface *ecran,int d);
void quiz(SDL_Surface *ecran,int d);
void good(SDL_Surface *ecran);
#endif 
