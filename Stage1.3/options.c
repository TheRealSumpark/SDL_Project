#include "options.h"
typedef struct _CouleurRGBg_
{
 Uint8 r;
 Uint8 g; // Ici c'est une structure de r,g,b de type couleur
 Uint8 b;
} _Couleur_g;

Uint32 SDL_LireCouleurAuxg(SDL_Surface* surface, int x, int y)
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

int get_positiong(_Couleur_g couleur){
	
	if (couleur.r == 21 && couleur.g == 193 && couleur.b == 206)
		return 1;
	if (couleur.r == 218 && couleur.g == 255 && couleur.b == 64)
		return 2;
	if (couleur.r == 255 && couleur.g == 29 && couleur.b == 250)
		return 3;
	if (couleur.r == 255 && couleur.g == 113 && couleur.b == 85)
		return 4;

	return -1;
}


_Couleur_g SDL_LireCouleurg(SDL_Surface * surface, int x, int y)
{
    _Couleur_g couleur;
    SDL_GetRGB(SDL_LireCouleurAuxg(surface, x, y), surface->format,
               (Uint8*)   &couleur.r, (Uint8*) &couleur.g, (Uint8*) &couleur.b);
    return couleur;
}



void choix_options(SDL_Surface *ecran)
{
FILE *f = fopen("idea1","w");
_Couleur_g couleur ;
int continuer=1,i_audio=1,retour=0,i_menu=1,verif_audio=3,current_volume=MIX_MAX_VOLUME;
SDL_Rect posschoix_options;
SDL_Event event;
posschoix_options.x = 0;
posschoix_options.y = 0;
SDL_Surface *choix_options=NULL,*oppos =NULL;
oppos=SDL_LoadBMP("oppos.bmp");
Mix_Chunk* check;
check=Mix_LoadWAV("Check.wav");
FILE *fichier=NULL;
const SDL_VideoInfo* myPointer = SDL_GetVideoInfo();
choix_options=SDL_LoadBMP("op1.bmp");
SDL_BlitSurface(choix_options,NULL,ecran,&posschoix_options);
SDL_Flip(ecran);
//SDL_EnableKeyRepeat(100, 100);

while (continuer)
{
SDL_WaitEvent(&event);

switch (event.type){
case SDL_QUIT : exit(1);break;

case SDL_MOUSEMOTION :	
	SDL_LockSurface(oppos);
	couleur=SDL_LireCouleurg(oppos,(event.motion.x),	(event.motion.y)); 
	SDL_LockSurface(oppos);
	retour = get_positiong(couleur);
	if (retour!=-1)
	{i_audio=retour;}
	switch (i_audio)
	{case 1:Mix_PlayChannel(-1, check,0);break;
	case 2:Mix_PlayChannel(-1, check,0);break;
	case 3:Mix_PlayChannel(-1, check,0);break;
	case 4:Mix_PlayChannel(-1, check,0);break;
	}break;
	
	
break;
case SDL_MOUSEBUTTONUP :
		switch (i_audio){
		case 1 : verif_audio=1;current_volume=Mix_VolumeMusic(0); break;
		case 2 : verif_audio=2;  if (current_volume==0) 
		{current_volume=Mix_VolumeMusic(current_volume+32);}
		else 
		{current_volume=Mix_VolumeMusic(current_volume-64);}break;
		case 3 : verif_audio=3;	
		if (current_volume==MIX_MAX_VOLUME) 
		{current_volume=Mix_VolumeMusic(current_volume-32);}
		else 
		{current_volume=Mix_VolumeMusic(current_volume+64);} break;
		case 4 : verif_audio=4;current_volume=Mix_VolumeMusic(MIX_MAX_VOLUME);break;
		}
case SDL_KEYDOWN :
switch (event.key.keysym.sym){

case SDLK_ESCAPE :Nettoyer_choix_options(choix_options);
main(ecran);
break;
case SDLK_BACKSPACE :
fichier=fopen("SAVE.txt","w");
fprintf(fichier,"%d\n",verif_audio);
fclose(fichier);
break;

case SDLK_UP :Mix_PlayChannel(-1, check,0);

if (i_audio==1){
i_audio=4;
}
else{
i_audio--;}
break;
case SDLK_DOWN :Mix_PlayChannel(-1, check,0);
if (i_audio==4){
i_audio=1;
}
else{
i_audio++;
}
break;
case SDLK_RIGHT :Mix_PlayChannel(-1, check,0);
switch(i_audio)
{
case 1: i_audio=3;break;
case 2:	i_audio=4;break;
case 3:	i_audio=1;break;
case 4:	i_audio=2;break;
}
break;
case SDLK_LEFT : Mix_PlayChannel(-1, check,0);

switch(i_audio)
{
case 1: i_audio=3;break;
case 2:	i_audio=4;break;
case 3:	i_audio=1;break;
case 4:	i_audio=2;break;
}
break;
case SDLK_RETURN :
switch (i_audio){
case 1 :
// Audio muet
verif_audio=1;current_volume=Mix_VolumeMusic(0);
break;
case 2 :
// audio normal
verif_audio=2;  if (current_volume==0) 
		{current_volume=Mix_VolumeMusic(current_volume+32);}
		else 
		{current_volume=Mix_VolumeMusic(current_volume-64);}
break;
case 3 :
// audio moyen
verif_audio=3;	
		if (current_volume==MIX_MAX_VOLUME) 
		{current_volume=Mix_VolumeMusic(current_volume-32);}
		else 
		{current_volume=Mix_VolumeMusic(current_volume+64);}
break;
case 4 :
// audio max
verif_audio=4;current_volume=Mix_VolumeMusic(MIX_MAX_VOLUME);
break;
}
break;
}
break;
}
switch (i_audio){
case 1 : 
	choix_options=SDL_LoadBMP("op1.bmp");break;
case 2 :
	choix_options=SDL_LoadBMP("op2.bmp");break;
case 3 : 
	choix_options=SDL_LoadBMP("op3.bmp");break;
case 4 :
	choix_options=SDL_LoadBMP("op4.bmp");break;
}
SDL_BlitSurface(choix_options,NULL,ecran,&posschoix_options);
SDL_Flip(ecran);
}

SDL_FreeSurface(choix_options);
Mix_FreeChunk(check);
SDL_FreeSurface(oppos);
Mix_Quit();
}

void Nettoyer_choix_options(SDL_Surface *choix_options)
{
SDL_FreeSurface(choix_options);
}

