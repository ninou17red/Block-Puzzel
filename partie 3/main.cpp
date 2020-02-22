#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include<SDL/SDL_ttf.h>

typedef struct
{
    int occupe;
    int couleur1,couleur2,color3;
    int position_x,position_y;
}block;
SDL_Surface *colone;
SDL_Surface *ecran=NULL;
void dessin_de_grille();
int N,tab_affich3block[3]={0},choose=0,M,tab_affich3block2[3]={0},choose2=0,xvoid_place=0,yvoid_place=0;
int grand_block(int x,int y,int couleur1,int couleur2,int color3),cpt_scor,cpt_scor2,bestscor2=1779,bestscor=1779;
block tab[10][10], mat[10][10];
void affich_3_block(int x,int y);
void occupy_all_blocks(int indis,int x,int y);
void affch_1_block(int x,int y,int aficher);
int suprimerligneetcolone();
void texte();

//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
void occupy_all_blocks_machine(int indis,int x,int y);
int suprimerligneetcolone_machine();
int void_place(int indis);
int remplire_mat_machine(int couleur1,int couleur2,int color3,int position_x,int position_y);



int main(int argc, char *argv[])
{
    int continuer = 1,i,ok=0,x=-1,y=-1,j,now=0,ex=0,dt=0,periodfps=40,xsouri,ysouri,Npres=0;
    SDL_Event event;
    int red2=0,Mprecedent=0,x2=0,y2=0,Npres2;
    int kha=1;

     srand(time(NULL));
     for (i=0;i<10;i++)
     {
         for(j=0;j<10;j++)
         {
             mat[i][j].occupe=0;
             tab[i][j].occupe=0;
         }

     }

    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1000,680,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("partie 3 block puzzle", NULL);

while (continuer)
    {
        now=SDL_GetTicks();
        dt=now-ex;
        if(dt>periodfps)
        {

        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;


                case SDL_MOUSEBUTTONUP:
                    {
                        x=event.button.x;y=event.button.y;

                        //aleatoir=x%21;
                        if(x>314 && y>500 && x<470)
                            {choose=3;}
                        else
                        {
                            if(x>182&& y>500 && x<322 )
                                {choose=2;}

                        }

                        if(x<182 && y>500 )
                            {choose=1;}

                        x=x-(x-50)%40+3;y=y-(y-100)%40+3;


                    }
                    break;
        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,55,200,200));

        dessin_de_grille();

  //aleatoir=((SDL_GetTicks()+21)%21)+1;
  choose2=(rand() % 3);
    if(choose2==0){choose2=3;}





if(ok == 0)
    {
        if(tab_affich3block[0]==0){tab_affich3block[0]=((SDL_GetTicks()+4)%26)+1;}
        if(tab_affich3block[1]==0){tab_affich3block[1]=((SDL_GetTicks()+13)%26)+1;}
        if(tab_affich3block[2]==0){tab_affich3block[2]=((SDL_GetTicks()+18)%26)+1;}
    }
    ok =1;


if(red2==0)
    {
        if(tab_affich3block2[0]==0){tab_affich3block2[0]=((SDL_GetTicks()+4)%26)+1;}
        if(tab_affich3block2[1]==0){tab_affich3block2[1]=((SDL_GetTicks()+13)%26)+1;}
        if(tab_affich3block2[2]==0){tab_affich3block2[2]=((SDL_GetTicks()+18)%26)+1;}
    }


red2=1;


      affch_1_block(532,540,tab_affich3block2[0]);
      affch_1_block(678,540,tab_affich3block2[1]);
      affch_1_block(824,540,tab_affich3block2[2]);

if (kha==0)
{


   Mprecedent=M;

      if((choose2==1 )&&(void_place(tab_affich3block2[0])))
   {
       x2=xvoid_place*40+554;y2=yvoid_place*40+104;
      occupy_all_blocks_machine(tab_affich3block2[0],x2,y2);
      if(Mprecedent<M){  choose2=-1;x2=-1;red2=0;tab_affich3block2[0]=0;}
      texte();
      kha=1;

   }
    if((choose2==2 )&&(void_place(tab_affich3block2[1])))
   {
       x2=xvoid_place*40+554;y2=yvoid_place*40+104;
     occupy_all_blocks_machine(tab_affich3block2[1],x2,y2);
      if(Mprecedent<M)
        {  choose2=-1;x2=-1;red2=0;tab_affich3block2[1]=0;}
        texte();
        kha=1;

   }
    if((choose2==3)&&(void_place(tab_affich3block2[2])))
   {
       x2=xvoid_place*40+554;y2=yvoid_place*40+104;
     occupy_all_blocks_machine(tab_affich3block2[2],x2,y2);
      if(Mprecedent<M){  choose2=-1;x2=-1;red2=0;tab_affich3block2[2]=0;}
      texte();
      kha=1;
   }

}
texte();
if ((void_place(tab_affich3block2[0])==0)&&(void_place(tab_affich3block2[1])==0)&&(void_place(tab_affich3block2[2])==0))
{
    kha=1;
}


  xsouri=event.button.x;ysouri=event.button.y;


       affich_3_block(xsouri,ysouri);

if (kha==1)
{


Npres=N;
   if((y<500)&&(x>50)&&(y>100)&&(x<450))
   {


   if(choose==1 )
   {
      occupy_all_blocks(tab_affich3block[0],x,y);
      if(Npres<N){  choose=0;x=-1;ok=0;tab_affich3block[0]=0;}
      texte();
      kha=0;
   }
    if(choose==2 )
   {
     occupy_all_blocks(tab_affich3block[1],x,y);
      if(Npres<N){  choose=0;x=-1;ok=0;tab_affich3block[1]=0;}
      texte();
      kha=0;


   }
    if(choose==3)
   {
      occupy_all_blocks(tab_affich3block[2],x,y);
       if(Npres<N){  choose=0;x=-1;ok=0;tab_affich3block[2]=0;}
       texte();
       kha=0;
   }
   }
}
texte();

Npres2=N;

if(N>0)
    {
   for(i=0;i<10;i++)
   {
       for(j=0;j<10;j++)
       {
           if(tab[i][j].occupe==1)
           {
           grand_block(tab[i][j].position_x,tab[i][j].position_y,tab[i][j].couleur1,tab[i][j].couleur2,tab[i][j].color3);

           }
       }
   }
      }


      if(M>0)
    {
   for(i=0;i<10;i++)
   {
       for(j=0;j<10;j++)
       {
           if(mat[i][j].occupe==1)
           {
           grand_block(mat[i][j].position_x,mat[i][j].position_y,mat[i][j].couleur1,mat[i][j].couleur2,mat[i][j].color3);

           }
       }
   }
      }



        SDL_Flip(ecran);
        suprimerligneetcolone();
        suprimerligneetcolone_machine();
        texte();

 ex=now;


    }
    else
    {
         SDL_Delay(periodfps-dt);
        }


    }

    SDL_Quit();

    return EXIT_SUCCESS;

}
// **************************************************************************************


