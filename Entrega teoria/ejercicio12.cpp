/*
Implementa una cola con prioridad que contenga strings y de la que salgan primero las
cadenas de caracteres más largas y que en caso de igualdad salgan por orden alfabético.
*/


#include<iostream>
#include<queue>

using namespace std;


//void add_priority(queue<string> &p, string nuevo);
void imprimir(priority_queue <string, vector<string>, less<string> > p);

bool operator< (string a, string b){
	int prioridad1 = 0, prioridad2 = 0;
	
	for (unsigned i=0 ; i!=a.size() ; i++){
		prioridad1 ++;
	}

	for (unsigned i=0 ; i!=b.size() ; i++){
		prioridad2 ++;
	}
	
	if (prioridad1 == prioridad2){
		if (a < b){
		   return (prioridad1 < prioridad2);
      }
   }
	else{
		return (prioridad1 < prioridad2);
	}
}

int main(){
	priority_queue <string, vector<string>, less<string> > cola;
	
	string s1 = "hola";
	string s3 = "hola caracola";
	string s4 = "hola cara";
	string s5 = "ho";
	
	//add_priority(cola, s1);
	cola.push(s1);
	imprimir(cola);
	
	
	cola.push(s3);
	//add_priority(cola, s3);
	imprimir(cola);
	
	cola.push(s4);
	//add_priority(cola, s4);
	imprimir(cola);
	
	cola.push(s5);
	//add_priority(cola, s5);
	imprimir(cola);
}

void imprimir(priority_queue <string, vector<string>, less<string> > p){
	cout << endl;
	priority_queue <string, vector<string>, less<string> > aux;
	aux = p;
	while(!aux.empty()){
		cout << aux.top();
		aux.pop();
		cout << endl;
	}
	cout << endl;
}



/*
void add_priority(queue<string> &p, string nuevo){
	int tam = nuevo.size();
	bool insertado = false;
	if(p.empty()){
		p.push(nuevo);
	}
	else{
		string auxi;
		queue<string> aux;
		while(!p.empty()){
			auxi = p.front();
			if(tam >= auxi.size() && !insertado){
				aux.push(nuevo);
				insertado = true;
			}
				
			
			aux.push(p.front());
			p.pop();
		}
		p = aux;
		
		if(tam < p.back().size())
			p.push(nuevo);
	}
}*/
