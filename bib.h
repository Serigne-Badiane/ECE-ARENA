#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 18
#define COLONNE 24

typedef struct
{
    int type;
    int x;
    int y;
    int hauteur;
    int largeur;
}t_case;

t_case matrice_terrain[LIGNE][COLONNE];

typedef struct
{
    int x;
    int y;
}t_joueur;

t_joueur acteur[10];


int addi (int a, int b);
void initialisation();
void afficher();
void init_struct_case();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);
void init_perso();
void deplacement(BITMAP* terrain, BITMAP* buffer);

#endif // BIB_H_INCLUDED
