#include  "main.h"

void afficherobjet(EO *ob,EO *clef,EO *porte,EO *piste,SDL_Surface *ecran,background *b)
{
int i;
for (i=0;i<7;i++)
{SDL_BlitSurface(ob[i].objett,NULL,ecran,&ob[i].positionobjett);}	
SDL_BlitSurface(clef->objett,NULL,ecran,&clef->positionobjett);
SDL_BlitSurface(porte->objett,NULL,ecran,&porte->positionobjett);
SDL_BlitSurface(piste->objett,NULL,ecran,&piste->positionobjett);
}
