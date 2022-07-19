#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED

#include "funciones.h"

void SubMenuCanciones();
void SubMenuInterpretes();
void SubMenuConfiguracion();
void SubMenuReportes();



void SubMenuCanciones(){
    recuadro(25, 3, 67, 16, cROJO_CLARO, cNEGRO);
    textcolor(cAMARILLO);
 int opc1;

 gotoxy(53,7);
cout<<"MENU CANCIONES"<<endl;
gotoxy(43,8);
cout<<"-------------------------------"<<endl;
gotoxy(43,9);
cout<<"1) AGREGAR CANCION"<<endl;
gotoxy(43,10);
cout<<"2) LISTAR CANCION POR ID"<<endl;
gotoxy(43,11);
cout<<"3) LISTAR TODAS LAS CANCIONES"<<endl;
gotoxy(43,12);
cout<<"4) MODIFICAR FECHA DE ESTRENO "<<endl;
gotoxy(43,13);
cout<<"5) ELIMINAR CANCION"<<endl;
gotoxy(43,14);
cout<<"--------------------------------"<<endl;
gotoxy(43,15);
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
gotoxy(27,18);
cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
cin>>opc1;
clrscr();

switch(opc1){

        case 1: AgregarCancion();
        system("pause>nul");
        system("cls");
        SubMenuCanciones();
            break;

        case 2: MostrarCancionXID();
        system("pause>nul");
        system("cls");
        SubMenuCanciones();
            break;

        case 3:MostrarCanciones();
        system("pause>nul");
        system("cls");
        SubMenuCanciones();
            break;

        case 4: if(ModificarFECHA()==true){
                        cout<<"REGISTRO MODIFICADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                    }
         system("pause>nul");
         system("cls");
         SubMenuCanciones();
            break;

        case 5: if(BajaLogicaCancion()==true){
                        cout<<"REGISTRO BORRADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                    }
         system("pause>nul");
         system("cls");
         SubMenuCanciones();
            break;

        case 0: return;
            break;

            default:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                    gotoxy(50,6);
                    textcolor(cAMARILLO);
                    cout<<"OPCION INCORRECTA";
                    system("pause>nul");
                    system("cls");
                    SubMenuCanciones();
}
}




void SubMenuInterpretes(){
    recuadro(25, 3, 67, 16, cROJO_CLARO, cNEGRO);
    textcolor(cAMARILLO);

int opc2;

gotoxy(53,7);
cout<<"MENU INTERPRETES"<<endl;
gotoxy(43,8);
cout<<"-------------------------------"<<endl;
gotoxy(43,9);
cout<<"1) AGREGAR INTERPRETE"<<endl;
gotoxy(43,10);
cout<<"2) LISTAR INTERPRETE POR ID"<<endl;
gotoxy(43,11);
cout<<"3) LISTAR TODOS LOS INTERPRETES"<<endl;
gotoxy(43,12);
cout<<"4) MODIFICAR TIPO DE MUSICA "<<endl;
gotoxy(43,13);
cout<<"5) ELIMINAR INTERPRETE"<<endl;
gotoxy(43,14);
cout<<"--------------------------------"<<endl;
gotoxy(43,15);
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
gotoxy(27,18);
cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
cin>>opc2;
clrscr();

switch(opc2){

        case 1: AgregarInterprete();
        system("pause>nul");
        system("cls");
        SubMenuInterpretes();
            break;

        case 2: MostrarInterpreteXID();
        system("pause>nul");
        system("cls");
        SubMenuInterpretes();
            break;

        case 3: MostrarInterpretes();
        system("pause>nul");
        system("cls");
        SubMenuInterpretes();
            break;

        case 4: if(ModificarTipoMusica()==true){
                        cout<<"REGISTRO MODIFICADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                    }
        system("pause>nul");
        system("cls");
        SubMenuInterpretes();
            break;

        case 5: if(BajaLogicaInterprete()==true){
                        cout<<"REGISTRO BORRADO"<<endl;
                    }
                    else{
                        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                    }
        system("pause>nul");
        system("cls");
        SubMenuInterpretes();

            break;

        case 0: return;
            break;

            default:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                    gotoxy(50,6);
                    textcolor(cAMARILLO);
                    cout<<"OPCION INCORRECTA";
                    system("pause>nul");
                    system("cls");
                    SubMenuInterpretes();
}

}


void SubMenuReportes(){
    recuadro(25, 3, 67, 16, cROJO_CLARO, cNEGRO);
    textcolor(cAMARILLO);

int opc3;
gotoxy(53,7);
cout<<"MENU REPORTES"<<endl;
gotoxy(31,8);
cout<<"-------------------------------------------------------"<<endl;
gotoxy(31,9);
cout<<"1) MOSTRAR POR INTERPRETE LA CANTIDAD DE CANCIONES "<<endl;
gotoxy(31,10);
cout<<"------------------------------------------------------"<<endl;
gotoxy(31,11);
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
gotoxy(27,14);
cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
cin>>opc3;
clrscr();

switch(opc3){

        case 1:CancionesPorArtista();
        system("pause>nul");
        system("cls");
        SubMenuReportes();
            break;

        case 0: return;

            break;
            default:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                    gotoxy(50,6);
                    textcolor(cAMARILLO);
                    cout<<"OPCION INCORRECTA";
                    system("pause>nul");
                    system("cls");
                    SubMenuReportes();
}
}


void SubMenuConfiguracion(){
    recuadro(25, 3, 67, 16, cROJO_CLARO, cNEGRO);
    textcolor(cAMARILLO);
int opc4;

gotoxy(53,7);
cout<<"MENU CONFIGURACION"<<endl;
gotoxy(31,8);
cout<<"--------------------------------------------------------"<<endl;
gotoxy(31,9);
cout<<"1) HACER COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES"<<endl;
gotoxy(31,10);
cout<<"2) HACER COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES"<<endl;
gotoxy(31,11);
cout<<"3) RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
gotoxy(31,12);
cout<<"4) RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
gotoxy(31,13);
cout<<"5) ESTABLECER DATOS DE INICIO"<<endl;
gotoxy(31,14);
cout<<"--------------------------------------------------------"<<endl;
gotoxy(31,15);
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
gotoxy(27,18);
cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
cin>>opc4;
clrscr();

switch(opc4){

        case 1: BackUpCanciones();
                recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                gotoxy(45,6);
                textcolor(cAMARILLO);
        cout<<"COPIA DE SEGURIDAD REALIZADA";
        system("pause>nul");
        system("cls");
        SubMenuConfiguracion();
            break;

        case 2: BackUpInterpretes();
                recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                gotoxy(43,6);
                textcolor(cAMARILLO);
        cout<<"COPIA DE SEGURIDAD REALIZADA";
        system("pause>nul");
        system("cls");
        SubMenuConfiguracion();
            break;

        case 3: RestaurarBackUpCanciones();
                recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                gotoxy(43,6);
                textcolor(cAMARILLO);
        cout<<"ARCHIVO DE CANCIONES RESTAURADO";
        system("pause>nul");
        system("cls");
        SubMenuConfiguracion();
            break;

        case 4: RestaurarBackUpInterpretes();
                recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                gotoxy(43,6);
                textcolor(cAMARILLO);
        cout<<"ARCHIVO DE INTERPRETES RESTAURADO";
        system("pause>nul");
        system("cls");
        SubMenuConfiguracion();
            break;

        case 5: RestaurarBackUpCancionesINICIO();
                RestaurarBackUpInterpretesINICIO();
                recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                gotoxy(43,6);
                textcolor(cAMARILLO);
        cout<<"DATOS DE INICIO ESTABLECIDOS";
        system("pause>nul");
        system("cls");
        SubMenuConfiguracion();

            break;

        case 0: return;
            break;

            default:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
                    gotoxy(50,6);
                    textcolor(cAMARILLO);
                    cout<<"OPCION INCORRECTA";
                    system("pause>nul");
                    system("cls");
                    SubMenuConfiguracion();
}

}


#endif // SUBMENUES_H_INCLUDED