void dessin_de_grille()
{
      SDL_Surface *lignes[22];
      SDL_Rect posligne;int i;
      SDL_Surface *lignes2[22];
      SDL_Rect posligne2;
       i=0;
    while(i<11)
        {
            lignes[i]=SDL_CreateRGBSurface(SDL_SWSURFACE,400,2,32,0,0,0,0);
            i++;

        }

    i=0;
    while(i<11)
        {
            lignes[i+11]=SDL_CreateRGBSurface(SDL_SWSURFACE,2,400,32,0,0,0,0);
            i++;

        }

         for(i=0;i<11;i++)
    {
        posligne.x=50;
        posligne.y=100+i*40;

    SDL_FillRect(lignes[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes[i],NULL,ecran,&posligne);

    }
    for(i=0;i<11;i++)
    {
        posligne.x=50+i*40;
        posligne.y=100;

    SDL_FillRect(lignes[i+11],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes[i+11],NULL,ecran,&posligne);

    }

     for(i=0;i<22;i++)
    {
        SDL_FreeSurface(lignes[i]);
    }
    posligne.x=40;
    posligne.y=510;

    for(i=0;i<3;i++)
    {
        posligne.x=(147)*i+30;
    posligne.y=510;

    lignes[i]=SDL_CreateRGBSurface(SDL_SWSURFACE,146,165,32,0,0,0,0);
    SDL_FillRect(lignes[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes[i],NULL,ecran,&posligne);


    }
    //kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
    //kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
       i=0;
    while(i<11)
        {
            lignes2[i]=SDL_CreateRGBSurface(SDL_SWSURFACE,400,2,32,0,0,0,0);
            i++;

        }

    i=0;
    while(i<11)
        {
            lignes2[i+11]=SDL_CreateRGBSurface(SDL_SWSURFACE,2,400,32,0,0,0,0);
            i++;

        }

         for(i=0;i<11;i++)
    {
        posligne2.x=550;
        posligne2.y=100+i*40;

    SDL_FillRect(lignes2[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes2[i],NULL,ecran,&posligne2);

    }
    for(i=0;i<11;i++)
    {
        posligne2.x=550+i*40;
        posligne2.y=100;

    SDL_FillRect(lignes2[i+11],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes2[i+11],NULL,ecran,&posligne2);

    }

     for(i=0;i<22;i++)
    {
        SDL_FreeSurface(lignes2[i]);
    }
    posligne2.x=540;
    posligne2.y=510;

    for(i=0;i<3;i++)
    {
        posligne2.x=(147)*i+530;
    posligne2.y=510;

    lignes2[i]=SDL_CreateRGBSurface(SDL_SWSURFACE,146,165,32,0,0,0,0);
    SDL_FillRect(lignes2[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(lignes2[i],NULL,ecran,&posligne2);


    }

    //liberatioooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
      for(i=0;i<3;i++)
    {
        SDL_FreeSurface(lignes[i]);
    }
      for(i=0;i<3;i++)
    {
        SDL_FreeSurface(lignes2[i]);
    }

}

int grand_block(int x,int y,int couleur1,int couleur2,int color3)
{
    SDL_Rect position;
    position.x=x;position.y=y;

        colone=SDL_CreateRGBSurface(SDL_SWSURFACE,35,35,32,0,0,0,0);

    SDL_FillRect(colone,NULL,SDL_MapRGB(ecran->format,couleur1,couleur2,color3));
    SDL_BlitSurface(colone,NULL,ecran,&position);
       SDL_FreeSurface(colone);

        position.x=x+5;position.y=y+5;

        colone=SDL_CreateRGBSurface(SDL_SWSURFACE,25,25,32,0,0,0,0);


    SDL_FillRect(colone,NULL,SDL_MapRGB(ecran->format,couleur1-30,couleur2-30,color3-30));
    SDL_BlitSurface(colone,NULL,ecran,&position);
           SDL_FreeSurface(colone);

           position.x=x+4;position.y=y+4;

        colone=SDL_CreateRGBSurface(SDL_SWSURFACE,31,31,32,0,0,0,0);


    SDL_FillRect(colone,NULL,SDL_MapRGB(ecran->format,couleur1-20,couleur2-20,color3-20));
    SDL_BlitSurface(colone,NULL,ecran,&position);
           SDL_FreeSurface(colone);

    return 0;


}


int occupy_mat_block(int couleur1,int couleur2,int color3,int position_x,int position_y)
{
    int i=(position_x-50)/40,j=(position_y-100)/40;
    tab[i][j].couleur1=couleur1;tab[i][j].couleur2=couleur2;tab[i][j].color3=color3;tab[i][j].occupe=1;tab[i][j].position_x=position_x;tab[i][j].position_y=position_y;

    return 0;
}
int occupy_block1(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
    if(tab[i][j].occupe!=1)
    {occupy_mat_block(100,200,50,x,y);N=N+1;
    return 0;
    }
}
int occupy_block2(int x,int y)
{
int i=(x-50)/40,j=(y-100)/40;
    if((tab[i][j].occupe!=1)&&(tab[i+1][j].occupe!=1))
    {occupy_mat_block(30,230,70,x,y);N=N+1;occupy_mat_block(30,230,70,x+40,y);cpt_scor=cpt_scor+20;
        N=N+1;
        return 0;
    }
}
int occupy_block3(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
     if ((x>50)&&(y>100)&&(y<460)&&(x<410)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+1][j+1].occupe==0))
    {occupy_mat_block(30,255,255,x,y);N=N+1;occupy_mat_block(30,255,255,x+40,y);N=N+1;occupy_mat_block(30,255,255,x+40,y+40);N=N+1;cpt_scor=cpt_scor+30;
    }

        return 0;
}
int occupy_block4(int x,int y)
{
     int i=(x-50)/40,j=(y-100)/40;
     if ((x>50)&&(y>100)&&(x<370)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+2][j].occupe==0))
     {occupy_mat_block(50,100,100,x,y);N=N+1;occupy_mat_block(50,100,100,x+40,y);N=N+1;occupy_mat_block(50,100,100,x+80,y);N=N+1;cpt_scor=cpt_scor+30;
     }
        return 0;
}
int occupy_block5(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
     if ((x>50)&&(y>100)&&(x<330)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+2][j].occupe==0)&&(tab[i+3][j].occupe==0))
      {occupy_mat_block(70,100,255,x,y);N=N+1;occupy_mat_block(70,100,255,x+40,y);N=N+1;occupy_mat_block(70,100,255,x+80,y);N=N+1;occupy_mat_block(70,100,255,x+120,y);N=N+1;cpt_scor=cpt_scor+40;
      }
        return 0;
}

