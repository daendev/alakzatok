#include "fvek.h"
#include <string>
#include <sstream>
#include <stdexcept>

void beolvas(std::istream& fin,std::list<Alakzat*>& tar){
    std::string sor,n,t;
    int sorszam=1;
    Pont kp,cs;
    Alakzat* uj_alakzat;
    std::string hiba("Ervenytelen adat a ");
    std::ostringstream sorszamstring;
    Kor egysegkor(Pont(0,0),Pont(1,0),"egysegkor");

    while(std::getline(fin,sor)){
        std::stringstream ss;
        ss<<sor;
        if(!(ss>>n>>t>>kp>>cs)){
            sorszamstring<<sorszam;
            throw std::invalid_argument((hiba+sorszamstring.str()+". sorban.\n").c_str());
        }
        if     (t=="Negyzet")
            uj_alakzat=new Negyzet(kp,cs,n.c_str());
        else if(t=="Haromszog")
            uj_alakzat=new Haromszog(kp,cs,n.c_str());
        else if(t=="Kor")
            uj_alakzat=new Kor(kp,cs,n.c_str());
        else {
            sorszamstring<<sorszam;
            throw std::invalid_argument((hiba+sorszamstring.str()+". sorban.\nRossz alakzat tipus.\n").c_str());
        }
        if(!uj_alakzat->korben(1)) tar.push_back(uj_alakzat);
        else delete uj_alakzat;
        ++sorszam;
    }
}
