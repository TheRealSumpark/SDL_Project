#include  "main.h"

void main(SDL_Surface *ecran)
{
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
	
	for (i=0;i<4;i++)
	{strcpy (Mob_Name,mob);
   	c=i+48;
    	Mob_Name[len]=c;
    	Mob_Name[len+1]='\0';
    	strcat(Mob_Name,ext);
	fscanf(f,"%d %d\n",&X,&Y);
	Mob[i]=Init_Ennemi(Mob_Name,X,Y);}
	fclose(f);

	int vie=3,score=0;
	int localisation=1;
	int frametime=0,frametime1=0,frame=0,nmbb_frame=5,nmb1_frame=5;
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

	//SDL_EnableKeyRepeat(100, 100);
	
    	do{
	SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	}
	afficher(ecran,&b);
	Initial_objet(ob,&clef,&porte,&piste);
	afficherobjet(ob,&clef,&porte,&piste,ecran,&b);
	localisation=collisionall(ob,clef,porte,piste,&hero,&vie,&score,Sens,State,Mob,C,Background);
	if(localisation==1)
	{
	reponse(ecran,d);
	solution(ecran,d);
	quiz(ecran,d);
	good(ecran);
	enigme(d);
	}
	//deplacement2(Sens,State,&hero);
	event_handler(event,&Sens ,&State) ; 
	deplacement(Sens,State,&hero);
	Animer_Personnage(&frametime ,nmbb_frame,&frame,&hero,&Sens,&State);	
	Afficher_perso(hero,hero.P_health,ecran);
	//Sens1=mvt_aleatoire (Mob[0],Mob[0].Pos_Ennemi,Mob[0].Pos_Ennemi);
	//ecran=Animer_enemy(Ennemi Mob,&frametime1,nmb1_frame,frame,Sens1) ;
	Afficher_Ennemi(Mob[0],ecran);
	Afficher_Ennemi(Mob[1],ecran);
	//Afficher_Ennemi(Mob[2],ecran);
	Afficher_Ennemi(Mob[3],ecran);
	scrolling (&b,ecran,Sens,State);
	SDL_Flip(ecran);
	}while(continuer);

	SDL_FreeSurface(ecran);
	SDL_Quit();
}
