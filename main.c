#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>

void initialisation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 713, 0,0)!=0)         ///1272,713
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
    str_perso joueur [nbrjoueur];
    joueur[0].x = 200;
    joueur[0].y = 400;
    joueur[1].x = 400;
    sortperso sortjoueur [nbrjoueur];
    load_cra_feu(&sortjoueur[0]);
    load_mage_eau(&sortjoueur[1]);


    //menu();
    init_struct_case();
    terrain_couleur(buffer_invisible_couleur);

    while (!key[KEY_ESC])
    {
        if (tourjoueur > nbrjoueur - 1){
            tourjoueur = 0;
        }
        affichage_terrain(terrain,buffer);
        /*for(int i=0;i<LIGNE;i++)
        {
            for(int j=0;j<COLONNE;j++)
            {
                if(matrice_terrain[i][j].passage==0)
                {
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,200,200,200);
                }
                if(matrice_terrain[i][j].passage==1)
                {
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,250,200,150);
                }
                if(matrice_terrain[i][j].passage==2)
                {
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,100,50,200);
                }
                if(matrice_terrain[i][j].passage==3)
                {
                    case_couleur(buffer,matrice_terrain[i][j].x,matrice_terrain[i][j].y,200,20,200);
                }
            }
        }*/
        while(play[0].case_ligne==0 || play[0].case_colonne==0 || play[1].case_ligne==0 || play[1].case_colonne==0 || play[2].case_ligne==0 || play[2].case_colonne==0 || play[3].case_ligne==0 || play[3].case_colonne==0)
        {
            placement_joueur_debut(buffer,buffer_invisible_couleur);
        }
        //chrono(terrain, buffer);
        deplacement(terrain,buffer, buffer_invisible_couleur);
        deplacement_p2(terrain,buffer,buffer_invisible_couleur);

        init_joueur(nbrjoueur,joueur);

        quadrillage(buffer,terrain);
        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);

        draw_sprite(buffer, player[tourjoueur], 0,0);
        usesort(buffer,bdf1,bdf2,bdf3,joueur[tourjoueur],joueur[1]);
        textprintf_ex(buffer,font,905,460,makecol(255,255,255),makecol(64,47,32),"Joueur 1 lance une boule de feu !");
        textprintf_ex(buffer,font,905,470,makecol(255,255,255),makecol(64,47,32),"Joueur 2 - 45 pv");

        draw_sprite(screen, buffer, 0,0);
        tourjoueur ++;

        //rest(500);
    }
    return 0;

}END_OF_MAIN();
