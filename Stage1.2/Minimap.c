
#include "main.h"

void Mini_map(SDL_Surface* ecran,Map M)
{



M.Overview=shrinkSurface (ecran,7,7);
SDL_BlitSurface(M.Border , NULL,ecran,&M.Pos);
SDL_BlitSurface(M.Overview , NULL,ecran,NULL);
SDL_FreeSurface (M.Overview);
}
