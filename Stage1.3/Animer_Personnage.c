#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "jouer.h"
/**
* @file Animer_Personnage.c	
*/
void Animer_Personnage(int *frametime ,int nmb_frame,int *frame,Player *hero,Direction *Sens ,Etat *State)
{
int FPS=60;

				
				
switch (*State)
{		case IDLE: 				*frametime=0;*frame=0;
							switch (*Sens)
							{	case LEFT:hero->perso=hero->perso_idle[1];break;
								case RIGHT:hero->perso=hero->perso_idle[0];break;	
								}break;
								
		case ATTACK:					(*frametime)++;
							switch (*Sens) {
							case LEFT:	hero->perso=hero->perso_attack_left[*frame];
									if (FPS/(*frametime)==8)
									{(*frametime)=0;
									(*frame)++;
									if (*frame==nmb_frame)
									{*frame=0;*State=IDLE;}}
							break;
							case RIGHT:	hero->perso=hero->perso_attack_right[*frame];
									if (FPS/(*frametime)==8)
									{(*frametime)=0;
									(*frame)++;
									if (*frame==nmb_frame)
									{*frame=0;*State=IDLE;}}
						
									
							break;
							
							}break;

		case WALK :  					 switch (*Sens)
{


case DOWN:						break;
							
case UP:						break;
							
case LEFT:						(*frametime)++;
							hero->perso=hero->perso_mv_left[*frame];					
							hero->perso=hero->perso_mv_left[*frame];
									if (FPS/(*frametime)==8)
									{(*frametime)=0;
									(*frame)++;
									if (*frame==nmb_frame)
									{*frame=0;*State=IDLE;}};break;

				
							
case RIGHT:						
							(*frametime)++;
							hero->perso=hero->perso_mv_right[*frame];
							hero->perso=hero->perso_mv_right[*frame];
									if (FPS/(*frametime)==8)
									{(*frametime)=0;
									(*frame)++;
									if (*frame==nmb_frame)
									{*frame=0;*State=IDLE;}}
							
							break;
							
} break;


}
}
