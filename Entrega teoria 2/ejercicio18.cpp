#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<class T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){
	int times;
	T valor;
	for(auto it = pos.begin(); it != pos.end(); ++it){
		auto aux = v.begin();
		advance(aux, it -> first);
		v.insert(aux, it -> second);
	}
}


int main(){
	vector<int> v = {1,1,1,2,2,2,2,2,2,7,7,7,7,7,12,1,1,5,5};
	vector<pair<int, int> > pos;
	pos.push_back(make_pair(2, 333));
	pos.push_back(make_pair(9, 5123));
	
	intercalar(v, pos);
	
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
