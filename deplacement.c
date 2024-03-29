#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

int verif (int z,int y, int tour_joueur)                                ///sspg qui verifie qu'il n'y a pas d'obstacle sur le chemin de joueur pour qu'il puisse atteindre la case qu'il a choisi
{                                                                       ///si le compteur renvoi une valeur différente de zero, on ne pourra utiliser ce chemin
    int compteur=0;
    if (z<joueur[tour_joueur].pos.case_ligne_iso)
    {
        while(z<joueur[tour_joueur].pos.case_ligne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            z++;
        }
    }
    if (z>joueur[tour_joueur].pos.case_ligne_iso)
    {
        while(z>joueur[tour_joueur].pos.case_ligne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            z--;
        }
    }
    if (y<joueur[tour_joueur].pos.case_colonne_iso)
    {
        while(y<joueur[tour_joueur].pos.case_colonne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            y++;
        }
    }
    if (y>joueur[tour_joueur].pos.case_colonne_iso)
    {
        while(y>joueur[tour_joueur].pos.case_colonne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            y--;
        }
    }
    return compteur;
}

int verif2 (int z,int y, int tour_joueur)                               ///meme sspg mais pour le chemin numero 2
{                                                                       ///si le compteur renvoi une valeur différente de zéro, on ne pourra pas atteindre la case
    int compteur=0;
    if (y<joueur[tour_joueur].pos.case_colonne_iso)
    {
        while(y<joueur[tour_joueur].pos.case_colonne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            y++;
        }
    }
    if (y>joueur[tour_joueur].pos.case_colonne_iso)
    {
        while(y>joueur[tour_joueur].pos.case_colonne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            y--;
        }
    }
    if (z<joueur[tour_joueur].pos.case_ligne_iso)
    {
        while(z<joueur[tour_joueur].pos.case_ligne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            z++;
        }
    }
    if (z>joueur[tour_joueur].pos.case_ligne_iso)
    {
        while(z>joueur[tour_joueur].pos.case_ligne_iso)
        {
            if(matrice_terrain_iso[z][y].passage!=1)
            {
                if(joueur[tour_joueur].classe==0)
                {
                    if(matrice_terrain_iso[z][y].passage!=2)
                    {
                        compteur++;
                    }
                }
                else
                    compteur++;
            }
            z--;
        }
    }
    return compteur;
}

void placement_joueur_debut(BITMAP*buffer,BITMAP*buffer_couleur,int nb_joueur,BITMAP* cursor,BITMAP* buffer_enlevage)          ///sspg pour placer les joueurs au début de partie
{                                                                                                      ///on affiche des cases sur lesquels ils peuvent se placer et en fonction du choix on change leur positionnement
    for(int i=0;i<LIGNE2;i++)
    {
        for(int j=0;j<COLONNE2;j++)
        {
            switch(matrice_terrain_iso[i][j].placement_debut)
            {
                case 1:
                    case_couleur(buffer,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,100,100,100);
                    break;
                case 2:
                    case_couleur(buffer,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,100,170,100);
                    break;
                case 3:
                    case_couleur(buffer,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,100,100,170);
                    break;
                case 4:
                    case_couleur(buffer,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,170,100,100);
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
                            matrice_terrain_iso[joueur[a].pos.case_ligne_iso][joueur[a].pos.case_colonne_iso].passage=0;
                            while (mouse_b & 1)                 ///blindage click gauche
                            {
                                rest(150);
                            }
                        }
                    }
                }
            }
            recuperation_couleur(buffer,buffer_enlevage);
            masked_blit(cursor, buffer , 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
            masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            enlevage_des_indications(buffer,buffer_enlevage);
        }
    }
}

void respirer(BITMAP* buffer,BITMAP* terrain, int nbr_joueur,BITMAP* temp)  ///sspg qui permet un effet de respiration (le joueur est tjrs en mouvement)
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

    for(int k=0; k<20; k++)
    {
        if (image_joueur[k]==NULL)
        {
            allegro_message("Pas l'image %d", k);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    int i=0;
    recuperation_couleur(buffer,temp);
    for (int k=0;k<nbr_joueur;k++)
    {
        while(i<=2)
        {
            if(joueur[k].pv>0)
            {
                stretch_blit(image_joueur[0+joueur[k].classe*5], buffer, 0, 0,image_joueur[0+joueur[k].classe*5]->w, image_joueur[0+joueur[k].classe*5]->h, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].x-image_joueur[0+joueur[k].classe*5]->w/2, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].y-image_joueur[0+joueur[k].classe*5]->h, image_joueur[0+joueur[k].classe*5]->w, image_joueur[0+joueur[k].classe*5]->h+3*i);
            }
            masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            enlevage_des_indications(buffer,temp);
            i++;
        }
        while(i>0)
        {
            if(joueur[k].pv>0)
            {
                stretch_blit(image_joueur[0+joueur[k].classe*5], buffer, 0, 0,image_joueur[0+joueur[k].classe*5]->w, image_joueur[0+joueur[k].classe*5]->h, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].x-image_joueur[0+joueur[k].classe*5]->w/2, matrice_terrain_iso[joueur[k].pos.case_ligne_iso][joueur[k].pos.case_colonne_iso].y-image_joueur[0+joueur[k].classe*5]->h, image_joueur[0+joueur[k].classe*5]->w, image_joueur[0+joueur[k].classe*5]->h+3*i);
            }
            masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            enlevage_des_indications(buffer,temp);
            i--;
        }
    }

}

