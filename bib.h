#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
#define LIGNE 18
#define COLONNE 24

typedef struct{
    int type;
    int x;
    int y;
    int hauteur;
    int largeur;
}t_case;

t_case matrice_terrain[LIGNE][COLONNE];

int addi (int a, int b);
void initialisation();
void afficher();
void init_struct_case();
void affichage_terrain();
void deplacement();
void affichage_terrain(BITMAP* terrain, BITMAP* buffer);


#endif // BIB_H_INCLUDED
