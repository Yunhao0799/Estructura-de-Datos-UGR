#ifndef Diccionario_h
#define Diccionario_h


#include "Termino.h"
#include <string>
#include<iostream>
#include "Vector_Dinamico.h"
using namespace std;

class Diccionario{
    private:
        Vector_Dinamico<Termino> terminos;
    
    public:
        //constructor de por defecto
        Diccionario();

        //constructor por parametros
        Diccionario(Termino);

        //constructor de copia
        Diccionario(Diccionario&);

        //getters
        Vector_Dinamico<string> getDefinicionesPalabra(Termino) const;

        Vector_Dinamico<Termino> getAllTerms() const;
        
        int getNumTerminos() const;

        //setters
        void setNewTerm(Termino);

        void eliminarTermino(Termino);

        //metodo que nos devuelve la posicion a la que se encuentra un termino
        int buscarTermino(Termino);
        
        friend istream& operator>>(istream &is, const Diccionario &d);

        friend ostream& operator<<(ostream &os, const Diccionario &d);
};

#endif