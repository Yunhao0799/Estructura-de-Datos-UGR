/*
Implementa una cola con prioridad de un tipo struct con (apellidos, nombre, prioridad) de
forma que los datos salgan de acuerdo a ese tercer campo prioridad.
*/

#include<iostream>
#include<queue>

using namespace std;

struct estructura{
	string apellidos;
	string nombre;
	int prioridad;
};

//void add_priority(queue<estructura> &p, estructura nuevo);
void imprimir(priority_queue <estructura, vector<estructura>, greater<estructura> >  p);
bool operator> (estructura a, estructura b){
   return(a.prioridad < b.prioridad);
}

int main(){
	//queue<estructura> cola, aux;
	priority_queue <estructura, vector<estructura>, greater<estructura> > cola;
	estructura e1 = {"apellido1", "nombre1", 5};
	estructura e2 = {"apellido2", "nombre2", 5};
	estructura e3 = {"apellido3", "nombre3", 7};
	estructura e4 = {"apellido4", "nombre4", 3};
	
	//add_priority(cola, e1);
	cola.push(e1);
	imprimir(cola);
	
	cola.push(e4);
	//add_priority(cola, e2);
	imprimir(cola);
	
	cola.push(e3);
	//add_priority(cola, e3);
	imprimir(cola);
	
	cola.push(e2);
	//add_priority(cola, e4);
	imprimir(cola);
	
	
}

void imprimir(priority_queue <estructura, vector<estructura>, greater<estructura> >  p){
	cout << endl;
	priority_queue <estructura, vector<estructura>, greater<estructura> >  aux;
	aux = p;
	while(!aux.empty()){
		cout << aux.top().apellidos << "	" << aux.top().nombre << "		Prioridad: " << aux.top().prioridad;
		aux.pop();
		cout << endl;
	}
	cout << endl;
}
/*
void add_priority(queue<estructura> &p, estructura nuevo){
	int prioridad = nuevo.prioridad;
	bool insertado = false;
	if(p.empty()){
		p.push(nuevo);
	}
	else{
		estructura auxi;
		queue<estructura> aux;
		while(!p.empty()){
			auxi = p.front();
			if(prioridad >= auxi.prioridad && !insertado){
				aux.push(nuevo);
				insertado = true;
			}
				
			
			aux.push(p.front());
			p.pop();
		}
		p = aux;
		
		if(prioridad < p.back().prioridad)
			p.push(nuevo);
	}
}*/
