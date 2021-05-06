//
// Created by Robert on 04.05.2021.
//

#include "Sala.h"

Sala::Sala(): Incapere(), tipScena(false), tipMese(false), areProiector(false) {}

Sala::Sala(const string &tip, bool proiector): Incapere(200) , areProiector(proiector){
    if(tip == "scena"){
        tipMese = false;
        tipScena = true;
    }
    else{
        tipMese = true;
        tipScena = false;
    }
}

ostream &operator<<(ostream &os, const Sala &sala) {
    os << "Sala cu numarul "<<sala.m_id_incapere;
    if(sala.tipMese){
        os<<" are mese individuale";
    }
    else os<<" are scena";
    if(sala.areProiector)os<<" si proiector.";
    else os<<".";
    return os;
}

