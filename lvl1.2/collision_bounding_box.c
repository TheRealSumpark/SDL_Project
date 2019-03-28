#include "collision_bounding_box.h"

int collision(Player hero,enemy e)
{
int collision=1;
if(hero.positiontext.x + hero.positiontext. w< e.positionenemyy. x 
|| hero.positiontext.x> e.positionenemyy. x + e.positionenemyy. w
|| hero.positiontext.y + hero.positiontext.h< e.positionenemyy. y 
|| hero.positiontext.y> e.positionenemyy. y + e.positionenemyy. h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}

int collisionbox(Player hero,objet ob)
{
int collision=1;
if(hero.positiontext.x + hero.positiontext. w< ob.positionobjett. x 
|| hero.positiontext.x> ob.positionobjett. x + ob.positionobjett. w
|| hero.positiontext.y + hero.positiontext.h< ob.positionobjett. y 
|| hero.positiontext.y> ob.positionobjett. y + ob.positionobjett. h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}
