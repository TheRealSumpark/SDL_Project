#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include  "main.h"

typedef enum
{
UP,
DOWN,
RIGHT,
LEFT,
}Direction;

typedef enum 
{ATTACK,IDLE,WALK}Etat;


void main(SDL_Surface *ecran)
{	
	int tempsactuel=0,tempsprecedent=0;

	int i=0,frame=0,frametime=0;
	Etat State=IDLE;
	Direction Sens=RIGHT;

	SDL_Init(SDL_INIT_EVERYTHING);
	objet ob,ob1,ob2,ob3,ob4,ob5,ob6,ob7,clef,porte,piste;
	Player hero;
	enemy e1,e2,e3;
	hero=Initial_personnage();
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1){
	printf("%s", Mix_GetError());
	}
	Mix_AllocateChannels(32);
	Mix_Music *musique;
	musique = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(musique, -1);
	SDL_Surface Player_Health[3];
	SDL_Surface *text= NULL, *background= NULL; 

	SDL_Surface *perso=NULL,*perso_mv_right[5],*perso_idle[2],*perso_attack_right[5],*perso_mv_left[5],*perso_attack_left[5];
	int nmb_mv=5,nmb_attack=5;

	hero.P_health=3;
	int continuer = 1;
	int direction=0,direction1=0;
	SDL_Rect positionBackground;
	SDL_Rect positionHealth;
	SDL_Event event;
	
	perso_idle[0]=IMG_Load("idle/0.png");
	perso_idle[1]=IMG_Load("idle/1.png");
	perso=perso_idle[0];


	perso_mv_right[0]=IMG_Load("mv_right/0.png");
	perso_mv_right[1]=IMG_Load("mv_right/1.png");
	perso_mv_right[2]=IMG_Load("mv_right/2.png");
	perso_mv_right[3]=IMG_Load("mv_right/3.png");
	perso_mv_right[4]=IMG_Load("mv_right/4.png");

	SDL_Rect Pos_perso;
	Pos_perso.x=145;
	Pos_perso.y=535;
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


	ob1.objett=IMG_Load("ob1.png");
	ob1.positionobjett.x=1030;
	ob1.positionobjett.y=350;
	ob1.positionobjett.h=ob1.objett->h;
	ob1.positionobjett.w=ob1.objett->w;
	
	ob2.objett=IMG_Load("ob2.png");
	ob2.positionobjett.x=520;
	ob2.positionobjett.y=227;
	ob2.positionobjett.h=ob2.objett->h;
	ob2.positionobjett.w=ob2.objett->w;

	ob3.objett=IMG_Load("ob3.png");
	ob3.positionobjett.x=270;
	ob3.positionobjett.y=400;
	ob3.positionobjett.h=ob3.objett->h;
	ob3.positionobjett.w=ob3.objett->w;

	ob4.objett=IMG_Load("ob4.png");
	ob4.positionobjett.x=540;
	ob4.positionobjett.y=514;
	ob4.positionobjett.h=ob4.objett->h;
	ob4.positionobjett.w=ob4.objett->w;

	ob5.objett=IMG_Load("ob5.png");
	ob5.positionobjett.x=470;
	ob5.positionobjett.y=575;
	ob5.positionobjett.h=ob5.objett->h;
	ob5.positionobjett.w=ob5.objett->w;

	ob6.objett=IMG_Load("ob6.png");
	ob6.positionobjett.x=5;
	ob6.positionobjett.y=300;
	ob6.positionobjett.h=ob6.objett->h;
	ob6.positionobjett.w=ob6.objett->w;

	ob7.objett=IMG_Load("ob7.png");
	ob7.positionobjett.x=830;
	ob7.positionobjett.y=569;
	ob7.positionobjett.h=ob7.objett->h;
	ob7.positionobjett.w=ob7.objett->w;
	
	e1.enemyy=IMG_Load("mob0.png");
	e1.positionenemyy.x=38;
	e1.positionenemyy.y=232;
	e1.positionenemyy.h=e1.enemyy->h;
	e1.positionenemyy.w=e1.enemyy->w;

	e2.enemyy=IMG_Load("mob1.png");
	e2.positionenemyy.x=669;
	e2.positionenemyy.y=130;
	e2.positionenemyy.h=e2.enemyy->h;
	e2.positionenemyy.w=e2.enemyy->w;
 	
	e3.enemyy=IMG_Load("mob3.png");
	e3.positionenemyy.x=1065;
	e3.positionenemyy.y=560;
	e3.positionenemyy.h=e3.enemyy->h;
	e3.positionenemyy.w=e3.enemyy->w;

	clef.objett=IMG_Load("clef.png");
	clef.positionobjett.x=1590;
	clef.positionobjett.y=540;
	clef.positionobjett.h=clef.objett->h;
	clef.positionobjett.w=clef.objett->w;

	porte.objett=IMG_Load("porte.png");
	porte.positionobjett.x=1661;
	porte.positionobjett.y=433;
	porte.positionobjett.h=porte.objett->h;
	porte.positionobjett.w=porte.objett->w;

	piste.objett=IMG_Load("piste.png");
	piste.positionobjett.x=0;
	piste.positionobjett.y=634;
	piste.positionobjett.h=piste.objett->h;
	piste.positionobjett.w=piste.objett->w;

	positionBackground.x = 0;
	positionBackground.y = 0;
         	
	positionHealth.x=0;
	positionHealth.y=0;
         
	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(1867, 800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Stage 1", NULL);

	hero.Player_Health[0]=IMG_Load("love1-1.png");
	hero.Player_Health[1]=IMG_Load("love2.png");
	hero.Player_Health[2]=IMG_Load("love3.png");
	background =IMG_Load("stage 1.png");
	//SDL_BlitSurface(background, NULL, ecran, &positionBackground);

	SDL_EnableKeyRepeat(100, 100);

	/*frame+=0.01;
	if (frame <4)
	{frame1=frame;}
	if (frame>4)
	{frame1 =frame=0;}*/ 
	/*if(tempsactuel=tempsprecedent >100)
	{
	hero.positiontext.x+=10;
	tempsprecedent=tempsactuel;
	}
	else{
	}*/
	
    	do{
	//SDL_PollEvent(&event);
       SDL_WaitEvent(&event);
	SDL_GetTicks();
	//SDL_Delay(20);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	   case SDL_MOUSEBUTTONDOWN :
	
	if (event.button.button==SDL_BUTTON_RIGHT)
	{
	      
		direction=3;
						
							//Pos_perso.x+=30;
	      hero.positiontext.x=hero.positiontext.x+20;
	if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			 Pos_perso.x=Pos_perso.x-20;
			 hero.positiontext.x=hero.positiontext.x-20;
			}
	}
        if (event.button.button==SDL_BUTTON_LEFT)
	{
	      
		direction=4;
							//Pos_perso.x-=30;
                        hero.positiontext.x=hero.positiontext.x-20;
	if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			//Pos_perso.x=Pos_perso.x+30;
			hero.positiontext.x=hero.positiontext.x+20;
			}
	}
         break;
	case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: 
			direction=1; 
                        hero.positiontext.y=hero.positiontext.y-30;
			if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			 hero.positiontext.y=hero.positiontext.y+30;
			}
			//SDL_BlitSurface (hero.Player_Animation.Mouvement[frame1],NULL,ecran,&hero.positiontext);
                        break;
                    case SDLK_DOWN: 
			direction=2;
                        hero.positiontext.y=hero.positiontext.y+15;
			if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
