#include "estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

void Disco::leerArchivogcc(){
    //ifstream para leer archivos de texto
    ifstream archivo("src\\gcc.trace",ios::in);

    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Consulta Datos********\n\n";

    cout<<"Ruta: "<<"\t\t"<<"Operacion: "<<"\n";

    while(getline(archivo,palabra,' ')){
        cout<<palabra<<"\t\t";
    }

    archivo.close();
}

void Disco::leerArchivobzip(){
    
    ifstream archivo("src\\bzip.trace",ios::in);

    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Consulta Datos********\n\n";

    cout<<"Ruta: "<<"\t\t"<<"Operacion: "<<"\n";

    while(getline(archivo,palabra,' ')){
        cout<<palabra<<"\t\t";
    }

    archivo.close();
}
#include <chrono>
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
          //cout<<strData<<endl;
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

/*void Disco::hashTable(){
     for(int i = 0; i < vector1.size(); i++)
        ht.insertElement(i, vector1[i]);

    cout<<"\nCargado a hashtable exitoso total de valores: "<<ht.Size()<<endl;
}*/
void Disco::printAll(){
     using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
     const char separator    = '\t';
    const int nameWidth     = 6;
    const int numWidth      = 8;
    int cont=0;
    for(int i=0;i<vector1.size();i++){
         cout << left << setw(nameWidth) << setfill(separator) << "  "+vector1[i];
         cont++;
         if(cont==9){
             cout<<endl;
             cont=0;
         }
    }
    
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_double.count()/1000 << " segundos\n";
}
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
void Disco::simular()
{
    cout<<"\nIngrese La cantidad de veces que desea simular: ";
    int cant;
    cin>>cant;
    int random;
    const char separator    = ' ';
    const int nameWidth     = 6;
    const int numWidth      = 8;
     int cont=0;
    for (int i = 0; i < cant; i++)
    {
         random = rand() % vector1.size() + 1;
         cout<<"[Pos: ";
         cout << left << setw(nameWidth) << setfill(separator) << random;
         cout << left << setw(nameWidth) << setfill(separator) <<"Dir: ";
         cout << left << setw(nameWidth) << setfill(separator) << vector1[random];
         cout<<"]";
        
         cont++;
         if(i==cant-1){
             cout<<endl;
             cont=0;
             break;
         }
         if(cont==3){
             cout<<endl<<endl;
             cont=0;
         }else{
             cout<<"->";
         }
      
    }
    cout<<endl<<endl;
}