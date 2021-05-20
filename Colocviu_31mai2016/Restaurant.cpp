//
// Created by Robert on 20.05.2021.
//

#include "Restaurant.h"

Restaurant::Restaurant(): nr_comenzi(0), nr_ospatari(0), nr_produse(0) {}

Restaurant::Restaurant(int n_comenzi, const vector<Comanda *>& c,int n_ospatari, const vector<Ospatar *>& o, int n_produse, const vector<Produs*>& p):
nr_produse(n_produse), nr_ospatari(n_ospatari), nr_comenzi(n_comenzi), comenzi_totale(c), ospatari(o), produse(p){}

void Restaurant::adaugaOspatar(Ospatar *o) {
    ospatari.push_back(o);
}

void Restaurant::adaugaProdus(Produs *p) {
    produse.push_back(p);
}

void Restaurant::adaugaComanda(Comanda *c) {
    comenzi_totale.push_back(c);
}

void Restaurant::comenzi_la_data(int zi, int luna, int an) {
    bool ok = false;
    cout << "Comenzile din data de " << zi << '.'<< luna << '.' << an <<" sunt: ";
    for(Comanda *c:comenzi_totale){
        if(c->getData().an == an && c->getData().luna == luna && c->getData().zi == zi){
            ok = true;
            cout << "\n\t" <<*c;
        }
    }
    if(!ok){
        cout<<"Nu exista.";
    }
    cout << '\n';
}

int Restaurant::nr_portii(const string &nume, int luna, int an) {
    int cnt = 0;
    for(Comanda *c:comenzi_totale){
        if( c->getProd().getDenProdus() == nume && c->getData().luna == luna && c->getData().an  == an){
            cnt += c->getNrPortii();
        }
    }
    return cnt;
}

float Restaurant::procent_online(int luna, int an) {
    float bani_online = 0, bani_totali = 0, procent;
    for(Comanda *c:comenzi_totale){
        if(c->getData().an == an && c->getData().luna == luna){
            bani_totali += c->getPret();
            const auto eOnline = dynamic_cast<const ComOnline *>(c);
            if (eOnline != nullptr){
                bani_online +=c->getPret();
            }
        }
    }
    procent = bani_online * 100 / bani_totali;
    return procent;
}


