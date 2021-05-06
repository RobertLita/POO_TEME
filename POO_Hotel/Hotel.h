//
// Created by Robert on 04.05.2021.
//

#ifndef POO_HOTEL_HOTEL_H
#define POO_HOTEL_HOTEL_H

#include <ostream>
#include "Restaurant.h"
#include "Sala.h"
#include "Camera.h"
#include "Apartament.h"
#include "Grup.h"

class Hotel {
private:
    int m_nr_incaperi;
    enum tipIncapere{
        CAMERA,
        APARTAMENT,
        RESTAURANT,
        SALA,
        NONE
    };
    vector <Incapere*> m_incaperi_hotel;
public:
    Hotel();
    void cazeazaGrup(Grup *grup);
    void cazeazaGrup(Grup &grup);
    void adaugaIncapere(Incapere *incapere);
    void adaugaPersoana(Persoana &persoana);
    void adaugaPersoana(Persoana *persoana);
    void anuleazaRezervare(Grup &grup);
    void anuleazaRezervare(Grup *grup);
    static tipIncapere getTipIncapere(const Incapere *incapere);
    friend ostream &operator<<(ostream &os, const Hotel &hotel);
};


#endif //POO_HOTEL_HOTEL_H
