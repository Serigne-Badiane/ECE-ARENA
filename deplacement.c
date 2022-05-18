#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void placement_joueur_debut(BITMAP*buffer,BITMAP*buffer_couleur, BITMAP* buffer_enlevage_indication,int nb_joueur)
{
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
}

void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* buffer_couleur,int tour_joueur)
{
    int i=joueur[tour_joueur].pos.case_ligne_iso;
    int p=joueur[tour_joueur].pos.case_colonne_iso;

    if(joueur[tour_joueur].pm==3)
    {
        for(int o=p-3;o<p+4;o++)
        {
            if (o==p)
            {
                o=p+1;
            }
            if(matrice_terrain_iso[i][o].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[i][o].x, matrice_terrain_iso[i][o].y, 140,140,140);
            }
        }
        for(int o=i-3;o<i+4;o++)
        {
            if (o==i)
            {
                o=i+1;
            }
            if(matrice_terrain_iso[o][p].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[o][p].x, matrice_terrain_iso[o][p].y, 140,140,140);
            }
        }
        if(matrice_terrain_iso[i+1][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p+1].x, matrice_terrain_iso[i+1][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+1][p+2].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p+2].x, matrice_terrain_iso[i+1][p+2].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p+1].x, matrice_terrain_iso[i-1][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p+2].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p+2].x, matrice_terrain_iso[i-1][p+2].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+1][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p-1].x, matrice_terrain_iso[i+1][p-1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+1][p-2].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p-2].x, matrice_terrain_iso[i+1][p-2].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p-1].x, matrice_terrain_iso[i-1][p-1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p-2].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p-2].x, matrice_terrain_iso[i-1][p-2].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+2][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+2][p+1].x, matrice_terrain_iso[i+2][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-2][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-2][p+1].x, matrice_terrain_iso[i-2][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+2][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+2][p-1].x, matrice_terrain_iso[i+2][p-1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-2][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-2][p-1].x, matrice_terrain_iso[i-2][p-1].y, 140,140,140);
        }
    }

    if(joueur[tour_joueur].pm==2)
    {
        for(int o=i+1;o<i+3;o++)
        {
            if(matrice_terrain_iso[o][p].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[o][p].x, matrice_terrain_iso[o][p].y, 140,140,140);
            }
        }
        for(int o=i-1;o>i-3;o--)
        {
            if(matrice_terrain_iso[o][p].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[o][p].x, matrice_terrain_iso[o][p].y, 140,140,140);
            }
        }
        for(int o=p-1;o>p-3;o--)
        {
            if(matrice_terrain_iso[i][o].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[i][o].x, matrice_terrain_iso[i][o].y, 140,140,140);
            }
        }
        for(int o=p+1;o<p+3;o++)
        {
            if(matrice_terrain_iso[i][o].passage==1)
            {
                case_couleur(buffer,matrice_terrain_iso[i][o].x, matrice_terrain_iso[i][o].y, 140,140,140);
            }
        }
        if(matrice_terrain_iso[i+1][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p+1].x, matrice_terrain_iso[i+1][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p+1].x, matrice_terrain_iso[i-1][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p-1].x, matrice_terrain_iso[i-1][p-1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+1][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p-1].x, matrice_terrain_iso[i+1][p-1].y, 140,140,140);
        }
    }
    if(joueur[tour_joueur].pm==1)
    {
        if(matrice_terrain_iso[i][p+1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i][p+1].x, matrice_terrain_iso[i][p+1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i][p-1].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i][p-1].x, matrice_terrain_iso[i][p-1].y, 140,140,140);
        }
        if(matrice_terrain_iso[i+1][p].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i+1][p].x, matrice_terrain_iso[i+1][p].y, 140,140,140);
        }
        if(matrice_terrain_iso[i-1][p].passage==1)
        {
            case_couleur(buffer,matrice_terrain_iso[i-1][p].x, matrice_terrain_iso[i-1][p].y, 140,140,140);
        }
    }
}

