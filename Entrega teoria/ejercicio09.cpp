/*
Dada una matriz que representa un laberinto, construye una función que determine si se
puede llegar desde la entrada hasta la salida. Esta matriz tendrá una ’E’ en la entrada, una ’S’
en la salida, un ’0’ en las casillas por las que se pueda pasar y un ’1’ en las que no. No se
puede ir en diagonal.
? bool salida_laberinto(char laberinto[][], int n_filas, int n_cols)
*/

#include<iostream>

using namespace std;

pair<int, int> siguiente_movimiento(char laberinto[][100], int n_filas, int n_colas, pair<int, int> pos){
	pair<int, int> siguiente;
	//bool insispensable1 = pos.first = 1 >= 0 && pos.first < n_filas;
	if(laberinto[pos.first + 1][pos.second] == '0' && pos.first + 1 >= 0 && pos.first + 1 < n_filas){
		pair<int,int> nuevo(pos.first + 1, pos.second);
		siguiente = nuevo;
	}
	else if(laberinto[pos.first - 1][pos.second] == '0' && pos.first - 1 >= '0' && pos.first - 1 < n_filas){
		pair<int,int> nuevo(pos.first - 1, pos.second);
		siguiente = nuevo;
	}
	else if(laberinto[pos.first][pos.second + 1] != '0' && pos.second + 1 >= '0' && pos.second + 1 < n_colas){
		pair<int,int> nuevo(pos.first, pos.second + 1);
		siguiente = nuevo;
	}
	else if(laberinto[pos.first][pos.second - 1] == '0' && pos.second - 1 >= '0' && pos.second - 1 < n_colas){
		pair<int,int> nuevo(pos.first, pos.second - 1);
		siguiente = nuevo;
	}
	else{
		pair<int, int> ini(1, 0);
		siguiente = ini;
	}
	
	
	return siguiente;
}

bool salida_laberinto(char laberinto[][100], int n_filas, int n_cols){
	pair<int, int> inicio(1,0);
	pair<int, int> pos;
	pos = siguiente_movimiento(laberinto, n_filas, n_cols, inicio);
	while(laberinto[pos.first][pos.second] != 'S'){
		laberinto[pos.first][pos.second] = '2';
		pos = siguiente_movimiento(laberinto, n_filas, n_cols, inicio);
	}
}



void imprimir(char m[][100], int f, int c){
	cout << endl;
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++)
			cout << m[i][j] << "	";
		
		cout << endl;
	}
	cout << endl;
}

int main(){
	char maze[][100] = {{'1', '1', '1', '0', '1'},
					   {'E', '0', '0', '1', '1'},//[1][0];
					   {'1', '1', '0', '0', 'S'}, //[2][4];
					   {'1', '1', '1', '0', '1'}};
	const int FILAS = 4, COLS = 5; 
	
	imprimir(maze, FILAS, COLS);
	
	pair<int, int> ini(1, 0);
	pair<int, int> pos(1, 0);
	while(maze[pos.first][pos.second] != 'S'){
		if(siguiente_movimiento(maze, FILAS, COLS, pos) == ini){
			maze[pos.first][pos.second] = '2';
		}
		pos = siguiente_movimiento(maze, FILAS, COLS, pos);
		
		
		cout << pos.first << pos.second;
	
	}
	
	
	/*if(salida_laberinto(maze, FILAS, COLS))
		imprimir(maze, FILAS, COLS);
	else
		cout << "No solucion";*/
}
