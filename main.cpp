#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

/// Lisandro Jimenez. Lo hice Individual.

using namespace std;
#include"rlutil.h"
#include "SubMenues.h"
#include "funciones.h"
#include "class.h"

int main(){

    int opc;
    while (true){
    recuadro(25, 3, 67, 16, cROJO_CLARO, cNEGRO);
    textcolor(cAMARILLO);

      gotoxy(53,7);
      cout<<"MENU PRINCIPAL"<<endl;
      gotoxy(43,8);
      cout<<"--------------------------------"<<endl;
      gotoxy(43,9);
      cout<<"1) MENU CANCIONES"<<endl;
      gotoxy(43,10);
      cout<<"2) MENU INTERPRETES"<<endl;
      gotoxy(43,11);
      cout<<"3) REPORTES"<<endl;
      gotoxy(43,12);
      cout<<"4) CONFIGURACION"<<endl;
      gotoxy(43,13);
      cout<<"--------------------------------"<<endl;
      gotoxy(43,14);
      cout<<"0) FIN DEL PROGRAMA"<<endl;
      gotoxy(27,17);
      cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
      cin>>opc;
      clrscr();
  switch(opc){

  case 1: SubMenuCanciones();

         break;

  case 2: SubMenuInterpretes();
         break;

  case 3: SubMenuReportes();
         break;

  case 4: SubMenuConfiguracion();
         break;

  case 0:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
         gotoxy(50,6);
         textcolor(cAMARILLO);
         cout<<"FIN DEL PROGRAMA"<<endl;
         gotoxy(1,20);
         return 0;
         break;

  default:recuadro(25, 3, 67, 6, cROJO_CLARO, cNEGRO);
          gotoxy(50,6);
          textcolor(cAMARILLO);
          cout<<"OPCION INCORRECTA";
          system("pause>nul");
          system("cls");
    }
   }
    cout<<endl;
    system("pause>nul");
    return 0;
}
