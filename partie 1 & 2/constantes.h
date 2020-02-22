#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define TAILLE_GBLOC 50 // Taille d'un bloc (carré) en pixels
#define TAILLE_PBLOC 40
#define NB_BLOCS_LARG 10
#define NB_PBLOCS_LARG 5

enum{vide,gris,vert,rouge,bleu,violet,orange,marron,lavande,rose,turcoise,jaune};
typedef struct
{
    int occupe;
    int couleur;
    int posx,posy;
}block;



#endif // CONSTANTES_H_INCLUDED
