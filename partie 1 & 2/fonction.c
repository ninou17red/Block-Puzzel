#include "constantes.h"
#include "fonction.h"
#include "partie1.h"
#include "partie2.h"
#include <SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_ttf.h>

void pause_machine(SDL_Surface *ecran, int *cpt_scor, int *bestscor)
{
    SDL_Surface *image=NULL;
    SDL_Event event;
    TTF_Font *police=NULL;
     SDL_Rect pos,pos_image,pos2;
     int continuer=1,x,y;
         SDL_Surface *text=NULL,*text2=NULL;
         SDL_Color noire={0,0,0};
         char scor[20]="";
         char highscor[20]="";

         TTF_Init();
         image=SDL_LoadBMP("menu_pause.bmp");
         pos_image.x=0;
         pos_image.y=0;

         police=TTF_OpenFont("minipixel.ttf",60);
        sprintf(scor," %d ",*cpt_scor);
        sprintf(highscor," %d ",*bestscor);

        text= TTF_RenderText_Blended(police,scor, noire);
        text2= TTF_RenderText_Blended(police,highscor, noire);
        pos.x=447;
        pos.y=121;
        pos2.x=690;
        pos2.y=190;
        TTF_CloseFont(police);
        TTF_Quit();
         while(continuer)
         {
             SDL_PollEvent(&event);
             switch (event.type)
           {
              case SDL_QUIT:
                 continuer=2;
                  break;
              case SDL_MOUSEBUTTONUP:

               {
                   x=event.button.x;//on recupere les coordonnées de la souris
                   y = event.button.y;
                   if (x < 333 && x > 241 && y < 358 && y > 271 )
                   {
                       continuer=2;
                   }
                   if (x < 469 && x > 375 && y < 358 && y > 271 )
                   {
                     //save
                   }
                   if (x < 603 && x > 510 && y < 358 && y > 271 )
                   {
                       continuer=0;
                     jouer_partie2(ecran);
                   }
               }
               break;
             }

             SDL_BlitSurface(image,NULL,ecran,&pos_image);
             SDL_BlitSurface(text, NULL, ecran, &pos);
             SDL_BlitSurface(text2, NULL, ecran, &pos2);
             SDL_Flip(ecran);
             if (continuer==2){return;}


        }


         SDL_FreeSurface(text);
        SDL_FreeSurface(image);



}






void gameover(SDL_Surface *ecran)
{
    TTF_Font *police=NULL;
     SDL_Rect pos;
         SDL_Surface *text=NULL,*text2=NULL;
         SDL_Color noire={0,0,0};
         char scor[20]="";

          TTF_Init();
        police=TTF_OpenFont("minipixel.ttf",80);
        text= TTF_RenderText_Blended(police,"GAME OVER  ", noire);
        pos.x=100;
        pos.y=100;
        SDL_BlitSurface(text, NULL, ecran, &pos);


}






void pause(SDL_Surface *ecran, int *cpt_scor, int *bestscor)
{
    SDL_Surface *image=NULL;
    SDL_Event event;
    TTF_Font *police=NULL;
     SDL_Rect pos,pos_image,pos2;
     int continuer=1,x,y;
         SDL_Surface *text=NULL,*text2=NULL;
         SDL_Color noire={0,0,0};
         char scor[20]="";
         char highscor[20]="";

         TTF_Init();
         image=SDL_LoadBMP("menu_pause.bmp");
         pos_image.x=0;
         pos_image.y=0;

         police=TTF_OpenFont("minipixel.ttf",60);
        sprintf(scor," %d ",*cpt_scor);
        sprintf(highscor," %d ",*bestscor);

        text= TTF_RenderText_Blended(police,scor, noire);
        text2= TTF_RenderText_Blended(police,highscor, noire);
        pos.x=447;
        pos.y=121;
        pos2.x=690;
        pos2.y=190;
        TTF_CloseFont(police);
        TTF_Quit();
         while(continuer)
         {
             SDL_PollEvent(&event);
             switch (event.type)
           {
              case SDL_QUIT:
                 continuer=2;
                  break;
              case SDL_MOUSEBUTTONUP:

               {
                   x=event.button.x;//on recupere les coordonnées de la souris
                   y = event.button.y;
                   if (x < 333 && x > 241 && y < 358 && y > 271 )
                   {
                       continuer=2;
                   }
                   if (x < 469 && x > 375 && y < 358 && y > 271 )
                   {
                     //save
                   }
                   if (x < 603 && x > 510 && y < 358 && y > 271 )
                   {
                       continuer=0;
                     jouer_partie1(ecran);
                   }
               }
               break;
             }

             SDL_BlitSurface(image,NULL,ecran,&pos_image);
             SDL_BlitSurface(text, NULL, ecran, &pos);
             SDL_BlitSurface(text2, NULL, ecran, &pos2);
             SDL_Flip(ecran);
             if (continuer==2){return;}


        }


         SDL_FreeSurface(text);
        SDL_FreeSurface(image);



}

