#include <iostream>
#include "bintree.h"
#include <queue>
#include <cmath>

using namespace std;


template <typename T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n) {
	queue<typename bintree<T>::node> nodos;
 	if (!n.null()) {
		 nodos.push(n);
		 while (!nodos.empty()) {
			n = nodos.front(); 
			nodos.pop();
			
			cout << *n << " ";
			
			//out = n;
				
				
			if (!n.left().null()) 
				nodos.push(n.left());
			if (!n.right().null())
				nodos.push(n.right());
			
			//elementos++;
		}
	}
	
}

template<typename T>
void swap_son(bintree<T> &tree, typename bintree<T>::node &n){
	if(!n.null()){
		T aux = *(n.left());
		//cout << *(aux) << endl;
		*(n.left()) = *(n.right());
		//cout << *(n.left()) << endl;
		*(n.right()) = aux;
		//cout << *(n.right()) << endl;
	}
		
}

template<typename T>
void reflexion(bintree<T> &arb){
	bintree<T> aux;
	bintree<T> aux1;
	
	if (!arb.empty()){
		arb.prune_left(arb.root(), aux);
		arb.prune_right(arb.root(), aux1);
		
		reflexion(aux);
		arb.insert_left(arb.root(), aux1);

		reflexion(aux1);
		arb.insert_right(arb.root(), aux);
	}
	
}



int main(){
	//typedef bintree<int> bti;
	bintree<int> Arb(5);
	Arb.insert_left(Arb.root(), 10);
	Arb.insert_right(Arb.root(), 11);
	Arb.insert_left(Arb.root().left(), 32);	
	Arb.insert_right(Arb.root().left(), 44);
	Arb.insert_left(Arb.root().right(), 77);	
	Arb.insert_right(Arb.root().right(), 99);	
//	Arb.insert_left(Arb.root().right().left(), 777);
//	Arb.insert_right(Arb.root().right().left(), 999);
	
	bintree<int>::node aux = Arb.root().left(), aux2;
	int n;

	//cout << completo(Arb) << endl;
	
	cout << "Arbol original \n";
	ListarPostNiveles(Arb, Arb.root());
	
	cout << "\n\nArbol reflexivo \n";
	reflexion(Arb);
	ListarPostNiveles(Arb, Arb.root());

}
