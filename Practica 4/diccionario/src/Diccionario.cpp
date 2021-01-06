#include "Diccionario.h"
#include<iostream>
#include<fstream>



Diccionario::Diccionario(){

}


Diccionario::Diccionario(const Termino& nuevo){
    //Recordamos que los elementos del set son unicos, es decir solo puede
    //existir una vez
    (this -> terminos).insert(nuevo);
}


Diccionario::Diccionario(const Diccionario& otra){
    (this -> terminos) = otra.getAllTerms();
}


vector<string> Diccionario::getDefinicionesPalabra(Termino aBuscar) const{
    auto it = (this -> terminos).find(aBuscar);
    return (*it).getDefinicionesAsociadas();
}


set<Termino> Diccionario::getAllTerms() const{
    return this -> terminos;
}


int Diccionario::getNumTerminos() const{
    return terminos.size();
}


void Diccionario::setNewTerm(Termino nuevo){/*
    if((this -> terminos).find() == terminos.end()){ //si no lo encuentra
        bool encontrado = 0;
        Diccionario::iterator aux;
        for(auto it = terminos.begin(); it != terminos.end() && !encontrado; ++it){
            aux = it;
            if(*it == nuevo){
                encontrado = 1;
            }

        }

        terminos.insert(aux, nuevo);
    }
    else    cout << "Este elemento ya existe \n";*/

    //Recordamos que los set se autordenan y son unicos, es decir, un elemento
    //una y solamente una vez
    terminos.insert(nuevo);
}


void Diccionario::eliminarTermino(Termino borrar){
    (this -> terminos).erase(borrar);
}


istream& operator>>(istream &is, Diccionario &d){
    Termino este, siguiente;
    is >> este;
    while(!is.eof()){
        is >> siguiente;
        while(siguiente.getPalabra() == este.getPalabra()){
            este.setDefiniciones(siguiente.getDefinicionesAsociadas());
            is >> siguiente;    
        }
        d.setNewTerm(este);
        if(!is.eof())
            este = siguiente;
    }

    return is;
}


ostream& operator<< (ostream & os, const Diccionario & d){
    Diccionario::const_iterator it;
    for(it = d.begin(); it != d.end(); ++it){
        os << *it;
    }
    
    return os;
}

Diccionario::iterator Diccionario::begin(){
    return (this -> terminos).begin();
}

Diccionario::const_iterator Diccionario::begin() const{
    return (this -> terminos).begin();
}

Diccionario::iterator Diccionario::end(){
    return (this -> terminos).end();
}

Diccionario::const_iterator Diccionario::end() const{
    return (this -> terminos).end();
}

Diccionario Diccionario::filtroIntervalo(const string inicio, const string fin){
    Diccionario::const_iterator it = terminos.begin();
    Diccionario salida;
    while(((it -> getPalabra()) >= inicio) && ((it -> getPalabra()) <= fin) && (it != terminos.end())){
        salida.setNewTerm(*it);
        it++;
    }

    return salida;
}

Diccionario Diccionario::subsecuencia(const string &clave){
    Diccionario salida;
    Diccionario::const_iterator it;
    vector<string>::const_iterator it_terminos;
    for(it = terminos.begin(); it != terminos.end(); it++){
        bool encontrado = 0;
        for(it_terminos = (*it).begin(); it_terminos != (*it).end() && !encontrado; it_terminos++){
            if((*it_terminos).find(clave) != string::npos)
                encontrado = true;
        }
            
            
        if(encontrado)
            salida.setNewTerm(*it);
        
    }
    return salida;
}

void Diccionario::recuento(double &totalDefiniciones, double& maxDefiniciones, double& promedio){
    totalDefiniciones = 0;
    maxDefiniciones = 0;
    for(Diccionario::const_iterator it = terminos.begin(); it != terminos.end(); it++){
        totalDefiniciones += (*it).getNAsociados();
        if((*it).getNAsociados() > maxDefiniciones)
            maxDefiniciones = (*it).getNAsociados();
    }

    promedio = totalDefiniciones/(getNumTerminos() * 1.0);
}
