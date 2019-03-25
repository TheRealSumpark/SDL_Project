#include "Init_Ennemi.h"



Ennemi Init_Ennemi()
{Ennemi Mob ;
	Mob.Anim_Ennemi=IMG_Load("mob.png");
	Mob.Pos_Ennemi.x=500;
	Mob.Pos_Ennemi.y=200;
	Mob.Pos_Ennemi.h=Mob.Anim_Ennemi->h;
	Mob.Pos_Ennemi.w=Mob.Anim_Ennemi->w;
	return Mob;
	
	}
					
