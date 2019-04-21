#include  "perso.h"

Player Initial_personnage()
{
Player hero1;
hero1.nmb_mv=5;
hero1.nmb_attack=5;
hero1.P_health=3;
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

void event_handler(SDL_Event event,Direction *Sens ,Etat *State)
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
			switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	if (*State==IDLE)
							{*Sens=DOWN;*State=WALK;}
							
				break;
				case SDLK_UP:		if (*State==IDLE)	
							{*Sens=UP;*State=WALK;}
							
				break;
				case SDLK_LEFT:		if (*State==IDLE)
							{*Sens=LEFT;*State=WALK;}
							
				break;
				case SDLK_RIGHT:	if (*State==IDLE)
							{*Sens=RIGHT;*State=WALK;}
							
				break;
				case SDLK_SPACE:      	if (*State==IDLE)
							{*State=ATTACK;}break;
				
			
}break;
	case SDL_KEYUP:	
				switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	*State=IDLE;*Sens=RIGHT;
							
				break;
				case SDLK_UP:		*State=IDLE;*Sens=RIGHT;
							
				break;
				case SDLK_LEFT:		*State=IDLE;
							
				break;
				case SDLK_RIGHT:	*State=IDLE;
							
				break;
			
				
			
			}break;
}
}

void deplacement(Direction Sens,Etat State,Player *hero )
{
switch(State )
{ 
case ATTACK: break;
	case IDLE : break;
	case WALK : switch (Sens) {

			case UP: hero->Pos_perso.y-=5 ;break;
			case DOWN:hero->Pos_perso.y+=5;	break;
			case RIGHT:hero->Pos_perso.x+=5 ;break;
			case LEFT:hero->Pos_perso.x-=5;	break;




}break;	}
}

