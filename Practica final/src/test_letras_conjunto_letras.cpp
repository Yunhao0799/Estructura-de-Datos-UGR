#include <iostream>
#include "conjunto_letras.h"
#include<fstream>

using namespace std;

int main(int argc, char *argv[]){
    conjunto_letras c;

    if(argc != 2){
        cout << "Introduzca el nombre del fichero \n";
    }

    ifstream archivo(argv[1]);

    if(!archivo){
        cout << "No se pudo abrir el fichero \n";
        return 0;
    }

    cout << "introduciendo datos \n";
    archivo >> c;

    cout << "mostrando datos \n";
    cout << c;

    cout << "La palabra introducida vale: " << c.puntuacion("zab") << " puntos\n";


}