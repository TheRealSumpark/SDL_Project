#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "perso.h"
#include  "manette.h"
#define STAT_SOL 0
#define STAT_AIR 1
/**
* @file perso.c	
*/

Player Initial_personnage()
{
Player hero1;
hero1.nmb_mv=5;
hero1.nmb_attack=5;
hero1.P_health=3;
hero1.vitesse = 0;
hero1.ACCELERATION =0;
hero1.perso_idle[0]=IMG_Load("idle/0.png");
hero1.perso_idle[1]=IMG_Load("idle/1.png");
hero1.perso=hero1.perso_idle[0];

hero1.perso_mv_right[0]=IMG_Load("mv_right/0.png");
hero1.perso_mv_right[1]=IMG_Load("mv_right/1.png");
hero1.perso_mv_right[2]=IMG_Load("mv_right/2.png");
hero1.perso_mv_right[3]=IMG_Load("mv_right/3.png");
hero1.perso_mv_right[4]=IMG_Load("mv_right/4.png");


hero1.Pos_perso.x=145;
hero1.Pos_perso.y=575;
hero1.Pos_perso.h=hero1.perso->h;
hero1.Pos_perso.w=hero1.perso->w;

hero1.status = STAT_SOL;
hero1.vx = hero1.vy = 0.0f;

hero1.perso_attack_right[0]=IMG_Load("attack_right/0.png");
hero1.perso_attack_right[1]=IMG_Load("attack_right/1.png");
hero1.perso_attack_right[2]=IMG_Load("attack_right/2.png");
hero1.perso_attack_right[3]=IMG_Load("attack_right/3.png");
hero1.perso_attack_right[4]=IMG_Load("attack_right/4.png");


hero1.perso_attack_left[0]=IMG_Load("attack_left/0.png");
hero1.perso_attack_left[1]=IMG_Load("attack_left/1.png");
hero1.perso_attack_left[2]=IMG_Load("attack_left/2.png");
hero1.perso_attack_left[3]=IMG_Load("attack_left/3.png");
hero1.perso_attack_left[4]=IMG_Load("attack_left/4.png");



hero1.perso_mv_left[0]=IMG_Load("mv_left/0.png");
hero1.perso_mv_left[1]=IMG_Load("mv_left/1.png");
hero1.perso_mv_left[2]=IMG_Load("mv_left/2.png");
hero1.perso_mv_left[3]=IMG_Load("mv_left/3.png");
hero1.perso_mv_left[4]=IMG_Load("mv_left/4.png");

hero1.Player_Health[0]=IMG_Load("love1-1.png");
hero1.Player_Health[1]=IMG_Load("love2.png");
hero1.Player_Health[2]=IMG_Load("love3.png");

hero1.positionHealth.x=0;
hero1.positionHealth.y=0;

//ajouter jump et 
return hero1;
}

void Afficher_perso(Player hero,int vie,SDL_Surface *ecran)
{

SDL_BlitSurface (hero.perso,NULL,ecran,&hero.Pos_perso);
if (vie==3){
SDL_BlitSurface(hero.Player_Health[2], NULL, ecran, &hero.positionHealth);}
if (vie==2){
SDL_BlitSurface(hero.Player_Health[1], NULL, ecran, &hero.positionHealth);}
if (vie==1){
SDL_BlitSurface(hero.Player_Health[0], NULL, ecran, &hero.positionHealth);}
//affichage des coeurs et du score 
}

void event_handler(SDL_Event event,Direction *Sens ,Etat *State,int *keysHeld)
{

switch(event.type)
        {
 case SDL_MOUSEBUTTONDOWN :
	
	if (event.button.button==SDL_BUTTON_RIGHT)
	{
		if (*State==IDLE)
							{*Sens=RIGHT;*State=WALK;}}
	if (event.button.button==SDL_BUTTON_LEFT)
	{
		if (*State==IDLE)
							{*Sens=LEFT;*State=WALK;}}
break;


case SDL_MOUSEBUTTONUP :

	if (event.button.button==SDL_BUTTON_RIGHT)
	{
		*State=IDLE;}
	if (event.button.button==SDL_BUTTON_LEFT)
	{
		*State=IDLE;}
break;	

case SDL_KEYDOWN : 
keysHeld[event.key.keysym.sym] = 1;
			switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	if (*State==IDLE)
							{*Sens=DOWN;*State=WALK;}
							
				break;
		
				case SDLK_LEFT:		if (*State==IDLE)
							{*Sens=LEFT;*State=WALK;
							}
							
				break;
				case SDLK_RIGHT:	if (*State==IDLE)
							{*Sens=RIGHT;*State=WALK;
							}
							
				break;
							
				break;
				case SDLK_SPACE:      	if (*State==IDLE)
							{*State=ATTACK;}break;
				
			
}break;
	case SDL_KEYUP:	
keysHeld[event.key.keysym.sym] = 0;
				switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	*State=IDLE;*Sens=RIGHT;
							
				break;
				case SDLK_LEFT:		*State=IDLE;		
				break;
				case SDLK_RIGHT:	*State=IDLE;	
				break;
			
				
			
			}break;
}
}
void Saute(Player *hero,float impulsion)
{
    hero->vy = -impulsion;
    hero->status = STAT_AIR;
}

