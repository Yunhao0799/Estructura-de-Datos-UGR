#include<iostream>
#include<vector>
#include<list>
#include<utility>
//#include <pair>

using namespace std;

template <typename T>
class vdisperso{
	private: 
		list<pair<int, T> > coefs;
		int n = 0, valor_nulo;
		
	public:
		vdisperso(const vector<T> &v, int valor_nulo){
			for(int i = 0; i < v.size(); i++){
				if(v[i] != valor_nulo){
					coefs.push_back(make_pair(i, v[i]));
				}
			}
			this -> valor_nulo = valor_nulo;
			n = v.size();
		}
		
		void asignar_coeficientes(int i, const T &x){
			bool insertado = 0;
			if(x == 0){
				//buscamos si existe esa posicion, y si si lo borramos
				bool encontrado = false;
				typename list<pair<int, T> >::iterator pos;
				for(auto it = coefs.begin(); it != coefs.end() && !encontrado; ++it){
					if((*it).first == i){
						pos = it;
						encontrado = 1;
					}
				}
				
				if(encontrado){
					coefs.erase(pos);
					//n--;
					insertado = 1;
				}
			}
			else{
				for(auto it = coefs.begin(); it != coefs.end() && !insertado; ++it){
					auto it2 = it;
					it2++;
					if((*it2).first > i){
						coefs.insert(it, make_pair(i, x));
						//n++;
						insertado = 1;
					}
					else if((*it2).first == i){
						(*it2).second = x;
						insertado = 1;
					}
				}
			}
		}
		
		vector<T> convertir() const{
			vector<T> salida;
			for(auto it = coefs.begin(); it != coefs.end(); it++){
				if(it == coefs.begin()){
					for(int i = 0; i < (*it).first; i++)
						salida.push_back(valor_nulo);
					salida.push_back((*it).second);
				}
				else{
					auto aux = it;
					--aux;
					for(int i = (*aux).first; i < (*it).first - 1; i++)
						salida.push_back(valor_nulo);
						
					salida.push_back((*it).second);
				}
			}
			
			if(salida.size() < n){
				for(int i = salida.size(); i < n; i++)
					salida.push_back(valor_nulo);
			}
			return salida;
		}
		
		void imprime(){
			//cout << "Total de elementos del vector original: " << n << endl;
			cout << "< ";
			for(typename list<pair<int, T> >::iterator it = coefs.begin(); it != coefs.end(); ++it){
				cout << "(" << (*it).first << " , " << (*it).second << ") ";
			}
			cout << " >\n";
		}
		
		void cambiar_nulo(const T &x){
			this -> valor_nulo = x;
		}
};

int main(){
	vector<int> v = {1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 6, 1, 8, 1, 9, 1, 1};
	vdisperso<int> disperso(v, 1);
	disperso.imprime();
	
	vector<int> v2 = disperso.convertir();
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
		
	disperso.asignar_coeficientes(1, 123);
	disperso.asignar_coeficientes(6, 9);
	cout << endl;
	
	disperso.imprime();
	cout << endl;
	v2 = disperso.convertir();
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	
	disperso.cambiar_nulo(0);
	disperso.imprime();
	cout << endl;
	v2 = disperso.convertir();
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	
}
