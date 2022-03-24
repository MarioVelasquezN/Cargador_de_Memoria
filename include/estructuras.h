#ifndef ESTRUCUTRAS_H
#define ESTRUCTURAS_H
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;
struct metadata{
    char dato[7];
    char operacion;
};
struct Ht_item {
    //* key;
    string value;
};
#include <iostream>
#include <list>

using namespace std;

class HashTable{
private:
  list<string> *table;
  int total_elements;

  // Hash function to calculate hash for a value:
  int getHash(int key){
    return key % total_elements;
  }

public:
  // Constructor to create a hash table with 'n' indices:
  HashTable(int n){
    total_elements = n;
    table = new list<string>[total_elements];
  }

  // Insert data in the hash table:
  void insertElement(int key, string value){
    table[getHash(key)].push_back(value);
  }

  void printAll(){
    // Traverse each index:
    for(int i = 0; i < total_elements; i++){
      cout << "Index is: " << i << ": ";

    cout << endl;
    }
  }
  int Size(){
    return total_elements;
  }
};


class Disco{

public:
    metadata m;
    vector<string> vector1;
    //HashTable ht;
    void buscar();
    void leerArchivogcc();
    void leerArchivobzip();
    void cargarArchivo();
    void escribirArchivo();
    void writeDir();
    //void hashTable();
    void printAll();
    void simular();
};

#endif