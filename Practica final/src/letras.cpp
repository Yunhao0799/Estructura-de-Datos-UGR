#include "letras.h"


letras::letras(char letter, int times, int points){
    this -> letter = letter;
    this -> time_can_be_appeared = times;
    this -> points = points;
}

letras::letras(){

}

char letras::getLetter() const{
    return letter;
}

int letras::getTimes() const{
    return time_can_be_appeared;
}

int letras::getPoints() const{
    return points;
}

istream& operator>>(istream &is, letras &l){
    char l1;
    int t, p;
    
    is >> l1 >> t >> p;

    l = letras(l1, t, p);

    return is;
}

ostream& operator<<(ostream &os, const letras &l){
    //os << l.getLetter() << "  	" << l.getTimes() << "      " << l.getPoints();
    os << l.getLetter() << "  	" << l.getPoints();
    return os;
}

bool letras::operator<(const letras &l) const{
    return (this -> letter) < l.getLetter();
}