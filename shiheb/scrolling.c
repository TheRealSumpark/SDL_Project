#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
SDL_Rect camera;
SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y) 
 {
  SDL_Color color;
  Uint32 col = 0 ;

  //determine position
  char* pPosition = ( char* ) pSurface->pixels ;

  //offset by y
  pPosition += ( pSurface->pitch * y ) ;

  //offset by x
  pPosition += ( pSurface->format->BytesPerPixel * x ) ;

  //copy pixel data
  memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

  //convert color
  SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
  return ( color ) ;
}

/////////////////////////////////////////SCROLLING///////////////////////////////////////////// 


void set_camera(SDL_Rect j,SDL_Surface *img){
  camera.x = (j.x + img->w / 2) - 400;
  camera.y = (j.y + img->h / 2) - 640;
  if (camera.x < 0){
    camera.x = 0;
  }
  if (camera.x > 9196)
  {
    camera.x = 9196;
  }
  if (camera.y < 0){
    camera.y = 0;
  }
  if (camera.y > 640 - camera.y){
    camera.y = 640 - camera.y;
  }
}





void collision(SDL_Surface *obstacle, SDL_Rect *position_perso, SDL_Surface *perso){
    
    SDL_Color c = GetPixel(obstacle, position_perso->x + perso->w/2, position_perso->y);
    SDL_Color c2 = GetPixel(obstacle, position_perso->x + perso->w/2, position_perso->y + perso->h);
    SDL_Color c3 = GetPixel(obstacle, position_perso->x + perso->w, position_perso->y + perso->h/2);

    if(c.r == 255 && c.g == 255 && c.b ==255){
        printf("Try again !!Try again !!Try again !!Try again !!\n");
        position_perso->x=150;
        position_perso->y=28;
    }
    if(c2.r == 255 && c2.g == 255 && c2.b ==255){
        
        printf("Try again !!Try again !!Try again !!Try again !!\n");
        position_perso->x=150;
        position_perso->y=280;
    }
    if(c3.r == 255 && c3.g == 255 && c3.b ==255){
        
        printf("Try again !!Try again !!Try again !!Try again !!\n");
        position_perso->x=150;
        position_perso->y=280;
    }     
}
 void fazzaa(SDL_Rect position_perso,SDL_Surface *perso, SDL_Surface *screen){
                      
                  
                        SDL_Rect fcam;
                        fcam.x = position_perso.x - camera.x;
                        fcam.y = position_perso.y - camera.y;
                       
                        SDL_BlitSurface(perso, NULL, screen, &fcam); //affiche perso
 }
