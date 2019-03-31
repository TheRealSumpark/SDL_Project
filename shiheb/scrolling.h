#ifndef FONCTIONSH
#define FONCTIONSH
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

SDL_Rect camera;
void set_camera(SDL_Rect j,SDL_Surface *img);
void collision(SDL_Surface *obstacle, SDL_Rect *position_perso, SDL_Surface *perso);
 void fazzaa(SDL_Rect position_perso,SDL_Surface *perso, SDL_Surface *screen);

#endif /* FONCTIONSH */
