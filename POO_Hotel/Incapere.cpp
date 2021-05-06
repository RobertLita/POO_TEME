//
// Created by Robert on 02.05.2021.
//
#include "Incapere.h"

Incapere::Incapere():m_capacitate(0), m_nr_persoane(0), m_idGrup(0), m_id_incapere(0){}

Incapere::Incapere(const int capacitate): m_capacitate(capacitate), m_nr_persoane(0), m_idGrup(0), m_id_incapere(0){}

void Incapere::ocupa(Persoana& persoana) {
    if(m_nr_persoane<m_capacitate){
        m_idGrup = persoana.getGrupId();
        m_nr_persoane++;
        m_persoane.push_back(persoana);
    }
}

ostream &operator<<(ostream &os, const Incapere &incapere) {

    if (incapere.m_capacitate == 2) {
        os << "Camera ";
    }
    else os << "Apartamentul ";
    os << "cu numarul " << incapere.m_id_incapere << " gazduieste " << incapere.m_nr_persoane
       << " persoane din cele " << incapere.m_capacitate << " locuri disponibile";
    if (incapere.m_nr_persoane >= 1) {
        os<<": ";
        for (int i = 0; i < incapere.m_nr_persoane - 1; i++) {
            os << incapere.m_persoane[i].getNumePrenume() << ", ";
        }
        os << incapere.m_persoane[incapere.m_nr_persoane - 1].getNumePrenume() << '.';
    }
    return os;
}

int Incapere::getIdCamera() const {
    return m_id_incapere;
}

Incapere::~Incapere() = default;

int Incapere::getCapacitate() const {
    return m_capacitate;
}

int Incapere::getNrPersoane() const {
    return m_nr_persoane;
}

int Incapere::getIdGrup() const {
    return m_idGrup;
}

void Incapere::setIdGrup(int IdGrup) {
    m_idGrup = IdGrup;
}

void Incapere::setIdIncapere(int IdIncapere) {
    m_id_incapere = IdIncapere;
}



