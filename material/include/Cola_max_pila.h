
#ifndef COLA_MAX_PILAS_H
#define COLA_MAX_PILAS_H

#include "Cola_max.h"
#include <stack>
#include <iostream>

using namespace std;

template <class T>
class Cola_max{
	private:
		stack<T> cola;
		stack<T> maximos;
		int contador = 0;
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
