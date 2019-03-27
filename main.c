#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "main.h"
typedef struct _CouleurRGB_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_;

Uint32 SDL_LireCouleurAux(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp)
    {
    case 1:
        return *p;
    case 2:
        return *(Uint16 *)p;
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
    case 4:
        return *(Uint32 *)p;
    default:
        return 0;
    }
}


int get_position(_Couleur_ couleur){
	
	if (couleur.r == 255 && couleur.g == 0 && couleur.b == 0)
		return 1;
	if (couleur.r == 255 && couleur.g == 255 && couleur.b == 0)
		return 2;
	if (couleur.r == 0 && couleur.g == 255 && couleur.b == 0)
		return 3;
	if (couleur.r == 0 && couleur.g == 0 && couleur.b == 255)
		return 4;

	return -1;
}


_Couleur_ SDL_LireCouleur(SDL_Surface * surface, int x, int y)
{
    _Couleur_ couleur;
    SDL_GetRGB(SDL_LireCouleurAux(surface, x, y), surface->format,
               (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
    return couleur;
}

void main(SDL_Surface *ecran)
{

	FILE *f = fopen("idea","w");
	_Couleur_ couleur;

	SDL_Surface *background = NULL, *backgroundCollision = NULL, *text= NULL;

	Mix_Chunk *check;
	Mix_Music *musique;

	SDL_Rect positionBackground;
	SDL_Rect positiontext;
	SDL_Event event;

	positionBackground.x = 0;
	positionBackground.y = 0;
	
	positiontext.x=9;
	positiontext.y=350;

	
	SDL_Init(SDL_INIT_VIDEO);

	TTF_Font *police = NULL;
	SDL_Color couleurblanc = {255, 255, 255};
	TTF_Init();

	ecran = SDL_SetVideoMode(560, 450, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("MENU", NULL);
	
	SDL_EnableKeyRepeat(0,0);

	int continuer = 1, i = 1;

	background = SDL_LoadBMP("image1.0.bmp");
	
	backgroundCollision = SDL_LoadBMP("COLLIS.bmp");

	police = TTF_OpenFont("Book Antiqua.ttf", 48);
	text = TTF_RenderText_Blended(police, "Esprit",couleurblanc);

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
		printf("%s", Mix_GetError());
	}

	//Mix_AllocateChannels(32);
	musique = Mix_LoadMUS("OstMenu.mp3");
	check =Mix_LoadWAV("check.wav");
	
	Mix_PlayChannel(-1, check,10);
	Mix_PlayMusic(musique, -1);

	do {
	
	SDL_WaitEvent(&event);
	switch (event.type){
		
		case SDL_QUIT : 
		continuer = 0;
		break;
		
		case SDL_MOUSEMOTION:
		SDL_LockSurface(backgroundCollision);
        	couleur=SDL_LireCouleur(backgroundCollision,(event.motion.x),(event.motion.y));
		SDL_LockSurface(backgroundCollision);
		//fprintf(f, "X = %d, Y = %d pixel : [ %d %d %d ], i = %d", event.button.x, event.button.y,couleur.r,couleur.g,couleur.b,get_position(couleur)); Ceci est un fichier de test.
		i = get_position(couleur);		
		break;

		case SDL_MOUSEBUTTONUP :
		switch (i){
		case 1 : /*CALL NEXT FUNCTION*/break;
		case 2 : /*CALL NEXT FUNCTION*/break;
		case 3 : /*CALL NEXT FUNCTION*/break;
		case 4 : continuer=0;break;
		}
		break;
				
		case SDL_KEYUP : 
		switch (event.key.keysym.sym){
		
		case SDLK_RETURN : 
		switch (i){
		case 1 : /*CALL NEXT FUNCTION*/break;
		case 2 : /*CALL NEXT FUNCTION*/break;
		case 3 : choix_options(ecran); break;
		case 4 : continuer=0; break;
		}	
		break;		

		case SDLK_UP : 
		if (i==1) {
			i = 4;		
		}
		else
			i--;
		break;
		
		case SDLK_DOWN :
		if (i==4) {
			i = 1;		
		}
		else
			i++;
		break;
		}
			}

		switch (i){
		case 1 : 
		background = SDL_LoadBMP("image1.0.bmp");
	
			
		break;
		case 2 : 
		background = SDL_LoadBMP("image2.0.bmp");
		
		break;
		case 3 :
		background = SDL_LoadBMP("image3.0.bmp");
				
		break;
		case 4 : 
		background = SDL_LoadBMP("image4.0.bmp");
		
		break;		
		}
		/*if(i==1){
		}

		if(i==2){check = Mix_LoadWAV("check.wav");
		Mix_PlayChannel(-1,check,0);
		}

		if(i==3){check = Mix_LoadWAV("check.wav");
		Mix_PlayChannel(-1,check,0);
		}

		if(i==4){check = Mix_LoadWAV("check.wav");
		Mix_PlayChannel(-1,check,0);
		}*/



	
	
	SDL_BlitSurface(background, NULL, ecran, &positionBackground);
	SDL_Flip(ecran);

	
	
	
	SDL_BlitSurface(background, NULL, ecran, &positionBackground);
	SDL_Flip(ecran);

	
	SDL_BlitSurface(text, NULL, ecran, &positiontext);
	SDL_Flip(ecran);


	}while(continuer);

	SDL_FreeSurface(background);
	Mix_FreeChunk(check);
	SDL_FreeSurface(backgroundCollision);
	SDL_Quit();
	fclose(f);

	//return EXIT_SUCCESS;
}



