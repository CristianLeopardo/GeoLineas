#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
class Usuario{

private:
    int nivel,puntaje;
    char nombre[15];
public:
void setPuntaje(int _puntaje){puntaje+=_puntaje;}
int getPuntaje(){return puntaje;}
void setNivel(int _nivel){nivel=_nivel;}
int getNivel(){return nivel;}
char *  getNombre(){return nombre;}
void    setNombre(char * _nombre){strcpy(nombre,_nombre);}
bool leer_de_Disco(int _pos)
{
    FILE *p;
    bool x=false;
    p=fopen("dudosos.dat","rb");
    if(p==NULL){
        freopen ("LogFile.txt","w+",stdout);
        printf("%d",2);
        fclose(stdout);
    }
    fseek(p,sizeof *this*_pos,0);
    x=fread(this,sizeof *this,1,p);
    if(x){x=true;}
    fclose(p);
    return x;
}
void grabar_en_Disco()
{
  FILE *p;
  p=fopen("dudosos.dat", "ab");
  if(p==NULL)exit(1);
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
}
};


#endif // USUARIO_H_INCLUDED
