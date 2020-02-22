#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonction.c"
#include "partie1.c"
#include "partie1.h"
#include "partie2.c"
#include "partie2.h"
#include<SDL/SDL_ttf.h>



int main(int argc, char *argv[])
{

    SDL_Surface *ecran=NULL ,*menu=NULL;
    SDL_Rect position_menu,position_clic;
    SDL_Event event;
    int continuer=1;


    putenv("SDL_VIDEO_CENTRED=1");//ont centre la fenetre
     SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
 //SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
 ecran=SDL_SetVideoMode(1000, 680, 32, SDL_HWSURFACE);
 if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
{
  fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
  exit(EXIT_FAILURE);

}
SDL_WM_SetCaption("bismillah SUPER GAME!!", NULL);
menu=SDL_LoadBMP("MENU.bmp");
position_menu.x=0;
position_menu.y=0;


while(continuer)
{
    SDL_WaitEvent(&event);
  switch(event.type)
  {
  case SDL_QUIT:
   continuer = 0;
   break;
  case SDL_MOUSEBUTTONUP:
    if(event.button.button==SDL_BUTTON_LEFT)
    {
        position_clic.x=event.button.x;//on recupere les coordonnées de la souris
        position_clic.y = event.button.y;

        if (event.button.x < 717 && event.button.x > 308 && event.button.y < 150 && event.button.y > 114 )
        {
            //jouer_introduction(ecran);
        }
        else if (event.button.x < 620 && event.button.x > 308 && event.button.y < 210 && event.button.y > 174 )
        {
           jouer_partie1(ecran)   ;
        }
        else if (event.button.x < 654 && event.button.x > 308 && event.button.y < 270 && event.button.y > 232 )
        {
            jouer_partie2(ecran);
        }
        else if (event.button.x < 684 && event.button.x > 308 && event.button.y < 330 && event.button.y > 292 )
        {
            //jouer_partie3(ecran);
        }
    }
    break;


  }
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
SDL_BlitSurface(menu,NULL,ecran,&position_menu);
SDL_Flip(ecran);


}

SDL_FreeSurface(menu);
 SDL_FreeSurface(ecran);
 SDL_Quit(); // Arrêt de la SDL

return EXIT_SUCCESS;
}
