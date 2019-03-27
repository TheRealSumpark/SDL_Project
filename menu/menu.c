#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

int main (void)
{
SDL_Surface *Ecran ,*Background;
SDL_Rect posEcran,posBack;
SDL_Event event;

Mix_Chunk *check;
Mix_Music *OstMenu;

int on[4]={0,0,0,0};
int done=1,i=0;
int check_on=0;

TTF_Init();
TTF_Font* font=TTF_OpenFont("angel.ttf",60);
const char *button[4]={"Start","Load","Settings","Quit"};
SDL_Color Red={255,0,0},Black={0,0,0};
SDL_Surface *Button[4];
Button[0]=TTF_RenderText_Solid(font,button[0],Black);
Button[1]=TTF_RenderText_Solid(font,button[1],Black);
Button[2]=TTF_RenderText_Solid(font,button[2],Black);
Button[3]=TTF_RenderText_Solid(font,button[3],Black);

SDL_Surface *ButtonRed[4];
ButtonRed[0]=TTF_RenderText_Solid(font,button[0],Red);
ButtonRed[1]=TTF_RenderText_Solid(font,button[1],Red);
ButtonRed[2]=TTF_RenderText_Solid(font,button[2],Red);
ButtonRed[3]=TTF_RenderText_Solid(font,button[3],Red);

SDL_Surface *ButtonBlack[4];
ButtonBlack[0]=TTF_RenderText_Solid(font,button[0],Black);
ButtonBlack[1]=TTF_RenderText_Solid(font,button[1],Black);
ButtonBlack[2]=TTF_RenderText_Solid(font,button[2],Black);
ButtonBlack[3]=TTF_RenderText_Solid(font,button[3],Black);

SDL_Rect pos_button[4];
pos_button[0].x=330;	pos_button[0].y=172;
pos_button[1].x=138;	pos_button[1].y=272;
pos_button[2].x=332;	pos_button[2].y=338;
pos_button[3].x=142;	pos_button[3].y=439;
	


if (SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Error init video  %s\n",SDL_GetError());
return 1;}

if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
			{printf("%s",Mix_GetError());}
check=Mix_LoadWAV("Check.wav");
OstMenu=Mix_LoadMUS("OstMenu.mp3");



putenv("SDL_Video_Centered=3");
Ecran=SDL_SetVideoMode(961,720,0,SDL_DOUBLEBUF | SDL_HWSURFACE);

posEcran.x=0;
posEcran.y=0;

posBack.x=0;
posBack.y=0;

Mix_PlayMusic(OstMenu,-1);
Background=IMG_Load("Loadnobuttons.jpg");/*
SDL_FillRect(Ecran,NULL,0);					
SDL_BlitSurface(Background,NULL,Ecran,&posBack);*/
/*
for (i=0;i<4;i++)
{SDL_BlitSurface (Button[i],NULL,Background,&pos_button[i]);}
*/

while (done)
{SDL_PollEvent(&event);
		switch (event.type) {			
			case SDL_QUIT : done =0;break;
			case SDL_MOUSEMOTION :for (i=0;i<4;i++)
				{if(event.motion.x >pos_button[i].x && event.motion.x <pos_button[i].x+pos_button[i].w && event.motion.y >pos_button[i].y 
				&& event.motion.y <pos_button[i].y+pos_button[i].h)
				{if (on[i]==0){on[i]=1;Mix_PlayChannel(-1,check,0);
				//SDL_FreeSurface(Button[i]);
				Button[i]=ButtonRed[i] ; 
} }
				else {if (on[i]==1)
					{on[i]=0;//SDL_FreeSurface(Button[i]);
				Button[i]=ButtonBlack[i];}
				}
					
				}}
SDL_BlitSurface(Background,NULL,Ecran,&posBack);
		for (i=0;i<4;i++)
{SDL_BlitSurface (Button[i],NULL,Ecran,&pos_button[i]);}
/*SDL_FillRect(Ecran,NULL,0);*/					

SDL_Flip(Ecran);
}




SDL_FreeSurface(Ecran);
Mix_FreeChunk(check);
TTF_CloseFont(font);
TTF_Quit();
SDL_VideoQuit;
Mix_Quit();
SDL_Quit();

return 1;

}
