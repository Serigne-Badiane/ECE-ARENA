#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void case_chemin_verticale(int pos_x, int pos_y, BITMAP* buffer, BITMAP* chemin)
{
    int changement_couleur[3], couleur_pixel;
    blit(chemin,buffer,0,0,pos_x+matrice_terrain[0][0].largeur/4,pos_y,SCREEN_H,SCREEN_W);
    for(int i=0;i<chemin->w;i++)
    {
        for(int j=0;j<chemin->h;j++)
        {
            couleur_pixel= getpixel(chemin,i,j);
            changement_couleur[0]=getr(couleur_pixel);
            changement_couleur[1]=getb(couleur_pixel);
            changement_couleur[2]=getg(couleur_pixel);
            if (changement_couleur[0]>200 && changement_couleur[0]<220 && changement_couleur[1]>80 && changement_couleur[1]<130 && changement_couleur[2]>180 && changement_couleur[2]<210)
            {
                putpixel(buffer,pos_x+i+matrice_terrain[0][0].largeur/4,pos_y+j,makecol(getr(getpixel(buffer,pos_x+i-matrice_terrain[0][0].largeur,pos_y+j)),getg(getpixel(buffer,pos_x+i-matrice_terrain[0][0].largeur,pos_y+j)),getb(getpixel(buffer,pos_x+i-matrice_terrain[0][0].largeur,pos_y+j))));
            }
        }
    }
}

void case_chemin_horiz(int pos_x, int pos_y, BITMAP* buffer, BITMAP* chemin)
{
    blit(chemin,buffer,0,0,pos_x,pos_y+matrice_terrain[0][0].hauteur/4,SCREEN_H,SCREEN_W);
    int changement_couleur[3], couleur_pixel;
    for(int i=0;i<chemin->w;i++)
    {
        for(int j=0;j<chemin->h;j++)
        {
            couleur_pixel= getpixel(chemin,i,j);
            changement_couleur[0]=getr(couleur_pixel);
            changement_couleur[1]=getb(couleur_pixel);
            changement_couleur[2]=getg(couleur_pixel);
            if (changement_couleur[0]>200 && changement_couleur[0]<220 && changement_couleur[1]>80 && changement_couleur[1]<130 && changement_couleur[2]>180 && changement_couleur[2]<210)
            {
                putpixel(buffer,pos_x+i,pos_y+j+matrice_terrain[0][0].hauteur/4,makecol(getr(getpixel(buffer,pos_x+i,pos_y+j-matrice_terrain[0][0].hauteur)),getg(getpixel(buffer,pos_x+i,pos_y+j-matrice_terrain[0][0].hauteur)),getb(getpixel(buffer,pos_x+i,pos_y+j-matrice_terrain[0][0].hauteur))));
            }
        }
    }
}

void case_arbre(int pos_x, int pos_y, BITMAP* buffer, BITMAP* type_case)
{
    int changement_couleur[3], couleur_pixel, ancienne_couleur[3][type_case->w][type_case->h], ancienne_couleur_pixel;
    for(int i=pos_x-55;i<pos_x-55+type_case->w;i++)
    {
        for(int j=pos_y-70;j<pos_y-70+type_case->h;j++)
        {
            ancienne_couleur_pixel=getpixel(buffer,i,j);
            ancienne_couleur[0][i-pos_x+55][j-pos_y+70]=getr(ancienne_couleur_pixel);
            ancienne_couleur[1][i-pos_x+55][j-pos_y+70]=getb(ancienne_couleur_pixel);
            ancienne_couleur[2][i-pos_x+55][j-pos_y+70]=getg(ancienne_couleur_pixel);
        }
    }
    blit(type_case,buffer,0,0,pos_x-55,pos_y-70,SCREEN_W,SCREEN_H);
    for(int i=0;i<type_case->w;i++)
    {
        for(int j=0;j<type_case->h;j++)
        {
            couleur_pixel= getpixel(type_case,i,j);
            changement_couleur[0]=getr(couleur_pixel);
            changement_couleur[1]=getb(couleur_pixel);
            changement_couleur[2]=getg(couleur_pixel);
            if (changement_couleur[0]>20 && changement_couleur[0]<40 && changement_couleur[1]>20 && changement_couleur[1]<40 && changement_couleur[2]>20 && changement_couleur[2]<40)
            {
                putpixel(buffer,pos_x+i-55,pos_y+j-70,makecol(ancienne_couleur[0][i][j],ancienne_couleur[2][i][j],ancienne_couleur[1][i][j]));
            }
        }
    }
    //blit(type_case,buffer,0,0,pos_x-55,pos_y-70,SCREEN_W,SCREEN_H);
}

