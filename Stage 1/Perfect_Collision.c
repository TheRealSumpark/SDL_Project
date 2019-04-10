#include "Perfect_Collision.h"

int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{int collision=0;
SDL_Color color ;


SDL_GetRGB(getpixel(Background,C),Background->format,&color.r,&color.g,&color.b);

if (color.r==0 && color.g==0 && color.b==0)
{collision=1;}

return collision;

}

Uint32 getpixel(SDL_Surface *surface,Coordinate C)
{
    int bpp = surface->format->BytesPerPixel;
   
    Uint8 *p = (Uint8 *)surface->pixels + C.Y * surface->pitch + C.X * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;      
    }
}
