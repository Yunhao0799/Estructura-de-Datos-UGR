#ifndef Diccionario_h
#define Diccionario_h


#include "Termino.h"
#include <string>
#include<iostream>
#include<set>
using namespace std;

class Diccionario{
    private:
        set<Termino> terminos;
    
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

        //filtro por intervalo
        Diccionario filtroIntervalo(string ini, string fin)

        //dado una palabra clave, se devuelve diccionario con palabras que en su definicion aparezca
        //la palabra clave
        Diccionario subsecuencia(string a_buscar);

        void recuento(double &totalDefiniciones, double &maxDefiniciones, double &promedio)
};

#endif