void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur,int tour_joueur,BITMAP*buffer_deplacement, BITMAP* buffer_enlevage_indication, BITMAP* buffer_deplacement2, int nbr_joueur)
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


    for (int s=0;s<nbr_joueur;s++)
    {
        masked_blit(image_joueur[0+s*5], buffer, 0 ,0, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
    }
    recuperation_couleur(buffer,buffer_enlevage_indication);
    for(int i=0;i<LIGNE2;i++)
    {
        for(int t=0; t<COLONNE2; t++)
        {
            if (getr(getpixel(buffer_deplacement,mouse_x,mouse_y))==140 && getb(getpixel(buffer_deplacement,mouse_x,mouse_y))==140 && getg(getpixel(buffer_deplacement,mouse_x,mouse_y))==140)
            {
                if(getr(getpixel(buffer_couleur,mouse_x,mouse_y))==getr(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)) && getb(getpixel(buffer_couleur,mouse_x,mouse_y))==getb(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)) && getg(getpixel(buffer_couleur,mouse_x,mouse_y))==getg(getpixel(buffer_couleur,matrice_terrain_iso[i][t].x,matrice_terrain_iso[i][t].y)))
                {
                    int z=i,y=t;
                    if (z<joueur[tour_joueur].pos.case_ligne_iso)
                    {
                        while(z<joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                            z++;
                        }
                    }
                    if (z>joueur[tour_joueur].pos.case_ligne_iso )
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
                    if (y>joueur[tour_joueur].pos.case_colonne_iso )
                    {
                        while(y>joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            case_couleur(buffer,matrice_terrain_iso[z][y].x,matrice_terrain_iso[z][y].y,151,223,198);
                            y--;
                        }
                    }


                    if(mouse_b&1 && i>=joueur[tour_joueur].pos.case_ligne_iso && t>=joueur[tour_joueur].pos.case_colonne_iso)
                    /*while (mouse_x<matrice_terrain_iso[i][t].x+matrice_terrain[0][0].largeur/2 &&  mouse_x>matrice_terrain_iso[i][t].x-matrice_terrain[0][0].largeur/2 && mouse_y<matrice_terrain_iso[i][t].y+matrice_terrain[0][0].hauteur/2 &&  mouse_y>matrice_terrain_iso[i][t].y-matrice_terrain[0][0].hauteur/2)
                    {
                        printf("l\n");
                        rest(15);
                    }*/
                    //enlevage_des_indications(buffer,buffer_enlevage_indication);
                    if(mouse_b&1)
                    {
                        /*while(matrice_terrain_iso[play[j].case_ligne][play[j].case_colonne].y<matrice_terrain_iso[i][t].y)
                        {
                            textprintf_ex(buffer,font,50,400,makecol(255,255,255),makecol(255,0,0),"LAAAAA");
                            while(i>joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                blit(image_joueur[3+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_ligne_iso++;
                                while(t>joueur[tour_joueur].pos.case_colonne_iso)
                                {
                                blit(image_joueur[4+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_colonne_iso++;
                                }
                            }
                        }
                    else if (mouse_b&1 && i>=joueur[tour_joueur].pos.case_ligne_iso && t<=joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            textprintf_ex(buffer,font,50,400,makecol(255,255,255),makecol(255,0,0),"LAAAAA2");
                            while(i>joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                blit(image_joueur[3+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_ligne_iso++;
                                while(t<joueur[tour_joueur].pos.case_colonne_iso)
                                {
                                blit(image_joueur[4+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_colonne_iso--;
                                }
                            }
                        }
                    else if (mouse_b&1 && i<=joueur[tour_joueur].pos.case_ligne_iso && t>=joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            textprintf_ex(buffer,font,50,400,makecol(255,255,255),makecol(255,0,0),"LAAAAA3");
                            while(i<joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                blit(image_joueur[1+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_ligne_iso--;
                                while(t>joueur[tour_joueur].pos.case_colonne_iso)
                                {
                                blit(image_joueur[2+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_colonne_iso++;
                                }
                            }
                        }
                    else if (mouse_b&1 && i<=joueur[tour_joueur].pos.case_ligne_iso && t<=joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            textprintf_ex(buffer,font,50,400,makecol(255,255,255),makecol(255,0,0),"LAAAAA4");
                            while(i<joueur[tour_joueur].pos.case_ligne_iso)
                            {
                                blit(image_joueur[1+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_ligne_iso--;
                                while(t<joueur[tour_joueur].pos.case_colonne_iso)
                                {
                                blit(image_joueur[2+tour_joueur*5], buffer, 0 ,0, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[tour_joueur].pos.case_ligne_iso][joueur[tour_joueur].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                                joueur[tour_joueur].pos.case_colonne_iso--;
                                }
                            }
                        }

                        /*enlevage_des_indications(buffer, buffer_enlevage_indication);
                        enlevage_des_indications(buffer_deplacement,buffer_deplacement2);

                        joueur[tour_joueur].pm-=joueur[tour_joueur].pos.case_ligne_iso-i+joueur[tour_joueur].pos.case_colonne_iso-t;
                        joueur[tour_joueur].pos.case_ligne_iso=i;
                        joueur[tour_joueur].pos.case_colonne_iso=t;
                        joueur[tour_joueur].pos.x = matrice_terrain_iso[i][t].x;
                        joueur[tour_joueur].pos.y = matrice_terrain_iso[i][t].y;*/
                            matrice_terrain_iso[play[j].case_ligne][play[j].case_colonne].x-=matrice_terrain_iso[0][0].largeur;
                            blit(image_joueur[2], terrain, 0 ,0, matrice_terrain_iso[play[j].case_ligne][play[j].case_colonne].x-image_joueur[2]->w/2, matrice_terrain_iso[play[j].case_ligne][play[j].case_colonne].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                            rest(200);
                        }*/
                        enlevage_des_indications(buffer, terrain);
                        enlevage_des_indications(buffer_deplacement,buffer_deplacement2);
                        /*for (int s=0;s<nbr_joueur;s++)
                        {
                            blit(image_joueur[0+s*5], buffer, 0 ,0, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].x-image_joueur[2]->w/2, matrice_terrain_iso[joueur[s].pos.case_ligne_iso][joueur[s].pos.case_colonne_iso].y-image_joueur[2]->h, image_joueur[2]->w, image_joueur[2]->h);
                        }*/
                        if(i<joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            joueur[tour_joueur].pm-=joueur[tour_joueur].pos.case_ligne_iso-i;
                        }
                        if(i>joueur[tour_joueur].pos.case_ligne_iso)
                        {
                            joueur[tour_joueur].pm-=-joueur[tour_joueur].pos.case_ligne_iso+i;
                        }
                        if(t>joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            joueur[tour_joueur].pm-=-joueur[tour_joueur].pos.case_colonne_iso+t;
                        }
                        if(t<joueur[tour_joueur].pos.case_colonne_iso)
                        {
                            joueur[tour_joueur].pm-=joueur[tour_joueur].pos.case_colonne_iso-t;
                        }
                        joueur[tour_joueur].pos.case_ligne_iso=i;
                        joueur[tour_joueur].pos.case_colonne_iso=t;
                        joueur[tour_joueur].pos.x = matrice_terrain_iso[i][t].x;
                        joueur[tour_joueur].pos.y = matrice_terrain_iso[i][t].y;
                        printf("%d\n",joueur[tour_joueur].pm);
                        while (mouse_b & 1)                 ///blindage click gauche
                        {
                            rest(150);
                        }
                    }
                }
            }
        }
    }
    }
}
