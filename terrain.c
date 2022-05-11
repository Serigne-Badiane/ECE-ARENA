#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void init_struct_case()
{
    matrice_terrain[0][0].hauteur=28;                               ///initialisation des structs : largeur, longueur, pos x, pos y
    matrice_terrain[0][0].largeur=50;
    matrice_terrain[0][0].x=0;
    matrice_terrain[0][0].y=14;
    for (int i=1;i<LIGNE;i++)
    {
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[0][0].x;
        matrice_terrain[i][0].y=matrice_terrain[i-1][0].y+(matrice_terrain[i][0].hauteur);
    }
    int z=1;
    for (int j=1;j<COLONNE;j++)
    {
        matrice_terrain[0][j].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[0][j].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[0][j].x=matrice_terrain[0][j-1].x+(matrice_terrain[0][j].largeur/2);
        if (z==0)
        {
            matrice_terrain[0][j].y=matrice_terrain[0][0].y;
        }
        else
            matrice_terrain[0][j].y=matrice_terrain[0][0].y-(matrice_terrain[0][0].hauteur/2);
        if(z==0)
            z=1;
        else
            z=0;
    }
    for (int i=1;i<LIGNE;i++)
    {
        for(int j=1;j<COLONNE;j++)
        {
            matrice_terrain[i][j].hauteur=matrice_terrain[0][0].hauteur;
            matrice_terrain[i][j].largeur=matrice_terrain[0][0].largeur;
            matrice_terrain[i][j].x=matrice_terrain[i][j-1].x+(matrice_terrain[i][j].largeur/2);
            matrice_terrain[i][j].y=matrice_terrain[i-1][j].y+(matrice_terrain[i][j].hauteur);
        }
    }
    for (int i=0;i<LIGNE;i++)                                                           ///toutes les cases sont considere comme du vide:initialisation
    {                                                                                  /// 0=vide;1=case traversable par le joueur et les attaques
        for(int j=0;j<COLONNE;j++)                                                      ///2=case eau
        {                                                                               ///3=case non traversable
            matrice_terrain[i][j].passage=0;
            matrice_terrain[i][j].passage_attaque=0;

        }
    }
    matrice_terrain[9][19].passage=3;
    matrice_terrain[9][21].passage=3;
    matrice_terrain[14][20].passage=3;
    matrice_terrain[10][20].passage=3;
    matrice_terrain[10][25].passage=3;
    matrice_terrain[14][25].passage=3;
    matrice_terrain[7][24].passage=3;
    matrice_terrain[14][26].passage=3;
    matrice_terrain[12][30].passage=3;
    matrice_terrain[11][30].passage=3;
    matrice_terrain[12][31].passage=3;
    matrice_terrain[12][29].passage=3;
    matrice_terrain[5][27].passage=3;                                                                              ///initialisation des autres cases
}

void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y)
{
    int losange=0, j, j2;
    for(int i=coord_y;i<coord_y+matrice_terrain[0][0].hauteur/2;i++)
    {

        putpixel(buffer,j,i,makecol(0,0,0));
        putpixel(buffer,j2,i,makecol(0,0,0));
        j=coord_x+matrice_terrain[0][0].largeur/2-losange;
        j2=coord_x-matrice_terrain[0][0].largeur/2+losange;
        losange+=2;
    }
    int losange2=0,j3,j4;
    for(int i=coord_y;i>coord_y-matrice_terrain[0][0].hauteur/2;i--)
    {
        putpixel(buffer,j3,i,makecol(0,0,0));
        putpixel(buffer,j4,i,makecol(0,0,0));
        j3=coord_x+matrice_terrain[0][0].largeur/2-losange2;
        j4=coord_x-matrice_terrain[0][0].largeur/2+losange2;
        losange2+=2;
    }
}

void quadrillage(BITMAP* buffer,BITMAP* terrain)
{
    for (int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            case_quadrillage(buffer,terrain,matrice_terrain[i][j].x,matrice_terrain[i][j].y);
        }
    }
}

void case_couleur(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y)
{
    int losange=0;
    for(int i=coord_y;i<coord_y+matrice_terrain[0][0].hauteur/2;i++)
    {
        for(int j=coord_x;j<coord_x+matrice_terrain[0][0].largeur/2-losange;j++)
        {
            putpixel(buffer,j,i,makecol(126-losange/2,247-losange,253-losange*2));
        }
        for(int j=coord_x;j>coord_x-matrice_terrain[0][0].largeur/2+losange;j--)
        {
            putpixel(buffer,j,i,makecol(126-losange/2,247-losange,253-losange*2));
        }
        losange+=2;
    }
    int losange2=0;
    for(int i=coord_y;i>coord_y-matrice_terrain[0][0].hauteur/2;i--)
    {
        for(int j=coord_x;j<coord_x+matrice_terrain[0][0].largeur/2-losange2;j++)
        {
            putpixel(buffer,j,i,makecol(126-losange2/2,247-losange2,253-losange2*2));
        }
        for(int j=coord_x;j>coord_x-matrice_terrain[0][0].largeur/2+losange2;j--)
        {
            putpixel(buffer,j,i,makecol(126-losange2/2,247-losange2,253-losange2*2));
        }
    losange2+=2;
    }
}

void affichage_terrain(BITMAP* terrain, BITMAP* buffer)
{
    blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    /*for(int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            textprintf_ex(buffer,font,matrice_terrain[i][j].x,matrice_terrain[i][j].y,makecol(40,40,40),-1,"l");
        }
    }*/
    //draw_sprite(screen, buffer, 0,0);*/
}
