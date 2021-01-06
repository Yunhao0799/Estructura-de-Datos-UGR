#include<iostream>
#include<list>
#include<cassert>

using namespace std;

template<class T>
void inversa( list<T> &l){
	list<T> sal;
	typename list<T>::const_iterator it;
	for(it = l.begin(); it != l.end(); ++it)
		sal.push_front(*it);
	
	l = sal;
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
		
	inversa(lista);
	assert(!lista.empty());
	cout << "Lista final: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
