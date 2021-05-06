//
// Created by Robert on 04.05.2021.
//

#include "Hotel.h"

Hotel::Hotel(): m_nr_incaperi(0) {}

void Hotel::adaugaIncapere(Incapere *incapere) {
    const auto eCamera = dynamic_cast<const Camera *>(incapere);
    const auto eApartament = dynamic_cast<const Apartament *>(incapere);
    const auto eRestaurant = dynamic_cast<const Restaurant *>(incapere);
    const auto eSala = dynamic_cast<const Sala *>(incapere);
    Incapere *copie = nullptr;
    if (eCamera != nullptr) {
        copie = new Camera(*eCamera);
    } else if(eApartament != nullptr) {
        copie = new Apartament(*eApartament);
    }
    else if (eRestaurant != nullptr) {
        copie = new Restaurant(*eRestaurant);
    }
    else if (eSala != nullptr) {
        copie = new Sala(*eSala);
    }
    if (copie != nullptr) {
        m_nr_incaperi++;
        copie->setIdIncapere(m_nr_incaperi);
        m_incaperi_hotel.push_back(copie);
        incapere->setIdIncapere(m_nr_incaperi);
    }
}


Hotel::tipIncapere Hotel::getTipIncapere(const Incapere *incapere) {
    const auto eCamera = dynamic_cast<const Camera *>(incapere);
    const auto eApartament = dynamic_cast<const Apartament *>(incapere);
    const auto eRestaurant = dynamic_cast<const Restaurant *>(incapere);
    const auto eSala = dynamic_cast<const Sala *>(incapere);
    if (eCamera != nullptr) {
        return CAMERA;
    }
    else if (eApartament != nullptr) {
        return APARTAMENT;
    }
    else if (eRestaurant != nullptr) {
        return RESTAURANT;
    }
    else if (eSala != nullptr) {
        return SALA;
    }
    return NONE;
}


void Hotel::adaugaPersoana(Persoana *persoana) {
    bool incapereExistenta = false;
    for(auto &incapere:m_incaperi_hotel){
        tipIncapere tip = getTipIncapere(incapere);
        if( ((tip == CAMERA && persoana->getTipCamera()=="camera") || (tip == APARTAMENT && persoana->getTipCamera()=="apartament"))
        && incapere->getNrPersoane() < incapere->getCapacitate() && persoana->getGrupId() == incapere->getIdGrup()){
            incapere->ocupa(*persoana);
            persoana->setIdCamera(incapere->getIdCamera());
            incapereExistenta = true;
        }
    }
    if(!incapereExistenta){
        const string& tipCamera = persoana->getTipCamera();
        if(tipCamera == "camera"){
            auto* c = new Camera();
            c->ocupa(*persoana);
            c->setIdGrup(persoana->getGrupId());
            adaugaIncapere(c);
        }
        else {
            auto* a = new Apartament();
            a->ocupa(*persoana);
            a->setIdGrup(persoana->getGrupId());
            adaugaIncapere(a);
        }
    }
}

void Hotel::adaugaPersoana( Persoana &persoana) {
    return adaugaPersoana(&persoana);
}

void Hotel::cazeazaGrup(Grup *grup) {
    if(m_nr_incaperi==0 || getTipIncapere(m_incaperi_hotel[0])!=RESTAURANT)
        for(const auto& persona:grup->getPersoane()){
            if(persona.getMasaRestaurant()){
                auto r=new Restaurant();
                adaugaIncapere(r);
                break;
            }
        }
    if(grup->getVorSala()){
        auto s=grup->getSala();
        s.setIdGrup(grup->getId());
        adaugaIncapere(&s);
    }
    for(auto persoana:grup->getPersoane()){
        adaugaPersoana(persoana);
    }
}

void Hotel::cazeazaGrup(Grup &grup) {
    cazeazaGrup(&grup);

}

ostream &operator<<(ostream &os, const Hotel &hotel) {
    os<<"Hotelul are "<<hotel.m_nr_incaperi<<" incaperi:\n";
    for(auto incapere:hotel.m_incaperi_hotel){
        Hotel::tipIncapere tip=hotel.getTipIncapere(incapere);
        if(tip==Hotel::SALA){
            os<<"   "<<(Sala&)*incapere<<'\n'; //daca incaperea este sala, afisez incaperea ca pe o sala
        }
        else if(tip==Hotel::RESTAURANT){
            os<<"   "<<(Restaurant&)*incapere<<'\n'; //analog cu restaurantul
        }
        else os<<"   "<<*incapere<<'\n'; //altfel, incaperea este camera sau apartament, care au aceeasi afisare, cea de baza
    }
    return os;
}

void Hotel::anuleazaRezervare(Grup &grup) {
    anuleazaRezervare(&grup);
}

void Hotel::anuleazaRezervare(Grup *grup) {
    int i=0;
    while(i<m_incaperi_hotel.size()){
        if(m_incaperi_hotel[i]->getIdGrup()==grup->getId()){
            m_incaperi_hotel.erase(m_incaperi_hotel.begin()+i);
            m_nr_incaperi--;
            i--;
        }
        i++;
    }
}