void texte(SDL_Surface *ecran,int *cpt_scor, int *bestscor)
{
    TTF_Font *police=NULL;
     SDL_Rect pos;
         SDL_Surface *text=NULL,*text2=NULL;
         SDL_Color noire={0,0,0};
         char scor[20]="";
         char high_scor[20]="";

        TTF_Init();
        police=TTF_OpenFont("minipixel.ttf",28);
        if (*bestscor<=*cpt_scor){*bestscor=*cpt_scor;}

        sprintf(scor,"SCORE: %d ",*cpt_scor);
        sprintf(high_scor,"HIGH SCORE: %d ",*bestscor);
        text= TTF_RenderText_Blended(police,scor, noire);
        text2= TTF_RenderText_Blended(police,high_scor, noire);
        pos.x=50;
        pos.y=70;
        SDL_BlitSurface(text, NULL, ecran, &pos); /* Blit du texte */
        pos.x=250;
        pos.y=70;
        SDL_BlitSurface(text2, NULL, ecran, &pos); /* Blit du texte */
         TTF_CloseFont(police);
        TTF_Quit();
            SDL_FreeSurface(text);


}


//dessin de l'inteface de jeu
void dessin_grille(SDL_Surface *ecran)
{
    int i=0,j=0,k=0;
     SDL_Surface *ecran2=NULL,*pausa=NULL;
    SDL_Surface *rectangle[NB_BLOCS_LARG][NB_BLOCS_LARG] = {NULL};
   SDL_Surface *rectangle2[NB_PBLOCS_LARG][NB_PBLOCS_LARG] = {NULL};
   SDL_Surface *ligne[NB_PBLOCS_LARG]={NULL};
   SDL_Rect position;

        pausa=SDL_LoadBMP("pause.bmp");
        ecran2=SDL_CreateRGBSurface(SDL_HWSURFACE,(TAILLE_GBLOC+2)*10+2,(TAILLE_GBLOC+2)*10+2,32,0,0,0,0);
        SDL_FillRect(ecran2,NULL,SDL_MapRGB(ecran2->format,0,0,0));
        position.x=50;
        position.y=100;
        SDL_BlitSurface(ecran2,NULL,ecran,&position);
        position.x=500;
        position.y=30;
        SDL_BlitSurface(pausa,NULL,ecran,&position);
        //allocation de la grille de jeu
for(i=0;i< NB_BLOCS_LARG;i++)
 {
     for(j = 0; j < 10; j++)
     {
         rectangle[i][j]=SDL_CreateRGBSurface(SDL_HWSURFACE,TAILLE_GBLOC,TAILLE_GBLOC,32,0,0,0,0);
     }
 }
 //allocation de la petite surface a droite

  for (i=0;i<NB_PBLOCS_LARG;i++)
 {
     for (j=0;j<NB_PBLOCS_LARG;j++)
        {
            rectangle2[i][j]=SDL_CreateRGBSurface(SDL_HWSURFACE,TAILLE_PBLOC,TAILLE_PBLOC,32,0,0,0,0);
        }
 }

 //alocation de la ligne
 for (k=0;k<NB_PBLOCS_LARG;k++)
 {
     ligne[k]=SDL_CreateRGBSurface(SDL_HWSURFACE,210,2,32,0,0,0,0);
 }

// dessin de la grille

 for(i=0;i<NB_BLOCS_LARG;i++)
 {
     for (j=0;j<NB_BLOCS_LARG;j++)
     {
     position.x = 52 + (j * (TAILLE_GBLOC+2));
     position.y=102 + i * (TAILLE_GBLOC+2);
     SDL_FillRect(rectangle[i][j],NULL,SDL_MapRGB(ecran->format,255,255,255));
     SDL_BlitSurface(rectangle[i][j],NULL,ecran,&position);


      }
}
//dessin de la petite grille
for (k=0;k<3;k++)
{
 for (i=0;i<NB_PBLOCS_LARG;i++)
 {
     for (j=0;j<NB_PBLOCS_LARG;j++)
        {
              position.x = 670 + (j * (TAILLE_PBLOC+2));
              position.y= ((k*210)+4) +(i * (TAILLE_PBLOC+2));
              SDL_FillRect(rectangle2[i][j],NULL,SDL_MapRGB(ecran->format,255,255,255));
              SDL_BlitSurface(rectangle2[i][j],NULL,ecran,&position);
        }
 }
 position.x=670;
 position.y=k*210+4;
 SDL_FillRect(ligne[k],NULL,SDL_MapRGB(ecran->format,0,0,0));
 SDL_BlitSurface(ligne[k],NULL,ecran,&position);
}
// Libération de la surface
 for(i=0;i<NB_BLOCS_LARG;i++)
 {
     for(j = 0;j <NB_BLOCS_LARG; j++)
     {
         SDL_FreeSurface(rectangle[i][j]);
     }
 }

   for(i=0;i<NB_PBLOCS_LARG;i++)
 {
     for(j = 0;j < NB_PBLOCS_LARG; j++)
     {
         SDL_FreeSurface(rectangle2[i][j]);
     }
 }

 for (k=0;k<NB_PBLOCS_LARG;k++)
 {
     SDL_FreeSurface(ligne[k]);
 }
 SDL_FreeSurface(ecran2);
 SDL_FreeSurface(pausa);

}



