#include <iostream>
#include "bintree.h"
#include <queue>

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

/*
template <typename T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n, typename bintree<T>::node out, int &nivel) {
	queue<typename bintree<T>::node> nodos;
	bool found = 0;
 	if (!n.null()) {
		 nodos.push(n);
		 while (!nodos.empty() && !found) {
			n = nodos.front(); 
			nodos.pop();
			
			//cout << *n << " ";
			
			
			if(*n == *out)
				found = true;
				
			nivel++;
				
			if (!n.left().null()) 
				nodos.push(n.left());
			if (!n.right().null())
				nodos.push(n.right());
		}
	}
	
}*/



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
	
	bintree<int>::node aux = Arb.root().left().left();
	int level = nivel(Arb, aux);
	cout << "\n\n MAIN: \n";
	cout << "Elemento " << *aux << " nivel " << level << endl;
	
	aux = Arb.root().right().left().right();
	level = nivel(Arb, aux);
	cout << "Elemento " << *aux << " nivel " << level << endl;
	//ListarPostNiveles(Arb, Arb.root());
}