int occupy_block6(int x,int y)
{
   int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(x<370)&&(y>140)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&
                        ( tab[i+2][j].occupe==0)&&(tab[i+1][j-1].occupe==0))
        {occupy_mat_block(100,100,100,x,y);N=N+1;occupy_mat_block(100,100,100,x+40,y);N=N+1;occupy_mat_block(100,100,100,x+80,y);N=N+1;occupy_mat_block(100,100,100,x+40,y-40);N=N+1;cpt_scor=cpt_scor+40;
      }
        return 0;
}
int occupy_block7(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
   if ((x>50)&&(x<410)&&(y<460)&&(y>100)&&(tab[i][j].occupe==0)&&(tab[i+1][j+1].occupe==0)&&(tab[i][j+1].occupe==0)
             &&(tab[i+1][j].occupe)==0)
      {occupy_mat_block(80,200,50,x,y);N=N+1;occupy_mat_block(80,200,50,x+40,y);N=N+1;occupy_mat_block(80,200,50,x,y+40);N=N+1;occupy_mat_block(80,200,50,x+40,y+40);N=N+1;cpt_scor=cpt_scor+40;
       }
        return 0;
}
int occupy_block8(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(x<370)&&(y<420)&&(y>100)&&(tab[i][j].occupe==0)&&(tab[i+1][j].
                                                                   occupe==0)&&(tab[i+2][j].
                                                                               occupe==0)
        &&(tab[i+2][j+1].occupe==0)&&(tab[i+2][j+2].occupe==0))
       {occupy_mat_block(130,70,255,x,y);N=N+1;occupy_mat_block(130,70,255,x+40,y);N=N+1;occupy_mat_block(130,70,255,x+80,y);N=N+1;occupy_mat_block(130,70,255,x+80,y+40);N=N+1;occupy_mat_block(130,70,255,x+80,y+80);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;
}
int occupy_block9(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(y>100)&&(x<410)&&(y<420)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+1][j+1].occupe==0)
        &&(tab[i+1][j+2].
           occupe==0)&&(tab[i][j+2].
                       occupe==0))
    {occupy_mat_block(200,130,70,x,y);N=N+1;occupy_mat_block(200,130,70,x+40,y);N=N+1;occupy_mat_block(200,130,70,x+40,y+40);N=N+1;occupy_mat_block(200,130,70,x+40,y+80);N=N+1;occupy_mat_block(200,130,70,x,y+80);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;
}
int occupy_block10(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
       if ((x>50)&&(x<370)&&(y<420)&&(y>100)&&(tab[i][j].
                                               occupe==0)&&(tab[i+1][j].
                                                           occupe==0)&&(tab[i+2][j].occupe==0)
        &&(tab[i][j+1].occupe==0)&&(tab[i+1][j+1].
                                     occupe==0)&&(tab[i+2][j+1].
                                                 occupe==0)&&(tab[i][j+2].
                                                             occupe==0)  &&(tab[i+1][j+2]. occupe==0)&&(tab[i+2][j+2]. occupe==0))



           {occupy_mat_block(255,200,50,x,y);N=N+1;occupy_mat_block(255,200,50,x+40,y);N=N+1;occupy_mat_block(255,200,50,x+80,y);N=N+1;occupy_mat_block(255,200,50,x,y+40);N=N+1;occupy_mat_block(255,200,50,x+40,y+40);N=N+1;occupy_mat_block(255,200,50,x+80,y+40);N=N+1;occupy_mat_block(255,200,50,x,y+80);N=N+1;occupy_mat_block(255,200,50,x+40,y+80);N=N+1;occupy_mat_block(255,200,50,x+80,y+80);N=N+1;cpt_scor=cpt_scor+90;
           }
        return 0;
}
int occupy_block11(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(y>100)&&(y<460)&&(x<410)&&(tab[i][j].occupe==0)&&(tab[i+1][j+1].occupe==0)&&(tab[i][j+1].occupe==0))
{occupy_mat_block(200,50,255,x,y);N=N+1;occupy_mat_block(200,50,255,x,y+40);N=N+1;occupy_mat_block(200,50,255,x+40,y+40);N=N+1;cpt_scor=cpt_scor+30;
    }
        return 0;
}
int occupy_block12(int x,int y)
{
     int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(x<450)&&(y<340)&&(y>100)&&(tab[i][j+1].occupe==0)&&(tab[i][j+2].occupe==0)&&(tab[i][j+3].
           occupe==0)&&(tab[i][j+4].occupe==0)&&(tab[i][j].occupe==0))
    {occupy_mat_block(110,200,200,x,y);N=N+1;occupy_mat_block(110,200,200,x,y+40);N=N+1;occupy_mat_block(110,200,200,x,y+80);N=N+1;occupy_mat_block(110,200,200,x,y+120);N=N+1;occupy_mat_block(110,200,200,x,y+160);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;
}
int occupy_block13(int x,int y)
{
     int i=(x-50)/40,j=(y-100)/40;
        if ((y<460)&&(x<450)&&(y>100)&&(x>50)&&(tab[i][j].
                                                occupe!=1)&&(tab[i][j+1].
                                                            occupe!=1))
        {occupy_mat_block(100,230,70,x,y);N=N+1;occupy_mat_block(100,230,70,x,y+40);N=N+1;cpt_scor=cpt_scor+20;
        }
        return 0;
}
int occupy_block14(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
    if ((y>100)&&(x>50)&&(x<410)&&(y<460)&&(tab[i][j].
                                            occupe!=1)&&
        (tab[i][j+1].
         occupe!=1)&&(tab[i+1][j].occupe==0))
        {occupy_mat_block(30,120,200,x,y);N=N+1;occupy_mat_block(30,120,200,x,y+40);N=N+1;occupy_mat_block(30,120,200,x+40,y);N=N+1;cpt_scor=cpt_scor+30;
        }
        return 0;
}
int occupy_block15(int x,int y)
{
     int i=(x-50)/40,j=(y-100)/40;
    if ((y>140)&&(x>50)&&(x<410)&&(y<500)&&(tab[i][j].occupe!=1)&&
        (tab[i+1][j].occupe!=1)&&(tab[i+1][j-1].
                                 occupe==0))
        {occupy_mat_block(190,200,70,x,y);N=N+1;occupy_mat_block(190,200,70,x+40,y);N=N+1;occupy_mat_block(190,200,70,x+40,y-40);N=N+1;cpt_scor=cpt_scor+30;
        }
        return 0;
}
int occupy_block16(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40,k;
     if ((x>50)&&(y>100)&&(y<410)&&(x<450)&&(tab[i][j].
                                             occupe==0)&&(tab[i][j+1].
                                                         occupe==0)&&(tab[i][j+2].
                                                                     occupe==0))
     {occupy_mat_block(230,80,170,x,y);N=N+1;occupy_mat_block(230,80,170,x,y+40);N=N+1;occupy_mat_block(230,80,170,x,y+80);N=N+1;cpt_scor=cpt_scor+30;
     }
        return 0;
}

int occupy_block17(int x,int y)
{
     int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(y>100)&&(y<380)&&(x<450)&&(tab[i][j].occupe==0)&&(tab[i][j+1].
                    occupe==0)&&(tab[i][j+2].occupe==0)&&(tab[i][j+3].occupe==0))
    {occupy_mat_block(230,200,100,x,y);N=N+1;occupy_mat_block(230,200,100,x,y+40);N=N+1;occupy_mat_block(230,200,100,x,y+80);N=N+1;occupy_mat_block(230,200,100,x,y+120);N=N+1;cpt_scor=cpt_scor+40;
    }
        return 0;
}

int occupy_block18(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(x<370)&&(y>100)&&(y<460)&&(tab[i][j].
                        occupe==0)&&(tab[i+1][j].occupe==0)&&( tab[i+2][j].
                    occupe==0)&&(tab[i+1][j+1].occupe==0))
        {occupy_mat_block(150,160,200,x,y);N=N+1;occupy_mat_block(150,160,200,x+40,y);N=N+1;occupy_mat_block(150,160,200,x+80,y);N=N+1;occupy_mat_block(150,160,200,x+40,y+40);N=N+1;cpt_scor=cpt_scor+40;
        }
        return 0;
}