//dessin d'un seule carré sur la petite grille
void petit_block(int x , int y , int couleur, SDL_Surface *ecran)
{
    SDL_Surface *image;
    SDL_Rect position;
    position.x=x;
    position.y=y;
   switch (couleur)
   {
       case gris: {image=SDL_LoadBMP("gris.bmp");
                    SDL_BlitSurface(image,NULL,ecran,&position);}break;
       case vert: {image=SDL_LoadBMP("vert.bmp");
                    SDL_BlitSurface(image,NULL,ecran,&position);}break;
        case rouge: {image=SDL_LoadBMP("rouge.bmp");
                     SDL_BlitSurface(image,NULL,ecran,&position);}break;
         case bleu: {image =SDL_LoadBMP("bleu.bmp");
                     SDL_BlitSurface(image,NULL,ecran,&position);}break;
          case violet: {image =SDL_LoadBMP("violet.bmp");
                           SDL_BlitSurface(image,NULL,ecran,&position);}break;
          case orange: {image =SDL_LoadBMP("orange.bmp");
                            SDL_BlitSurface(image,NULL,ecran,&position);}break;
              case marron: {image =SDL_LoadBMP("marron.bmp");
                             SDL_BlitSurface(image,NULL,ecran,&position);}break;
               case lavande: {image =SDL_LoadBMP("lavande.bmp");
                              SDL_BlitSurface(image,NULL,ecran,&position);}break;
            case rose: {image =SDL_LoadBMP("rose.bmp");
                              SDL_BlitSurface(image,NULL,ecran,&position);}break;
              case turcoise: {image =SDL_LoadBMP("turcoise.bmp");
                              SDL_BlitSurface(image,NULL,ecran,&position);}break;
            case jaune: {image =SDL_LoadBMP("jaune.bmp");
                              SDL_BlitSurface(image,NULL,ecran,&position);}break;
   }

   SDL_FreeSurface(image);


}
// dessin d'un seule grand block
int grand_block(int x , int y , int color,SDL_Surface *ecran )
{
    SDL_Surface *image2;
    SDL_Rect position;
    position.x=x;
    position.y=y;
   switch (color)
   {
       case gris: {image2=SDL_LoadBMP("GRISS.bmp");
                    SDL_BlitSurface(image2,NULL,ecran,&position);}break;
       case vert: {image2=SDL_LoadBMP("VERTT.bmp");
                    SDL_BlitSurface(image2,NULL,ecran,&position);}break;
        case rouge: {image2=SDL_LoadBMP("ROUGEE.bmp");
                     SDL_BlitSurface(image2,NULL,ecran,&position);}break;
         case bleu: {image2 =SDL_LoadBMP("BLEUU.bmp");
                     SDL_BlitSurface(image2,NULL,ecran,&position);}break;
          case violet: {image2 =SDL_LoadBMP("VIOLETT.bmp");
                           SDL_BlitSurface(image2,NULL,ecran,&position);}break;
          case orange: {image2 =SDL_LoadBMP("ORANGG.bmp");
              SDL_BlitSurface(image2,NULL,ecran,&position);}break;
              case marron: {image2 =SDL_LoadBMP("MARRONN.bmp");
                             SDL_BlitSurface(image2,NULL,ecran,&position);}break;
               case lavande: {image2 =SDL_LoadBMP("LAVANDEE.bmp");
                              SDL_BlitSurface(image2,NULL,ecran,&position);}break;
            case rose: {image2 =SDL_LoadBMP("ROSEE.bmp");
                              SDL_BlitSurface(image2,NULL,ecran,&position);}break;
              case turcoise: {image2 =SDL_LoadBMP("TURCOISEE.bmp");
                              SDL_BlitSurface(image2,NULL,ecran,&position);}break;
            case jaune: {image2 =SDL_LoadBMP("JAUNEE.bmp");
                              SDL_BlitSurface(image2,NULL,ecran,&position);}break;
   }

   SDL_FreeSurface(image2);
   return 0;


}
// remplire la matrice principales
void remplir(int color,int posx,int posy,block MAT[10][10])
{
    int i=(posx-50)/50,j=(posy-100)/50;
    MAT[i][j].couleur=color;
    MAT[i][j].occupe=1;
    MAT[i][j].posx=posx;
    MAT[i][j].posy=posy;

}
void occupy_block1(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
    if(MAT[i][j].occupe!=1)
    {remplir(gris,x,y,MAT);*N=*N+1;*cpt_scor=*cpt_scor+1;
    }
}
void occupy_block2(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
int i=(x-50)/50,j=(y-100)/50;
    if((x>50)&&(y>100)&&(y<621)&&(x<520)&&(MAT[i][j].occupe!=1)&&(MAT[i+1][j].occupe!=1))
    {remplir(vert,x,y,MAT);*N=*N+1;remplir(vert,x+52,y,MAT);*cpt_scor=*cpt_scor+20;
        *N=*N+1;

    }
}
void occupy_block3(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(y<570)&&(x<520)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j+1].occupe==0))
    {remplir(violet,x,y,MAT);*N=*N+1;remplir(violet,x+52,y,MAT);*N=*N+1;remplir(violet,x+52,y+52,MAT);*N=*N+1;*cpt_scor=*cpt_scor+30;
    }


}
void occupy_block4(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(x<468)&&(y<621)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0))
     {remplir(lavande,x,y,MAT);*N=*N+1;remplir(lavande,x+52,y,MAT);*N=*N+1;remplir(lavande,x+104,y,MAT);*N=*N+1;*cpt_scor=*cpt_scor+30;
     }

}
void occupy_block5(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(x<416)&&(y<621)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)&&(MAT[i+3][j].occupe==0))
      {remplir(rose,x,y,MAT);*N=*N+1;remplir(rose,x+52,y,MAT);*N=*N+1;remplir(rose,x+104,y,MAT);*N=*N+1;remplir(rose,x+156,y,MAT);*N=*N+1;*cpt_scor=*cpt_scor+40;
      }

}

