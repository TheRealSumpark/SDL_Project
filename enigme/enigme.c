#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "quiz.h"
#include <SDL/SDL_ttf.h>
#include <time.h>
int enigme(int argc,char *argv[])
{


    int d;

    srand(time(NULL));
    d=rand()%3+1;

    TTF_Init();
    if(TTF_Init()==-1)
    {
        fprintf(stderr,"ERREUR INIT: %s \n",TTF_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Color couleurnoir= {0,0,0};
    SDL_Surface *texte = NULL, *backg=NULL ; //declaration des variables globale
    SDL_Rect positiontexte,positiond;
    positiontexte.x=380;
    positiontexte.y=280;
    TTF_Font *police;//(pointeur contient parametre de la police)
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    SDL_Surface *ecran =NULL;
    police=TTF_OpenFont("font.ttf",200);
    ecran=SDL_SetVideoMode(800,600, 32,SDL_ANYFORMAT); // Ouverture de la fenêtre
    backg = IMG_Load("quiz.png");
    positiond.x=0 ;
    positiond.y=0 ;
    SDL_BlitSurface(backg,NULL, ecran, &positiond);
    SDL_Flip(ecran);
    texte=TTF_RenderText_Blended(police,"ENIGMA",couleurnoir);
    SDL_BlitSurface(texte,NULL,ecran,&positiontexte);
    SDL_Flip(ecran);
    SDL_Delay(2000);

    SDL_BlitSurface(backg,NULL, ecran, &positiond);
    SDL_Flip(ecran);
    quiz(ecran,d);
    reponse(ecran,d);
    SDL_FreeSurface(backg);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit(); // Arrêt de la SL

    return EXIT_SUCCESS; // Fermeture du programme
}