int occupy_block19(int x,int y)
{
      int i=(x-50)/40,j=(y-100)/40;
     if ((x>50)&&(y>140)&&(y<460)&&(x<410)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+1][j-1].occupe==0)&&(tab[i+1][j+1].occupe==0))
     {occupy_mat_block(170,80,80,x,y);N=N+1;occupy_mat_block(170,80,80,x+40,y);N=N+1;occupy_mat_block(170,80,80,x+40,y-40);N=N+1;occupy_mat_block(170,80,80,x+40,y+40);N=N+1;cpt_scor=cpt_scor+40;

     }
        return 0;
}
int occupy_block20(int x,int y)
{
    int i=(x-50)/40,j=(y-100)/40;
     if ((x>50)&&(y>100)&&(y<420)&&(x<410)&&(tab[i][j].occupe==0)&&(tab[i][j+1].occupe==0)
         &&(tab[i][j+2].occupe==0)&&(tab[i+1][j+1].occupe==0))
     {occupy_mat_block(80,80,170,x,y);N=N+1;occupy_mat_block(80,80,170,x,y+40);N=N+1;occupy_mat_block(80,80,170,x,y+80);N=N+1;occupy_mat_block(80,80,170,x+40,y+40);N=N+1;cpt_scor=cpt_scor+40;
     }
        return 0;
}
int occupy_block21(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40;

      if ((x>50)&&(x<370)&&(y<420)&&(y>100)&&(tab[i][j].occupe==0)&&(tab[i+1][j].
                                                                   occupe==0)&&(tab[i+2][j].
                                                                               occupe==0)
        &&(tab[i][j+1].occupe==0)&&(tab[i][j+2].occupe==0))
       {occupy_mat_block(130,70,255,x,y);N=N+1;occupy_mat_block(130,70,255,x+40,y);N=N+1;occupy_mat_block(130,70,255,x+80,y);N=N+1;occupy_mat_block(130,70,255,x,y+40);N=N+1;occupy_mat_block(130,70,255,x,y+80);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;
}
int occupy_block22(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40;
  if ((x>50)&&(x<370)&&(y<420)&&(y>100)&&(tab[i][j].occupe==0)&&(tab[i][j+1].
                                                                   occupe==0)&&(tab[i][j+2].
                                                                               occupe==0)
        &&(tab[i+1][j+2].occupe==0)&&(tab[i+2][j+2].occupe==0))
       {occupy_mat_block(130,70,255,x,y);N=N+1;occupy_mat_block(130,70,255,x,y+40);N=N+1;occupy_mat_block(130,70,255,x,y+80);N=N+1;occupy_mat_block(130,70,255,x+40,y+80);N=N+1;occupy_mat_block(130,70,255,x+80,y+80);N=N+1;cpt_scor=cpt_scor+50;
    }
   return 0;
}
int occupy_block23(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40;
       if ((x>50)&&(x<370)&&(y<500)&&(y>180)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+2][j].occupe==0)
        &&(tab[i+2][j-1].occupe==0)&&(tab[i+2][j-2].occupe==0))
       {occupy_mat_block(130,70,255,x,y);N=N+1;occupy_mat_block(130,70,255,x+40,y);N=N+1;occupy_mat_block(130,70,255,x+80,y);N=N+1;occupy_mat_block(130,70,255,x+80,y-40);N=N+1;occupy_mat_block(130,70,255,x+80,y-80);N=N+1;cpt_scor=cpt_scor+50;
    }
    return 0;
}
int occupy_block24(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40;
    if ((x>50)&&(y>100)&&(x<370)&&(y<460)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+2][j].occupe==0)
        &&(tab[i][j+1].occupe==0)&&(tab[i+2][j+1].occupe==0))
    {occupy_mat_block(200,70,70,x,y);N=N+1;occupy_mat_block(200,70,70,x+40,y);N=N+1;occupy_mat_block(200,70,70,x+80,y);N=N+1;occupy_mat_block(200,70,70,x,y+40);N=N+1;occupy_mat_block(200,70,70,x+80,y+40);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;

}
int occupy_block25(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40;

    if ((x>50)&&(y>100)&&(x<410)&&(y<420)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i][j+1].occupe==0)
        &&(tab[i][j+2].
           occupe==0)&&(tab[i+1][j+2].
                       occupe==0))
    {occupy_mat_block(200,70,70,x,y);N=N+1;occupy_mat_block(200,70,70,x+40,y);N=N+1;occupy_mat_block(200,70,70,x,y+40);N=N+1;occupy_mat_block(200,70,70,x,y+80);N=N+1;occupy_mat_block(200,70,70,x+40,y+80);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;

}
int occupy_block26(int x, int y)
{
     int i=(x-50)/40,j=(y-100)/40,k,l;
     if ((x>50)&&(y>100)&&(x<370)&&(y<460)&&(tab[i][j].occupe==0)&&(tab[i+1][j+1].occupe==0)&&(tab[i+2][j].occupe==0)
        &&(tab[i][j+1].occupe==0)&&(tab[i+2][j+1].occupe==0))
    {occupy_mat_block(200,70,70,x,y);N=N+1;occupy_mat_block(200,70,70,x+40,y+40);N=N+1;occupy_mat_block(200,70,70,x+80,y);N=N+1;occupy_mat_block(200,70,70,x,y+40);N=N+1;occupy_mat_block(200,70,70,x+80,y+40);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;


}
int occupy_block27(int x, int y)
{
    int i=(x-50)/40,j=(y-100)/40;
         if ((x>50)&&(y>100)&&(x<290)&&(y<500)&&(tab[i][j].occupe==0)&&(tab[i+1][j].occupe==0)&&(tab[i+2][j].occupe==0)
        &&(tab[i+3][j].occupe==0)&&(tab[i+4][j].occupe==0))
    {
    occupy_mat_block(200,130,70,x,y);N=N+1;occupy_mat_block(200,130,70,x+40,y);N=N+1;occupy_mat_block(200,130,70,x+80,y);N=N+1;occupy_mat_block(200,130,70,x+120,y);N=N+1;occupy_mat_block(200,130,70,x+160,y);N=N+1;cpt_scor=cpt_scor+50;
    }
        return 0;

}




void grand_block_3_chois(int x,int y,int couleur1,int couleur2,int color3)
{
    SDL_Rect position;
    position.x=x;position.y=y;
    SDL_Surface *colon;



        colon=SDL_CreateRGBSurface(SDL_SWSURFACE,26,26,32,0,0,0,0);


    SDL_FillRect(colon,NULL,SDL_MapRGB(ecran->format,couleur1,couleur2,color3));
    SDL_BlitSurface(colon,NULL,ecran,&position);
    SDL_FreeSurface(colon);
        position.x=x+4;position.y=y+4;

        colon=SDL_CreateRGBSurface(SDL_SWSURFACE,18,18,32,0,0,0,0);


    SDL_FillRect(colon,NULL,SDL_MapRGB(ecran->format,couleur1-30,couleur2-30,color3-30));
    SDL_BlitSurface(colon,NULL,ecran,&position);
    SDL_FreeSurface(colon);
     position.x=x+3;position.y=y+3;

        colon=SDL_CreateRGBSurface(SDL_SWSURFACE,23,23,32,0,0,0,0);


    SDL_FillRect(colon,NULL,SDL_MapRGB(ecran->format,couleur1-15,couleur2-15,color3-15));
    SDL_BlitSurface(colon,NULL,ecran,&position);
    SDL_FreeSurface(colon);
}
void affch_1_block(int x,int y,int aficher)
{
    switch(aficher)
    {
case 1:
    { grand_block_3_chois(x,y,100,200,50);}break;
case 2:
    { grand_block_3_chois(x,y,50,230,70);grand_block_3_chois(x+27,y,50,230,70);}break;
case 3:
    { grand_block_3_chois(x,y,50,255,255);grand_block_3_chois(x+27,y,50,255,255);grand_block_3_chois(x+27,y+27,50,255,255);}break;
case 4:
    { grand_block_3_chois(x,y,50,100,100);grand_block_3_chois(x+27,y,50,100,100);grand_block_3_chois(x+54,y,50,100,100);}break;
case 5:
    { grand_block_3_chois(x,y,70,100,255);grand_block_3_chois(x+27,y,70,100,255);grand_block_3_chois(x+54,y,70,100,255);
                        grand_block_3_chois(x+81,y,70,100,255);}break;
case 6:
    { grand_block_3_chois(x,y,100,100,100);grand_block_3_chois(x+27,y,100,100,100);grand_block_3_chois(x+54,y,100,100,100);
                          grand_block_3_chois(x+27,y-27,100,100,100);}break;
case 7:
    { grand_block_3_chois(x,y,80,200,50);grand_block_3_chois(x+27,y,80,200,50);grand_block_3_chois(x,y+27,80,200,50);
                 grand_block_3_chois(x+27,y+27,80,200,50);}break;
case 8:
    { grand_block_3_chois(x,y,130,70,255);grand_block_3_chois(x+27,y,130,70,255);grand_block_3_chois(x+54,y,130,70,255);
                          grand_block_3_chois(x+54,y+27,130,70,255);grand_block_3_chois(x+54,y+54,130,70,255);}break;
case 9:
    { grand_block_3_chois(x,y,200,130,70);grand_block_3_chois(x+27,y,200,130,70);grand_block_3_chois(x+27,y+27,200,130,70);
                          grand_block_3_chois(x+27,y+54,200,130,70); grand_block_3_chois(x,y+54,200,130,70);}break;
case 10:
    { grand_block_3_chois(x,y,255,200,50);grand_block_3_chois(x+27,y,255,200,50);grand_block_3_chois(x+54,y,255,200,50);
                          grand_block_3_chois(x,y+27,255,200,50);grand_block_3_chois(x+27,y+27,255,200,50); grand_block_3_chois(x+54,y+27,255,200,50);
                          grand_block_3_chois(x,y+54,255,200,50);grand_block_3_chois(x+27,y+54,255,200,50);grand_block_3_chois(x+54,y+54,255,200,50);}break;
case 11:
    { grand_block_3_chois(x,y,200,50,255);grand_block_3_chois(x,y+27,200,50,255);grand_block_3_chois(x+27,y+27,200,50,255);}break;
case 12:
    { grand_block_3_chois(x,y,110,200,200);grand_block_3_chois(x,y+27,110,200,200);grand_block_3_chois(x,y+54,110,200,200);
                    grand_block_3_chois(x,y+81,110,200,200);grand_block_3_chois(x,y+108,110,200,200);}break;
case 13:
     {grand_block_3_chois(x,y,100,230,70);grand_block_3_chois(x,y+27,100,230,70
                                                                );}break;
case 14:
    { grand_block_3_chois(x,y,50,120,200);grand_block_3_chois(x,y+27,50,120,200);grand_block_3_chois(x+27,y,50,120,200);}break;
case 15:
    { grand_block_3_chois(x,y,190,200,70);grand_block_3_chois(x+27,y,190,200,70);grand_block_3_chois(x+27,y-27,190,200,70);}break;
case 16:
    { grand_block_3_chois(x,y,230,80,170);grand_block_3_chois(x,y+27,230,80,170);grand_block_3_chois(x,y+54,230,80,170);}break;
case 17:
    { grand_block_3_chois(x,y,230,200,100);grand_block_3_chois(x,y+27,230,200,100);grand_block_3_chois(x,y+54,230,200,100);
                        grand_block_3_chois(x,y+81,230,200,100);}break;
case 18:
    { grand_block_3_chois(x,y,150,160,200);grand_block_3_chois(x+27,y,150,160,200);grand_block_3_chois(x+54,y,150,160,200);
                        grand_block_3_chois(x+27,y+27,150,160,200);}break;
case 19:
    { grand_block_3_chois(x,y,170,80,80);grand_block_3_chois(x+27,y,170,80,80);grand_block_3_chois(x+27,y-27,170,80,80);
                        grand_block_3_chois(x+27,y+27,170,80,80);}break;
case 20:
    { grand_block_3_chois(x,y,80,80,170);grand_block_3_chois(x,y+27,80,80,170);grand_block_3_chois(x,y+54,80,80,170);
                        grand_block_3_chois(x+27,y+27,80,80,170);}break;
case 21:
    {  grand_block_3_chois(x,y,130,70,255); grand_block_3_chois(x+27,y,130,70,255); grand_block_3_chois(x+54,y,130,70,255);
   grand_block_3_chois(x,y+27,130,70,255); grand_block_3_chois(x,y+54,130,70,255);  }break;
case 22:
    {  grand_block_3_chois(x,y,130,70,255); grand_block_3_chois(x,y+27,130,70,255); grand_block_3_chois(x,y+54,130,70,255);;
    grand_block_3_chois(x+27,y+54,130,70,255); grand_block_3_chois(x+54,y+54,130,70,255);}break;
case 23 :
    {  grand_block_3_chois(x,y,130,70,255);grand_block_3_chois(x+27,y,130,70,255);grand_block_3_chois(x+54,y,130,70,255);
    grand_block_3_chois(x+54,y-27,130,70,255);grand_block_3_chois(x+54,y-54,130,70,255);}break;
case 24 :
    {  grand_block_3_chois(x,y,200,70,70);grand_block_3_chois(x+27,y,200,70,70); grand_block_3_chois(x+54,y,200,70,70);
    grand_block_3_chois(x,y+27,200,70,70);grand_block_3_chois(x+54,y+27,200,70,70);}break;
case 25 :
    {  grand_block_3_chois(x,y,200,70,70);grand_block_3_chois(x+27,y,200,70,70);grand_block_3_chois(x,y+27,200,70,70);
    grand_block_3_chois(x,y+54,200,70,70);grand_block_3_chois(x+27,y+54,200,70,70);}break;
case 26 :
    { grand_block_3_chois(x,y,200,70,70);grand_block_3_chois(x+27,y+27,200,70,70);grand_block_3_chois(x+54,y,200,70,70);
    grand_block_3_chois(x,y+27,200,70,70);grand_block_3_chois(x+54,y+27,200,70,70);}break;
case 27:
     { grand_block_3_chois(x,y,200,130,70);grand_block_3_chois(x+27,y,200,130,70);grand_block_3_chois(x+54,y,200,130,70);
    grand_block_3_chois(x+81,y,200,130,70);grand_block_3_chois(x+108,y,200,130,70);}break;

    }
}

void affich_3_block(int x,int y)
{
    affch_1_block(32,540,tab_affich3block[0]);affch_1_block(178,540,tab_affich3block[1]);affch_1_block(324,540,tab_affich3block[2]);
if(choose==1)
    {  affch_1_block(x-5,y-5,tab_affich3block[0]); }
if(choose==2)
{  affch_1_block(x-5,y-5,tab_affich3block[1]); }
if(choose==3)
{  affch_1_block(x-5,y-5,tab_affich3block[2]); }
}

void occupy_all_blocks(int indis,int x,int y)
{
    if((x>50)&&(y>100))
    {
        if((x<450)&&(y<500))
        {
    switch (indis)
    {
       case 1:{ occupy_block1(x,y); };break;
    case 2:{ occupy_block2(x,y); };break;
    case 3:{ occupy_block3(x,y); };break;
    case 4:{ occupy_block4(x,y); };break;
    case 5:{ occupy_block5(x,y); };break;
    case 6:{ occupy_block6(x,y); };break;
    case 7:{ occupy_block7(x,y); };break;
    case 8:{ occupy_block8(x,y); };break;
    case 9:{ occupy_block9(x,y); };break;
    case 10:{ occupy_block10(x,y); };break;
    case 11:{ occupy_block11(x,y); };break;
    case 12:{ occupy_block12(x,y); };break;
    case 13:{ occupy_block13(x,y); };break;
    case 14:{ occupy_block14(x,y); };break;
    case 15:{ occupy_block15(x,y); };break;
    case 16:{ occupy_block16(x,y); };break;
    case 17:{ occupy_block17(x,y); };break;
    case 18:{ occupy_block18(x,y); };break;
    case 19:{ occupy_block19(x,y); };break;
    case 20:{ occupy_block20(x,y); };break;
    case 21:{ occupy_block21(x,y); };break;
    case 22:{ occupy_block22(x,y); };break;
    case 23:{ occupy_block23(x,y); };break;
    case 24:{ occupy_block24(x,y); };break;
    case 25:{ occupy_block25(x,y); };break;
    case 26:{ occupy_block26(x,y); };break;
    case 27:{ occupy_block27(x,y); };break;
    }}}

     }

int suprimerligneetcolone()
{
    int i,j,n=0;
    for(i=0;i<10;i++)
    {
        n=0;
        for(j=0;j<10;j++)
        {
            if(tab[i][j].occupe==1 || tab[i][j].occupe==2)
            {
                n=n+1;
            }
        }
        if(n==10)
        {
            for(j=0;j<10;j++)
            {
                tab[i][j].occupe=2;
            }

        }

    }
      for(i=0;i<10;i++)
    {
        n=0;
        for(j=0;j<10;j++)
        {
            if(tab[j][i].occupe==1 || tab[j][i].occupe==2)
            {
                n=n+1;
            }
        }
        if(n==10)
        {
            for(j=0;j<10;j++)
            {
                tab[j][i].occupe=2;
            }

        }

    }

     for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(tab[i][j].occupe==2)
            {
                tab[i][j].occupe=0;
            }
        }
    }



