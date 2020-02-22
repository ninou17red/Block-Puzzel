#include "constantes.h"
#include "partie1.h"
#include "fonction.h"
#include "partie2.h"
#include <SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL_ttf.h>





void jouer_partie2(SDL_Surface *ecran)
{
    int i=0,j=0,k=0,nmat=0;
    int continuer=1;
    SDL_Event event;
     block MAT[10][10];
    int red=0,x=-1,cpt,y=-1,now=0,ex=0,dt=0,periodfps=40,xsouri=50,ysouri=100,N_debut=0;
    int tab_affich3block[3]={0},choose=0,x_voidplace=-1,y_voidplace=-1;
    int N=0,compteurscor=0,bestscor=1779;
    srand(time(NULL));




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
                     if(x < 550 && x > 523 && y < 80 && y > 45)
                   {
                       choose=4;
                   }
                }
               break;

           }
           SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,55,200,200));

           dessin_grille(ecran);



         choose=(rand() % 3);
         if(choose==0){choose=3;}




    //aleatoir=((SDL_GetTicks()+21)%21)+1; on affiche l'autre forme de block

if(red==0){
        if(tab_affich3block[0]==0){tab_affich3block[0]=((SDL_GetTicks()+4)%26)+1;}
        if(tab_affich3block[1]==0){tab_affich3block[1]=((SDL_GetTicks()+13)%26)+1;}
        if(tab_affich3block[2]==0){tab_affich3block[2]=((SDL_GetTicks()+18)%26)+1;}

         }
red=1;




       affich_1_block(671,46,tab_affich3block[0],ecran);
       affich_1_block(671,256,tab_affich3block[1],ecran);
       affich_1_block(671,466,tab_affich3block[2],ecran);
       if(choose==4)
           {
               pause_machine(ecran,&compteurscor,&bestscor);
               SDL_Flip(ecran);
               choose=0;

           }

N_debut=N;



    if((choose==1)&&(placevide(tab_affich3block[0],MAT,&x_voidplace,&y_voidplace)==1) )
   {
        x=((x_voidplace*52)+52);y=((y_voidplace*52)+102);
      occupy_all_blocks(tab_affich3block[0],x,y,MAT,&N,&compteurscor);
            texte(ecran,&compteurscor,&bestscor);
      if(N_debut<N){  choose=-1; x=-1; red=0; tab_affich3block[0]=0;}
   }
    if((choose==2 )&&(placevide(tab_affich3block[1],MAT,&x_voidplace,&y_voidplace)==1) )
   {
       x=((x_voidplace*52)+52);y=((y_voidplace*52)+102);
     occupy_all_blocks(tab_affich3block[1],x,y,MAT,&N,&compteurscor);
          texte(ecran,&compteurscor,&bestscor);
      if(N_debut<N){  choose=-1;x=-1;red=0;tab_affich3block[1]=0;}


   }
    if((choose==3)&&(placevide(tab_affich3block[2],MAT,&x_voidplace,&y_voidplace)==1) )
   {
       x=((x_voidplace*52)+52);y=((y_voidplace*52)+102);
      occupy_all_blocks(tab_affich3block[2],x,y,MAT,&N,&compteurscor);
     texte(ecran,&compteurscor,&bestscor);
       if(N_debut<N){  choose=-1;x=-1;red=0;tab_affich3block[2]=0;}
    }


   texte(ecran,&compteurscor,&bestscor);




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
 if((placevide(tab_affich3block[0],MAT,&x_voidplace,&y_voidplace)==0)&&(placevide(tab_affich3block[1],MAT,&x_voidplace,&y_voidplace)==0)&&(placevide(tab_affich3block[2],MAT,&x_voidplace,&y_voidplace)==0))
    {
        gameover(ecran);
    }

        SDL_Delay(800);
        SDL_Flip(ecran);
        suprimerligneetcolone(MAT,&compteurscor);
        texte(ecran,&compteurscor,&bestscor);




}
else
    {
         SDL_Delay(periodfps-dt);
    }


 }

// Libération de la surface


}
