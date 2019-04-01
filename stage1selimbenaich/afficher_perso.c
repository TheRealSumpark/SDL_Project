#include  "afficher_perso.h"

void Afficher_perso(Player hero,SDL_Surface *ecran)
{

SDL_BlitSurface (hero.surf,NULL,ecran,&hero.positiontext);
}
