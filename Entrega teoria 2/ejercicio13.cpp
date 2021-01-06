#include <iostream>
#include <list>

using namespace std;

template<class T>
list<T> lista_posiciones(const list<T> &l, const list<typename list<T>::iterator> its){
	list<T> out;
	
	auto iter = its.begin();
	for(int i = 0; i < its.size() && iter != its.end(); ++i){
		out.push_back(**iter);
		++iter;
	}
	
	return out;
}

int main(){
	list<list<int>::iterator> hola;
	int elementos[] = {2, 43, 2345, 54, 2, 65, 5, 3, 3, 6};
	list<int> lista;
	lista.assign(elementos, elementos + 10);
	auto it = lista.begin();
	hola.push_back(it);
	advance(it, 5);
	hola.push_back(it);
	advance(it, 4);
	hola.push_back(it);
	//2 65 6, salida teorica
	
	cout << "Lista inicial: \n";
	for(auto it2 = lista.begin(); it2 != lista.end(); ++it2)
		cout << *it2 << " ";
		
	lista = lista_posiciones(lista, hola);
	
	cout << "\n\nLista final: \n";
	for(auto it2 = lista.begin(); it2 != lista.end(); ++it2)
		cout << *it2 << " ";
	
}
