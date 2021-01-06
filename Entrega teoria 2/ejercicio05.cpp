#include <iostream>
#include<string>
#include <map>

using namespace std;

map<string, string> params(string cad){
	//string aux;
	map<string, string> salida;
	for(int i = 0; i < cad.size() - 3; i++){
		if(cad[i] == '-'){
			if(cad[i + 3] == '-'){
				string aux;
				aux = cad[i+1];
				salida[aux] = "activo";
			}
			else if(cad[i + 3] != '-'){
				string aux2;
				aux2 = cad[i + 1];
				string aux = " ";
				int j = i + 3;
				while(cad[j] != ' ' && j < cad.size()){
					aux += cad[j];
					j++;
				}
				
				salida[aux2] = aux;
			}
		}
	}
	
	return salida;
}

int main(){
	string st = "tar -z -x -f fichero -y holoas";
	map<string, string> mapa;
	mapa = params(st);
	map<string,string>::iterator it;
	for(it = mapa.begin(); it != mapa.end(); it++){
		cout << "Modificador: " << it -> first << endl;
		cout << " 	parametro: " << it -> second << endl;
	}
}
