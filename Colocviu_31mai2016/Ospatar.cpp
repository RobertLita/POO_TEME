//
// Created by Robert on 19.05.2021.
//

#include "Ospatar.h"

Ospatar::Ospatar(): Nume("-"), comenzi(), nr_comenzi(0), gen('-'), varsta(0){}

Ospatar::Ospatar(const string &nume, Comanda *com, int nr_com, char sex, int ani): Nume(nume), varsta(ani), gen(sex),
nr_comenzi(nr_com), comenzi(com) {}

ostream &operator<<(ostream &os, const Ospatar &ospatar) {
    os << "Ospatarul " << ospatar.Nume<< " in varsta de " << ospatar.varsta << " are " << ospatar.nr_comenzi << " comenzi.";
    return os;
}

const string &Ospatar::nume() const {
    return Nume;
}

bool Ospatar::operator>(const Ospatar &ospatar) const {
    if(nr_comenzi > ospatar.nr_comenzi){
        return true;
    }
    return false;
}

bool Ospatar::operator==(const Ospatar &ospatar) const {
    if(nr_comenzi == ospatar.nr_comenzi){
        return true;
    }
    return false;
}
