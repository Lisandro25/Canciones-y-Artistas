#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include"class.h"
void mostrarVector(int v[], int tam);
void CancionesPorArtista();

void AgregarCancion();
void MostrarCancionXID();
void MostrarCanciones();

int BuscarIDcanc(int IDcanc);
bool ModificarFECHA();

bool BajaLogicaCancion();




void AgregarInterprete();
void MostrarInterpreteXID();
void MostrarInterpretes();


bool ModificarTipoMusica();

bool BajaLogicaInterprete();


bool BackUpCanciones();
bool BackUpInterpretes();

bool RestaurarBackUpCanciones();
bool RestaurarBackUpInterpretes();


///-------------------------//-------------------//_----------------------------_///

bool BajaLogicaInterprete(){
    int ID, pos;
    Interpretes obj;
    bool modifico;
    cout<<"INGRESAR EL ID DEL INTERPRETE A BORRAR: ";
    cin>>ID;
    pos=BuscarIDinterprete(ID);
    if(pos==-1){
        cout<<"NO HAY INTERPRETE CON ESE ID"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    obj.setActivo(false);
    modifico=obj.modificarEnDisco(pos);
    return modifico;
}





bool BajaLogicaCancion(){
    int ID, pos;
    Canciones reg;
    bool modifico;
    cout<<"INGRESAR EL ID DE LA CANCION A BORRAR: ";
    cin>>ID;
    pos=BuscarIDcanc(ID);
    if(pos==-1){
        cout<<"NO HAY CANCION CON ESE ID"<<endl;
        return false;
    }
    reg.leerDeDisco(pos);
    reg.setActivo(false);
    modifico=reg.modificarEnDisco(pos);
    return modifico;
}







int BuscarIDcanc(int IDcanc){
    Canciones reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getIDcancion()==IDcanc)
            return pos;
        pos++;
    }
    return -1;
}



bool ModificarFECHA(){
    int IDcanc, pos,dia,mes,anio;
    bool modifico;

    Canciones reg;
    fecha aux;

    cout<<"INGRESAR EL ID DE LA CANCION A MODIFICAR: ";
    cin>>IDcanc;
    cout<<endl;
    pos=BuscarIDcanc(IDcanc);

    if(pos==-1){
        cout<<"NO HAY CANCION CON ESE ID"<<endl;
        return false;
    }
    reg.leerDeDisco(pos);
    reg.Mostrar();
    cout<<endl;

    cout<<"INGRESE LA NUEVA FECHA DE ESTRENO "<<endl;
    cout<<"DIA: ";
    cin>>dia;
    aux.setdia(dia);
    cout<<"MES: ";
    cin>>mes;
    aux.setmes(mes);
    cout<<"ANIO: ";
    cin>>anio;
    aux.setanio(anio);

    reg.setFechaEstreno(aux);

    modifico=reg.modificarEnDisco(pos);
    return modifico;
}

///////////




bool ModificarTipoMusica(){
    int IDinter, pos, tipo;
    bool modifico;

    Interpretes obj;

    cout<<"INGRESAR EL ID DEL INTERPRETE A MODIFICAR: ";
    cin>>IDinter;
    cout<<endl;
    pos=BuscarIDinterprete(IDinter);

    if(pos==-1){
        cout<<"NO HAY INTERPRETE CON ESE ID"<<endl;
        return false;
    }
    obj.leerDeDisco(pos);
    obj.Mostrar();
    cout<<endl;

    cout<<"INGRESE EL NUEVO TIPO DE MUSICA DEL INTERPRETE: ";
    cin>>tipo;
    obj.setTipoMusica(tipo);

    modifico=obj.modificarEnDisco(pos);
    return modifico;
}






///---------------------///////////////////////////////////////////////////////////////////////////////
///CANCIONES////////////

