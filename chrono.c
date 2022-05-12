#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


///METTRE SOURCE

void chrono(BITMAP* terrain, BITMAP* buffer)
{
    int h, min, s, day, mois, an;
    time_t now;

    // Renvoie l'heure actuelle
    time(&now);

    struct tm *local = localtime(&now);
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;
    textprintf_ex(terrain,font,800,0,makecol(0,255,0),makecol(0,0,0),"Temps de jeu : %02d\n",s);
    int s2;


    if(s%15==0 )
    {
        s=0;            ///fin tour
    }
    else
    {

    }

    textprintf_ex(terrain,font,800,30,makecol(0,255,0),makecol(0,0,0),"Temps de jeu : %02d\n",s);
}
