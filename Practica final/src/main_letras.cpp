#include<iostream>
#include "lista_palabras.h"
#include "bolsa_letras.h"
#include <fstream>
#include <ctype.h>

using namespace std;

bool repeated_letters(string user_solution, string generated_letters){
    string user_solution_aux = user_solution;

    for(unsigned int i = 0; i < user_solution_aux.size(); i++)
        user_solution_aux[i] = toupper(user_solution_aux[i]);
            
    bool not_belong = false;
    string aux = generated_letters;
    for(unsigned int i = 0; i < user_solution_aux.size() && !not_belong; i++){
        
        int pos = aux.find(user_solution_aux[i]);
        if(pos != string::npos)
            aux.erase(pos, 1);
        else 
           not_belong = true;
    }

    return not_belong;
}

int main(int argc, char *argv[]){
/*
    prompt% letras spanish letras.txt 8 L

    1. El nombre del fichero con lista_palabras
    2. El nombre del fichero con las letras.
    3. El número de letras que se deben generar de forma aleatoria.
    4. Modalidad de juego: 
        Longitud: Si el parámetro es L se buscará la palabra más larga
        Puntuación: Si el parámetro es P se buscará la palabra de mayor puntuación.
*/
    if(argc != 5){
        cout << "Falta parametros \n";
        return 0;
    }

    //cargamos la lista de palabras
    ifstream archivo_lista_palabras(argv[1]);

    if(!archivo_lista_palabras){
        cout << "No se pudo abrir el fichero " << argv[1] << endl;
        return 0;
    }

    lista_palabras lista;
    archivo_lista_palabras >> lista;

    //cargamos nombre del archivo con las letras
    ifstream archivo_letras(argv[2]);
    if(!archivo_letras){
        cout << "No se pudo abrir el fichero "  << argv[2] << endl;
        return 0;
    }

    conjunto_letras letras;
    archivo_letras >> letras;

    int letters_to_generate = atoi(argv[3]);
    char game_mode = argv[4][0];
    game_mode = toupper(game_mode);

    //cout << "Tipo de juego " << game_mode << endl;
    if(game_mode != 'P' && game_mode != 'L'){
        cout << "No existe el modo de juego especificado \n";
        return 0;
    }

    bolsa_letras bolsa(letras);
    cout << endl;
    //cout << bolsa << endl;


    
    char keep_playing;
    do{
        cout << "\n\n\n\n";
        cout << "Iniciando juego\n";

        cout << endl;
        if(game_mode == 'P')
            cout << letras;

        cout << "Las letras generadas son:  ";
        string generated_letters = bolsa.letters_generator(letters_to_generate);

        for(unsigned int i = 0; i < generated_letters.size(); i++)
            cout << " " << generated_letters[i]; 

        cout << endl;

        string user_solution;
        do{
            cout << "Introduzca tu solucion \n";
            cin >> user_solution;
            if(user_solution.size() > (unsigned)letters_to_generate)
                cout << "Tu solucion tiene mas letras que las generadas \n";
        }while(user_solution.size() > (unsigned)letters_to_generate);
        
        bool not_belong = repeated_letters(user_solution, generated_letters);
        if(not_belong)
            cout << "Has empleado una letra que no se podia usar o lo has usado dos veces \n";
        else{
            if(lista.esta(user_solution)){

                //if(user_solution.size() > (unsigned)letters_to_generate)
                //    cout << "!!! Esa palabra es mas grande que las letras generadas !!!\n";
                cout << endl;
                //SOLUCION DEL USUARIO
                cout << user_solution << "  " << "Puntuacion: ";
                cout << letras.puntuacion(user_solution, game_mode) << endl;
                
            }
            else{
                cout << user_solution << " no esta en el diccionario   Puntuacion: 0 \n";
            }
        }

        cout << endl;

        //SOLUCIONES DEL SISTEMA
        cout << "Mis soluciones son: \n";  
        vector<string> ai_solutions = lista.palabras_con_las_letras_dadas(generated_letters);
        letras.print_ai_solutions(ai_solutions, game_mode);
        cout << endl;

        do{
            cout << "Desea seguir jugando? S o N \n"; 
            cin >> keep_playing;
            keep_playing = toupper(keep_playing);
        }while(keep_playing != 'N' && keep_playing != 'S');
        
        
        

    }while(keep_playing != 'N');

}