void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur,int tour_joueur, BITMAP* buffer_enlevage_indication, int nbr_joueur,int nbtour)      ///sspg qui déplace le joueur
{
    BITMAP* image_joueur[20];
    BITMAP* pnj_bitmap = load_bitmap("mont.bmp",NULL);

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
    BITMAP* image_fantome=load_bitmap("fantome.bmp", NULL);
    for(int k=0; k<20; k++)
    {
        if (image_joueur[k]==NULL)
        {
            allegro_message("Pas l'image %d", k);
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    for (int s=0;s<nbr_joueur;s++)                      ///on affiche tous les joueurs sauf les joueurs pour lequel c'est le tour
    {
        if(s!=tour_joueur)
        {
            if(joueur[s].pv>0)
            {
                masked_blit(image_joueur[0+joueur[s].classe*5], buffer, 0 ,0, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].x-image_joueur[0+joueur[s].classe*5]->w/2, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].y-image_joueur[0+joueur[s].classe*5]->h, image_joueur[0+joueur[s].classe*5]->w, image_joueur[0+joueur[s].classe*5]->h);
            }
            else
                masked_blit(image_fantome, buffer, 0 ,0, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].x-image_joueur[0+joueur[s].classe*5]->w/2, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].y-image_joueur[0+joueur[s].classe*5]->h, image_joueur[0+joueur[s].classe*5]->w, image_joueur[0+joueur[s].classe*5]->h);


        }
    }
    masked_blit(pnj_bitmap, buffer, 0 ,0, matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].x-pnj_bitmap->w/2, matrice_terrain_iso[pnj.pos.case_ligne_iso][pnj.pos.case_colonne_iso].y-pnj_bitmap->h, pnj_bitmap->w, pnj_bitmap->h);
    recuperation_couleur(buffer,buffer_enlevage_indication);                    ///on stocke le buffer sur un buffer temporaire puis on affiche le joueur pour lequel c'est le tour

    masked_blit(image_joueur[0+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[0+joueur[tour_joueur].classe*5]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[0+joueur[tour_joueur].classe*5]->h, image_joueur[0+joueur[tour_joueur].classe*5]->w, image_joueur[0+joueur[tour_joueur].classe*5]->h);
   //printf("%d %d \n")
    if(nbtour==ancien_nbtour[tour_joueur]+nbr_joueur)
    {
        if (dureesort[tour_joueur]==1)
        {
            if (joueur[tour_joueur].classe == 0){
                joueur[tour_joueur].pa += 3;
                dureesort[tour_joueur]=0;
                ancien_nbtour[tour_joueur]=0;
            }
            if (joueur[tour_joueur].classe == 2){
                joueur[tour_joueur].pv += 20;
                ancien_nbtour[tour_joueur]=0;
            }
            if (joueur[tour_joueur].classe == 3){
                joueur[tour_joueur].pm += 2;
                dureesort[tour_joueur]=0;
                ancien_nbtour[tour_joueur]=0;
            }
        }
    }
    for(int i=0;i<LIGNE2;i++)
    {
        for(int t=0; t<COLONNE2; t++)
        {
            if (abs(i-joueur[tour_joueur].pos.case_ligne_iso)+abs(t-joueur[tour_joueur].pos.case_colonne_iso)<=joueur[tour_joueur].pm)  ///calcul pour savoir les cases qui étant possible é atteindre par le joueur
            {                                                                                                               ///la boucle suivante permet de savoir sur quel case est la souris
                if(getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)))
                {
                    int z=i,y=t,compteur=0,compteur2=0;
                    compteur=verif(z,y,tour_joueur);                ///vérification qu'il n'y a pas d'obstacle
                    if (compteur==0)                                ///les boucles qui suivent permettent au joueur de savoir s'il peut se déplacer sur la case sur laquelle est la souris et de montrer le chemin
                    {                                               /// si la case est de couleur vert d'eau, elle est accessible
                        if (z<joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            while(z<joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                z++;
                            }
                        }
                        if (z>joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            while(z>joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                z--;
                            }
                        }
                        if (y<joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            while(y<joueur[tour_joueur].pos.case_colonne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                y++;
                            }
                        }
                        if (y>joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            while(y>joueur[tour_joueur].pos.case_colonne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                y--;
                            }
                        }
                    }
                    compteur2=verif2(z,y,tour_joueur);                      ///on vérifie qu'il n'y a pas d'obstacles sur le chemin 2
                    if (compteur2==0 && compteur!=0)                        ///si il y avait un obstacle sur le chemin 1 on utilise le chemin 2 (é condition qu'il n'y en ai pas sur celui-ci)
                    {
                        if (y<joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            while(y<joueur[tour_joueur].pos.case_colonne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                y++;
                            }
                        }
                        if (y>joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            while(y>joueur[tour_joueur].pos.case_colonne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                y--;
                            }
                        }
                        if (z<joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            while(z<joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                z++;
                            }
                        }
                        if (z>joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            while(z>joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                                z--;
                            }
                        }
                    }
                    int z2=joueur[tour_joueur].pos.case_ligne_iso,y2=joueur[tour_joueur].pos.case_colonne_iso;

                    int pimp=0;

                    if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==151 && getb(getpixel(buffer,mouse_x,mouse_y))==198 && getg(getpixel(buffer,mouse_x,mouse_y))==223) ///si le joueur clique et que la case est accessible
                    {
                        while(mouse_b&1)                 ///blindage click gauche
                        {
                            rest(150);
                        }
                        if(compteur==0)         ///on fait avancer le joueur par le chemin 1
                        {
                            if ( t<y2)
                            {
                                while(t!=y2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[1+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2--;
                                        pimp++;
                                    }
                                     else
                                    {
                                        masked_blit(image_joueur[2+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2--;
                                        pimp++;
                                    }
                                }

                            }
                            if ( t>y2)
                            {
                                while(t!=y2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[3+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w,image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2++;
                                        pimp++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[4+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w,image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2++;
                                        pimp++;
                                    }
                                }
                            }
                            if( i>z2)
                            {
                                while(i!=z2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[3+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2++;
                                        pimp++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[4+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2++;
                                        pimp++;
                                    }
                                }
                            }
                            if ( i<z2)
                            {
                                while(i!=z2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[1+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2--;
                                        pimp++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[2+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2--;
                                        pimp++;
                                    }
                                }
                            }
                        }
                        if(compteur2==0 && compteur!=0)                 ///on fait avancer le joueur par le chemin 2
                        {
                            if( i>z2)
                            {
                                while(i!=z2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[3+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2++;
                                        pimp++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[4+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2++;
                                        pimp++;
                                    }
                                }
                            }
                            if ( i<z2)
                            {
                                while(i!=z2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[1+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2--;
                                        pimp++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[2+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        z2--;
                                        pimp++;
                                    }
                                }
                            }
                            if ( t<y2)
                            {
                                while(t!=y2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[1+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2--;
                                        pimp++;
                                    }

                                    else
                                    {
                                        masked_blit(image_joueur[2+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2--;
                                        pimp++;
                                    }
                                }
                            }
                            if ( t>y2)
                            {
                                while(t!=y2)
                                {
                                    if(pimp%2==0)
                                    {
                                        masked_blit(image_joueur[3+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w,image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2++;
                                    }
                                    else
                                    {
                                        masked_blit(image_joueur[4+joueur[tour_joueur].classe*5], buffer, 0 ,0, matrice_terrain_iso[z2][y2].x-image_joueur[2]->w/2, matrice_terrain_iso[z2][y2].y-image_joueur[2]->h, image_joueur[2]->w,image_joueur[2]->h);
                                        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                        rest(500);
                                        enlevage_des_indications(buffer, buffer_enlevage_indication);
                                        y2++;
                                    }
                                }
                            }
                        }
                        enlevage_des_indications(buffer, terrain);                                       ///effacage du buffer

                        joueur[tour_joueur].pm-=(abs(i-joueur[tour_joueur].pos.case_ligne_iso)+abs(t-joueur[tour_joueur].pos.case_colonne_iso)); ///on change les points de mouvement du joueur
                        matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].passage=1;        ///la case sur laquelle était le joueur devient accessible
                        joueur[tour_joueur].pos.case_ligne_iso=i;                                       ///on change le positionnement du joueur (en pixel et en case)
                        joueur[tour_joueur].pos.case_colonne_iso=t;
                        matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].passage=0;            ///la nouvelle position du joueur n'est plus accessible
                        joueur[tour_joueur].pos.x = matrice_terrain_iso[i][t].x;
                        joueur[tour_joueur].pos.y = matrice_terrain_iso[i][t].y;
                    }
                }
            }
        }
    }
}
