/*
Implementa un TDA cola usando como representación dos pilas.
*/

#include<iostream>
#include<stack>

using namespace std;

template<class T>
void insertar1(stack<T> &P, int pos, const T &x){
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

template<class T>
class ventana{
	private:
		stack<T> pila1; //importante
		stack<T> pila2;
	public:
		ventana<T>(){
			
		}
		
		void insertar(T elemento, int pos){
			insertar1(pila1, pos, elemento);
		}
		
		void mover_izq(){
			T aux = pila1.top();
			pila1.pop();
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}
			pila1.push(aux);
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
		}
		
		void mover_derecha(){
			T aux;
			bool ultimo = false;
			int i = 0;
			while(i < pila1.size() - 1){
				aux = pila1.top();
				pila2.push(aux);
				pila1.pop();
			}
			
			aux = pila1.top();
			pila1.pop();
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
			
			pila1.push(aux);
		}
		
		bool empty(){
			return pila1.empty();
		}
		
		int size(){
			return pila1.size();
		}
		
		void imprimir(){
			while(!pila1.empty()){
				cout << pila1.top() << "	";
				pila1.pop();
			}
			cout << endl;
			cout << endl;
		}
		
		void add(T e){
			pila1.push(e);
		}
		
		void borrar(T e){
			bool encontrado = false;
			while(!encontrado && !pila1.empty()){
				if(pila1.top() == e)
					encontrado = true;
				else{
					pila2.push(pila1.top());
					pila1.pop();
				}
			}
			
			pila1.pop();
			
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
		}
};

int main(){
	ventana<int> v, d;
	v.add(3);
	v.add(5);
	v.add(7);
	v.add(14);
	v.add(21);
	d = v;
	v.imprimir();
	
	v = d;
	cout << "Mover a la izquierda" << endl;
	v.mover_izq();
	d = v;
	v.imprimir();
	
	v = d;
	cout << "Mover a la derecha" << endl;
	v.mover_derecha();
	d = v;
	v.imprimir();
	
	v = d;
	cout << "Insertar pos 3, 6" << endl;
	v.insertar(6, 3);
	d = v;
	v.imprimir();
	
	v = d;
	cout << "Eleiminar 5" << endl;
	v.borrar(5);
	v.imprimir();
}

