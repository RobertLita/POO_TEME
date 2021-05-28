//
// Created by Robert on 28.05.2021.
//

#include "Achizitie.h"

Achizitie::Achizitie(): m_data(), m_nume("-"), m_pret(0), m_nr_dezinfectanti(0), m_nr_masti(0){
    m_dezinfectanti = new Dezinfectant [100];
    m_masti = new MascaChirurgicala [100];
}

Achizitie::Achizitie(int zi, int luna, int an, const string &nume): m_data(zi, luna, an), m_nume(nume), m_pret(0), m_nr_dezinfectanti(0), m_nr_masti(0){
    m_dezinfectanti = new Dezinfectant [100];
    m_masti = new MascaChirurgicala [100];
}

Achizitie& Achizitie::operator=(Achizitie &a) {
    a.m_nr_dezinfectanti = m_nr_dezinfectanti;
    a.m_nr_masti = m_nr_masti;
    a.m_pret = m_pret;
    a.m_dezinfectanti = m_dezinfectanti;
    a.m_masti = m_masti;
    a.m_dezinfectanti = m_dezinfectanti;
    a.m_data = m_data;
}

Achizitie::Achizitie(const Achizitie &a) {
    m_nr_dezinfectanti = a.m_nr_dezinfectanti;
    m_nr_masti = a.m_nr_masti;
    m_pret = a.m_pret;
    m_dezinfectanti = a.m_dezinfectanti;
    m_masti = a.m_masti;
    m_nume = a.m_nume;
    m_data = a.m_data;
}

Achizitie::~Achizitie() {
    delete [] m_dezinfectanti;
    delete [] m_masti;
}

Achizitie &Achizitie::operator+=(const MascaChirurgicala &m) {
    m_masti[m_nr_masti] = m;
    const string tip = m.getTipProtectie();
    const auto ePolicarbonat = dynamic_cast<const MascaPolicarbonat *>(&m);
    if(ePolicarbonat != nullptr)
    {
        m_pret += 20;
    }
    else if(tip == "ffp1"){
        m_pret+= 5;
    }
    else if(tip == "ffp2"){
        m_pret+= 10;
    }
    else {
        m_pret+= 15;
    }
    m_nr_masti++;
    return *this;
}

Achizitie &Achizitie::operator+=(const Dezinfectant *d) {
    m_dezinfectanti[m_nr_dezinfectanti] = *d;
    float ef = m_dezinfectanti[m_nr_dezinfectanti].eficienta() * 10;
    if(ef >= 99){
        m_pret += 50;
    }
    else if(ef >= 97.5){
        m_pret += 40;
    }
    else if(ef >= 95){
        m_pret += 30;
    }
    else if(ef >= 90){
        m_pret += 20;
    }
    else {
        m_pret += 10;
    }
    m_nr_dezinfectanti++;
    return *this;
}

Achizitie &Achizitie::operator+=(const MascaChirurgicala *m) {
    operator+=(*m);
    return *this;
}

bool Achizitie::operator<(const Achizitie &a) const {
    if(m_pret < a.m_pret)return true;
    return false;
}

bool Achizitie::operator==(const Achizitie &a) const {
    if(m_pret == a.m_pret)return true;
    return false;
}

const string &Achizitie::nume() const {
    return m_nume;
}

