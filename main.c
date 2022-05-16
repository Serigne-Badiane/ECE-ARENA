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
    BITMAP* bdf1 = load_bitmap("bdf1.bmp", NULL);
    BITMAP* bdf2 = load_bitmap("bdf2.bmp", NULL);
    BITMAP* bdf3 = load_bitmap("bdf3.bmp", NULL);
    BITMAP* temp = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_invisible_couleur = create_bitmap(SCREEN_W, SCREEN_H);
    int nbrjoueur = 2;
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* player [nbrjoueur];
    player[0] = create_bitmap(SCREEN_W, SCREEN_H);
    player[1] = create_bitmap(SCREEN_W, SCREEN_H);
    player[2] = create_bitmap(SCREEN_W, SCREEN_H);
    player[3] = create_bitmap(SCREEN_W, SCREEN_H);
    for (int i = 0 ; i <4 ; i++)
        {
        rectfill(player[i],0,0,1272,713,makecol(255,0,255));
        }
    joueur[0].pos.x = 200;
    joueur[0].pos.y = 400;
    joueur[1].pos.x = 400;
    sortperso sortjoueur [nbrjoueur];
    load_cra_feu(&sortjoueur[0]);
    load_mage_eau(&sortjoueur[1]);


    //menu();
    init_struct_case();
    terrain_couleur(buffer_invisible_couleur);
    terrain_deplacement(buffer_deplacement);
    quadrillage(terrain,terrain);
    affichage_terrain(terrain,buffer);

    while (!key[KEY_ESC])
    {
        int compteur_pour_enlever_les_indics=0;
        if (tourjoueur > nbrjoueur - 1){
            tourjoueur = 0;
        }
        while(joueur[0].pos.case_ligne==0 || joueur[0].pos.case_colonne==0 || joueur[1].pos.case_ligne==0 || joueur[1].pos.case_colonne==0 || joueur[2].pos.case_ligne==0 || joueur[2].pos.case_colonne==0 || joueur[3].pos.case_ligne==0 || joueur[3].pos.case_colonne==0)
        {
            placement_joueur_debut(buffer,buffer_invisible_couleur,buffer_enlevage_indication);
        }
        //chrono(terrain, buffer);
        //deplacement(terrain,buffer, buffer_invisible_couleur);
        //deplacement_p2(terrain,buffer,buffer_invisible_couleur);

        init_joueur(nbrjoueur,joueur);

        clock_t debut, fin ;
        long clk_tck = CLOCKS_PER_SEC ;
        double difference ;

        debut=clock() ;
        do
        {
        fin=clock() ;
        difference = (double)(fin-debut)/(double)clk_tck ;

        deplacement(terrain, buffer_deplacement, buffer_invisible_couleur, tourjoueur,buffer,buffer_enlevage_indication,compteur_pour_enlever_les_indics,buffer_deplacement2);
        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur, buffer_deplacement,buffer_enlevage_indication,buffer_deplacement2,nbrjoueur);

        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);
        draw_sprite(buffer, player[tourjoueur], 0,0);
        usesort(buffer,bdf1,bdf2,bdf3,joueur[tourjoueur],joueur[1]);
        textprintf_ex(buffer,font,905,460,makecol(255,255,255),makecol(64,47,32),"Joueur 1 lance une boule de feu !");
        textprintf_ex(buffer,font,905,470,makecol(255,255,255),makecol(64,47,32),"Joueur 2 - 45 pv");

        draw_sprite(screen, buffer, 0,0);
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
