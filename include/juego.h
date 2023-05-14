#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
class Juego{

    protected:
    int movimientos,puntaje,puntajeMaximo,puntajeTotal,multiplicador=1;
    bool gano,corriendo;
    int nivel;
    Mix_Chunk *tututu = NULL;
    Mix_Chunk *explo = NULL;
    Mix_Chunk *fium = NULL;

    public:
    Juego(int _movimientos=45){
        movimientos=_movimientos;
        puntaje=0;
    }
    void grabarPuntaje(char *_nombre="LUCHO");
    void inicializarSonidos();
    int     getPuntajeTotal(){return puntajeTotal;}
    void    setPuntajeTotal(int _puntaje){puntajeTotal=_puntaje;}
    void    setPuntajeTotalSUM(int _puntaje){puntajeTotal+=_puntaje;}
    void setNivel(int a){nivel = a;}
    int getNivel(){return nivel;}
    void iniciarJuego();
    void setMultiplicador(int _multi){multiplicador= _multi;}
    int getMultiplicador(){return multiplicador;}
    int getMovimientos(){return movimientos;}
    void setMovimientos(int _movimientos){movimientos=_movimientos;}
    void RestarMovimientos(){movimientos--;}
    void incrementarMovimientos(int _movimientos){movimientos+=_movimientos;}
    bool getGano(){return gano;}
    void setGano(bool _gano){gano=_gano;}
    int getCorriendo(){return corriendo;}
    void setCorriendo(bool _corriendo){corriendo=_corriendo;}
    void setPuntaje(int _puntaje){puntaje+=_puntaje;}
    int getPuntaje(){return puntaje;}
    int getPuntajeMaximo(){return puntajeMaximo;}
    void setPuntajeMaximo(int _puntajeMaximo){puntajeMaximo=_puntajeMaximo;}
    void AcumularPuntaje(int _puntaje);
};
void Juego::AcumularPuntaje(int _puntaje){
    setPuntaje(_puntaje);
    //setPuntajeTotal(_puntaje);
}

void Juego::inicializarSonidos()
{
tututu = Mix_LoadWAV( "sounds/tututu.wav" );
fium = Mix_LoadWAV( "sounds/fium.wav" );
explo = Mix_LoadWAV( "sounds/explo.wav" );
}
void Juego::grabarPuntaje(char *_nombre){
freopen ("Puntajes.txt","a+",stdout);
printf ("%s %i %i",_nombre,puntaje,nivel);
fclose (stdout);
}

#endif // JUEGO_H_INCLUDED

