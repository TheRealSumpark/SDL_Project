#include "collision_bounding_box.h"

int collision(SDL_Surface *p,SDL_Surface *e,SDL_Rect perso,SDL_Rect enemy)
{
int collision=0;
if(perso.x < enemy.x + e->w 
&&perso.x + p->w > enemy.x 
&&perso.y < enemy.y + e->h 
&&p->h + perso.y > enemy.y)
{
collision=1;
}
else{
collision=0;
}
return collision;
}

int collisionbox(SDL_Surface *p,SDL_Surface *o,SDL_Rect perso,SDL_Rect objet)
{
int collision=1;
if(perso.x + p->w < objet.x 
|| perso.x> objet.x + o->w
|| perso.y + p->h < objet.y 
|| perso.y > objet.y + o->h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}
