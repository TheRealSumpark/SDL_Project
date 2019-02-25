#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "options.h"
void choix_options(SDL_Surface *ecran){
int continuer=1,i_audio=1,i_menu=1,verif_audio=3;
SDL_Event event;
SDL_Surface *choix_options=NULL;
FILE *fichier=NULL;
const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();


SDL_EnableKeyRepeat(100, 100);
while (continuer)
{
SDL_WaitEvent(&event);
switch(i_menu){
case 1 :
switch (i_audio){
case 1 : choix_options=SDL_LoadBMP("op1.bmp");break;
case 2 : choix_options=SDL_LoadBMP("op2.bmp");break;
case 3 : choix_options=SDL_LoadBMP("op3.bmp");break;
case 4 : choix_options=SDL_LoadBMP("op4.bmp");break;
}
break;
}

switch (event.type){
case SDL_QUIT : exit(1);break;
case SDL_KEYDOWN :

    switch (event.key.keysym.sym){

case SDLK_ESCAPE : continuer=0;break;
case SDLK_BACKSPACE :

fichier=fopen("options","w");
fprintf(fichier,"%d\n",verif_audio);
fclose(fichier);
break;

case SDLK_UP :
switch (i_menu){
case 1 :
i_audio--;
if (i_audio<1){
i_audio=4;
}
break;
}
break;
case SDLK_DOWN :

switch (i_menu){
case 2 :
i_audio++;
if (i_audio>4){
i_audio=1;
}
break;
}
break;
case SDLK_RETURN :
switch (i_menu){
case 1 :
switch (i_audio){
case 1 :
// Audio muet
verif_audio=1;
break;
case 2 :
// audio normal
verif_audio=2;
break;
case 3 :
// audio moyen
verif_audio=3;
break;
case 4 :
// audio max
verif_audio=4;
break;
}
break;
}
break;

}
break;
}
SDL_BlitSurface(choix_options,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_FreeSurface(choix_options);
SDL_Quit();
fclose(fichier);
}
}
