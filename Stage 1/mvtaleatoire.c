#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
//#include "mvtaleatoire.h"
#include  "main.h"
Direction mvt_aleatoire (Ennemi Mob , SDL_Rect max , SDL_Rect min  )
{
    
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    Direction sens ;

 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 20) /* Si 20 ms se sont écoulées depuis le dernier tour de boucle */
        {switch (sens ) 
 {case LEFT :
            Mob.Pos_Ennemi.x-=5;

                break ;  
case RIGHT :
 Mob.Pos_Ennemi.x+=5 ;
break ;}
if ( Mob.Pos_Ennemi.x >= max.x )
                    sens = LEFT ;

else if ( Mob.Pos_Ennemi.x <=min.x )
{
sens =RIGHT ;
                    
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }}


return  sens ;
}

SDL_Surface  *Animer_enemy(Ennemi Mob,int *frametime1 ,int nmb_frame,int frame , Direction sens  )
{ 
SDL_Surface *animation ;
int FPS=60;

							
switch ( sens ) 
{
case RIGHT :

							if (FPS/(*frametime1)==6)
							{(*frametime1)=0;
							frame++;
							if (frame==nmb_frame)
							{frame=0;}}
animation=Mob.Anim_Ennemi ;
							
break ;
case LEFT :

							if (FPS/(*frametime1)==7)
							{(*frametime1)=0;
							frame++;
							if (frame==nmb_frame)
							{frame=0;}}
							
animation=Mob.Anim_Ennemi ;
break ;}
return animation ;

}









