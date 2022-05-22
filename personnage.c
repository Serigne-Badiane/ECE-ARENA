#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void poison (){

    if (compteur < 2 && cible != 5){
        joueur[cible].pv -= (rand()%(40-10+1))+10;
        compteur ++;
    }
    else {
        compteur = 0;
        cible = 5;
    }
}

void init_joueur(int nbrjoueur,str_perso joueur [nbrjoueur])
{
    for (int i =0 ; i < nbrjoueur; i ++ ){
        joueur[i].pa = 6;
        joueur[i].pm = 3;
        joueur[i].pv = 200;
    }
}

void load_cra_feu (sortperso* perso){
    perso->sort1 = load_bitmap("bdf.bmp",NULL);
    perso->sort2 = load_bitmap("tir_explosif.bmp",NULL);
    perso->sort3=  load_bitmap("feu_oku.bmp",NULL);
    perso->sort4 = load_bitmap("cac_feu.bmp",NULL);
    perso->sort5 = load_bitmap("poison_feu.bmp",NULL);

}

void load_guerrier (sortperso* perso){
    perso->sort1 = load_bitmap("coco.bmp",NULL);
    perso->sort2 = load_bitmap("epee_iop.bmp",NULL);
    perso->sort3 = load_bitmap("boost_terre.bmp",NULL);
    perso->sort4 = load_bitmap("cac_terre.bmp",NULL);
    perso->sort5 = load_bitmap("poison_terre.bmp",NULL);

}
void load_anim_coco (animation* perso){
    perso->anim1 = load_bitmap("epee1.bmp",NULL);
    perso->anim2 = load_bitmap("epee2.bmp",NULL);
    perso->anim3 = load_bitmap("epee3.bmp",NULL);
    perso->porte  = 5;

}

void load_anim_lance (animation* perso){
    perso->anim1 = load_bitmap("lance.bmp",NULL);
    perso->anim2 = load_bitmap("lance.bmp",NULL);
    perso->anim3 = load_bitmap("lance.bmp",NULL);
    perso->porte  = 8;
}
void load_anim_tigr (animation* perso){
    perso->anim1 = load_bitmap("tigre1.bmp",NULL);
    perso->anim2 = load_bitmap("tigre3.bmp",NULL);
    perso->anim3 = load_bitmap("tigre2.bmp",NULL);
    perso->porte  = 5;

}

void load_tigre (sortperso* perso){
    perso->sort1 = load_bitmap("morsure.bmp",NULL);
    perso->sort2 = load_bitmap("rafale.bmp",NULL);
    perso->sort3= load_bitmap("bond_felin.bmp",NULL);
    perso->sort4 = load_bitmap("cac_air.bmp",NULL);
    perso->sort5 = load_bitmap("toxine.bmp",NULL);
}
void load_anim_epee_iop (animation* perso){
    perso->anim1 = load_bitmap("eppe.bmp",NULL);
    perso->anim2 = load_bitmap("eppe.bmp",NULL);
    perso->anim3 = load_bitmap("eppe.bmp",NULL);
    perso->porte  = 8;
}

void load_anim_cra_feu_bdf (animation* perso){
    perso->anim1 = load_bitmap("bdf1.bmp",NULL);
    perso->anim2 = load_bitmap("bdf2.bmp",NULL);
    perso->anim3 = load_bitmap("bdf3.bmp",NULL);
    perso->porte = 5;
}

void load_anim_cra_feu_fleche_feu (animation* perso){
    perso->anim1 = load_bitmap("fleche_feu.bmp",NULL);
    perso->anim2 = load_bitmap("fleche_feu.bmp",NULL);
    perso->anim3 = load_bitmap("fleche_feu.bmp",NULL);
    perso->porte  = 8;
}

void load_mage_eau (sortperso* perso){
    perso->sort1 = load_bitmap("vague.bmp",NULL);
    perso->sort2 = load_bitmap("propulsion.bmp",NULL);
    perso->sort3= load_bitmap("protection.bmp",NULL);
    perso->sort4 = load_bitmap("cac_eau.bmp",NULL);
    perso->sort5 = load_bitmap("poison_eau.bmp",NULL);

}

