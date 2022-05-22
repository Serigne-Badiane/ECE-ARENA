#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "bib.h"

int menu(int direct) /// Menu de début qui passe en paramètre une variable qui changera s'il y a un appuie sur new game et qui passera direct a l'interface de selection de joueurs
{
    BITMAP* decor; /// Initialisation de certaines Bitmap (d'autres se feront plus tard car il y eu des crashs en les initialisant tous en même temps
    BITMAP* page;
    /*BITMAP* page2;*/
    BITMAP* page3;
    BITMAP* Logo;
    BITMAP* NewGame;
    BITMAP* Credits;
    //BITMAP* Regles;
    BITMAP* Menu2;
    BITMAP* Sorcier[2];

    BITMAP* nbre_joueurs;
    BITMAP* cursor;
    BITMAP* serigne;
    BITMAP* victor;
    BITMAP* julien;
    BITMAP* paul;
    BITMAP* bordure;

    SAMPLE *son; /// son de menu

    char NomFichier[30];

    son = load_wav("clash-of-clans-raiding-musicvolume-increased.wav"); /// Precedure pour installer et faire marcher le son


    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {
        printf("Error initialising sound: %s\n", allegro_error);

    }

    if (!son) {
      allegro_message("Error avec le fichier .wav ");

   }

    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)              ///1272,700 dans le jeu car 1400 785 ne marche pas sur tous les ordis , ici c'est pour faire plus grand
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    play_sample(son, 255, 128, 1000, 1);

    Logo=load_bitmap("Logo.bmp",NULL);
    decor=load_bitmap("decordo.bmp",NULL);

    NewGame=load_bitmap("NewGame.bmp",NULL);
    Credits=load_bitmap("Credits.bmp", NULL);
    //Regles=load_bitmap("Regles.bmp", NULL);
    cursor=load_bitmap("cursor.bmp",NULL); /// changement d'apparence du curseur

    serigne=load_bitmap("serigne.bmp",NULL);
    victor=load_bitmap("victor.bmp",NULL);
    paul=load_bitmap("paul.bmp",NULL);
    julien=load_bitmap("julien.bmp",NULL);


    for (int i = 1; i < 3; i++){ /// Boucle d'animation du bonhomme dans le menu (pour rendre plus dynamique d'un point de vue esthétique le menu)

        sprintf(NomFichier,"player/player%dbis.bmp",i);

        Sorcier[i] = load_bitmap(NomFichier,NULL);

        if (!Sorcier[i]){

            allegro_message( "pas pu trouver %s",NomFichier);

            exit( EXIT_FAILURE );
        }
    }

    page=create_bitmap(SCREEN_W,SCREEN_H); /// creation des buffers
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
    int imgcourante = 1; /// Variables servant à l'animation


    while (!key[KEY_ESC])
    {

        masked_blit(cursor, page, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); /// changement de bitmap pr le curseur

        cptimage++;
        if (cptimage>=tmpimage){ // Animation sorcier dans le menu
            cptimage=0;
            imgcourante++;
        }

        /*show_mouse(page);*/


        rect(page,500,300,850,400,makecol(255,0,0)); /// Zone de clics a l'écran
        rect(page,500,450,850,550,makecol(255,0,0));
        //rect(page,500,600,850,700,makecol(255,0,0));

        masked_blit(Logo, page, 0, 0, 100, 100, Logo->w, Logo->h);
        masked_blit(NewGame, page, 0, 0, 548, 320, Logo->w, Logo->h);
        //masked_blit(Regles, page, 0, 0, 560, 616, Logo->w, Logo->h);
        masked_blit(Credits, page, 0, 0, 560, 468, Logo->w, Logo->h);

        /*masked_blit(Sorcier[imgcourante],page, 0, 0, 200, 468, Logo->w, Logo->h);*/

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        draw_sprite(page,Sorcier[imgcourante],603,590); /// animation du bonhomme

        if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850) /// Petite animation quand on passe la souris
        {
            rect(screen,500,300,850,400,makecol(0,255,255));

            if ((mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b&1) || direct == 1) /// Click sur New Game
            {
                masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); /// changement de buffer pr le curseur

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

                    blit(Menu2,screen,0,0,0,0,SCREEN_W,SCREEN_H); /// Dessin des zones de clics

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

                    if (mouse_y > 300 && mouse_y < 400 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Detection Click sur 2 donc Selection de 2 joueurs !!!!!!!!!!!!!!!!!!!!!!!!!!!



                    { /// PLAYER 1 à 5 : Sorcier FEU     PLAYER 6 à 10 : Archer FEU   PLAYER 11 à 15 : Chevalier PLAYER 16 à 20 : TIGRE

                        int nbre_joueur = 2;

                        rest(200);

                        clear_bitmap(Menu2);

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

                        for(int j=0;j<nbre_joueur;j++)
                        {
                            joueur[j].classe=6;
                        }

                        for(int j=0;j<nbre_joueur;j++)
                        {
                            while(joueur[j].classe==6) /// Boucle pour faire fonctionner
                            {
                                masked_blit(cursor, page3, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); /// changement de bitmap pr le curseur

                                blit(page3,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                                blit(decor,page3,0,0,0,0,SCREEN_W,SCREEN_H);

                                masked_blit(bordure, page3, 0, 0, 88, 130, bordure->w, bordure->h);
                                masked_blit(sorcier_feu1, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342)
                                {
                                    blit(noirr,page3,0,0,150,300,noirr->w,noirr->h);
                                    masked_blit(sorcier_feu, page3, 0, 0, 150, 300, Logo->w, Logo->h); /// Quand on passe la souris , on peut voir les sorts des personnages

                                    textprintf_ex(page3,font,220,640,makecol(0,0,255),makecol(255,255,255),"Boule d'eau : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,0,255),makecol(255,255,255),"Flocon bien lourd: Lance un flocon bien lourd qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,0,255),makecol(255,255,255),"Patate lointaine : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(0,255,0),makecol(255,255,255),"PASSIF : Peut marcher sur l'eau");

                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,150,300,makecol(255,0,0),2,"Sorcier de Feu");

                                    while(mouse_b&1)                 /// Blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    blit(noirr,page3,0,0,150,300,noirr->w,noirr->h);
                                    masked_blit(sorcier_feu, screen, 0, 0, 150, 300, Logo->w, Logo->h);
                                    joueur[j].classe = 0; /// Affectation de la classe (la classe est un int)

                                    if(cpteur_nbre_joueurs == nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 380, 130, bordure->w, bordure->h);
                                masked_blit(archer_feu1, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631) /// Animation quand passage de souris
                                {
                                    blit(noirr,page3,0,0,450,300,noirr->w,noirr->h);
                                    masked_blit(archer_feu, page3, 0, 0, 450, 300, Logo->w, Logo->h); /// sorts de l'archer
                                    textprintf_ex(page3,font,220,640,makecol(255,0,0),makecol(255,255,255),"Fleche de Feu : Lance une fleche enflamee qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,0),makecol(255,255,255),"Boule de Feu : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,0),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,0),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,0),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,450,300,makecol(0,255,255),2,"Archer de Feu");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 1;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 688, 130, bordure->w, bordure->h);
                                masked_blit(chevalier1, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934)
                                {
                                    blit(noirr,page3,0,0,750,300,noirr->w,noirr->h); /// sorts du chevalier
                                    masked_blit(chevalier, page3, 0, 0, 750, 300, Logo->w, Logo->h);
                                    textprintf_ex(page3,font,220,640,makecol(255,0,255),makecol(255,255,255),"Dague qui fait mal : Lance une dague qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,255),makecol(255,255,255),"Dague qui fait encore plus mal : Lance une dague qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,750,300,makecol(100,0,255),2,"Chevalier noir");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 2;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 988, 130, bordure->w, bordure->h);
                                masked_blit(tigre1, page3, 0, 0, 1055, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235)
                                {
                                    blit(noirr,page3,0,0,1055,300,noirr->w,noirr->h);
                                    masked_blit(tigre, page3, 0, 0, 1055, 300, Logo->w, Logo->h); /// sorts de tigrou
                                    textprintf_ex(page3,font,220,640,makecol(0,255,255),makecol(255,255,255)," Morsure lointaine : Morsure qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,255,255),makecol(255,255,255)," Javelot : Lance un javelot qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,255,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,255,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,255,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(255,0,0),makecol(255,255,255)," PASSIF : Deplacement accrue grace au bon cardio");
                                }


                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,1055,300,makecol(255,255,0),2,"Tigrou");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 3;

                                    if(cpteur_nbre_joueurs==nbre_joueur) /// Verification si le nombre de joueurs correspond aux selections
                                    {
                                        return nbre_joueur;
                                    }
                                }
                            }
                        }
                    }

                    if (mouse_y > 450 && mouse_y < 550 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur 3 donc Selection de 3 joueurs !!!!!!!!!!!!!!!!!!!!!!!!!!!


                    { /// PLAYER 1 à 5 : Sorcier FEU     PLAYER 6 à 10 : Archer FEU   PLAYER 11 à 15 : Chevalier PLAYER 16 à 20 : TIGRE

                        int nbre_joueur = 3;

                        rest(200);

                        clear_bitmap(Menu2);

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

                        for(int j=0;j<nbre_joueur;j++)
                        {
                            joueur[j].classe=6;
                        }

                        for(int j=0;j<nbre_joueur;j++)
                        {
                            while(joueur[j].classe==6)
                            {
                                masked_blit(cursor, page3, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur

                                blit(page3,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                                blit(decor,page3,0,0,0,0,SCREEN_W,SCREEN_H);

                                masked_blit(bordure, page3, 0, 0, 88, 130, bordure->w, bordure->h);
                                masked_blit(sorcier_feu1, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342)
                                {
                                    blit(noirr,page3,0,0,150,300,noirr->w,noirr->h);
                                    masked_blit(sorcier_feu, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(0,0,255),makecol(255,255,255),"Boule d'eau : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,0,255),makecol(255,255,255),"Flocon bien lourd: Lance un flocon bien lourd qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,0,255),makecol(255,255,255),"Patate lointaine : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(0,255,0),makecol(255,255,255),"PASSIF : Peut marcher sur l'eau");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,150,300,makecol(0,255,0),2,"Sorcier de Feu");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 0;

                                    if(cpteur_nbre_joueurs == nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 380, 130, bordure->w, bordure->h);
                                masked_blit(archer_feu1, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631)
                                {
                                    blit(noirr,page3,0,0,450,300,noirr->w,noirr->h);
                                    masked_blit(archer_feu, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(255,0,0),makecol(255,255,255),"Fleche de Feu : Lance une fleche enflamee qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,0),makecol(255,255,255),"Boule de Feu : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,0),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,0),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,0),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,450,300,makecol(0,0,255),2,"Archer de Feu");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 1;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 688, 130, bordure->w, bordure->h);
                                masked_blit(chevalier1, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934)
                                {
                                    blit(noirr,page3,0,0,750,300,noirr->w,noirr->h);
                                    masked_blit(chevalier, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(255,0,255),makecol(255,255,255),"Dague qui fait mal : Lance une dague qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,255),makecol(255,255,255),"Dague qui fait encore plus mal : Lance une dague qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");


                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,750,300,makecol(255,0,0),2,"Chevalier noir");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 2;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 988, 130, bordure->w, bordure->h);
                                masked_blit(tigre1, page3, 0, 0, 1055, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235){

                                    blit(noirr,page3,0,0,1055,300,noirr->w,noirr->h);
                                    masked_blit(tigre, page3, 0, 0, 1055, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(0,255,255),makecol(255,255,255)," Morsure lointaine : Morsure qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,255,255),makecol(255,255,255)," Javelot : Lance un javelot qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,255,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,255,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,255,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(255,0,0),makecol(255,255,255)," PASSIF : Deplacement accrue grace au bon cardio");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,1055,300,makecol(255,0,0),2,"Tigrou");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 3;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }
                            }
                        }
                    }

                    if (mouse_y > 600 && mouse_y < 700 && mouse_x > 500 && mouse_x < 850 && mouse_b & 1) /// Click sur 4 donc Selection de 4 joueurs !!!!!!!!!!!!!!!!!!!!!!!!!!!
                    { /// PLAYER 1 à 5 : Sorcier FEU     PLAYER 6 à 10 : Archer FEU   PLAYER 11 à 15 : Chevalier PLAYER 16 à 20 : TIGRE

                        int nbre_joueur = 4;

                        rest(200);

                        clear_bitmap(Menu2);

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

                        for(int j=0;j<nbre_joueur;j++)
                        {
                            joueur[j].classe=6;
                        }
                        for(int j=0;j<nbre_joueur;j++)
                        {

                            while(joueur[j].classe==6)
                            {
                                masked_blit(cursor, page3, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); // changement de bitmap pr le curseur

                                blit(page3,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                                blit(decor,page3,0,0,0,0,SCREEN_W,SCREEN_H);

                                masked_blit(bordure, page3, 0, 0, 88, 130, bordure->w, bordure->h);
                                masked_blit(sorcier_feu1, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342)
                                {
                                    blit(noirr,page3,0,0,150,300,noirr->w,noirr->h);
                                    masked_blit(sorcier_feu, page3, 0, 0, 150, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(0,0,255),makecol(255,255,255),"Boule d'eau : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,0,255),makecol(255,255,255),"Flocon bien lourd: Lance un flocon bien lourd qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,0,255),makecol(255,255,255),"Patate lointaine : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(0,255,0),makecol(255,255,255),"PASSIF : Peut marcher sur l'eau");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 130 && mouse_x < 342 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,150,300,makecol(255,0,0),2,"Sorcier de Feu");
                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 0;

                                    if(cpteur_nbre_joueurs == nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 380, 130, bordure->w, bordure->h);
                                masked_blit(archer_feu1, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631)
                                {
                                    blit(noirr,page3,0,0,450,300,noirr->w,noirr->h);
                                    masked_blit(archer_feu, page3, 0, 0, 450, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(255,0,0),makecol(255,255,255),"Fleche de Feu : Lance une fleche enflamee qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,0),makecol(255,255,255),"Boule de Feu : Lance une boule d'eau qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,0),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,0),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,0),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 420 && mouse_x < 631 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,450,300,makecol(255,0,0),2,"Archer de Feu");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }
                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 1;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 688, 130, bordure->w, bordure->h);
                                masked_blit(chevalier1, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934)
                                {
                                    blit(noirr,page3,0,0,750,300,noirr->w,noirr->h);
                                    masked_blit(chevalier, page3, 0, 0, 750, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(255,0,255),makecol(255,255,255),"Dague qui fait mal : Lance une dague qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(255,0,255),makecol(255,255,255),"Dague qui fait encore plus mal : Lance une dague qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(255,0,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(255,0,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(255,0,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 723 && mouse_x < 934 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,750,300,makecol(255,0,0),2,"Chevalier noir");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;

                                    joueur[j].classe = 2;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }

                                masked_blit(bordure, page3, 0, 0, 988, 130, bordure->w, bordure->h);
                                masked_blit(tigre1, page3, 0, 0, 1055, 300, Logo->w, Logo->h);

                                if(mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235)
                                {
                                    blit(noirr,page3,0,0,1055,300,noirr->w,noirr->h);
                                    masked_blit(tigre, page3, 0, 0, 1055, 300, Logo->w, Logo->h);

                                    textprintf_ex(page3,font,220,640,makecol(0,255,255),makecol(255,255,255)," Morsure lointaine : Morsure qui inflige 30pt de degat max");
                                    textprintf_ex(page3,font,220,650,makecol(0,255,255),makecol(255,255,255)," Javelot : Lance un javelot qui inflige 45pt de degat max");
                                    textprintf_ex(page3,font,220,660,makecol(0,255,255),makecol(255,255,255),"Canalisation : Vous vous canalisez et gagnez 3pt de mouvement pour 2 tour");
                                    textprintf_ex(page3,font,220,670,makecol(0,255,255),makecol(255,255,255),"Patate : Un coup au corps a corps qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,680,makecol(0,255,255),makecol(255,255,255),"Poison : Un coup au corps a corps avec plus de portée qui inflige peu de degat");
                                    textprintf_ex(page3,font,220,690,makecol(255,0,0),makecol(255,255,255)," PASSIF : Deplacement accrue grace au bon cardio");
                                }

                                if (mouse_y > 173 && mouse_y < 553 && mouse_x > 1024 && mouse_x < 1235 && mouse_b & 1)
                                {
                                    textprintf_ex(screen,font,1055,300,makecol(255,0,0),2,"Tigrou");

                                    while(mouse_b&1)                 ///blindage click gauche
                                    {
                                        rest(150);
                                    }

                                    cpteur_nbre_joueurs++;
                                    joueur[j].classe = 3;

                                    if(cpteur_nbre_joueurs==nbre_joueur)
                                    {
                                        return nbre_joueur;
                                    }
                                }
                            }
                        }
                    }
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
                int sortie=0;
                while (!key[KEY_ENTER] && sortie==0) /// Retour en arriere
                {
                    if(mouse_b&2)
                    {
                        sortie=1;
                    }
                    masked_blit(cursor, Menu2, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); /// changement de bitmap pr le curseur
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

        if(imgcourante == 2) /// Condition de changement d'image en fin de boucle pour donner l'animation du menu
        {
            imgcourante = 1;
        }
    }
    return 1;
}




////////////////////










int menudefin(int nbrjoueur,int nbre_total_de_tours){ /// Menu de fin, prend le nombre de joueurs en parametre pour ensuite afficher leur position (gagnant/perdant) et affichage du nombre de tours

    int quit = 0;
    int direct = 0;

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1400,750,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    BITMAP* decor_de_fin = load_bitmap("summonersrift.bmp",NULL);
    BITMAP* buffer_decor = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP* cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP* quitter=load_bitmap("quitter.bmp",NULL);
    BITMAP* new_game=load_bitmap("new_game.bmp",NULL);
    BITMAP* revanche=load_bitmap("revanche.bmp",NULL);
    BITMAP* trophee=load_bitmap("trophee.bmp",NULL);



    BITMAP* sorcier_feu=load_bitmap("player/player3bis.bmp", NULL);
    BITMAP* archer_feu=load_bitmap("player/player6bis.bmp", NULL);
    BITMAP* chevalier=load_bitmap("player/player11bis.bmp", NULL);
    BITMAP* tigre=load_bitmap("player/player16bis.bmp", NULL);

    BITMAP* sorcier_feu2=load_bitmap("player/player3.bmp", NULL);
    BITMAP* archer_feu2=load_bitmap("player/player6.bmp", NULL);
    BITMAP* chevalier2=load_bitmap("player/player11.bmp", NULL);
    BITMAP* tigre2=load_bitmap("player/player16.bmp", NULL);




    /*SAMPLE* son_de_fin = load_wav("clash-of-clans-clan-wars-son.wav");

    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, 0) != 0)
    {
        printf("Erreur sound: %s\n", allegro_error);

    }

    if (!son_de_fin) {
      allegro_message("Error avec le fichier .wav ");

   }


    play_sample(son_de_fin, 255, 127,1000, 1);*/

    while (quit!=1)
    {
        textprintf_ex(buffer_decor,font,550,100,makecol(255,0,0),2,"NOMBRE TOTAL DE TOURS : %d",nbre_total_de_tours-1);

        rect(buffer_decor,1000,50,1300,150,makecol(255,255,0));
        rect(buffer_decor,1000,200,1300,300,makecol(255,255,0));
        rect(buffer_decor,1000,350,1300,450,makecol(255,255,0));

        masked_blit(quitter, buffer_decor, 0, 0, 1025, 70, quitter->w, quitter->h);
        masked_blit(revanche, buffer_decor, 0, 0, 1025, 220, quitter->w, quitter->h);
        masked_blit(new_game, buffer_decor, 0, 0, 1025, 370, quitter->w, quitter->h);

        masked_blit(trophee, buffer_decor, 0, 0, 50, 150, trophee->w, trophee->h);


        masked_blit(cursor, buffer_decor, 0, 0,mouse_x, mouse_y, cursor->w, cursor->h); /// changement de bitmap pr le curseur

        for(int i=0;i<nbrjoueur;i++){

            if(joueur[i].pv <= 0){ /// Si perdant , quelle classe n'est plus en vie ?
                if(joueur[i].classe == 0){

                    masked_blit(sorcier_feu2, buffer_decor, 0, 0, 175, 400, sorcier_feu2->w, sorcier_feu2->h);
                    textprintf_ex(buffer_decor,font,250,400,makecol(255,0,0),2,"Mort au tour : %d", joueur[i].tourfinal);

                }
                else if(joueur[i].classe == 1){
                    masked_blit(archer_feu2, buffer_decor, 0, 0, 175, 480, archer_feu2->w, archer_feu2->h);
                    textprintf_ex(buffer_decor,font,250,480,makecol(255,0,0),2,"Mort au tour : %d", joueur[i].tourfinal);

                }
                else if(joueur[i].classe == 2){
                    masked_blit(chevalier2, buffer_decor, 0, 0, 175, 560, chevalier2->w, chevalier2->h);
                    textprintf_ex(buffer_decor,font,250,560,makecol(255,0,0),2,"Mort au tour : %d", joueur[i].tourfinal);

                }
                else if(joueur[i].classe == 3){
                    masked_blit(tigre2, buffer_decor, 0, 0, 175, 640, tigre2->w, tigre2->h);
                    textprintf_ex(buffer_decor,font,250,640,makecol(255,0,0),2,"Mort au tour : %d", joueur[i].tourfinal);
                }
            }

            if(joueur[i].pv > 0){ /// Si gagnant , quelle classe est toujours en vie ?

                if(joueur[i].classe == 0){

                    masked_blit(sorcier_feu, buffer_decor, 0, 0, 260, 210, sorcier_feu->w, sorcier_feu->h);
                    textprintf_ex(buffer_decor,font,50,140,makecol(0,255,0),2,"MAGE D'EAU REMPORTE LA PARTIE AVEC %d PV RESTANT!", joueur[i].pv);



                }
                else if(joueur[i].classe == 1){
                    masked_blit(archer_feu, buffer_decor, 0, 0, 260, 210, archer_feu->w, archer_feu->h);
                    textprintf_ex(buffer_decor,font,50,140,makecol(0,255,0),2,"ARCHER DE FEU REMPORTE LA PARTIE AVEC %d PV RESTANT!", joueur[i].pv);


                }
                else if(joueur[i].classe == 2){
                    masked_blit(chevalier, buffer_decor, 0, 0, 260, 210, chevalier->w, chevalier->h);
                    textprintf_ex(buffer_decor,font,50,140,makecol(0,255,0),2,"CHEVALIER NOIR REMPORTE LA PARTIE AVEC %d PV RESTANT!", joueur[i].pv);

                }
                else if(joueur[i].classe == 3){
                    masked_blit(tigre, buffer_decor, 0, 0, 260, 210, tigre->w, tigre->h);
                    textprintf_ex(buffer_decor,font,50,140,makecol(0,255,0),2,"TIGROU REMPORTE LA PARTIE AVEC %d PV RESTANT!", joueur[i].pv);
                }




        }
        }



        blit(buffer_decor,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(decor_de_fin,buffer_decor,0,0,0,0,SCREEN_W,SCREEN_H);

        if (mouse_y > 50 && mouse_y < 150 && mouse_x > 1000 && mouse_x < 1300 && mouse_b & 1) /// Click sur Quitter
            {
                return 0;

            }

        if (mouse_y > 350 && mouse_y < 450 && mouse_x > 1000 && mouse_x < 1300 && mouse_b & 1) /// Click sur New Game
            {
                direct = 1; /// Passera en parametre du menu de debut pour sauter la premiere interface
                return direct;


            }

        if (mouse_y > 200 && mouse_y < 300 && mouse_x > 1000 && mouse_x < 1300 && mouse_b & 1){ /// Click sur Revanche

                //sauvegarde(nbrjoueur, tourjoueur);


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
                BITMAP* cdp = load_bitmap("coup_de_poing.bmp",NULL);
                BITMAP* petit_coeur = load_bitmap("petit_coeur.bmp",NULL);
                BITMAP* buffer_enlevage_indication = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* buffer_enlevage_indication2 = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* buffer_enlevage = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* buffer_deplacement2 = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* buffer_deplacement = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* temp1 = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* temp2 = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* buffer_invisible_couleur = create_bitmap(SCREEN_W, SCREEN_H);
                BITMAP* coeurpv= load_bitmap("coeurpv.bmp",NULL);
                BITMAP* player [nbrjoueur];
                player[0] = create_bitmap(SCREEN_W, SCREEN_H);
                player[1] = create_bitmap(SCREEN_W, SCREEN_H);
                player[2] = create_bitmap(SCREEN_W, SCREEN_H);
                player[3] = create_bitmap(SCREEN_W, SCREEN_H);
                animation perso1 [4] [4];
                int compteur;
                int cible = 5;
                int blop;
                int ttour = 0;

                for (int i = 0 ; i <4 ; i++)
                {
                    rectfill(player[i],0,0,1272,713,makecol(255,0,255));
                }

                for (int i = 0 ; i <nbrjoueur ; i++)
                {
                    joueur[i].pos.case_colonne_iso=0;
                    joueur[i].pos.case_ligne_iso=0;
                }

                sortperso sortjoueur [nbrjoueur];

                int ennemi;

                init_struct_case(nbrjoueur);
                terrain_couleur(buffer_invisible_couleur);
                ///quadrillage(terrain,terrain);                 ///quadrille la map (possibilité de le mettre au choix)
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

                }

                init_joueur(nbrjoueur,joueur);
                recuperation_couleur(terrain, buffer_enlevage_indication);
                recuperation_couleur(buffer_deplacement,buffer_deplacement2);
                int nb_mort=0;
                int nbtour = 1;

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
                    double difference = 0;
                    double difference2 = 0;
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

                        deplacement_p2(terrain, buffer ,buffer_invisible_couleur, tourjoueur,buffer_enlevage_indication, nbrjoueur, nbtour);

                        affichagesort(player[tourjoueur],sortjoueur[tourjoueur],coeurpv,joueur);
                        draw_sprite(buffer, player[tourjoueur], 0,0);
                        usesort(buffer,perso1[tourjoueur],temp1,cursor,temp2);

                        usesortboost(buffer,perso1[tourjoueur],temp1,cdp,cursor,temp2, nbtour,&blop);
                        if (cible != 5 && ttour == 0){
                            poison(compteur,&cible);
                            ttour = 1;
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

                    joueur[tourjoueur].pm=3;
                    joueur[tourjoueur].pa=6;
                    tourjoueur ++;
                    ttour = 0;
                    if(joueur[tourjoueur].pv<=0)
                    {
                        joueur[tourjoueur].pv=0;
                        tourjoueur++;
                    }
                    nbtour+=1;
                    nb_mort=checkwin(nbrjoueur,0);
                    //retrait(nbrjoueur, tourjoueur);
                }
                return 0;
        }
    }
}

