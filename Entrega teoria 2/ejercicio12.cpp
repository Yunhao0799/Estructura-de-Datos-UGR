#include<iostream>
#include <list>

using namespace std;

bool contenida(const list<int> &l1, const list<int> &l2){
	bool contenida ;
	//buscar en l1, l2
	int is;
	list<int>::const_iterator it, it2 = l1.begin(), it3;
	for(it = l1.begin(); it != l1.end(); it++){
		if(*it == *it2){
			contenida = true;
			it3 = it;
			for(it2 = l2.begin(); it2 != l2.end(); it2++){
				if(*it2 != *it3)
					contenida = false;
				it3++;
			}
			//if(aux) contenida = true;
			
		}
	}
	return contenida;
}

int main(){
	int elementos[] = {4, 5};
	int elementos2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	list<int> lista, lista2;
	list<int>::iterator it;
	lista.assign(elementos, elementos + 2);
	lista2.assign(elementos2, elementos2 + 10);
	
	if(contenida(lista2, lista))
		cout << "contenida \n ";
	else
		cout << "no";
}
