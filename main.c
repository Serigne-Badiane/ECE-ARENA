#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "bib.h"
#include <time.h>


void initialisation()               ///initialisation de allegro
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
    //show_mouse(screen);
}

int main()
{
    cible=5;                ///utilisé pour le sort de poison
    compteur=0;             ///sort poison
    int direct = 0;
    srand(time(NULL));          ///pour les randoms
    initialisation();
    //direct = menudefin();
    int nbtour=1;           ///variable qui calcul le nombre de tours joués

    int nbrjoueur;          ///le nombre de joueur qui joue
    nbrjoueur = menu(direct);
    sauvegarde(nbrjoueur, tourjoueur);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1272, 700, 0,0)!=0)         ///1272,700
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    tourjoueur = 0;         ///variable pour savoir qui doit jouer dans le tour

    BITMAP* cursor = load_bitmap("cursor.bmp", NULL);

    BITMAP* terrain= load_bitmap("vrai_map.bmp", NULL);
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* cdp = load_bitmap("coup_de_poing.bmp",NULL);
    BITMAP* petit_coeur = load_bitmap("petit_coeur.bmp",NULL);
    BITMAP* buffer_enlevage_indication = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_enlevage_indication2 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_enlevage = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* temp1 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* temp2 = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* buffer_invisible_couleur = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
    BITMAP* player [nbrjoueur];
    player[0] = create_bitmap(SCREEN_W, SCREEN_H);
    player[1] = create_bitmap(SCREEN_W, SCREEN_H);
    player[2] = create_bitmap(SCREEN_W, SCREEN_H);
    player[3] = create_bitmap(SCREEN_W, SCREEN_H);
    int ttour;
    int blop;
    animation perso1 [4] [4];



    for (int i = 0 ; i <4 ; i++)
    {
        rectfill(player[i],0,0,1272,713,makecol(255,0,255));
    }

    sortperso sortjoueur [nbrjoueur];

    int ennemi;

    init_struct_case(nbrjoueur);
    terrain_couleur(buffer_invisible_couleur);
    ///quadrillage(terrain,terrain);                 ///quadrille la map (possibilit� de le mettre au choix)
    affichage_terrain(terrain,buffer);
    for (int i = 0 ; i< nbrjoueur ; i ++){
        if (joueur[i].classe == 0){
            load_mage_eau(&sortjoueur[i]);
            load_anim_mage_eau_vague(&perso1[i][0]);
            load_anim_mage_eau_flaque(&perso1[i][1]);
        }
        if (joueur[i].classe == 1){
            load_cra_feu(&sortjoueur[i]);
            load_anim_cra_feu_bdf(&perso1[i][0]);
            load_anim_cra_feu_fleche_feu(&perso1[i][1]);
        }
        if (joueur[i].classe == 2){
            load_guerrier(&sortjoueur[i]);
            load_anim_coco(&perso1[i][0]);
            load_anim_epee_iop(&perso1[i][1]);
        }
        if (joueur[i].classe == 3){
            load_tigre(&sortjoueur[i]);
            load_anim_tigr(&perso1[i][0]);
            load_anim_lance(&perso1[i][1]);

        }

    }


    init_joueur(nbrjoueur,joueur);
    recuperation_couleur(terrain, buffer_enlevage_indication);
    //recuperation_couleur(buffer_deplacement,buffer_deplacement2);
    int nb_mort=0;

    while (!key[KEY_ESC] && nb_mort!=nbrjoueur-1)
    {
        //show_mouse(screen);
        if (tourjoueur > nbrjoueur - 1)
        {
            tourjoueur = 0;
        }

        for (int i=0;i<nbrjoueur;i++)
        {
             while(joueur[i].pos.case_ligne_iso==0 && joueur[i].pos.case_colonne_iso==0 )
            {
                placement_joueur_debut(buffer,buffer_invisible_couleur,nbrjoueur,cursor,buffer_enlevage);
            }
        }
        enlevage_des_indications(buffer,buffer_enlevage_indication);

        clock_t debut, fin ;
        long clk_tck = CLOCKS_PER_SEC ;
        double difference=0 ;
        double difference2=0;
        int compteur_respiration=0;
        int ancienne_ligne_joueur=0;
        int ancienne_colonne_joueur=0;
        debut=clock();

    do
    {
        affichage_terrain(terrain,buffer);

        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);

        tour(buffer, nbrjoueur, tourjoueur);
        barre_de_vie(buffer, nbrjoueur, tourjoueur);

        ancienne_ligne_joueur=joueur[tourjoueur].pos.case_ligne_iso;
        ancienne_colonne_joueur=joueur[tourjoueur].pos.case_colonne_iso;

        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur,buffer_enlevage_indication,nbrjoueur,nbtour);


        masked_blit(cursor,buffer, 9, 0,mouse_x, mouse_y, cursor->w, cursor->h);
        draw_sprite(buffer, player[tourjoueur], 0,0);
        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);
        usesort(buffer,perso1[tourjoueur],temp1,cursor,temp2);
        usesortboost(buffer,perso1[tourjoueur],temp1,cdp,cursor,temp2,nbtour,&blop);
        if (cible != 5 && ttour == 0 && tourjoueur==cible){
           poison();
           ttour=1;
        }

        fin=clock() ;
        difference = (double)(fin-debut)/(double)clk_tck;
        textprintf_ex(buffer,font,1000,0,makecol(255,255,255),makecol(153,217,234),"Il vous reste que %.0lf secondes", 15-difference);
        //circlefill(buffer, 1240, 490, 30-(difference*2), makecol(255,0,0));

        difference2 = fin_de_tour(buffer);
        affichage_pv(buffer,petit_coeur);

        bonus(buffer,ancienne_ligne_joueur,ancienne_colonne_joueur);

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
    if (blop == 1){
        perso1[tourjoueur][0].porte -= 3;
        perso1[tourjoueur][1].porte -= 3;
        blop = 0;
    }
    ttour=0;
    joueur[tourjoueur].pm=3;
    joueur[tourjoueur].pa=6;
    tourjoueur ++;
    if(joueur[tourjoueur].pv<=0)
    {
        joueur[tourjoueur].pv=0;
        joueur[tourjoueur].tourfinal = nbtour;
        tourjoueur++;
    }
    nbtour+=1;
    nb_mort=checkwin(nbrjoueur,0);



    //retrait(nbrjoueur, tourjoueur);

    }


    direct = menudefin(nbrjoueur, nbtour);
    return 0;

}END_OF_MAIN();
