#ifndef PONT_HPP_INCLUDED
#define PONT_HPP_INCLUDED

#include <iostream>

class Pont {
public:
    double x,y;
    Pont(double x=0, double y=0): x(x), y(y) {}

    inline Pont operator+(const Pont& that) const;
    inline Pont operator++(int);
    inline Pont operator++();
    inline Pont operator+=(const Pont& that);

    inline Pont operator-(const Pont& that) const;
    inline Pont operator--(int);
    inline Pont operator--();
    inline Pont operator-=(const Pont& that);

    inline Pont operator*(double that) const;
    inline Pont operator*=(double that);

    inline Pont operator/(double that) const;
    inline Pont operator/=(double that);

    friend std::ostream& operator<<(std::ostream& o, const Pont& p){
        return o << p.x << ";" << p.y;
    }

    friend std::istream& operator>>(std::istream& i, Pont& p){
        double a;
        i>>a;
        p.x=a;
        i.ignore(1,';');
        i>>a;
        p.y=a;
        return i;
    }

    inline Pont forgat(int hanyszor=1) const;

};

Pont Pont::operator+(const Pont& that) const {
    return Pont(x+that.x,y+that.y);
}

Pont Pont::operator++(){
    ++x;
    ++y;
    return *this;
}

Pont Pont::operator++(int){
    Pont temp=*this;
    ++(*this);
    return temp;
}

Pont Pont::operator+=(const Pont& that){
    Pont temp=*this;
    *this=*this+that;
    return temp;
}

Pont Pont::operator-(const Pont& that) const {
    return Pont(x-that.x,y-that.y);
}

Pont Pont::operator--(){
    --x;
    --y;
    return *this;
}

Pont Pont::operator--(int){
    Pont temp=*this;
    --*this;
    return temp;
}

Pont Pont::operator-=(const Pont& that){
    Pont temp=*this;
    *this=*this-that;
    return temp;
}

Pont Pont::operator*(double that) const {
    return Pont(x*that,y*that);
}

Pont Pont::operator*=(double that){
    Pont temp=*this;
    *this=*this*that;
    return temp;
}

Pont Pont::operator/(double that) const {
    return Pont(x/that,y/that);
}

Pont Pont::operator/=(double that){
    Pont temp=*this;
    *this=*this/that;
    return temp;
}

Pont Pont::forgat(int hanyszor) const {
    Pont uj(x,y);
    double temp;
    for(int i=0;i<hanyszor;++i){
        temp = uj.x;
        uj.x = uj.y*(-1);
        uj.y = temp;
    }
    return uj;
}

#endif // PONT_HPP_INCLUDED
