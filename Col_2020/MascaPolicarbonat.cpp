//
// Created by Robert on 28.05.2021.
//

#include "MascaPolicarbonat.h"

MascaPolicarbonat::MascaPolicarbonat():m_tip_prindere("-"), MascaChirurgicala() {}

MascaPolicarbonat::MascaPolicarbonat(const string &tip_prindere): m_tip_prindere(tip_prindere), MascaChirurgicala("ffp0","-",0) {}

ostream &operator<<(ostream &os, MascaPolicarbonat &m) {
    if(m.m_tip_prindere == "-"){
        os << "Masca fara date.\n";
    }
    else {
        m.tip_masca(os);
        os << " cu tipul de prindere: " << m.m_tip_prindere << ".\n";
    }
    return os;
}

void MascaPolicarbonat::tip_masca(ostream &os) {
    os << "Masca din policarbonat";
}

istream &operator>>(istream &is, MascaPolicarbonat &m) {
    cout << "Tip prindere:";
    is >> m.m_tip_prindere;
    m.m_nr_pliuri = 0;
    m.m_culoare = "-";
    m.m_tip_protectie = "ffs0";
    return is;
}

istream &operator>>(istream &is, MascaPolicarbonat *m) {
    is >> *m;
    return is;
}

ostream &operator<<(ostream &os, MascaPolicarbonat *m) {
    os << *m;
    return os;
}