void occupy_block6(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
   int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(x<570)&&(y>150)&&(y<518)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&
                        ( MAT[i+2][j].occupe==0)&&(MAT[i+1][j-1].occupe==0))
        {remplir(rouge,x,y,MAT);*N=*N+1;remplir(rouge,x+52,y,MAT);*N=*N+1;remplir(rouge,x+104,y,MAT);*N=*N+1;remplir(rouge,x+52,y-52,MAT);*N=*N+1;*cpt_scor=*cpt_scor+40;
      }

}
void occupy_block7(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
   if ((x>50)&&(x<520)&&(y<571)&&(y>100)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i][j+1].occupe==0)
             &&(MAT[i+1][j].occupe)==0)
      {remplir(orange,x,y,MAT);*N=*N+1;remplir(orange,x+52,y,MAT);*N=*N+1;remplir(orange,x,y+52,MAT);*N=*N+1;remplir(orange,x+52,y+52,MAT);*N=*N+1;*cpt_scor=*cpt_scor+40;
       }

}
void occupy_block8(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(x<467)&&(y<520)&&(y>100)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i+2][j+1].occupe==0)&&(MAT[i+2][j+2].occupe==0))
       {remplir(bleu,x,y,MAT);*N=*N+1;remplir(bleu,x+52,y,MAT);*N=*N+1;remplir(bleu,x+104,y,MAT);*N=*N+1;remplir(bleu,x+104,y+52,MAT);*N=*N+1;remplir(bleu,x+104,y+104,MAT);*N=*N+1;*cpt_scor=*cpt_scor+50;
    }

}
void occupy_block9(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(y>100)&&(x<520)&&(y<519)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)
        &&(MAT[i+1][j+2].occupe==0)&&(MAT[i][j+2].occupe==0))
    {remplir(turcoise,x,y,MAT);*N=*N+1;remplir(turcoise,x+52,y,MAT);*N=*N+1;remplir(turcoise,x+52,y+52,MAT);*N=*N+1;remplir(turcoise,x+52,y+104,MAT);*N=*N+1;remplir(turcoise,x,y+104,MAT);*N=*N+1;*cpt_scor=*cpt_scor+50;
    }

}
void occupy_block10(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
       if ((x>50)&&(x<468)&&(y<519)&&(y>100)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i+2][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)
           &&(MAT[i+1][j+2]. occupe==0)&&(MAT[i+2][j+2]. occupe==0))
           {remplir(jaune,x,y,MAT);remplir(jaune,x+52,y,MAT);remplir(jaune,x+104,y,MAT);remplir(jaune,x,y+52,MAT);remplir(jaune,x+52,y+52,MAT);remplir(jaune,x+104,y+52,MAT);remplir(jaune,x,y+104,MAT);remplir(jaune,x+52,y+104,MAT);remplir(jaune,x+104,y+104,MAT);*N=*N+9;*cpt_scor=*cpt_scor+90;
           }

}
void occupy_block11(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(y>100)&&(y<571)&&(x<520)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i][j+1].occupe==0))
    {remplir(violet,x,y,MAT);remplir(violet,x,y+52,MAT);remplir(violet,x+52,y+52,MAT);*N=*N+3;*cpt_scor=*cpt_scor+30;
    }

}
void occupy_block12(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(x<570)&&(y<413)&&(y>100)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)&&(MAT[i][j+3].
           occupe==0)&&(MAT[i][j+4].occupe==0)&&(MAT[i][j].occupe==0))
    {remplir(marron,x,y,MAT);remplir(marron,x,y+52,MAT);remplir(marron,x,y+104,MAT);remplir(marron,x,y+156,MAT);remplir(marron,x,y+208,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }


}
void occupy_block13(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
        if ((y<570)&&(x<570)&&(y>100)&&(x>50)&&(MAT[i][j].occupe!=1)&&(MAT[i][j+1].occupe!=1))
        {remplir(vert,x,y,MAT);remplir(vert,x,y+52,MAT);*N=*N+2;*cpt_scor=*cpt_scor+20;
        }

}
void occupy_block14(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
    if ((y>100)&&(x>50)&&(x<520)&&(y<570)&&(MAT[i][j].occupe!=1)&&(MAT[i][j+1].occupe!=1)&&(MAT[i+1][j].occupe==0))
        {remplir(violet,x,y,MAT);remplir(violet,x,y+52,MAT);remplir(violet,x+52,y,MAT);*N=*N+3;*cpt_scor=*cpt_scor+30;
        }

}
void occupy_block15(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
    if ((y>140)&&(x>50)&&(x<520)&&(y<620)&&(MAT[i][j].occupe!=1)&&(MAT[i+1][j].occupe!=1)&&(MAT[i+1][j-1].occupe==0))
        {remplir(violet,x,y,MAT);remplir(violet,x+52,y,MAT);remplir(violet,x+52,y-52,MAT);*N=*N+3;*cpt_scor=*cpt_scor+30;
        }

}
void occupy_block16(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(y<518)&&(x<570)&&(MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0))
     {remplir(lavande,x,y,MAT);remplir(lavande,x,y+52,MAT);remplir(lavande,x,y+104,MAT);*N=*N+3;*cpt_scor=*cpt_scor+30;
     }

}

