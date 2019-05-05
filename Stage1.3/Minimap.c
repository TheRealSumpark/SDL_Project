
#include "jouer.h"

void Mini_map(SDL_Surface* ecran,Map M)
{



M.Overview=shrinkSurface (ecran,6,7);
M.Pos.x=410;
M.Pos.y=0;
SDL_Rect Pos_Border;
Pos_Border.x=400;
Pos_Border.y=-70;

SDL_BlitSurface(M.Border,NULL,ecran,&Pos_Border);
SDL_BlitSurface(M.Overview,NULL,ecran,&M.Pos);
SDL_FreeSurface (M.Overview);
}
