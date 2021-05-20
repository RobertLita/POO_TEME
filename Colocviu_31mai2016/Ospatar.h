//
// Created by Robert on 19.05.2021.
//

#ifndef COLOCVIU_31MAI2016_OSPATAR_H
#define COLOCVIU_31MAI2016_OSPATAR_H

#include <iostream>
#include "Comanda.h"
#include <vector>
using namespace std;

class Ospatar {
private:
    string Nume;
    int nr_comenzi, varsta;
    char gen;
    Comanda* comenzi;
public:
    Ospatar();
    Ospatar(const string& nume,Comanda* com, int nr_com, char sex, int ani);
    friend ostream &operator<<(ostream &os, const Ospatar &ospatar);
    bool operator>(const Ospatar &ospatar) const;
    bool operator==(const Ospatar &ospatar) const;
    const string &nume() const;
};


#endif //COLOCVIU_31MAI2016_OSPATAR_H
