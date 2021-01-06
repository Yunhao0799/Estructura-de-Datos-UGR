#include "Termino.h"

/**
 * @brief Constructor por defecto
 */

Termino::Termino(){
}

/**
 * @brief Constructor por parametros
 */

Termino::Termino(pair<string, vector<string> > termino){
    this -> termino = termino;
}

/**
 * @brief Constructor de copia
 */

Termino::Termino(const Termino& otra){
    string aux = otra.getPalabra();
    (this -> termino) -> first = aux;
    vector<string> aux2 = otra.getDefinicionesAsociadas();
    (this -> termino) -> second = aux2;
}