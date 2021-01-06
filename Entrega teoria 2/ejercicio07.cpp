#include<iostream>
#include<list>
#include<cassert>

using namespace std;

template<class T>
void elimina(list<T> &l){
	list<int>::iterator it, it2, it3;
	for(it = l.begin(); it != l.end(); ++it){
		it3 = it;
		advance(it3, 1);
		//busqueda elemento, si se encuentra se elimina
		for(it2 = it3; it2 != l.end(); ++it2){
			if(*it2 == *it)
				l.erase(it2);
		}
	}
}





int main(){
	int elementos[] = {2, 1, 1, 1, 1, 5, 3, 3, 6};
	
	list<int> lista;
	list<int>::iterator it;
	lista.assign(elementos, elementos + 7);
	
	cout << "Lista inicial: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
	cout << "\n";
		
	elimina(lista);
	assert(!lista.empty());
	cout << "Lista final: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
