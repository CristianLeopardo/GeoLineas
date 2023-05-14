#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED
#include <cstring>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
class Triangulo
{
public:
   Triangulo (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int i, int x, int y,int flip = 1);
   // CONSTRUCTORES

   // DESTRUCTOR
   ~Triangulo();

private:
    SDL_Surface *triangulo;
    int columnas;
    int filas;
    int w,h;
    Uint32 colorkey;
};

Triangulo::Triangulo(Uint32 r,Uint32 g,Uint32 b)
{
    triangulo= SDL_LoadBMP ("sprite3.bmp");
    if(triangulo == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = triangulo;
    triangulo = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(triangulo == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(triangulo->format, r, g, b);
    SDL_SetColorKey(triangulo, SDL_SRCCOLORKEY, colorkey);
}

void Triangulo::dibujar(SDL_Surface *superficie, int i, int x, int y, int flip)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(triangulo, NULL, superficie, &destino);
}

Triangulo::~Triangulo()
{
    SDL_FreeSurface(triangulo);
}


/********************************************************************************************/
class Cuadrado
{
public:
   Cuadrado (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int x, int y);
   // DESTRUCTOR
   ~Cuadrado();
private:
    SDL_Surface *cuadrado;
    Uint32 colorkey;
};

Cuadrado::Cuadrado(Uint32 r,Uint32 g,Uint32 b)
{
    cuadrado= SDL_LoadBMP ("sprite1.bmp");
    if(cuadrado == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = cuadrado;
    cuadrado = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(cuadrado == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(cuadrado->format, r, g, b);
    SDL_SetColorKey(cuadrado, SDL_SRCCOLORKEY, colorkey);
}

void Cuadrado::dibujar(SDL_Surface *superficie, int x, int y)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(cuadrado, NULL, superficie, &destino);
}

Cuadrado::~Cuadrado()
{
    SDL_FreeSurface(cuadrado);
}

/********************************************************************************************/
class Rombo
{
public:
   Rombo (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int x, int y);
   // DESTRUCTOR
   ~Rombo();
private:
    SDL_Surface *rombo;
    Uint32 colorkey;
};

Rombo::Rombo(Uint32 r,Uint32 g,Uint32 b)
{
    rombo= SDL_LoadBMP("sprite4.bmp");
    if(rombo == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = rombo;
    rombo = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(rombo == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(rombo->format, r, g, b);
    SDL_SetColorKey(rombo, SDL_SRCCOLORKEY, colorkey);
}

void Rombo::dibujar(SDL_Surface *superficie, int x, int y)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(rombo, NULL, superficie, &destino);
}

Rombo::~Rombo()
{
    SDL_FreeSurface(rombo);
}

/********************************************************************************************/

class Circulo
{
public:
   Circulo (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int x, int y);
   // DESTRUCTOR
   ~Circulo();
private:
    SDL_Surface *circulo;
    Uint32 colorkey;
};

Circulo::Circulo(Uint32 r,Uint32 g,Uint32 b)
{
    circulo= SDL_LoadBMP("sprite2.bmp");
    if(circulo == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = circulo;
    circulo = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(circulo == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(circulo->format, r, g, b);
    SDL_SetColorKey(circulo, SDL_SRCCOLORKEY, colorkey);
}

void Circulo::dibujar(SDL_Surface *superficie, int x, int y)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(circulo, NULL, superficie, &destino);
}

Circulo::~Circulo()
{
    SDL_FreeSurface(circulo);
}

/********************************************************************************************/
class Vacio
{
public:
   Vacio (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int x, int y);
   // DESTRUCTOR
   ~Vacio();
private:
    SDL_Surface *vacio;
    Uint32 colorkey;
};

Vacio::Vacio(Uint32 r,Uint32 g,Uint32 b)
{
    vacio= SDL_LoadBMP("sprite5.bmp");
    if(vacio == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = vacio;
    vacio = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(vacio == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(vacio->format, r, g, b);
    SDL_SetColorKey(vacio, SDL_SRCCOLORKEY, colorkey);
}

void Vacio::dibujar(SDL_Surface *superficie, int x, int y)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(vacio, NULL, superficie, &destino);
}

Vacio::~Vacio()
{
    SDL_FreeSurface(vacio);
}

/********************************************************************************************/
class Bloque
{
public:
   Bloque (Uint32 r=0, Uint32 g=0, Uint32 b=0);
   void dibujar(SDL_Surface *superficie, int x, int y);
   // DESTRUCTOR
   ~Bloque();
private:
    SDL_Surface *bloque;
    Uint32 colorkey;
};

Bloque::Bloque(Uint32 r,Uint32 g,Uint32 b)
{
    bloque= IMG_Load("sprite5.bmp");
    if(bloque == NULL) {
    exit(1);
    }
    SDL_Surface *tmp = bloque;
    bloque = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    if(bloque == NULL) {
    exit(1);
    }
    colorkey = SDL_MapRGB(bloque->format, r, g, b);
    SDL_SetColorKey(bloque, SDL_SRCCOLORKEY, colorkey);
}

void Bloque::dibujar(SDL_Surface *superficie, int x, int y)
{
    SDL_Rect destino;
    destino.x = x;
    destino.y = y;
    SDL_BlitSurface(bloque, NULL, superficie, &destino);
}

Bloque::~Bloque()
{
    SDL_FreeSurface(bloque);
}

/********************************************************************************************************/

class Textos{
private:
    SDL_Surface *stexto;
    char tfuente[30],texto[255];
    int tam,color;
    SDL_Color textColor;
    SDL_Rect trect;
    TTF_Font *fuente;
public:
        Textos(int,int,char *);
void    setTexto(char *_texto);
void    setFuente(const char *_tfuente);
void    setTamanio(int _tam);
void    setColor(int _color);
void    pantallaNivel(SDL_Surface *screen, int nivel);
void    dibujarTexto(SDL_Surface *_superficie,int x,int y);
SDL_Surface* liberarSuperficie(){return stexto;}
};


void Textos::pantallaNivel(SDL_Surface *screen, int nivel)
{

    char l[10];
    setColor(7);
    setTamanio(100);
    setFuente(arkanoid);
    setTexto("NIVEL ");
    dibujarTexto(screen,225,225);
    setColor(7);
    setTamanio(100);
    setFuente(arial);
    setTexto(itoa(nivel+2, l, 10));
    dibujarTexto(screen,550,225);
}


Textos::Textos(int _color=1,int _tamanio=30,char * _fuente ="arial.ttf"){
    this->setColor(_color);
    this->setTamanio(_tamanio);
    this->setFuente(_fuente);
}
void Textos::setTexto(char *_texto){
    strcpy(texto,_texto);
}
void Textos::setFuente(const char *_tfuente){
    fuente= TTF_OpenFont(_tfuente,tam);
}
void Textos::setTamanio(int _tam){
    tam=_tam;
}
void Textos::setColor(int _color){
    if(_color==1){
        textColor={ 0, 255, 0 }; return; //Verde
    }
    if(_color==2){
        textColor={ 255, 0, 0 }; return; //rojo
    }
    if(_color==3){
        textColor={ 0, 0, 255 }; return; //azul
    }
    if(_color==4){
        textColor={ 255, 255, 0 }; return; //amarillo
    }
    if(_color==5){
        textColor={ 230, 95, 0 }; return; //naranja
    }
    if(_color==6){
        textColor={ 139, 0, 255 }; return; //violeta
    }
    if(_color==7){
        textColor={ 255, 255, 255 }; return; //blanco
    }
    if(_color==8){
        textColor={ 0, 0, 0 }; return; //negro
    }
}
void Textos::dibujarTexto(SDL_Surface *_superficie,int x,int y){
    trect.x=x;
    trect.y=y;
    stexto=TTF_RenderText_Solid(fuente,texto,textColor);
    TTF_CloseFont(fuente);
    SDL_BlitSurface(stexto,NULL,_superficie,&trect);
    SDL_FreeSurface(stexto);
}


#endif // GRAFICOS_H_INCLUDED
