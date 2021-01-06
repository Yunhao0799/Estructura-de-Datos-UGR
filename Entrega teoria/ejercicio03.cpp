/*
Implementa una función insertar(P, pos, x) que inserte un elemento en una pila P en la
posición pos. La pila debe quedar como estaba antes de insertar el elemento (salvo por el
nuevo elemento)
? void insertar(stack<T> &P, int pos, const T &x)
*/

#include <iostream>
#include <stack>

using namespace std;

template<class T>
void insertar(stack<T> &P, int pos, const T &x){
	stack<T> aux;
	int counter = 0;
	while(!P.empty()){
		aux.push(P.top());
		P.pop();
	}
	while(!aux.empty()){
		if(counter == pos)
			P.push(x);
		
		P.push(aux.top());
		aux.pop();
		counter++;
	}
}

int main(){
	stack<int> pila, aux;
	for(int i = 0; i < 10; i++)
		pila.push(i);
	
	insertar(pila, 6, 7);
	aux = pila;
	while(!aux.empty()){
		cout << aux.top() << "	";
		aux.pop();
	}
}
