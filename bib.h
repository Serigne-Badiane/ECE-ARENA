#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 26
#define COLONNE 52
#define LIGNE2 21
#define COLONNE2 22
#define NB_JOUEURS 4

typedef struct
{
    int x;
    int y;
    int hauteur;
    int largeur;
    int passage;
    int placement_debut;
}t_case;

typedef struct
{
    int x;
    int y;
    int passage;
    int placement_debut;

}t_case_iso;

typedef struct
{
    int x;
    int y;
    int case_ligne;
    int case_colonne;
    int case_ligne_iso;
    int case_colonne_iso;
}t_joueur;

typedef struct{

    t_joueur pos;
    int pa;
    int pm;
    int pv;
    int classe;

}str_perso;
int tourjoueur;
t_case matrice_terrain[LIGNE][COLONNE];
t_case_iso matrice_terrain_iso[LIGNE2][COLONNE2];



//t_joueur play[4];
typedef struct{
    BITMAP* anim1;
    BITMAP* anim2;
    BITMAP* anim3;
}animation;

typedef struct{
    BITMAP* sort1;
    BITMAP* sort2;
    BITMAP* sort3;
    BITMAP* sort4;
    char expl1 [100];
    char expl2 [100];
    char expl3 [100];
    char expl4 [100];

}sortperso;

str_perso joueur [4];

void load_cra_feu (sortperso* perso);
void load_cra_feu_anim(sortperso* perso);
void load_mage_eau (sortperso* perso);

int addi (int a, int b);
void initialisation();
void menu();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void affichagesort (BITMAP* buffer,sortperso perso,BITMAP * coeurpv, str_perso joueur [4]);

void usesort (BITMAP* buffer,animation perso [tourjoueur],BITMAP* temp);

void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* buffer_couleur,int tour_joueur);
void deplacement_p2(BITMAP*terrain,BITMAP*buffer,BITMAP*buffer_couleur,int tour_joueur,BITMAP*buffer_deplacement,BITMAP* buffer_enlevage_indication,BITMAP* buffer_deplacement2,int nbr_joueur);
double fin_de_tour(BITMAP* buffer);
void recuperation_couleur(BITMAP* buffer, BITMAP* buffer_enlevage_indication);
void enlevage_des_indications(BITMAP* buffer, BITMAP* buffer_enlevage_indication);

void placement_joueur_debut(BITMAP*buffer,BITMAP*terrain,BITMAP* buffer_enlevage_indication,int nb_joueur);
void chrono(BITMAP* terrain, BITMAP* buffer);
void init_joueur(int nbrjoueur,str_perso joueur [4]);
void case_couleur(BITMAP* buffer,int coord_x,int coord_y,float r,float v,float b);
void terrain_couleur(BITMAP* buffer);
void quadrillage(BITMAP* buffer,BITMAP* terrain);
void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y);

void sauvegarde(int nbrjoueur, int tour_joueur);
void retrait(int nbrjoueur, int tour_joueur);

#endif // BIB_H_INCLUDED
