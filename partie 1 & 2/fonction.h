#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "constantes.h"
#include <SDL/SDL.h>



int rand_ab(int a ,int b);


 void petit_block(int x , int y , int couleur,SDL_Surface *ecran);
 int  grand_block(int x , int y , int color,SDL_Surface *ecran);

void dessin_grille(SDL_Surface *ecran);

void remplir(int color,int posx,int posy,block MAT[10][10]);
void affch_1_block(int x,int y,int aficher,SDL_Surface *ecran);
void affich_3_block(int x,int y,int choisir,SDL_Surface *ecran,int tab_affich3block[3]);
void occupy_all_blocks(int indis,int x,int y,block MAT[10][10],int *N,int *compteurscor);
int suprimerligneetcolone(block MAT[10][10],int *compteurscor);

void occupy_block1(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block2(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block3(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block4(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block5(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block6(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block7(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block8(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block9(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block10(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block11(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block12(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block13(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block14(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block15(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block16(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block17(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block18(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block19(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block20(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block21(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block22(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block23(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block24(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block25(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block26(int x,int y,block MAT[10][10],int *N,int *compteurscor);
void occupy_block27(int x,int y,block MAT[10][10],int *N,int *compteurscor);

void texte(SDL_Surface *ecran,int *compteurscor, int *bestscor);
void pause_machine(SDL_Surface *ecran, int *cpt_scor, int *bestscor);
void pause(SDL_Surface *ecran, int *cpt_scor, int *bestscor);
//fonction qui vérifie si la grille est vide
int placevide(int indis_choix,block MAT[10][10],int *x_voidplace ,int *y_voidplace);

void gameover(SDL_Surface *ecran);


#endif // FONCTION_H_INCLUDED
