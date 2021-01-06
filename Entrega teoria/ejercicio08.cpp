/*
Se llama expresión en postfijo a una expresión matemática en la que cada operación aparece
con sus dos operandos seguidos por el operador. Hay un espacio entre cada dos elementos.
Por ejemplo:
2 3 + 5 *
Escribe una función que evalúe una expresión en postfijo.
 a b ^ c * d / e + donde a = 5, b = 3, c = d = 2, e = 9
 a b c d e + * + - donde a = 12, b = 4, c = 7, d = 5, e = 2
 a b + c d * + e * donde a = 2, b = 6, c = 3, d = 5, e = 9
? T evaluar(string expresion, pair<char, T> *variables[], int num_variables)
*/

#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;



template<class T>
T operar(T num1, char n, T num2){
	T salida = 0;
	if(n == '+')
		salida = num1 + num2;
	else if(n == '-')
		salida = num1 - num2;
	else if(n == '*')
		salida = num1 * num2;
	else if(n == '/')
		salida = num1 / num2;
	else if(n == '^')
		salida = pow(num1, num2);
	
	return salida;
}

template<class T>
T valor(char letra, pair<char, T> variables[], int num_variables){
	for(int i = 0; i < num_variables; i++){
		if(letra == variables[i].first){
			return variables[i].second;
			break;
		}
	}
}

template<class T>
T evaluar(string expresion, pair<char, T> variables[], int num_variables){
	stack<T> numeros;
	T num1, num2, aux;

	int tam = expresion.size();
	
	for(int i = 0; i < tam; i++){
		if (expresion[i] != ' '){
			if(expresion[i] >= 'a' && expresion[i] <= 'z'){
				aux = valor(expresion[i], variables, num_variables);
				numeros.push(aux);
			}
			else{
				num2 = numeros.top();
				numeros.pop();
				num1 = numeros.top();
				numeros.pop();
				aux = operar(num1, expresion[i], num2);
				numeros.push(aux);
			}
		}
	}
	return numeros.top();
	
}

int main(){
	string expresion1 = "a b ^ c * d / e +";
	pair<char, int> variables1[5];
	variables1[0] = pair<char, int> ('a', 5);
	variables1[1] = pair<char, int> ('b', 3);
	variables1[2] = pair<char, int> ('c', 2);
	variables1[3] = pair<char, int> ('d', 2);
	variables1[4] = pair<char, int> ('e', 9);
	
	cout <<  evaluar(expresion1, variables1, 5) << endl;
	
	string expresion2 = "a b c d e + * + -";
	pair<char, int> variables2[5];
	variables2[0] = pair<char, int> ('a', 12);
	variables2[1] = pair<char, int> ('b', 4);
	variables2[2] = pair<char, int> ('c', 7);
	variables2[3] = pair<char, int> ('d', 5);
	variables2[4] = pair<char, int> ('e', 2);
	
	cout <<  evaluar(expresion2, variables2, 5) << endl;
	
	
	string expresion3 = "a b + c d * + e *";
	pair<char, int> variables3[5];
	variables3[0] = pair<char, int> ('a', 2);
	variables3[1] = pair<char, int> ('b', 6);
	variables3[2] = pair<char, int> ('c', 3);
	variables3[3] = pair<char, int> ('d', 5);
	variables3[4] = pair<char, int> ('e', 9);
	
	cout <<  evaluar(expresion3, variables3, 5) << endl;

	
}
