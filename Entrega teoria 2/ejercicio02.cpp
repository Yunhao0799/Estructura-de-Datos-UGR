#include <iostream>
#include <map>
#include <iterator>

using namespace std;

string desencripta(string cad, const map<char,char> codigo){
	string salida = cad;
	bool encontrado;
	char aux;
	map<char, char>::const_iterator it, aux_it;
	for (int i = 0; i < salida.size(); i++){
			encontrado = false;
		aux = salida[i];
		//it = codigo.find(aux);
		for(it = codigo.begin(); it != codigo.end() && !encontrado; it++){
			if(it -> second == aux){
				encontrado = 1;
				aux_it = it;
			}
		}
		
		if(encontrado)
			salida[i] = aux_it -> first;
	
	}
	
	return salida;
}
int main(){
	string sin = "mnopq";
	//map<key, value>
	map<char, char> codigo;
	codigo['a'] = 'm';
	codigo['b'] = 'n';
	codigo['c'] = 'o';
	codigo['d'] = 'p';
	codigo['e'] = 'q';
	string con = desencripta(sin, codigo);
	
	cout << con;
}
