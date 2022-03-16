#ifndef ESTRUCUTRAS_H
#define ESTRUCTURAS_H

struct metadata{
    char dato[7];
    char operacion;
};

class Disco{
public:
    metadata m;
    void leerArchivogcc();
    void leerArchivobzip();
    void cargarArchivo();
    
    void escribirArchivo();
};

#endif