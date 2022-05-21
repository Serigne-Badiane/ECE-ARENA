#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void init_struct_case(int nbre_joueurs)                                                         ///sspg qui initialise toutes les cases
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

    matrice_terrain_iso[0][0].x=matrice_terrain[12][4].x;                                                               ///initialisation des positions x et y de chaque case iso
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
    }                                                                                                                                               ///fin

    for (int i=0;i<LIGNE2;i++)                                                                                                                 ///initialisation de la possibilite de passer � travers cette case
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
    matrice_terrain_iso[12][8].passage=2;                                                                                                       ///fin
    for (int i=6;i<9;i++)                                                                                                       ///permet d'afficher les cases sur lesquels le joueur peut se placer
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
            if (nbre_joueurs==3 || nbre_joueurs==4)
            {
                matrice_terrain_iso[i][j].placement_debut=2;
            }
        }
    }
    for (int i=15;i<18;i++)
    {
        for (int j=2;j<5;j++)
        {
            if (nbre_joueurs==3 || nbre_joueurs==4)
            {
                matrice_terrain_iso[i][j].placement_debut=3;
            }
            if (nbre_joueurs==2)
            {
                matrice_terrain_iso[i][j].placement_debut=2;
            }
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=6;j<9;j++)
        {
            if (nbre_joueurs==4)
            {
                matrice_terrain_iso[i][j].placement_debut=4;
            }
        }
    }                                                                                                                                       ///fin
}

void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y)                   ///sspg qui � partir de deux coordonn�es (x,y) cr�e un losange autour de celles-ci
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

void quadrillage(BITMAP* buffer,BITMAP* terrain)                                                ///sspg qui quadrille toute la map (on appel le sspg pr�c�dent)
{                                                                                               ///extr�mement utile lors de la conception (il est possible de quadriller ou non la map)
    for (int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            case_quadrillage(buffer,terrain,matrice_terrain[i][j].x,matrice_terrain[i][j].y);
        }
    }
}

void case_couleur(BITMAP* buffer,int coord_x,int coord_y,float r,float v,float b)               ///sspg qui � partir de deux coordonn�es (x,y) cr�e un losange remplit (la couleur du losange est pass�e en param�tre)
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

void terrain_couleur(BITMAP* buffer)                                                            ///sspg qui cr�er un buffer (buffer_invisible_couleur) pour lequel chaque case est d'une couleur diff�rente.
{                                                                                               ///utile pour se d�placer (rep�rer sur quel case se trouve la souris)
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

void affichage_terrain(BITMAP* terrain, BITMAP* buffer)                                         ///sspg qui transmet au buffer la bitmap du terrain (nous aurions pu ne pas cr�er ce sspg)
{
    blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
}

void recuperation_couleur(BITMAP* buffer, BITMAP* buffer_enlevage_indication)                   ///sspg qui transmet � un buffer l'image d'un autre buffer
{                                                                                               ///on utilise ce sspg avec celui d'en dessous pour permettre d'effacer les traces d'une indication donn�e au joueur
    blit(buffer,buffer_enlevage_indication,0,0,0,0,SCREEN_W,SCREEN_H);                          ///par exemple, avec ce sspg on efface les indications des cases sur lesquels les joueurs vont se placer au debut de partie
}

void enlevage_des_indications(BITMAP* buffer,BITMAP* buffer_enlevage_indication)                ///fait la meme chose que le sspg au-dessus
{                                                                                               ///ce sspg n'�tait pas n�cessaire (nous aurions pu utiliser celui du dessus en inversant les bitmaps en param�tre)
    blit(buffer_enlevage_indication,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
}

void bonus (BITMAP* buffer)
{
    BITMAP* pnj_bitmap = load_bitmap("ronaldo.bmp",NULL);
    if(pnj.pos.case_ligne_iso==0 && pnj.pos.case_colonne_iso==0)
    {
        pnj.pos.case_ligne_iso=rand()%(21);
        pnj.pos.case_colonne_iso=rand()%(22);
        while(matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].passage!=1)
        {
            pnj.pos.case_ligne_iso=rand()%(21);
            pnj.pos.case_colonne_iso=rand()%(22);
        }
    }
    if (joueur[tourjoueur].pos.case_ligne_iso == pnj.pos.case_ligne_iso && joueur[tourjoueur].pos.case_colonne_iso== pnj.pos.case_colonne_iso)
    {
        pnj.pos.case_ligne_iso=rand()%(21);
        pnj.pos.case_colonne_iso=rand()%(22);
        while(matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].passage!=1)
        {
            pnj.pos.case_ligne_iso=rand()%(21);
            pnj.pos.case_colonne_iso=rand()%(22);
        }
        int choix_bonus=rand()%(3-1)+1;
        if (choix_bonus==1)
        {
            joueur[tourjoueur].pv+=rand()%(30-15)+15;
        }
        if (choix_bonus==2)
        {
            joueur[tourjoueur].pa+=rand()%(8-1)+1;
        }
        if (choix_bonus==3)
        {
            joueur[tourjoueur].pm+=rand()%(4-1)+1;
        }
    }
    masked_blit(pnj_bitmap, buffer, 0 ,0, matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].x-pnj_bitmap->w/2, matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].y-pnj_bitmap->h, pnj_bitmap->w, pnj_bitmap->h);
    masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}
