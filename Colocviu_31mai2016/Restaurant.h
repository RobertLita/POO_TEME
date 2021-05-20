//
// Created by Robert on 20.05.2021.
//

#ifndef COLOCVIU_31MAI2016_RESTAURANT_H
#define COLOCVIU_31MAI2016_RESTAURANT_H

#include "ComSpec.h"
#include "ComOnline.h"
#include "Ospatar.h"
class Restaurant {
private:
    int nr_comenzi, nr_ospatari, nr_produse;
    vector<Comanda*> comenzi_totale;
    vector<Ospatar*> ospatari;
    vector<Produs*> produse;
public:
    Restaurant();
    Restaurant(int n_comenzi, const vector<Comanda*> &c, int n_ospatari, const vector<Ospatar*> &o,int n_produse, const vector<Produs*> &p);
    void adaugaOspatar(Ospatar *o);
    void adaugaProdus(Produs *p);
    void adaugaComanda(Comanda *c);
    void comenzi_la_data(int zi, int luna, int an);
    int nr_portii(const string &nume, int luna, int an);
    float procent_online(int luna, int an);
};


#endif //COLOCVIU_31MAI2016_RESTAURANT_H
