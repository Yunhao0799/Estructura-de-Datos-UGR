#include "Cola_max_vd.h"
#include <iostream>


template <typename T>
void Cola_max<T>::imprime(){
	cout << "Cola: \n";
	for(long unsigned int i = 0; i < cola.size(); i++)
		cout << cola[i] << " ";
	cout << endl;
	cout << endl;

	cout << "Maximos: \n";
	for(long unsigned int i = 0; i < maximos.size(); i++)
		cout << maximos[i] << " ";
	cout << endl;
	cout << endl;
}

//constructor por defecto
template <typename T>
Cola_max<T>::Cola_max(){
}

//operacion de consulta del primer elemento
template <typename T>
T Cola_max<T>::frente(){
	return cola.front();
}

//operacion que quita el primer elemento introducido
template <typename T>
void Cola_max<T>::quitar(){
	cola.erase(cola.begin());
	maximos.erase(maximos.begin());
}

//añadir elemento al final, tenemos que comprobar si es
//menor que el maximo para resetear o si es mayor que el maximo
//y actualizar todo lo anterior
template <typename T>
void Cola_max<T>::poner(T elemento){
	cola.push_back(elemento);
	if(!(maximos.empty())){
		if(elemento < maximos.back()){
			maximos.push_back(elemento);
			inicio_nuevo_maximo = maximos.size() - 1;
		}
		else{
			maximos.push_back(elemento);
			for(long unsigned int i = inicio_nuevo_maximo; i < maximos.size(); i++)
				maximos[i] = elemento;
		}
	}
	else{
		inicio_nuevo_maximo = 0;
		maximos.push_back(elemento);
	}
	
}

//devolucion del tamaño
template <typename T>
int Cola_max<T>::num_elementos(){
	return cola.size();
}

template <typename T>
T Cola_max<T>::maximo(){
	return maximos.back();
	//maximos.pop_back();
}

template <typename T>
bool Cola_max<T>::vacia(){
	return cola.empty();
}

template <typename T>
int Cola_max<T>::inicio(){
	return inicio_nuevo_maximo;
}
