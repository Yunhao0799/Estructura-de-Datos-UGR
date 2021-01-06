#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Hospital{
	private:
		map<string, vector<string> > datos;
	public:
		void insertar(string dni, vector<string> resto){
			datos[dni] = resto;
		}
		
		void borrar(string dni){
			datos.erase(dni);
		}
		
		void print(){
			for(auto it = datos.begin(); it != datos.end(); ++it){
				cout << "DNI: " << it -> first;
				vector<string> aux = it -> second;
				//for(auto it2 = aux.begin(); it2 != aux.end(); ++it2)
				//	cout << aux[*it];
				cout << "			";
				for(int i = 0; i < aux.size(); i++)
					cout << aux[i] << " ";
				
				cout << endl;
			}
		}
		
		vector<string> paciente(string dni){
			return datos[dni];
		}
};

int main(){
	Hospital salud;
	string p1 = "21";
	vector<string> p1r = {"nombre1" , "apellido1", "gravedad1"};; //
	salud.insertar(p1, p1r);
	p1 = "22";
	p1r = {"nombre2" , "apellido2", "gravedad2"};; //
	salud.insertar(p1, p1r);
	salud.print();
	
	
	//acceso a paciente con dni 22
	vector<string> aux = salud.paciente("22");
	for(int i = 0; i < aux.size(); i++)
		cout << aux[i] << " ";
	
}
