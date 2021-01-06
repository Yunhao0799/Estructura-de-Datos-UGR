/*
Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la
posición pos. La cola debe quedar como estaba antes de insertar el elemento (salvo por el
nuevo elemento)
? void insertar(queue<T> &P, int pos, const T &x)
*/

#include<iostream>
#include<queue>

using namespace std;

template<class T>
void insertar(queue<T> &P, int pos, const T &x){
	queue<T> aux;
	int counter = 0;
	while(!P.empty()){
		if(counter == pos)
			aux.push(x);
		
		aux.push(P.front());
		P.pop();
		counter++;
	}
	P = aux;
}

int main(){
	queue<int> cola, aux;
	for(int i = 0; i < 10; i++)
		cola.push(i);
	
	insertar(cola, 6, 7);
	aux = cola;
	while(!aux.empty()){
		cout << aux.front() << "	";
		aux.pop();
	}
}
