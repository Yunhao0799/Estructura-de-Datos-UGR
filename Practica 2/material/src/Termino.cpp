#include "Termino.h"
#include <string>
#include<iostream>
using namespace std;

Termino::Termino(){
    
}

Termino::Termino(string palabra, Vector_Dinamico<string> def){
    this -> palabra = palabra;
    this -> definicion = def;
}

Termino::Termino(Termino &otra){
    this -> palabra = otra.getPalabra();
    this -> definicion =  otra.getDefinicionesAsociadas();
}

string Termino::getPalabra() const{
    return palabra;
}

Vector_Dinamico<string> Termino::getDefinicionesAsociadas() const{
    return definicion;
}

int Termino::getNAsociados() const{
    return definicion.size();
}

void Termino::setPalabra(string palabra){
    this -> palabra = palabra;
}

void Termino::setDefiniciones(Vector_Dinamico<string> defini){
    int tam_or = definicion.size(), tam_n = defini.size();
    definicion.resize(tam_or + tam_n);
    int i, j = 0;
    for(i = tam_or; i < definicion.size(); i++){
        definicion[i] = defini[j];
        j++;
    }

}



istream& Termino::operator>>(istream &is, const Termino &t){
    string term;
    Vector_Dinamico<string> definiciones(1);

    getline(is, term, ';');
    getline(is, definiciones[0]);

    Termino aux(term, definiciones);
    t = aux;

    return is;
}

ostream& operator<<(ostream &os, const Termino &t){
    os << t.getPalabra() << endl;
    for(int i = 0; i < t.getDefinicionesAsociadas().size(); i++){
        os << " " << t.getDefinicion(i) << endl;
    }
}

string Termino::getDefinicion(int index) const{
    return definicion[index];
}
