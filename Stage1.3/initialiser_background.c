#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "jouer.h"
/**
* @file initialiser_background.c	
*/

void initialiser (background *b)
{

b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=635;

b->image = IMG_Load("stage 1.png");
b->positionecran.x=0;
b->positionecran.y=0;
b->positionecran.w=b->image->w;
b->positionecran.h=b->image->h;


if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}
b->music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(b->music,-1);

 }












