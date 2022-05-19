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

    int classe_perso;

    //menu(&nbre_joueurs,&classe_perso);

    tourjoueur = 0;
    int game_over;

    BITMAP* cursor = load_bitmap("cursor.bmp", NULL);

    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_enlevage_indication = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_deplacement2 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_deplacement = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP* temp = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_invisible_couleur = create_bitmap(SCREEN_W, SCREEN_H);
    int nbrjoueur = 2;
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
    BITMAP* petit_coeur = load_bitmap("petit_coeur.bmp",NULL);

    init_struct_case(nbrjoueur);
    terrain_couleur(buffer_invisible_couleur);
    quadrillage(terrain,terrain);
    affichage_terrain(terrain,buffer);
    load_cra_feu(&sortjoueur[1]);
    load_anim_cra_feu_bdf(&perso1[1][0]);
    load_anim_cra_feu_fleche_feu(&perso1[1][1]);
    load_mage_eau(&sortjoueur[0]);
    load_anim_mage_eau_vague(&perso1[0][0]);
    load_anim_mage_eau_flaque(&perso1[0][1]);
    init_joueur(nbrjoueur,joueur);
    recuperation_couleur(terrain, buffer_enlevage_indication);
    recuperation_couleur(buffer_deplacement,buffer_deplacement2);


    while (!key[KEY_ESC])
    {

        masked_blit(cursor, terrain ,0, 0,mouse_x, mouse_y, cursor->w, cursor->h);

        if (tourjoueur > nbrjoueur - 1)
        {
            tourjoueur = 0;
        }
        for (int i=0;i<nbrjoueur;i++)
            {
             while(joueur[i].pos.case_ligne_iso==0 || joueur[i].pos.case_colonne_iso==0 )
            {
                placement_joueur_debut(buffer,buffer_invisible_couleur,buffer_enlevage_indication,nbrjoueur);
            }
        }
        enlevage_des_indications(buffer,buffer_enlevage_indication);

        clock_t debut, fin ;
        long clk_tck = CLOCKS_PER_SEC ;
        double difference ;
        double difference2;

        debut=clock() ;
    do
    {
        affichage_terrain(terrain,buffer);

        barre_de_vie(buffer, nbrjoueur, tourjoueur);
        tour(buffer, nbrjoueur, tourjoueur);



        deplacement(terrain, buffer_deplacement, buffer_invisible_couleur, tourjoueur);
        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur, buffer_deplacement,buffer_enlevage_indication,buffer_deplacement2,nbrjoueur);

        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);

        draw_sprite(buffer, player[tourjoueur], 0,0);
        usesort(buffer,perso1[tourjoueur],temp);
        usesortboost(buffer,perso1[tourjoueur],temp);
        /*if (checkwin(nbrjoueur) ==  1){
            blit (player[3],screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest (500);
            game_over = 1;
            break;
        }*/
        textprintf_ex(buffer,font,905,460,makecol(255,255,255),makecol(64,47,32),"Joueur 1 lance une boule de feu !");
        textprintf_ex(buffer,font,905,470,makecol(255,255,255),makecol(64,47,32),"Joueur 2 - 45 pv");


        fin=clock() ;
        difference = (double)(fin-debut)/(double)clk_tck;
        textprintf_ex(buffer,font,905,480,makecol(255,255,255),makecol(64,47,32),"%lf", difference);

        circlefill(buffer, 1240, 490, 30-(difference*2), makecol(255,0,0));

        difference = fin_de_tour(buffer);
        affichage_pv(buffer,petit_coeur);
        masked_blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        enlevage_des_indications(buffer,terrain);

    }while(difference2<15 && difference<15);

    if (game_over == 1){
        break;
    }
    sauvegarde(nbrjoueur, tourjoueur);

    clear_bitmap(buffer_deplacement);
    clear_bitmap(buffer_deplacement2);
    joueur[tourjoueur].pm=3;
    joueur[tourjoueur].pa=6;
    tourjoueur ++;

    //retrait(nbrjoueur, tourjoueur);

    }
    return 0;

}END_OF_MAIN();
