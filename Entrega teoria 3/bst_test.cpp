#include <iostream>
#include "bst.h"

#include <map>

using namespace std;

bool operator<=(const map<char, int> &m1, const map<char, int> &m2){
			map<char, int> aux_m1 = m1, aux_m2 = m2;
    		int elements_m1 = 0, elements_m2 = 0;
    		bool less_equal = true;
    		
    		//if m1 have more elements than m2, that means that m1 have an letter 
			//that m2 does not have
    		
    		if(m1.size() > m2.size()){
    			less_equal = false;
    			return less_equal;
			} 
			
			for(char c = 'a'; c <= 'z' && less_equal; c++){
				if(aux_m1[c] > aux_m2[c])
					less_equal = false;
			}
			
			
    		return less_equal;
}

const int NUM = 3;
int main(){
	/*BST<string, string> arb;
	 string palabras[NUM] = {"piedra", "tiza", "cosa"};
	 string definiciones[NUM] = {"objeto muy duro",
	 "objeto muy blando", "obj"};
	 for (int i= 0; i<NUM; i++)
	 arb.insert(pair<string,string>(palabras[i],
	 definiciones[i]));
	 cout << "Num.datos: " << arb.size() << endl;
	 BST<string, string>::iterator i;
	 for (i = arb.begin(); i != arb.end(); ++i)
	 cout << (*i).first << ": " << (*i).second << endl;*/
	 
	 //cout << (*(arb.find("tiza"))).second;
	 
	/*for(int i = 0; i < 100; i++)
	  cout << (char)('A' + rand()%26) << endl;*/
	  
	  /*
	  string generated_letters = "UHETDPFA", user_solution = "UHH";
	  
	  string aux = generated_letters;
	  bool not_belong = false;
        for(int i = 0; i < user_solution.size() && !not_belong; i++){
            
            int pos = aux.find(user_solution[i]);
            if(pos != string::npos)
                aux.erase(pos, 1);
            else 
                not_belong = true;
                
            cout << aux << endl;
        }

        if(not_belong)
            cout << "Has empleado una letra que no se podia usar \n";*/
            
        
            
	string generated_chars = "eholl";

    vector<string> out;
    map<char, int> given_string_map;
    for(int i = 0; i < generated_chars.size(); i++)
        given_string_map[generated_chars[i]]++;
        
    vector<string> dic = {"hellos", "hello", "bye", "ole"};

    for(int k = 0; k < dic.size(); k++){
        //build map for (*it)*/
        string aux_dic = dic[k];
        map<char, int> aux_dic_map;
        for(int i = 0; i < aux_dic.size(); i++)
            aux_dic_map[aux_dic[i]]++;

        if(aux_dic_map <= given_string_map)
            out.push_back(aux_dic);
	}
    cout << "Secuencia dada: " << generated_chars << endl;
    cout << "Diccionario \n";
    for(int i = 0; i < dic.size(); i++){
    	cout << dic[i] << endl;
	}
	cout << "\n\n\n";
    cout << "combinaciones posible \n";
    for(int i = 0; i < out.size(); i++){
    	cout << out[i] << endl;
	}

	

}
        
        

