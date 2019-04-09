#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "mvtaleatoire.h"




float mvt_aleatoire (SDL_Rect posinitialMonstre , SDL_Rect max , SDL_Rect min  )
{
    SDL_Event event;
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    Direction sens ;
SDL_Rect posactuelMonstre ;
 SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 20) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {switch (sens ) 
 {case LEFT :
            posinitialMonstre.x-=5;

                break ;  
case RIGHT :
 posinitialMonstre.x+=5 ;
break ;}
if ( posinitialMonstre.x >= max.x )
                    sens = LEFT ;

else if ( posinitialMonstre.x<=min.x )

sens =RIGHT ;
                    
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }}

 posactuelMonstre.x= posinitialMonstre.x ;
return  posactuelMonstre.x ;
}
/*********************************************************************/

SDL_Surface animatin_monstre ( SDL_Rect posactuelMonstre , SDL_Rect posinitialMonstre , SDL_Surface  *monstrebleu  ,  SDL_Surface *monstrejaune)
{ SDL_Surface *couleurmonstre=NULL ;
 monstrebleu =NULL ;
monstrejaune=NULL ;

 monstrebleu = IMG_Load("monstrebleu.png");
 monstrejaune= IMG_Load("monstrejaune.png");

if (posactuelMonstre.x > posinitialMonstre.x)

couleurmonstre = monstrejaune ; /*le monstre change de couleur selon son mouvement aleatoire de gauche a droite */
else couleurmonstre=monstrebleu ;
       return *couleurmonstre ;
}
