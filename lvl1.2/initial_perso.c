#include "initial_perso.h"

Player Initial_personnage()
{
Player hero;
hero.surf=IMG_Load("1.png");
hero.positiontext.x=30;
hero.positiontext.y=440;
hero.positiontext.h=hero.surf->h;
hero.positiontext.w=hero.surf->w;
return hero;
}
