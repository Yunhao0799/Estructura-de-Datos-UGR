#include <iostream>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

map<string, int> contar(string nombre_fichero){
	map<string, int> salida;
	map<string, int> it;
	ifstream fichero(nombre_fichero.c_str());
	//fichero.open(nombre_fichero);
	string aux;
	if(fichero){
		while(!fichero.eof()){
			fichero >> aux;
			//it = salida.find(aux);
			//if(salida)
			salida[aux]++;
		}
	}
	else
		cout << "No se pudo abrir \n";
		
	return salida;
}


int main(){
	string nombre = "nombre.txt";
	map<string, int> salida;
	salida = contar(nombre);
	
	map<string, int>::iterator it;
	for(it = salida.begin(); it != salida.end(); it++){
		cout << "Palabra " << it -> first << endl;
		cout<< " 			veces " << it -> second << endl;
	}
	//cout << con;
}
