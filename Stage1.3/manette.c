#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "manette.h"
int arduinoWriteData(int w)
{
    char chemin[]="/dev/ttyACM0";
    FILE *f;

    f=fopen(chemin,"w");
    if(f == NULL){
        return(-1);}

    fprintf(f,"%d",w);
    fclose(f);

    return(0);
}

void arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE *f;
   
    f=fopen(chemin,"r");

    if(f == NULL){
        exit(0);}

    fscanf(f,"%d",x);
    fclose(f);
}
