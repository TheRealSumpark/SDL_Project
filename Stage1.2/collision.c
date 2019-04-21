#include  "main.h"
#include  "collision_bounding_box.h"
#include "Collision_trigo.h"
#include "Ennemi.h"
#include  "Afficher_Ennemi.h"
#include "Perfect_Collision.h"

/*void deplacement2(Direction Sens,Etat State,Player *hero )
{
switch(State )
{ 
case ATTACK: break;
	case IDLE : break;
	case WALK : switch (Sens) {

			case UP: hero->Pos_perso.y+=5 ;break;
			case DOWN:hero->Pos_perso.y-=5;	break;
			case RIGHT:hero->Pos_perso.x-=5 ;break;
			case LEFT:hero->Pos_perso.x+=5;	break;




}break;	}
}*/


int collisionall(EO *ob,EO clef,EO porte,EO piste,Player *hero,int *vie,int *score,Direction Sens,Etat State,Ennemi Mob[], Coordinate C,SDL_Surface *Background)
{
int enigme;
int collision;
if (State== WALK)
{
switch (Sens)
{

		case UP:
if((Collision_Ennemi(hero->Pos_perso,Mob[0])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[1])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[3])==1))
{hero->P_health-=1;
			 hero->Pos_perso.y=hero->Pos_perso.y+5;}
if ((collisionbox(hero->perso,ob[0].objett,hero->Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[1].objett,hero->Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[2].objett,hero->Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[3].objett,hero->Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[4].objett,hero->Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[5].objett,hero->Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero->perso,ob[6].objett,hero->Pos_perso,ob[6].positionobjett)==1)) 
			{
			 hero->Pos_perso.y+=5;
			}
if(collisionbox(hero->perso,clef.objett,hero->Pos_perso,clef.positionobjett)==1)
	{enigme=1;
hero->Pos_perso.y+=5;}
break ;
		case DOWN :
if((Collision_Ennemi(hero->Pos_perso,Mob[0])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[1])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[3])==1))
{hero->P_health-=1;
			 hero->Pos_perso.y=hero->Pos_perso.y-5;}
if ((collisionbox(hero->perso,ob[0].objett,hero->Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[1].objett,hero->Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[2].objett,hero->Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[3].objett,hero->Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[4].objett,hero->Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[5].objett,hero->Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero->perso,ob[6].objett,hero->Pos_perso,ob[6].positionobjett)==1)
|| (collisionbox(hero->perso,piste.objett,hero->Pos_perso,piste.positionobjett)==1))
			{
			 hero->Pos_perso.y-=5;
			}
if(collisionbox(hero->perso,clef.objett,hero->Pos_perso,clef.positionobjett)==1)
	{enigme=1;
hero->Pos_perso.y-=5;}
							collision=0;
							C.Y=hero->Pos_perso.y+hero->Pos_perso.h;
							C.X=hero->Pos_perso.x;							
							while (!collision && C.X<=(hero->Pos_perso.x+hero->Pos_perso.w))
							{
							collision= Collision_Parfaite(Background,C);
							C.X++;
							if (collision)
							{hero->Pos_perso.y--;
							C.X=hero->Pos_perso.x;
							C.Y=hero->Pos_perso.y+hero->Pos_perso.h;
							collision=0;}}
break ;
		case LEFT :
if((Collision_Ennemi(hero->Pos_perso,Mob[0])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[1])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[3])==1))
{hero->P_health-=1;
			 hero->Pos_perso.x=hero->Pos_perso.x+5;}
if ((collisionbox(hero->perso,ob[0].objett,hero->Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[1].objett,hero->Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[2].objett,hero->Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[3].objett,hero->Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[4].objett,hero->Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[5].objett,hero->Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero->perso,ob[6].objett,hero->Pos_perso,ob[6].positionobjett)==1)) 
			{
			 hero->Pos_perso.x+=5;
			}
if(collisionbox(hero->perso,clef.objett,hero->Pos_perso,clef.positionobjett)==1)
	{enigme=1;
hero->Pos_perso.x+=5;}
break ;
		case RIGHT:
if((Collision_Ennemi(hero->Pos_perso,Mob[0])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[1])==1) 
|| (Collision_Ennemi(hero->Pos_perso,Mob[3])==1))
{hero->P_health-=1;
			 hero->Pos_perso.x=hero->Pos_perso.x-5;}
if ((collisionbox(hero->perso,ob[0].objett,hero->Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[1].objett,hero->Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[2].objett,hero->Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[3].objett,hero->Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[4].objett,hero->Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero->perso,ob[5].objett,hero->Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero->perso,ob[6].objett,hero->Pos_perso,ob[6].positionobjett)==1)) 
			{
			 hero->Pos_perso.x-=5;
			}
if(collisionbox(hero->perso,clef.objett,hero->Pos_perso,clef.positionobjett)==1)
	{enigme=1;
hero->Pos_perso.x-=5;}

break ;
}
}
}
