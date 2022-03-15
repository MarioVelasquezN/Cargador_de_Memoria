#ifndef ESTRUCUTRAS_H
#define ESTRUCTURAS_H

struct metadata{
    char dato[7];
    char operacion;
};

class Disco{
public:
    metadata m;
    void leerArchivo();
    void cargarArchivo();
    
    void escribirArchivo();
};

#endif