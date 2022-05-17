#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void placement_joueur_debut(BITMAP*buffer,BITMAP*buffer_couleur, BITMAP* buffer_enlevage_indication,int nb_joueur)
{
    recuperation_couleur(buffer,buffer_enlevage_indication);
    for(int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            switch(matrice_terrain[i][j].placement_debut)
            {
                case 1:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,100,100);
                    break;
                case 2:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,170,100);
                    break;
                case 3:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,100,170);
                    break;
                case 4:
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,170,100,100);
                    break;
            }
        }
    }

    for(int a=0;a<nb_joueur;a++)
    {
        while(joueur[a].pos.case_ligne_iso==0 || joueur[a].pos.case_colonne_iso==0)
        {
            for(int i=0;i<LIGNE2;i++)
            {
                for(int j=0;j<COLONNE2;j++)
                {
                    if (getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y)) && mouse_b & 1)
                    {
                        if (matrice_terrain_iso[i][j].placement_debut==a+1 && matrice_terrain_iso[i][j].passage==1)
                        {
                            case_couleur(buffer, matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,40,150,78);
                            joueur[a].pos.case_ligne_iso=i;
                            joueur[a].pos.x = matrice_terrain_iso[i][j].x;
                            joueur[a].pos.y = matrice_terrain_iso[i][j].y;
                            joueur[a].pos.case_colonne_iso=j;
                            while (mouse_b & 1)                 ///blindage click gauche
                            {
                                rest(150);
                            }
                        }
                    }
                }
            }
            draw_sprite(screen, buffer, 0,0);
        }
    }
    enlevage_des_indications(buffer,buffer_enlevage_indication);
}

void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* buffer_couleur,int tour_joueur,BITMAP* buffer_vrai, BITMAP* buffer_enlevage_indication,int c,BITMAP*buffer_deplacement2)
{
    if (c==0)
    {
        recuperation_couleur(terrain, buffer_enlevage_indication);
        recuperation_couleur(buffer,buffer_deplacement2);
    }
    int i=joueur[tour_joueur].pos.case_ligne_iso;
    int p=joueur[tour_joueur].pos.case_colonne_iso;

    if(joueur[tour_joueur].pm==3)
    {

    }

    if(joueur[tour_joueur].pm==2)
    {

    }
    if(joueur[tour_joueur].pm==1)
    {
        if(matrice_terrain[i][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain[i][p+1].x, matrice_terrain[i][p+1].y, 140,140,140);
        }
        if(matrice_terrain[i][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain[i][p-1].x, matrice_terrain[i][p-1].y, 140,140,140);
        }
        if(matrice_terrain[i+1][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain[i+1][p-1].x, matrice_terrain[i+1][p-1].y, 140,140,140);
        }
        if(matrice_terrain[i+1][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain[i+1][p+1].x, matrice_terrain[i][p+1].y, 140,140,140);
        }
    }
}

void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur,int tour_joueur,BITMAP*buffer_deplacement, BITMAP* buffer_enlevage_indication, BITMAP* buffer_deplacement2, int nbr_joueur)
{
    BITMAP* image_joueur[32];

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
    for (int s=0;s<nbr_joueur;s++)
    {
        blit(image_joueur[2], buffer, 0 ,0, matrice_terrain[joueur[s].pos.case_ligne][joueur[s].pos.case_colonne].x-image_joueur[2]->w/2, matrice_terrain[joueur[s].pos.case_ligne][joueur[s].pos.case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
    }
        for(int i=0;i<LIGNE;i++)
        {
            for(int t=0; t<COLONNE; t++)
            {
                if (getr(getpixel(buffer_deplacement,mouse_x,mouse_y))==140 && getb(getpixel(buffer_deplacement,mouse_x,mouse_y))==140 && getg(getpixel(buffer_deplacement,mouse_x,mouse_y))==140 && mouse_b&1)
                {
                    if(getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain[i][t].x,matrice_terrain[i][t].y)))
                    {
                    /*while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].y<matrice_terrain[i][t].y)
                    {
                        matrice_terrain[play[j].case_ligne][play[j].case_colonne].y+=matrice_terrain[0][0].hauteur;
                        blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                        rest(300);
                    }
                    while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].x<matrice_terrain[i][t].x)
                    {
                        matrice_terrain[play[j].case_ligne][play[j].case_colonne].x+=matrice_terrain[0][0].largeur;
                        blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                        rest(200);
                    }
                    while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].y>matrice_terrain[i][t].y)
                    {
                        matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-=matrice_terrain[0][0].hauteur;
                        blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                        rest(200);
                    }
                    while(matrice_terrain[play[j].case_ligne][play[j].case_colonne].x>matrice_terrain[i][t].x)
                    {
                        matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-=matrice_terrain[0][0].largeur;
                        blit(image_joueur[2], terrain, 0 ,0, matrice_terrain[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                        rest(200);
                    }*/
                    enlevage_des_indications(buffer, buffer_enlevage_indication);
                    enlevage_des_indications(buffer_deplacement,buffer_deplacement2);
                    blit(image_joueur[2], buffer, 0 ,0, matrice_terrain[i][t].x-image_joueur[2]->w/2, matrice_terrain[i][t].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                    joueur[tour_joueur].pos.case_ligne=i;
                    joueur[tour_joueur].pos.case_colonne=t;
                    joueur[tour_joueur].pos.x = matrice_terrain[i][t].x;
                    joueur[tour_joueur].pos.y = matrice_terrain[i][t].y;
                    }
                }
            }
        }

}
