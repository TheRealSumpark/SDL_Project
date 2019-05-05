#include "saving.h"
typedef struct _CouleurRGBg_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_g;

Uint32 SDL_LireCouleurAuxg2(SDL_Surface* surface, int x, int y)
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

int get_positiong2(_Couleur_g couleur){
	
	if (couleur.r == 0 && couleur.g == 78 && couleur.b == 127)
		return 1; 
	
	if (couleur.r == 72 && couleur.g == 126 && couleur.b == 192 )
		return 2; 
	

	return -1;
}


_Couleur_g SDL_LireCouleurg2(SDL_Surface * surface, int x, int y)
{
    _Couleur_g couleur;
    SDL_GetRGB(SDL_LireCouleurAuxg2(surface, x, y), surface->format,
               (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
    return couleur;
}

int saving (SDL_Surface *ecran)
{
FILE *f = fopen("idea3","w");
_Couleur_g couleur ;
int continuer=1,i_load=1,retour=0,i_menu=1,verif_load=2 ;
SDL_Rect posschoix_load;
SDL_Event event;
posschoix_load.x = 0;
posschoix_load.y = 0;
SDL_Surface *choix_load=NULL,/**input =NULL ,*/ *colisload=NULL ;
colisload=IMG_Load("colisload.png");
Mix_Chunk* check;
check=Mix_LoadWAV("Check.wav");
FILE *fichier=NULL;
const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
choix_load=IMG_Load("load.png");
SDL_BlitSurface(choix_load,NULL,ecran,&posschoix_load);
SDL_Flip(ecran);
//SDL_EnableKeyRepeat(100, 100);
while (continuer)
{
SDL_WaitEvent(&event);

switch (event.type){
case SDL_QUIT : exit(1);break;

case SDL_MOUSEMOTION :	
	SDL_LockSurface(colisload);
	couleur=SDL_LireCouleurg2(colisload,(event.motion.x),(event.motion.y)); 
	SDL_LockSurface(colisload);
	retour = get_positiong2(couleur);
	if (retour!=-1)

	{i_quit=retour;}
	switch (i_load)
	{case 1:Mix_PlayChannel(-1, check,0);break;
	case 2:Mix_PlayChannel(-1, check,0);break;
	
	
	}break;
	
	
break;

case SDL_MOUSEBUTTONUP :

		switch (i_load){
		case 1 : verif_load =1 ;
	          break;
		case 2 :verif_load=2 ; SDL_FreeSurface(ecran); SDL_Quit(); break;
		
		
		}
case SDL_KEYDOWN :
switch (event.key.keysym.sym){



case SDLK_RIGHT :Mix_PlayChannel(-1, check,0);
switch(i_load)
{
case 1: i_load=2;break;
case 2:	i_load=1;break;
/*case 3:	i_input=1;break;*/

}
break;
case SDLK_LEFT : Mix_PlayChannel(-1, check,0);

switch(i_load)
{
case 1: i_load=2;break;
case 2:	i_load=1;break;


}
break;
case SDLK_RETURN :
switch (i_quit){
case 1 : verif_load=1; /* save	*/ break ;
case 2 : verif_load=2 ; /* quitter */ break ;

}
break;
}
break;
}
switch (i_load){
case 1 : 
	choix_load=IMG_Load("loadyes.png");break;
case 2 :
	choix_load=IMG_Load("loadno.png");break;

}
SDL_BlitSurface(choix_load,NULL,ecran,&posschoix_load);
SDL_Flip(ecran);
}

SDL_FreeSurface(choix_load);
Mix_FreeChunk(check);
SDL_FreeSurface(colisload);
Mix_Quit();
return verif_load ;
}
void Nettoyer_quit(SDL_Surface *choix_load)
{
SDL_FreeSurface(choix_load);
}


