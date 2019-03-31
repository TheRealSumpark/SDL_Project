
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "background.h"
background initialiser ()
{background b ;
b.image=NULL ;
SDL_Surface *screen=NULL ;
SDL_Event event;

/*afficher image*/

b.image = /*SDL_LoadBMP*/IMG_Load("background.png");
if(b.image==NULL)
{printf("Unable to load image %s \n",SDL_GetError());

}
b.positionecran.x=0;
b.positionecran.y=0;
b.positionecran.w=b.image->w;
b.positionecran.h=b.image->h;

/*music*/
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}
b.music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(b.music,-1);

 return b;}
void afficher (background b , SDL_Surface *screen) 
{
SDL_BlitSurface(b.image,&b.positionecran,screen,NULL);
SDL_Flip(screen);
}
/*********************************************************************************************************************************/

/***********************************************************************************************************/

















