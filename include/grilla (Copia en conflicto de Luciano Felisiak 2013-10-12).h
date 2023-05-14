#ifndef GRILLA_H_INCLUDED
#define GRILLA_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>

class grilla
{
private:
    int a[10][10];
    //Triangulo tri;
    //Cuadrado cuad;
    //Rombo rom;
    //Circulo cir;
    //Vacio vac;


public:
    void setRandom();
    void getRandom();
};

void grilla::setRandom()
{
    int j,i;
    for (j=0;j<10;j++)
    {

        for (i=0;i<10;i++)
        {
           a[j][i]=rand()%4;
        }
    }
}

void grilla::getRandom()
{
    int j,i;
    for (j=0;j<10;j++)
    {

        for (i=0;i<10;i++)
        {
           cout<< a[j][i];
        }
    }
}


#endif // GRILLA_H_INCLUDED
