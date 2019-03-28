#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include  "main.h"
void main(SDL_Surface *ecran)
{	

	SDL_Init(SDL_INIT_EVERYTHING);
	objet ob;
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

	hero.P_health=3;
	int continuer = 1;
	int direction=0,direction1=0;
	SDL_Rect positionBackground;
	SDL_Rect positionHealth;
	SDL_Event event;
	
	ob.objett=IMG_Load("2.png");
	ob.positionobjett.x=80;
	ob.positionobjett.y=140;
	ob.positionobjett.h=ob.objett->h;
	ob.positionobjett.w=ob.objett->w;
	
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

	positionBackground.x = 0;
	positionBackground.y = 0;
         	
	positionHealth.x=0;
	positionHealth.y=0;
         
	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(6000, 800, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("IMAGE", NULL);

	hero.Player_Health[0]=IMG_Load("love1-1.png");
	hero.Player_Health[1]=IMG_Load("love2.png");
	hero.Player_Health[2]=IMG_Load("love3.png");
	background =IMG_Load("testclavier.png");
	SDL_BlitSurface(background, NULL, ecran, &positionBackground);

	SDL_EnableKeyRepeat(100, 100);
	
    	do{
	//SDL_PollEvent(&event);
       SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	   case SDL_MOUSEBUTTONDOWN :
	
	if (event.button.button==SDL_BUTTON_RIGHT)
	{
	      
		direction=3;
	      hero.positiontext.x=hero.positiontext.x+20;}
        if (event.button.button==SDL_BUTTON_LEFT)
	{
	      
		direction=4;
                        hero.positiontext.x=hero.positiontext.x-20;}
         break;
	 case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: 
			direction=1;
                        hero.positiontext.y=hero.positiontext.y-30;
			if((collision(hero,e1)==1) || (collision(hero,e2)==1) || (collision(hero,e3)==1))
			{
			 hero.positiontext.y=hero.positiontext.y+30;
			}
                        break;
                    case SDLK_DOWN: 
			direction=2;
                        hero.positiontext.y=hero.positiontext.y+30;
			if((collision(hero,e1)==1) || (collision(hero,e2)==1) || (collision(hero,e3)==1))
			{
			 hero.positiontext.y=hero.positiontext.y-30;
			}
                        break;
                    case SDLK_RIGHT: 
			direction=3;
                        hero.positiontext.x=hero.positiontext.x+30;
			if((collision(hero,e1)==1) || (collision(hero,e2)==1) || (collision(hero,e3)==1))
			{
			 hero.positiontext.x=hero.positiontext.x-30;
			}	
                        break;
                    case SDLK_LEFT: 
			direction=4;
                        hero.positiontext.x=hero.positiontext.x-30;
			if((collision(hero,e1)==1) || (collision(hero,e2)==1) || (collision(hero,e3)==1))
			{
			hero.positiontext.x=hero.positiontext.x+30;
			}
                        break;
	break;
}
	switch(direction){
		case 0: 
		hero.surf=IMG_Load("1.png");
		
		break;
		case 1 : 
		hero.surf=IMG_Load("1.png");
			
		break;
		case 2 : 
		hero.surf=IMG_Load("1.png");
		
		break;
		case 3 :
		hero.surf=IMG_Load("1.png");
				
		break;
		case 4 : 
		hero.surf=IMG_Load("1.png");
		
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

                }
		
	SDL_BlitSurface(background, NULL, ecran, &positionBackground);
	SDL_BlitSurface(hero.Player_Health[2], NULL, ecran, &positionHealth);
	SDL_BlitSurface (e1.enemyy,NULL,ecran,&e1.positionenemyy);
	SDL_BlitSurface (e2.enemyy,NULL,ecran,&e2.positionenemyy);
	SDL_BlitSurface (e3.enemyy,NULL,ecran,&e3.positionenemyy);
	Afficher_perso(hero,ecran);
	SDL_Flip(ecran);
	}while(continuer);
		
	SDL_FreeSurface(background);
	SDL_FreeSurface(ecran);
	SDL_FreeSurface(hero.Player_Health[2]);
	SDL_Quit();
}
