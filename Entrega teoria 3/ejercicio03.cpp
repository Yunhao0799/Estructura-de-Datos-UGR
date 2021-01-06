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

/*
template <typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &arb){
	typename bintree<T>::node out;
	ListarPostNiveles(arb, arb.root(), out);
	return out;
}*/

template <typename T>
void ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n, typename bintree<T>::node &out, int &elementos) {
	queue<typename bintree<T>::node> nodos;
	int k = 0;
	int i = 0;
	int num = 0;
 	if (!n.null()) {
		 nodos.push(n);
		 while (!nodos.empty()) {
			n = nodos.front();
			nodos.pop();
			/*
			num = pow(2, k);
			if(i == num ){
                cout << endl;
                k++;
			}*/
			cout << *n << " ";

			out = n;


			if (!n.left().null())
				nodos.push(n.left());
			if (!n.right().null())
				nodos.push(n.right());

			elementos++;
			i++;
		}
	}

}

template<class T>
bool completo(const bintree<T> &Arb){
	//tenemos que sacar los elementos que tiene, y si coincide con el total devolver true
	int elementos = 0, total_elementos_lleno = 0, lleno_ult_nivel;
	typename bintree<T>::node aux;
	ListarPostNiveles(Arb, Arb.root(), aux, elementos);
	int niveles = nivel(Arb, aux);

	for(int i = niveles - 1; i >= 0; i--)
		total_elementos_lleno += pow(2, i);

	lleno_ult_nivel = total_elementos_lleno + pow(2, niveles);
	if(elementos == lleno_ult_nivel)
		return true;
	if(elementos >= total_elementos_lleno){

	}


	return false;
}


template<class T>
bool completo_ultimo_nivel(const bintree<T> &arb, typename bintree<T>::node n){
	typename bintree<T>::node aux = n.parent();
	if(aux == n){
		aux.parent();
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

	bintree<int>::node aux = Arb.root().left().left(), aux2;
	int n;

	//cout << completo(Arb) << endl;

	aux = Arb.root();
	for(int i = 0; i < 2; i++)
		aux = aux.left();

	ListarPostNiveles(Arb, Arb.root(), aux2, n);

}
