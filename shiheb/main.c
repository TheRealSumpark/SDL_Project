int main()
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen, *background, *perso, *obstacle;
        perso = IMG_Load("submarine.png");
        background = IMG_Load("bg1.png");
        obstacle = IMG_Load("bg2.png");
        SDL_Rect position_perso;
        screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);

        int speed = 2,i=1;

  
        camera.w = 800;
        camera.h = 640;
        position_perso.x=200;
        position_perso.y=280;

        SDL_Event event;

        SDL_WM_SetCaption("Stage-chaima", NULL);
        SDL_EnableKeyRepeat(100, 100);
    
        SDL_Color couleur;

      
///////////////////////////////////////////// Boucle bich yebda el Stage  /////////////////////////////////////////////

        while(i != 0) {
                  //fazatet ta3 cam
                        set_camera(position_perso,perso); // tgued lcam
                        SDL_BlitSurface(background, &camera, screen, NULL); // affiche bg
                        fazzaa(position_perso,perso,screen); // teb3 collision //feha el Blit ta3 perso
                        collision(obstacle,&position_perso,perso); // collision 
                        
                        position_perso.x += speed; // vitesse deplacement perso
                        position_perso.y += 1 ; // graviteeeeee


                        SDL_Flip(screen); 
                        if (position_perso.x > 9995) {return 1;} // traja3 1 ki terba7 stage

///////////////////////////////////////////// Fazet les evenements ?? /////////////////////////////////////////////
                        SDL_PollEvent(&event);
                               switch(event.type)
                                        {
                                          case SDL_KEYDOWN :
                                                switch(event.key.keysym.sym)
                                                {    
                                                        case SDLK_ESCAPE:
                                                                i = 0;
                                                          break;   

                                                      case SDLK_UP :
                                                        if (position_perso.y > 200) 
							{position_perso.y -= 3;}
                                                      break;
                                                      
                                                    case SDLK_DOWN :
                                                      
                                                      position_perso.y += 3;
                                                    break; 
                                                  }
                                          break;                                                  
                                        } 
 
 
      
               }            

        SDL_FreeSurface(obstacle);
        SDL_FreeSurface(background);
        SDL_FreeSurface(screen);
        SDL_FreeSurface(perso);
        SDL_Quit();
        return 0;
}
