#include <iostream>
#include "bintree.h"
#include <queue>

using namespace std;

template <typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &arb){
	typename bintree<T>::node out;
	ListarPostNiveles(arb, arb.root(), out);
	return out;
}

template <typename T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n, typename bintree<T>::node &out) {
	queue<typename bintree<T>::node> nodos;
 	if (!n.null()) {
		 nodos.push(n);
		 while (!nodos.empty()) {
			n = nodos.front(); 
			nodos.pop();
			
			//cout << *n << " ";
			
			out = n;
				
				
			if (!n.left().null()) 
				nodos.push(n.left());
			if (!n.right().null())
				nodos.push(n.right());
		}
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
	Arb.insert_left(Arb.root().right().left(), 777);
	Arb.insert_right(Arb.root().right().left(), 999);
	
	bintree<int>::node aux = mas_profunda(Arb);
	cout << "\n\n MAIN: \n";
	cout << *aux;
	//ListarPostNiveles(Arb, Arb.root());
}