void ControleSol(Player *hero)
{
    if (hero->Pos_perso.y>575.0f)
    {
        hero->Pos_perso.y = 575.0f;
        if (hero->vy>0.0f)
            hero->vy = 0.0f;
        hero->status = STAT_SOL;
    }
}

void Gravite(Player *hero,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (hero->status == STAT_AIR && keys[SDLK_UP])
        factgravite/=factsautmaintenu;
    hero->vy += factgravite;
}

void deplacement(Direction Sens,Etat State,Player *hero,int *keysHeld,int *frametime1 ,int nmb1_frame,int *frame1,Uint8* keys)
{
float lateralspeed = 0.5f;
float airlateralspeedfacteur = 0.5f;
float maxhspeed = 3.0f;
float adherance = 1.5f;
float impulsion = 6.0f;
float factgravite = 0.5f;
float factsautmaintenu = 3.0f;
int FPS=60;
int direction=0;
int x=0;
int fa=0;
//system("stty -F /dev/ttyACM0 9600 -parenb cs8 -cstopb");
//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
int TEMPS =60;
int tempsPrecedent = 0, tempsActuel = 0;
hero->vitesse = 0;
hero->ACCELERATION =5;
tempsActuel = SDL_GetTicks();
SDL_Event event;
if (tempsActuel - tempsPrecedent > TEMPS)
 { 
switch(State )
{ 
case ATTACK: break;
	case IDLE : break;
	case WALK : switch (Sens) {
			case DOWN:
hero->Pos_perso.y+=5;	
if (hero->vitesse > hero->ACCELERATION) { hero->vitesse - hero->ACCELERATION; }
                else {hero->vitesse = 0; }
break;
			case RIGHT:
direction=1;
hero->Pos_perso.x+=5 ;
hero->vitesse+=hero->ACCELERATION;
hero->vx+=lateralspeed;
break;
			case LEFT:
direction=2;
hero->Pos_perso.x-=5;
hero->vitesse+=hero->ACCELERATION;
hero->vx-=lateralspeed;	
break;

break;	
}
}
tempsPrecedent = tempsActuel; 
}
if (hero->status == STAT_AIR) 
        lateralspeed*= airlateralspeedfacteur;
if (hero->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) 
        hero->vx/=adherance;
if (hero->vx>maxhspeed) 
        hero->vx = maxhspeed;
if (hero->vx<-maxhspeed)
        hero->vx = -maxhspeed;
if (keys[SDLK_UP] && hero->status == STAT_SOL)
        Saute(hero,impulsion);
    Gravite(hero,factgravite,factsautmaintenu,keys);
    ControleSol(hero);
    hero->Pos_perso.x +=hero->vx;
   hero->Pos_perso.y +=hero->vy;
switch(direction)
{
case 1:
if(RIGHT && keysHeld[SDLK_LSHIFT]) {
hero->Pos_perso.x+=hero->vitesse;
}
break;
case 2:
if(LEFT && keysHeld[SDLK_LSHIFT]) {
 hero->Pos_perso.x-=hero->vitesse;
}
break;
}

//arduinoReadData(&x);
	switch(x)

{
            	case 0: direction=0; 
             	break;

             	case 3: direction=3; 
             	break; 
	     
	     	case 4: direction=4;
	     	break;
	
	     	case 5:direction=5;*frametime1=0;*frame1=0;fa=1;
	     	break;

            	case 6: direction=6; 
            	break;
}

if(direction == 3 )
{
hero->Pos_perso.x+=5 ;
}
if(direction == 4 )
{
hero->Pos_perso.x-=5;
}
if(direction == 5 )
{
(*frametime1)++;
if(fa==1)
{
hero->perso=hero->perso_attack_right[*frame1];
if (FPS/(*frametime1)==8)
{(*frametime1)=0;
(*frame1)++;
if (*frame1==nmb1_frame)
{*frame1=0;}}
}}
if(direction == 6 )
{
hero->Pos_perso.y-=5;
}
}

