#include <iostream>

#include "Cola_max_pila.h"



template <typename T>
void Cola_max<T>::imprime(){
    stack<T> aux;
    aux = cola;
    cout << "Cola: \n";
    while(!aux.empty()){
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << endl;
    aux = maximos;
    cout << "Maximos: \n";
    while(!aux.empty()){
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << "\n\n";
}

//constructor por defecto
template <typename T>
Cola_max<T>::Cola_max(){
}

//operacion de consulta del primer elemento
template <typename T>
T Cola_max<T>::frente(){
    stack<T> aux;
    aux = cola;
    for(int i = 0; i < aux.size() - 1; i++)
        aux.pop();

    return aux.top(); 
}

//operacion que quita el primer elemento introducido
template <typename T>
void Cola_max<T>::quitar(){
    stack<T> aux;
    //borrado del primer eleento de pila
    for(int i = 0; i < cola.size() - 1; i++){
        aux.push(cola.top());
        cola.pop();
    }
    cola.pop();

    for(int i = 0; i < aux.size(); i++){
        cola.push(aux.top());
        aux.pop();
    }

    //vaciamos el auxiliar
    while(!aux.empty())
        aux.pop();

    //borrado del primer elemento de maximos
    for(int i = 0; i < maximos.size() - 1; i++){
        aux.push(maximos.top());
        maximos.pop();
    }
    maximos.pop();

    for(int i = 0; i < aux.size(); i++){
        maximos.push(aux.top());
        aux.pop();
    }
}

//añadir elemento al final, tenemos que comprobar si es
//menor que el maximo para resetear o si es mayor que el maximo
//y actualizar todo lo anterior
template <typename T>
void Cola_max<T>::poner(T elemento){
    cola.push(elemento);
	if(!maximos.empty()){
        if(elemento < maximos.top()){
            //actualizamos el nuevo maximo
            maximos.push(elemento);
            contador = 0;
        }
        else{
            contador++;
            //actualizamos todas las posisciones anteriores al nuevo elemento
            for(int i = 0; i < contador; i++){
                maximos.pop();
            }
                

            for(int i = 0; i < contador + 1; i++)
                maximos.push(elemento);
        }
    }
    else{
        maximos.push(elemento);
    }
    
}

//devolucion del tamaño
template <typename T>
int Cola_max<T>::num_elementos(){
	return cola.size();
}

template <typename T>
T Cola_max<T>::maximo(){
	return maximos.top();
	//maximos.pop_back();
}

template <typename T>
bool Cola_max<T>::vacia(){
	return cola.empty();
}

template <typename T>
int Cola_max<T>::inicio(){
}
