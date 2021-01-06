#include<iostream>
#include<list>

using namespace std;

void inserta_antes(list<int> &l, int x){
	list<int>::const_iterator it;
	list<int>::const_iterator aux;
	for(it = l.begin(); it != l.end(); it++){
		if(*it == x){
			aux = it;
			aux++;
			l.insert(aux, x-1);
		}
	}
}


int main(){
	int elementos2[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
	
	list<int> lista;
	list<int>::iterator it;
	lista.assign(elementos2, elementos2 + 10);
	
	inserta_antes(lista, 5);
	
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
