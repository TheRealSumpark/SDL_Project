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

void main(SDL_Surface *screen)
{	

	//Ennemii Slime;
	//Slime=Init_Ennemi1();	
	anim Wind;
	Wind=Init_Anim();
	
	
	FILE *f = fopen("idea","w");
	_Couleur_ couleur;

	SDL_Surface *background = NULL, *backgroundCollision = NULL, *text= NULL, *ecran;
	
	
	
	
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Music *musique;
	Mix_Chunk *check;
	SDL_Rect positionBackground;
	SDL_Rect positiontext;
	SDL_Event event;
	
	
	positionBackground.x = 800;
	positionBackground.y = 600;
	
	positiontext.x=9;
	positiontext.y=510;

	
	

	/*TTF_Font *police = NULL;
	SDL_Color couleurblanc = {255, 255, 255};
	TTF_Init();*/
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(800,600, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("MENU", NULL);

	int continuer = 1, localisation = 1,frame1=0,retour,frame3=0;
	float frame=0,frame2=0;
	background = SDL_LoadBMP("image1.0.bmp");
	
	backgroundCollision = SDL_LoadBMP("COLLIS.bmp");

	/*police = TTF_OpenFont("Book Antiqua.ttf", 48);
	text = TTF_RenderText_Blended(police, "Esprit",couleurblanc);*/

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
		printf("%s", Mix_GetError());
	}

	//Mix_AllocateChannels(32);
	musique = Mix_LoadMUS("OstMenu.mp3");
	check =Mix_LoadWAV("Check.wav");
	
	
	Mix_PlayMusic(musique, -1);
	
	//SDL_EnableKeyRepeat(100,100);

	do{
	//SDL_WaitEvent(&event);
	SDL_PollEvent(&event);

	switch (event.type){
		
		case SDL_QUIT : 
		continuer = 0;
		break;
		
		case SDL_MOUSEMOTION:
		SDL_LockSurface(backgroundCollision);
        	couleur=SDL_LireCouleur(backgroundCollision,(event.motion.x),(event.motion.y));
		SDL_LockSurface(backgroundCollision);
		retour= get_position(couleur);
		if (retour!=-1)
		{localisation=retour;}
		switch (localisation)
		{case 1: Mix_PlayChannel(0, check,0);break;
		case 2:Mix_PlayChannel(0, check,0);break;
		case 3:Mix_PlayChannel(0, check,0);break;
		case 4:Mix_PlayChannel(0, check,0);break;}
		
		
		
		break;
		
		case SDL_MOUSEBUTTONUP :
		switch (localisation){
		case 1 :/*CALL NEXT FUNCTION*/Nettoyer(background);jouer(ecran);break;
		case 2 :/*CALL NEXT FUNCTION*/break;
		case 3 :Nettoyer(background);choix_options(screen); break;
		case 4 :  continuer=0;break;
		}
		break;
	
		case SDL_KEYDOWN : 
		switch (event.key.keysym.sym){
		case SDLK_RETURN : 
		switch (localisation){
		case 1 : /*CALL NEXT FUNCTION*/Nettoyer(background);jouer(ecran);break;
		case 2 : /*CALL NEXT FUNCTION*/break;
		case 3 : Nettoyer(background);  choix_options(screen);  break;
		case 4 :  exit(1); break;
		}	
		break;		

		case SDLK_UP : Mix_PlayChannel(0, check,0);
		if (localisation==1) {
			localisation = 4;		
		}
		else
			localisation--;
		break;
		
		case SDLK_DOWN :Mix_PlayChannel(0, check,0);
		if (localisation==4) {
			localisation = 1;		
		}
		else
			localisation++;
		break;
		}
			}

		switch (localisation){
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
		frame+=0.1;
		frame2+=0.2;
		
		if (frame <22)
			{frame1=frame;}
		if (frame>22)
		{frame1 =frame=0;}
		
		
		/*if (frame2<47)
		{frame3=frame2;}*/
		/*if (frame2>47)
		{frame2=frame3=0;}
		printf("%d",frame3);*/
		SDL_BlitSurface(background, NULL, screen, NULL);
		//SDL_BlitSurface(Slime.Anim_Ennemi[frame3],NULL,screen,NULL);
		SDL_BlitSurface (Wind.Anim[frame1],NULL,screen,NULL);
		
		
		//SDL_BlitSurface(text, NULL, screen, &positiontext);
		/*Animation_Speed*/
		SDL_Flip(screen);
		}while(continuer);
		
		SDL_FreeSurface(background);
		SDL_FreeSurface(screen);
		Mix_FreeChunk(check);
		Mix_FreeMusic(musique);
		SDL_FreeSurface (Wind.Anim[22]);
		//SDL_FreeSurface(Slime.Anim_Ennemi[48]);
		
		SDL_FreeSurface(backgroundCollision);
		fclose(f);
		Mix_Quit();
		SDL_Quit();
}

void Nettoyer(SDL_Surface *background)
{
		SDL_FreeSurface(background);
}

anim Init_Anim()
{	SDL_Surface * wind[22];
int i ;
anim Wind ;
	wind[0]=IMG_Load("wind/wind1.png");	
	wind[1]=IMG_Load("wind/wind2.png");
	wind[2]=IMG_Load("wind/wind3.png");
	wind[3]=IMG_Load("wind/wind4.png");
	wind[4]=IMG_Load("wind/wind5.png");
	wind[5]=IMG_Load("wind/wind6.png");
	wind[6]=IMG_Load("wind/wind7.png");
	wind[7]=IMG_Load("wind/wind8.png");
	wind[8]=IMG_Load("wind/wind9.png");
	wind[9]=IMG_Load("wind/wind10.png");
	wind[10]=IMG_Load("wind/wind11.png");
	wind[11]=IMG_Load("wind/wind12.png");
	wind[12]=IMG_Load("wind/wind13.png");
	wind[13]=IMG_Load("wind/wind14.png");
	wind[14]=IMG_Load("wind/wind15.png");
	wind[15]=IMG_Load("wind/wind16.png");
	wind[16]=IMG_Load("wind/wind17.png");
	wind[17]=IMG_Load("wind/wind18.png");
	wind[18]=IMG_Load("wind/wind19.png");
	wind[19]=IMG_Load("wind/wind10.png");
	wind[20]=IMG_Load("wind/wind21.png");
	wind[21]=IMG_Load("wind/wind22.png");	
	for (i=0;i<22;i++)
	{Wind.Anim[i]=wind[i];}
		return Wind;
}


