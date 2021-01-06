/*
Implementa un TDA pila usando dos colas
*/

#include<iostream>
#include<queue>


using namespace std;

template<class T>
class pila{
	private:
		queue<T> cola1; //importante
		queue<T> cola2;
	public:
		pila<T>(){
			
		}
		
		void pop(){
			T aux;
			bool parar = false;
			while(!parar){
				aux = cola1.front();
				cola1.pop();
				if(cola1.empty()){
					parar = true;
				}
				else{
					cola2.push(aux);
				}
			}
			
			while(!cola2.empty()){
				cola1.push(cola2.front());
				cola2.pop();
			}
			
		}
		
		void push(T valor){
			cola1.push(valor);
		}
		
		T top(){
			return cola1.back();
		}
		
		bool empty(){
			return cola1.empty();
		}
		
		bool size(){
			return cola1.size();
		}
};

int main(){
	pila<char> pila, aux;
	pila.push('a');
	pila.push('b');
	pila.push('c');
	pila.push('d');
	
	
	aux = pila;
	while(!aux.empty()){
		cout << aux.top() << "	" ;
		aux.pop();
	}
	
	cout << endl;

	cout << endl;
	aux = pila;
	aux.pop();
	cout << aux.top() ;
}

/* observamos que la operacion push es O de 1, y la operacion pop en el peor de los casos, o del tamaño de la pila

*/
