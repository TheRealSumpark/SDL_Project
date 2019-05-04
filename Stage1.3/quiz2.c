void init_images ()
{
   char im_sol[100];
    char im_no[100];
       char im_yes[100];
       char im4[100], im1[100], im2[100], im3[100];
    SDL_Surface *image1 = NULL;
    SDL_Rect positionFond1;
    positionFond1.x =  0 ;
    positionFond1.y =  0 ;
    SDL_Surface *image_no = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    image_no= IMG_Load("no.png");
    sprintf(im_sol,"solu/%d.png",d);
    image= IMG_Load(im_sol);
    SDL_Surface *image_yes = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im_yes,"welldone.png");
    image_yes= IMG_Load(im_yes);
    SDL_Surface *image_quiz = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im_no,"quiz/%d.png",d);
    image_quiz= IMG_Load(im_no);
    
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"reponse/%d.png",d);
    image= IMG_Load(im);
    sprintf(im1,"reponse/%d/1.png",d);
    sprintf(im2,"reponse/%d/2.png",d);
    sprintf(im3,"reponse/%d/3.png",d);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);

}
void solution(SDL_Surface *ecran,int d)
{
     SDL_BlitSurface(image_no,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(3000);
	 SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void good (SDL_Surface *ecran)
{
 SDL_BlitSurface(image_yes,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}
void quiz(SDL_Surface *ecran,int d)
{
	SDL_BlitSurface(image_quiz,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}
void reponse(SDL_Surface *ecran,int d)
{
    SDL_Event event;
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    int continuer =1;
    int i=0;



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
               {
             case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && d%3==1)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==2 && d%3==2)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==3 && d%3==0)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,d);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,ecran,&positionim);
        SDL_Flip(ecran);
    }


}
