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


			if (!n.left().null())
				nodos.push(n.left());
			if (!n.right().null())
				nodos.push(n.right());
		}
	}
}

template<class T>
bool similares(const bintree<T> &Arb1,const bintree<T> &Arb2){
	bool similar = true;
	queue<typename bintree<T>::node> nodos, nodos2;
	typename bintree<T>::node n = Arb1.root(), n2 = Arb2.root();

 	if (!n.null() && !n2.null()) {
		 nodos.push(n);
		 nodos2.push(n2);
		 while ((!nodos.empty() || !nodos2.empty()) && similar) {
		 	int a = nodos.size(), b = nodos2.size();
		 	if(nodos.size() != nodos2.size())
					similar = false;
					
			
			n = nodos.front();
			nodos.pop();
			n2 = nodos2.front();
			nodos2.pop();



			if (!n.left().null()){
				nodos.push(n.left());				
			}
			
			if (!n2.left().null())
				nodos2.push(n2.left());
				
			if (!n.right().null()){
				nodos.push(n.right());
			}
			
			if (!n2.right().null())
				nodos2.push(n2.right());
			
				
		}
	}
	
	return similar;
}
/*
template<class T>
bool similares(const bintree<T> &Arb1,const bintree<T> &Arb2){
	bool similar = true;
	bintree<T> izq1, izq2, dch1, dch2, arb1 = Arb1, arb2 = Arb2;
	bool n1 = arb1.root().null(), n2 = arb2.root().null();
	if( !n1 && !n2){
		if(!arb1.root().left().null() && !arb2.root().left().null()){
			arb1.prune_left(arb1.root().left(), izq1);
			arb2.prune_left(arb2.root().left(), izq2);
		}
		
		similares(izq1, izq2);
		if(!arb1.root().right().null() && !arb2.root().right().null()){
			arb1.prune_left(arb1.root().right(), dch1);
			arb2.prune_left(arb2.root().right(), dch2);
		}
		similares(dch1, dch2);
	}
	else similar = false;
	return similar;
}*/

int main(){
	//typedef bintree<int> bti;
	bintree<int> Arb(5), tree2;
	Arb.insert_left(Arb.root(), 10);
	Arb.insert_right(Arb.root(), 11);
	Arb.insert_left(Arb.root().left(), 32);
	Arb.insert_right(Arb.root().left(), 44);
	Arb.insert_left(Arb.root().right(), 77);
	Arb.insert_right(Arb.root().right(), 99);
	Arb.insert_left(Arb.root().right().left(), 777);
	Arb.insert_right(Arb.root().right().left(), 999);
	//

	tree2 = Arb;
	
	Arb.insert_right(Arb.root().right().left().right(), 222);
	tree2.insert_right(tree2.root().left().right(), 222);
	
	ListarPostNiveles(Arb, Arb.root());
	cout << endl;

	cout << endl;
	ListarPostNiveles(tree2, tree2.root());
	
	cout << "\n\n";
	cout << "\nSimilitud	" << similares(tree2, Arb);
	


}
