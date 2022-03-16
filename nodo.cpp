#include "nodo.h"
#include "cstring"
#include<bits/stdc++.h> 
#include <vector>
    nodo::nodo( const char*_nombre)
    {
        nombre = new char[strlen(_nombre)];
        strcpy(nombre,_nombre);
         anterior=0;
        siguiente=0;
    }
//imprime de forma recursiva la letra con sus nombres desde el inicio
void imprimir(nodo** raiz){
  nodo*temp=(*raiz);
  std::string str;
  int i=0;
std::string lista[sizeof(&(*raiz))];
  while(temp!=nullptr)
  {
     
     lista[i]=temp->nombre;
      i++;

      temp=temp->siguiente;
  
  }
        //sort
       
        std::sort(begin(lista),end(lista));
        std::cout<<"\nlista : ";
        for(int i = 0; i <sizeof(&(*raiz)); i++){
            
        std::cout << lista[i]<<" ";      
    }
}
//inserta un nuevo nodo con el nombre de forma ordenada y no agregar el mismo
void insertar(nodo**raiz,const char*_nombre)
{
   
        if (*raiz == 0)
    {
         
           
              nodo*nuevo=new nodo(_nombre);
             *raiz=nuevo;
     
}
      else 
    {
         
                 if (strcmp(_nombre,(*raiz)->nombre)!=0)
     {
               insertar(&(*raiz)->siguiente, _nombre);
     }
        }

}




//elimina el nodo con el valor del nombre
void eliminar(nodo**raiz,const char*valor)
{
    if (*raiz==0)
    {
        /* code */
        return;
    }
    
    
  if (strcmp(valor,(*raiz)->nombre)==0){
        std::cout<<"\n existe borrando cadena "<<((*raiz)->nombre)<<"\n";
         delete (*raiz)->nombre; return;        }
        else { buscar(&(*raiz)->siguiente,valor);
        }
       
}


//busca el nodo con el nombre
bool buscar(nodo**raiz,const char*_nombre)
{
    nodo*actual=(*raiz);
   /* 
  return false;*/
       if (strcmp(_nombre,(*raiz)->nombre)==0){
        std::cout<<"\n existe "<<_nombre<<"\n";
        return true;
        }
        else if(*raiz!=0){
        buscar(&(*raiz)->siguiente,_nombre);}
    
    
     return false;
    

}
void imprimirRecursivo(nodo**raiz)
{
    if(*raiz==0){
        return;
    }else{
        std::cout<<"["<<(*raiz)->nombre<<"]";
        imprimir(&(*raiz)->siguiente);
      
    }
}