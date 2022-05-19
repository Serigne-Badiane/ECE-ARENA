#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

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
    perso->sort3= load_bitmap("feu_oku.bmp",NULL);
    perso->sort4 = load_bitmap("cac_feu.bmp",NULL);

}

/*void load_cra_feu_anim(sortperso* perso){
    perso->animsort1->anim1 = load_bitmap("bdf1.bmp",NULL);
    perso->animsort1->anim2 = load_bitmap("bdf2.bmp",NULL);
    perso->animsort1->anim3 = load_bitmap("bdf3.bmp",NULL);

}*/
void load_anim_cra_feu_bdf (animation* perso){
    perso->anim1 = load_bitmap("bdf1.bmp",NULL);
    perso->anim2 = load_bitmap("bdf2.bmp",NULL);
    perso->anim3 = load_bitmap("bdf3.bmp",NULL);
}

void load_anim_cra_feu_fleche_feu (animation* perso){
    perso->anim1 = load_bitmap("fleche_feu.bmp",NULL);
    perso->anim2 = load_bitmap("fleche_feu.bmp",NULL);
    perso->anim3 = load_bitmap("fleche_feu.bmp",NULL);
}

void load_mage_eau (sortperso* perso){
    perso->sort1 = load_bitmap("vague.bmp",NULL);
    perso->sort2 = load_bitmap("propulsion.bmp",NULL);
    perso->sort3= load_bitmap("protection.bmp",NULL);
    perso->sort4 = load_bitmap("vision.bmp",NULL);

}

void load_anim_mage_eau_vague(animation* perso){
    perso->anim1 = load_bitmap("vague1.bmp",NULL);
    perso->anim2 = load_bitmap("vague2.bmp",NULL);
    perso->anim3 = load_bitmap("vague3.bmp",NULL);
}

void load_anim_mage_eau_flaque(animation* perso){
    perso->anim1 = load_bitmap("flaque1.bmp",NULL);
    perso->anim2 = load_bitmap("flaque2.bmp",NULL);
    perso->anim3 = load_bitmap("flaque3.bmp",NULL);
}
void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [tourjoueur]){
        rectfill(buffer,0,650,1272,713,makecol(130,98,85));
        rectfill(buffer,900,450,1272,650,makecol(64,47,32));
        blit(perso.sort1, buffer ,0,0,220,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort2, buffer ,0,0,300,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort3, buffer ,0,0,380,650,perso.sort1->h,perso.sort1->w);
        blit(perso.sort4, buffer ,0,0,460,650,perso.sort1->h,perso.sort1->w);
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

         rectfill(buffer,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 60,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 40,makecol(0,0,0));
         draw_sprite(screen, buffer, 0,0);

    }
    if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28){

         rectfill(buffer,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 40,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 80,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x + 40,matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 40,makecol(0,0,0));
         draw_sprite(screen, buffer, 0,0);

    }



}


