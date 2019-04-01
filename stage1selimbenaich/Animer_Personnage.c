#include "Animer_Personnage.h"



int Animer_Personnage(int *frametime ,int nmb_frame,int frame )
{
int FPS=60;

							if (FPS/(*frametime)==5)
							{(*frametime)=0;
							frame++;
							if (frame==nmb_frame)
							{frame=0;}}
							return frame;
}

