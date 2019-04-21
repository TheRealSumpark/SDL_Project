#include  "main.h"

void afficher (SDL_Surface *ecran , background *b ) 
{
SDL_BlitSurface(b->image,&b->camera,ecran,&b->positionecran);
} 
