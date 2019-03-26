#include "main.h"






void main ()
{
int done=1,i=0,len,X,Y,collision=0;
    char c ;
    char mob[]="mob";
    char ext[]=".png";
    len=strlen (mob);
    char Mob_Name[len+2];
    

Ennemi Mob[4];Ennemi m;
	FILE *f;
	f=fopen("Pos.txt","r");
	
	for (i=0;i<4;i++)
	 {strcpy (Mob_Name,mob);
   	 c=i+48;
    	Mob_Name[len]=c;
    	Mob_Name[len+1]='\0';
    	strcat(Mob_Name,ext);
	fscanf(f,"%d %d\n",&X,&Y);
	 Mob[i]=Init_Ennemi(Mob_Name,X,Y);}
	fclose(f);


SDL_Surface *ecran=NULL,*perso=NULL,*Background=NULL;
Background=IMG_Load("Artboard1.png");
perso=IMG_Load("Selim.png");
SDL_Rect Pos_perso;
Pos_perso.x=200;
Pos_perso.y=100;
Pos_perso.h=perso->h;
Pos_perso.w=perso->w;





SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(6000,800, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
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
			
			
				case SDLK_DOWN :	Pos_perso.y+=15;
							for (i=0;i<4;i++)
							{m=Mob[i];
							collision+=Collision_Ennemi(Pos_perso,m);}
							if (collision)
							{Pos_perso.y-=15;collision=0;}
				break;
				case SDLK_UP:		Pos_perso.y-=15;
							for (i=0;i<4;i++)
							{m=Mob[i];
							collision+=Collision_Ennemi(Pos_perso,m);}
							if (collision)
							{Pos_perso.y+=15;collision=0;}
				break;
				case SDLK_LEFT:		Pos_perso.x-=15;
							for (i=0;i<4;i++)
							{m=Mob[i];
							collision+=Collision_Ennemi(Pos_perso,m);}
							if (collision)
							{Pos_perso.x+=15;collision=0;}
				break;
				case SDLK_RIGHT:	Pos_perso.x+=15;
							for (i=0;i<4;i++)
							{m=Mob[i];
							collision+=Collision_Ennemi(Pos_perso,m);}
							if (collision)
							{Pos_perso.x-=15;collision=0;};
				break;
			
			}
			




}
 

SDL_BlitSurface(Background,NULL,ecran,NULL); 
SDL_BlitSurface(perso,NULL,ecran,&Pos_perso); 
//SDL_BlitSurface (Mob[0].Anim_Ennemi,NULL,ecran,&Mob[0].Pos_Ennemi);
Afficher_Ennemi(Mob[0],ecran);
Afficher_Ennemi(Mob[1],ecran);
Afficher_Ennemi(Mob[2],ecran);
Afficher_Ennemi(Mob[3],ecran);
SDL_Flip(ecran);



}

SDL_FreeSurface(ecran);
SDL_FreeSurface(perso);
SDL_Quit();


}
