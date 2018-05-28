#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "alakzatok.hpp"
#include "pont.hpp"
#include "fvek.h"

using namespace std;

int main () {

  try {
        string fajlnev;
        cout<<"Kerem a file nevet: ";
        if(!(cin>>fajlnev)) throw runtime_error("Bemeneti hiba");
        ifstream fajl (fajlnev.c_str());
        list<Alakzat*> alakzatlista;
        if(!fajl.is_open()) throw runtime_error("Hiba a fajl megnyitasa soran");
        beolvas(fajl,alakzatlista);

        for(list<Alakzat*>::iterator i=alakzatlista.begin();i!=alakzatlista.end();++i){
            cout<<**i<<endl;
            delete *i;
        }

  } catch (exception& e) {
    cout<<e.what();
  }
  return 0;
}