void load_anim_mage_eau_vague(animation* perso){
    perso->anim1 = load_bitmap("vague1.bmp",NULL);
    perso->anim2 = load_bitmap("vague2.bmp",NULL);
    perso->anim3 = load_bitmap("vague3.bmp",NULL);
    perso->porte = 5;
}

void load_anim_mage_eau_flaque(animation* perso){
    perso->anim1 = load_bitmap("flaque1.bmp",NULL);
    perso->anim2 = load_bitmap("flaque2.bmp",NULL);
    perso->anim3 = load_bitmap("flaque3.bmp",NULL);
    perso->porte  = 8;
}

void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [tourjoueur]){
        //rectfill(buffer,0,650,1272,713,makecol(130,98,85));
        blit(perso.sort1, buffer ,0,0,220,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort2, buffer ,0,0,300,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort3, buffer ,0,0,380,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort4, buffer ,0,0,460,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort5, buffer ,0,0,540,650,perso.sort1->h,perso.sort1->w);
        rectfill(buffer,100,20,220,40,makecol(0,0,255));
        rectfill(buffer,100,45,220,65,makecol(0,255,0));
        textprintf_ex(buffer,font,35,40,makecol(255,255,255),makecol(255,0,0),"%d",joueur[tourjoueur].pv);
        textprintf_ex(buffer,font,155,25,makecol(255,255,255),makecol(0,0,255),"%d",joueur[tourjoueur].pa);
        textprintf_ex(buffer,font,160,50,makecol(255,255,255),makecol(0,255,0),"%d",joueur[tourjoueur].pm);
        draw_sprite(buffer,coeurpv,5,10);
}

void affichage_pv (BITMAP* buffer,BITMAP* petit_coeur){
    if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28){

        rectfill(buffer,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 70,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 40,makecol(0,0,0));
        textprintf_ex(buffer,font,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x -20,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 60,makecol(255,255,255),makecol(0,0,0),"%d",joueur[0].pv);
        draw_sprite(buffer,petit_coeur,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +10,matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 70);
        draw_sprite(screen, buffer, 0,0);
    }
    if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 ){

         rectfill(buffer,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 70,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 40,makecol(0,0,0));
         textprintf_ex(buffer,font,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x -20,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 60,makecol(255,255,255),makecol(0,0,0),"%d",joueur[1].pv);
         draw_sprite(buffer,petit_coeur,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x+10,matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 70);
         draw_sprite(screen, buffer, 0,0);

    }
    if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28){

         rectfill(buffer,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 70,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 40,makecol(0,0,0));
         textprintf_ex(buffer,font,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x -20,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 60,makecol(255,255,255),makecol(0,0,0),"%d",joueur[2].pv);
         draw_sprite(buffer,petit_coeur,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x+10,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 70);
         draw_sprite(screen, buffer, 0,0);

    }
    if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){

         rectfill(buffer,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 70,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 40,makecol(0,0,0));
         textprintf_ex(buffer,font,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x -20,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 60,makecol(255,255,255),makecol(0,0,0),"%d",joueur[3].pv);
         draw_sprite(buffer,petit_coeur,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x+10,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 70);
         draw_sprite(screen, buffer, 0,0);

    }



}