|| (collisionbox(hero.surf,piste.objett,hero.positiontext,piste.positionobjett)==1)
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			 hero.positiontext.y=hero.positiontext.y-15;
			}
			//SDL_BlitSurface (hero.Player_Animation.Mouvement[frame1],NULL,ecran,&hero.positiontext);
                        break;
                    case SDLK_RIGHT: 
			direction=3;
                        hero.positiontext.x=hero.positiontext.x+30;
			if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			 hero.positiontext.x=hero.positiontext.x-30;
			}	
                        break;
			//SDL_BlitSurface (hero.Player_Animation.Mouvement[frame1],NULL,ecran,&hero.positiontext);
                    case SDLK_LEFT: 
			direction=4;
                        hero.positiontext.x=hero.positiontext.x-30;
			if((collision(hero.surf,e1.enemyy,hero.positiontext,e1.positionenemyy)==1) 
|| (collision(hero.surf,e2.enemyy,hero.positiontext,e2.positionenemyy)==1) 
|| (collision(hero.surf,e3.enemyy,hero.positiontext,e3.positionenemyy)==1) 
|| (collisionbox(hero.surf,ob1.objett,hero.positiontext,ob1.positionobjett)==1) 
|| (collisionbox(hero.surf,ob2.objett,hero.positiontext,ob2.positionobjett)==1) 
|| (collisionbox(hero.surf,ob3.objett,hero.positiontext,ob3.positionobjett)==1) 
|| (collisionbox(hero.surf,ob4.objett,hero.positiontext,ob4.positionobjett)==1) 
|| (collisionbox(hero.surf,ob5.objett,hero.positiontext,ob5.positionobjett)==1) 
|| (collisionbox(hero.surf,ob6.objett,hero.positiontext,ob6.positionobjett)==1)
|| (collisionbox(hero.surf,ob7.objett,hero.positiontext,ob7.positionobjett)==1) 
||(collisionbox(hero.surf,clef.objett,hero.positiontext,clef.positionobjett)==1))
			{
			hero.positiontext.x=hero.positiontext.x+30;
			}
                        break;
			//SDL_BlitSurface (hero.Player_Animation.Mouvement[frame1],NULL,ecran,&hero.positiontext);
	break;
}

	/*case SDL_KEYDOWN : 
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
							{State=ATTACK;}break;
				
			
}break;*/
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


