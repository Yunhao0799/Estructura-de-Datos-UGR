#ifndef BOLSA_LETRAS
#define BOLSA_LETRAS

#include <iostream>
#include "conjunto_letras.h"
#include <map>
#include <cstdlib>
#include <random>

using namespace std;

/**
 * @brief T.D.A Bolsa_letras
 *      Este T.D.A almacena las letras, y las veces que puede generar 
 *      cada letra
 * 
 * @author Yunhao Lin
 */

class bolsa_letras{
    private:
        map<char, int> values;

    public:
        /**
         * @brief Construct a new bolsa letras object
         * 
         */
        bolsa_letras();

        /**
         * @brief Construct a new bolsa letras object
         *  
         * @param c Del tipo conjunto_letras
         */
        bolsa_letras(const conjunto_letras &c);

        //void insert(const conjunto_letras &c);

        /**
         * @brief Devuelve el atributo privado
         * 
         * @return map<char, int> 
         */
        map<char, int> getAll() const;

        /**
         * @brief Sobrecarga del operador de salida
         * 
         * @param os  Flujo de salida
         * @param b Bolsa de letras a imprimir
         * @return ostream&  Devuelve el flujo
         */
        friend ostream& operator<<(ostream &os, const bolsa_letras &b);

        /**
         * @brief Metodo que nos genera un string
         *      con n letras aleatorias
         * 
         * @param quantity Cantidad de letras aleatorias a generar
         * @return string Letras aleatorias generadas
         */
        string letters_generator(int quantity);
};

#endif