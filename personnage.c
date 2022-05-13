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
