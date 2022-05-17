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
    for (int i=1;i<LIGNE;i++)                                       ///d'abord colonne 0 car on utilise i-1 pour initialiser i
    {                                                               ///si i=1 i-1=0 et donc doit etre initialiser auparavant
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[0][0].x;
        matrice_terrain[i][0].y=matrice_terrain[i-1][0].y+(matrice_terrain[i][0].hauteur);
    }
    int z=1;
    for (int j=1;j<COLONNE;j++)                                   ///pareil pour la ligne 0
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
    for (int i=1;i<LIGNE;i++)                                               ///initialisation de toutes les autres cases
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
    matrice_terrain[17][34].passage=0;                                                       ///fin initialisation du passage

    matrice_terrain[6][30].placement_debut=1;                                              ///debut initialisation pour le placement au depart
    matrice_terrain[7][30].placement_debut=1;                                             ///1=j1;2=j2...
    matrice_terrain[7][31].placement_debut=1;                                            ///joueur1
    matrice_terrain[6][31].placement_debut=1;
    matrice_terrain[6][29].placement_debut=1;
    matrice_terrain[7][29].placement_debut=1;
    matrice_terrain[6][28].placement_debut=1;
    matrice_terrain[6][32].placement_debut=1;
    matrice_terrain[5][30].placement_debut=1;

    matrice_terrain[19][23].placement_debut=2;                                              ///joueur 2
    matrice_terrain[19][24].placement_debut=2;
    matrice_terrain[19][22].placement_debut=2;
    matrice_terrain[18][23].placement_debut=2;
    matrice_terrain[18][22].placement_debut=2;
    matrice_terrain[18][24].placement_debut=2;
    matrice_terrain[19][25].placement_debut=2;
    matrice_terrain[19][21].placement_debut=2;
    matrice_terrain[20][23].placement_debut=2;

    matrice_terrain[14][32].placement_debut=3;                                              ///joueur 3
    matrice_terrain[14][33].placement_debut=3;
    matrice_terrain[14][34].placement_debut=3;
    matrice_terrain[14][31].placement_debut=3;
    matrice_terrain[14][30].placement_debut=3;
    matrice_terrain[13][32].placement_debut=3;
    matrice_terrain[15][32].placement_debut=3;
    matrice_terrain[15][31].placement_debut=3;
    matrice_terrain[15][33].placement_debut=3;

    matrice_terrain[9][12].placement_debut=4;                                              ///joueur 4
    matrice_terrain[9][13].placement_debut=4;
    matrice_terrain[9][14].placement_debut=4;
    matrice_terrain[9][11].placement_debut=4;
    matrice_terrain[9][10].placement_debut=4;
    matrice_terrain[8][12].placement_debut=4;
    matrice_terrain[10][12].placement_debut=4;
    matrice_terrain[10][11].placement_debut=4;
    matrice_terrain[10][13].placement_debut=4;

    matrice_terrain_iso[0][0].x=matrice_terrain[12][4].x;
    matrice_terrain_iso[0][0].y=matrice_terrain[12][4].y;
    for (int i=1;i<COLONNE2;i++)
    {
        matrice_terrain_iso[0][i].x = matrice_terrain_iso[0][i-1].x+matrice_terrain[0][0].largeur/2;
        matrice_terrain_iso[0][i].y = matrice_terrain_iso[0][i-1].y-matrice_terrain[0][0].hauteur/2;
    }
    for (int i=1;i<LIGNE2;i++)
    {
        for (int j=0;j<COLONNE2;j++)
        {
            matrice_terrain_iso[i][j].x = matrice_terrain_iso[i-1][j].x+matrice_terrain[0][0].largeur/2;
            matrice_terrain_iso[i][j].y = matrice_terrain_iso[i-1][j].y+matrice_terrain[0][0].hauteur/2;
        }
    }
    for (int i=0;i<LIGNE2;i++)
    {
        for (int j=0;j<COLONNE2;j++)
        {
            matrice_terrain_iso[i][j].passage=1;
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<6;j++)
        {
            matrice_terrain_iso[i][j].passage=0;
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<3;j++)
        {
            matrice_terrain_iso[i][j].passage=0;
        }
    }
    matrice_terrain_iso[8][0].passage=0;
    matrice_terrain_iso[10][1].passage=0;
    matrice_terrain_iso[11][1].passage=0;
    matrice_terrain_iso[12][1].passage=0;
    matrice_terrain_iso[10][2].passage=0;
    matrice_terrain_iso[11][2].passage=0;
    matrice_terrain_iso[9][2].passage=0;
    matrice_terrain_iso[14][2].passage=0;
    matrice_terrain_iso[14][1].passage=0;
    matrice_terrain_iso[15][1].passage=0;
    matrice_terrain_iso[16][1].passage=0;
    matrice_terrain_iso[19][1].passage=0;
    matrice_terrain_iso[20][1].passage=0;
    matrice_terrain_iso[19][2].passage=0;
    matrice_terrain_iso[20][2].passage=0;
    for (int i=14;i<LIGNE2;i++)
    {
        matrice_terrain_iso[i][0].passage=0;
    }
    matrice_terrain_iso[0][11].passage=0;
    matrice_terrain_iso[1][11].passage=0;
    matrice_terrain_iso[1][16].passage=0;
    matrice_terrain_iso[1][17].passage=0;
    for (int i=17;i<20;i++)
    {
        for (int j=5;j<11;j++)
        {
             matrice_terrain_iso[i][j].passage=0;
        }
    }
    matrice_terrain_iso[19][9].passage=1;
    matrice_terrain_iso[19][10].passage=1;
    matrice_terrain_iso[13][18].passage=0;
    matrice_terrain_iso[14][18].passage=0;
    matrice_terrain_iso[16][18].passage=0;
    for (int i=12;i<LIGNE2;i++)
    {
        for (int j=19;j<COLONNE2;j++)
        {
            matrice_terrain_iso[i][j].passage=0;
        }
    }
    for (int i=17;i<LIGNE2;i++)
    {
        for (int j=14;j<COLONNE2;j++)
        {
            matrice_terrain_iso[i][j].passage=0;
        }
    }
    for (int i=10;i<COLONNE2;i++)
    {
        matrice_terrain_iso[LIGNE2-1][i].passage=0;
    }
    matrice_terrain_iso[LIGNE2-2][12].passage=0;
    matrice_terrain_iso[LIGNE2-2][13].passage=0;
    matrice_terrain_iso[LIGNE2-3][13].passage=0;
    matrice_terrain_iso[4][11].passage=3;
    matrice_terrain_iso[5][15].passage=3;
    matrice_terrain_iso[6][10].passage=3;
    matrice_terrain_iso[5][12].passage=3;
    matrice_terrain_iso[10][6].passage=3;
    matrice_terrain_iso[12][9].passage=3;
    matrice_terrain_iso[12][13].passage=3;
    matrice_terrain_iso[12][14].passage=3;
    matrice_terrain_iso[13][13].passage=3;
    matrice_terrain_iso[13][14].passage=3;
    matrice_terrain_iso[4][19].passage=3;
    matrice_terrain_iso[8][13].passage=3;
    matrice_terrain_iso[5][13].passage=2;
    matrice_terrain_iso[6][13].passage=2;
    matrice_terrain_iso[6][12].passage=2;
    matrice_terrain_iso[7][12].passage=2;
    matrice_terrain_iso[8][12].passage=2;
    matrice_terrain_iso[7][11].passage=2;
    for (int i=8;i<10;i++)
    {
        for (int j=9;j<12;j++)
        {
            matrice_terrain_iso[i][j].passage=2;
        }
    }
    matrice_terrain_iso[10][9].passage=2;
    matrice_terrain_iso[10][10].passage=2;
    matrice_terrain_iso[11][9].passage=2;
    matrice_terrain_iso[11][8].passage=2;
    matrice_terrain_iso[12][8].passage=2;
    for (int i=6;i<9;i++)
    {
        for (int j=18;j<21;j++)
        {
            matrice_terrain_iso[i][j].placement_debut=1;
        }
    }
    for (int i=15;i<18;i++)
    {
        for (int j=11;j<14;j++)
        {
            matrice_terrain_iso[i][j].placement_debut=2;
        }
    }
    for (int i=15;i<18;i++)
    {
        for (int j=2;j<5;j++)
        {
            matrice_terrain_iso[i][j].placement_debut=3;
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=6;j<9;j++)
        {
            matrice_terrain_iso[i][j].placement_debut=4;
        }
    }


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

