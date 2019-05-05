#include "input.h"
typedef struct _CouleurRGBg_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_g;

Uint32 SDL_LireCouleurAuxg1(SDL_Surface* surface, int x, int y)
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

int get_positiong1(_Couleur_g couleur){
	
	if (couleur.r == 56 && couleur.g == 40 && couleur.b == 81)
		return 1;
	if (couleur.r == 223 && couleur.g == 153 && couleur.b == 95)
		return 2;
	

	return -1;
}


_Couleur_g SDL_LireCouleurg1(SDL_Surface * surface, int x, int y)
{
    _Couleur_g couleur;
    SDL_GetRGB(SDL_LireCouleurAuxg1(surface, x, y), surface->format,
               (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
    return couleur;
}



int choix_input(SDL_Surface *ecran)
{
FILE *f = fopen("idea2","w");
_Couleur_g couleur ;
int continuer=1,i_input=1,retour=0,i_menu=1,verif_input;
SDL_Rect posschoix_input;
SDL_Event event;
posschoix_input.x = 0;
posschoix_input.y = 0;
SDL_Surface *choix_input=NULL,*colisinput =NULL;
colisinput=IMG_Load("input.png");
Mix_Chunk* check;
check=Mix_LoadWAV("Check.wav");
FILE *fichier=NULL;
const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
choix_input=IMG_Load("input.png");
SDL_BlitSurface(choix_input,NULL,ecran,&posschoix_input);
SDL_Flip(ecran);
//SDL_EnableKeyRepeat(100, 100);

while (continuer)
{
SDL_WaitEvent(&event);

switch (event.type)
{
case SDL_QUIT : exit(1);break;

case SDL_MOUSEMOTION :	
	SDL_LockSurface(colisinput);
	couleur=SDL_LireCouleurg1(colisinput,(event.motion.x),	(event.motion.y)); 
	SDL_LockSurface(colisinput);
	retour = get_positiong1(couleur);
	if (retour!=-1)
	{i_input=retour;}
	switch (i_input)
	{case 1:Mix_PlayChannel(-1, check,0);break;
	case 2:Mix_PlayChannel(-1, check,0);break;
	
	}break;
	
	
break;
case SDL_MOUSEBUTTONUP :
		switch (i_input){
		case 1 : verif_input=1; break;
		case 2 : verif_input=2;break;
		}
case SDL_KEYDOWN :
switch (event.key.keysym.sym){

/*case SDLK_ESCAPE :Nettoyer_choix_input(choix_input);
main(ecran);
continuer=0; 
break;*/
case SDLK_BACKSPACE :
fichier=fopen("SAVE1.txt","w");
fprintf(fichier,"%d\n",verif_input);
fclose(fichier);
break;

case SDLK_RIGHT: Mix_PlayChannel(-1, check,0);

switch(i_input)
{
case 1: i_input=2;break;
case 2:	i_input=1;break;

}
break;
case SDLK_LEFT : Mix_PlayChannel(-1, check,0);

switch(i_input)
{
case 1: i_input=2;break;
case 2:	i_input=1;break;

}
break;
case SDLK_RETURN :
switch (i_input){
case 1 :

verif_input=1;
break;
case 2 :

verif_input=2;  
break;

}
break;
}
break;
}
switch (i_input){
case 1 : 
	choix_input=IMG_Load("input2.png");break;
case 2 :
	choix_input=IMG_Load("input3.png");break;

}
SDL_BlitSurface(choix_input,NULL,ecran,&posschoix_input);
SDL_Flip(ecran);
}

SDL_FreeSurface(choix_input);
Mix_FreeChunk(check);
SDL_FreeSurface(colisinput);
Mix_Quit();
return verif_input ;
}

void Nettoyer_choix_input(SDL_Surface *choix_input)
{
SDL_FreeSurface(choix_input);
}

