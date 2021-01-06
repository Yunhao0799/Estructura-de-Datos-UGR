#include "Diccionario.h"
#include <fstream>
#include <iostream>

using namespace std;

void imprimir(const Diccionario &mi_diccionario){
  //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
  Diccionario::const_iterator it; 
   for(it = mi_diccionario.begin(); it != mi_diccionario.end(); ++it){
     cout << (*it) << endl;
   }
}

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f>>mi_diccionario; //Cargamos en memoria el diccionario
   
   imprimir(mi_diccionario);
   
   
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    - Obtener las definiciones asociadas a una palabra   
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */
    cout << "*************************Prueba filtro por intervalo************************* \n";
    Diccionario dic1;
    cout << "\n \n ";
    dic1 = mi_diccionario.filtroIntervalo("a", "b");
    imprimir(dic1);
    cout << "\n \n \n";

    cout << "*************************Prueba filtro por palabra dada************************* \n";
    cout << "\n \n ";
    Diccionario dic2;
    dic2 = mi_diccionario.subsecuencia("Constantine");
    imprimir(dic2);
    cout << "\n \n \n";

    double definiciones, maximo;
    double media;
    mi_diccionario.recuento(definiciones, maximo, media);
    cout << "Total de definiciones: " << definiciones << endl;
    cout << "Maximo de definiciones: " << maximo << endl;
    cout << "Promedio de definiciones: " << media << endl;
}


