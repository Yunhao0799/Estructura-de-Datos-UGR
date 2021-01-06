#include <iostream>
#include <list>
#include <utility>

using namespace std;

template<class T>
list<pair<T, int> > comprimir(const list<T> &l){
	list<pair<T, int> >  out;
	int contador = 1;
	for(auto it = l.begin(); it != l.end(); ++it){
		auto it2 = it;
		it2++;
		if(*it2 != *it){
			pair<T, int> aux(*it, contador);
			out.push_back(aux);
			contador = 0;
		}
		contador++;
	}
	
	return out;
}

template<class T>
list<T> descomprimir(const list<pair<T, int> > &lc){
	list<T> out;
	for(auto it = lc.begin(); it != lc.end(); ++it){
		for(int i = 0; i < (it -> second); i++)
			out.push_back(it -> first);
	}
	
	return out;
}


int main(){
	int v[] = {1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5};
	list<int> lista(v, v + sizeof(v)/sizeof(int));
	cout << "Lista inicial \n";
	for(auto it = lista.begin(); it != lista.end(); ++it)
		cout << *it << " ";
	cout << endl;
	
	list<pair<int, int> > comprimido;
	comprimido = comprimir(lista);
	
	cout << "\n\nComprimido: \n";
	for(auto it = comprimido.begin(); it != comprimido.end(); ++it)
		cout << "< " << it -> first << " , " << it -> second << " >   ";
	
		
	cout << "\n\nDescomprimido: \n";
	lista = descomprimir(comprimido);	
	for(auto it = lista.begin(); it != lista.end(); ++it)
		cout << *it << " ";
	
}
