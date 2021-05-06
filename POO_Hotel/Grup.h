//
// Created by Robert on 04.05.2021.
//

#ifndef POO_HOTEL_GRUP_H
#define POO_HOTEL_GRUP_H

#include <ostream>
#include "Sala.h"
class Grup {
private:
    static int nr_grupuri;
    int m_nr_persoane, m_id;
    bool vorSala;
    Sala m_sala;
    vector<Persoana> m_persoane;
    struct sejur{
        struct data{
            int m_zi, m_luna;
            data():m_luna(0),m_zi(0){};
        } m_data_ocupare;
        int m_durata;
        sejur(): m_durata(0), m_data_ocupare(){}
    } m_sejur;
public:
    Grup();
    Grup(int nr_persoane, int zi, int luna, int durata, vector<Persoana>& p, bool sala = false);
    Grup(int nr_persoane, int zi, int luna, int durata, vector<Persoana>& p, bool sala, const Sala& s);
    bool getVorSala() const;
    const Sala &getSala() const;
    const vector<Persoana> &getPersoane() const;
    friend ostream &operator<<(ostream &os, const Grup &grup);
    int getId() const;

};


#endif //POO_HOTEL_GRUP_H
