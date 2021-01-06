#include<iostream>
#include<list>
#include<cassert>

using namespace std;

/*
template<class T>
void sort(list<T> &l1, typename list<T>::iterator izq, typename list<T>::iterator dch){
	list<T> aux;
	if(*izq < * dch){
		int centro = l1.size()/2;
		typename list<T>::iterator it;
		advance(it, centro);
		//msort
		sort(l1, izq, it);
		it++;
		sort(l1, it, dch);
	}
	//inplace_merge(l1, l2);
	
}*/

/*
template<class T>
list<T> mezclar(const list<T> &l, const list<T> &l2){
	list<T> sal = l;
	typename list<T>::const_iterator it;
	
	typename list<T>::iterator it1, it2, aux, aux2, it3, aux3;
	//union de los dos
	for(it = l2.begin(); it != l2.end(); ++it)
		sal.push_back(*it);
	for(it3 = sal.begin(); it3 != sal.end(); it3++)
					cout << *it3 << " ";
				cout << endl;
	
	//ordenamos
	for(it1 = sal.begin(); it1 != sal.end(); ++it1){
		aux = it1;
		aux++;
		T var = *aux;
		if(aux != sal.end()){
		
			if(var < *it){
				//buscamos su posicion correcta
				bool encontrado = false;
				for(it2 = sal.begin(); it2 != sal.end() && !encontrado; it2++){
					if(var < *it2){
						aux2 = it2;
						encontrado = 1;
					}
				}
				for(it3 = sal.begin(); it3 != sal.end(); it3++)
						cout << *it3 << " ";
					cout << endl;
				
				
				iter_swap(aux, aux2);
			}
		}
	}
	
	
	return sal;
}*/




template<class T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
	list<T> salida;
	typename list<T>::const_iterator it1, it2;
	bool mayorl1 = true;
	if(l2.size() > l1.size())
		mayorl1 = false;
	
	
	it1 = l1.begin();
	it2 = l2.begin();
	if(mayorl1){
		while(it2 != l2.end()){
			if(*it1 <= *it2){
				salida.push_back(*it1);
				it1++;
			}
			else{
				salida.push_back(*it2);
				it2++;
			}
		}
		
		while(it1 != l1.end()){
			salida.push_back(*it1);
			it1++;
		}
	}
	else{
		while(it1 != l1.end()){
			if(*it1 <= *it2){
				salida.push_back(*it1);
				it1++;
			}
			else{
				salida.push_back(*it2);
				it2++;
			}
		}
		while(it2 != l2.end()){
			salida.push_back(*it2);
			it2++;
		}
	}
	
	return salida;
}

int main(){
	/*int elementos[] = {2, 1, 1, 1, 1, 5, 3};
	int elementos2[] = {2, 43, 2345, 54, 2, 65, 5, 3, 3, 6};*/
	int elementos[] = {1,3,5,7,9,10,34, 56, 78, 90};
	int elementos2[] = {1, 2, 4, 5, 6, 8, 9, 10, 30, 40, 56, 70, 68, 345, 543, 670};
	
	list<int> lista, lista2;
	list<int>::iterator it;
	lista.assign(elementos, elementos + 7);
	lista2.assign(elementos2, elementos2 + 10);
	
	cout << "Lista inicial: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
	cout << "\n";
		
	lista = mezclar(lista, lista2);
	//inplace_merge(lista, lista2);
	assert(!lista.empty());
	cout << "Lista final: \n";
	for(it = lista.begin(); it != lista.end(); it++)
		cout << *it << " ";
}
