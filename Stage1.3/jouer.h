#ifndef JOUER_H_INCLUDED
#define JOUER_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collision_bounding_box.h"
//#include "perso.h"
#include "Init_Ennemi.h"
#include "Afficher_Ennemi.h"
#include "mvtaleatoire.h"
#include "Ennemi.h"
#include "main.h"
#include "Collision_trigo.h"
//#include "Perfect_Collision.h"
#include "quiz.h"
//#include "vitesse_acceleration.h"
#include <SDL/SDL_rotozoom.h>


typedef struct 
{

int X;
int Y;

}Coordinate;


typedef struct 
{
 
SDL_Surface *image;
SDL_Rect positionecran;
Mix_Music *music;
SDL_Rect camera;
	
}background;

typedef enum 
{
ATTACK,
IDLE,
WALK,
}Etat;


typedef enum
{
UP,
DOWN,
RIGHT,
LEFT,
}Direction;

typedef struct Player
{	
	SDL_Surface *perso;
    	SDL_Rect Pos_perso;
	SDL_Surface *perso_mv_right[5];
	SDL_Surface *perso_idle[2];
	SDL_Surface *perso_attack_right[5];
	SDL_Surface *perso_mv_left[5];
	SDL_Surface *perso_attack_left[5];
	SDL_Rect positionHealth;
	SDL_Surface *Player_Health[3];
	int nmb_mv;
	int nmb_attack;
	int P_health;
	int vitesse ;
	int ACCELERATION ;
	int status;
    	float vx,vy;
}Player;

typedef struct EO
{
	SDL_Surface *objett;
	SDL_Surface *surf1;
    	SDL_Rect positionsurf1;
	SDL_Rect positionobjett;
}EO;


typedef struct
{
	SDL_Surface *Border;
	SDL_Surface *Overview;
	SDL_Rect Pos;


}Map;


void initialiser (background *b);
void afficher (SDL_Surface *ecran , background *b ) ;
Player Initial_personnage();
Player Initial_personnage2();
void event_handler(SDL_Event event,Direction *Sens ,Etat *State,int *keysHeld);
void deplacement(Direction Sens,Etat State,Player *hero,int *keysHeld,int *frametime1 ,int nmb1_frame,int *frame1,Uint8* keys,int collision);
void Saute(Player *hero,float impulsion);
void ControleSol(Player *hero);
void Gravite(Player *hero,float factgravite,float factsautmaintenu,Uint8* keys);
void Afficher_perso(Player hero,int vie,SDL_Surface *ecran);
void Animer_Personnage(int *frametime ,int *frame,Player *hero,Direction *Sens ,Etat *State);
void Initial_objet(EO *ob,EO *clef,EO *porte,EO *piste);
void afficherobjet(EO *ob,EO *clef,EO *porte,EO *piste,SDL_Surface *ecran,background *b);
void scrolling (background *b,SDL_Surface *ecran,Direction Sens,Etat State);
int collision(SDL_Surface *p,SDL_Surface *e,SDL_Rect perso,SDL_Rect enemy);
int collisionbox(SDL_Surface *p,SDL_Surface *o,SDL_Rect perso,SDL_Rect objet);
int collisionall(EO *ob,EO clef,EO porte,EO piste,Player *hero,int *vie,int *score,Direction Sens,Etat State,Ennemi Mob[], Coordinate C,SDL_Surface *Background);
int Collision_Ennemi(SDL_Rect Pos_perso,Ennemi Mob);
Ennemi Init_Ennemi(char  Mob_Name[],int X , int Y);
void Afficher_Ennemi(Ennemi Mob,SDL_Surface *ecran);
void mvtaleatoire (Ennemi *mob , int max , int min  );
void enigme(int d,SDL_Surface *ecran);
void reponse(SDL_Surface *ecran,int d);
void solution(SDL_Surface *ecran,int d);
void quiz(SDL_Surface *ecran,int d);
void good(SDL_Surface *ecran);
//void Vitesse(Direction Sens,Etat State,Player *hero);
void jouer(SDL_Surface *ecran);
void Nettoyer_stage(background * b);
int arduinoWriteData(int w);
void arduinoReadData(int *x);
void Rotozoom(SDL_Surface * ecran, background b,EO clef, double *angle);
void Mini_map(SDL_Surface* ecran,Map M);
void Manette(Etat * State ,Direction * Sens);
#endif
