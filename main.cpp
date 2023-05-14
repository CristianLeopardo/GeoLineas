#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;
const char * arial="arial.ttf";
const char * arkanoid="Arka_solid.ttf";
//#include "SDL/SDL.h"
//#include "SDL/SDL_image.h"
//#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "include/juego.h"
#include "include/usuario.h"
#include "include/graficos.h"
#include "include/figuras.h"
#include "include/grilla.h"
int menu();
bool leerPuntaje(Usuario * aux[5]);
bool comoJugar(SDL_Surface *screen);
bool continuarPartida(SDL_Surface *screen);
void muestraPuntajes(SDL_Surface *screen);
void correJuego(SDL_Surface *screen,int _nivel=1);
void grabarUsuario(int _puntaje,char * _nombre,int _nivel);
/*-lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf*/


int main(int argc, char *argv[])
{
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        exit(0);
    }
menu();
return 0;
}

bool comoJugar(SDL_Surface *screen)
{
    bool salir=true;
    SDL_Surface* menucj = NULL;
    SDL_Surface* volver = NULL;
    SDL_Surface* volver2 = NULL;
    SDL_Surface* leyenda = NULL;
    menucj= SDL_LoadBMP("menucj.bmp");
    volver= SDL_LoadBMP("volv.bmp");
    volver2= SDL_LoadBMP("volv2.bmp");
    leyenda= SDL_LoadBMP("leyenda.bmp");
    Uint32 colorkey = SDL_MapRGB( volver->format, 0, 0, 0);
    Uint32 colorkey6 = SDL_MapRGB( volver2->format, 0, 0, 0);
    Uint32 colorkey1 = SDL_MapRGB( leyenda->format, 0, 0, 0);
    SDL_SetColorKey( volver, SDL_SRCCOLORKEY, colorkey );
    SDL_SetColorKey( volver2, SDL_SRCCOLORKEY, colorkey6 );
    SDL_SetColorKey( leyenda, SDL_SRCCOLORKEY, colorkey1 );
    SDL_Rect ley;
    ley.x=120;
    ley.y=205;
    SDL_Rect volv;
    volv.x = 415;
    volv.y = 765;
    volv.w = 745;
    volv.h = 815;
    int x,y;
    SDL_Event evento;
    while(salir==true){
            SDL_BlitSurface(menucj,NULL,screen,NULL);
            SDL_BlitSurface(leyenda,NULL,screen,&ley);
        if (SDL_PollEvent (&evento)){
                if(evento.key.keysym.sym==SDLK_ESCAPE){salir = false;}
            if (evento.type== SDL_MOUSEBUTTONDOWN){
                        if(evento.button.button==1)
                        if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h){salir=false;}
            }
            if (evento.type== SDL_MOUSEMOTION)
                        {
                            x= evento.motion.x;
                            y= evento.motion.y;
                            if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h)
                            {
                                SDL_BlitSurface(volver2,NULL,screen,&volv);
                            }
                            else
                            {
                            }

                        }
            SDL_BlitSurface(volver,NULL,screen,&volv);
            SDL_Flip (screen);
        }
        SDL_BlitSurface(volver,NULL,screen,&volv);
        SDL_Flip (screen);

    }
}
bool leerPuntaje(Usuario * aux){
    Usuario obj;
    bool lee=false;
    int pos;
    pos=0;
    while(obj.leer_de_Disco(pos++)){
        aux[pos].setNombre(obj.getNombre());
        aux[pos].setPuntaje(obj.getPuntaje());
        lee=true;
        freopen ("pos.txt","ab",stdout);
        printf ("%d ",pos);
        fclose (stdout);
    }
    return lee;
}
void grabarPuntaje(int _puntaje,char * _nombre,int _nivel){
    Usuario obj;
    obj.setNombre(_nombre);
    obj.setPuntaje(_puntaje);
    obj.setNivel(_nivel);
    obj.grabar_en_Disco();
}
void grabarUsuario(int _puntaje,char * _nombre,int _nivel){
    Usuario objU1;
    objU1.setPuntaje(_puntaje);
    objU1.setNombre(_nombre);
    objU1.setNivel(_nivel);
    objU1.grabar_en_Disco();
}
void corriendo(SDL_Surface *screen,int _nivel,int puj){
    int clic = 0,_vuelta=1,ini=0,celda_anterior=-2,ra;
    char a[10],l[10],j[5];
    bool testvar;
    bool musica = true;
    char testvar2[5];
    int testvar3;
    Textos objT;
    bool mouseLiberado = true,gano=true;
    int aux,aux2,x1,x2,y1,y2,ax,ay,h=0,p=0,mouseX=0,mouseY,posY=0,posX=0;
    SDL_Rect rectangulo2;
    SDL_Rect trect;
    rectangulo2.x = 0;
    rectangulo2.y = 0;
    SDL_Rect rect3;
    rect3.x=0;
    rect3.y=0;
    SDL_Rect grillaxy;
    grillaxy.x = 75;
    grillaxy.y = 75;
    SDL_Surface* fondo = NULL;
    SDL_Surface* click = NULL;
    SDL_Surface* cuadricula = NULL;
    Mix_Music *music = NULL;
    Mix_Chunk *jaja = NULL;
    Mix_Chunk *win = NULL;
    Mix_Chunk *bonus = NULL;
    fondo = IMG_Load("mathsign2.jpg");
    click = SDL_LoadBMP ("click.bmp");
    cuadricula = SDL_LoadBMP ("grilla.bmp");
    bonus = Mix_LoadWAV( "sounds/bono.wav" );
    jaja = Mix_LoadWAV ("sounds/jaja.wav");
    win = Mix_LoadWAV ("sounds/applause1.wav");
    SDL_SetColorKey(cuadricula, SDL_SRCCOLORKEY, SDL_MapRGB(cuadricula->format, 0,0,0));
    SDL_SetColorKey(click, SDL_SRCCOLORKEY, SDL_MapRGB(click->format, 0,0,0));
    grilla obj;
    SDL_Event evento;
    obj.setPuntaje(0);
    obj.setPuntajeTotal(puj);
    srand ( time(NULL) );
    if (bonus==NULL)
    {
        exit(0);
    }
    ra= rand()%5;
    switch (ra)
    {
        case 0: music = Mix_LoadMUS( "sounds/music.wav" );
                break;
        case 1: music = Mix_LoadMUS( "sounds/music2.wav" );
                break;
        case 2: music = Mix_LoadMUS( "sounds/music3.wav" );
                break;
        case 3: music = Mix_LoadMUS( "sounds/music4.wav" );
                break;
        case 4: music = Mix_LoadMUS( "sounds/music5.wav" );
                break;
    }
    obj.inicializarSonidos();
    switch (_nivel)
    {
        case 0 : obj.setNivel1();obj.setPuntajeMaximo(3000); break;
        case 1 : obj.setNivel2();obj.setPuntajeMaximo(2500); break;
        case 2 : obj.setNivel3();obj.setPuntajeMaximo(5000); break;
        case 3 : obj.setNivel4();obj.setPuntajeMaximo(7500); break;
        case 4: obj.setNivel(0); obj.setNivel1();obj.setPuntajeMaximo(3000); break;
        }
    SDL_GetError();
    if( music == NULL )
    {
        exit (0);
    }
    Mix_PlayMusic( music, -1 );
    while(gano==true)
        {
            if (SDL_PollEvent (&evento))
            {
                if(evento.type==SDL_KEYDOWN)
                {
                    if(evento.key.keysym.sym==SDLK_ESCAPE)
                    {
                        SDL_FreeSurface(screen);
                        menu();
                    }
                }

                if(evento.key.keysym.sym==SDLK_m){
                        if(Mix_PausedMusic()){
                            Mix_ResumeMusic();
                        }else{
                            Mix_PauseMusic();

                        }
                    }

                if (evento.type== SDL_MOUSEBUTTONDOWN)
                {
                    if (mouseLiberado)
                    {
                        if ((evento.button.button == 1)&&(evento.button.x>=75)&&(evento.button.y>=75)&&(evento.button.x<826)&&(evento.button.y<826) )
                        {
                            ax=evento.button.x/75;
                            ay=evento.button.y/75;
                            mouseLiberado = false;
                            if(clic==0)
                            {
                                celda_anterior=obj.getCeldaId(ay-1,ax-1);
                            }
                            aux = evento.button.x;
                            aux = aux /75;
                            if (clic == 1)
                            {
                                x1 = aux;
                            }
                            else
                            {
                                x2 = aux;
                            }
                            aux = aux*75;
                            aux2 = evento.button.y;
                            aux2 = aux2 /75;
                            if (clic == 1)
                            {
                                y1 = aux2;
                            }
                            else
                            {
                                y2 = aux2;
                            }
                            aux2 = aux2*75;
                            rectangulo2.x = aux ;
                            rectangulo2.y = aux2 ;
                            SDL_BlitSurface(click,NULL ,screen,&rectangulo2);
                            if(obj.BuscarBloque(ay,ax))
                            {
                                clic=-1;
                            }
                            else
                            {
                                if (clic == 1)
                                {
                                    if(obj.BuscarBloque(ay,ax))
                                    {
                                        clic=0;
                                    }
                                    else
                                    {
                                        if((obj.getCeldaId(ay-1,ax-1) != celda_anterior)&&(!obj.BuscarBloque(ay,ax)))
                                        {
                                            if (obj.Intercambiar(x1,y1,x2,y2)==true)
                                                {
                                                    obj.RestarMovimientos();
                                                    rect3.x=rectangulo2.x;
                                                    rect3.y=rectangulo2.y;
                                                }
                                            SDL_BlitSurface(fondo,NULL,screen,NULL);
                                            obj.MostrarMatriz(screen);
                                            clic =0;
                                        }
                                    }
                                }
                                else
                                {
                                    if(clic==0)clic = 1;
                                    if(clic==-1)clic=0;
                                }
                            }
                        }
                    }
                }
                if (evento.type== SDL_MOUSEBUTTONUP)
                {
                    mouseLiberado = true;
                }
            }


        SDL_BlitSurface(fondo,NULL,screen,NULL);
        SDL_BlitSurface(cuadricula,NULL,screen,&grillaxy);
        obj.MostrarMatriz(screen);
        if ((rect3.x!=rectangulo2.x)||(rect3.y!=rectangulo2.y))
        {
           SDL_BlitSurface(click,NULL ,screen,&rectangulo2);
        }
        _vuelta+=obj.BuscarCoincidencias(_vuelta);

        if((_vuelta==5)&&(p==0)){
           if(obj.getNivel()==3){
            objT.setTamanio(60);
            objT.setColor(3);
            objT.setFuente(arial);
            objT.setTexto("Bonus x3");
            objT.dibujarTexto(screen,200,400);
            SDL_Flip (screen);
            Mix_PlayChannel( -1, bonus, 0 );
            SDL_Delay(500);
            obj.setMultiplicador(3);
           }else{
            objT.setTamanio(60);
            objT.setColor(6);
            objT.setFuente(arial);
            objT.setTexto("Bonus x2");
            objT.dibujarTexto(screen,200,400);
            SDL_Flip (screen);
            Mix_PlayChannel( -1, bonus, 0 );
            SDL_Delay(500);
            obj.setMultiplicador(2);
           }
            p++;
            }
        if(_vuelta==10){
            _vuelta++;
            objT.setTamanio(60);
            objT.setColor(7);
            objT.setFuente(arial);
            objT.setTexto("Movimientos +3");
            objT.dibujarTexto(screen,200,400);
            SDL_Flip (screen);
            Mix_PlayChannel( -1, bonus, 0 );
            SDL_Delay(500);
            obj.incrementarMovimientos(3);
        }
        if(_vuelta>=20){
            _vuelta=-5;
            objT.setTamanio(60);
            objT.setColor(2);
            objT.setFuente(arial);
            objT.setTexto("Bonus x1");
            objT.dibujarTexto(screen,200,400);
            SDL_Flip (screen);
            Mix_PlayChannel( -1, bonus, 0 );
            SDL_Delay(500);
            obj.setMultiplicador(1);
            p=0;

        }
        obj.SubirNumeros();
        objT.setTamanio(40);
        objT.setColor(7);
        objT.setFuente(arial);
        objT.setTexto(itoa(obj.getPuntaje(), a, 10));
        objT.dibujarTexto(screen,850,150);
        objT.setTamanio(40);
        objT.setColor(7);
        objT.setFuente(arial);
        objT.setTexto(itoa(obj.getMovimientos(), l, 10));
        objT.dibujarTexto(screen,850,280);
        objT.setTamanio(40);
        objT.setColor(7);
        objT.setFuente(arial);
        objT.setTexto(itoa(obj.getPuntajeMaximo(), l, 10));
        objT.dibujarTexto(screen,850,360);objT.setTamanio(40);
        objT.setColor(7);
        objT.setFuente(arial);
        objT.setTexto(itoa(obj.getPuntaje()+ obj.getPuntajeTotal() , l, 10));
        objT.dibujarTexto(screen,850,450);


        SDL_Flip (screen);
        if(obj.getMovimientos()<=0)
        {
            gano=false;

        }

        SDL_Delay(90);
    }
        if (obj.getPuntaje()>=obj.getPuntajeMaximo())
        {
            obj.setPuntajeTotalSUM(obj.getPuntaje());
            h= _nivel +1;
            obj.setNivel(h);
            switch(h){
            case 1:
                SDL_BlitSurface(fondo,NULL,screen,NULL);
                objT.pantallaNivel(screen,_nivel);
                SDL_Flip(screen);
                SDL_Delay(2000);
                Mix_FreeMusic(music);
                corriendo(screen,obj.getNivel(),obj.getPuntajeTotal());
                break;
            case 2:
                SDL_BlitSurface(fondo,NULL,screen,NULL);
                objT.pantallaNivel(screen,_nivel);
                SDL_Flip(screen);
                SDL_Delay(2000);
                Mix_FreeMusic(music);
                corriendo(screen,obj.getNivel(),obj.getPuntajeTotal());
                break;
            case 3:
                    SDL_BlitSurface(fondo,NULL,screen,NULL);
                objT.pantallaNivel(screen,_nivel);
                SDL_Flip(screen);
                SDL_Delay(2000);
                Mix_FreeMusic(music);
                corriendo(screen,obj.getNivel(),obj.getPuntajeTotal());
                break;
            case 4:
                SDL_BlitSurface(fondo,NULL,screen,NULL);
                objT.setColor(5);
                objT.setTamanio(125);
                objT.setFuente(arkanoid);
                objT.setTexto("GANASTE CAPO ");
                objT.dibujarTexto(screen,0,450);
                objT.setColor(7);
                objT.setTamanio(110);
                objT.setFuente(arial);
                objT.setTexto("           ");
                objT.dibujarTexto(screen,100,95);
                SDL_Flip(screen);
                Mix_PlayChannel( -1, win, 0 );
                SDL_Delay(8000);
                 corriendo(screen,obj.getNivel(),0);
                Mix_FreeMusic(music);
                break;
            default: break;

            }
        }else{
                SDL_BlitSurface(fondo,NULL,screen,NULL);
                objT.setColor(5);
                objT.setTamanio(125);
                objT.setFuente(arkanoid);
                objT.setTexto("PERDISTE ");
                objT.dibujarTexto(screen,0,450);
                SDL_Flip(screen);
                SDL_Delay(2000);
                objT.pantallaNivel(screen,_nivel-1);
                SDL_Flip(screen);
                SDL_Delay(2000);
                Mix_FreeMusic(music);
                corriendo(screen,_nivel,0);
        }


}
void correJuego(SDL_Surface *screen,int _nivel,int a){
   corriendo(screen,_nivel,a);
}
void muestraPuntajes(SDL_Surface *screen){
    Usuario aux[5];
    bool salir=true;
    char nombre[30];
    char puntos[7];
    Textos objTexto;
    SDL_Surface* menucj = NULL;
    SDL_Surface* volver = NULL;
    SDL_Surface* volver2 = NULL;
    SDL_Surface* leyenda = NULL;
    menucj= SDL_LoadBMP("menucj.bmp");
    volver= SDL_LoadBMP("volv.bmp");
    volver2= SDL_LoadBMP("volv2.bmp");
    Uint32 colorkey = SDL_MapRGB( volver->format, 0, 0, 0);
    Uint32 colorkey6 = SDL_MapRGB( volver2->format, 0, 0, 0);
    SDL_SetColorKey( volver, SDL_SRCCOLORKEY, colorkey );
    SDL_SetColorKey( volver2, SDL_SRCCOLORKEY, colorkey6 );
    SDL_Rect ley;
    ley.x=120;
    ley.y=205;
    SDL_Rect volv;
    volv.x = 415;
    volv.y = 765;
    volv.w = 745;
    volv.h = 815;
    int x,y;
    SDL_Event evento;
    while(salir==true){
        SDL_BlitSurface(menucj,NULL,screen,NULL);
        objTexto.setColor(6);
        objTexto.setTamanio(35);
        objTexto.setFuente(arial);
        objTexto.setTexto("Puntajes");
        objTexto.dibujarTexto(screen,420,250);
        if (SDL_PollEvent (&evento)){
            if (evento.type== SDL_MOUSEBUTTONDOWN){
                    if(evento.button.button==1){
                        if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h){
                            salir=false;
                        }
                    }
            }
            if (evento.type== SDL_MOUSEMOTION)
                        {
                            x= evento.motion.x;
                            y= evento.motion.y;
                            if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h)
                            {
                                SDL_BlitSurface(volver2,NULL,screen,&volv);
                            }
                            else
                            {
                            }

                        }
            SDL_BlitSurface(volver,NULL,screen,&volv);
            SDL_Flip (screen);
        }
    }
}
bool continuarPartida(SDL_Surface *screen){
    bool salir=true;
    SDL_Surface* login = NULL;
    SDL_Surface* volver = NULL;
    SDL_Surface* volver2 = NULL;
    login= SDL_LoadBMP("login.bmp");
    volver= SDL_LoadBMP("volv.bmp");
    volver2= SDL_LoadBMP("volv2.bmp");
    Uint32 colorkey = SDL_MapRGB( volver->format, 0, 0, 0);
    Uint32 colorkey6 = SDL_MapRGB( volver2->format, 0, 0, 0);
    SDL_SetColorKey( volver, SDL_SRCCOLORKEY, colorkey );
    SDL_SetColorKey( volver2, SDL_SRCCOLORKEY, colorkey6 );
    SDL_Rect volv;
    volv.x = 415;
    volv.y = 765;
    volv.w = 745;
    volv.h = 815;
    int x,y;
    SDL_Event evento;
    while(salir==true){
            SDL_BlitSurface(login,NULL,screen,NULL);
        if (SDL_PollEvent (&evento)){
                if(evento.key.keysym.sym==SDLK_ESCAPE)
                    {
                        salir = false;
                    }
            if (evento.type== SDL_MOUSEBUTTONDOWN){
                        if(evento.button.button==1)
                        if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h){salir = false;}
            }
            if (evento.type== SDL_MOUSEMOTION)
                        {
                            x= evento.motion.x;
                            y= evento.motion.y;
                            if(x>volv.x&&x<volv.x+volv.w&&y>volv.y&&y<volv.y+volv.h)
                            {
                                SDL_BlitSurface(volver2,NULL,screen,&volv);
                            }
                            else
                            {
                            }

                        }
            SDL_BlitSurface(volver,NULL,screen,&volv);
            SDL_Flip (screen);
        }
        SDL_BlitSurface(volver,NULL,screen,&volv);
        SDL_Flip (screen);
    }
}
int menu(){

    bool mouseLiberado = true;
    bool gano=false ;
    int x,y;
    Juego obj;
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        return 0;
    }
    if( TTF_Init() == -1 ) { return 0; }
    SDL_WM_SetCaption("GeoLineas v1.0",NULL);
    SDL_Surface* screen = NULL;
    SDL_Surface* menu = NULL;
    SDL_Surface* nuevoj=NULL;
    SDL_Surface* nuevoj2=NULL;
    SDL_Surface* conti=NULL;
    SDL_Surface* conti2=NULL;
    SDL_Surface* punt=NULL;
    SDL_Surface* punt2=NULL;
    SDL_Surface* salir=NULL;
    SDL_Surface* salir2=NULL;
    SDL_Surface* comj=NULL;
    SDL_Surface* comj2=NULL;
    menu= SDL_LoadBMP("menu.bmp");
    conti= SDL_LoadBMP("cont.bmp");
    conti2= SDL_LoadBMP("cont2.bmp");
    punt= SDL_LoadBMP("punt.bmp");
    punt2= SDL_LoadBMP("punt2.bmp");
    salir= SDL_LoadBMP("sal.bmp");
    salir2= SDL_LoadBMP("sal2.bmp");
    comj= SDL_LoadBMP("cjugar.bmp");
    comj2= SDL_LoadBMP("cjugar2.bmp");
    nuevoj= SDL_LoadBMP("jn.bmp");
    nuevoj2= SDL_LoadBMP("jn2.bmp");
    screen = SDL_SetVideoMode( 1125, 900, 32,SDL_SWSURFACE| SDL_DOUBLEBUF);//SDL_FULLSCREEN);//SDL_SWSURFACE | SDL_RESIZABLE);
    Uint32 colorkey = SDL_MapRGB( nuevoj->format, 0, 0, 0);
    Uint32 colorkey6 = SDL_MapRGB( nuevoj2->format, 0, 0, 0);
    SDL_SetColorKey( nuevoj, SDL_SRCCOLORKEY, colorkey );
    SDL_SetColorKey( nuevoj2, SDL_SRCCOLORKEY, colorkey6 );
    Uint32 colorkey2 = SDL_MapRGB( conti->format, 0, 0, 0);
    Uint32 colorkey7 = SDL_MapRGB( conti2->format, 0, 0, 0);
    SDL_SetColorKey( conti, SDL_SRCCOLORKEY, colorkey2 );
    SDL_SetColorKey( conti2, SDL_SRCCOLORKEY, colorkey7 );
    Uint32 colorkey3 = SDL_MapRGB( comj->format, 0, 0, 0);
    Uint32 colorkey9 = SDL_MapRGB( comj2->format, 0, 0, 0);
    SDL_SetColorKey( comj, SDL_SRCCOLORKEY, colorkey3 );
    SDL_SetColorKey( comj2, SDL_SRCCOLORKEY, colorkey9 );
    Uint32 colorkey4 = SDL_MapRGB( salir->format, 0, 0, 0);
    Uint32 colorkey10 = SDL_MapRGB( salir2->format, 0, 0, 0);
    SDL_SetColorKey( salir, SDL_SRCCOLORKEY, colorkey4 );
    SDL_SetColorKey( salir2, SDL_SRCCOLORKEY, colorkey10 );
    Uint32 colorkey5 = SDL_MapRGB( punt->format, 0, 0, 0);
    Uint32 colorkey8 = SDL_MapRGB( punt2->format, 0, 0, 0);
    SDL_SetColorKey( punt, SDL_SRCCOLORKEY, colorkey5 );
    SDL_SetColorKey( punt2, SDL_SRCCOLORKEY, colorkey8 );
    if( screen == NULL ) { exit(0); } //Initialize SDL_ttf

    SDL_Rect jn;
    jn.x=320;
    jn.y=200;
    jn.w=790;
    jn.h=260;

    SDL_Rect cont;
    cont.x=320;
    cont.y=320;
    cont.w=790;
    cont.h=380;

    SDL_Rect mp;
    mp.x=320;
    mp.y=445;
    mp.w=790;
    mp.h=505;

    SDL_Rect cj;
    cj.x=320;
    cj.y=575;
    cj.w=790;
    cj.h=635;

    SDL_Rect sa;
    sa.x=320;
    sa.y=705;
    sa.w=790;
    sa.h=760;


    SDL_Event evento;
    obj.setNivel(0);
    Mix_Chunk *inicio = NULL;
    Mix_Chunk *gong = NULL;
    Mix_Music *sonidomenu = NULL;
    sonidomenu = Mix_LoadMUS("sounds/sonidomenu.wav");
    inicio = Mix_LoadWAV ("sounds/Effect28.wav");
    gong = Mix_LoadWAV ("sounds/gong.wav");
    if (sonidomenu == NULL)
    {
        exit(0);
    }
    Mix_PlayChannel( -1,inicio, 0 );
    Mix_PlayMusic( sonidomenu, -1 );
    while(gano!=true){
        if (SDL_PollEvent (&evento))
        {   if(evento.type==SDL_KEYDOWN){
                if(evento.key.keysym.sym==SDLK_ESCAPE){
                   SDL_Quit();exit(0);
                }
            }

            if (evento.type== SDL_MOUSEBUTTONDOWN){
                if(evento.button.button==1)
                if(x>sa.x&&x<sa.x+sa.w&&y>sa.y&&y<sa.y+sa.h){ SDL_Quit();exit(0);}
                if (x>cj.x&&x<cj.x+cj.w&&y>cj.y&&y<cj.y+cj.h)
                {
                    comoJugar(screen);
                }
                if(x>jn.x&&x<jn.x+jn.w&&y>jn.y&&y<jn.y+jn.h){
                    correJuego(screen,obj.getNivel(),0);
                }
                if(x>cont.x&&x<cont.x+cont.w&&y>cont.y&&y<cont.y+cont.h){
                    continuarPartida(screen);
                }
                if(x>mp.x&&x<mp.x+mp.w&&y>mp.y&&y<mp.y+mp.h){
                    muestraPuntajes(screen);
                }
            }

            SDL_BlitSurface(menu,NULL,screen,NULL);
            if (evento.type== SDL_MOUSEMOTION)
            {
                x= evento.motion.x;
                y= evento.motion.y;
                if (x>jn.x&&x<jn.x+jn.w&&y>jn.y&&y<jn.y+jn.h)
                {
                    SDL_BlitSurface(nuevoj2, NULL, screen, &jn);
                }
                if (x>cont.x&&x<cont.x+cont.w&&y>cont.y&&y<cont.y+cont.h)
                {
                    SDL_BlitSurface(conti2, NULL, screen, &cont);
                }
                if (x>mp.x&&x<mp.x+mp.w&&y>mp.y&&y<mp.y+mp.h)
                {
                    SDL_BlitSurface(punt2, NULL, screen, &mp);
                }
                if (x>cj.x&&x<cj.x+cj.w&&y>cj.y&&y<cj.y+cj.h)
                {
                    SDL_BlitSurface(comj2, NULL, screen, &cj);
                }
                if (x>sa.x&&x<sa.x+sa.w&&y>sa.y&&y<sa.y+sa.h)
                {
                    SDL_BlitSurface(salir2, NULL, screen, &sa);
                }
            }
        }
        SDL_BlitSurface(nuevoj, NULL, screen, &jn);
        SDL_BlitSurface(conti, NULL, screen, &cont);
        SDL_BlitSurface(punt, NULL, screen, &mp);
        SDL_BlitSurface(comj, NULL, screen, &cj);
        SDL_BlitSurface(salir, NULL, screen, &sa);
        SDL_Flip (screen);
    }
    return 0;
}
