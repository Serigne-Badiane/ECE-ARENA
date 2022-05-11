#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 23
#define COLONNE 55
#define NB_JOUEURS 4

typedef struct
{
    int x;
    int y;
    int hauteur;
    int largeur;
    int passage;
    int passage_attaque;
}t_case;
typedef struct{

    int pa;
    int pm;
    int pv;

}str_perso;


t_case matrice_terrain[LIGNE][COLONNE];

typedef struct
{
    int x;
    int y;
}t_joueur;

t_joueur acteur[NB_JOUEURS];


int addi (int a, int b);
void initialisation();
void menu();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void affichagesort (BITMAP* buffer,BITMAP* bdf,BITMAP*  tir_explosif, BITMAP* feu_oku, BITMAP* cac_feu,BITMAP * coeurpv, str_perso joueur [4]);
void init_perso();
void deplacement(BITMAP* terrain, BITMAP* buffer);
void chrono(BITMAP* terrain, BITMAP* buffer);
void init_joueur(int nbrjoueur,str_perso joueur [4]);
void case_couleur(BITMAP* buffer,BITMAP* terrain, int coord_x, int coord_y);
void quadrillage(BITMAP* buffer,BITMAP* terrain);
void case_quadrillage(BITMAP* buffer,BITMAP* terrain,int coord_x,int coord_y);

#endif // BIB_H_INCLUDED
