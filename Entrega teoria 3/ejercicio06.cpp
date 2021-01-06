#include <iostream>
#include "bintree.h"
#include <queue>
#include <cmath>
#include <map>

using namespace std;


int evalua(const bintree<char> &Arb, map<char, int> &valores){
	char a = *(Arb.root().left()), b = *(Arb.root().right());
	switch (*(Arb.root())){
		case '*':
			return (valores[a] * valores[b]);
			break;
		case '+':
			return (valores[a] + valores[b]);
			break;
		case '-':
			return (valores[a] - valores[b]);
			break;
		case '/':
			return (valores[a] / valores[b]);
			break;
	}
}

int main(){
	map<char, int> val;
	val['a'] = 10;
	val['b'] = 50;
	bintree<char> tree('-');
	tree.insert_left(tree.root(), 'b');
	tree.insert_right(tree.root(), 'a');
	
	cout << evalua(tree, val);
}
