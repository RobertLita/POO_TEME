//
// Created by Robert on 04.05.2021.
//

#include "Grup.h"
int Grup::nr_grupuri;

Grup::Grup(): m_nr_persoane(0), vorSala(false), m_id(++nr_grupuri), m_sejur(){}

Grup::Grup(const int nr_persoane,const int zi, const int luna, const int durata, vector<Persoana>& p, bool sala)
    :m_nr_persoane(nr_persoane), vorSala(sala), m_id(++nr_grupuri){
    m_sejur.m_durata = durata;
    m_sejur.m_data_ocupare.m_zi = zi;
    m_sejur.m_data_ocupare.m_luna = luna;
    for(Persoana& persoana:p){
        persoana.setGrupId(m_id);
    }
    m_persoane=p;
}

Grup::Grup(const int nr_persoane, const int zi, const int luna, const int durata, vector<Persoana>& p, bool sala, const Sala& s):
Grup(nr_persoane, zi, luna, durata, p, sala){
    m_sala = s;
}

bool Grup::getVorSala() const {
    return vorSala;
}

const Sala &Grup::getSala() const {
    return m_sala;
}

const vector<Persoana> &Grup::getPersoane() const {
    return m_persoane;
}

ostream &operator<<(ostream &os, const Grup &grup) {
    os<<"Grupul "<<grup.m_id<<" format din:\n";
    for(const auto& persoana:grup.m_persoane){
        os<<persoana;
    }
    return os;
}

int Grup::getId() const {
    return m_id;
}



