#ifndef nodo_h
#define nodo_h

#include <iostream>
struct nodo{
    char * nombre;
    nodo * anterior;
    nodo * siguiente;
    nodo(const char*_nombre);
};  
    void insertar(nodo **,const char*);
    void imprimir(nodo **);
    bool buscar(nodo**,const char*);
    void eliminar(nodo**, const char*);
    void imprimirRecursivo(nodo**);
#endif