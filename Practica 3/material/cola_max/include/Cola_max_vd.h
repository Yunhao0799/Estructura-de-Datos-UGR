
#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

//#include "Cola_max.h"
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Cola_max{
	private:
		vector<T> cola;
		vector<T> maximos;
		int inicio_nuevo_maximo = 0;
	public:
		Cola_max();
		
		//operacion de consulta del elemento primero 
		T frente();

		//operacion que quita el primer valor metido
		void quitar();

		//añadir elemento al final
		void poner(T);

		//cosulta del tamaño
		int num_elementos();

		//devolucin maximo(el ultimo elemento de la cola de los maximos
		T maximo();

		bool vacia();

		int inicio();

		void imprime();
};

#endif