void occupy_block17(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(y>100)&&(y<465)&&(x<570)&&(MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)&&(MAT[i][j+3].occupe==0))
    {remplir(rose,x,y,MAT);remplir(rose,x,y+52,MAT);remplir(rose,x,y+104,MAT);remplir(rose,x,y+156,MAT);*N=*N+4;*cpt_scor=*cpt_scor+40;
    }

}

void occupy_block18(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(x<688)&&(y>100)&&(y<518)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&( MAT[i+2][j].occupe==0)&&(MAT[i+1][j+1].occupe==0))
        {remplir(rouge,x,y,MAT);remplir(rouge,x+52,y,MAT);remplir(rouge,x+104,y,MAT);remplir(rouge,x+52,y+52,MAT);*N=*N+4;*cpt_scor=*cpt_scor+40;
        }

}

void occupy_block19(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
      int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>140)&&(y<570)&&(x<520)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j-1].occupe==0)&&(MAT[i+1][j+1].occupe==0))
     {remplir(rouge,x,y,MAT);remplir(rouge,x+52,y,MAT);remplir(rouge,x+52,y-52,MAT);remplir(rouge,x+52,y+52,MAT);*N=*N+4;*cpt_scor=*cpt_scor+40;

     }

}
void occupy_block20(int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(y<518)&&(x<420)&&(MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)&&(MAT[i+1][j+1].occupe==0))
     {remplir(rouge,x,y,MAT);remplir(rouge,x,y+52,MAT);remplir(rouge,x,y+104,MAT);remplir(rouge,x+52,y+52,MAT);*N=*N+4;*cpt_scor=*cpt_scor+40;
     }

}
void occupy_block21(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;

      if ((x>50)&&(x<467)&&(y<519)&&(y>100)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0))
       {remplir(bleu,x,y,MAT);remplir(bleu,x+52,y,MAT);remplir(bleu,x+104,y,MAT);remplir(bleu,x,y+52,MAT);remplir(bleu,x,y+104,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }

}
void occupy_block22(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
  if ((x>50)&&(x<467)&&(y<519)&&(y>100)&&(MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)
        &&(MAT[i+1][j+2].occupe==0)&&(MAT[i+2][j+2].occupe==0))
       {remplir(bleu,x,y,MAT);remplir(bleu,x,y+52,MAT);remplir(bleu,x,y+104,MAT);remplir(bleu,x+52,y+104,MAT);remplir(bleu,x+104,y+104,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }

}
void occupy_block23(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
       if ((x>50)&&(x<467)&&(y<621)&&(y>180)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i+2][j-1].occupe==0)&&(MAT[i+2][j-2].occupe==0))
       {remplir(bleu,x,y,MAT);remplir(bleu,x+52,y,MAT);remplir(bleu,x+104,y,MAT);remplir(bleu,x+104,y-52,MAT);remplir(bleu,x+104,y-104,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }

}
void occupy_block24(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{
     int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(y>100)&&(x<468)&&(y<568)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i+2][j+1].occupe==0))
    {remplir(turcoise,x,y,MAT);remplir(turcoise,x+52,y,MAT);remplir(turcoise,x+104,y,MAT);remplir(turcoise,x,y+52,MAT);remplir(turcoise,x+104,y+52,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }


}
void occupy_block25(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{

     int i=(x-50)/50,j=(y-100)/50;
    if ((x>50)&&(y>100)&&(x<520)&&(y<518)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i][j+1].occupe==0)
        &&(MAT[i][j+2].occupe==0)&&(MAT[i+1][j+2].occupe==0))
    {remplir(turcoise,x,y,MAT);remplir(turcoise,x+52,y,MAT);remplir(turcoise,x,y+52,MAT);remplir(turcoise,x,y+104,MAT);remplir(turcoise,x+52,y+104,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }


}
void occupy_block26(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{

     int i=(x-50)/50,j=(y-100)/50;
     if ((x>50)&&(y>100)&&(x<520)&&(y<518)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i+2][j+1].occupe==0))
    {remplir(turcoise,x,y,MAT);remplir(turcoise,x+52,y+52,MAT);remplir(turcoise,x+104,y,MAT);remplir(turcoise,x,y+52,MAT);remplir(turcoise,x+104,y+52,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }



}
void occupy_block27(int x, int y,block MAT[10][10],int *N,int *cpt_scor)
{
    int i=(x-50)/50,j=(y-100)/50;
         if ((x>50)&&(y>100)&&(x<363)&&(y<620)&&(MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i+3][j].occupe==0)&&(MAT[i+4][j].occupe==0))
    {remplir(marron,x,y,MAT);remplir(marron,x+52,y,MAT);remplir(marron,x+104,y,MAT);remplir(marron,x+156,y,MAT);remplir(marron,x+208,y,MAT);*N=*N+5;*cpt_scor=*cpt_scor+50;
    }


}
//affichage des 3 blocks
void affich_1_block(int x,int y,int aficher,SDL_Surface *ecran)
{
    switch(aficher)
    {
case 1:{ petit_block(x,y,gris,ecran);}break;
case 2:{ petit_block(x,y,vert,ecran);petit_block(x+42,y,vert,ecran);}break;
case 3:{ petit_block(x,y,violet,ecran);petit_block(x+42,y,violet,ecran);petit_block(x+42,y+42,violet,ecran);}break;
case 4:{ petit_block(x,y,lavande,ecran);petit_block(x+42,y,lavande,ecran);petit_block(x+84,y,lavande,ecran);}break;
case 5:{ petit_block(x,y,rose,ecran);petit_block(x+42,y,rose,ecran);petit_block(x+84,y,rose,ecran);
                        petit_block(x+126,y,rose,ecran);}break;
case 6:{ petit_block(x,y,rouge,ecran);petit_block(x+42,y,rouge,ecran);petit_block(x+84,y,rouge,ecran);
                          petit_block(x+42,y-42,rouge,ecran);}break;
case 7:{ petit_block(x,y,orange,ecran);petit_block(x+42,y,orange,ecran);petit_block(x,y+42,orange,ecran);
                 petit_block(x+42,y+42,orange,ecran);}break;
case 8:{ petit_block(x,y,bleu,ecran);petit_block(x+42,y,bleu,ecran);petit_block(x+84,y,bleu,ecran);
                          petit_block(x+84,y+42,bleu,ecran);petit_block(x+84,y+84,bleu,ecran);}break;
case 9:{ petit_block(x,y,turcoise,ecran);petit_block(x+42,y,turcoise,ecran);petit_block(x+42,y+42,turcoise,ecran);
                          petit_block(x+42,y+84,turcoise,ecran); petit_block(x,y+84,turcoise,ecran);}break;
case 10:{ petit_block(x,y,jaune,ecran);petit_block(x+42,y,jaune,ecran);petit_block(x+84,y,jaune,ecran);
                          petit_block(x,y+42,jaune,ecran);petit_block(x+42,y+42,jaune,ecran); petit_block(x+84,y+42,jaune,ecran);
                          petit_block(x,y+84,jaune,ecran);petit_block(x+42,y+84,jaune,ecran);petit_block(x+84,y+84,jaune,ecran);}break;
case 11:{ petit_block(x,y,violet,ecran);petit_block(x,y+42,violet,ecran);petit_block(x+42,y+42,violet,ecran);}break;
case 12:{ petit_block(x,y,marron,ecran);petit_block(x,y+42,marron,ecran);petit_block(x,y+84,marron,ecran);
                    petit_block(x,y+126,marron,ecran);petit_block(x,y+168,marron,ecran);}break;
case 13:{ petit_block(x,y,vert,ecran);petit_block(x,y+42,vert,ecran);}break;

case 14:{ petit_block(x,y,violet,ecran);petit_block(x,y+42,violet,ecran);petit_block(x+42,y,violet,ecran);}break;

case 15:{ petit_block(x,y,violet,ecran);petit_block(x+42,y,violet,ecran);petit_block(x+42,y-42,violet,ecran);}break;

case 16:{ petit_block(x,y,lavande,ecran);petit_block(x,y+42,lavande,ecran);petit_block(x,y+84,lavande,ecran);}break;
case 17:{ petit_block(x,y,rose,ecran);petit_block(x,y+42,rose,ecran);petit_block(x,y+84,rose,ecran);
                        petit_block(x,y+126,rose,ecran);}break;
case 18:{ petit_block(x,y,rouge,ecran);petit_block(x+42,y,rouge,ecran);petit_block(x+84,y,rouge,ecran);
                        petit_block(x+42,y+42,rouge,ecran);}break;
case 19:{ petit_block(x,y,rouge,ecran);petit_block(x+42,y,rouge,ecran);petit_block(x+42,y-42,rouge,ecran);
                        petit_block(x+42,y+42,rouge,ecran);}break;
case 20:{ petit_block(x,y,rouge,ecran);petit_block(x,y+42,rouge,ecran);petit_block(x,y+84,rouge,ecran);
                        petit_block(x+42,y+42,rouge,ecran);}break;
case 21: {  petit_block(x,y,bleu,ecran); petit_block(x+42,y,bleu,ecran); petit_block(x+84,y,bleu,ecran);
   petit_block(x,y+42,bleu,ecran); petit_block(x,y+84,bleu,ecran);  }break;
case 22:{  petit_block(x,y,bleu,ecran); petit_block(x,y+42,bleu,ecran); petit_block(x,y+84,bleu,ecran);;
    petit_block(x+42,y+84,bleu,ecran); petit_block(x+84,y+84,bleu,ecran);}break;
case 23 : {  petit_block(x,y,bleu,ecran);petit_block(x+42,y,bleu,ecran);petit_block(x+84,y,bleu,ecran);
    petit_block(x+84,y-42,bleu,ecran);petit_block(x+84,y-84,bleu,ecran);}break;

case 24 :{  petit_block(x,y,turcoise,ecran);petit_block(x+42,y,turcoise,ecran); petit_block(x+84,y,turcoise,ecran);
    petit_block(x,y+42,turcoise,ecran);petit_block(x+84,y+42,turcoise,ecran);}break;
case 25 :{  petit_block(x,y,turcoise,ecran);petit_block(x+42,y,turcoise,ecran);petit_block(x,y+42,turcoise,ecran);
    petit_block(x,y+84,turcoise,ecran);petit_block(x+42,y+84,turcoise,ecran);}break;
case 26 : { petit_block(x,y,turcoise,ecran);petit_block(x+42,y+42,turcoise,ecran);petit_block(x+84,y,turcoise,ecran);
    petit_block(x,y+42,turcoise,ecran);petit_block(x+84,y+42,turcoise,ecran);}break;
case 27: { petit_block(x,y,marron,ecran);petit_block(x+42,y,marron,ecran);petit_block(x+84,y,marron,ecran);
    petit_block(x+126,y,marron,ecran);petit_block(x+168,y,marron,ecran);}break;

    }

}
// affichage des trois forme a droite
void affich_3_block(int x,int y,int choisir,SDL_Surface *ecran,int tab_affich3block[3])
{
    affich_1_block(671,46,tab_affich3block[0],ecran);
    affich_1_block(671,256,tab_affich3block[1],ecran);
    affich_1_block(671,466,tab_affich3block[2],ecran);
if(choisir==1){  affich_1_block(x-5,y-5,tab_affich3block[0],ecran); }
if(choisir==2){  affich_1_block(x-5,y-5,tab_affich3block[1],ecran); }
if(choisir==3){  affich_1_block(x-5,y-5,tab_affich3block[2],ecran); }

}