void case_eau(int pos_x, int pos_y, BITMAP* buffer, BITMAP* type_case)
{
   blit(type_case,buffer,0,0,pos_x,pos_y,SCREEN_H,SCREEN_W);
}

void init_struct_case()
{
    matrice_terrain[0][0].hauteur=45;                               ///initialisation des structs : largeur, longueur, pos x, pos y, possibilite de passage
    matrice_terrain[0][0].largeur=45;
    matrice_terrain[0][0].x=0;
    matrice_terrain[0][0].y=0;
    if (matrice_terrain[0][0].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
    {
        matrice_terrain[0][0].passage==1;
    }
    else
        matrice_terrain[0][0].passage==0;
    for (int i=1;i<LIGNE;i++)
    {
        matrice_terrain[i][0].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[i][0].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[i][0].x=matrice_terrain[0][0].x;
        matrice_terrain[i][0].y=matrice_terrain[i-1][0].y+(matrice_terrain[i][0].hauteur);
        if (matrice_terrain[i][0].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
        {
            matrice_terrain[i][0].passage==1;
        }
        else
            matrice_terrain[i][0].passage==0;
    }
    for (int j=1;j<COLONNE;j++)
    {
        matrice_terrain[0][j].hauteur=matrice_terrain[0][0].hauteur;
        matrice_terrain[0][j].largeur=matrice_terrain[0][0].largeur;
        matrice_terrain[0][j].x=matrice_terrain[0][j-1].x+(matrice_terrain[0][j].largeur);
        matrice_terrain[0][j].y=matrice_terrain[0][0].y;
        if (matrice_terrain[0][j].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
        {
            matrice_terrain[0][j].passage==1;
        }
        else
            matrice_terrain[0][j].passage==0;
    }
    for (int i=1;i<LIGNE;i++)
    {
        for(int j=1;j<COLONNE;j++)
        {
            matrice_terrain[i][j].hauteur=matrice_terrain[0][0].hauteur;
            matrice_terrain[i][j].largeur=matrice_terrain[0][0].largeur;
            matrice_terrain[i][j].x=matrice_terrain[i][j-1].x+(matrice_terrain[i][j].largeur);
            matrice_terrain[i][j].y=matrice_terrain[i-1][j].y+(matrice_terrain[i][j].hauteur);
            if (matrice_terrain[i][j].type==1||matrice_terrain[0][0].type==2||matrice_terrain[0][0].type==4)
            {
                matrice_terrain[i][j].passage==1;
            }
            else
                matrice_terrain[i][j].passage==0;
        }
    }
    for (int i=0;i<LIGNE/2;i++)                                                                           ///initialisation du type de la case
    {
        for(int j=0;j<COLONNE/2;j++)
        {
            matrice_terrain[i][j].type=1;
        }
    }
    for (int i=LIGNE/2;i<LIGNE;i++)
    {
        for(int j=COLONNE/2;j<COLONNE;j++)
        {
            matrice_terrain[i][j].type=4;
        }
    }
    for (int i=LIGNE/2;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE/2;j++)
        {
            matrice_terrain[i][j].type=3;
        }
    }
    for (int i=0;i<LIGNE/2;i++)
    {
        for(int j=COLONNE/2;j<COLONNE;j++)
        {
            matrice_terrain[i][j].type=2;
        }
    }
    for(int i=5;i<9;i++)
    {
        for(int j=6;j<12;j++)
        {
            matrice_terrain[i][j].type=6;
        }
    }


}

void affichage_terrain(BITMAP* terrain, BITMAP* buffer, BITMAP* ciel)
{
    //int changement_couleur[3], couleur_pixel, ancienne_couleur[3][ciel->w][ciel->h], ancienne_couleur_pixel;
    blit(ciel,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    /*for(int i=0;i<ciel->w;i++)
    {
        for(int j=0;j<ciel->h;j++)
        {
            ancienne_couleur_pixel=getpixel(ciel,i,j);
            ancienne_couleur[0][i][j]=getr(ancienne_couleur_pixel);
            ancienne_couleur[1][i][j]=getb(ancienne_couleur_pixel);
            ancienne_couleur[2][i][j]=getg(ancienne_couleur_pixel);
        }
    }*/
    blit(terrain,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
   /* for(int i=0;i<terrain->w;i++)
    {
        for(int j=0;j<terrain->h;j++)
        {
            couleur_pixel= getpixel(terrain,i,j);
            changement_couleur[0]=getr(couleur_pixel);
            changement_couleur[1]=getb(couleur_pixel);
            changement_couleur[2]=getg(couleur_pixel);
            if (changement_couleur[0]>250 && changement_couleur[0]<260 && changement_couleur[1]>250 && changement_couleur[1]<260 && changement_couleur[2]>250 && changement_couleur[2]<260)
            {
                putpixel(buffer,i,j,makecol(ancienne_couleur[0][i][j],ancienne_couleur[2][i][j],ancienne_couleur[1][i][j]));
            }
        }
    }*/

    //draw_sprite(screen, buffer, 0,0);*/
}



//BITMAP* type_case[6];
    /*type_case[0]=load_bitmap("herbe.bmp", NULL);
    type_case[1]=load_bitmap("terre.bmp", NULL);
    type_case[2]=load_bitmap("neige.bmp", NULL);
    type_case[3]=load_bitmap("sable.bmp", NULL);
    type_case[4]=load_bitmap("arbre_dofus.bmp", NULL);
    type_case[5]=load_bitmap("eau.bmp",NULL);
    BITMAP* chemin_verticale=load_bitmap("chemin_verticale.bmp", NULL);
    BITMAP* chemin_horiz=load_bitmap("chemin_horiz.bmp", NULL);*/
/*for (int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            switch (matrice_terrain[i][j].type)
            {
                case 1:
                    blit(type_case[0],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                    break;
                case 2:
                    blit(type_case[1],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                    break;
                case 3:
                    blit(type_case[2],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                    break;
                case 4:
                    blit(type_case[3],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                    break;
                case 5:
                    blit(type_case[matrice_terrain[i][j-1].type-1],buffer,0,0,matrice_terrain[i][j].x,matrice_terrain[i][j].y,SCREEN_W,SCREEN_H);
                    break;
                case 6:
                    case_eau(matrice_terrain[i][j].x,matrice_terrain[i][j].y,buffer,type_case[5]);
            }
        }
    }
    for (int i=3;i<LIGNE-3;i++)
    {
            case_chemin_verticale(matrice_terrain[i][2].x,matrice_terrain[i][2].y,buffer,chemin_verticale);
            case_chemin_verticale(matrice_terrain[i][COLONNE-3].x,matrice_terrain[i][COLONNE-3].y,buffer,chemin_verticale);
    }
    for (int i=3;i<COLONNE-3;i++)
    {
            case_chemin_horiz(matrice_terrain[2][i].x,matrice_terrain[2][i].y,buffer,chemin_horiz);
            case_chemin_horiz(matrice_terrain[LIGNE-3][i].x,matrice_terrain[LIGNE-3][i].y,buffer,chemin_horiz);
    }
    matrice_terrain[4][5].type=5;
    matrice_terrain[9][5].type=5;
    matrice_terrain[9][12].type=5;
    matrice_terrain[4][12].type=5;
    for (int i=0;i<LIGNE;i++)
    {
        for(int j=0;j<COLONNE;j++)
        {
            if (matrice_terrain[i][j].type==5)
            {
                case_arbre(matrice_terrain[i][j].x,matrice_terrain[i][j].y,buffer,type_case[4]);
            }
        }
    }*/
