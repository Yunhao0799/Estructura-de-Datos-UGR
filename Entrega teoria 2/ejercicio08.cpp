#include<iostream>
#include<list>
#include<cassert>

using namespace std;

template<class T>
list<T> inversa(const list<T> &l){
	list<T> sal;
	typename list<T>::const_iterator it;
	for(it = l.begin(); it != l.end(); ++it)
		sal.push_front(*it);
	
	return sal;
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
		
	lista = inversa(lista);
	assert(!lista.empty());
	cout << "Lista final: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
