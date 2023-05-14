#ifndef GRILLA_H_INCLUDED
#define GRILLA_H_INCLUDED
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
class grilla : public Juego{
private:
    int a[10][10],_movimientos=1;
    Triangulo tri;
    Cuadrado cuad;
    Rombo rom;
    Circulo cir;
    Vacio vac;
    Bloque blo;
    Usuario usu;
//    Comodin com;
public:
    grilla(){
        setPuntaje(0);
    }
    void MostrarMatriz(SDL_Surface* screen);
    void SubirNumeros();
    int BuscarCoincidencias(int);
    void setRandom();
    void setRandomNeg();
    void getRandom();
    bool Intercambiar(int x, int y, int x2, int y2);
    bool BuscarBloque(int x,int y);
    void IniciarNivel();
    int BuscarINI();
    int getCeldaId(int j,int i);
    int buscarIgual(int j,int i);
    bool buscarCoincidenciaH(int j,int i);
    void setNivel1();
    void setNivel2();
    void setNivel3();
    void setNivel4();
    void DestruirTriangulo(){
        tri.~Triangulo();
    }
    void DestruirCuadrado(){
        cuad.~Cuadrado();
    }
    void DestruirCirculo(){
        cir.~Circulo();
    }
    void DestruirRombo(){
        rom.~Rombo();
    }
    void DestruirVacio(){
        vac.~Vacio();
    }
    void DestruirBloque(){
        blo.~Bloque();
    }
    void evaluarXPuntaje(int _ID,int _coincidencia_id,int _nivel);
};
void grilla::evaluarXPuntaje(int _ID,int _coincidencia_id,int _nivel){



switch (_coincidencia_id){
case 3:Mix_PlayChannel( -1, tututu, 0 );

        break;
case 4: Mix_PlayChannel( -1, explo, 0 );

        break;
case 5: Mix_PlayChannel( -1, fium, 0 );

        break;
}

    switch (_ID){
    case 0:
        switch (_coincidencia_id){
        case 3:
            this->AcumularPuntaje(40*this->getMultiplicador());
            break;
        case 4:
            this->AcumularPuntaje(80*this->getMultiplicador());
            break;
        case 5:
            this->AcumularPuntaje(300*this->getMultiplicador());
            break;
        }
        break;
    case 1:
        switch (_coincidencia_id){
        case 3:
            this->AcumularPuntaje(30*this->getMultiplicador());
            break;
        case 4:
            this->AcumularPuntaje(60*this->getMultiplicador());
            break;
        case 5:
            this->AcumularPuntaje(200*this->getMultiplicador());
            break;
        }
        break;
    case 2:
        switch (_coincidencia_id){
        case 3:
            this->AcumularPuntaje(60*this->getMultiplicador());
            break;
        case 4:
            this->AcumularPuntaje(120*this->getMultiplicador());
            break;
        case 5:
            this->AcumularPuntaje(500*this->getMultiplicador());
            if(_nivel==4){
            //this->incrementarMovimientos();
            }
            break;
        }
        break;
    case 3:
        switch (_coincidencia_id){
        case 3:
            this->AcumularPuntaje(50*this->getMultiplicador());
            break;
        case 4:
            this->AcumularPuntaje(100*this->getMultiplicador());
            break;
        case 5:
            this->AcumularPuntaje(400*this->getMultiplicador());
            break;
        }
}
}

void grilla::setNivel4()
{
    setNivel1();
    int i;
    for (i=0;i<10;i++)
    {
        a[i][0]= a[i][1]=a[i][2]=a[i][7]=a[i][8]=a[i][9]=6;
    }
    setMovimientos(35);
}

void grilla::setNivel3()
{
    setNivel1();
    int i;
    for (i=0;i<10;i++)
    {
        a[9][i] = a[8][i]=6;
    }
    for (i=0;i<10;i++)
    {
        a[i][0] = a[i][9]=6;
    }
    setMovimientos(25);
}

void grilla::setNivel2()
{
    setNivel1();
    int i;
    for (i=0;i<10;i++)
    {
        a[9][i] =6;
    }
    a[8][9]=a[8][8]=a[7][9]=a[7][0]=a[8][0]=a[8][1]=6;
    setMovimientos(15);
}

void grilla::setNivel1()
{
    setRandom();
    while (BuscarINI()!=0)
    {
        int i;
        for (i=0;i<10;i++)
        {
            SubirNumeros();
        }
    }
    setMovimientos(20);
}

