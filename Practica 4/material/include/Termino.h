#ifndef Termino_h
#define Termino_h

#include <string>
#include<iostream>
#include <vector>
using namespace std;

class Termino{
    private:
        pair<string, vector<string> >  termino;
    public:
        //constructor por defecto
        Termino();

        //contructor por parametros
        Termino(pair<string, vector<string> >);

        //constructor de copia
        Termino(Termino&);

        //Getters
        string getPalabra() const;
        
        vector<string> getDefinicionesAsociadas() const;

        int getNAsociados() const;

        string getDefinicion(int) const;


        //setters
        void setPalabra(string);

        void setDefiniciones(vector<string> defini);

        

        friend istream& operator>>(istream &is, const Termino &t);

        friend ostream& operator<<(ostream &os, const Termino &t);
};

#endif