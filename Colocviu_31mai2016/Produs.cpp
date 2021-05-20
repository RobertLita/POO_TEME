//
// Created by Robert on 19.05.2021.
//

#include "Produs.h"
unordered_map<string, float>Produs::preturi;
Produs::Produs(const string &produs, float pret): pretProdus(pret), denProdus(produs) {
    if(pret != 0 && preturi.find(produs) == preturi.end()){
        preturi[produs] = pret;
    }
}

Produs::Produs(): pretProdus(0), denProdus("-") {}

float Produs::getPret(const string &produs) {
    return preturi[produs];
}

ostream &operator<<(ostream &os, const Produs &produs) {
    os<<produs.denProdus<<".........." <<produs.pretProdus;
    return os;
}

const string &Produs::getDenProdus() const {
    return denProdus;
}


