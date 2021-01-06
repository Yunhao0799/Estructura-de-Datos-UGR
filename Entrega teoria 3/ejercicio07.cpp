#include <iostream>
#include "bintree.h"
#include <queue>
#include <stack>
#include <cmath>
#include <map>

using namespace std;


bintree<char> construir_arbol(string expresion){
	bintree<char> arbol;
	stack<bintree<char> > pila2;
	stack<char> pila;
	for(int i = 0; i < expresion.length(); i++){
		char aux = expresion[i];
		if(expresion[i] != '+' && expresion[i] != '*' && expresion[i] != '/' && expresion[i] != '-')
			pila.push(aux);
		else{
		//	if(pila.size() < 2){
		//		cout << "error\n";
		//		return 0;
		//	}
		//	else{
				char a2 = pila.top();
				pila.pop();
				char a1 = pila.top();
				pila.pop();
				bintree<char> tree(aux);
				tree.insert_left(tree.root(), arbol);
				tree.insert_right(tree.root(), a2);
				pila.push(tree);
		//	}
				
		}
	}
	
	return pila2.top();
}

template<class T>
void PostordenBinario(const bintree<T> & A, typename bintree<T>::node v)
{
	 if (!v.null()) {
		 PostordenBinario(A, v.left());
		 PostordenBinario(A, v.right());
		 cout << *v; // acción sobre el nodo v.
	 }
}

int main(){
	string expresion = "ef+a+bc/+";
	bintree<char> b = construir_arbol(expresion);
	PostordenBinario(b, b.root());
}