return 0;

}


//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

int remplire_mat_machine(int couleur1,int couleur2,int color3,int position_x,int position_y)
{
    int i=(position_x-550)/40,j=(position_y-100)/40;
    mat[i][j].couleur1=couleur1;mat[i][j].couleur2=couleur2;mat[i][j].color3=color3;mat[i][j].occupe=1;mat[i][j].position_x=position_x;mat[i][j].position_y=position_y;

    return 0;
}
int occupy_block_machine1(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
    if(mat[i][j].occupe!=1)
    {
    remplire_mat_machine(100,200,50,x,y);M=M+1;
    return 0;
    }
}
int occupy_block_machine2(int x,int y)
{
int i=(x-550)/40,j=(y-100)/40;
    if((mat[i][j].occupe!=1)&&(mat[i+1][j].occupe!=1))
    {
     remplire_mat_machine(30,230,70,x,y);M=M+1;remplire_mat_machine(30,230,70,x+40,y);cpt_scor2=cpt_scor2+20;
        M=M+1;
        return 0;
    }
}
int occupy_block_machine3(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
     if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j+1].occupe==0))
    {
     remplire_mat_machine(30,255,255,x,y);M=M+1;remplire_mat_machine(30,255,255,x+40,y);M=M+1;remplire_mat_machine(30,255,255,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+30;
    }

        return 0;
}
int occupy_block_machine4(int x,int y)
{
     int i=(x-550)/40,j=(y-100)/40;
     if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0))
     {remplire_mat_machine(50,100,100,x,y);M=M+1;remplire_mat_machine(50,100,100,x+40,y);M=M+1;remplire_mat_machine(50,100,100,x+80,y);M=M+1;cpt_scor2=cpt_scor2+30;
     }
        return 0;
}
int occupy_block_machine5(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
     if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)&&(mat[i+3][j].occupe==0))
      {remplire_mat_machine(70,100,255,x,y);M=M+1;remplire_mat_machine(70,100,255,x+40,y);M=M+1;remplire_mat_machine(70,100,255,x+80,y);M=M+1;remplire_mat_machine(70,100,255,x+120,y);M=M+1;cpt_scor2=cpt_scor2+40;
      }
        return 0;
}

