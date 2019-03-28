#include "main.h"

typedef enum
{
UP,
DOWN,
RIGHT,
LEFT,
}Direction;

typedef enum 
{ATTACK,IDLE,WALK}Etat;




void main ()
{
int done=1,i=0,len,X,Y,collision=0,frame=0,frametime=0;
   Coordinate C;
   Direction Sens=RIGHT;
   Etat State=IDLE;
   


SDL_Surface *ecran=NULL,*perso=NULL,*Background=NULL, *perso_mv_right[5],*perso_idle[2],*perso_attack_right[5],*perso_mv_left[5],*perso_attack_left[5];
							int nmb_mv=5,nmb_attack=5;

Background=IMG_Load("test.jpg");

perso_idle[0]=IMG_Load("idle/0.png");
perso_idle[1]=IMG_Load("idle/1.png");
perso=perso_idle[0];


perso_mv_right[0]=IMG_Load("mv_right/0.png");
perso_mv_right[1]=IMG_Load("mv_right/1.png");
perso_mv_right[2]=IMG_Load("mv_right/2.png");
perso_mv_right[3]=IMG_Load("mv_right/3.png");
perso_mv_right[4]=IMG_Load("mv_right/4.png");

SDL_Rect Pos_perso;
Pos_perso.x=600;
Pos_perso.y=100;
Pos_perso.h=perso->h;
Pos_perso.w=perso->w;

perso_attack_right[0]=IMG_Load("attack_right/0.png");
perso_attack_right[1]=IMG_Load("attack_right/1.png");
perso_attack_right[2]=IMG_Load("attack_right/2.png");
perso_attack_right[3]=IMG_Load("attack_right/3.png");
perso_attack_right[4]=IMG_Load("attack_right/4.png");


perso_attack_left[0]=IMG_Load("attack_left/0.png");
perso_attack_left[1]=IMG_Load("attack_left/1.png");
perso_attack_left[2]=IMG_Load("attack_left/2.png");
perso_attack_left[3]=IMG_Load("attack_left/3.png");
perso_attack_left[4]=IMG_Load("attack_left/4.png");



perso_mv_left[0]=IMG_Load("mv_left/0.png");
perso_mv_left[1]=IMG_Load("mv_left/1.png");
perso_mv_left[2]=IMG_Load("mv_left/2.png");
perso_mv_left[3]=IMG_Load("mv_left/3.png");
perso_mv_left[4]=IMG_Load("mv_left/4.png");

SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(900,800, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("MENU", NULL);

SDL_Event event;


SDL_EnableKeyRepeat(100,100);
while (done)
{	
	SDL_PollEvent(&event);
	switch (event.type)
{
	case SDL_QUIT : done=0;break;
	case SDL_KEYDOWN : 
			switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	if (State==IDLE)
							{Sens=DOWN;State=WALK;}
							
				break;
				case SDLK_UP:		if (State==IDLE)	
							{Sens=UP;State=WALK;}
							
				break;
				case SDLK_LEFT:		if (State==IDLE)
							{Sens=LEFT;State=WALK;}
							
				break;
				case SDLK_RIGHT:	if (State==IDLE)
							{Sens=RIGHT;State=WALK;}
							
				break;
				case SDLK_SPACE:      	if (State==IDLE)
							State=ATTACK;break;
				
			}break;
	case SDL_KEYUP:	switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	State=IDLE;Sens=RIGHT;
							
				break;
				case SDLK_UP:		State=IDLE;Sens=RIGHT;
							
				break;
				case SDLK_LEFT:		State=IDLE;
							
				break;
				case SDLK_RIGHT:	State=IDLE;
							
				break;
			
				
			
			}break;
			




}
 
 


switch (State)
	{	case IDLE: 				frametime=0;frame=0;
							switch (Sens)
							{	case LEFT:perso=perso_idle[1];break;
								case RIGHT:perso=perso_idle[0];break;	
								}break;
								
		case ATTACK:					frametime++;
							switch (Sens) {
							case LEFT:	perso=perso_attack_left[frame];
									frame=Animer_Personnage(&frametime,nmb_attack,frame);
									if (frame==0)
									{State=IDLE;}
							break;
							case RIGHT:	perso=perso_attack_right[frame];
									frame=Animer_Personnage(&frametime,nmb_attack,frame);
									if (frame==0)
									{State=IDLE;}
							break;
							
							}break;
							
		case WALK :  					 switch (Sens)
{


case DOWN:						Pos_perso.y+=2;
							C.Y=Pos_perso.y+Pos_perso.h;
							C.X=Pos_perso.x;
							while (!collision && C.X<=(Pos_perso.x+Pos_perso.w))
							{
							collision= Collision_Parfaite(Background,C);C.X++;
							if (collision)
							{Pos_perso.y--;
							C.X=Pos_perso.x;
							C.Y=Pos_perso.y+Pos_perso.h;
							collision=0;}}break;
							
case UP:						Pos_perso.y-=2;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							
							while (!collision && C.X<= (Pos_perso.x+Pos_perso.w))
							{
							collision= Collision_Parfaite(Background,C);C.X++;
							if (collision)
							{Pos_perso.y++;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							collision=0;}}break;
							
case LEFT:						frametime++;
							perso=perso_mv_left[frame];					
							frame=Animer_Personnage(&frametime,nmb_mv,frame);

							Pos_perso.x-=2;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							while (!collision && C.Y<=(Pos_perso.y+Pos_perso.h))
							{
							collision= Collision_Parfaite(Background,C);C.Y++;
							if (collision)
							{Pos_perso.x+=2;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							collision=0;}}break;
							
case RIGHT:						
							frametime++;
							perso=perso_mv_right[frame];
							frame=Animer_Personnage(&frametime,nmb_mv,frame);
							
							
							Pos_perso.x+=2;			
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x+Pos_perso.w;
							while (!collision && C.Y<=(Pos_perso.y+Pos_perso.h))
							{
							collision= Collision_Parfaite(Background,C);C.Y++;
							if (collision)
							{Pos_perso.x--;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x+Pos_perso.w;
							collision=0;}}break;
							
} break;
							
							
							 }

SDL_BlitSurface(Background,NULL,ecran,NULL); 
SDL_BlitSurface(perso,NULL,ecran,&Pos_perso); 
 
 
SDL_Flip(ecran);



}

SDL_FreeSurface(ecran);
SDL_FreeSurface(perso);
SDL_Quit();


}
