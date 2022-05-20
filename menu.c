#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

void menu(int* nbre_joueur, int* classe_perso_joueur1, int* classe_perso_joueur2 , int* classe_perso_joueur3 , int* classe_perso_joueur4)
{
    BITMAP* decor;
    BITMAP* page;
    /*BITMAP* page2;*/
    BITMAP* page3;
    BITMAP* Logo;
    BITMAP* NewGame;
    BITMAP* Credits;
    BITMAP* Regles;
    BITMAP* Menu2;
    BITMAP* Sorcier[2];

    BITMAP* nbre_joueurs;
    BITMAP* cursor;
    BITMAP* serigne;
    BITMAP* victor;
    BITMAP* julien;
    BITMAP* paul;
    BITMAP* bordure;





    SAMPLE *son;

    char NomFichier[30];




    /*allegro_init();
    install_keyboard();
    install_mouse();*/

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    son = load_wav("clash-of-clans-raiding-musicvolume-increased.wav");


    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {
        printf("Error initialising sound: %s\n", allegro_error);

    }

    if (!son) {
      allegro_message("Error avec le fichier .wav ");

   }


    /*set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }*/

    play_sample(son, 255, 128, 1000, 1);

    Logo=load_bitmap("Logo.bmp",NULL);
    decor=load_bitmap("decordo.bmp",NULL);



    NewGame=load_bitmap("NewGame.bmp",NULL);
    Credits=load_bitmap("Credits.bmp", NULL);
    Regles=load_bitmap("Regles.bmp", NULL);
    cursor=load_bitmap("cursor.bmp",NULL);

    serigne=load_bitmap("serigne.bmp",NULL);
    victor=load_bitmap("victor.bmp",NULL);
    paul=load_bitmap("paul.bmp",NULL);
    julien=load_bitmap("julien.bmp",NULL);





    for (int i = 1; i < 3; i++){

        sprintf(NomFichier,"player/player%dbis.bmp",i);

        Sorcier[i] = load_bitmap(NomFichier,NULL);



        if (!Sorcier[i]){

            allegro_message( "pas pu trouver %s",NomFichier);

            exit( EXIT_FAILURE );

        }

    }




    page=create_bitmap(SCREEN_W,SCREEN_H);
    //page2=create_bitmap(SCREEN_W,SCREEN_H);
    Menu2=create_bitmap(SCREEN_W,SCREEN_H);
    page3=create_bitmap(SCREEN_W,SCREEN_H);



    clear_bitmap(page);
    if (!decor)
    {
        allegro_message("pas pu trouver ");
        exit(EXIT_FAILURE);
    }

    int cptimage = 0;
    int tmpimage = 2;
    int imgcourante = 1;
    int sortie = 0;


    while (!key[KEY_ESC] && sortie != 1)
    {

        masked_blit(cursor, page, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur

        cptimage++;
        if (cptimage>=tmpimage){ // Animation sorcier dans le menu
            cptimage=0;

            imgcourante++;
        }

        /*show_mouse(page);*/


        rect(page,500,300,850,400,makecol(255,0,0));
        rect(page,500,450,850,550,makecol(255,0,0));
        rect(page,500,600,850,700,makecol(255,0,0));

        masked_blit(Logo, page, 0, 0, 100, 100, Logo->w, Logo->h);
        masked_blit(NewGame, page, 0, 0, 548, 320, Logo->w, Logo->h);
        masked_blit(Regles, page, 0, 0, 560, 616, Logo->w, Logo->h);
        masked_blit(Credits, page, 0, 0, 560, 468, Logo->w, Logo->h);

        /*masked_blit(Sorcier[imgcourante],page, 0, 0, 200, 468, Logo->w, Logo->h);*/





        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);


        draw_sprite(page,Sorcier[imgcourante],200,468);



        if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850) /// Petite animation quand on passe la souris
        {


            rect(screen,500,300,850,400,makecol(0,255,255));


            if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b&1) /// Click sur New Game
            {
                masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur

                BITMAP* deux;
                BITMAP* trois;
                BITMAP* quatre;

                nbre_joueurs=load_bitmap("nbrejoueurs.bmp",NULL);
                deux=load_bitmap("deux.bmp", NULL);
                trois=load_bitmap("trois.bmp", NULL);
                quatre=load_bitmap("quatre.bmp", NULL);

                clear_bitmap(page);

                rest(200);

                while (!key[KEY_ENTER]) /// Retour en arriere
                {
                     masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h);

                    /*show_mouse(Menu2);*/

                    blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H);


                    blit(decor,Menu2,0,0,0,0,SCREEN_W,SCREEN_H);


                    rect(Menu2,500,300,850,400,makecol(0,255,255));

                    masked_blit(nbre_joueurs, Menu2, 0, 0, 30, 0, nbre_joueurs->w, nbre_joueurs->h);

                   // textprintf_ex(Menu2,font,640,350,makecol(255,0,0),2,"2 Joueurs");
                    masked_blit(deux, Menu2, 0, 0,615, 287, deux->w, deux->h);

                    rect(Menu2,500,450,850,550,makecol(255,0,255));


                    //textprintf_ex(Menu2,font,640,500,makecol(0,255,0),2,"3 Joueurs");
                    masked_blit(trois, Menu2, 0, 0, 615, 437, trois->w, trois->h);

                    rect(Menu2,500,600,850,700,makecol(0,100,255));

                    //textprintf_ex(Menu2,font,640,650,makecol(0,0,255),2,"4 Joueurs");
                    masked_blit(quatre, Menu2, 0, 0, 615, 587, quatre->w, quatre->h);

                    if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850) /// Petite animation quand on passe la souris
                    {
                        rect(screen,500,300,850,400,makecol(255,0,0));
                    }

                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850)
                    {

                    rect(screen,500,450,850,550,makecol(0,0,255));

                    }
                    if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850)
                    {

                    rect(screen,500,600,850,700,makecol(0,255,0));

                    }
                    if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) // Click sur 2 donc Selection de 2 joueurs

                    { /// PLAYER 1 à 5 : Sorcier FEU     PLAYER 6 à 10 : Archer FEU   PLAYER 11 à 15 : Chevalier PLAYER 16 à 20 : TIGRE

                        nbre_joueur = 2;

                        rest(200);

                        clear_bitmap(Menu2);
                        /*show_mouse(screen);*/





                        BITMAP* sorcier_feu;
                        BITMAP* archer_feu;
                        BITMAP* chevalier;
                        BITMAP* tigre;


                        BITMAP* sorcier_feu1;
                        BITMAP* archer_feu1;
                        BITMAP* chevalier1;
                        BITMAP* tigre1;
                        BITMAP* noirr;




                        sorcier_feu=load_bitmap("player/player3bis.bmp", NULL);
                        archer_feu=load_bitmap("player/player6bis.bmp", NULL);
                        chevalier=load_bitmap("player/player11bis.bmp", NULL);
                        tigre=load_bitmap("player/player16bis.bmp", NULL);

                        sorcier_feu1=load_bitmap("player/player1bis.bmp", NULL);
                        archer_feu1=load_bitmap("player/player7bis.bmp", NULL);
                        chevalier1=load_bitmap("player/player12bis.bmp", NULL);
                        tigre1=load_bitmap("player/player17bis.bmp", NULL);
                        noirr=load_bitmap("noirr.bmp",NULL);

                        bordure=load_bitmap("bordure.bmp",NULL);

                        int cpteur_nbre_joueurs = 0;

                        while(1){


                            masked_blit(cursor, page3, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur

                            blit(page3,screen,0,0,0,0,SCREEN_W,SCREEN_H);


                            blit(decor,page3,0,0,0,0,SCREEN_W,SCREEN_H);



                            masked_blit(bordure, page3, 0, 0, 88, 130, bordure->w, bordure->h);
                            masked_blit(sorcier_feu1, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                            if(mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342){

                                blit(noirr,page3,0,0,150,300,noirr->w,noirr->h);
                                masked_blit(sorcier_feu, page3, 0, 0, 150, 300, Logo->w, Logo->h);
                            }


                            if (mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342 && mouse_b & 1){

                                rest(200);



                                classe_perso_joueur1 = 1;
                                cpteur_nbre_joueurs++;
                                printf("%d", cpteur_nbre_joueurs);

                                if(cpteur_nbre_joueurs==nbre_joueur){

                                    sortie = 1;


                                }



                            }


                            masked_blit(bordure, page3, 0, 0, 380, 130, bordure->w, bordure->h);
                            masked_blit(archer_feu1, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                            if(mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631){

                                blit(noirr,page3,0,0,450,300,noirr->w,noirr->h);
                                masked_blit(archer_feu, page3, 0, 0, 450, 300, Logo->w, Logo->h);
                            }


                            if (mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631 && mouse_b & 1){



                                classe_perso_joueur1 = 2;
                                cpteur_nbre_joueurs++;
                                printf("%d", cpteur_nbre_joueurs);

                                if(cpteur_nbre_joueurs==nbre_joueur){
                                    break;
                                }



                            }

                            masked_blit(bordure, page3, 0, 0, 688, 130, bordure->w, bordure->h);
                            masked_blit(chevalier1, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                            if(mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934){

                                blit(noirr,page3,0,0,750,300,noirr->w,noirr->h);
                                masked_blit(chevalier, page3, 0, 0, 750, 300, Logo->w, Logo->h);
                            }


                            if (mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934 && mouse_b & 1){



                                classe_perso_joueur1 = 3;
                                cpteur_nbre_joueurs++;
                                printf("%d", cpteur_nbre_joueurs);

                                if(cpteur_nbre_joueurs==nbre_joueur){
                                    break;
                                }



                            }

                            masked_blit(bordure, page3, 0, 0, 988, 130, bordure->w, bordure->h);
                            masked_blit(tigre1, page3, 0, 0, 1055, 300, Logo->w, Logo->h);


                            if(mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235){

                                blit(noirr,page3,0,0,1055,300,noirr->w,noirr->h);
                                masked_blit(tigre, page3, 0, 0, 1055, 300, Logo->w, Logo->h);
                            }


                            if (mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235 && mouse_b & 1){



                                classe_perso_joueur1 = 4;
                                cpteur_nbre_joueurs++;
                                printf("%d", cpteur_nbre_joueurs);

                                if(cpteur_nbre_joueurs==nbre_joueur){
                                    break;
                                }



                            }

                           // textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);



                            }

                    }
                    rest(1);
                }



                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1)
                    {
                        nbre_joueur = 3;
                    }

                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1)
                    {
                        nbre_joueur = 4;
                    }


        }

        }

        if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,450,850,550,makecol(255,0,255));

        }

            if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
            {



                clear_bitmap(page);
                while (!key[KEY_ENTER]) /// Retour en arriere
                {
                    masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur


                    /*show_mouse(Menu2);*/

                    blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                    blit(decor,Menu2,0,0,0,0,SCREEN_W,SCREEN_H);



                    blit(victor, Menu2, 0, 0, 100, 200, victor->w, victor->h);
                    textprintf_ex(Menu2,font,120,450,makecol(255,0,0),2,"Victor CHEVALLIER");

                    blit(serigne, Menu2, 0, 0, 425, 200, victor->w, victor->h);
                    textprintf_ex(Menu2,font,450,450,makecol(255,0,0),2,"Serigne BADIANE");

                    blit(julien, Menu2, 0, 0, 750, 200, victor->w, victor->h);
                    textprintf_ex(Menu2,font,781,450,makecol(255,0,0),2,"Julien DOUVRY");

                    blit(paul, Menu2, 0, 0, 1075, 200, victor->w, victor->h);
                    textprintf_ex(Menu2,font,1075,450,makecol(255,0,0),2,"Paul ARNAUD BATTANDIER");

                    textprintf_ex(Menu2,font,0,0,makecol(0,0,255),2,"Appuyez sur ENTREE pour revenir au MENU");

                }







        }


        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,600,850,700,makecol(0,100,255));

            if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1)  /// CLick regle
            {



            }

        }



        if(imgcourante == 2){
            imgcourante = 1;
        }

        /*rest(200);*/



        /*if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
        {




        }

        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Regles
        {




        }*/

}
}

/*int menu_selec_perso(int choix_perso){

}*/
/*destroy_sample(son);*/

/*}END_OF_MAIN();*/
