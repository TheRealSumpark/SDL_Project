#include  "Afficher_Ennemi.h"



void Afficher_Ennemi(Ennemi Mob,SDL_Surface *ecran)
{

SDL_BlitSurface (Mob.Anim_Ennemi,NULL,ecran,&Mob.Pos_Ennemi);
}
