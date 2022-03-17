#include "estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

void Disco::leerArchivogcc(){
    //ifstream para leer archivos de texto
    ifstream archivo("src\\gcc.trace",ios::in);

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
        Sleep(2);
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
        Sleep(2);
    }

    archivo.close();
}
#include <chrono>

/* Only needed for the sake of this example. */
#include <iostream>
#include <thread>

void Disco::cargarArchivo()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
   
     //ifstream para leer archivos de texto
    ifstream archivo("src\\gcc.trace",ios::in);

    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Cargando Datos********\n\n";
       cout<<"Cargando datos..."<<"\n";
    while(getline(archivo,palabra,'\n')){
        //cout<<palabra<<"\t\t";
        vector1.push_back(palabra);
        if(vector1.size()==500000){
            cout<<"50%"<<"\n";
        }
    }
    cout<<"100%"<<"\n";
    archivo.close();
    cout<<"Cargandos exitosamente"<<"\n";
    
      auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_double.count()/1000 << " segundos\n";

}
void Disco::buscar(){
    int pos;
    cout<<"Size: "<<vector1.size()<<endl;
    cout<<"Ingrese el dato a buscar: ";
    cin>>pos;
    bool encontrado=false;
    char* dato=new char[8];
    string strData="";
    for(int i=0;i<vector1.size();i++){
        if(i==pos){
            cout<<"El dato se encuentra en la posicion: "<<i<<endl;
            cout<<vector1[i]<<endl;
            encontrado=true;
            for(int j=0;j<8;j++){
                dato[j]=vector1[pos][j];
            }
             for(int j=0;j<8;j++){
                  strData+=dato[j];
            }
          cout<<strData<<endl;
            break;
        }
    }
    if(!encontrado){
        cout<<"El dato no se encuentra en el vector"<<endl;
    }
}
void Disco::writeDir(){
    int pos;
    cout<<"Size: "<<vector1.size()<<endl;
    cout<<"Ingrese el dato a buscar: ";
    cin>>pos;
    bool encontrado=false;
    for(int i=0;i<vector1.size();i++){
        if(i==pos){
            cout<<"El dato se encuentra en la posicion: "<<i<<endl;
            cout<<vector1[i]<<endl;
            encontrado=true;
            char w = 'W';
            cout<<"wtf: "<<vector1[i][9]<<endl;
            if(w==vector1[i][9]){
                cout<<"Se modifico el valor de esa dir"<<endl;
                vector1[i]="00000000 M";
                cout<<"\n En la direccion: "<<&vector1[i]<<endl;
            }
            break;
        }
    }
    if(!encontrado){
        cout<<"El dato no se encuentra en el vector"<<endl;
    }
}
