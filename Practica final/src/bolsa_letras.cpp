#include "bolsa_letras.h"


bolsa_letras::bolsa_letras(){

}

bolsa_letras::bolsa_letras(const conjunto_letras &c){
    
    set<letras> aux = c.getLetters();
    for(auto it = aux.begin(); it != aux.end(); it++){
        int n = (*it).getTimes();
        /*for(int i = 0; i < n; i++)
            values.push_back((*it).getLetter());*/
        values[(*it).getLetter()] = n;
    }
}

/*void bolsa_letras::insert(const conjunto_letras &c){
    set<letras> aux = c.getLetters();
    for(auto it = aux.begin(); it != aux.end(); it++){
        int n = (*it).getTimes();
        for(int i = 0; i < n; i++)
            values.push_back((*it).getLetter());
    }
}*/

map<char, int> bolsa_letras::getAll() const{
    return values;
}

ostream& operator<<(ostream &os, const bolsa_letras &b){
    /*vector<char> aux = b.getAll();
    for(int i = 0; i < aux.size(); i++)
        os << aux[i] << endl;*/

    map<char, int> aux = b.getAll();
    for(auto it = aux.begin(); it != aux.end(); it++)
        os << (*it).first << "  " << (*it).second << endl;

    return os;
}

string bolsa_letras::letters_generator(int quantity){
    int already_generated = 0;
    map<char, int> aux = values;
    string out;
    random_device rd;
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis('A', 'Z');
    char generated_char;//, previous_generated = 'A' + rand()%26;;
    while(already_generated != quantity){
        srand (time(NULL));
        generated_char = dis(gen);
        
        if(aux[generated_char] > 0){
            out.push_back(generated_char);
            aux[generated_char]--;
            already_generated++;
        }
    }

    return out;
}