bool grilla::Intercambiar(int x, int y, int x2, int y2)
{
        int aux;
        if (((((x-1)-(x2-1))<=1)&&(((x-1)-(x2-1))>=-1))&&((((y-1)-(y2-1)<=1)&&((y-1)-(y2-1)>=-1))))
        {
            if ((a[y-1][x-1]!=6)&&(a[y2-1][x2-1]!=6))
            {
            aux =a[y-1][x-1] ;
            a[y-1][x-1] =a[y2-1][x2-1];
            a[y2-1][x2-1] = aux;
            return true;
            }

        }
        return false;

}

void grilla::MostrarMatriz(SDL_Surface* screen)
{
    SDL_Rect rectangulo;
    rectangulo.x = 75;
    rectangulo.y = 75;
    int i,j;
    for (j=0;j<10;j++)
    {

                rectangulo.x=75;
        for(i=0;i<10;i++)
        {

            if (a[j][i]==0)
            {
                tri.dibujar(screen,0,rectangulo.x,rectangulo.y);

            }

            if (a[j][i]==1)
            {
                cuad.dibujar(screen,rectangulo.x,rectangulo.y);
            }

            if (a[j][i]==2)
            {
                rom.dibujar(screen,rectangulo.x,rectangulo.y);
            }
            if (a[j][i]==3)
            {
                cir.dibujar(screen,rectangulo.x,rectangulo.y);
            }
            if (a[j][i]==4)
            {
                blo.dibujar(screen,rectangulo.x,rectangulo.y);
            }

            if (a[j][i]==-1)
            {
                vac.dibujar(screen,rectangulo.x,rectangulo.y);
            }
            rectangulo.x += 75;
        }
        rectangulo.y +=75;
    }
}

void grilla::setRandom()
{
    int j,i;
    srand ( time(NULL) );
    for (j=0;j<10;j++)
    {
        for (i=0;i<10;i++)
        {
           a[j][i]=rand()%4;
        }
    }
    /*
    */
}

int grilla::BuscarINI()
{
    int i,j,aux,ini=0;
    for (j=0;j<10;j++)
    {
        for (i=0;i<10;i++)
        {
            if((a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i]))
                        {
                            if ((j+1<10)&&(j+2<10))
                            {
                                if(a[j][i]>-1){
                                    aux=a[j][i];
                                    a[j][i]=-1;
                                    a[j+1][i]=-1;
                                    a[j+2][i]=-1;
                                    ini++;
                                }
                            }
                        }
                        if((a[j][i]==a[j][i+1])&&(a[j][i+1]==a[j][i+2]))
                            {
                            if ((i+1<10)&&(i+2<10))
                                {
                                    if(a[j][i]>-1){
                                        aux=a[j][i];
                                        a[j][i]=-1;
                                        a[j][i+1]=-1;
                                        a[j][i+2]=-1;
                                        ini ++;
                                    }
                                }
                            }
        }
    }
    return ini;
}

void grilla::setRandomNeg()
{
    int j,i;
    srand ( time(NULL) );
    for (j=0;j<10;j++)
    {
        for (i=0;i<10;i++)
        {
            if(a[j][i]==-1)a[j][i]=rand()%4;
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
           cout<< a[j][i]<<"\t";
        }
    }
}

