#include<iostream>
#include<list>

using namespace std;

template<class T>
void elimina(list<T> &l, const T &x){
	list<int>::iterator it, aux;
	for(it = l.begin(); it != l.end(); ++it){
		if(*it == x){
			l.erase(it);
		}
		
		//l.remove(x);
	}
}





int main(){
	int elementos[] = {2, 1, 1, 1, 1, 5, 3};
	
	list<int> lista;
	list<int>::iterator it;
	lista.assign(elementos, elementos + 7);
	
	cout << "Lista inicial: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
	cout << "\n";
		
	elimina(lista, 1);
	cout << "Lista final: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
