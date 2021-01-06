#include <iostream>
#include "Cola_max_pila.h"
#include "Cola_max_pila.cpp"
#include <vector>


using namespace std;

int main(){
	
  Cola_max <int> p;
  p.poner(2);
  cout << "Se introduce el valor 2. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(3);
  cout << "Se introduce el valor 3. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(5);
  cout << "Se introduce el valor 5. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(4);
  cout << "Se introduce el valor 4. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(9);
  cout << "Se introduce el valor 9. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(7);
  cout << "Se introduce el valor 7. El maximo es " << p.maximo() << endl;
  p.imprime();

  p.poner(8);
  cout << "Se introduce el valor 8. El maximo es " << p.maximo() << endl;
  p.imprime();
   
  cout << "La cola tiene " << p.num_elementos() << " elementos. ";
  cout << "El maximo es " << p.maximo() << endl;

  while(!p.vacia()){
    cout << "El frente contiene " << p.frente() << ". ";
    cout << "El maximo es " << p.maximo() << ". ";
    p.quitar();
    cout << "Se quita este valor" << endl;
    p.imprime();
  }
 
  cout << "\n\n\n\n" ;

  Cola_max <float> q;
  q.poner(2.4);
  cout << "Se introduce el valor 2.4. El maximo es " << q.maximo() << endl;
  q.imprime();

  q.poner(5.5);
  cout << "Se introduce el valor 5.5. El maximo es " << q.maximo() << endl;
  q.imprime();

  q.poner(4.1);
  cout << "Se introduce el valor 4.1. El maximo es " << q.maximo() << endl;
  q.imprime();

  q.poner(9.6);
  cout << "Se introduce el valor 9.6. El maximo es " << q.maximo() << endl;
  q.imprime();

  q.poner(7.9);
  cout << "Se introduce el valor 7.9. El maximo es " << q.maximo() << endl;
  q.imprime();

  q.poner(8.3);
  cout << "Se introduce el valor 8.3. El maximo es " << q.maximo() << endl;
  q.imprime();
   
  cout << "La cola tiene " << q.num_elementos() << " elementos. ";
  cout << "El maximo es " << q.maximo() << endl;

  while(!q.vacia()){
    cout << "El frente contiene " << q.frente() << ". ";
    cout << "El maximo es " << q.maximo() << ". ";
    q.quitar();
    cout << "Se quita este valor" << endl;
    q.imprime();
  }

  return 0;
}
