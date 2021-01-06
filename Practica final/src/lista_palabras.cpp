#include "lista_palabras.h"

lista_palabras::lista_palabras(){

}

lista_palabras::lista_palabras(const lista_palabras &otra){
    this->diccionario = otra.get_all();
}

lista_palabras::lista_palabras(const string &palabra){
    diccionario.insert(palabra);
}

void lista_palabras::insert(const string &palabra){
    diccionario.insert(palabra);
}

void lista_palabras::erase(const string &palabra){
    diccionario.erase(palabra);
}

set<string> lista_palabras::get_all() const {
    return this->diccionario;
}

ostream& operator<<(ostream &os, const lista_palabras &l){
    for(set<string>::iterator it = l.begin(); it != l.end(); it++)
        os << *it << endl;

    return os;
}

istream& operator>>(istream &is, lista_palabras &l){
    string termino;
    while(!is.eof()){
        getline(is, termino);
        l.insert(termino);
    }
    
    return is;
}

set<string>::iterator lista_palabras::begin() const{
    return (this->diccionario).begin();
}

set<string>::iterator lista_palabras::end() const{
    return (this->diccionario).end();
}

set<string>::iterator lista_palabras::begin(){
    return (this->diccionario).begin();
}

set<string>::iterator lista_palabras::end(){
    return (this->diccionario).end();
}

vector<string> lista_palabras::palabras_longitud(const int &longitud) const{
    vector<string> out;
    for(auto it = diccionario.begin(); it != diccionario.end(); it++){
        if((unsigned)(*it).size() == (unsigned)longitud)
            out.push_back(*it);
    }

    return out;
}

bool lista_palabras::esta(const string& palabra) const{
    if(diccionario.find(palabra) != diccionario.end())
        return true;
    return false;
}

int lista_palabras::size() const{
    return diccionario.size();
}

/*BST<char, string> lista_palabras::palabras_longitud_bst(const int &longitud) const{
    BST<char, string> out;
    for(auto it = diccionario.begin(); it != diccionario.end(); it++){
        if((*it).size() == longitud){
            out.insert(pair<char, string>('a', (*it)));
        }
            
    }
}*/




bool operator<=(const map<char, int> &m1, const map<char, int> &m2){
			map<char, int> aux_m1 = m1, aux_m2 = m2;
    		bool less_equal = true;
    		
    		//if m1 have more elements than m2, that means that m1 have an letter 
			//that m2 does not have
    		
    		if(m1.size() > m2.size()){
    			less_equal = false;
    			return less_equal;
			} 
			
			for(char c = 'a'; c <= 'z' && less_equal; c++){
				if(aux_m1[c] > aux_m2[c])
					less_equal = false;
			}
			
			
    		return less_equal;
}

vector<string> lista_palabras::palabras_con_las_letras_dadas(const string &generated_char) const{
    //construimos el mapa del argumento
    string generated_chars = generated_char;
    for(unsigned int i = 0; i < generated_chars.size(); i++)
            generated_chars[i] = tolower(generated_chars[i]);

    vector<string> out;
    map<char, int> given_string_map;
    for(unsigned int i = 0; i < generated_chars.size(); i++)
        given_string_map[generated_chars[i]]++;

    

    for(auto it = diccionario.begin(); it != diccionario.end(); it++){
        //build map for (*it)
        string aux_diccionario = (*it);
        
        if(aux_diccionario.find("ñ") == string::npos){
            map<char, int> aux_diccionario_map;
            for(unsigned int i = 0; i < aux_diccionario.size(); i++)
                aux_diccionario_map[aux_diccionario[i]]++;

            if(aux_diccionario_map <= given_string_map)
                out.push_back(aux_diccionario);
        }
    }

    return out;

}

void lista_palabras::count(map<char, double> &m, int &total_chars){
    total_chars = 0;

    for(auto it = diccionario.begin(); it != diccionario.end(); it++){
        string aux = *it;
        for(unsigned int i = 0; i < aux.size(); i++){
            if(aux[i] >= 'a' && aux[i] <= 'z'){ 
                m[aux[i]]++;
                total_chars++;
            }
        }
    }
}

