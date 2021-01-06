#ifndef LETRAS
#define LETRAS

#include <iostream>
#include<string>

using namespace std;

/**
 * @brief T.D.A Letras
 *  Nos permite guardar la letra, las veces que puede aparecer, y los puntos que tiene esa letra
 * 
 * @author Yunhao Lin
 */

class letras{
    private:
        char letter;
        int time_can_be_appeared;
        int points;
    public:
        /**
         * @brief Construct a new letras object
         * 
         */
        letras();

        /**
         * @brief Construct a new letras object
         * 
         * @param letter Letra, tipo char
         * @param times Veces que puede aparecer, tipo int
         * @param points Puntos que se le da a esa letra, tipo int
         */
        letras(char letter, int times, int points);

        /**
         * @brief Devuelve la letra
         * 
         * @return char Atributo letras
         */
        char getLetter() const;

        /**
         * @brief Devuelve las veces que puede aparecer una letra
         * 
         * @return int Veces que puede aparecer
         */
        int getTimes() const;

        /**
         * @brief Devuelve los puntos que vale esa letra
         * 
         * @return int Punto de la letra
         */
        int getPoints() const;

    	/**
    	 * @brief Sobrecarga del operador de entrada
    	 * 
    	 * @param is Flujo de entrada
    	 * @param l Objeto de la clase letras
    	 * @return istream& Flujo de entrada
    	 */
        friend istream& operator>>(istream &is, letras &l);

        /**
         * @brief Sobrecarga del operador de salida
         * 
         * @param os Flujo de salida
         * @param l objeto de la clase letras
         * @return ostream& Flujo de salida
         */
        friend ostream& operator<<(ostream &os, const letras &l);

        /**
         * @brief Sobrecarga del operador <
         * 
         * @param l Objeto de la clase letras
         * @return true Si es menor
         * @return false Si es mayor o igual
         */
        bool operator<(const letras &l)const; 
};
#endif
