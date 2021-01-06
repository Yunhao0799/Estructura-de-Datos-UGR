#include <iostream>
#include <list>

using namespace std;

template<class T>
class vector_dinamico{
	private:
		list<T> vector;
	
	public:
		//cte
		int size(){
			return vector.size();
		}
		
		//O(j)
		T& operator[](const int i){
			auto it = vector.begin();
			for(int j = 0; j < i; j++)
				it++;
			return *it;
		}
		
		//O(j)
		const T& operator[](const int i) const{
			auto it = vector.begin();
			for(int j = 0; j < i; j++)
				it++;
			return *it;
		}
		//cte
		void push(T dato){
			vector.push_back(dato);
		}
		
		//O(n)
		void resize(int tam){
			vector.resize(tam);
		}
		
		//cte
		int max_size(){
			return vector.max_size();
		}
		
		//cte
		T front(){
			return vector.front();
		}
		
		//cte
		T back(){
			return vector.back();
		}
		//vector_dinamico<T> operator
		
		//cte
		typename list<T>::iterator begin(){
			return vector.begin();
		}
		
		//cte
		typename list<T>::iterator end(){
			return vector.end();
		}
		
};

int main(){
	vector_dinamico<int> v;
	
	for(int i = 0; i < 10; i++)
		v.push(i);
		
	for(int i = 0; i < 10; i++)
		cout << v[i] << " ";
		
	cout << "\n\n\n";
	v[8] = 10;
	
	//v.resize(20);
	//cout << "\n" << v.max_size() << " ";
	
	for(int i = 0; i < 10; i++)
		cout << v[i] << " ";
		
	cout << "\n" << *(v.begin());
}
