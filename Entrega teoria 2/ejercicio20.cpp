#include <map>
#include <iostream>

using namespace std;

int main(){
	map<pair<float, float>, int> contador;
	
	float a, b;
	for(int i = 0; i < 5; i++){
		cin >> a >> b;
		contador[make_pair(a, b)]++;
	}
	
	for(auto it = contador.begin(); it != contador.end(); ++it){
		cout << "Par: (" << (it->first).first << " , " << (it->first).second << ") veces: " << it -> second;
		cout << endl;
	}
}
