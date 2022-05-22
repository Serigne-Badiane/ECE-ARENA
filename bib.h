#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 26
#define COLONNE 52
#define LIGNE2 21
#define COLONNE2 22
#define NB_JOUEURS 4

///https://forums.commentcamarche.net/forum/affich-15461118-chronometre-en-c-et-precision

typedef struct  ///structure pour les cases en forme de losange
{
    int x;
    int y;
    int hauteur;
    int largeur;
    int passage;
    int placement_debut;
}t_case;

typedef struct  ///structure pour la création de case en forme de carré malgré la forme isométrique du terrain
{               ///on utilise cette structure pour les déplacements car moins de calculs
    int x;
    int y;
    int passage;
    int placement_debut;

}t_case_iso;

typedef struct              ///structure pour la position des joueurs
{
    int x;
    int y;
    int case_ligne;
    int case_colonne;
    int case_ligne_iso;
    int case_colonne_iso;
}t_joueur;

typedef struct{             ///structure complète du joueur

    t_joueur pos;
    int pa;
    int pm;
    int pv;
    int classe;

}str_perso;

int tourjoueur;                 ///déclaration de tour joueur ici pour ne pas avoir à le mettre dans chaque appel de sspg
t_case matrice_terrain[LIGNE][COLONNE];
t_case_iso matrice_terrain_iso[LIGNE2][COLONNE2];
int dureesort[4];
int ancien_nbtour[4];


typedef struct{                 ///structure pour les animations de sort et la portée de ceci
    BITMAP* anim1;
    BITMAP* anim2;
    BITMAP* anim3;
    int porte;
}animation;

typedef struct{             ///structure pour les sorts de chaque classes
    BITMAP* sort1;
    BITMAP* sort2;
    BITMAP* sort3;
    BITMAP* sort4;
    char expl1 [100];
    char expl2 [100];
    char expl3 [100];
    char expl4 [100];

}sortperso;

str_perso joueur[4];
str_perso pnj;

void load_cra_feu (sortperso* perso);
void load_cra_feu_anim(sortperso* perso);
void load_mage_eau (sortperso* perso);

int addi (int a, int b);
void initialisation();
int menu();
int menudefin();
void afficher();
void init_struct_case(int nbre_joueurs);
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [4]);

void usesort (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp1,BITMAP* cursor,BITMAP* temp2);
void usesortboost (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp1, BITMAP* cdp,BITMAP* cursor,BITMAP* temp2,int nbtour);

void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur,int tour_joueur,BITMAP* buffer_enlevage_indication,int nbr_joueur,int nbtour);
double fin_de_tour(BITMAP* buffer);
void recuperation_couleur(BITMAP* buffer, BITMAP* buffer_enlevage_indication);
void enlevage_des_indications(BITMAP* buffer, BITMAP* buffer_enlevage_indication);
int verif (int z,int y,int tour_joueur);
int verif2 (int z,int y, int tour_joueur);

void placement_joueur_debut(BITMAP*buffer,BITMAP*terrain,int nb_joueur,BITMAP* cursor,BITMAP* buffer_enlevage);
void init_joueur(int nbrjoueur,str_perso joueur [4]);
void case_couleur(BITMAP* buffer,int coord_x,int coord_y,float r,float v,float b);
void terrain_couleur(BITMAP* buffer);
void quadrillage(BITMAP* buffer,BITMAP* terrain);
void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y);
void affichage_pv (BITMAP* buffer,BITMAP* petit_coeur);

void tour(BITMAP* buffer, int nbrjoueur, int tour_joueur);
void barre_de_vie(BITMAP* buffer, int nbrjoueur, int tour_joueur);
void respirer(BITMAP* buffer,BITMAP* terrain, int nbr_joueur,BITMAP*temp);

void sauvegarde(int nbrjoueur, int tour_joueur);
void retrait(int nbrjoueur, int tour_joueur);
int checkwin(int nbre_joueurs,int i);
void bonus (BITMAP* buffer,int pos_x,int pos_y);

#endif // BIB_H_INCLUDED