void occupy_all_blocks(int indis,int x,int y,block MAT[10][10],int *N,int *cpt_scor)
{
    if((x>50)&&(y>100))
    {
        if((x<570)&&(y<621))
        {
    switch (indis)
    {
       case 1:{ occupy_block1(x,y,MAT,N,cpt_scor); };break;
    case 2:{ occupy_block2(x,y,MAT,N,cpt_scor); };break;
    case 3:{ occupy_block3(x,y,MAT,N,cpt_scor); };break;
    case 4:{ occupy_block4(x,y,MAT,N,cpt_scor); };break;
    case 5:{ occupy_block5(x,y,MAT,N,cpt_scor); };break;
    case 6:{ occupy_block6(x,y,MAT,N,cpt_scor); };break;
    case 7:{ occupy_block7(x,y,MAT,N,cpt_scor); };break;
    case 8:{ occupy_block8(x,y,MAT,N,cpt_scor); };break;
    case 9:{ occupy_block9(x,y,MAT,N,cpt_scor); };break;
    case 10:{ occupy_block10(x,y,MAT,N,cpt_scor); };break;
    case 11:{ occupy_block11(x,y,MAT,N,cpt_scor); };break;
    case 12:{ occupy_block12(x,y,MAT,N,cpt_scor); };break;
    case 13:{ occupy_block13(x,y,MAT,N,cpt_scor); };break;
    case 14:{ occupy_block14(x,y,MAT,N,cpt_scor); };break;
    case 15:{ occupy_block15(x,y,MAT,N,cpt_scor); };break;
    case 16:{ occupy_block16(x,y,MAT,N,cpt_scor); };break;
    case 17:{ occupy_block17(x,y,MAT,N,cpt_scor); };break;
    case 18:{ occupy_block18(x,y,MAT,N,cpt_scor); };break;
    case 19:{ occupy_block19(x,y,MAT,N,cpt_scor); };break;
    case 20:{ occupy_block20(x,y,MAT,N,cpt_scor); };break;
    case 21:{ occupy_block21(x,y,MAT,N,cpt_scor); };break;
    case 22:{ occupy_block22(x,y,MAT,N,cpt_scor); };break;
    case 23:{ occupy_block23(x,y,MAT,N,cpt_scor); };break;
    case 24:{ occupy_block24(x,y,MAT,N,cpt_scor); };break;
    case 25:{ occupy_block25(x,y,MAT,N,cpt_scor); };break;
    case 26:{ occupy_block26(x,y,MAT,N,cpt_scor); };break;
    case 27:{ occupy_block27(x,y,MAT,N,cpt_scor); };break;
    }}}


     }
