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
        }
    }
    int losange=0;
    for(int i=11;i<22;i++)
    {

        for(int j=24;j<48-losange;j++)
        {
            matrice_terrain[i][j].passage=1;
        }
        for(int j=24;j>0+losange;j--)
        {
           matrice_terrain[i][j].passage=1;
        }
        losange+=2;
    }
    int losange2=0;
    for(int i=11;i>0;i--)
    {
        for(int j=24;j<45-losange2;j++)
        {
            matrice_terrain[i][j].passage=1;
        }
        for(int j=24;j>5+losange2;j--)
        {
            matrice_terrain[i][j].passage=1;
        }
        losange2+=2;
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
    matrice_terrain[5][27].passage=3;
    matrice_terrain[9][22].passage=2;
    matrice_terrain[8][22].passage=2;
    matrice_terrain[9][23].passage=2;
    matrice_terrain[10][22].passage=2;
    matrice_terrain[10][23].passage=2;
    matrice_terrain[11][22].passage=2;
    matrice_terrain[12][22].passage=2;
    matrice_terrain[11][23].passage=2;
    matrice_terrain[12][23].passage=2;
    matrice_terrain[13][23].passage=2;
    matrice_terrain[12][21].passage=2;
    matrice_terrain[14][23].passage=2;
    matrice_terrain[14][24].passage=2;
    matrice_terrain[13][24].passage=2;
    matrice_terrain[12][24].passage=2;
    matrice_terrain[11][24].passage=2;
    matrice_terrain[10][24].passage=2;
    for(int i=8;i<18;i++)
    {
        for(int j=35;j<48;j++)
        {
            matrice_terrain[i][j].passage=0;
        }
    }
    for(int i=10;i<16;i++)
    {
        for(int j=1;j<10;j++)
        {
            matrice_terrain[i][j].passage=0;
        }
    }
    matrice_terrain[12][9].passage=1;
    matrice_terrain[13][35].passage=1;
    matrice_terrain[12][35].passage=1;
    matrice_terrain[11][35].passage=1;
    matrice_terrain[8][35].passage=1;
    matrice_terrain[12][36].passage=1;
    matrice_terrain[11][36].passage=1;
    matrice_terrain[11][37].passage=1;
    matrice_terrain[12][37].passage=1;
    matrice_terrain[10][10].passage=0;
    matrice_terrain[13][10].passage=0;
    matrice_terrain[14][10].passage=0;
    matrice_terrain[15][10].passage=0;
    matrice_terrain[14][11].passage=0;
    matrice_terrain[15][11].passage=0;
    matrice_terrain[16][11].passage=0;
    matrice_terrain[14][12].passage=0;
    matrice_terrain[15][12].passage=0;
    matrice_terrain[16][12].passage=0;
    matrice_terrain[15][13].passage=0;
    matrice_terrain[16][15].passage=0;
    matrice_terrain[17][15].passage=0;
    matrice_terrain[16][16].passage=0;
    matrice_terrain[17][16].passage=0;
    matrice_terrain[17][17].passage=0;
    matrice_terrain[18][17].passage=0;
    matrice_terrain[7][15].passage=0;
    matrice_terrain[7][16].passage=0;
    matrice_terrain[1][24].passage=0;
    matrice_terrain[4][22].passage=0;
    matrice_terrain[5][21].passage=0;
    matrice_terrain[19][18].passage=0;
    matrice_terrain[19][19].passage=0;
    matrice_terrain[19][20].passage=0;
    matrice_terrain[20][19].passage=0;
    matrice_terrain[20][20].passage=0;
    matrice_terrain[20][21].passage=0;
    matrice_terrain[21][22].passage=0;
    matrice_terrain[18][20].passage=0;
    matrice_terrain[21][21].passage=0;
    matrice_terrain[21][24].passage=0;
    matrice_terrain[21][25].passage=0;
    matrice_terrain[21][26].passage=0;
    matrice_terrain[18][26].passage=0;
    matrice_terrain[18][27].passage=0;
    matrice_terrain[18][28].passage=0;
    matrice_terrain[18][29].passage=0;
    matrice_terrain[18][30].passage=0;
    matrice_terrain[18][31].passage=0;
    matrice_terrain[17][31].passage=0;
    matrice_terrain[16][31].passage=0;
    matrice_terrain[16][32].passage=0;
    matrice_terrain[16][30].passage=0;
    matrice_terrain[17][30].passage=0;
    matrice_terrain[19][27].passage=0;
    matrice_terrain[17][28].passage=0;
    matrice_terrain[19][28].passage=0;
    matrice_terrain[17][29].passage=0;
    matrice_terrain[19][29].passage=0;
    matrice_terrain[17][34].passage=0;;
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
}
