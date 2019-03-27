#include "Perfect_Collision.h"




int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{int collision=0;
SDL_Color color;

color=GetPixel(Background,C);

if (color.r==0 && color.g==0 && color.b==0)
{collision=1;}

return collision;

}





SDL_Color GetPixel(SDL_Surface *background ,Coordinate C)
{


SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) background->pixels;
pPosition+= (background->pitch * C.Y);
pPosition+= (background->format->BytesPerPixel *C.X);
memcpy(&col ,pPosition ,background->format->BytesPerPixel);


SDL_GetRGB(col,background->format, &color.r, &color.g, &color.b);
return (color);




}
