/*
. Implementa un función para determinar si una expresión contenida en un string tiene una
configuración de paréntesis correcta. Debe tener un orden lineal
? bool parentesis_correctos(string expresion)
*/
#include<iostream>
#include <stack>

using namespace std;

bool parentesis_correctos(string expresion);

int main(){
	string s1 = "este (esta) ()bien",
		   s2 = "este no esta) bien",
		   s3 = "este no (esta)( bien";
		   
	cout << parentesis_correctos(s1) << endl;
	cout << parentesis_correctos(s2) << endl;
	cout << parentesis_correctos(s3) << endl;
}

bool parentesis_correctos(string expresion){
	bool bien = true;
	stack<int> pila;
	
		for(int i = 0; i < expresion.size() && bien; i++){
			if(expresion[i] == ')' && pila.empty())
				bien = false;
			else if(expresion[i] == '(')
				pila.push(1);
			else if(expresion[i] == ')')
				pila.pop();
			
		}		
	
	if(!pila.empty())
		bien = false;
		
	return bien;
}