void usesort (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp,BITMAP* cursor,BITMAP* temp2){
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290){
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);

        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une grosse attaque dans un rayon de 5 cases");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290 && mouse_b & 1){
                int leave=0;
                for (int i = 2 ; i < perso[0].porte ; i++){
                        if(joueur[tourjoueur].pos.case_ligne_iso+i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso+i>0 && joueur[tourjoueur].pos.case_colonne_iso<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso-i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso-i>0 && joueur[tourjoueur].pos.case_colonne_iso<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso>0 && joueur[tourjoueur].pos.case_colonne_iso+i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso+i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso>0 && joueur[tourjoueur].pos.case_colonne_iso-i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso-i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso+i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso+i>0 && joueur[tourjoueur].pos.case_colonne_iso+i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso+i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso+i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso+i].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso+i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso+i>0 && joueur[tourjoueur].pos.case_colonne_iso-i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso-i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso-i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso-i].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso-i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso-i>0 && joueur[tourjoueur].pos.case_colonne_iso+i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso+i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso+i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso+i].y,0,0,255);
                        }
                        if(joueur[tourjoueur].pos.case_ligne_iso-i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso-i>0 && joueur[tourjoueur].pos.case_colonne_iso-i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso-i>0)
                        {
                            case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso-i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso-i].y,0,0,255);
                        }
                    draw_sprite(screen, buffer, 0,0);
                    blit(buffer,temp2,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (joueur[tourjoueur].pa <= 3){

                }
                else {
                        while (leave == 0){
                            blit(temp2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                            masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
                            draw_sprite(screen, buffer, 0,0);
                            if (mouse_b & 2){
                                leave =1;
                            }
                            if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==0 && getb(getpixel(buffer,mouse_x,mouse_y))==255 && getg(getpixel(buffer,mouse_x,mouse_y))==0) ///si le joueur clique et que la case est accessible
                            {
                            int k = 4;
                            if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28 ){
                                k = 0;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 ){
                                k = 1;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28 ){
                                k = 2;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){
                                k = 3;
                            }
                            if (k != 4){
                                    int altern = 0;
                                    int i = 1;
                                    int am;
                                    int bm;
                                    int j =1 ;
                                    int a;
                                    int b;
                                    a = ((joueur[k].pos.x-joueur[tourjoueur].pos.x)/2);
                                    b = ((joueur[k].pos.y-joueur[tourjoueur].pos.y)/2);
                                    if (a >= 0){
                                        am  = 0;
                                    }
                                    if (a < 0){
                                        am = 1;
                                    }
                                    if (b>= 0){
                                        bm  = 0;
                                    }
                                    if (b < 0){
                                        bm = 1;
                                    }
                                    if (am == 0 && bm == 0){
                                        while( i< a || j< b)
                                        {
                                                if (altern == 0)
                                                   {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32)); // 128 = 180�
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 1;
                                                   }
                                                if (altern == 1)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 2;
                                                }
                                                if (altern == 2)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim3, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
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
                                        while( i > a || j< b)
                                        {
                                                if (altern == 0)
                                                   {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 1;
                                                   }
                                                if (altern == 1)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 2;
                                                }
                                                if (altern == 2)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
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
                                        while( i< a || j> b)
                                        {
                                                if (altern == 0)
                                                   {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 1;
                                                   }
                                                if (altern == 1)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                                    draw_sprite(screen, buffer, 0,0);
                                                    altern = 2;
                                                }
                                                if (altern == 2)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
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
                                        while( i> a || j> b)
                                        {
                                                if (altern == 0)
                                                   {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                    draw_sprite(screen, buffer, 0,0);

                                                    altern = 1;
                                                   }
                                                if (altern == 1)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                    draw_sprite(screen, buffer, 0,0);

                                                    altern = 2;
                                                }
                                                if (altern == 2)
                                                {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, perso[0].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                    draw_sprite(screen, buffer, 0,0);

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
                                            if (((rand()%(12-1+1))+1) != 1){  /// 1 chance sur 12 d'échouer
                                                joueur[k].pv -= (rand()%(40-20+1))+20;
                                            }

                                            joueur[tourjoueur].pa -= 4;
                                            leave = 1;
                                        }


                              }
                            }
                        }
                    }



    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370){
         blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance un sort a grande portée en ligne droite uniquement");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370 && mouse_b & 1){
                int leave=0;
                for (int i = 2 ; i < perso[1].porte ; i++){
                    if(joueur[tourjoueur].pos.case_ligne_iso+i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso+i>0 && joueur[tourjoueur].pos.case_colonne_iso<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso>0)
                    {
                        case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                    }
                    if(joueur[tourjoueur].pos.case_ligne_iso-i<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso-i>0 && joueur[tourjoueur].pos.case_colonne_iso<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso>0)
                    {
                        case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                    }
                    if(joueur[tourjoueur].pos.case_ligne_iso<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso>0 && joueur[tourjoueur].pos.case_colonne_iso+i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso+i>0)
                    {
                        case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].y,0,0,255);
                    }
                    if(joueur[tourjoueur].pos.case_ligne_iso<LIGNE2 && joueur[tourjoueur].pos.case_ligne_iso>0 && joueur[tourjoueur].pos.case_colonne_iso-i<COLONNE2 && joueur[tourjoueur].pos.case_colonne_iso-i>0)
                    {
                        case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].y,0,0,255);
                    }
                    draw_sprite(screen, buffer, 0,0);
                    blit(buffer,temp2,0,0,0,0,SCREEN_W,SCREEN_H);
                }

                if (joueur[tourjoueur].pa > 2){
                while (leave == 0){
                    blit(temp2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                    masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
                    draw_sprite(screen, buffer, 0,0);
                    int k = 4;
                    if (mouse_b & 2){
                        leave =1 ;
                    }
                    if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==0 && getb(getpixel(buffer,mouse_x,mouse_y))==255 && getg(getpixel(buffer,mouse_x,mouse_y))==0) ///si le joueur clique et que la case est accessible
                    {
                        if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28){
                            k = 0;
                        }
                        if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 ){
                            k = 1;
                        }
                        if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28){
                            k = 2;
                        }
                        if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){
                            k = 3;
                        }
                        if (k != 4){
                                int altern = 0;
                                int i = 1;
                                int am;
                                int bm;
                                int j =1 ;
                                int a;
                                int b;
                                a = ((joueur[k].pos.x-joueur[tourjoueur].pos.x)/2);
                                b = ((joueur[k].pos.y-joueur[tourjoueur].pos.y)/2);
                                if (a >= 0){
                                    am  = 0;
                                }
                                if (a < 0){
                                    am = 1;
                                }
                                if (b>= 0){
                                    bm  = 0;
                                }
                                if (b < 0){
                                    bm = 1;
                                }
                                if (am == 0 && bm == 0){
                                    while( i< a || j< b)
                                    {
                                            if (altern == 0)
                                               {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32)); // 128 = 180�
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 1;
                                               }
                                            if (altern == 1)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 2;
                                            }
                                            if (altern == 2)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim3, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
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
                                    while( i > a || j< b)
                                    {
                                            if (altern == 0)
                                               {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 1;
                                               }
                                            if (altern == 1)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 2;
                                            }
                                            if (altern == 2)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
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
                                    while( i< a || j> b)
                                    {
                                            if (altern == 0)
                                               {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 1;
                                               }
                                            if (altern == 1)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                                draw_sprite(screen, buffer, 0,0);
                                                altern = 2;
                                            }
                                            if (altern == 2)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
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
                                    while( i> a || j> b)
                                    {
                                            if (altern == 0)
                                               {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                draw_sprite(screen, buffer, 0,0);

                                                altern = 1;
                                               }
                                            if (altern == 1)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                draw_sprite(screen, buffer, 0,0);

                                                altern = 2;
                                            }
                                            if (altern == 2)
                                            {
                                                blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                rotate_sprite(buffer, perso[1].anim3, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                                draw_sprite(screen, buffer, 0,0);

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
                                leave = 1;
                                if (((rand()%(12-1+1))+1) != 1){ /// 1 chance sur 12 d'échouer
                                    joueur[k].pv -= (rand()%(30-10+1))+10;
                                }

                                joueur[tourjoueur].pa -= 3;
                            }
                    }
                    }
            }
        }
    }

}