void case_couleur(BITMAP* buffer,int coord_x,int coord_y,float r,float v,float b)
{
    int losange=0;
    for(int i=coord_y;i<coord_y+matrice_terrain[0][0].hauteur/2;i++)
    {
        for(int j=coord_x;j<coord_x+matrice_terrain[0][0].largeur/2-losange;j++)
        {
            putpixel(buffer,j,i,makecol(r,v,b));
        }
        for(int j=coord_x;j>coord_x-matrice_terrain[0][0].largeur/2+losange;j--)
        {
            putpixel(buffer,j,i,makecol(r,v,b));
        }
        losange+=2;
    }
    int losange2=0;
    for(int i=coord_y;i>coord_y-matrice_terrain[0][0].hauteur/2;i--)
    {
        for(int j=coord_x;j<coord_x+matrice_terrain[0][0].largeur/2-losange2;j++)
        {
            putpixel(buffer,j,i,makecol(r,v,b));
        }
        for(int j=coord_x;j>coord_x-matrice_terrain[0][0].largeur/2+losange2;j--)
        {
            putpixel(buffer,j,i,makecol(r,v,b));
        }
    losange2+=2;
    }
}

void terrain_couleur(BITMAP* buffer)
{
    float r=40,v=40,b=40;
    for(int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,r,v,b);
            r+=1;
            v+=0.1;
            b+=0.1;
        }
    }
}

void affichage_terrain(BITMAP* terrain, BITMAP* buffer)
{
    blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
}

void recuperation_couleur(BITMAP* buffer, BITMAP* buffer_enlevage_indication)
{
    blit(buffer,buffer_enlevage_indication,0,0,0,0,SCREEN_W,SCREEN_H);
}

void enlevage_des_indications(BITMAP* buffer,BITMAP* buffer_enlevage_indication)
{
    blit(buffer_enlevage_indication,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
}
