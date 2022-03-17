#include <iostream>
#include <stdio.h>
#include "estructuras.h"

using namespace std;

int main(){
    Disco d;
    //d.leerArchivogcc();
   
    int op;
    do
    {
        cout<<"Funciones Funcionales"<<endl;
        cout<<"1.\tLeer archivos de gcc.trace"<<endl;
        cout<<"2.\tleer archivos de bzip.trace"<<endl;
        cout<<"3.\tCargar a memoria"<<endl;
        cout<<"4.\taqui va el hastable de Rodrigo"<<endl;
        cout<<"5.\tSalir"<<endl;
        cout<<"\t\tSelecciones su opcion: "<<endl;
        cin>>op;

        switch (op)
        {
        case 1:
            d.leerArchivogcc();
            break;

        case 2:
            d.leerArchivobzip();
            break;

        case 3:
            cout<<"Aqui va lo de marco"<<endl;
             d.cargarArchivo();
            break;

        case 4:
            cout<<"Aqui lo de Rodrigo"<<endl;
            break;

        case 5:
            cout<<"Salir!!"<<endl;
            break;

        default:
            break;
        }

    } while (op!=5);

}