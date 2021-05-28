//
// Created by Robert on 28.05.2021.
//

#include "MascaChirurgicala.h"

MascaChirurgicala::MascaChirurgicala(): m_nr_pliuri(0), m_tip_protectie("-"), m_culoare("-") {}

MascaChirurgicala::MascaChirurgicala(const string& tip_protectie, const string &culoare, int nr_pliuri): m_tip_protectie(tip_protectie), m_nr_pliuri(nr_pliuri), m_culoare(culoare) {}

istream &operator>>(istream &is, MascaChirurgicala &m) {
    string culoare, tip_protectie;
    int nr_pliuri;
    cout << "Tipul de protectie al mastii:";
    is >> tip_protectie;
    cout << "Culoarea mastii:";
    is >> culoare;
    cout << "Numarul de pliuri ale mastii:";
    is >> nr_pliuri;
    m.m_nr_pliuri = nr_pliuri;
    m.m_tip_protectie = tip_protectie;
    m.m_culoare = culoare;
    return is;
}

ostream &operator<<(ostream &os, MascaChirurgicala &m) {
    if(m.m_tip_protectie == "-" && m.m_nr_pliuri == 0)
    {
        os << "Masca fara date.\n";
    }
    else{
        m.tip_masca(os);
        os << "cu tipul de protectie " << m.m_tip_protectie << ", de culoare " << m.m_culoare << " si " << m.m_nr_pliuri << " pliuri.\n";
    }

    return os;
}

void MascaChirurgicala::tip_masca(ostream &os) {
    os << "Masca chirurgicala ";
}

const string &MascaChirurgicala::getTipProtectie() const {
    return m_tip_protectie;
}

