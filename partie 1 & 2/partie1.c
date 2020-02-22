#include "constantes.h"
#include "partie1.h"
#include "fonction.h"
#include <SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL_ttf.h>



void jouer_partie1(SDL_Surface *ecran)
{
    int i=0,j=0,k=0;
    int continuer=1;
    SDL_Event event;
     block MAT[10][10];
    int red =0,x=-1,y=-1,aleatoir=1,now=0,ex=0,dt=0,periodfps=40,xsouri,ysouri,N_debut=0;
    int tab_affich3block[3]={0},choose=0;
    int N=0,cpt_scor=0,bestscor=1779,x_voidplace,y_voidplace;

for (i=0;i<10;i++)
{
    for (j=0;j<10;j++)
    {
        MAT[i][j].occupe=0;
    }
}




 while(continuer) // Mise en pause du programme
 {
     now=SDL_GetTicks();
        dt=now-ex;
    if(dt>periodfps)

    {
        SDL_PollEvent(&event);

         switch (event.type)
           {
           case SDL_QUIT:
           continuer=0;
           break;
           case SDL_MOUSEBUTTONUP:

               {
                   x=event.button.x;//on recupere les coordonnées de la souris
                   y = event.button.y;
                   //aleatoir=x%21;
                   if (x < 877 && x > 672 && y < 213 && y > 7 )
                    {
                            choose=1;
                    }
                   if(x < 877 && x > 672 && y < 425 && y > 224 )
                   {
                       choose=2;
                   }
                   if(x < 877 && x > 672 && y < 634 && y > 433)
                   {
                       choose=3;
                   }
                   if(x < 550 && x > 523 && y < 80 && y > 45)
                   {
                       choose=4;
                   }
                   x=x-(x-50)%52+2;y=y-(y-100)%52+2;


               }
               break;

           }
           SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,55,200,200));
          dessin_grille(ecran);
                                                                 //aleatoir=((SDL_GetTicks()+21)%21)+1;

if(red==0){
        if(tab_affich3block[0]==0){tab_affich3block[0]=((SDL_GetTicks()+4)%26)+1;}
        if(tab_affich3block[1]==0){tab_affich3block[1]=((SDL_GetTicks()+13)%26)+1;}
        if(tab_affich3block[2]==0){tab_affich3block[2]=((SDL_GetTicks()+18)%26)+1;}

         }
red=1;

 xsouri=event.button.x;ysouri=event.button.y;


       affich_3_block(xsouri,ysouri,choose,ecran,tab_affich3block);
       if(choose==4)
           {
               pause(ecran,&cpt_scor,&bestscor);
               SDL_Flip(ecran);
               choose=0;

           }

N_debut=N;
   if((y<621)&&(x>50)&&(y>100)&&(x<570))
   {

   if(choose==1 )
   {
      occupy_all_blocks(tab_affich3block[0],x,y,MAT,&N,&cpt_scor);
         texte(ecran,&cpt_scor,&bestscor);
      if(N_debut<N){  choose=0; x=-1; red=0; tab_affich3block[0]=0;}
   }
    if(choose==2 )
   {
     occupy_all_blocks(tab_affich3block[1],x,y,MAT,&N,&cpt_scor);
          texte(ecran,&cpt_scor,&bestscor);
      if(N_debut<N){  choose=0;x=-1;red=0;tab_affich3block[1]=0;}


   }
    if(choose==3)
   {
      occupy_all_blocks(tab_affich3block[2],x,y,MAT,&N,&cpt_scor);
     texte(ecran,&cpt_scor,&bestscor);
       if(N_debut<N){  choose=0;x=-1;red=0;tab_affich3block[2]=0;}
    }

   }
   texte(ecran,&cpt_scor,&bestscor);
    if((placevide(tab_affich3block[0],MAT,&x_voidplace,&y_voidplace)==0)&&(placevide(tab_affich3block[1],MAT,&x_voidplace,&y_voidplace)==0)&&(placevide(tab_affich3block[2],MAT,&x_voidplace,&y_voidplace)==0))
    {
        gameover(ecran);
    }



if(N>0)
{
    for(i=0;i<10;i++)
     {
       for(j=0;j<10;j++)
       {
           if(MAT[i][j].occupe==1)
           {
             grand_block(MAT[i][j].posx,MAT[i][j].posy,MAT[i][j].couleur,ecran);

           }
       }
     }
}


        SDL_Flip(ecran);
        suprimerligneetcolone(MAT,&cpt_scor);
        texte(ecran,&cpt_scor,&bestscor);




}
else
    {
         SDL_Delay(periodfps-dt);
    }


 }
// Libération de la surface


}
