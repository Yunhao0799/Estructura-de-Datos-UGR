#ifndef Termino_h
#define Termino_h

#include <string>
#include<iostream>
#include "Vector_Dinamico.h"
using namespace std;

class Termino{
    private:
        string palabra;
        Vector_Dinamico<string> definicion;
    public:
        //constructor por defecto
        Termino();

        //contructor por parametros
        Termino(string, Vector_Dinamico<string>);

        //constructor de copia
        Termino(Termino&);

        //Getters
        string getPalabra() const;

        
        Vector_Dinamico<string> getDefinicionesAsociadas() const;

        int getNAsociados() const;

        string getDefinicion(int) const;


        //setters
        void setPalabra(string);

        void setDefiniciones(Vector_Dinamico<string> defini);

        

        friend istream& operator>>(istream &is, const Termino &t);

        friend ostream& operator<<(ostream &os, const Termino &t);
};

#endif