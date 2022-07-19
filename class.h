#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#include"funciones.h"

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int BuscarIDinterprete(int IDinter);

///_________________________________///____________________________///_________________________//_____

class fecha {
  private:
    int dia,mes,anio;
  public:
       fecha(int d=0, int m=0, int a=0){
       dia=d;
       mes=m;
       anio=a;
       }
///________SETS_________________________
  bool setdia(int d){
        if(d>0 && d<=31){
               dia=d;
        return true;
        }
        return false;
        }




  bool setmes(int m){
        if(m>0 && m<=12){mes=m;
           return true;}
           return false;}




  bool setanio(int a){
        if(a>0 && a<=2021){anio=a;
           return true;}
           return false;}


                           bool ValidarFecha(){
                           int DiaPorMes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
                           if(dia>DiaPorMes[mes-1]) return false;
                           return true;
                           }
///_______GETS__________________________
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}





    bool Cargar(){
                    int dia,mes,anio;
                  cout<<"DIA: ";
                  cin>>dia;
                  if(setdia(dia)==false){
                    cout<<"EL DIA NO ES VALIDO"<<endl;
                    system("pause>nul");
                    return false;
                  }

                  cout<<"MES: ";
                  cin>>mes;
                  if(setmes(mes)==false){
                    cout<<"EL MES NO ES VALIDO"<<endl;
                    system("pause>nul");
                    return false;
                  }

                  cout<<"ANIO: ";
                  cin>>anio;
                  if(setanio(anio)==false){
                    cout<<"EL ANIO NO ES VALIDO"<<endl;
                    system("pause>nul");
                    return false;
                  }
                  return ValidarFecha();
                  }

    void Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }



};


///_____________________CLASS CANCIONES_________________________________________

class Canciones{

private:
    int IDcancion;
    char NombreCancion[30];
    char NombreAutor[30];
    int IDinterprete;
    fecha FechaEstreno;
    bool Activo;


public:
    void Cargar();
    void Mostrar();

                            bool grabarEnDisco(){    ///___FUNCION__///
                            FILE *pCanc;
                            pCanc=fopen("Canciones.dat", "ab");
                            if(pCanc==NULL){
                            cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                            return false;
                            }
                            bool grabo=fwrite(this,sizeof(Canciones),1,pCanc);
                            fclose(pCanc);
                            return grabo;
                            }

    bool leerDeDisco(int pos){     ///___FUNCION__///
        FILE *p;
        p=fopen("Canciones.dat","rb");
        if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
        }
        fseek(p,sizeof(Canciones)*pos,0);
        bool leyo=fread(this, sizeof(Canciones), 1, p);
        fclose(p);
        return leyo;
        }


                              bool modificarEnDisco(int pos){
                                  FILE *p;
                                  p=fopen("Canciones.dat","rb+");///+ agrega al modo lo que le falta
                                  if(p==NULL){
                                  cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                                  return false;
                                  }
                                  fseek(p,sizeof(Canciones)*pos,0);
                                  bool leyo=fwrite(this, sizeof(Canciones), 1, p);
                                  fclose(p);
                                  return leyo;

                              }

        bool leerDeBkp(int pos){     ///___FUNCION__///
        FILE *p;
        p=fopen("Canciones.bkp","rb");
        if(p==NULL){
        return false;
        }
        fseek(p,sizeof(Canciones)*pos,0);
        bool leyo=fread(this, sizeof(Canciones), 1, p);
        fclose(p);
        return leyo;
        }


        bool leerDeBcp(int pos){     ///___FUNCION__///
        FILE *p;
        p=fopen("Canciones.inicio","rb");
        if(p==NULL){
        return false;
        }
        fseek(p,sizeof(Canciones)*pos,0);
        bool leyo=fread(this, sizeof(Canciones), 1, p);
        fclose(p);
        return leyo;
        }




///___________SETS_______________________________
    void setIDcancion(int IDc){IDcancion=IDc;}
    void setNombreCancion(const char *Nc){strcpy(NombreCancion,Nc);}
    void setNombreAutor(const char *Na){strcpy(NombreAutor,Na);}
    void setIDinterprete(int IDi){IDinterprete=IDi;}
    void setActivo(bool A){Activo=A;}
    void setFechaEstreno(fecha F){FechaEstreno=F;}

///____________GETS________________________________
    int getIDcancion(){return IDcancion;}
    const char *getNombreCancion(){return NombreCancion;}
    const char *getNombreAutor(){return NombreAutor;}
    int getIDinterprete(){return IDinterprete;}
    bool getActivo(){return Activo;}
    fecha getFechaEstreno(){return FechaEstreno;};
};
                                  void Canciones::Cargar(){
                                  cout<<"ID CANCION: ";
                                  cin>>IDcancion;
                                  cout<<"NOMBRE DE LA CANCION: ";
                                  cargarCadena(NombreCancion,29);
                                  cout<<"NOMBRE DEL AUTOR: ";
                                  cargarCadena(NombreAutor,29);
                                  cout<<"ID DEL INTERPRETE: ";
                                  cin>>IDinterprete;
                                  if(BuscarIDinterprete(IDinterprete)==-1){
                                        cout<<endl;
                                  textcolor(cROJO);
                                    cout<<"EL ID NO PERTENECE A NINGUN INTERPRETE";
                                    system("pause>nul");
                                    Activo=false;
                                    return;
                                  }
                                  cout<<"FECHA DE ESTRENO "<<endl;
                                  if(FechaEstreno.Cargar()==false){
                                  Activo=false;
                                  return;
                                  }
                                  Activo=true;
                                  }

   void Canciones::Mostrar(){
       if(Activo==true){
   cout<<"ID CANCION: "<<IDcancion<<endl;
   cout<<"NOMBRE DE LA CANCION: "<<NombreCancion<<endl;
   cout<<"NOMBRE DEL AUTOR: "<<NombreAutor<<endl;
   cout<<"ID DEL INTERPRETE: "<<IDinterprete<<endl;
   cout<<"FECHA DE ESTRENO ";
   FechaEstreno.Mostrar();

       }

   }