void usesortboost (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp,BITMAP* cdp,BITMAP* cursor,BITMAP* temp2,int nbtour,int * blop){

    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 380 && mouse_x < 450){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Vous vous canalisez et gagnez un bonus en fonction de votre classe");
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 380 && mouse_x < 450 && mouse_b & 1){
                case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                draw_sprite(screen, buffer, 0,0);
                blit(buffer,temp2,0,0,0,0,SCREEN_W,SCREEN_H);

                if (joueur[tourjoueur].pa <= 1){

                }
                else{
                    int leave = 0;
                    while (leave == 0){
                        blit(temp2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
                        draw_sprite(screen, buffer, 0,0);

                        if (mouse_b & 2){
                            leave =1 ;
                        }
                        if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==0 && getb(getpixel(buffer,mouse_x,mouse_y))==255 && getg(getpixel(buffer,mouse_x,mouse_y))==0) ///si le joueur clique et que la case est accessible
                        {
                            if (joueur[tourjoueur].classe == 0){
                                joueur[tourjoueur].pa += 3;
                                dureesort[tourjoueur]=1;
                                ancien_nbtour[tourjoueur]=nbtour;
                            }
                            if (joueur[tourjoueur].classe == 1){
                                perso[0].porte += 3;
                                perso[1].porte += 3;
                                *blop = 1;
                                ancien_nbtour[tourjoueur]=nbtour;
                            }
                            if (joueur[tourjoueur].classe == 2){
                                joueur[tourjoueur].pv += 20;
                                ancien_nbtour[tourjoueur]=nbtour;
                            }
                            if (joueur[tourjoueur].classe == 3){
                                joueur[tourjoueur].pm += 2;
                                dureesort[tourjoueur]=1;
                                ancien_nbtour[tourjoueur]=nbtour;
                            }
                            joueur[tourjoueur].pa -= 2;
                            leave = 1;

                        }
                    }
                }
        }
    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 460 && mouse_x < 530){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Un coup au corps a corps qui inflige peu de degat");
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 460 && mouse_x < 530 && mouse_b & 1){

                case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+1][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+1][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-1][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-1][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+1].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+1].y,0,0,255);
                case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-1].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-1].y,0,0,255);
                draw_sprite(screen, buffer, 0,0);
                blit(buffer,temp2,0,0,0,0,SCREEN_W,SCREEN_H);

                if (joueur[tourjoueur].pa <= 1){

                }
                else{

                int leave = 0;
                while (leave == 0){
                    blit(temp2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                    masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
                    draw_sprite(screen, buffer, 0,0);
                    int k = 4;
                    if (mouse_b & 2){
                        leave =1 ;
                    }
                        if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==0 && getb(getpixel(buffer,mouse_x,mouse_y))==255 && getg(getpixel(buffer,mouse_x,mouse_y))==0) ///si le joueur clique et que la case est accessible
                        {
                            if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28){
                                k = 0;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 ){
                                k = 1;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28){
                                k = 2;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){
                                k = 3;
                            }
                            if (k != 4){
                                    int i = 1;
                                    int am;
                                    int bm;
                                    int j =1 ;
                                    int a;
                                    int b;
                                    a = ((joueur[k].pos.x-joueur[tourjoueur].pos.x)/2);
                                    b = ((joueur[k].pos.y-joueur[tourjoueur].pos.y)/2);
                                    if (a >= 0){
                                        am  = 0;
                                    }
                                    if (a < 0){
                                        am = 1;
                                    }
                                    if (b>= 0){
                                        bm  = 0;
                                    }
                                    if (b < 0){
                                        bm = 1;
                                    }
                                    if (am == 0 && bm == 0){
                                        while( i< a || j< b)
                                        {

                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, cdp, joueur[tourjoueur].pos.x+(i),joueur[tourjoueur].pos.y+(j)-45, ftofix(32)); // 128 = 180�
                                                    draw_sprite(screen, buffer, 0,0);
                                                if (i < a){
                                                  i++;
                                                }
                                                if (j< b){
                                                  j++;
                                                }

                                        }
                                    }
                                    if (am == 1 && bm == 0){
                                        while( i > a || j< b)
                                        {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, cdp, joueur[tourjoueur].pos.x+(i) ,joueur[tourjoueur].pos.y+(j)-45, ftofix(96));
                                                    draw_sprite(screen, buffer, 0,0);

                                                if (i > a){
                                                  i--;
                                                }
                                                if (j< b){
                                                  j++;
                                                }
                                        }

                                    }
                                    if (am == 0 && bm == 1){
                                        while( i< a || j> b)
                                        {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, cdp, joueur[tourjoueur].pos.x+(i) ,joueur[tourjoueur].pos.y+(j)-45, ftofix(-32));
                                                    draw_sprite(screen, buffer, 0,0);

                                                if (i < a){
                                                  i++;
                                                }
                                                if (j> b){
                                                  j--;
                                                }
                                        }
                                    }
                                    if (am == 1 && bm == 1){
                                        while( i> a || j> b)
                                        {
                                                    blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                                    rotate_sprite(buffer, cdp, joueur[tourjoueur].pos.x+(i) ,joueur[tourjoueur].pos.y+(j)-45, ftofix(-96));
                                                    draw_sprite(screen, buffer, 0,0);

                                                if (i > a){
                                                  i--;
                                                }
                                                if (j> b){
                                                  j--;
                                                }

                                        }
                                    }

                                leave = 1;
                                if (((rand()%(12-1+1))+1) != 1){   /// 1 chance sur 12 d'échouer
                                    joueur[k].pv -= (rand()%(20-5+1))+5;
                                }
                                attaque(buffer,k);
                                joueur[tourjoueur].pa -= 2;
                            }
                        }


                }
        }

        }
    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 540 && mouse_x < 610){
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance un poison qui infige des degats sur 2 tours");
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 540 && mouse_x < 610 && mouse_b & 1){
                for (int i = 2 ; i < 4 ; i++){
                    case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso+i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                    case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso-i][joueur[tourjoueur].pos.case_colonne_iso].y,0,0,255);
                    case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso+i].y,0,0,255);
                    case_couleur(buffer,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].x,matrice_terrain_iso[joueur[tourjoueur].pos.case_ligne_iso][joueur[tourjoueur].pos.case_colonne_iso-i].y,0,0,255);
                    draw_sprite(screen, buffer, 0,0);
                    blit(buffer,temp2,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (joueur[tourjoueur].pa <= 2){

                }
                else{

                    int leave = 0;
                    while (leave == 0){
                        blit(temp2,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
                        draw_sprite(screen, buffer, 0,0);
                        int k = 4;
                        if (mouse_b & 2){
                            leave =1 ;
                        }
                        if(mouse_b&1 && getr(getpixel(buffer,mouse_x,mouse_y))==0 && getb(getpixel(buffer,mouse_x,mouse_y))==255 && getg(getpixel(buffer,mouse_x,mouse_y))==0) ///si le joueur clique et que la case est accessible
                        {
                            if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28){
                                k = 0;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 ){
                                k = 1;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28){
                                k = 2;
                            }
                            if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){
                                k = 3;
                            }
                            if (k!=4){

                                cible = k;
                                joueur[tourjoueur].pa -= 2;
                                leave  = 1;
                            }
                        }
                    }
                }
        }
    }
}

double fin_de_tour (BITMAP* buffer)
{
    rectfill(buffer,700,650,880,700,makecol(242,143,45));
    textprintf_ex(buffer,font,745,670,makecol(0,0,0),makecol(242,143,45),"FIN DE TOUR");
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 700 && mouse_x < 880 && mouse_b&1)
    {
        while (mouse_b&1)                 ///blindage click gauche
        {
            rest(150);
        }
        return 15;
    }
}

int checkwin(int nbre_joueurs,int i) /// sspg qui verifie si il y a un vainqueur ou non
{
    if (i==nbre_joueurs)
    {
        return 0;
    }
    if (joueur[i].pv <= 0)
    {
        return 1+checkwin(nbre_joueurs,i+1);
    }
    else
        return 0+checkwin(nbre_joueurs,i+1);
}
