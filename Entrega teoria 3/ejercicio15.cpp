#include <iostream>
#include "bintree.h"
#include <queue>
#include <cmath>

using namespace std;

template <typename T>
int nivel(const bintree<T> &arb, typename bintree<T>::node n){
	int nivel = 0;
	while(arb.root()!= n){
		nivel++;
		n = n.parent();
	}
	
		
	return nivel;	
	
}



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

template<class T>
typename bintree<T>::node ancestro_comun(typename bintree<T>::node n1, typename bintree<T>::node n2){
	
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
	
	bintree<int>::node aux = Arb.root().left().left(), aux2;
	int n;

	//cout << completo(Arb) << endl;
	
	aux = Arb.root();
	for(int i = 0; i < 2; i++)
		aux = aux.left();
		
	ListarPostNiveles(Arb, Arb.root(), aux2, n);

}
