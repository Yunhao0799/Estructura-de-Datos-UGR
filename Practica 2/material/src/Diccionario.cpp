#include "Diccionario.h"
#include "Termino.h"
#include <string>
#include<iostream>
using namespace std;

Diccionario::Diccionario(){

}

Diccionario::Diccionario(Termino termino){
    terminos[0] = termino;
}

Diccionario::Diccionario(Diccionario &otra){
    terminos = otra.getAllTerms();
}

Vector_Dinamico<string> Diccionario::getDefinicionesPalabra(Termino buscado) const{
    Vector_Dinamico<string> salida;

    for(int i = 0; i < terminos.size(); i++){
        if(terminos[i].getPalabra == buscado.getPalabra)
            salida = terminos[i].getDefinicionesAsociadas();
    }
    return salida;
}

Vector_Dinamico<Termino> Diccionario::getAllTerms() const{
    return terminos;
}

int Diccionario::getNumTerminos() const{
    return terminos.size();
}

void Diccionario::setNewTerm(Termino nuevo){
    int pos = buscarTermino(nuevo);

    terminos.resize(terminos.size() + 1);

    for(int i = terminos.size() - 1; i > pos; i--)
        terminos[i] = terminos[i - 1];
    
    terminos[pos] = nuevo;
    
}

void Diccionario::eliminarTermino(Termino eliminar){
    int pos = buscarTermino(eliminar);

    for(int i = pos; i < terminos.size() - 1; i++)
        terminos[i] = terminos[i + 1];
    
    terminos.resize(terminos.size() - 1);
}

int Diccionario::buscarTermino(Termino nuevo){
    int centro = 0, inf = 0, sup = terminos.size() - 1, pos = -1;

    
    while(inf <= sup){
        centro = ((sup - inf)/2) + inf;
        if(terminos[centro].getPalabra() == nuevo.getPalabra())
            pos = centro;
        else if (nuevo.getPalabra() < terminos[centro].getPalabra())
            sup = centro - 1;
        else 
            inf = centro + 1;

    }

    return pos;
}


istream& Diccionario::operator>>(istream &is, const Diccionario &d){
    Termino este, siguiente;
    is >> este;
    while(!is.eof()){
        is >> siguiente;
        while(siguiente.getPalabra() == actual.getPalabra()){
            este.setDefiniciones(siguiente.getDefiniciones());
            is >> siguiente;    
        }
        terminos.setNewTerm(actual);
        if(!is.eof())
            actual = siguiente;
    }

    return is;
}

ostream& operator<<(ostream &os, const Diccionario &d){
    for(int i = 0; i < terminos.size(); i++)
        os << terminos[i];
    
    return os;
}