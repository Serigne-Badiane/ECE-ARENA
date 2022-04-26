#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

typedef struct{
    int type;
    int x;
    int y;
    int hauteur;
    int largeur;
}t_case;

t_case matrice_terrain[19][21];

int addi (int a, int b);
void initialisation();
void afficher();
void init_struct_case();
void affichage_terrain();


#endif // BIB_H_INCLUDED
