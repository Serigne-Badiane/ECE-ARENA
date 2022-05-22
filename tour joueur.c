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

void barre_de_vie(BITMAP* buffer, int nbrjoueur, int tour_joueur)               ///ce sspg crée une barre de vie en dessous des images des joueurs (en haut)
{
    int degats=0;

    for(int i=0; i<nbrjoueur; i++)
    {
        degats=200-joueur[i].pv;
        rectfill(buffer, 1000+55*i, 60, (1000+55*i+(joueur[i].pv/4))-(degats/30), 65, makecol(255,0,0));
    }
}

void attaque(BITMAP*buffer, int k)              ///ce sspg colorie en rouge le joueur quand il prend des dêgats
{
    BITMAP* image_joueur;

    image_joueur = load_bitmap("player/player1.bmp", NULL);

    BITMAP *imgneg;

    imgneg=create_bitmap(image_joueur->w,image_joueur->h);

    for (int y=0;y<image_joueur->h;y++)
    {
        for (int x=0;x<image_joueur->w;x++)
        {
            putpixel(imgneg,x,y,makecol(255,0,0));
        }
    }
    blit(imgneg,buffer,0,0,matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].x-imgneg->w/2, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].y-imgneg->h, imgneg->w, imgneg->h);

    //textprintf_ex(buffer,font,matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].x-(imgneg->w/2)+50, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].y-imgneg->h,makecol(255,255,255),makecol(153,217,234),"-%d", degats);

}
