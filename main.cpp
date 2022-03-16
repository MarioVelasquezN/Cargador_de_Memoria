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
        cout<<"1.Leer archivos de gcc.trace"<<endl;
        cout<<"2.leer archivos de bzip.trace"<<endl;
        cout<<"3. Aqui va el cargar archivos de marco"<<endl;
        cout<<"4.aqui va el hastable de Rodrigo"<<endl;
        cout<<"Selecciones su opcion: "<<endl;
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