/*
EJERCICIO 1

Construye una función a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo
T y que modifique la pila de forma que todas las veces que aparezca x se substituya por y
(quedando la pila en el mismo estado en el que estaba anteriormente). Para este ejercicio no
se podrán utilizar iteradores.
? void substituye(stack<T> &P, const T &x, const T &y)*/


#include <iostream>
#include <stack>

using namespace std;

template <class T>
void substituye(stack<T> &P, const T &x, const T &y){
	stack<T> aux;
	
	//vamos sacando elementos para comprobar si es igual a x lo sustituimos por y
	while(!(P.empty())){
		if(P.top() == x)
			aux.push(y);
		else aux.push(P.top());
		P.pop();
	}
	
	//ahora tenemos qeu devolver volver a meterlo en aux
	while(!(aux.empty())){
		P.push(aux.top());
		aux.pop();
	}
}

//void substituye(stack<T> &P, const T &x, const T &y);

int main(){
	//Vamos a probar que funciona nuestra funcion
	int elementos[10] = {3, 9, 23, 1, 5, 1, 54, 23, 7, 3};
	stack<int> pila, pila_copia;
	for(int i = 0; i < 10; i++)
		pila.push(elementos[i]);
		

	substituye(pila, 1, 0);
	pila_copia = pila;
	while(!(pila_copia.empty())){
		cout << pila_copia.top() << "	";
		pila_copia.pop();
	}
	
	cout << endl;
	//vamos a probar con char
	char elementos1[10] = {'a', 'b', 'c', 'd', 'e', 'e', 'e', 'e', 'e', 'e'};
	stack<char> pila2, pila_copia2;
	for(int i = 0; i < 10; i++)
		pila2.push(elementos1[i]);
		

	substituye(pila2, 'e', 'z');
	pila_copia2 = pila2;
	while(!(pila_copia2.empty())){
		cout << pila_copia2.top() << "	";
		pila_copia2.pop();
	}
}


