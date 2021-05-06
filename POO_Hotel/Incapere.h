//
// Created by Robert on 02.05.2021.
//

#ifndef POO_HOTEL_INCAPERE_H
#define POO_HOTEL_INCAPERE_H

#include "Persoana.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Incapere {
protected:
    int m_capacitate, m_nr_persoane, m_id_incapere, m_idGrup;
    vector <Persoana> m_persoane;

public:
    Incapere();
    virtual ~Incapere();
    explicit Incapere(int capacitate);
    void ocupa(Persoana& persoana);
    int getIdCamera() const;
    int getCapacitate() const;
    int getNrPersoane() const;
    int getIdGrup() const;
    void setIdGrup(int mIdGrup);
    void setIdIncapere(int IdIncapere);
    friend ostream &operator<<(ostream &os, const Incapere& incapere);
};


#endif //POO_HOTEL_INCAPERE_H
