#include "estructuras.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
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
    ifstream archivo("gcc.trace",ios::in);

    if(!archivo){
        cout<<"Error al abrir el archivo!"<<endl;
        return;
    }
    string palabra="0";
    cout<<"*********Cargando Datos********\n\n";

    while(getline(archivo,palabra,'\n')){
        //cout<<palabra<<"\t\t";
        vector1.push_back(palabra);
    }
    archivo.close();

      for (decltype(vector1.size()) i = 0; i <= vector1.size() - 1; i++)
    {
        cout << vector1[i] << endl;
    }
      auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_double.count()/1000/60 << " minutos\n";

}
