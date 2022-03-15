#include "estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void Disco::leerArchivo(){
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
        cout<<palabra<<"\t\t";
        sleep(2);
    }

    archivo.close();
}