case DOWN:						Pos_perso.y+=30;
														
if((collision(perso,e1.enemyy,Pos_perso,e1.positionenemyy)==1) 
|| (collision(perso,e2.enemyy,Pos_perso,e2.positionenemyy)==1) 
|| (collision(perso,e3.enemyy,Pos_perso,e3.positionenemyy)==1)
|| (collisionbox(perso,ob1.objett,Pos_perso,ob1.positionobjett)==1) 
|| (collisionbox(perso,ob2.objett,Pos_perso,ob2.positionobjett)==1) 
|| (collisionbox(perso,ob3.objett,Pos_perso,ob3.positionobjett)==1) 
|| (collisionbox(perso,ob4.objett,Pos_perso,ob4.positionobjett)==1) 
|| (collisionbox(perso,ob5.objett,Pos_perso,ob5.positionobjett)==1) 
|| (collisionbox(perso,ob6.objett,Pos_perso,ob6.positionobjett)==1) 
|| (collisionbox(perso,ob7.objett,Pos_perso,ob7.positionobjett)==1) 
|| (collisionbox(perso,piste.objett,Pos_perso,piste.positionobjett)==1)
||(collisionbox(perso,clef.objett,Pos_perso,clef.positionobjett)==1))
			{
			Pos_perso.x=Pos_perso.x+30;}break;
							
case UP:						Pos_perso.y-=30;
							
if((collision(perso,e1.enemyy,Pos_perso,e1.positionenemyy)==1) 
|| (collision(perso,e2.enemyy,Pos_perso,e2.positionenemyy)==1) 
|| (collision(perso,e3.enemyy,Pos_perso,e3.positionenemyy)==1)
|| (collisionbox(perso,ob1.objett,Pos_perso,ob1.positionobjett)==1) 
|| (collisionbox(perso,ob2.objett,Pos_perso,ob2.positionobjett)==1) 
|| (collisionbox(perso,ob3.objett,Pos_perso,ob3.positionobjett)==1) 
|| (collisionbox(perso,ob4.objett,Pos_perso,ob4.positionobjett)==1) 
|| (collisionbox(perso,ob5.objett,Pos_perso,ob5.positionobjett)==1) 
|| (collisionbox(perso,ob6.objett,Pos_perso,ob6.positionobjett)==1) 
|| (collisionbox(perso,ob7.objett,Pos_perso,ob7.positionobjett)==1) 
||(collisionbox(perso,clef.objett,Pos_perso,clef.positionobjett)==1))
			{
			 Pos_perso.y=Pos_perso.y+30;
			}break;
							
case LEFT:						frametime++;
							perso=perso_mv_left[frame];					
							frame=Animer_Personnage(&frametime,nmb_mv,frame);

							Pos_perso.x-=30;
if((collision(perso,e1.enemyy,Pos_perso,e1.positionenemyy)==1) 
|| (collision(perso,e2.enemyy,Pos_perso,e2.positionenemyy)==1) 
|| (collision(perso,e3.enemyy,Pos_perso,e3.positionenemyy)==1)
|| (collisionbox(perso,ob1.objett,Pos_perso,ob1.positionobjett)==1) 
|| (collisionbox(perso,ob2.objett,Pos_perso,ob2.positionobjett)==1) 
|| (collisionbox(perso,ob3.objett,Pos_perso,ob3.positionobjett)==1) 
|| (collisionbox(perso,ob4.objett,Pos_perso,ob4.positionobjett)==1) 
|| (collisionbox(perso,ob5.objett,Pos_perso,ob5.positionobjett)==1) 
|| (collisionbox(perso,ob6.objett,Pos_perso,ob6.positionobjett)==1) 
|| (collisionbox(perso,ob7.objett,Pos_perso,ob7.positionobjett)==1) 
||(collisionbox(perso,clef.objett,Pos_perso,clef.positionobjett)==1))
			{
			Pos_perso.x=Pos_perso.x+30;
			}break;
							
case RIGHT:						
							frametime++;
							perso=perso_mv_right[frame];
							frame=Animer_Personnage(&frametime,nmb_mv,frame);
							
							
							Pos_perso.x+=30;			