int occupy_block_machine6(int x,int y)
{
   int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&
                        ( mat[i+2][j].occupe==0)&&(mat[i+1][j-1].occupe==0))
        {remplire_mat_machine(100,100,100,x,y);M=M+1;remplire_mat_machine(100,100,100,x+40,y);M=M+1;remplire_mat_machine(100,100,100,x+80,y);M=M+1;remplire_mat_machine(100,100,100,x+40,y-40);M=M+1;cpt_scor2=cpt_scor2+40;
      }
        return 0;
}
int occupy_block_machine7(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
   if ((mat[i][j].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i][j+1].occupe==0)
             &&(mat[i+1][j].occupe)==0)
      {
    remplire_mat_machine(80,200,50,x,y);M=M+1;remplire_mat_machine(80,200,50,x+40,y);M=M+1;remplire_mat_machine(80,200,50,x,y+40);M=M+1;remplire_mat_machine(80,200,50,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+40;
       }
        return 0;
}
int occupy_block_machine8(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i+1][j].
                                                                   occupe==0)&&(mat[i+2][j].
                                                                               occupe==0)
        &&(mat[i+2][j+1].occupe==0)&&(mat[i+2][j+2].occupe==0))
       {remplire_mat_machine(130,70,255,x,y);M=M+1;remplire_mat_machine(130,70,255,x+40,y);M=M+1;remplire_mat_machine(130,70,255,x+80,y);M=M+1;remplire_mat_machine(130,70,255,x+80,y+40);M=M+1;remplire_mat_machine(130,70,255,x+80,y+80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;
}
int occupy_block_machine9(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j+1].occupe==0)
        &&(mat[i+1][j+2].
           occupe==0)&&(mat[i][j+2].
                       occupe==0))
    {remplire_mat_machine(200,130,70,x,y);M=M+1;remplire_mat_machine(200,130,70,x+40,y);M=M+1;remplire_mat_machine(200,130,70,x+40,y+40);M=M+1;remplire_mat_machine(200,130,70,x+40,y+80);M=M+1;remplire_mat_machine(200,130,70,x,y+80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;
}
int occupy_block_machine10(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
       if ((y>100)&&(mat[i][j].
                                               occupe==0)&&(mat[i+1][j].
                                                           occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i+1][j+1].
                                     occupe==0)&&(mat[i+2][j+1].
                                                 occupe==0)&&(mat[i][j+2].
                                                             occupe==0)  &&(mat[i+1][j+2]. occupe==0)&&(mat[i+2][j+2]. occupe==0))



           { remplire_mat_machine(255,200,50,x,y);M=M+1;remplire_mat_machine(255,200,50,x+40,y);M=M+1;remplire_mat_machine(255,200,50,x+80,y);M=M+1;remplire_mat_machine(255,200,50,x,y+40);M=M+1;remplire_mat_machine(255,200,50,x+40,y+40);M=M+1;remplire_mat_machine(255,200,50,x+80,y+40);M=M+1;remplire_mat_machine(255,200,50,x,y+80);M=M+1;remplire_mat_machine(255,200,50,x+40,y+80);M=M+1;remplire_mat_machine(255,200,50,x+80,y+80);M=M+1;cpt_scor2=cpt_scor2+90;
           }
        return 0;
}
int occupy_block_machine11(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i][j+1].occupe==0))
    {remplire_mat_machine(200,50,255,x,y);M=M+1;remplire_mat_machine(200,50,255,x,y+40);M=M+1;remplire_mat_machine(200,50,255,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+30;
    }
        return 0;
}
int occupy_block_machine12(int x,int y)
{
     int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0)&&(mat[i][j+3].
           occupe==0)&&(mat[i][j+4].occupe==0)&&(mat[i][j].occupe==0))
    { remplire_mat_machine(110,200,200,x,y);M=M+1;remplire_mat_machine(110,200,200,x,y+40);M=M+1;remplire_mat_machine(110,200,200,x,y+80);M=M+1;remplire_mat_machine(110,200,200,x,y+120);M=M+1;remplire_mat_machine(110,200,200,x,y+160);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;
}
int occupy_block_machine13(int x,int y)
{
     int i=(x-550)/40,j=(y-100)/40;
        if ((mat[i][j].
                                                occupe!=1)&&(mat[i][j+1].
                                                            occupe!=1))
        {remplire_mat_machine(100,230,70,x,y);M=M+1;remplire_mat_machine(100,230,70,x,y+40);M=M+1;cpt_scor2=cpt_scor2+20;
        }
        return 0;
}
int occupy_block_machine14(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].
                                            occupe!=1)&&
        (mat[i][j+1].
         occupe!=1)&&(mat[i+1][j].occupe==0))
        {remplire_mat_machine(30,120,200,x,y);M=M+1;remplire_mat_machine(30,120,200,x,y+40);M=M+1;remplire_mat_machine(30,120,200,x+40,y);M=M+1;cpt_scor2=cpt_scor2+30;
        }
        return 0;
}
int occupy_block_machine15(int x,int y)
{
     int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe!=1)&&(mat[i+1][j].occupe!=1)&&(mat[i+1][j-1].occupe==0))
        {remplire_mat_machine(190,200,70,x,y);M=M+1;remplire_mat_machine(190,200,70,x+40,y);M=M+1;remplire_mat_machine(190,200,70,x+40,y-40);M=M+1;cpt_scor2=cpt_scor2+30;
        }
        return 0;
}
int occupy_block_machine16(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40,k;
     if ((x<450)&&(mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0))
     {remplire_mat_machine(230,80,170,x,y);M=M+1;remplire_mat_machine(230,80,170,x,y+40);M=M+1;remplire_mat_machine(230,80,170,x,y+80);M=M+1;cpt_scor2=cpt_scor2+30;
     }
        return 0;
}

