#include "main.h"

typedef enum 
{
UP,
DOWN,
RIGHT,
LEFT,
STILL,
}Direction;





void main ()
{
int done=1,i=0,len,X,Y,collision=0;
   Coordinate C;
   Direction Sens=STILL;


SDL_Surface *ecran=NULL,*perso=NULL,*Background=NULL;


Background=IMG_Load("test.jpg");

perso=IMG_Load("Selim.png");

SDL_Rect Pos_perso;
Pos_perso.x=600;
Pos_perso.y=100;
Pos_perso.h=perso->h;
Pos_perso.w=perso->w;





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
			
			
				case SDLK_DOWN :	Sens=DOWN;
							
				break;
				case SDLK_UP:		Sens=UP;
							
				break;
				case SDLK_LEFT:		Sens=LEFT;
							
				break;
				case SDLK_RIGHT:	Sens=RIGHT;
							
				break;
			
			}break;
	case SDL_KEYUP:	switch (event.key.keysym.sym)
			{		
			
			
				case SDLK_DOWN :	Sens=STILL;
							
				break;
				case SDLK_UP:		Sens=STILL;
							
				break;
				case SDLK_LEFT:		Sens=STILL;
							
				break;
				case SDLK_RIGHT:	Sens=STILL;
							
				break;
			
			}break;
			




}
 
 
 switch (Sens)
{


case DOWN:						Pos_perso.y+=15;
							C.Y=Pos_perso.y+Pos_perso.h;
							C.X=Pos_perso.x;
							while (!collision && C.X<= (Pos_perso.x+Pos_perso.w))
							{C.X+=1;
							collision= Collision_Parfaite(Background,C);}
							if (collision!=0)
							{Pos_perso.y-=15;collision=0;}break;
							
case UP:						Pos_perso.y-=15;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							while (!collision && C.X<= (Pos_perso.x+Pos_perso.w))
							{C.X+=1;
							collision= Collision_Parfaite(Background,C);}
							if (collision!=0)
							{Pos_perso.y+=15;collision=0;}break;
							
case LEFT:						Pos_perso.x-=15;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x;
							while (!collision && C.Y<= (Pos_perso.y+Pos_perso.h))
							{C.Y+=1;
							collision= Collision_Parfaite(Background,C);}
							if (collision!=0)
							{Pos_perso.x+=15;collision=0;}break;
case RIGHT:	Pos_perso.x+=15;
							C.Y=Pos_perso.y;
							C.X=Pos_perso.x+Pos_perso.w;
							while (!collision && C.Y<= (Pos_perso.y+Pos_perso.h))
							{C.Y+=1;
							collision= Collision_Parfaite(Background,C);}
							if (collision!=0)
							{Pos_perso.x-=15;collision=0;}break;

} 
 

SDL_BlitSurface(Background,NULL,ecran,NULL); 
SDL_BlitSurface(perso,NULL,ecran,&Pos_perso); 
 
 
SDL_Flip(ecran);



}

SDL_FreeSurface(ecran);
SDL_FreeSurface(perso);
SDL_Quit();


}
