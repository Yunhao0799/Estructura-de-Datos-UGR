/*
Usando una pila y una cola, implementa una función que compruebe si un string es un
palíndromo.
? bool palindromo(string cad)

*/

#include <iostream>
#include<queue>
#include<stack>

using namespace std;

bool palindromo(string cad);

int main(){
	string cadena = "ali tomo tila";
	cout << palindromo(cadena);
}

bool palindromo(string cad){
	stack<char> pila;
	queue<char> cola;
	bool palindromo = true;
	
	for(int i = 0; i < cad.length(); i++){
		pila.push(cad[i]);
		cola.push(cad[i]);
	}
	
	while(!pila.empty() && !cola.empty()){
		if(pila.top() == ' ')
			pila.pop();
		if(cola.front() == ' ')
			cola.pop();
		if(cola.front() != pila.top())
			palindromo = false;
			
		pila.pop();
		cola.pop();
	}
	return palindromo;
}
