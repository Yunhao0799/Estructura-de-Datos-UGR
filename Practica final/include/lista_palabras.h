#ifndef LISTA_PALABRAS
#define LISTA_PALABRAS

#include<iostream>
#include<set>
#include<vector>
#include <map>
#include <string>

using namespace std;

class lista_palabras{
    private:
        set<string> diccionario;

    public:
        /**
         * @brief Constructor sin parametros
         * 
         */
        lista_palabras();

        /**
         * @brief Constructor de copia
         * 
         * @param otra 
         */
        lista_palabras(const lista_palabras &otra);

        /**
         * @brief Constructor por parametros
         * 
         * @param palabra 
         */
        lista_palabras(const string &palabra);

        /**
         * @brief Inserta nueva palabra
         * 
         * @param palabra 
         */
        void insert(const string &palabra);

        /**
         * @brief Elimina una palabra dada
         * 
         * @param palabra 
         */
        void erase(const string &palabra);

        /**
         * @brief Get the all object
         * 
         * @return set<string> 
         */
        set<string> get_all() const;

        /**
         * @brief Sobrecarga operador de salida
         * 
         * @param os 
         * @param l 
         * @return ostream& 
         */
        friend ostream& operator<<(ostream &os, const lista_palabras &l);

        /**
         * @brief Sobrecarga operador de entrada
         * 
         * @param is 
         * @param l 
         * @return istream& 
         */
        friend istream& operator>>(istream &is, lista_palabras &l);

        /**
         * @brief Iterador al principio const
         * 
         * @return set<string>::iteratos 
         */
        set<string>::iterator begin() const;

        /**
         * @brief Iterador al principio
         * 
         * @return set<string>::iterator 
         */
        set<string>::iterator begin();

        /**
         * @brief Iterador al final
         * 
         * @return set<string>::iterator 
         */
        set<string>::iterator end();

        /**
         * @brief Iterador al final
         * 
         * @return set<string>::iterator 
         */
        set<string>::iterator end() const;

        /**
         * @brief Devuelve un vector con las palabras de esa longitud
         * 
         * @param longitud 
         * @return vector<string> 
         */
        vector<string> palabras_longitud(const int &longitud) const;

        //BST<char, string> palabras_longitud_bst(const int &longitud) const;

        /**
         * @brief Nos dice si existe una palabra
         * 
         * @param palabra 
         * @return true 
         * @return false 
         */
        bool esta(const string& palabra) const;

        /**
         * @brief Devuelve el numero de palabras en el lista_palabras
         */
        int size() const;

        /**
         * @brief Nos genera las palabras que contienen las letras dadas
         * 
         * @param generated_chars Letras que tienene que contener las palabras
         * @return vector<string> Soluciones con las letras dadas
         */
        vector<string> palabras_con_las_letras_dadas(const string &generated_chars) const;

        /**
         * @brief Metodo que nos permite saber el total de veces que aparece cada letra
         * 
         * @param m Mapa que nos permite contar las letras, pasado por referencia
         * @param total_chars Variable que nos permite saber cuantas letras hay en nuestro diccionario, pasado por referencia
         */
        void count(map<char, double > &m, int &total_chars);


};

/**
 * @brief Sobrecarga del operador <= de los mapas
 *  El objetivo de la sobrecarga es que si un mapa es mas pequeño que otro, y 
 *  ademas teniendo los mismos indices y menor o igual tamaño, es decir todos 
 *  los indices del mapa primero tiene que estar contenido en el segundo mapa
 * 
 * @param m1 Mapa 1
 * @param m2 Mapa 2
 * @return true Si m1 es <= m2
 * @return false Si m2 > m1
 */
bool operator<=(const map<char, int> &m1, const map<char, int> &m2);


#endif