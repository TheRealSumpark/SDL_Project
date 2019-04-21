#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "quiz.h"
#include <string.h>
void enigme(int d,SDL_Surface *ecran)
{

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

    
}
void solution(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image1 = NULL;
    SDL_Rect positionFond1;
    positionFond1.x =  0 ;
    positionFond1.y =  0 ;
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    image1= IMG_Load("no.png");
    SDL_BlitSurface(image1,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(3000);

}

void good(SDL_Surface *ecran)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"goood.png");
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void quiz(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"quiz/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);

}


void reponse(SDL_Surface *ecran,int d)
{
    SDL_Event event;
    char im[100], im1[100], im2[100], im3[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x = 0 ;
    positionim.y = 0;
    sprintf(im1,"reponse/%d/1.png",d);
    sprintf(im2,"reponse/%d/2.png",d);
    sprintf(im3,"reponse/%d/3.png",d);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    int continuer =1;
    int i=0;
  
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==3 && d==1)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==3 && d==2)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==1 && d==3)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,d);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                break;
            }
        }

        SDL_Flip(ecran);
    }



