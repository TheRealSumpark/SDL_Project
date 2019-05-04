#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "mvtaleatoire.h"
/**
* @file mvtaleatoire.c	
*/

 void mvtaleatoire (  Ennemi *mob  , int min , int max )  
{ 

if (mob->Pos_Ennemi.x >= max)
	mob->direction = 0;
		
	if (mob->Pos_Ennemi.x <= min )
		mob->direction = 1;
		
	if (mob->direction == 1)
		mob->Pos_Ennemi.x += 10;
	if (mob->direction == 0)
		mob->Pos_Ennemi.x -= 5;


}
 



