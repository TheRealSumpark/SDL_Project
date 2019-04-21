#include  "main.h"

void Initial_objet(EO *ob,EO *clef,EO *porte,EO *piste)
{

	/*ob[0].camera1.x=0;
	ob[0].camera1.y=0;
	ob[0].camera1.w=100;
	ob[0].camera1.h=200;

	ob[1].camera1.x=0;
	ob[1].camera1.y=0;
	ob[1].camera1.w=333;
	ob[1].camera1.h=458;
	
	ob[2].camera1.x=0;
	ob[2].camera1.y=0;
	ob[2].camera1.w=782;
	ob[2].camera1.h=124;

 	ob[3].camera1.x=0;
	ob[3].camera1.y=0;
	ob[3].camera1.w=523;
	ob[3].camera1.h=245;

	ob[4].camera1.x=0;
	ob[4].camera1.y=0;
	ob[4].camera1.w=694;
	ob[4].camera1.h=321;
	
	ob[5].camera1.x=0;
	ob[5].camera1.y=0;
	ob[5].camera1.w=487;
	ob[5].camera1.h=234;

	ob[6].camera1.x=0;
	ob[6].camera1.y=0;
	ob[6].camera1.w=532;
	ob[6].camera1.h=520;*/

	ob[0].objett=IMG_Load("ob1.png");
	ob[0].positionobjett.x=1030;
	ob[0].positionobjett.y=350;
	ob[0].positionobjett.h=ob[0].objett->h;
	ob[0].positionobjett.w=ob[0].objett->w;
	
	ob[1].objett=IMG_Load("ob2.png");
	ob[1].positionobjett.x=520;
	ob[1].positionobjett.y=227;
	ob[1].positionobjett.h=ob[1].objett->h;
	ob[1].positionobjett.w=ob[1].objett->w;

	ob[2].objett=IMG_Load("ob3.png");
	ob[2].positionobjett.x=270;
	ob[2].positionobjett.y=400;
	ob[2].positionobjett.h=ob[2].objett->h;
	ob[2].positionobjett.w=ob[2].objett->w;

	ob[3].objett=IMG_Load("ob4.png");
	ob[3].positionobjett.x=540;
	ob[3].positionobjett.y=514;
	ob[3].positionobjett.h=ob[3].objett->h;
	ob[3].positionobjett.w=ob[3].objett->w;

	ob[4].objett=IMG_Load("ob5.png");
	ob[4].positionobjett.x=470;
	ob[4].positionobjett.y=575;
	ob[4].positionobjett.h=ob[4].objett->h;
	ob[4].positionobjett.w=ob[4].objett->w;

	ob[5].objett=IMG_Load("ob6.png");
	ob[5].positionobjett.x=5;
	ob[5].positionobjett.y=300;
	ob[5].positionobjett.h=ob[5].objett->h;
	ob[5].positionobjett.w=ob[5].objett->w;

	ob[6].objett=IMG_Load("ob7.png");
	ob[6].positionobjett.x=830;
	ob[6].positionobjett.y=569;
	ob[6].positionobjett.h=ob[6].objett->h;
	ob[6].positionobjett.w=ob[6].objett->w;
	
	clef->objett=IMG_Load("clef.png");
	clef->positionobjett.x=1590;
	clef->positionobjett.y=540;
	clef->positionobjett.h=clef->objett->h;
	clef->positionobjett.w=clef->objett->w;

	porte->objett=IMG_Load("porte.png");
	porte->positionobjett.x=1661;
	porte->positionobjett.y=433;
	porte->positionobjett.h=porte->objett->h;
	porte->positionobjett.w=porte->objett->w;

	piste->objett=IMG_Load("piste.png");
	piste->positionobjett.x=0;
	piste->positionobjett.y=634;
	piste->positionobjett.h=piste->objett->h;
	piste->positionobjett.w=piste->objett->w;
}
