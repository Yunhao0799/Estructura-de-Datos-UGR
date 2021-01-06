/*
Implementa una cola con prioridad que contenga strings y de la que salgan primero las
cadenas de caracteres que tengan más vocales y que en caso de igualdad salgan por orden
alfabético
*/


#include<iostream>
#include<queue>

using namespace std;


//void add_priority(queue<string> &p, string nuevo);
bool operator< (string a, string b){
	int prioridad1 = 0, prioridad2 = 0;
	
	for (unsigned i=0 ; i!=a.size() ; i++){
		if((a[i] == 'a') || (a[i] == 'e') || (a[i] == 'i') || (a[i] == 'o') || (a[i] == 'u') || (a[i] == 'A') || (a[i] == 'E') || (a[i] == 'I') || (a[i] == 'O') || (a[i] == 'U')){
			prioridad1 ++;
		}
	}

	for (unsigned i=0 ; i!=b.size() ; i++){
		if((b[i] == 'a') || (b[i] == 'e') || (b[i] == 'i') || (b[i] == 'o') || (b[i] == 'u') || (b[i] == 'A') || (b[i] == 'E') || (b[i] == 'I') || (b[i] == 'O') || (b[i] == 'U')){
			prioridad2 ++;
		}
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
void imprimir(priority_queue <string, vector<string>, less<string> > p);
int vocales(string s);

int main(){
	priority_queue <string, vector<string>, less<string> > cola;
	
	string s1 = "hola";
	string s2 = "holaloliluteeeeeee";
	string s3 = "hola caracola";
	string s4 = "hola cara";
	string s5 = "ho";

	
	//add_priority(cola, s1);
	cola.push(s1);
	imprimir(cola);
	
	
	//add_priority(cola, s2);
	cola.push(s2);
	imprimir(cola);
	
	//add_priority(cola, s3);
	cola.push(s3);
	imprimir(cola);
	
	//add_priority(cola, s4);
	cola.push(s4);
	imprimir(cola);
	
	//add_priority(cola, s5);
	cola.push(s5);
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
	int tam = vocales(nuevo);
	bool insertado = false;
	if(p.empty()){
		p.push(nuevo);
	}
	else{
		string auxi;
		queue<string> aux;
		while(!p.empty()){
			auxi = p.front();
			if(tam > vocales(auxi) && !insertado){
				aux.push(nuevo);
				insertado = true;
			}
			else if(tam == vocales(auxi) && !insertado && nuevo < auxi){
				aux.push(nuevo);
				insertado = true;
			}	
			
			aux.push(p.front());
			p.pop();
		}
		p = aux;
		
		if(tam < vocales(auxi))
			p.push(nuevo);
	}
}*/

int vocales(string s){
	int cont = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			cont++;
	}
	return cont;
}
