#include "Init_Ennemi.h"
#include  "main.h"


Ennemi Init_Ennemi(char Mob_Name[], int X , int Y)
{Ennemi Mob ;
	Mob.Anim_Ennemi=IMG_Load(Mob_Name);
	Mob.Pos_Ennemi.x=X;
	Mob.Pos_Ennemi.y=Y;
	Mob.Pos_Ennemi.h=Mob.Anim_Ennemi->h;
	Mob.Pos_Ennemi.w=Mob.Anim_Ennemi->w;
	Mob.direction =1;
	return Mob;
	}
					