int grilla::BuscarCoincidencias(int _vuelta)
{
    int i,j,aux,p=0;
for (j=0;j<10;j++)
    {
        for (i=0;i<10;i++)
        {
            //HORIZONTAL
            if((i<6)&&(a[j][i]==a[j][i+1])&&(a[j][i+1]==a[j][i+2])&&(a[j][i+2]==a[j][i+3])&&(a[j][i+3]==a[j][i+4]))
            {
                if((i+1<10)&&(i+2<10)&&(i+3<10)&&(i+4<10))
                {
                    if(a[j][i]>-1&&a[j][i]!=6){
                        aux=a[j][i];
                        a[j][i]=-1;
                        a[j][i+1]=-1;
                        a[j][i+2]=-1;
                        a[j][i+3]=-1;
                        a[j][i+4]=-1;
                        this->evaluarXPuntaje(aux,5,this->getNivel());
                    }
                    //this->incrementarMovimientos();
                }

            }
            else
            {
                    if((i<7)&&(a[j][i]==a[j][i+1])&&(a[j][i+1]==a[j][i+2])&&(a[j][i+2]==a[j][i+3]))
                    {
                        if((i+1<10)&&(i+2<10)&&(i+3<10))
                        {
                            if(a[j][i]>-1&&a[j][i]!=6){
                                aux=a[j][i];
                                a[j][i]=-1;
                                a[j][i+1]=-1;
                                a[j][i+2]=-1;
                                a[j][i+3]=-1;
                                _vuelta+=1;
                                p++;
                                this->evaluarXPuntaje(aux,4,this->getNivel());
                            }
                        }

                    }
                    else
                    {
                        if((i<8)&&(a[j][i]==a[j][i+1])&&(a[j][i+1]==a[j][i+2]))
                            {
                            if ((i+1<10)&&(i+2<10))
                                {
                                    if(a[j][i]>-1&&a[j][i]!=6){
                                        aux=a[j][i];
                                        a[j][i]=-1;
                                        a[j][i+1]=-1;
                                        a[j][i+2]=-1;
                                        this->evaluarXPuntaje(aux,3,this->getNivel());
                                    }
                                }

                            }
                    }
            }

            //VERTICAL
            if((j<6)&&(a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i])&&(a[j+2][i]==a[j+3][i])&&(a[j+3][i]==a[j+4][i]))
                {
                    if((j+1<10)&&(j+2<10)&&(j+3<10)&&(j+4<10)){
                        if(a[j][i]>-1&&a[j][i]!=6){
                            aux=a[j][i];
                            a[j][i]=-1;
                            a[j+1][i]=-1;
                            a[j+2][i]=-1;
                            a[j+3][i]=-1;
                            a[j+4][i]=-1;
                            this->evaluarXPuntaje(aux,5,this->getNivel());
                            //this->incrementarMovimientos();
                        }
                    }
                }
            else
            {
               if((j<7)&&(a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i])&&(a[j+2][i]==a[j+3][i]))
                    {
                        if((j+1<10)&&(j+2<10)&&(j+3<10)){
                            if(a[j][i]>-1&&a[j][i]!=6){
                                aux=a[j][i];
                                a[j][i]=-1;
                                a[j+1][i]=-1;
                                a[j+2][i]=-1;
                                a[j+3][i]=-1;p++;
                               this->evaluarXPuntaje(aux,4,this->getNivel());
                            }
                        }
                    }
                else
                {
                    if((j<8)&&(a[j][i]==a[j+1][i])&&(a[j+1][i]==a[j+2][i]))
                        {
                            if ((j+1<10)&&(j+2<10))
                            {
                                if(a[j][i]>-1&&a[j][i]!=6){
                                    aux=a[j][i];
                                    a[j][i]=-1;
                                    a[j+1][i]=-1;
                                    a[j+2][i]=-1;
                                    this->evaluarXPuntaje(aux,3,this->getNivel());
                                }
                            }
                        }
                }
            }
        }
    }
    return p;
}

void grilla::SubirNumeros()
{
    int j,i,k,aux;

        for (j=0;j<10;j++)
        {
            for(i=0;i<10;i++)
            {
                if(a[j][i]!=4){
                    if (a[j][i]==-1)
                    {
                        if (j>0)
                        {
                            aux=a[j-1][i];
                            a[j-1][i]=a[j][i];
                            a[j][i]=aux;
                        }
                        else
                        {
                            a[j][i]=rand()%4;
                            a[j][i]=rand()%4;
                        }
                    }
                }else{}
            }
        }
}
bool grilla::BuscarBloque(int y,int x){
    bool encontre=false;
    freopen ("myfile3.txt","w",stdout);
  printf ("%d",a[y-1][x-1]);
  fclose (stdout);
    if(a[y-1][x-1]==4){
        encontre=true;
    }
return encontre;
}
int grilla::getCeldaId(int j,int i){
    freopen ("myfile4.txt","w",stdout);
    printf ("%d",a[j][i]);
    fclose (stdout);
    return a[j][i];
}
bool grilla::buscarCoincidenciaH(int j,int i){
    bool coincidencia=false;
    if((a[j][i]==a[j][i+1])&&(a[j][i]==a[j][i+2])){
        coincidencia=true;
    }
    return coincidencia;
}

#endif // GRILLA_H_INCLUDED
