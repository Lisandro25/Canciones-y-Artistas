#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

#include"class.h"

void Punto1();
void Punto2();
     void mostrarVector(int v[], int tam);
void Punto3();
    int BuscarNOMBREinterprete(const char *);




/// Dado una nacionalidad que se ingresa por teclado,
/// listar todos los intérpretes de esa nacionalidad.

void Punto1(){
    Interpretes obj;
    char Nacionalidad[20];
    cout<<"INGRESAR NACIONALIDAD: ";
    cargarCadena(Nacionalidad,19);
    int pos=0;
    while(obj.leerDeDisco(pos++)){
     if(strcmp(obj.getNacionalidad(),Nacionalidad)==0){
        obj.Mostrar();
     }
}
}


///La cantidad de intérpretes de cada tipo de intérprete, entre los intérpretes de música rock.

void Punto2(){
    Interpretes obj;
    int pos=0;
    int Vinter[5]={};
    while(obj.leerDeDisco(pos++)){
      if(obj.getTipoMusica()==3){
       Vinter[obj.getTipoInterprete()-1]++;
       }
      }
      mostrarVector(Vinter,5);
}


void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"CANTIDAD DE INTERPRETE: "<<v[i]<<"  DEL TIPO DE INTERPRETE "<<i+1<<endl;
    }
}




///Dado el nombre de un intérprete que se ingresa por teclado, generar un archivo
///con las canciones de ese intérprete que se estrenaron el año pasado.

///Los registros deben tener el siguiente formato:
///ID de canción, nombre de la canción, fecha de estreno

class EstrenoAnioPasado{
 private:
    int IDcancion;
    char NombreCancion[30];
    fecha FechaDeEstreno;

 public:
    void setIDcancion(int IDc){IDcancion=IDc;}
    void setNombreCancion(const char *Nc){strcpy(NombreCancion,Nc);}
    void setFechaDeEstreno(fecha Fe){FechaDeEstreno=Fe;}

            bool grabarEnDisco(){
                FILE *pCanc;
                pCanc=fopen("EstrenoAnioPasado.dat", "ab");
                if(pCanc==NULL){
                cout<<"NO SE PUDO CREAR/ABRIR EL ARCHIVO"<<endl;
                return false;
                }
                bool grabo=fwrite(this,sizeof(EstrenoAnioPasado),1,pCanc);
                fclose(pCanc);
                return grabo;
                }
};







void Punto3(){
    Canciones reg;
    EstrenoAnioPasado registro;
    int idInterprete;
    char NombreDelInterprete[30];
    cout<<"NOMBRE DEL INTERPRETE: "<<endl;
    cargarCadena(NombreDelInterprete,29);
    idInterprete=BuscarNOMBREinterprete(NombreDelInterprete);
    if(idInterprete==-1){
        cout<<"NO EXISTE UN INTERPRETE CON ESE NOMBRE"<<endl;
        return;
    }
    int pos=0;
    while(reg.leerDeDisco(pos++)){
    if(reg.getFechaEstreno().getanio()==2020){
      registro.setIDcancion(reg.getIDcancion());
      registro.setNombreCancion(reg.getNombreCancion());
      registro.FechaDeEstreno(reg.getFechaEstreno());
      registro.grabarEnDisco();
    }
 }
}

int BuscarNOMBREinterprete(NombreDelInterprete){
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos)==true){
        if(strcmp(obj.getNombreGRUoPER(),NombreDelInterprete)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}










#endif // PARCIAL_H_INCLUDED