void usesort (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp){
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290){
        blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);

        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une boule de feu qui infliche 45pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 220 && mouse_x < 290 && mouse_b & 1){
                int leave;
                if (joueur[tourjoueur].pa <= 3){

                }
                else {
                while (leave == 0 || mouse_b & 1){
                    int k = 4;
                    if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 0;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 1;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 2;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28 && mouse_b & 1){
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
                                            //blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                                            //draw_sprite(screen, buffer, 0,0);

                                            rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32)); // 128 = 180�
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            //blit(bdf2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- bdf2->w,joueur[tourjoueur].pos.y+(2*j), bdf2->w, bdf2->h);
                                            //draw_sprite(screen, buffer, 0,0);

                                            rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            //blit(bdf3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- bdf3->w,joueur[tourjoueur].pos.y+(2*j), bdf3->w, bdf3->h);
                                            //draw_sprite(screen, buffer, 0,0);

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
                                            /*blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            */

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
                                           /* blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                           /* blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            draw_sprite(screen, buffer, 0,0);*/

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
                                            /*blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                            draw_sprite(screen, buffer, 0,0);

                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[0].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                            draw_sprite(screen, buffer, 0,0);

                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            draw_sprite(screen, buffer, 0,0);*/

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
                            joueur[k].pv -= (rand()%(40-20+1))+20;
                            joueur[tourjoueur].pa -= 4;
                            leave = 1;
                        }
                }
            }
        }


    }
    if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370){
         blit(buffer,temp,0,0,0,0,SCREEN_W,SCREEN_H);
        textprintf_ex(buffer,font,220,640,makecol(255,0,0),makecol(255,255,255),"Lance une fleche enflamee qui inflige 30pt de degat");
        if (mouse_y > 650 && mouse_y < 713 && mouse_x > 300 && mouse_x < 370 && mouse_b & 1){
                int leave;
                if (joueur[tourjoueur].pa <= 2){

                }
                else{
                while (leave == 0 || mouse_b & 1){
                    int k = 4;
                    if (mouse_y > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[0].pos.case_ligne_iso][joueur[0].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 0;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[1].pos.case_ligne_iso][joueur[1].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 1;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[2].pos.case_ligne_iso][joueur[2].pos.case_colonne_iso].x +28 && mouse_b & 1){
                        k = 2;
                    }
                    if (mouse_y > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y - 45  && mouse_y < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].y + 25 && mouse_x > matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x - 28 && mouse_x < matrice_terrain_iso[joueur[3].pos.case_ligne_iso][joueur[3].pos.case_colonne_iso].x +28 && mouse_b & 1){
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
                                            //blit(bdf1, buffer, 0, 0, joueur1.pos.x+(2*i) - bdf1->w,joueur1.pos.y+(2*j), bdf1->w, bdf1->h);
                                            //draw_sprite(screen, buffer, 0,0);

                                            rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i),joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32)); // 128 = 180�
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            //blit(bdf2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- bdf2->w,joueur[tourjoueur].pos.y+(2*j), bdf2->w, bdf2->h);
                                            //draw_sprite(screen, buffer, 0,0);

                                            rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            //blit(bdf3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- bdf3->w,joueur[tourjoueur].pos.y+(2*j), bdf3->w, bdf3->h);
                                            //draw_sprite(screen, buffer, 0,0);

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
                                            /*blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(96));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            */

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
                                           /* blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-32));
                                            draw_sprite(screen, buffer, 0,0);
                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                           /* blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            draw_sprite(screen, buffer, 0,0);*/

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
                                            /*blit(perso[0].animsort1.anim1, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim1->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim1->w, perso[0].animsort1.anim1->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim1, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                            draw_sprite(screen, buffer, 0,0);

                                            altern = 1;
                                           }
                                        if (altern == 1)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim2, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim2->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim2->w, perso[0].animsort1.anim2->h);
                                            draw_sprite(screen, buffer, 0,0);*/

                                            rotate_sprite(buffer, perso[1].anim2, joueur[tourjoueur].pos.x+(2*i) ,joueur[tourjoueur].pos.y+(2*j)-45, ftofix(-96));
                                            draw_sprite(screen, buffer, 0,0);

                                            altern = 2;
                                        }
                                        if (altern == 2)
                                        {
                                            blit(temp,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
                                            /*blit(perso[0].animsort1.anim3, buffer, 0, 0, joueur[tourjoueur].pos.x+(2*i)- perso[0].animsort1.anim3->w,joueur[tourjoueur].pos.y+(2*j), perso[0].animsort1.anim3->w, perso[0].animsort1.anim3->h);
                                            draw_sprite(screen, buffer, 0,0);*/

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
                            joueur[k].pv -= (rand()%(30-10+1))+10;
                            joueur[tourjoueur].pa -= 3;
                        }
                }
            }
        }
    }

}

void usesortboost (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp){

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


int checkwin(int nbre_joueurs){
    for (int i = 0 ; i < nbre_joueurs -1 ; i ++){
        if (joueur[i].pv <= 0){
            return 1;
        }
    }
}