void AgregarCancion(){
    Canciones reg;
    reg.Cargar();
    system("cls");
    if(reg.getActivo()==true){
    if(reg.grabarEnDisco()==true){
        cout<<"REGISTRO AGREGADO !";
    }
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;

}

void MostrarCancionXID(){
    Canciones reg;
    int pos=0, IDc;
    cout<<"INGRESAR ID DE LA CANCION: ";
    cin>>IDc;
    system("cls");
    while(reg.leerDeDisco(pos)==true){
        if(reg.getIDcancion()==IDc){
            reg.Mostrar();
            cout<<endl;
        }
        pos++;
    }

}



void MostrarCanciones(){
    Canciones reg;
    FILE *pCanc;
    pCanc=fopen("Canciones.dat", "rb");
    if(pCanc==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
    while(fread(&reg,sizeof reg,1,pCanc)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(pCanc);
}





///-////////////////////////////////////////////////////////////////////////////////////////////////////////
///INTERPRETES/////

void AgregarInterprete(){
    Interpretes obj;
    obj.Cargar();
    system("cls");
    if(obj.getActivo()==true){
    if(obj.grabarEnDisco()==true){
        cout<<"REGISTRO AGREGADO !";
    }
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
}



void MostrarInterpreteXID(){
    Interpretes obj;
    int pos=0, IDi;
    cout<<"INGRESAR ID DEL INTERPRETE: ";
    cin>>IDi;
    system("cls");
    while(obj.leerDeDisco(pos)==true){
        if(obj.getIDinterprete()==IDi){
            obj.Mostrar();
            cout<<endl;
        }
        pos++;
    }
}



void MostrarInterpretes(){
    Interpretes obj;
    FILE *pInter;
    pInter=fopen("Interpretes.dat", "rb");
    if(pInter==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj,sizeof obj,1,pInter)==1){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pInter);
}


///--------------------------------------------------//////////////////////////////////
bool BackUpCancionesINICIO(){
     FILE *p;
     p=fopen("Canciones.inicio", "wb");
    if(p==NULL)return false;
    Canciones reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
    if(fwrite(&reg,sizeof reg,1,p)==0){
        fclose(p);
        return false;
    }
}
     fclose(p);
     return true;
}


bool RestaurarBackUpCancionesINICIO(){
     FILE *p;
     p=fopen("Canciones.dat", "wb");
    if(p==NULL)return false;
    fclose(p);
    Canciones reg;
    int pos=0;
    while(reg.leerDeBcp(pos++)){
         if(!reg.grabarEnDisco()){
            return false;
         }
    }
           return true;
}



bool BackUpCanciones(){
     FILE *p;
     p=fopen("Canciones.bkp", "wb");
    if(p==NULL)return false;
    Canciones reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
    if(fwrite(&reg,sizeof reg,1,p)==0){
        fclose(p);
        return false;
    }
}
     fclose(p);
     return true;
}



bool RestaurarBackUpCanciones(){
     FILE *p;
     p=fopen("Canciones.dat", "wb");
    if(p==NULL)return false;
    fclose(p);
    Canciones reg;
    int pos=0;
    while(reg.leerDeBkp(pos++)){
         if(!reg.grabarEnDisco()){
            return false;
         }
    }
           return true;
}




bool BackUpInterpretesINICIO(){
     FILE *p;
     p=fopen("Interpretes.inicio", "wb");
    if(p==NULL)return false;
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
    if(fwrite(&obj,sizeof obj,1,p)==0){
        fclose(p);
        return false;
    }
}
     fclose(p);
     return true;
}


bool RestaurarBackUpInterpretesINICIO(){
     FILE *p;
     p=fopen("Interpretes.dat", "wb");
    if(p==NULL)return false;
    fclose(p);
    Interpretes obj;
    int pos=0;
    while(obj.leerDeBack(pos++)){
         if(!obj.grabarEnDisco()){
            return false;
         }
    }
           return true;
}



bool BackUpInterpretes(){
     FILE *p;
     p=fopen("Interpretes.bkp", "wb");
    if(p==NULL)return false;
    Interpretes obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
    if(fwrite(&obj,sizeof obj,1,p)==0){
        fclose(p);
        return false;
    }
}
     fclose(p);
     return true;
}


bool RestaurarBackUpInterpretes(){
     FILE *p;
     p=fopen("Interpretes.dat", "wb");
    if(p==NULL)return false;
    fclose(p);
    Interpretes obj;
    int pos=0;
    while(obj.leerDeBkp(pos++)){
         if(!obj.grabarEnDisco()){
            return false;
         }
    }
           return true;
}



void CancionesPorArtista(){
Canciones reg;
int V[8]={0};
int pos=0;
    while(reg.leerDeDisco(pos++)){
           V[reg.getIDinterprete()-1]++;
            }
            pos++;
            mostrarVector(V,8);
            }




void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"ARTISTA "<<i+1<<": "<<v[i]<<endl;
    }
}



#endif // FUNCIONES_H_INCLUDED
