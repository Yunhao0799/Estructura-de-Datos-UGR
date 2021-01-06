#include <iostream>
#include "lista_palabras.h"
#include<fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[] ){
    if(argc != 2){
        cout << "Falta introducir el archivo a leer \n";
    }

    ifstream archivo(argv[1]);

    if(!archivo){
        cout << "No se pudo abrir el fichero \n";
        return 0;
    }

    lista_palabras lista;
    archivo >> lista;

    //cout << lista;
        

    cout << "\n\n********************************************************************************************************\n\n";

    vector<string> v = lista.palabras_longitud(5);
    cout << "Palabras de longitud " << 5 << endl;
    for(unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << endl;


    /*BST<char, string> tree = lista.palabras_longitud_bst(5);
    cout << "\n\n********************************************************************************************************\n\n";

    cout << "Palabras de longitud 5, arbol" << endl;
    BST<char, string>::iterator i;
	for (i = tree.begin(); i != tree.end(); ++i)
	    cout << (*i).first << ": " << (*i).second << endl;*/

    cout << "Estado para la palabra dada, (0 no esta, 1 esta) , estado:       " << lista.esta("o") << endl;
}   