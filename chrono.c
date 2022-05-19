#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


///https://forums.commentcamarche.net/forum/affich-15461118-chronometre-en-c-et-precision


void chrono(BITMAP* terrain, BITMAP* buffer)
{
clock_t debut, fin ;
long clk_tck = CLOCKS_PER_SEC ;
double difference ;

int tour=0;

    do
    {
        debut=clock() ;
        do
        {
            fin=clock() ;
            difference = (double)(fin-debut)/(double)clk_tck ;
        }while(difference<15);

        textprintf_ex(terrain,font,50,400,makecol(255,255,255),makecol(255,0,0),"Fin de tour ca fait %.2lf secondes", difference);

        tour++;

    }while(tour<1);

}

