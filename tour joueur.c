#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void tour(BITMAP* buffer, int nbrjoueur, int tour_joueur)
{
    BITMAP* image_joueur[4];

    image_joueur[0] = load_bitmap("tour/1.bmp", NULL);
    image_joueur[1] = load_bitmap("tour/2.bmp", NULL);
    image_joueur[2] = load_bitmap("tour/3.bmp", NULL);
    image_joueur[3] = load_bitmap("tour/4.bmp", NULL);

    BITMAP* fleche;
    fleche = load_bitmap("tour/fleche_tour.bmp", NULL);

    for(int k=0; k<4; k++)
    {
        if (image_joueur[k]==NULL)
        {
            allegro_message("Pas l'image %d", k);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }


    for(int k=0; k<nbrjoueur; k++)
    {
        blit(image_joueur[joueur[k].classe], buffer, 0,0, 1000+k*55, 10, image_joueur[joueur[k].classe]->w, image_joueur[joueur[k].classe]->h);
    }

    masked_blit(fleche, buffer, 0,0, 1010+tour_joueur*55, 70, fleche->w, fleche->h);
}

void barre_de_vie(BITMAP* buffer, int nbrjoueur, int tour_joueur)
{
    int degats=0;

    for(int i=0; i<nbrjoueur; i++)
    {
        degats=200-joueur[i].pv;
        rectfill(buffer, 1000+55*i, 60, (1000+55*i+(joueur[i].pv/4))-(degats/30), 65, makecol(255,0,0));
    }
}

void attaque(BITMAP*buffer, int k)
{
    BITMAP* image_joueur[20];

    image_joueur[0] = load_bitmap("player/player1.bmp", NULL);
    image_joueur[1] = load_bitmap("player/player2.bmp", NULL);
    image_joueur[2] = load_bitmap("player/player3.bmp", NULL);
    image_joueur[3] = load_bitmap("player/player4.bmp", NULL);
    image_joueur[4] = load_bitmap("player/player5.bmp", NULL);
    image_joueur[5] = load_bitmap("player/player6.bmp", NULL);
    image_joueur[6] = load_bitmap("player/player7.bmp", NULL);
    image_joueur[7] = load_bitmap("player/player8.bmp", NULL);
    image_joueur[8] = load_bitmap("player/player9.bmp", NULL);
    image_joueur[9] = load_bitmap("player/player10.bmp", NULL);
    image_joueur[10] = load_bitmap("player/player11.bmp", NULL);
    image_joueur[11] = load_bitmap("player/player12.bmp", NULL);
    image_joueur[12] = load_bitmap("player/player13.bmp", NULL);
    image_joueur[13] = load_bitmap("player/player14.bmp", NULL);
    image_joueur[14] = load_bitmap("player/player15.bmp", NULL);
    image_joueur[15] = load_bitmap("player/player16.bmp", NULL);
    image_joueur[16] = load_bitmap("player/player17.bmp", NULL);
    image_joueur[17] = load_bitmap("player/player18.bmp", NULL);
    image_joueur[18] = load_bitmap("player/player19.bmp", NULL);
    image_joueur[19] = load_bitmap("player/player20.bmp", NULL);

    BITMAP *imgneg[4];

    imgneg[0]=create_bitmap(image_joueur[0]->w,image_joueur[0]->h);
    imgneg[1]=create_bitmap(image_joueur[5]->w,image_joueur[5]->h);
    imgneg[2]=create_bitmap(image_joueur[10]->w,image_joueur[10]->h);
    imgneg[3]=create_bitmap(image_joueur[15]->w,image_joueur[15]->h);

    for (int y=0;y<image_joueur[0]->h;y++)
    {
        for (int x=0;x<image_joueur[0]->w;x++)
        {
            putpixel(imgneg,x,y,makecol(255,0,0));
        }
    }
    masked_blit(imgneg[0],buffer,0,0,matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].x-imgneg[0]->w/2, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].y-imgneg[0]->h, imgneg[0]->w, imgneg[0]->h);
}
