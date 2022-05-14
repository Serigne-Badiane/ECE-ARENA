#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

int menu()
{
    BITMAP* decor;
    BITMAP* page;
    BITMAP* page2;
    BITMAP* Logo;
    BITMAP* NewGame;
    BITMAP* Credits;
    BITMAP* Regles;
    BITMAP* Menu2;
    BITMAP* Sorcier[2];
    BITMAP* paul;
    BITMAP* serigne;
    BITMAP* victor;
    BITMAP* julien;
    BITMAP* deux;
    BITMAP* trois;
    BITMAP* quatre;

    SAMPLE *son;

    char NomFichier[30];



    /*allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }*/


    son = load_wav("clash-of-clans-raiding-musicvolume-increased.wav");


    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {
        printf("Error initialising sound: %s\n", allegro_error);
        return 1;
    }

    if (!son) {
      allegro_message("Error avec le fichier .wav ");
      return 1;
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
    serigne=load_bitmap("serigne.bmp",NULL);
    victor=load_bitmap("victor.bmp",NULL);
    julien=load_bitmap("julien.bmp",NULL);
    paul=load_bitmap("paul.bmp",NULL);

    deux=load_bitmap("deux.bmp",NULL);
    trois=load_bitmap("trois.bmp",NULL);
    quatre=load_bitmap("quatre.bmp",NULL);


    for (int i = 1; i < 3; i++){

        sprintf(NomFichier,"marcher%d.bmp",i);

        Sorcier[i] = load_bitmap(NomFichier,NULL);



        if (!Sorcier[i]){

            allegro_message( "pas pu trouver %s",NomFichier);

            exit( EXIT_FAILURE );

        }

        /*if(i=1){
            i=0;
        }*/


    }




    page=create_bitmap(SCREEN_W,SCREEN_H);
    /*page2=create_bitmap(SCREEN_W,SCREEN_H);*/
    Menu2=create_bitmap(SCREEN_W,SCREEN_H);



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

        cptimage++;
        if (cptimage>=tmpimage){
            cptimage=0;

            imgcourante++;
        }

        show_mouse(page);


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
                clear_bitmap(page);


                show_mouse(screen);


                blit(decor,Menu2,0,0,0,0,SCREEN_W,SCREEN_H);

                blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H);


                rect(screen,500,300,850,400,makecol(0,255,255));
                masked_blit(deux, page, 0, 0,600, 400, deux->w, deux->h);

                rect(screen,500,450,850,550,makecol(255,0,255));
                masked_blit(trois, page, 0, 0, 600, 450, deux->w, deux->h);

                rect(screen,500,600,850,700,makecol(0,100,255));
                masked_blit(quatre, page, 0, 0, 600, 500, deux->w, deux->h);

                rest(50000);


        }

        }

        if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,450,850,550,makecol(255,0,255));

            if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
            {
                clear_bitmap(page);
                while (!key[KEY_ENTER]) /// Click sur Credits
                {

                    rect(screen,500,450,850,550,makecol(255,0,255));

                    show_mouse(screen);

                    blit(decor,Menu2,0,0,0,0,SCREEN_W,SCREEN_H);

                    blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                    blit(victor, screen, 0, 0, 100, 200, victor->w, victor->h);
                    textprintf_ex(screen,font,120,450,makecol(255,0,0),2,"Victor CHEVALLIER");

                    blit(serigne, screen, 0, 0, 425, 200, victor->w, victor->h);
                    textprintf_ex(screen,font,450,450,makecol(255,0,0),2,"Serigne BADIANE");

                    blit(julien, screen, 0, 0, 750, 200, victor->w, victor->h);
                    textprintf_ex(screen,font,781,450,makecol(255,0,0),2,"Julien DOUVRY");

                    blit(paul, screen, 0, 0, 1075, 200, victor->w, victor->h);
                    textprintf_ex(screen,font,1075,450,makecol(255,0,0),2,"Paul ARNAUD BATTANDIER");
                    //rest(5000);
                }







        }
        }

        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850)
        {


            rect(screen,500,600,850,700,makecol(0,100,255));

        }
         if(imgcourante == 2){
            imgcourante = 1;
        }

        rest(100);



        /*if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Credits
        {




        }

        if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur Regles
        {




        }*/

}
}
/*destroy_sample(son);*/

/*}END_OF_MAIN();*/
