/*
Implementa un TDA cola usando como representación dos pilas.
*/

#include<iostream>
#include<stack>

using namespace std;

template<class T>
class cola{
	private:
		stack<T> pila1; //importante
		stack<T> pila2;
	public:
		cola<T>(){
			
		}
		
		T front(){
			stack<T> aux = pila1;
			while(!aux.empty()){
				pila2.push(aux.top());
				aux.pop();
			}
			return pila2.top();
		}
		
		T back(){
			return pila1.top();
		}
		
		void push(T valor){
			pila1.push(valor);
		}
		
		void pop(){
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}
			pila2.pop();
			
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
		}
		
		bool empty(){
			return pila1.empty();
		}
		
		int size(){
			return pila1.size();
		}
};

int main(){
	cola<int> cola1;
	cola1.push(5);
	cola1.push(4);
	cola1.push(3);
	cola1.push(7);
	cout << cola1.front() << "	" << cola1.back() << endl;
	cola1.pop();
	cout << cola1.front();
}
