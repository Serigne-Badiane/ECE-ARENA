#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

void menu(int* nbre_joueur, int* classe_perso)
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

        sprintf(NomFichier,"marcher%d.bmp",i);

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


    while (!key[KEY_ESC])
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


            if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur New Game
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


                while (!key[KEY_ENTER]) /// Retour en arriere
                {



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

                    { /// PLAYER 1 � 5 : Sorcier FEU     PLAYER 6 � 10 : Archer FEU   PLAYER 11 � 15 : Chevalier PLAYER 16 � 20 : TIGRE

                        clear_bitmap(Menu2);


                        nbre_joueur = 2;

                        BITMAP* sorcier_feu;
                        BITMAP* archer_feu;
                        BITMAP* chevalier;
                        BITMAP* tigre;

                        while(!key[KEY_ENTER]){

                        blit(page3,screen,0,0,0,0,SCREEN_W,SCREEN_H);


                        blit(decor,page3,0,0,0,0,SCREEN_W,SCREEN_H);


                        sorcier_feu=load_bitmap("player/player3.bmp", NULL);
                        archer_feu=load_bitmap("player/player6.bmp", NULL);
                        chevalier=load_bitmap("player/player11.bmp", NULL);
                        tigre=load_bitmap("player/player16.bmp", NULL);

                        masked_blit(sorcier_feu, page3, 0, 0, 30, 30, Logo->w, Logo->h);
                        }



                    }

                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
                    {
                        nbre_joueur = 3;
                    }

                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
                    {
                        nbre_joueurs = 4;
                    }


        }}

        }

        if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,450,850,550,makecol(255,0,255));

        }

            if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Regles
            {
                masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur


                clear_bitmap(page);
                while (!key[KEY_ENTER]) /// Retour en arriere
                {


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

            if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1)
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
