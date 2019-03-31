#ifndef FONCTIONSH
#define FONCTIONSH
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
typedef struct 
{
 
SDL_Surface *beb; SDL_Surface *mefteh ;
SDL_Rect positionbeb , positionmefteh;

}objet;

objet initialiser ();
void afficher (objet o, SDL_Surface *background) ;

#endif /* FONCTIONSH */
