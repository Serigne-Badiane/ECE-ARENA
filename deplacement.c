#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void deplacement(BITMAP* terrain, BITMAP* buffer)
{
    //rectfill(buffer,150,150,250,250, makecol(0,255,255));

    BITMAP* image_joueur[4];

    int nombre_joueurs=1;
    int var;
    for (var=0; var<nombre_joueurs; var++)
    {
        image_joueur[var] = load_bitmap("perso1.bmp", NULL);
        if (image_joueur[var]==NULL)
        {
            allegro_message("Pas d'image");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for (var=0; var<nombre_joueurs; var++)
    {
        blit(image_joueur[var], buffer, 0 ,0, matrice_terrain[2][3].x, matrice_terrain[2][3].y, SCREEN_W, SCREEN_H);        //variable de placement initiale a mettre
    }

}
