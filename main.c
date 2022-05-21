#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 700, 0,0)!=0)         ///1272,700
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
}


int main()
{
    srand(time(NULL));
    initialisation();

    int nbrjoueur;
    nbrjoueur = menu();

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 700, 0,0)!=0)         ///1272,700
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    tourjoueur = 0;

    BITMAP* cursor = load_bitmap("cursor.bmp", NULL);

    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* petit_coeur = load_bitmap("petit_coeur.bmp",NULL);
    BITMAP* buffer_enlevage_indication = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_enlevage_indication2 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_enlevage = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_deplacement2 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_deplacement = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* temp = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_invisible_couleur = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* player [nbrjoueur];
    player[0] = create_bitmap(SCREEN_W, SCREEN_H);
    player[1] = create_bitmap(SCREEN_W, SCREEN_H);
    player[2] = create_bitmap(SCREEN_W, SCREEN_H);
    player[3] = create_bitmap(SCREEN_W, SCREEN_H);
    animation perso1 [4] [4];



    for (int i = 0 ; i <4 ; i++)
    {
        rectfill(player[i],0,0,1272,713,makecol(255,0,255));
    }

    sortperso sortjoueur [nbrjoueur];

    int ennemi;

    init_struct_case(nbrjoueur);
    terrain_couleur(buffer_invisible_couleur);
    quadrillage(terrain,terrain);
    affichage_terrain(terrain,buffer);
    for (int i = 0 ; i< nbrjoueur ; i ++){
        if (joueur[i].classe == 1){
             load_mage_eau(&sortjoueur[i]);
            load_anim_mage_eau_vague(&perso1[i][0]);
            load_anim_mage_eau_flaque(&perso1[i][1]);
        }
        if (joueur[i].classe == 2){
            load_cra_feu(&sortjoueur[i]);
            load_anim_cra_feu_bdf(&perso1[i][0]);
            load_anim_cra_feu_fleche_feu(&perso1[i][1]);
        }

    }


    init_joueur(nbrjoueur,joueur);
    recuperation_couleur(terrain, buffer_enlevage_indication);
    recuperation_couleur(buffer_deplacement,buffer_deplacement2);
    int nb_mort=0;

    while (!key[KEY_ESC] && nb_mort!=nbrjoueur-1)
    {
        show_mouse(screen);
        if (tourjoueur > nbrjoueur - 1)
        {
            tourjoueur = 0;
        }
        for (int i=0;i<nbrjoueur;i++)
        {
             while(joueur[i].pos.case_ligne_iso==0 || joueur[i].pos.case_colonne_iso==0 )
            {
                placement_joueur_debut(buffer,buffer_invisible_couleur,nbrjoueur,cursor,buffer_enlevage);
            }
        }
        enlevage_des_indications(buffer,buffer_enlevage_indication);

        clock_t debut, fin ;
        long clk_tck = CLOCKS_PER_SEC ;
        double difference ;
        double difference2;
        int compteur_respiration=0;
        debut=clock() ;
    do
    {
        affichage_terrain(terrain,buffer);

        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);

        tour(buffer, nbrjoueur, tourjoueur);
        barre_de_vie(buffer, nbrjoueur, tourjoueur);

        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur, buffer_deplacement,buffer_enlevage_indication,buffer_deplacement2,nbrjoueur);

        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);
        draw_sprite(buffer, player[tourjoueur], 0,0);
        usesort(buffer,perso1[tourjoueur],temp);
        usesortboost(buffer,perso1[tourjoueur],temp);
        textprintf_ex(buffer,font,905,460,makecol(255,255,255),makecol(64,47,32),"Joueur 1 lance une boule de feu !");
        textprintf_ex(buffer,font,905,470,makecol(255,255,255),makecol(64,47,32),"Joueur 2 - 45 pv");
        fin=clock() ;
        difference = (double)(fin-debut)/(double)clk_tck;
        textprintf_ex(buffer,font,905,480,makecol(255,255,255),makecol(64,47,32),"%lf", difference);
        circlefill(buffer, 1240, 490, 30-(difference*2), makecol(255,0,0));

        difference2 = fin_de_tour(buffer);
        affichage_pv(buffer,petit_coeur);
        if (compteur_respiration % 100==0)
        {
            respirer(buffer,terrain,nbrjoueur,buffer_enlevage_indication2);
            compteur_respiration=0;
        }
        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        enlevage_des_indications(buffer,terrain);
        compteur_respiration++;

    }while(difference2<15 && difference<15);

    sauvegarde(nbrjoueur, tourjoueur);

    clear_bitmap(buffer_deplacement);
    clear_bitmap(buffer_deplacement2);
    joueur[tourjoueur].pm=3;
    joueur[tourjoueur].pa=6;
    tourjoueur ++;
    nb_mort=checkwin(nbrjoueur,0);
    //retrait(nbrjoueur, tourjoueur);

    }
    return 0;

}END_OF_MAIN();
