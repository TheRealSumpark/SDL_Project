#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "jouer.h"
/**
* @file jouer.c
* @brief Testing Program.
* @author C Team
* @version 1.2
* @date Apr 04, 2019
*
* Testing program for game
*
*/
void jouer(SDL_Surface *ecran)
{


//ROTOZOOM VARIABLES
double angle=0;
Map M;
M.Overview=NULL;
M.Border=IMG_Load("Border.png");

int on =0;
//


	//Declaring P2
	int hero2_on=1;
	int frametime_2=0,frame_2=0;
	Player hero_2;
	hero_2=Initial_personnage2();
	int keysHeld_2[323] = {0};
	Direction Sens_2;
	Etat State_2; 
	int collision_2;
	int numkeys_2;
	Uint8 * keys_2;

	// End of declaration of P2

	//choix input manette
	int Input=1;	
	//






         int d;	
	 srand(time(NULL));
    	d=rand()%3+1;
	

	int i=0,len,X,Y;
	Coordinate C;
    	char c ;
    	char mob[]="mob";
    	char ext[]=".png";
    	len=strlen (mob);
    	char Mob_Name[len+2];
    	Ennemi Mob[4];Ennemi m;
	FILE *f;
	f=fopen("Pos.txt","r");
	
	int keysHeld[323] = {0};
	for (i=0;i<4;i++)
	{strcpy (Mob_Name,mob);
   	c=i+48;
    	Mob_Name[len]=c;
    	Mob_Name[len+1]='\0';
    	strcat(Mob_Name,ext);
	fscanf(f,"%d %d\n",&X,&Y);
	Mob[i]=Init_Ennemi(Mob_Name,X,Y);}
	fclose(f);
	int min , max,min1,min2,max1,max2;
 	max = Mob[0].Pos_Ennemi.x +40 ;
 	min = Mob[0].Pos_Ennemi.x -40 ;
	max1 = Mob[1].Pos_Ennemi.x +40 ;
 	min1 = Mob[1].Pos_Ennemi.x -40 ;
	max2 = Mob[3].Pos_Ennemi.x +40 ;
 	min2 = Mob[3].Pos_Ennemi.x -40 ;
	int vie=3,score=0;
	int localisation=0;
	int frametime=0,frametime1=0,frame=0,nmbb_frame=5,nmb1_frame=5,frame1=0;
	int numkeys;
	Uint8 * keys;
	SDL_Init(SDL_INIT_EVERYTHING);
	Etat State;
	Direction Sens,Sens1;
	background b;
	EO ob[7],clef,porte,piste;
	EO  e[3];
	Player hero;
	hero=Initial_personnage();
	initialiser(&b);
	int continuer = 1;
	SDL_Surface *Background=NULL;
	SDL_Event event;
         	
	Background=IMG_Load("back.png");
	SDL_LockSurface(Background);
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(1867,800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Stage 1", NULL);
	Initial_objet(ob,&clef,&porte,&piste);
    	do{
	SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	case SDL_KEYDOWN :
	switch (event.key.keysym.sym){

	 case SDLK_ESCAPE :Nettoyer_stage(&b);
		main(ecran); 
		break;
	}}
	afficher(ecran,&b);
	
	afficherobjet(ob,&clef,&porte,&piste,ecran,&b);
	int collision=0;
	collision=collisionbox(hero.perso,ob[4].objett,hero.Pos_perso,ob[4].positionobjett);


	localisation=collisionall(ob,clef,porte,piste,&hero,&vie,&score,Sens,State,Mob,C,Background);
	if (!Input)
	{event_handler(event,&Sens ,&State,keysHeld);}
	else {Manette(&State,&Sens);}
	SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
	deplacement(Sens,State,&hero,keysHeld,&frametime1,nmb1_frame,&frame1,keys,collision);
	Animer_Personnage(&frametime ,&frame,&hero,&Sens,&State);
	//Vitesse(Sens,State,&hero);	
	Afficher_perso(hero,hero.P_health,ecran);


	//Printing second hero
	if (hero2_on)
	{
	
	if (Input)
	{event_handler(event,&Sens_2,&State_2,keysHeld_2);}
	else {Manette(&State_2,&Sens_2);}

	SDL_PumpEvents();
        keys_2=SDL_GetKeyState(&numkeys_2);
	collision_2=collisionall(ob,clef,porte,piste,&hero_2,&vie,&score,Sens,State,Mob,C,Background);
	deplacement(Sens_2,State_2,&hero_2,keysHeld_2,&frametime_2,nmb1_frame,&frame_2,keys_2,collision_2);
	Animer_Personnage(&frametime_2,&frame_2,&hero_2,&Sens_2,&State_2);	
	Afficher_perso(hero_2,hero_2.P_health,ecran);
	}	
		
	

	Mini_map(ecran,M);

	if (angle!=360)
	{ Rotozoom(ecran,b,clef,&angle);
	}

	
	//localisation=1;	
	/*if(localisation==1)
	{
              init_images;
              enigme(d,ecran);
       	}	*/



	mvtaleatoire (&Mob[0]  , min ,  max );
	mvtaleatoire (&Mob[1]  , min1 ,  max1 );
	mvtaleatoire (&Mob[3]  , min2 ,  max2);
	Afficher_Ennemi(Mob[0],ecran);
	Afficher_Ennemi(Mob[1],ecran);
	Afficher_Ennemi(Mob[3],ecran);
	
	//scrolling (&b,ecran,Sens,State);
	SDL_Flip(ecran);

	}while(continuer);
	
	SDL_FreeSurface(ecran);
	SDL_FreeSurface(M.Border);
	SDL_FreeSurface(M.Overview);
	SDL_FreeSurface(Background);
	for (i=0;i<hero.nmb_mv;i++)
	{SDL_FreeSurface(hero.perso_mv_right[i]);
	SDL_FreeSurface(hero.perso_mv_left[i]);}
	for (i=0;i<hero.nmb_attack;i++)
	{
	SDL_FreeSurface(hero.perso_attack_right[i]);
	SDL_FreeSurface(hero.perso_attack_left[i]);
	}
	for (i=0;i<3;i++)
	{SDL_FreeSurface(hero.Player_Health[i]);
	}
	for (i=0;i<2;i++)
	{SDL_FreeSurface(hero.perso_idle[i]);}
	

	for (i=0;i<hero_2.nmb_mv;i++)
	{SDL_FreeSurface(hero_2.perso_mv_right[i]);
	SDL_FreeSurface(hero.perso_mv_left[i]);}
	for (i=0;i<hero_2.nmb_attack;i++)
	{
	SDL_FreeSurface(hero_2.perso_attack_right[i]);
	SDL_FreeSurface(hero_2.perso_attack_left[i]);
	}
	for (i=0;i<3;i++)
	{SDL_FreeSurface(hero_2.Player_Health[i]);
	}
	for (i=0;i<2;i++)
	{SDL_FreeSurface(hero_2.perso_idle[i]);}


/*
	SDL_FreeSurface();
	SDL_FreeSurface();
	SDL_FreeSurface();*/


	SDL_Quit();
}
void Nettoyer_stage(background * b)
{
		SDL_FreeSurface(b->image);
}
