#ifndef Diccionario_h
#define Diccionario_h


#include "Termino.h"
#include <string>
#include<iostream>
#include<set>
using namespace std;
/*
struct comparar{
    bool operator() (const Termino &t1, const Termino &t2) const{
        return (t1.getPalabra() < t2.getPalabra());
    }
};*/


/**
 * @brief T.D.A Diccionario
 * Una variable de la clase Diccionario estara
 * formado por un set de terminos
 * 
 * Un ejemplo de su uso
 * @include pruebadiccionario.cpp
 * 
 * @author Yunhao Lin
 * @date Sábado, 01 de diciembre 2018
 * */

class Diccionario{
    private:
        set<Termino> terminos;
    
    public:
        /**
         * @brief Constructor de por defecto
         *
         */
        Diccionario();

        /** @brief Constructor por parametros
         * @param termino variable de la clase Termino
         */
        Diccionario(const Termino&);

        /** @brief constructor de copia
         * @param otra variable que representa otro direccionario
         */
        Diccionario(const Diccionario&);

        //getters
        /**
         * @brief Definiciones de una palabra dada
         * @param buscado Termino del que queremos obtener las definiciones
         * @return salida Devuelve un vector de tipo string
         */
        vector<string> getDefinicionesPalabra(Termino) const;

        /**
         * @brief Todos los terminos del diccionario
         * @return terminos Devuelve un vector de tipo Termino
         */
        set<Termino> getAllTerms() const;
        
        /**
         * @brief Total de terminos
         * @return Devuelve un entero con la cantidad de terminos del diccionario
         */
        int getNumTerminos() const;

        //setters
        /** 
         * @brief Añade un termino
         * @param  nuevo Termino a añadir
         */
        void setNewTerm(Termino);

        /** 
         * @brief Elimina un termino
         * @param  eliminar Termino a eliminar
         */
        void eliminarTermino(Termino);

        //metodo que nos devuelve la posicion a la que se encuentra un termino
        //int buscarTermino(Termino);
        
        /**
         * @brief Entrada de un diccionario desde istream
         * @param is stream de entrada
         * @param d Diccionario que recibe el valor
         * @retval El Diccionario leído en d
         * @pre La entrada tiene el formato Palabra; definicion
         */
        friend istream& operator>>(istream &is, Diccionario &d);

        /**
         * @brief Salida de un Diccionario a ostream
         * @param os stream de salida
         * @param d Diccionario a escribir
         * @post Se imprime  un Termino
         */
        friend ostream& operator<<(ostream &os, const Diccionario &d);

        typedef set<Termino>::iterator iterator;

        typedef set<Termino>::const_iterator const_iterator;

        Diccionario::iterator begin();

        Diccionario::const_iterator begin() const;

        Diccionario::iterator end();

        Diccionario::const_iterator end() const;

        /**
         * @brief Filtrado por Intervalo
         * Dado un diccionario, 
         * el objetivo es obtener un subconjunto de este 
         * diccionario que incluya únicamente los términos
         * cuya palabra asociada esté en elintervalo 
         * especificado por[carácter_inicio, carácter_fin]
         * @param ini Caracter de inicio
         * @param fin Caracter de fin
         * @return salida Diccionario que empieza en el caracter dado y 
         *          termina en el caracter fin
         */
        Diccionario filtroIntervalo(const string, const string);

        /**
         * @brief FIltrado por palabra clave
         * Dado un diccionario, el objetivo es obtener un subconjuntode 
         * este diccionario que incluya únicamente las palabras en cuya 
         * definición aparezcala palabra clave. Si una palabra tiene 
         * varias definiciones, solo se devolverían como re-sultado del 
         * filtrado por palabra clave aquellas definiciones relacionadas 
         * con la palabraclave
         * @param a_buscar String que contiene la secuencia a buscar
         * @return salida Diccionario que contiene los terminos que tiene la palabra dada
         */
        Diccionario subsecuencia(const string&);

        /**
         * @brief Recuento de definiciones
         * Dado un diccionario, el objetivo es obtener el número total
         * de definiciones, el máximo de definiciones asociadas a una única 
         * palabra y el promediode definiciones por palabra
         * @param totalDefiniciones Double pasado por referencia y almacena el total de definiciones
         * @param maxDefiniciones Double pasado por referencia y almacena la palabra con mas definicones(cantidad)
         * @param promedio
         */
        void recuento(double&, double&, double&);
};

#endif