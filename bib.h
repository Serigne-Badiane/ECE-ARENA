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
void affichage_terrain(BITMAP* terrain, BITMAP* buffer,BITMAP*ciel);
void init_perso();
void deplacement(BITMAP* terrain, BITMAP* buffer, BITMAP* ciel);
void chrono(BITMAP* terrain, BITMAP* buffer);
void case_couleur(BITMAP* buffer,BITMAP* terrain, int coord_x, int coord_y);

#endif // BIB_H_INCLUDED
