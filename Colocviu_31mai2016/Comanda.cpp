//
// Created by Robert on 19.05.2021.
//

#include "Comanda.h"

int Comanda::Num;

Comanda::Comanda(): Prod(), data(), nrPortii(0), nr_comanda(++Num){}

Comanda::Comanda(const string& p, int portii, int zi, int luna, int an): Prod(p, Produs::getPret(p)), nrPortii(portii), data(19, 5 , 2021),
                                                                         nr_comanda(++Num){}

Comanda& Comanda::operator+(int x) {
    nrPortii+=x;
    return *this;
}

Comanda &Comanda::operator++() {
    nrPortii++;
    return *this;
}

Comanda Comanda::operator++(int) {
    Comanda t = *this;
    ++*this;
    return t;
}

void Comanda::del() {
    nrPortii=0;
    Produs p;
    Prod=p;
    data.an = data.zi = data.luna = 0;
}

istream &operator>>(istream &is, Comanda &c) {
    string nume;
    cout<<"Numele produsului:";
    is>>nume;
    Produs p(nume, Produs::getPret(nume));
    c.Prod = p;
    cout<<"Numarul de portii:";
    is>>c.nrPortii;
    c.data.zi = 19;
    c.data.luna = 5;
    c.data.an = 2021;
    return is;
}

ostream &operator<<(ostream &os, const Comanda &comanda) {
    if(comanda.nrPortii != 0) {
        os << "Comanda cu numarul " << comanda.nr_comanda << " din data de " << comanda.data.zi << '.'
           << comanda.data.luna << '.' << comanda.data.an << ":\n";
        const string nume = comanda.Prod.getDenProdus();
        os << comanda.nrPortii << "x " << nume << ".............." << comanda.nrPortii * Produs::getPret(nume);
    }
    else{
        os << "Comanda inexistenta.";
    }
    return os;
}

const Produs &Comanda::getProd() const {
    return Prod;
}

float Comanda::getPret() {
    return nrPortii * Produs::getPret(Prod.getDenProdus());
}

const Comanda::Data &Comanda::getData() const {
    return data;
}

int Comanda::getNrPortii() const {
    return nrPortii;
}






