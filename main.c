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
    int tourjoueur;

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
    load_cra_feu(&sortjoueur[0]);
    load_mage_eau(&sortjoueur[1]);
    int ennemi;

    //menu();
    init_struct_case();
    terrain_couleur(buffer_invisible_couleur);
    quadrillage(terrain,terrain);
    affichage_terrain(terrain,buffer);
    load_cra_feu(&sortjoueur[0]);
    load_anim_cra_feu_bdf(&perso1[0][0]);
    load_anim_cra_feu_fleche_feu(&perso1[0][1]);
    load_anim_mage_eau_vague(&perso1[1][0]);
    load_anim_mage_eau_flaque(&perso1[1][1]);

    while (!key[KEY_ESC])
    {
        int compteur_pour_enlever_les_indics=0;
        if (tourjoueur > nbrjoueur - 1){
            tourjoueur = 0;
        }
        if (tourjoueur == 0){
            ennemi = 1;
        }
        else{
            ennemi = 0;
        }
        for (int i=0;i<nbrjoueur;i++)
        {
             while(joueur[i].pos.case_ligne_iso==0 || joueur[i].pos.case_colonne_iso==0 )
            {
                placement_joueur_debut(buffer,buffer_invisible_couleur,buffer_enlevage_indication,nbrjoueur);
            }
        }

        //chrono(terrain, buffer);
        //deplacement(terrain,buffer, buffer_invisible_couleur);
        //deplacement_p2(terrain,buffer,buffer_invisible_couleur);

        init_joueur(nbrjoueur,joueur);

        clock_t debut, fin ;
        long clk_tck = CLOCKS_PER_SEC ;
        double difference ;
        /*for (int i=0;i<LIGNE2;i++)
        {
            for (int j=0;j<COLONNE2;j++)
            {
                if (matrice_terrain_iso[i][j].placement_debut==2)
                {
                    case_couleur(buffer,matrice_terrain_iso[i][j].x,matrice_terrain_iso[i][j].y,80,80,80);
                }
            }
        }*/

        debut=clock() ;
        do
        {
        fin=clock() ;
        difference = (double)(fin-debut)/(double)clk_tck ;

        deplacement(terrain, buffer_deplacement, buffer_invisible_couleur, tourjoueur,buffer,buffer_enlevage_indication,compteur_pour_enlever_les_indics,buffer_deplacement2);
        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur, buffer_deplacement,buffer_enlevage_indication,buffer_deplacement2,nbrjoueur);

        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);
        draw_sprite(buffer, player[tourjoueur], 0,0);
        usesort(buffer,perso1[tourjoueur],joueur[tourjoueur],joueur[ennemi],temp);
        textprintf_ex(buffer,font,905,460,makecol(255,255,255),makecol(64,47,32),"Joueur 1 lance une boule de feu !");
        textprintf_ex(buffer,font,905,470,makecol(255,255,255),makecol(64,47,32),"Joueur 2 - 45 pv");
        draw_sprite(screen, buffer, 0,0);
        //draw_sprite(screen, buffer_deplacement, 0,0);
        compteur_pour_enlever_les_indics++;
        }while(difference<15);

    //textprintf_ex(terrain,font,50,400,makecol(255,255,255),makecol(255,0,0),"Fin de tour ca fait %.2lf secondes", difference);
    clear_bitmap(buffer_deplacement);
    clear_bitmap(buffer_deplacement2);
    clear_bitmap(buffer_enlevage_indication);

    tourjoueur ++;

    }
    return 0;

}END_OF_MAIN();
