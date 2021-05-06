//
// Created by Robert on 02.05.2021.
//

#include "Persoana.h"

Persoana::Persoana(const string &nume, const string &prenume, const string &tip_camera, const string &tipMasa):m_grup_id(-1),m_id_camera(0) {
    m_nume=nume;
    m_prenume=prenume;
    m_tip_camera=tip_camera;
    m_masaRestaurant=false;
    if(tipMasa=="restaurant")
        m_masaRestaurant=true;
    else m_masaRestaurant= false;
}

Persoana::Persoana(): m_grup_id(-1), m_id_camera(0){
    m_nume=m_prenume=m_tip_camera='-';
    m_masaRestaurant=false;

}

ostream &operator<<(ostream &os, const Persoana &persoana) {
    os<<persoana.getNumePrenume()<<" s-a cazat in "<<persoana.m_tip_camera;
    os<<" si ia micul dejun in ";
    if(persoana.m_masaRestaurant)
        os<<"restaurant.";
    else os<<"camera.";
    os<<'\n';
    return os;
}

string Persoana::getNumePrenume() const {
    return m_nume+' '+m_prenume;
}

void Persoana::setGrupId(int grupid) {
    m_grup_id = grupid;
}

int Persoana::getGrupId() const {
    return m_grup_id;
}

const string &Persoana::getTipCamera() const {
    return m_tip_camera;
}

void Persoana::setIdCamera(const int IdCamera) {
    m_id_camera = IdCamera;
}

bool Persoana::getMasaRestaurant() const {
    return m_masaRestaurant;
}