int occupy_block_machine17(int x,int y)
{
     int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i][j+1].
                    occupe==0)&&(mat[i][j+2].occupe==0)&&(mat[i][j+3].occupe==0))
    {
    remplire_mat_machine(230,200,100,x,y);M=M+1;remplire_mat_machine(230,200,100,x,y+40);M=M+1;remplire_mat_machine(230,200,100,x,y+80);M=M+1;remplire_mat_machine(230,200,100,x,y+120);M=M+1;cpt_scor2=cpt_scor2+40;
    }
        return 0;
}

int occupy_block_machine18(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].
                        occupe==0)&&(mat[i+1][j].occupe==0)&&( mat[i+2][j].
                    occupe==0)&&(mat[i+1][j+1].occupe==0))
        {remplire_mat_machine(150,160,200,x,y);M=M+1;remplire_mat_machine(150,160,200,x+40,y);M=M+1;remplire_mat_machine(150,160,200,x+80,y);M=M+1;remplire_mat_machine(150,160,200,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+40;
        }
        return 0;
}

int occupy_block_machine19(int x,int y)
{
      int i=(x-550)/40,j=(y-100)/40;
     if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j-1].occupe==0)&&(mat[i+1][j+1].occupe==0))
     {remplire_mat_machine(170,80,80,x,y);M=M+1;remplire_mat_machine(170,80,80,x+40,y);M=M+1;remplire_mat_machine(170,80,80,x+40,y-40);M=M+1;remplire_mat_machine(170,80,80,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+40;

     }
        return 0;
}
int occupy_block_machine20(int x,int y)
{
    int i=(x-550)/40,j=(y-100)/40;
     if ((mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)
         &&(mat[i][j+2].occupe==0)&&(mat[i+1][j+1].occupe==0))
     {remplire_mat_machine(80,80,170,x,y);M=M+1;remplire_mat_machine(80,80,170,x,y+40);M=M+1;remplire_mat_machine(80,80,170,x,y+80);M=M+1;remplire_mat_machine(80,80,170,x+40,y+40);M=M+1;cpt_scor2=cpt_scor2+40;
     }
        return 0;
}
int occupy_block_machine21(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40;

      if ((mat[i][j].occupe==0)&&(mat[i+1][j].
                                                                   occupe==0)&&(mat[i+2][j].
                                                                               occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0))
       {
    remplire_mat_machine(130,70,255,x,y);M=M+1;remplire_mat_machine(130,70,255,x+40,y);M=M+1;remplire_mat_machine(130,70,255,x+80,y);M=M+1;remplire_mat_machine(130,70,255,x,y+40);M=M+1;remplire_mat_machine(130,70,255,x,y+80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;
}
int occupy_block_machine22(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40;
  if ((mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0)
        &&(mat[i+1][j+2].occupe==0)&&(mat[i+2][j+2].occupe==0))
       {
         remplire_mat_machine(130,70,255,x,y);M=M+1;remplire_mat_machine(130,70,255,x,y+40);M=M+1;remplire_mat_machine(130,70,255,x,y+80);M=M+1;remplire_mat_machine(130,70,255,x+40,y+80);M=M+1;remplire_mat_machine(130,70,255,x+80,y+80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
   return 0;
}
int occupy_block_machine23(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40;
       if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i+2][j-1].occupe==0)&&(mat[i+2][j-2].occupe==0))
       {
         remplire_mat_machine(130,70,255,x,y);M=M+1;remplire_mat_machine(130,70,255,x+40,y);M=M+1;remplire_mat_machine(130,70,255,x+80,y);M=M+1;remplire_mat_machine(130,70,255,x+80,y-40);M=M+1;remplire_mat_machine(130,70,255,x+80,y-80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
    return 0;
}
int occupy_block_machine24(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40;
    if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i+2][j+1].occupe==0))
    {
     remplire_mat_machine(200,70,70,x,y);M=M+1;remplire_mat_machine(200,70,70,x+40,y);M=M+1;remplire_mat_machine(200,70,70,x+80,y);M=M+1;remplire_mat_machine(200,70,70,x,y+40);M=M+1;remplire_mat_machine(200,70,70,x+80,y+40);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;

}
int occupy_block_machine25(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40;

    if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i][j+1].occupe==0)
        &&(mat[i][j+2].
           occupe==0)&&(mat[i+1][j+2].
                       occupe==0))
    {
        remplire_mat_machine(200,70,70,x,y);M=M+1;remplire_mat_machine(200,70,70,x+40,y);M=M+1;remplire_mat_machine(200,70,70,x,y+40);M=M+1;remplire_mat_machine(200,70,70,x,y+80);M=M+1;remplire_mat_machine(200,70,70,x+40,y+80);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;

}
int occupy_block_machine26(int x, int y)
{
     int i=(x-550)/40,j=(y-100)/40,k,l;
     if ((mat[i][j].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i+2][j+1].occupe==0))
    {
    remplire_mat_machine(200,70,70,x,y);M=M+1;remplire_mat_machine(200,70,70,x+40,y+40);M=M+1;remplire_mat_machine(200,70,70,x+80,y);M=M+1;remplire_mat_machine(200,70,70,x,y+40);M=M+1;remplire_mat_machine(200,70,70,x+80,y+40);M=M+1;
    cpt_scor2=cpt_scor2+50;
    }
        return 0;


}
int occupy_block_machine27(int x, int y)
{
    int i=(x-550)/40,j=(y-100)/40;
         if ((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i+3][j].occupe==0)&&(mat[i+4][j].occupe==0))
    {
    remplire_mat_machine(200,130,70,x,y);M=M+1;remplire_mat_machine(200,130,70,x+40,y);M=M+1;remplire_mat_machine(200,130,70,x+80,y);M=M+1;remplire_mat_machine(200,130,70,x+120,y);M=M+1;remplire_mat_machine(200,130,70,x+160,y);M=M+1;cpt_scor2=cpt_scor2+50;
    }
        return 0;

}