///_______________CLASS INTERPRETES____________________________________

class Interpretes{
private:
    int IDinterprete;
    char NombreGRUoPER[40];
    char Nacionalidad[20];
    int TipoInterprete;
    int TipoMusica;
    bool Activo;

public:
    void Cargar();
    void Mostrar();
                      bool grabarEnDisco(){   ///___FUNCION__///
                          FILE *pInter;
                          bool grabo;
                          pInter=fopen("Interpretes.dat", "ab");
                          if(pInter==NULL){
                              return false;
                          }
                          grabo=fwrite(this,sizeof(Interpretes)/*this*/,1,pInter);
                          fclose(pInter);
                          return grabo;
                          }

        bool leerDeDisco(int pos){  ///___FUNCION__///
            FILE *p;
            p=fopen("Interpretes.dat","rb");
            if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
            }
            fseek(p,sizeof(Interpretes)*pos,0);
            bool leyo=fread(this, sizeof(Interpretes), 1, p);
            fclose(p);
            return leyo;
            }


                              bool modificarEnDisco(int pos){
                                  FILE *p;
                                  p=fopen("Interpretes.dat","rb+");
                                  if(p==NULL){
                                  cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                                  return false;
                                  }
                                  fseek(p,sizeof(Interpretes)*pos,0);
                                  bool leyo=fwrite(this, sizeof(Interpretes), 1, p);
                                  fclose(p);
                                  return leyo;
                                  }

        bool leerDeBkp(int pos){     ///___FUNCION__///
        FILE *p;
        p=fopen("Interpretes.bkp","rb");
        if(p==NULL){
        return false;
        }
        fseek(p,sizeof(Interpretes)*pos,0);
        bool leyo=fread(this, sizeof(Interpretes), 1, p);
        fclose(p);
        return leyo;
        }


        bool leerDeBack(int pos){     ///___FUNCION__///
        FILE *p;
        p=fopen("Interpretes.inicio","rb");
        if(p==NULL){
        return false;
        }
        fseek(p,sizeof(Interpretes)*pos,0);
        bool leyo=fread(this, sizeof(Interpretes), 1, p);
        fclose(p);
        return leyo;
        }


///______________SETS__________________________
     void setIDinterprete(int IDi){IDinterprete=IDi;}
     void setNombreGRUoPER(const char *NGP){strcpy(NombreGRUoPER,NGP);}
     void setNacionalidad(const char *Nac){strcpy(Nacionalidad,Nac);}

      bool setTipoInterprete(int TipoInt){
           if(TipoInt>0 && TipoInt<6){
           TipoInterprete=TipoInt;
           return true;
           }
           return false;
           }

                             bool setTipoMusica(int TipoMus){
                                  if(TipoMus>0 && TipoMus<11){
                                  TipoMusica=TipoMus;
                                  return true;
                                  }
                                  return false;
                                  }

     void setActivo(bool A){Activo=A;}


 ///_____________GETS_______________________________
     int getIDinterprete(){return IDinterprete;}
     const char *getNombreGRUoPER(){return NombreGRUoPER;}
     const char *getNacionalidad(){return Nacionalidad;}
     int getTipoInterprete(){return TipoInterprete;}
     int getTipoMusica(){return TipoMusica;}
     bool getActivo(){return Activo;}
};


                    void Interpretes::Cargar(){
                    cout<<"ID INTERPRETE: ";
                    cin>>IDinterprete;
                    cout<<"NOMBRE DEL GRUPO O PERSONA: ";
                    cargarCadena(NombreGRUoPER,39);
                    cout<<"NACIONALIDAD: ";
                    cargarCadena(Nacionalidad,19);
                    cout<<"TIPO DE INTERPRETE: ";
                    cin>>TipoInterprete;
                    if(setTipoInterprete(TipoInterprete)==false){
                     cout<<"TIPO DE INTERPRETE INCORRECTO";
                     system("pause>nul");
                           Activo=false;
                           return;
                    }
                    cout<<"TIPO DE MUSICA: ";
                    cin>>TipoMusica;
                    if(setTipoMusica(TipoMusica)==false){
                        cout<<"TIPO DE MUSICA INCORECTO";
                        system("pause>nul");
                        Activo=false;
                        return;
                    }
                    Activo=true;
                    }



   void Interpretes::Mostrar(){
       if(Activo==true){
   cout<<"ID INTERPRETE: "<<IDinterprete<<endl;
   cout<<"NOMBRE DEL GRUPO O PERSONA: "<<NombreGRUoPER<<endl;
   cout<<"NACIONALIDAD: "<<Nacionalidad<<endl;
   cout<<"TIPO DE INTERPRETE: "<<TipoInterprete<<endl;
   cout<<"TIPO DE MUSICA: "<<TipoMusica<<endl;
   }
   }






   int BuscarIDinterprete(int IDinter){
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDinterprete()==IDinter)
            return pos;
        pos++;
    }
    return -1;
}


#endif // CLASS_H_INCLUDED
