#ifndef ESTRUCUTRAS_H
#define ESTRUCTURAS_H
#include <string>
#include <vector>
using namespace std;
struct metadata{
    char dato[7];
    char operacion;
};

class Disco{

public:
    metadata m;
    vector<string> vector1;

    void leerArchivogcc();
    void leerArchivobzip();
    void cargarArchivo();
    void escribirArchivo();
};

#endif