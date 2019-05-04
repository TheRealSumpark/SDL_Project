#ifndef manette_H_INCLUDED
#define manette_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include  "main.h"
int arduinoWriteData(int w);
void arduinoReadData(int *x);
#endif
