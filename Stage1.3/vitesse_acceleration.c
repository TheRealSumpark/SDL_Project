#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h> 
#include  "perso.h"
#include  "vitesse_acceleration.h"
#define TEMPS 60 
#define ACCELERATION 5
/**
* @file vitesse_acceleration.c	
*/

void Vitesse(Direction Sens,Etat State,Player *hero)
{
 int keysHeld[323] = {0};
 int tempsPrecedent = 0, tempsActuel = 0;
 int vitesse = 0;
 tempsActuel = SDL_GetTicks();

 if (tempsActuel - tempsPrecedent > TEMPS)
 { 
 if (State== WALK)
{
switch (Sens)
{
case UP:
if (vitesse > ACCELERATION) { vitesse - ACCELERATION; }
                else {vitesse = 0; }
break ;
case DOWN :
if (vitesse > ACCELERATION) { vitesse - ACCELERATION; }
                else {vitesse = 0; }
  
break ;
case LEFT :
  
   vitesse += ACCELERATION;
if(keysHeld[SDLK_LSHIFT]) {


   hero->Pos_perso.x-=vitesse;
}
	
break;
 
case RIGHT:
 
    vitesse += ACCELERATION;
if(keysHeld[SDLK_LSHIFT]) {
    hero->Pos_perso.x+=vitesse;
}

  break;

}      tempsPrecedent = tempsActuel; 
}
}
}
