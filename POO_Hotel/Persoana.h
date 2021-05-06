//
// Created by Robert on 02.05.2021.
//

#ifndef POO_HOTEL_PERSOANA_H
#define POO_HOTEL_PERSOANA_H

#include <string>
#include <iostream>
using namespace std;
class Persoana {
private:
    string m_nume, m_prenume, m_tip_camera;
    int m_id_camera, m_grup_id;
    bool m_masaRestaurant;
public:
    Persoana();
    Persoana(const string& nume, const string& prenume, const string& tip_camera, const string& tipMasa);
    string getNumePrenume() const;
    friend ostream &operator<<(ostream &os, const Persoana& persoana);
    void setGrupId(int grupid);
    int getGrupId() const;
    void setIdCamera(int IdCamera);
    const string &getTipCamera() const;
    bool getMasaRestaurant() const;
};


#endif //POO_HOTEL_PERSOANA_H
