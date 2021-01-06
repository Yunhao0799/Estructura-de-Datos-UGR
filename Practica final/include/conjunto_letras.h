#ifndef CINJUNTO_LETRAS
#define CONJUNTO_LETRAS

#include <set>
#include<iostream>
#include "letras.h"
#include <vector>
#include <map>
#include<ctime>
#include <string>

/**
 * @brief T.D.A Conjunto_letras
 *      Como su nombre indica, guarda letras
 *      
 * @author Yunhao Lin
 */

class conjunto_letras{
    private:
        set<letras> letters;

    public:
        /**
         * @brief Construct a new conjunto letras object
         * 
         */
        conjunto_letras();

        /**
         * @brief Get the Letters object
         * 
         * @return set<letras> Atributo privado
         */
        set<letras> getLetters() const;

        /**
         * @brief Inserta nueva letra
         * 
         * @param l Objeto de la clase letras
         */
        void push(const letras &l);

        /**
         * @brief Inserta nueva letra
         *  Se pasa como argumento los valores para construir una nueva
         *  letra y posteriormente insertarlo en la lista
         * 
         * @param c De tipo char
         * @param t De tipo int
         * @param p De tipo int
         */
        void push(const char c, const int t, const int p);

        /*set<letras>::iterator begin();

        set<letras>::const_iterator begin();

        set<letras>::iterator end();

        set<letras>::const_iterator end();*/

        /**
         * @brief Sobrecarga del operador de entrada
         * 
         * @param is Flujo de entrada
         * @param c Objeto de la clase conjunto letras
         * @return istream& Flujo de entrada
         */
        friend istream& operator>>(istream &is, conjunto_letras &c);
        
        /**
         * @brief Sobrecarga del operador de salida
         * 
         * @param os Flujo de salida
         * @param c Objeto de la clase conjunto de letras
         * @return ostream& Flujo de salida
         */
        friend ostream& operator<<(ostream &os, const conjunto_letras &c);

        /**
         * @brief Metodo que nos calcula la puntuacion de una palabra dada
         * 
         * @param word1 Palaba a la cualle vamos a calcular la puntuacion
         * @param game_mode Tipo de juego, por puntuacion o por longitud
         * @return int Puntuancion de esa palabra
         */
        int puntuacion(const string &word1, char game_mode) const;

        /**
         * @brief Metodos que nos sirve para imprimir las soluciones que ha encontrado el sistema
         * 
         * @param ai_solutions Soluciones del sistema
         * @param game_mode Tipo de juego
         */
        void print_ai_solutions(const vector<string> ai_solutions, const char game_mode);


};
#endif