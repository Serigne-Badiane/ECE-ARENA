#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void init_joueur(int nbrjoueur,str_perso joueur [nbrjoueur]){
    for (int i =0 ; i < nbrjoueur; i ++ ){
        joueur[i].pa = 6;
        joueur[i].pm = 3;
        joueur[i].pv = 200;
    }
}

void load_cra_feu (sortperso* perso){
    perso->sort1 = load_bitmap("bdf.bmp",NULL);
    perso->sort2 = load_bitmap("tir_explosif.bmp",NULL);
    perso->sort3= load_bitmap("feu_oku.bmp",NULL);
    perso->sort4 = load_bitmap("cac_feu.bmp",NULL);
}

void load_mage_eau (sortperso* perso){
    perso->sort1 = load_bitmap("vague.bmp",NULL);
    perso->sort2 = load_bitmap("propulsion.bmp",NULL);
    perso->sort3= load_bitmap("protection.bmp",NULL);
    perso->sort4 = load_bitmap("vision.bmp",NULL);

}

void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [4]){
        rectfill(buffer,0,650,1272,713,makecol(130,98,85));
        rectfill(buffer,900,450,1272,650,makecol(64,47,32));
        blit(perso.sort1, buffer ,0,0,220,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort2, buffer ,0,0,300,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort3, buffer ,0,0,380,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort4, buffer ,0,0,460,650,perso.sort1->h,perso.sort1->w);
        rectfill(buffer,100,20,220,40,makecol(0,0,255));
        rectfill(buffer,100,45,220,65,makecol(0,255,0));
        textprintf_ex(buffer,font,35,40,makecol(255,255,255),makecol(255,0,0),"%d",joueur[0].pv);
        textprintf_ex(buffer,font,155,25,makecol(255,255,255),makecol(0,0,255),"%d",joueur[0].pa);
        textprintf_ex(buffer,font,160,50,makecol(255,255,255),makecol(0,255,0),"%d",joueur[0].pm);
        draw_sprite(buffer,coeurpv,5,10);
}


void usesort (BITMAP* buffer,BITMAP* bdf1,BITMAP* bdf2,BITMAP* bdf3,str_perso joueur1,str_perso joueur2,BITMAP* temp){
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290)
        {
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);

        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une boule de feu qui infliche 45pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290 && mouse_b & 1){
            int altern = 0;
            int i = 1;
            int am;
            int bm;
            int j =1 ;
            int a;
            int b;
            a = ((joueur2.pos.x-joueur1.pos.x)/2);
            b = ((joueur2.pos.y-joueur1.pos.y)/2);
            if (((joueur2.pos.x-joueur1.pos.x)/2) > 0){
                am  = 0;
            }
            if (((joueur2.pos.x-joueur1.pos.x)/2) < 0){
                am = 1;
            }
            if (((joueur2.pos.y-joueur1.pos.y)/2) > 0){
                bm  = 0;
            }
            if (((joueur2.pos.y-joueur1.pos.y)/2) < 0){
                bm = 1;
            }
            if (am == 0 && bm == 0){
                while( i< a && j< b)
                {
                        if (altern == 0)
                           {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            //blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                            //draw_sprite(screen, buffer, 0,0);
                            rotate_sprite(buffer, bdf1, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10)); // 128 = 180°
                            draw_sprite(screen, buffer, 0,0);
                            altern = 1;
                           }
                        if (altern == 1)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            //blit(bdf2, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf2->w,joueur1.pos.y+(2*j), bdf2->w, bdf2->h);
                            //draw_sprite(screen, buffer, 0,0);
                            rotate_sprite(buffer, bdf2, joueur1.pos.x+(2*i) - bdf2->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 2;
                        }
                        if (altern == 2)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            //blit(bdf3, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf3->w,joueur1.pos.y+(2*j), bdf3->w, bdf3->h);
                            //draw_sprite(screen, buffer, 0,0);
                            rotate_sprite(buffer, bdf3, joueur1.pos.x+(2*i) - bdf3->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 0;
                        }
                        if (i < a){
                          i++;
                        }
                        if (j< b){
                          j++;
                        }

                }
            }
            if (am == 1 && bm == 0){
                while( i > a && j< b)
                {
                        if (altern == 0)
                           {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf1, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 1;
                           }
                        if (altern == 1)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf2, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf2->w,joueur1.pos.y+(2*j), bdf2->w, bdf2->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf2, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 2;
                        }
                        if (altern == 2)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf3, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf3->w,joueur1.pos.y+(2*j), bdf3->w, bdf3->h);
                            */
                            rotate_sprite(buffer, bdf3, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 0;
                        }
                        if (i > a){
                          i--;
                        }
                        if (j< b){
                          j++;
                        }
                }

            }
            if (am == 0 && bm == 1){
                while( i< a && j> b)
                {
                        if (altern == 0)
                           {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                           /* blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf1, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 1;
                           }
                        if (altern == 1)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf2, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf2->w,joueur1.pos.y+(2*j), bdf2->w, bdf2->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf2, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);
                            altern = 2;
                        }
                        if (altern == 2)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                           /* blit(bdf3, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf3->w,joueur1.pos.y+(2*j), bdf3->w, bdf3->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf3, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            draw_sprite(screen, buffer, 0,0);

                            altern = 0;
                        }
                        if (i < a){
                          i++;
                        }
                        if (j> b){
                          j--;
                        }
                }
            }
            if (am == 1 && bm == 1){
                while( i> a && j> b)
                {
                        if (altern == 0)
                           {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf1, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            altern = 1;
                           }
                        if (altern == 1)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf2, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf2->w,joueur1.pos.y+(2*j), bdf2->w, bdf2->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf2, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            altern = 2;
                        }
                        if (altern == 2)
                        {
                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            /*blit(bdf3, buffer, 0, 0, joueur1.pos.x+(2*i)- bdf3->w,joueur1.pos.y+(2*j), bdf3->w, bdf3->h);
                            draw_sprite(screen, buffer, 0,0);*/
                            rotate_sprite(buffer, bdf3, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), ftofix(-10));
                            altern = 0;
                        }
                        if (i > a){
                          i--;
                        }
                        if (j> b){
                          j--;
                        }
                }
            }
        }

    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une fleche enflamée qui inflige 30pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370 && mouse_b & 1){

                rectfill(buffer,0,300,400,713,makecol(255,0,0));
        }
    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 380 && mouse_x < 450){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Vous vous enflammez et gagnez 3pt de mouvement pour 2 tour");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 380 && mouse_x < 450 && mouse_b & 1){
                rectfill(buffer,0,300,400,713,makecol(255,0,0));
        }
    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 460 && mouse_x < 530){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Un coup au corps a corps qui inflige 20 pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 460 && mouse_x < 530 && mouse_b & 1){
                rectfill(buffer,0,300,400,713,makecol(255,0,0));
        }
    }
}
