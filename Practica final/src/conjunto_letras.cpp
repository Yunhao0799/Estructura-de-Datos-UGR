#include "conjunto_letras.h"


conjunto_letras::conjunto_letras(){

}

set<letras> conjunto_letras::getLetters() const{
    return this -> letters; 
}

void conjunto_letras::push(const letras &l){
    this -> letters.insert(l);
}

void conjunto_letras::push(const char c, const int t, const int p){
    this -> letters.insert(letras(c, t, p));
}

/*
set<letras>::iterator conjunto_letras::begin(){
    return this -> letters.begin();
}

set<letras>::const_iterator conjunto_letras::begin(){
    return this -> letters.begin();
}

set<letras>::iterator conjunto_letras::end(){
    return this -> letters.end();
}

set<letras>::const_iterator conjunto_letras::end(){
    return this -> letters.end();
}*/

istream& operator>>(istream &is, conjunto_letras &c){
    letras aux;
    string data;
    getline(is, data); // skip reading the first line
    while(!is.eof()){
        is >> aux;

        c.push(aux);
    }

    return is;
}

ostream& operator<<(ostream &os, const conjunto_letras &c){
    cout << "******Puntuaciones Letras*******\n";
    set<letras> aux = c.getLetters();
    for(auto it = aux.begin(); it != aux.end(); it++){
        os << *it << endl;
    }

    os << endl;

    return os;
}

int conjunto_letras::puntuacion(const string &word1, char game_mode)const{
    int points = 0;
    if(game_mode == 'P'){
        string word = word1;
        for(unsigned int i = 0; i < word.size(); i++){
            for(auto it = letters.begin(); it != letters.end(); it++){
                word[i] = toupper(word[i]);
                if((*it).getLetter() == word[i])
                    points += (*it).getPoints();
            }
        }
    }
    else
        points = word1.size();

    return points;
}

void conjunto_letras::print_ai_solutions(const vector<string> ai_solutions, const char game_mode){
    map<int, string> to_print;
    for(unsigned int i = 0; i < ai_solutions.size(); i++){
        int points = puntuacion(ai_solutions[i], game_mode);
        to_print[points] = ai_solutions[i];
    }

    for(auto it = to_print.rbegin(); it != to_print.rend(); it++){
        if((*it).first != 0)
            cout << (*it).second << "   Puntuacion: " << (*it).first << endl;
    }

    cout << endl;

    cout << "Mejor solucion: " << (*to_print.rbegin()).second << endl; 
}