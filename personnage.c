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


void usesort (BITMAP* buffer,BITMAP* bdf1,BITMAP* bdf2,BITMAP* bdf3,str_perso joueur1,str_perso joueur2){
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290){

        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une boule de feu qui infliche 45pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290 && mouse_b & 1){
            int altern = 0;
            for (int i = 1; i< (joueur2.x-joueur1.x)/2 ; i++){
                if (altern == 0){
                    draw_sprite(buffer,bdf1,joueur1.x+(2*i),joueur1.y);
                    blit(buffer,screen,0,0,0,0,SCREEN_H,SCREEN_W);

                    altern = 1;
                }
                if (altern == 1){
                    draw_sprite(buffer,bdf2,joueur1.x+(2*i),joueur1.y);
                    blit(buffer,screen,0,0,0,0,SCREEN_H,SCREEN_W);
                    altern = 2;
                }
                if (altern == 2){
                    draw_sprite(buffer,bdf3,joueur1.x+(2*i),joueur1.y);
                    blit(buffer,screen,0,0,0,0,SCREEN_H,SCREEN_W);

                    altern = 0;
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
