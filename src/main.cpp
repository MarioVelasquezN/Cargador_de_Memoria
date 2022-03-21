#include <iostream>
#include <stdio.h>
#include "estructuras.h"

using namespace std;

int main(){
    Disco d;
    //d.leerArchivogcc();
    d.cargarArchivo();
    //d.hashTable();
   
    int op;
    do
    {

        cout<<"Funciones Funcionales"<<endl;
        cout<<"1.\tLeer archivos de gcc.trace"<<endl;
        cout<<"2.\tleer archivos de bzip.trace"<<endl;
        cout<<"3.\tBuscar"<<endl;
        cout<<"4.\tPrint all"<<endl;
        cout<<"5.\tSimular"<<endl;
        cout<<"6.\tSalir"<<endl;

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
        {
            int opcion;
            cout<<"\n1. read\n2. write "<<endl;
            cin>>opcion;
            if(opcion==1){
                d.buscar();
            }
            else if(opcion==2){
                d.writeDir();
            }
            else{
                cout<<"Opcion no valida"<<endl;
            }
            break;
        }
        case 4:
            d.printAll();
            break;
        case 5:
            d.simular();
            break;
        case 6:
            cout<<"Salir!!"<<endl;
            break;
       
        default:
            break;
        }
    } while (op!=6);
}