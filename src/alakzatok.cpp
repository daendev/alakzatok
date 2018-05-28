#include "alakzatok.hpp"

double tavolsag(const Pont& a, const Pont& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double tavolsag(const Pont& pont, const Oldal& oldal){
    return tavolsag(pont,oldal.metszespont(Oldal(pont,oldal.getV().forgat())));
}

bool Negyzet::benne(const Pont& p) const {
    Oldal ab(getA(),getB()-getA());
    Oldal bc(getB(),getC()-getB());
    Oldal cd(getC(),getD()-getC());
    Oldal da(getD(),getA()-getD());
    return ab(p,kp) && bc(p,kp) && cd(p,kp) && da(p,kp);
}

bool Haromszog::benne(const Pont& p) const {
    Oldal a(getB(),getC()-getB());
    Oldal b(getA(),getC()-getA());
    Oldal c(getB(),getA()-getB());
    return a(p,kp) && b(p,kp) && c(p,kp);
}

bool Kor::benne(const Pont& p) const {
    return tavolsag(p,kp)<getR();
}

bool Negyzet::korben(double sugar) const {
    Pont origo(0,0);
    Kor k(origo,Pont(0,sugar),"ebben benne");
    Oldal ab(getA(),getB()-getA());
    Oldal bc(getB(),getC()-getB());
    Oldal cd(getC(),getD()-getC());
    Oldal da(getD(),getA()-getD());
    return benne(origo) || k.benne(getA()) || k.benne(getB()) || k.benne(getC()) || k.benne(getD()) ||
           tavolsag(origo,ab)<k.getR() || tavolsag(origo,bc)<k.getR()
           || tavolsag(origo,cd)<k.getR() || tavolsag(origo,da)<k.getR();
}

bool Haromszog::korben(double sugar) const {
    Pont origo(0,0);
    Kor k(origo,Pont(0,sugar),"ebben benne");
    Oldal c(getA(),getB()-getA());
    Oldal a(getB(),getC()-getB());
    Oldal b(getC(),getA()-getC());
    return benne(origo) || k.benne(getA()) || k.benne(getB()) || k.benne(getC()) ||
            tavolsag(origo,a)<k.getR() || tavolsag(origo,b)<k.getR()
           || tavolsag(origo,c)<k.getR();
}

bool Kor::korben(double sugar) const {
    return tavolsag(kp,Pont(0,0))<getR()+sugar;
}

Pont Oldal::metszespont(const Oldal& masik) const {
    if(fuggoleges) return Pont(p1.x,masik.p1.y);
    if(masik.fuggoleges) return Pont(masik.p1.x,p1.y);
    return Pont((masik.p1.y-p1.y+m*p1.x-masik.m*masik.p1.x)/(m-masik.m),
                (p1.y+(masik.p1.x-p1.x)*m-m/masik.m*masik.p1.y)/(1-m/masik.m));
}

Pont Oldal::getV() const {
    return p1-p2;
}

bool Oldal::operator()(const Pont& a, const Pont& kozep) const {
    if(fuggoleges) return kozep.x<p1.x ? a.x<p1.x : a.x>p1.x;
    else return kozep.y<m*(kozep.x-p1.x)+p1.y ? a.y<m*(a.x-p1.x)+p1.y : a.y>m*(a.x-p1.x)+p1.y;
}

Oldal::Oldal(const Pont& p, const Pont& iranyvektor): p1(p), p2(p+iranyvektor), fuggoleges(false) {
    if(p.x==(p+iranyvektor).x) fuggoleges=true;
    else m=iranyvektor.y/iranyvektor.x;
}
