#include <iostream>
#include <map>

using namespace std;

string encripta(string cad, const map<char,char> &codigo){
	string salida = cad;
	char aux;
	map<char,char>::iterator it;
	for (int i = 0; i < salida.size(); i++){
		aux = salida[i];
		//it = codigo.find(aux);
		if(codigo.find(aux) != codigo.end())
			salida[i] = codigo.find(aux) -> second;
	}
	
	return salida;
}
int main(){
	string sin = "abcde";
	//map<letter, key>
	map<char, char> codigo;
	codigo['a'] = 'm';
	codigo['b'] = 'n';
	codigo['c'] = 'o';
	codigo['d'] = 'p';
	codigo['e'] = 'q';
	string con = encripta(sin, codigo);
	
	cout << con;
}
