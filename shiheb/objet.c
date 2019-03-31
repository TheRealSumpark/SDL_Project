#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "objet.h"
objet initialiser ()
{objet o ;
o.beb=NULL ;
o.mefteh=NULL;
SDL_Surface *screen=NULL ;
SDL_Event event;

/*afficher image*/

o.beb = /*SDL_LoadBMP*/IMG_Load("beb.png");
if(o.beb==NULL)
{printf("Unable to load image %s \n",SDL_GetError());

}
o.mefteh = /*SDL_LoadBMP*/IMG_Load("mefteh.png");
if(o.mefteh==NULL)
{printf("Unable to load image %s \n",SDL_GetError());

}
o.positionbeb.x=1800;
o.positionbeb.y=351;

o.positionmefteh.x=1775;
o.positionmefteh.y=351;
 return o;}
void afficher (objet o, SDL_Surface *background) 
{
SDL_BlitSurface(o.beb,&o.positionbeb,background,NULL);
SDL_BlitSurface(o.mefteh,&o.positionmefteh,background,NULL);
SDL_Flip(background);
}
