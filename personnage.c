#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void init_joueur(int nbrjoueur,str_perso joueur [4]){
    for (int i =0 ; i < nbrjoueur; i ++ ){
        joueur[i].pa = 6;
        joueur[i].pm = 3;
        joueur[i].pv = 200;
    }
}

void affichagesort (BITMAP* buffer,BITMAP* bdf,BITMAP*  tir_explosif, BITMAP* feu_oku, BITMAP* cac_feu,BITMAP * coeurpv, str_perso joueur [4]){
        blit(bdf, buffer ,0,0,220,650,bdf->h,bdf->w);
        blit(tir_explosif, buffer ,0,0,265,650,bdf->h,bdf->w);
        blit(feu_oku, buffer ,0,0,310,650,bdf->h,bdf->w);
        blit(cac_feu, buffer ,0,0,355,650,bdf->h,bdf->w);
        rectfill(buffer,100,20,220,40,makecol(0,0,255));
        rectfill(buffer,100,45,220,65,makecol(0,255,0));
        textprintf_ex(buffer,font,35,40,makecol(255,255,255),makecol(255,0,0),"%d",joueur[0].pv);
        textprintf_ex(buffer,font,155,25,makecol(255,255,255),makecol(0,0,255),"%d",joueur[0].pa);
        textprintf_ex(buffer,font,160,50,makecol(255,255,255),makecol(0,255,0),"%d",joueur[0].pm);
        draw_sprite(buffer,coeurpv,5,10);
}
