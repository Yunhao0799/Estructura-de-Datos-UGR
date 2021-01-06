#include<iostream>
#include<fstream>
#include "bolsa_letras.h"
#include "lista_palabras.h"
#include <map>

using namespace std;

int main(int argc, char *argv[]){
    /**
        prompt% cantidad_letras spanish letras.txt salida.txt

        1. El nombre del fichero con lista_palabras
        2. El nombre del fichero con las letras 
        3. El fichero donde escribir el conjunto de letras con la cantidad de apariciones calculada
    */
    ifstream archivo_lista_palabras(argv[1]);
    ifstream archivo_letras(argv[2]);
    ofstream archivo_salida(argv[3]);

    if(argc != 4){
        cout << "Falta argumentos \n";
        return 0;
    }

    if(!archivo_lista_palabras){
        cout << "No se pudo abrir " << argv[1] << endl;
        return 0;
    }

    if(!archivo_letras){
        cout << "No se pudo abrir " << argv[2] << endl;
        return 0;
    }

    
    conjunto_letras letras;
    archivo_letras >> letras;

    lista_palabras diccionario;
    archivo_lista_palabras >> diccionario;

    map<char, double> values;

    int total_chars = 0;
    diccionario.count(values, total_chars);

    archivo_salida << "#Letra Frecuencia \n";
    for(auto it = values.begin(); it != values.end(); it++){
        (*it).second = ((*it).second/(total_chars * 1.0)) * 100;
        archivo_salida << "   " << (*it).first << "       " << (*it).second<< endl;
    }

}