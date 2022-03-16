#include "estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "nodo.h"
using namespace std;

void Disco::leerArchivogcc(){
    //ifstream para leer archivos de texto
    ifstream archivo("gcc.trace",ios::in);

    // while(!archivo.eof()){
    //     archivo>>m.dato>>m.operacion;
    //     cout<<m.dato<<endl;
    //     cout<<m.operacion<<endl;
    // }
    // archivo.close();

    // system("pause");
    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Consulta Datos********\n\n";

    cout<<"Ruta: "<<"\t\t"<<"Operacion: "<<"\n";

  

    while(getline(archivo,palabra,' ')){
        nodo*prueba=0;
        const char*b=palabra.c_str();
        insertar(&prueba,b);
       // cout<<palabra<<"\t\t";
        sleep(2);
    }

    archivo.close();
    imprimir(&prueba);
}
//function to mount gcc.trace
void Disco::cargarArchivo(){
    ifstream archivo("gcc.trace",ios::in);
    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Carga Datos********\n\n";

    cout<<"Ruta: "<<"\t\t"<<"Operacion: "<<"\n";

    while(getline(archivo,palabra,' ')){
        cout<<palabra<<"\t\t";
        sleep(2);
    }

    archivo.close();
}

void Disco::leerArchivobzip(){
    
    ifstream archivo("bzip.trace",ios::in);

    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Consulta Datos********\n\n";

    cout<<"Ruta: "<<"\t\t"<<"Operacion: "<<"\n";

    while(getline(archivo,palabra,' ')){
        cout<<palabra<<"\t\t";
        sleep(2);
    }

    archivo.close();
}