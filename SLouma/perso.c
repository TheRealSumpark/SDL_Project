#include  "perso.h"

typedef enum
{
UP,
DOWN,
RIGHT,
LEFT,
}Direction;

typedef enum 
{
ATTACK,
IDLE,
WALK,
}Etat;

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

int Animer_Personnage(int *frametime ,int nmb_frame,int frame ) // changer la variable temporaire 
{
int FPS=60;

							if (FPS/(*frametime)==5)
							{(*frametime)=0;
							frame++;
							if (frame==nmb_frame)
							{frame=0;}}
							return frame;
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

void main(SDL_Surface *ecran)
{	
	int i,j,frame=0,frametime=0;
	int vie;
	Etat State=IDLE;
	Direction Sens=RIGHT;
	SDL_Init(SDL_INIT_EVERYTHING);
	EO ob[7],clef,porte,piste;
	EO  e[3];
	Player hero;
	hero=Initial_personnage();
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1){
	printf("%s", Mix_GetError());
	}
	Mix_AllocateChannels(32);
	Mix_Music *musique;
	musique = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(musique, -1);
	SDL_Surface *text= NULL, *background= NULL; 

	int continuer = 1;
	SDL_Rect positionBackground;
	
	SDL_Event event;

	ob[0].objett=IMG_Load("ob1.png");
	ob[0].positionobjett.x=1030;
	ob[0].positionobjett.y=350;
	ob[0].positionobjett.h=ob[0].objett->h;
	ob[0].positionobjett.w=ob[0].objett->w;
	
	ob[1].objett=IMG_Load("ob2.png");
	ob[1].positionobjett.x=520;
	ob[1].positionobjett.y=227;
	ob[1].positionobjett.h=ob[1].objett->h;
	ob[1].positionobjett.w=ob[1].objett->w;

	ob[2].objett=IMG_Load("ob3.png");
	ob[2].positionobjett.x=270;
	ob[2].positionobjett.y=400;
	ob[2].positionobjett.h=ob[2].objett->h;
	ob[2].positionobjett.w=ob[2].objett->w;

	ob[3].objett=IMG_Load("ob4.png");
	ob[3].positionobjett.x=540;
	ob[3].positionobjett.y=514;
	ob[3].positionobjett.h=ob[3].objett->h;
	ob[3].positionobjett.w=ob[3].objett->w;

	ob[4].objett=IMG_Load("ob5.png");
	ob[4].positionobjett.x=470;
	ob[4].positionobjett.y=575;
	ob[4].positionobjett.h=ob[4].objett->h;
	ob[4].positionobjett.w=ob[4].objett->w;

	ob[5].objett=IMG_Load("ob6.png");
	ob[5].positionobjett.x=5;
	ob[5].positionobjett.y=300;
	ob[5].positionobjett.h=ob[5].objett->h;
	ob[5].positionobjett.w=ob[5].objett->w;

	ob[6].objett=IMG_Load("ob7.png");
	ob[6].positionobjett.x=830;
	ob[6].positionobjett.y=569;
	ob[6].positionobjett.h=ob[6].objett->h;
	ob[6].positionobjett.w=ob[6].objett->w;
	
	e[0].surf1=IMG_Load("mob0.png");
	e[0].positionsurf1.x=38;
	e[0].positionsurf1.y=232;
	e[0].positionsurf1.h=e[0].surf1->h;
	e[0].positionsurf1.w=e[0].surf1->w;

	e[1].surf1=IMG_Load("mob1.png");
	e[1].positionsurf1.x=669;
	e[1].positionsurf1.y=130;
	e[1].positionsurf1.h=e[1].surf1->h;
	e[1].positionsurf1.w=e[1].surf1->w;
 	
	e[2].surf1=IMG_Load("mob3.png");
	e[2].positionsurf1.x=1065;
	e[2].positionsurf1.y=560;
	e[2].positionsurf1.h=e[2].surf1->h;
	e[2].positionsurf1.w=e[2].surf1->w;

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
         	

	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(1867, 800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Stage 1", NULL);

	background =IMG_Load("stage 1.png");
	SDL_EnableKeyRepeat(100, 100);
	
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
						
							hero.Pos_perso.x+=20;
		if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
{ hero.Pos_perso.x=hero.Pos_perso.x-20;
hero.P_health-=1;}
if((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1))
			{
			 hero.Pos_perso.x=hero.Pos_perso.x-20;
			}
	}
        if (event.button.button==SDL_BUTTON_LEFT)
	{
	      
							hero.Pos_perso.x-=20;
	if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
{ hero.Pos_perso.x=hero.Pos_perso.x+20;
hero.P_health-=1;}
if((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1))
			{
			hero.Pos_perso.x=hero.Pos_perso.x+20;
			}
	}
         break;
	
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
							{State=ATTACK;}break;
				
			
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
							{	case LEFT:hero.perso=hero.perso_idle[1];break;
								case RIGHT:hero.perso=hero.perso_idle[0];break;	
								}break;
								
		case ATTACK:					frametime++;
							switch (Sens) {
							case LEFT:	hero.perso=hero.perso_attack_left[frame];
									frame=Animer_Personnage(&frametime,hero.nmb_attack,frame);
									if (frame==0)
									{State=IDLE;}
							break;
							case RIGHT:	hero.perso=hero.perso_attack_right[frame];
									frame=Animer_Personnage(&frametime,hero.nmb_attack,frame);
									if (frame==0)
									{State=IDLE;}
							break;
							
							}break;
							
		case WALK :  					 switch (Sens)
{


case DOWN:						hero.Pos_perso.y+=20;
														
	if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
{
hero.P_health-=1;
			hero.Pos_perso.y=hero.Pos_perso.y-20;}
if ((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1)
|| (collisionbox(hero.perso,piste.objett,hero.Pos_perso,piste.positionobjett)==1))
			{
			hero.Pos_perso.y=hero.Pos_perso.y-20;}break;
							
case UP:						hero.Pos_perso.y-=20;
							
if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
{hero.P_health-=1;
			 hero.Pos_perso.y=hero.Pos_perso.y+20;}
if ((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1))
			{
			 hero.Pos_perso.y=hero.Pos_perso.y+20;
			}break;
							
case LEFT:						frametime++;
							hero.perso=hero.perso_mv_left[frame];					
							frame=Animer_Personnage(&frametime,hero.nmb_mv,frame);

							hero.Pos_perso.x-=20;
if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
	{ hero.P_health-=1;
			hero.Pos_perso.x=hero.Pos_perso.x+20;}
if ((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1))
			{
			hero.Pos_perso.x=hero.Pos_perso.x+20;
			}break;
							
case RIGHT:						
							frametime++;
							hero.perso=hero.perso_mv_right[frame];
							frame=Animer_Personnage(&frametime,hero.nmb_mv,frame);
							
							
							hero.Pos_perso.x+=20;			
if((collision(hero.perso,e[0].surf1,hero.Pos_perso,e[0].positionsurf1)==1) 
|| (collision(hero.perso,e[1].surf1,hero.Pos_perso,e[1].positionsurf1)==1) 
|| (collision(hero.perso,e[2].surf1,hero.Pos_perso,e[2].positionsurf1)==1))
{
hero.P_health-=1;
			 hero.Pos_perso.x=hero.Pos_perso.x-20;}
if((collisionbox(hero.perso,ob[0].objett,hero.Pos_perso,ob[0].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[1].objett,hero.Pos_perso,ob[1].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[2].objett,hero.Pos_perso,ob[2].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[3].objett,hero.Pos_perso,ob[3].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett)==1) 
|| (collisionbox(hero.perso,ob[5].objett,hero.Pos_perso,ob[5].positionobjett)==1)
|| (collisionbox(hero.perso,ob[6].objett,hero.Pos_perso,ob[6].positionobjett)==1) 
||(collisionbox(hero.perso,clef.objett,hero.Pos_perso,clef.positionobjett)==1))
			{
			
			 hero.Pos_perso.x=hero.Pos_perso.x-20;
			}break;
							
} break;
}
	

	SDL_BlitSurface(background, NULL, ecran, &positionBackground);
	SDL_BlitSurface (piste.objett,NULL,ecran,&piste.positionobjett);
	for(i=0; i<7; i++)
	{
	SDL_BlitSurface (ob[i].objett,NULL,ecran,&ob[i].positionobjett);}
	SDL_BlitSurface (porte.objett,NULL,ecran,&porte.positionobjett);
	SDL_BlitSurface (clef.objett,NULL,ecran,&clef.positionobjett);
	for(j=0; j<3; j++)
	{
	SDL_BlitSurface (e[j].surf1,NULL,ecran,&e[j].positionsurf1);
	}
	Afficher_perso(hero,hero.P_health,ecran);
	SDL_Flip(ecran);
	}while(continuer);

	SDL_FreeSurface(background);
	SDL_FreeSurface(piste.objett);
	for(i=0; i<7; i++)
	{	
	SDL_FreeSurface(ob[i].objett);}
	SDL_FreeSurface(porte.objett);
	SDL_FreeSurface(clef.objett);
	for(j=0; j<3; j++)
	{
	SDL_FreeSurface(e[j].surf1);}
	SDL_FreeSurface(ecran);
	SDL_Quit();
}
