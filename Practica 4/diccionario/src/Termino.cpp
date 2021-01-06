#include "Termino.h"
#include<iostream>
#include<fstream>


Termino::Termino(){
}


Termino::Termino(pair<string, vector<string> > termino){
    this -> termino = termino;
}


Termino::Termino(const Termino& otra){
    string aux = otra.getPalabra();
    (this -> termino).first = aux;
    vector<string> aux2 = otra.getDefinicionesAsociadas();
    (this -> termino).second = aux2;
}



string Termino::getPalabra() const{
    return (this -> termino).first;
}

 
vector<string> Termino::getDefinicionesAsociadas() const{
    return (this -> termino).second;
}


int Termino::getNAsociados() const{
    vector<string> aux = (this -> termino).second;
    return aux.size();
}

//string getDefinicion(int) const;



void Termino::setPalabra(const string palabra){
    (this -> termino).first = palabra;
}


void Termino::setDefiniciones(const vector<string> defini){
    for(vector<string>::const_iterator it = defini.begin(); it != defini.end(); it++)
        (this -> termino).second.push_back(*it);
}


ostream& operator<< (ostream & os, const Termino & t){
    Termino::const_iterator it;
    os << t.termino.first ;
    os << "\n\n";
    int i = 1;
    for(it = t.begin(); it != t.end(); ++it){
        os << "  " << i << ". " << (*it) << endl;
        i++;
    }
    os << "\n\n\n";

    return os;
}

istream& operator>>(istream &is, Termino &t){
    string term;
    vector<string> definiciones(1);

    getline(is, term, ';');
    getline(is, definiciones[0]);

    Termino aux(make_pair(term, definiciones));
    t = aux;

    return is;
}


bool Termino::operator==(const Termino& otra) const{
    bool es_igual = true;
    if(termino.first != otra.getPalabra())
        es_igual = 0;
    if(termino.second.size() == otra.getNAsociados()){
        vector<string> de_otra = otra.getDefinicionesAsociadas();
        vector<string> esta = termino.second;
        for(int i = 0; i < termino.second.size() && es_igual; i++){
            if(esta[i] != de_otra[i])
                es_igual = 0;
        }
    }
    else    es_igual = 0;

    return es_igual;
}


bool Termino::operator<(const Termino& otra) const{
    return termino.first < otra.getPalabra();
}

bool Termino::operator<=(const Termino& otra) const{
    return termino.first <= otra.getPalabra();
}

vector<string>::iterator Termino::begin(){
    return termino.second.begin();
}


vector<string>::const_iterator Termino::begin() const{
    return termino.second.begin();
}

vector<string>::iterator Termino::end(){
    return termino.second.end();
}


vector<string>::const_iterator Termino::end() const{
    return termino.second.end();
}

bool Termino::operator>=(const Termino& otra) const{
    return termino.first >= otra.getPalabra();
}