if((collision(perso,e1.enemyy,Pos_perso,e1.positionenemyy)==1) 
|| (collision(perso,e2.enemyy,Pos_perso,e2.positionenemyy)==1) 
|| (collision(perso,e3.enemyy,Pos_perso,e3.positionenemyy)==1)
|| (collisionbox(perso,ob1.objett,Pos_perso,ob1.positionobjett)==1) 
|| (collisionbox(perso,ob2.objett,Pos_perso,ob2.positionobjett)==1) 
|| (collisionbox(perso,ob3.objett,Pos_perso,ob3.positionobjett)==1) 
|| (collisionbox(perso,ob4.objett,Pos_perso,ob4.positionobjett)==1) 
|| (collisionbox(perso,ob5.objett,Pos_perso,ob5.positionobjett)==1) 
|| (collisionbox(perso,ob6.objett,Pos_perso,ob6.positionobjett)==1) 
|| (collisionbox(perso,ob7.objett,Pos_perso,ob7.positionobjett)==1) 
||(collisionbox(perso,clef.objett,Pos_perso,clef.positionobjett)==1))
			{
			 Pos_perso.x=Pos_perso.x-30;
			}break;
							
} break;
}
	switch(direction){
		case 1 : 
		hero.surf=IMG_Load("clef.png");
			
		break;
		case 2 : 
		hero.surf=IMG_Load("clef.png");
		
		break;
		case 3 :
		hero.surf=IMG_Load("clef.png");
				
		break;
		case 4 : 
		hero.surf=IMG_Load("clef.png");
		
		break;		
		}

           	/*switch(SDL_KEYUP)
		{
		   case SDLK_UP: 
			direction=0;
			//surf[0]=IMG_Load("1.png");
                        break;
                    case SDLK_DOWN: 
			direction=0;
                       //surf[0]=IMG_Load("1.png");
                        break;
                    case SDLK_RIGHT:
			direction=0;
                        //surf[0]=IMG_Load("1.png");
                        break;
                    case SDLK_LEFT: 
			direction=0;
                        //surf[0]=IMG_Load("1.png");
                        break;	
		}*/

	SDL_BlitSurface(background, NULL, ecran, &positionBackground);
		SDL_BlitSurface (piste.objett,NULL,ecran,&piste.positionobjett);
	SDL_BlitSurface(hero.Player_Health[2], NULL, ecran, &positionHealth);
		SDL_BlitSurface (ob7.objett,NULL,ecran,&ob7.positionobjett);
	SDL_BlitSurface (ob5.objett,NULL,ecran,&ob5.positionobjett);
		SDL_BlitSurface (ob4.objett,NULL,ecran,&ob4.positionobjett);
	SDL_BlitSurface (ob3.objett,NULL,ecran,&ob3.positionobjett);
		SDL_BlitSurface (ob6.objett,NULL,ecran,&ob6.positionobjett);
	SDL_BlitSurface (ob2.objett,NULL,ecran,&ob2.positionobjett);
		SDL_BlitSurface (ob1.objett,NULL,ecran,&ob1.positionobjett);
	SDL_BlitSurface (porte.objett,NULL,ecran,&porte.positionobjett);
		SDL_BlitSurface (clef.objett,NULL,ecran,&clef.positionobjett);
	SDL_BlitSurface (e1.enemyy,NULL,ecran,&e1.positionenemyy);
		SDL_BlitSurface (e2.enemyy,NULL,ecran,&e2.positionenemyy);
	SDL_BlitSurface (e3.enemyy,NULL,ecran,&e3.positionenemyy);
		Afficher_perso(hero,ecran);
	SDL_BlitSurface(perso,NULL,ecran,&Pos_perso);
	SDL_Flip(ecran);
	}while(continuer);
		
	SDL_FreeSurface(background);
		SDL_FreeSurface(ecran);
	SDL_FreeSurface(hero.Player_Health[2]);
		SDL_FreeSurface(piste.objett);	
	SDL_FreeSurface(ob7.objett);
		SDL_FreeSurface(ob5.objett);
	SDL_FreeSurface(ob4.objett);
		SDL_FreeSurface(ob3.objett);
	SDL_FreeSurface(ob6.objett);
		SDL_FreeSurface(ob2.objett);
	SDL_FreeSurface(ob1.objett);
		SDL_FreeSurface(porte.objett);
	SDL_FreeSurface(clef.objett);
		SDL_FreeSurface(e1.enemyy);
	SDL_FreeSurface(e2.enemyy);
		SDL_FreeSurface(e3.enemyy);
	SDL_FreeSurface(perso);
	//SDL_FreeSurface(hero.Player_Animation.Mouvement[frame1]);
	SDL_Quit();
}
