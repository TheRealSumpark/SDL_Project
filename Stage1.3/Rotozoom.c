#include "jouer.h"




void Rotozoom(SDL_Surface * ecran, background b,EO clef, double *angle)
{SDL_Surface * rotation=NULL;



{
(*angle)+=10;
rotation = rotozoomSurface(clef.objett ,(*angle), 1, 1);
SDL_BlitSurface(rotation , NULL,ecran,&clef.positionobjett);
SDL_FreeSurface(rotation);
}

}
 




