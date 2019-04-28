#include "main.h"




void Rotozoom(SDL_Surface * ecran, background b,EO clef, double angle)
{SDL_Surface * rotation=NULL;
if (angle==360)
{SDL_FreeSurface(rotation);}
else 
{
angle+=10;
rotation = rotozoomSurface(clef.objett ,angle, 1, 1);
afficher(ecran,&b);
SDL_BlitSurface(rotation , NULL,ecran,&clef.positionobjett);
SDL_Flip(ecran);
SDL_Delay(100);
Rotozoom(ecran,b,clef,angle);}

}
 




