#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include  "main.h"
void scrolling (background *b,SDL_Surface *ecran,Direction Sens,Etat State)
{
if (State== WALK)
{
switch (Sens)
{case UP:

break ;
case DOWN :
break ;
case LEFT :
if(b->camera.x>0){
b->camera.x-=20;
}

break ;
case RIGHT:
if (b->camera.x<1886-b->camera.w){
b->camera.x+=20;
}
break ;}
}
}
