#include "initial_perso.h"

Player Initial_personnage()
{
int i;
Player hero;
hero.surf=IMG_Load("clef.png");
hero.positiontext.x=145;
hero.positiontext.y=535;
hero.positiontext.h=hero.surf->h;
hero.positiontext.w=hero.surf->w;
hero.Player_Animation.Mouvement[0]=IMG_Load("1.png");	
hero.Player_Animation.Mouvement[1]=IMG_Load("2.png");
hero.Player_Animation.Mouvement[2]=IMG_Load("3.png");
hero.Player_Animation.Mouvement[3]=IMG_Load("4.png");
return hero;
}
