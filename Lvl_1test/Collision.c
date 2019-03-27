
#include "Collision.h"



int Collision_Ennemi(SDL_Rect Pos_perso,Ennemi Mob)
{int collision=0;
float rayon_objet,rayon_perso,D1,D2;

SDL_Rect centre_perso;
centre_perso.x=Pos_perso.x+(Pos_perso.w/2);
centre_perso.y=Pos_perso.y+(Pos_perso.h/2);

SDL_Rect centre;
centre.x=Mob.Pos_Ennemi.x+(Mob.Pos_Ennemi.w/2);
centre.y=Mob.Pos_Ennemi.y+(Mob.Pos_Ennemi.h/2);




rayon_objet=sqrt (pow((Mob.Pos_Ennemi.w/2),2)+pow((Mob.Pos_Ennemi.h/2),2))/2;
rayon_perso=sqrt (pow((Pos_perso.w/2),2)+pow((Pos_perso.h/2),2))/2.5;

D1=sqrt (pow(centre.x-centre_perso.x,2) + pow(centre.y-centre_perso.y,2));
D2=rayon_objet+rayon_perso;

if (D2>=D1)
{collision=1;}

return collision;

}
