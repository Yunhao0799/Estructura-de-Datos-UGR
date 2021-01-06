#ifndef Termino_h
#define Termino_h

#include <string>
#include<iostream>
#include <vector>
using namespace std;

/**
 * @brief T.D.A TErmino
 * Una variable de la clase Termino estara
 * formado por un pair cuyo primer argumento 
 * es un string y el segundo argumento es un 
 * vector de strings
 * 
 * 
 * @author Yunhao Lin
 * @date Sábado, 01 de diciembre 2018
 * */
class Termino{
    private:
        pair<string, vector<string> >  termino;
    public:
        //constructor por defecto
        /**
         * @brief Constructor de por defecto
         *
         */
        Termino();

        //contructor por parametros
        /** @brief Constructor por parametros
         * @param palabra Variable de tipo string
         * @param def Vector dinamico con las definiciones
         */
        Termino(pair<string, vector<string> >);

        //constructor de copia
        /**
         * @brief Constructor de copia
         * @param otra Variable de la clase termino a copiar
         */ 
        Termino(const Termino&);

        //Getters
        /**
         * @brief Devuelve el nombre del termino
         * @return palabra
         */
        string getPalabra() const;
        
        /**
         * @brief Devuelve todas las definiciones que hay
         * @return definicion Vector con las definiciones
         */
        vector<string> getDefinicionesAsociadas() const;

        /**
         * @brief Devuelve la cantidad de definiciones que hay
         * @return Un entero con la cantidad de definiciones
         */
        int getNAsociados() const;

        //string getDefinicion(int) const;


        //setters
        /**
         * @brief Cambia el nombre de palabra
         * @param palabra String
         */
        void setPalabra(const string);

        /**
         * @brief Cambia el nombre de palabra
         * @param defini Vector dinamico de tipo string
         */
        void setDefiniciones(const vector<string> defini);
        
        //Termino& operator=(const Termino &otra);

        /**
         * @brief Entrada de un termino desde istream
         * @param is stream de entrada
         * @param t termino que recibe el valor
         * @retval El termino leído en t
         */
        friend istream& operator>>(istream &is, Termino &t);

        /**
         * @brief Salida de un Termino a ostream
         * @param os stream de salida
         * @param t Termino a escribir
         * @post Se imprime el nombre del termino y a continuacion las definiciones asociadas
         */
        friend ostream& operator<<(ostream &os, const Termino &t);

        
        typedef vector<string>::iterator iterator;

        typedef vector<string>::const_iterator const_iterator;

        /**
         * @brief Devuelve un iterador al principio del segundo elemento
         *        del pair
         */
        vector<string>::iterator begin();

        /**
         * @brief Devuelve un iterador constante al principio del segundo 
         *        elemento del pair
         */
        vector<string>::const_iterator begin() const;

        /**
         * @brief Devuelve un iterador al final del segundo elemento
         *        del pair
         */
        vector<string>::iterator end();

        /**
         * @brief Devuelve un iterador constante al final del segundo 
         *        elemento del pair
         */
        vector<string>::const_iterator end() const;

        /**
         * @brief Sobrecarga del operador de comparacion
         */
        bool operator==(const Termino&) const;

        /**
         * @brief Sobrecarga del operador menor
         */
        bool operator<(const Termino& otra) const;

        /**
         * @brief Sobrecarga del operador mayor o igual
         */
        bool operator>=(const Termino&) const;

        /**
         * @brief Sobrecarga del operador menor o igual
         */
        bool operator<=(const Termino& otra) const;
};

#endif