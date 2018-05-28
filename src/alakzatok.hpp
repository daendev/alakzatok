#ifndef ALAKZATOK_HPP_INCLUDED
#define ALAKZATOK_HPP_INCLUDED

#include "pont.hpp"
#include <math.h>



class Alakzat {

protected:
    Pont kp;
    Pont cs;
    std::string nev;
    std::string tipus;

public:

    Alakzat(Pont kozeppont, Pont csucs, const char* n, const char* t): kp(kozeppont), cs(csucs), nev(n), tipus(t) {}

    virtual bool benne(const Pont&) const = 0;

    virtual bool korben(double) const = 0;

    friend std::ostream& operator<<(std::ostream& o, const Alakzat& a){
        return o<<a.nev<<" "<<a.tipus<<" "<<a.kp<<" "<<a.cs;
    }

    virtual ~Alakzat() {}
};



struct Negyzet : public Alakzat {

    Negyzet(Pont kozeppont, Pont csucs, const char* n): Alakzat(kozeppont,csucs,n,"Negyzet") {}

    inline Pont getA() const;
    inline Pont getB() const;
    inline Pont getC() const;
    inline Pont getD() const;

    bool benne(const Pont&) const;
    bool korben(double) const;
};



struct Haromszog : public Alakzat {

    Haromszog(Pont kozeppont, Pont csucs, const char* n): Alakzat(kozeppont,csucs,n,"Haromszog") {}

    inline Pont getA() const;
    inline Pont getB() const;
    inline Pont getC() const;

    bool benne(const Pont&) const;
    bool korben(double) const;
};



struct Kor : public Alakzat {

    Kor(Pont kozeppont, Pont csucs, const char* n): Alakzat(kozeppont,csucs,n,"Kor") {}

    inline double getR() const;

    bool benne(const Pont&) const;
    bool korben(double) const;
};



class Oldal {
    double m;
    const Pont& p1;
    const Pont& p2;
    bool fuggoleges;
public:

    Oldal(const Pont& p, const Pont& iranyvektor);

    bool operator()(const Pont&, const Pont&) const;

    Pont metszespont(const Oldal&) const;

    inline Pont getV() const;
};




inline double tavolsag(const Pont&, const Pont&);
inline double tavolsag(const Pont&, const Oldal&);

Pont Negyzet::getA() const {
    return cs;
}

Pont Negyzet::getB() const {
    return kp+(kp-cs).forgat();
}

Pont Negyzet::getC() const {
    return cs+(kp-cs)*2;
}

Pont Negyzet::getD() const {
    return kp+(kp-cs).forgat(3);
}

Pont Haromszog::getA() const {
    return cs;
}

Pont Haromszog::getB() const {
    return cs+(kp-cs)*3/2+((kp-cs).forgat())*sqrt(3)/2;
}

Pont Haromszog::getC() const {
    return cs+(kp-cs)*3/2+((kp-cs).forgat(3))*sqrt(3)/2;
}

double Kor::getR() const {
    return tavolsag(kp,cs);
}



#endif // ALAKZATOK_HPP_INCLUDED