void occupy_all_blocks_machine(int indis,int x,int y)
{

    switch (indis)
    {
       case 1:{ occupy_block_machine1(x,y); };break;
    case 2:{ occupy_block_machine2(x,y); };break;
    case 3:{ occupy_block_machine3(x,y); };break;
    case 4:{ occupy_block_machine4(x,y); };break;
    case 5:{ occupy_block_machine5(x,y); };break;
    case 6:{ occupy_block_machine6(x,y); };break;
    case 7:{ occupy_block_machine7(x,y); };break;
    case 8:{ occupy_block_machine8(x,y); };break;
    case 9:{ occupy_block_machine9(x,y); };break;
    case 10:{ occupy_block_machine10(x,y); };break;
    case 11:{ occupy_block_machine11(x,y); };break;
    case 12:{ occupy_block_machine12(x,y); };break;
    case 13:{ occupy_block_machine13(x,y); };break;
    case 14:{ occupy_block_machine14(x,y); };break;
    case 15:{ occupy_block_machine15(x,y); };break;
    case 16:{ occupy_block_machine16(x,y); };break;
    case 17:{ occupy_block_machine17(x,y); };break;
    case 18:{ occupy_block_machine18(x,y); };break;
    case 19:{ occupy_block_machine19(x,y); };break;
    case 20:{ occupy_block_machine20(x,y); };break;
    case 21:{ occupy_block_machine21(x,y); };break;
    case 22:{ occupy_block_machine22(x,y); };break;
    case 23:{ occupy_block_machine23(x,y); };break;
    case 24:{ occupy_block_machine24(x,y); };break;
    case 25:{ occupy_block_machine25(x,y); };break;
    case 26:{ occupy_block_machine26(x,y); };break;
    case 27:{ occupy_block_machine27(x,y); };break;
    }

     }

int suprimerligneetcolone_machine()
{
    int i,j,n=0;
    for(i=0;i<10;i++)
    {
        n=0;
        for(j=0;j<10;j++)
        {
            if(mat[i][j].occupe==1 || mat[i][j].occupe==2)
            {
                n=n+1;
            }
        }
        if(n==10)
        {
            for(j=0;j<10;j++)
            {
                mat[i][j].occupe=2;
            }

        }

    }
      for(i=0;i<10;i++)
    {
        n=0;
        for(j=0;j<10;j++)
        {
            if(mat[j][i].occupe==1 || mat[j][i].occupe==2)
            {
                n=n+1;
            }
        }
        if(n==10)
        {
            for(j=0;j<10;j++)
            {
                mat[j][i].occupe=2;
            }

        }

    }

     for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(mat[i][j].occupe==2)
            {
                mat[i][j].occupe=0;
            }
        }
    }



return 0;

}

//kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk


int void_place(int indis)
{
     int i,j,vide=0;
    switch(indis)
    {
    case 1:
        {
            for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
               {
                    if(mat[i][j].occupe==0)
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe!=1)&&(mat[i+1][j].occupe!=1))
                    {
                    vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j+1].occupe==0))
                        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                   if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0))
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)&&(mat[i+3][j].occupe==0))
                        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&( mat[i+2][j].occupe==0))
                        {
                            if(j>0 &&(mat[i+1][j-1].occupe==0) ){ vide=1;xvoid_place=i;yvoid_place=j;}

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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i][j+1].occupe==0)
             &&(mat[i+1][j].occupe)==0)
             {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                   if( (mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i+2][j+1].occupe==0)&&(mat[i+2][j+2].occupe==0))
                       {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j+1].occupe==0)
                      &&(mat[i+1][j+2].occupe==0)&&(mat[i][j+2].occupe==0))
                       {
                           vide=1;xvoid_place=i;yvoid_place=j;
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
                    if(  (mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
                         &&(mat[i][j+1].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i+2][j+1].
                         occupe==0)&&(mat[i][j+2].occupe==0)  &&(mat[i+1][j+2]. occupe==0)&&(mat[i+2][j+2].occupe==0))
                       {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)&&(mat[i+1][j+1].occupe==0))
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0)&&(mat[i][j+3].
           occupe==0)&&(mat[i][j+4].occupe==0)&&(mat[i][j].occupe==0))
           {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe!=1)&&(mat[i][j+1].occupe!=1))
                        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe!=1)&&(mat[i][j+1].occupe!=1)&&(mat[i+1][j].occupe==0))
                        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0))
                              {
                                  if(j>0 &&(mat[i+1][j-1].occupe==0) ){  vide=1;xvoid_place=i;yvoid_place=j; }
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
                    if((mat[i][j].occupe==0)&&(mat[i][j+1].
                    occupe==0)&&(mat[i][j+2].occupe==0))
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i][j+1].
                    occupe==0)&&(mat[i][j+2].occupe==0)&&(mat[i][j+3].occupe==0))
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)&&(mat[i+1][j+1].occupe==0) )
                    {
                       vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+1][j+1].occupe==0))
                { if(j>0 &&(mat[i+1][j-1].occupe==0)){ vide=1;xvoid_place=i;yvoid_place=j;}

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
                   if((mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)
         &&(mat[i][j+2].occupe==0)&&(mat[i+1][j+1].occupe==0))
          {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
                         &&(mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0))
        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i][j+1].occupe==0)&&(mat[i][j+2].occupe==0)
                  &&(mat[i+1][j+2].occupe==0)&&(mat[i+2][j+2].occupe==0))
        {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0))
                    {
                        if(j>1 &&(mat[i+2][j-1].occupe==0)&&(mat[i+2][j-2].occupe==0)){  vide=1;xvoid_place=i;yvoid_place=j;}

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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i+2][j+1].occupe==0))
                    {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i][j+1].occupe==0)
        &&(mat[i][j+2].occupe==0)&&(mat[i+1][j+2].occupe==0))
                       {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j+1].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i][j+1].occupe==0)&&(mat[i+2][j+1].occupe==0))
                   {
                        vide=1;xvoid_place=i;yvoid_place=j;
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
                    if((mat[i][j].occupe==0)&&(mat[i+1][j].occupe==0)&&(mat[i+2][j].occupe==0)
        &&(mat[i+3][j].occupe==0)&&(mat[i+4][j].occupe==0))
                   {
                        vide=1;xvoid_place=i;yvoid_place=j;
                    }
               }
        }
        }break;


    }
return (vide);

}




void texte()
{
    TTF_Font *police=NULL;
     SDL_Rect pos,pos2;
         SDL_Surface *text=NULL,*text2=NULL,*textmachine=NULL,*textmachine2=NULL;
         SDL_Color noire={0,0,0};
         char scor[20]="";
         char high_scor[20]="";
         char scor2[20]="";
         char high_scor2[20]="";


        TTF_Init();
        police=TTF_OpenFont("minipixel.ttf",28);
        if (bestscor<=cpt_scor){bestscor=cpt_scor;}
        if (bestscor2<=cpt_scor2){bestscor2=cpt_scor2;}

        sprintf(scor2,"SCORE: %d ",cpt_scor2);
        sprintf(high_scor2,"HIGH SCORE: %d ",bestscor2);
        sprintf(scor,"SCORE: %d ",cpt_scor);
        sprintf(high_scor,"HIGH SCORE: %d ",bestscor);
        text= TTF_RenderText_Blended(police,scor, noire);
        text2= TTF_RenderText_Blended(police,high_scor, noire);
        textmachine= TTF_RenderText_Blended(police,scor2, noire);
        textmachine2= TTF_RenderText_Blended(police,high_scor2, noire);
        pos.x=50;
        pos.y=70;
        SDL_BlitSurface(text, NULL, ecran, &pos); /* Blit du texte */
        pos.x=250;
        pos.y=70;
        SDL_BlitSurface(text2, NULL, ecran, &pos); /* Blit du texte */
        pos2.x=550;
        pos2.y=70;
        SDL_BlitSurface(textmachine, NULL, ecran, &pos2); /* Blit du texte */
        pos2.x=750;
        pos2.y=70;
        SDL_BlitSurface(textmachine2, NULL, ecran, &pos2); /* Blit du texte */
         TTF_CloseFont(police);
        TTF_Quit();
            SDL_FreeSurface(text);


}