int suprimerligneetcolone(block MAT[10][10],int *cpt_scor)
{
    int i,j,n=0,m=0;
    for(i=0;i<10;i++)
    {
        n=0;
        for(j=0;j<10;j++)
        {
            if(MAT[i][j].occupe==1 || MAT[i][j].occupe==2)
            {
                n=n+1;
            }
        }
        if(n==10)
        {
            *cpt_scor=*cpt_scor+100;
            for(j=0;j<10;j++)
            {
                MAT[i][j].occupe=2;
            }

        }

    }
      for(i=0;i<10;i++)
    {
        m=0;
        for(j=0;j<10;j++)
        {
            if(MAT[j][i].occupe==1 || MAT[j][i].occupe==2)
            {
                m=m+1;
            }
        }
        if(m==10)
        {
            *cpt_scor=*cpt_scor+100;
            for(j=0;j<10;j++)
            {
                MAT[j][i].occupe=2;
            }

        }

    }
    if ((n==10)&& (m==10)){*cpt_scor=*cpt_scor+100;}

     for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(MAT[i][j].occupe==2)
            {
                MAT[i][j].occupe=0;
            }
        }
    }



return 0;

}

int placevide(int indis_choix,block MAT[10][10],int *x_voidplace ,int *y_voidplace)
{
     int i,j,vide=0;
    switch(indis_choix)
    {
    case 1:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
               {
                    if(MAT[i][j].occupe==0)
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }

               }
        }
        }break;
         case 2:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe!=1)&&(MAT[i+1][j].occupe!=1))
                    {
                    vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 3:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j+1].occupe==0))
                        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 4:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<10;j++)
               {
                   if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0))
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 5:
        {
            for(i=0;i<7;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)&&(MAT[i+3][j].occupe==0))
                        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 6:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&( MAT[i+2][j].occupe==0))
                        {
                            if(j>0 &&(MAT[i+1][j-1].occupe==0) ){ vide=1;*x_voidplace=i;*y_voidplace=j;}

                    }
               }
        }
        }break;
         case 7:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i][j+1].occupe==0)
             &&(MAT[i+1][j].occupe)==0)
             {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 8:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
               {
                   if( (MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i+2][j+1].occupe==0)&&(MAT[i+2][j+2].occupe==0))
                       {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 9:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)
                      &&(MAT[i+1][j+2].occupe==0)&&(MAT[i][j+2].occupe==0))
                       {
                           vide=1;*x_voidplace=i;*y_voidplace=j;
                        }
               }
        }
        }break;
         case 10:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
               {
                    if(  (MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
                         &&(MAT[i][j+1].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i+2][j+1].
                         occupe==0)&&(MAT[i][j+2].occupe==0)  &&(MAT[i+1][j+2]. occupe==0)&&(MAT[i+2][j+2].occupe==0))
                       {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                       }
               }
        }
        }break;
         case 11:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i+1][j+1].occupe==0))
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 12:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<6;j++)
               {
                    if((MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)&&(MAT[i][j+3].
           occupe==0)&&(MAT[i][j+4].occupe==0)&&(MAT[i][j].occupe==0))
           {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 13:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe!=1)&&(MAT[i][j+1].occupe!=1))
                        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 14:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe!=1)&&(MAT[i][j+1].occupe!=1)&&(MAT[i+1][j].occupe==0))
                        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 15:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0))
                              {
                                  if(j>0 &&(MAT[i+1][j-1].occupe==0) ){  vide=1;*x_voidplace=i;*y_voidplace=j; }
                              }
               }
        }
        }break;
         case 16:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<8;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0))
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 17:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<6;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)&&(MAT[i][j+3].occupe==0))
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 18:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)&&(MAT[i+1][j+1].occupe==0) )
                    {
                       vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
         case 19:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+1][j+1].occupe==0))
                { if(j>0 &&(MAT[i+1][j-1].occupe==0)){ vide=1;*x_voidplace=i;*y_voidplace=j;}

                    }
               }
        }
        }break;
        case 20:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
               {
                   if((MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)
            &&(MAT[i][j+2].occupe==0)&&(MAT[i+1][j+1].occupe==0))
          {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }

               }
        }
        }break;
        case 21:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
                         &&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0))
        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
        case 22:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i][j+1].occupe==0)&&(MAT[i][j+2].occupe==0)
                  &&(MAT[i+1][j+2].occupe==0)&&(MAT[i+2][j+2].occupe==0))
        {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
        case 23:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0))
                    {
                        if(j>1 &&(MAT[i+2][j-1].occupe==0)&&(MAT[i+2][j-2].occupe==0)){  vide=1;*x_voidplace=i;*y_voidplace=j;}

                    }
               }
        }
        }break;
        case 24:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i+2][j+1].occupe==0))
                    {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
        case 25:
        {
            for(i=0;i<9;i++)
        {
            for(j=0;j<8;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i][j+1].occupe==0)
        &&(MAT[i][j+2].occupe==0)&&(MAT[i+1][j+2].occupe==0))
                       {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                       }
               }
        }
        }break;
        case 26:
        {
            for(i=0;i<8;i++)
        {
            for(j=0;j<9;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j+1].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i][j+1].occupe==0)&&(MAT[i+2][j+1].occupe==0))
                   {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;
        case 27:
        {
            for(i=0;i<6;i++)
        {
            for(j=0;j<10;j++)
               {
                    if((MAT[i][j].occupe==0)&&(MAT[i+1][j].occupe==0)&&(MAT[i+2][j].occupe==0)
        &&(MAT[i+3][j].occupe==0)&&(MAT[i+4][j].occupe==0))
                   {
                        vide=1;*x_voidplace=i;*y_voidplace=j;
                    }
               }
        }
        }break;


    }

return (vide);
}

